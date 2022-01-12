# Stable Roommates Problem - Irving Algorithm

The Stable Roommates Problem is a type of stable matching problem where agents act selfishly to optimize their own satisfaction, subject to mutually conflicting constraints. 

This project studies the Stable Roommates Problem, in which $n$ people pair up to share $n_{room}$ rooms in such a way that all of them are happy. Concretely, we are trying to corroborate Mertens Conjecture on the asymptotic decay in the probability of a stable matching existing as $n$ increases.

We have implemented a solution using Irving's Algorithm in c++ and R. 

The results and analysis is on the file called Report.pdf

## R
There are four files inside the R folder:
  - `requirements.R`: a script that installs the requirements
  - `generator.R`: generates stable roommates problems and solves them using Irving's algorithm from `matchingR`. 
  - `results.csv`: our output from the previous script.
  - `analyzer.R`: reads the results and runs some statistical analysis on the data.

### Execution
```
cd R/
Rscript requirements.R
Rscript script_GeneradorIrving.R
Rscript script_Analisis.R
```

## C++
Problem Generator:
  - Generates $m$ problems of size $n$. 
  - Problems are $n \times n$ arrays and they are stored in a vector of size $m$.
  - This vector is the output of the generator program and the input of the program that generates Irving's algorithm.

### Execution
```
cd cpp/
make      
./Program
```
