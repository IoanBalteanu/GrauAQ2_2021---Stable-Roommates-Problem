library(matchingR)

# Probabilitat de Mertens
Pn <- function(n) return(exp(1)*(1/sqrt(pi))*(4/n)^(1/4))

# Room sizes que experimentem
#        1   2    3    4     5     6     7    8      9     10     11
Ns <- c(50, 100, 250, 500, 1000, 2000, 5000, 7500, 10000, 15000, 20000)

# dataframe buit per recopilar la informacio
df <- data.frame(matrix(0, ncol=7, nrow=length(Ns), 
                 dimnames=list(NULL, c("n", "sample", "stable", "unstable", "t_gen", "t_roomST", "t_roomUN"))))

# posarho Ns al df, i calcular Pn per cada probabilitat
df$n <- Ns
Pns <- Pn(Ns)

# sample size
df[, 'sample'] <- ceiling((1.96**2)*(1 - Pns)*Pns/(0.15**2))
# valors esperats per la quanitat de sample
expected <- Pns * df[, 'sample'] 

for(i in 1:length(Ns)) {
  set.seed(1984 + i)   # escollim una seed different per cada conjunt de experiments (aixi si peta potem reexecutar nomes una part)
  n_size <- df[i, 'n']
  print(n_size)        # ensenyar per on anem
  
  # per cada n_sample size repetim el experiment
  for (j in 1:df[i, 'sample']) {
    ptm <- proc.time()
    u = matrix(runif(n_size^2),  nrow = n_size, ncol = n_size) # matriu de permutacions
    df[i, "t_gen"] <- (proc.time() - ptm)[3]
    
    ptm <- proc.time()
    rmSol <- roommate(utils = u) # Irving
    t <- (proc.time() - ptm)[3]
    
    # posem els temps on toquen
    if (is.null(rmSol)) {
      df[i, 'unstable'] <- df[i, 'unstable'] + 1
      df[i, 't_roomUN'] <- df[i, 't_roomUN'] + t
    } else {
      df[i, 'stable']   <- df[i, 'stable']  + 1
      df[i, 't_roomST'] <- df[i, 't_roomST']+ t
    }
    # a cada experiment guardem el df -> per si peta per memoria no haver de tornar a comencar
    write.csv(df, paste0("experiment_size_",i,".csv"), row.names = F)
  }
  # quan ha acabat un -> guardar a fitxer que sha acabat la generacio d'aquests
  sink(paste0("completed_",i,".txt"))
  print("yay")
  closeAllConnections()
}
