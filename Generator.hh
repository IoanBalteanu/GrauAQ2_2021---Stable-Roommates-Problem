#include <iostream>
#include <vector>
#include <algorithm> 
#include <ctime>
#include <cstdlib>   
#include <list>  

using namespace std;

typedef vector<vector<int>> Problem;
typedef vector<Problem> ProblemSet;

typedef vector<list<int>> LProblem;
typedef vector<LProblem> LProblemSet;

class Generator
{
    private:
        
        Generator(){}
        
        static void getTable(Problem& table, int n);
        
        static void shuffleTable(Problem& table, int n);
        
        static LProblem toList(Problem& table);
        
    public:
        static LProblemSet getProblems(int nProbs, int nRms);
};
