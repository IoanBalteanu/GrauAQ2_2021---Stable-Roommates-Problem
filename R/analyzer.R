# Script que analitza els resultats
library(ggplot2)

## Probabilitat de Mertens
Pn <- function(n) return(exp(1)*(1/sqrt(pi))*(4/n)^(1/4))

## Llegim les dades
df <- read.csv("results.csv", header = T)

## Analisis de les dades
df$samples_real <- df$stable + df$unstable

### Estimacio de Pn
Pn_estimat <- (df$stable/df$samples_real)
df$Pn_estimat <- Pn_estimat

### Desviacio per Pn
round(Pn_desviacio <- sqrt(Pn_estimat*(1- Pn_estimat)/df$sample), 3)

### Interval de confianca per Pn al 95%
(ICp <- round(c(Pn_estimat + 1.96*Pn_desviacio), 3))
(ICn <- round(c(Pn_estimat - 1.96*Pn_desviacio), 3))

### 
err = abs(abs(Pn_estimat - Pn(df$n)))

### times
(t_st <- round(df$t_roomST/df$stable, 3))
(t_un <- round(df$t_roomUN/df$unstable, 3))
(t_ge <- round(df$t_gen/df$samples_real, 3))
(t_to <- round((df$t_gen + df$t_roomST + df$t_roomUN)/3600, 3))

### Chi square
expected <- df$samples_real * Pn(df$n)
observed <- df$stable 
chi_val <- sum( (observed - expected )^2/expected)

pvalue <- (1 - pchisq(chi_val, df = length(observed) - 1))
print(paste0("Chi-square value: ", round(chi_val, 3), ", p-value: ", round(pvalue, 3)))

### Generalized linear Model
lmod <- glm(cbind(stable, samples_real-stable) ~ I(n^(-1/4)),
           family=binomial, data = df)

#### Summary fit
sink("lmod.txt", append = F, type = "output")
summary(lmod)
closeAllConnections()

#### IC pel fit
confint(lmod)

#### Goodness of fit
pchisq(deviance(lmod), df.residual(lmod), lower=FALSE)

### Predict
n_pred <- 10000
exp(as.numeric(lmod$coefficients[1]) + as.numeric(lmod$coefficients[2])*n_pred^(-1/4))/
  (1 + exp(as.numeric(lmod$coefficients[1]) + as.numeric(lmod$coefficients[2])*n_pred^(-1/4)))

## Plots
### Time 
dfPlot <- data.frame(time = c(df$t_roomST/df$stable, df$t_roomUN/df$unstable),
                     type = rep(c("Stable", "Unstable"), each = length(observed)),
                     samples = rep(df$samples_real, times = 2),
                     n = rep(df$n, times = 2))

ggplot(dfPlot, aes(x = n, y = time, color = type)) + geom_point(size = 1) + theme_light() + 
  expand_limits(y = 0, x = 0) + theme(legend.title = element_blank(), legend.position=c(0.25, 0.8)) +
  ylab(expression(paste(bar('t'), plain( (s) )))) + xlab(expression('n')) +
  stat_smooth(aes(fill = type), method = 'lm', formula = y ~ I(x^2), se = F, lwd = 0.5) +
  scale_colour_brewer(palette = "Set1")
  
ggsave("time_irving.png", width = 7)

##### linear model
sink("lm.txt", append = F, type = "output")
summary(lmfit <- lm(time ~ I(n^2)*type, data = dfPlot))
closeAllConnections()


### Pn vs Pn_obs
pframe <- with(df, expand.grid(n=seq(min(df$n), max(df$n),length=100)))
pframe$Pn_estimat <- predict(lmod, newdata=pframe, type="response")

ggplot(df, aes(x=n, y=Pn_estimat)) + geom_point(shape = 18) + theme_light() + 
  expand_limits(y = c(0, 0.75), x = 0) +
  ylab(expression('P'[n])) + xlab(expression('n')) +
  geom_function(fun = Pn, aes(colour = "red")) + 
  geom_line(data=pframe, aes(colour = 'blue')) +
  scale_colour_brewer(labels = c("Experimental", "Mertens"), palette = "Set1") +
  theme(legend.title = element_blank(), legend.position=c(0.75, 0.8)) 
ggsave("Pn_vs_observed.png", width = 7)


