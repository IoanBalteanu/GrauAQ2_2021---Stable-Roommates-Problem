#include"Generator.hh"

using namespace std;


void Generator::shuffleTable(vector<vector<int>>& table, int n)
{
    for(int i = 0 ; i < n ; ++i){
        random_shuffle(++table[i].begin(),table[i].end());
    }
}

void Generator::getTable(vector<vector<int>>& table, int n) 
{
    for (int i = 0 ; i < n; ++i) {
        table[i][0] = i;
        for (int j = 1; j < n; ++j) {
            if (j == i) table[i][j] = 0;
            else table[i][j] = j;
        }
    }
}


vector<vector<vector<int>>> Generator::getProblems(int nProbs, int nRms)
{
    vector<vector<vector<int>>> Problems (nProbs, vector<vector<int>> (2*nRms,vector<int> (2*nRms)));

    Generator::getTable(Problems[0], 2*nRms);
    
    for(int i = 1 ; i < nProbs ; ++i){
        Problems[i] = Problems[0];
    }
    for(int i = 0 ; i < nProbs ; ++i){
        Generator::shuffleTable(Problems[i], 2*nRms);
    }
    
    return Problems;
}
