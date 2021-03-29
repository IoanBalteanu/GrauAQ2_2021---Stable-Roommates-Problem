#include <iostream>
#include <vector>
#include <algorithm> 
#include <ctime>
#include <cstdlib>     

using namespace std;

class Generator
{
    private:
        
        Generator(){}
        
        static void getTable(vector<vector<int>>& table, int n);
        
        static void shuffleTable(vector<vector<int>>& table, int n);
        
    public:
        static vector<vector<vector<int>>> getProblems(int nProbs, int nRms);
};
