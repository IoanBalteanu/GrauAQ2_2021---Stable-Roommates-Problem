#include <iostream>
#include <vector>
#include <algorithm> 
#include <ctime>
#include <cstdlib>     

using namespace std;

typedef vector<vector<int>> PROBLEM;

class Generator
{
    private:
        
        Generator(){}
        
        static void getTable(PROBLEM& table, int n);
        
        static void shuffleTable(PROBLEM& table, int n);
        
    public:
        static vector<PROBLEM> getProblems(int nProbs, int nRms);
};
