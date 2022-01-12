#include"Generator.hh"

using namespace std;


void Generator::shuffleTable(Problem& table, int n)
{
    for(int i = 0 ; i < n ; ++i){
        random_shuffle(++table[i].begin(),table[i].end());
    }
}

void Generator::getTable(Problem& table, int n) 
{
    for (int i = 0 ; i < n; ++i) {
        table[i][0] = i;
        for (int j = 1; j < n; ++j) {
            if (j == i) table[i][j] = 0;
            else table[i][j] = j;
        }
    }
}

LProblem Generator::toList(Problem& p)
{
    LProblem lp;
    
    for (auto row : p)
    {
        list<int> aux(row.begin(), row.end());
        lp.push_back(aux);
    }

    return lp;
}


LProblemSet Generator::getProblems(int nProbs, int nRms)
{
    //Declare Problem Sets
    ProblemSet problems (nProbs, Problem (2*nRms,vector<int> (2*nRms)));
    LProblemSet Lproblems;
    //Generate first Problem of 2nRms * 2nRms
    Generator::getTable(problems[0], 2*nRms);
    
    //Copy basic Problem to all Set
    for(int i = 1 ; i < nProbs ; ++i){
        problems[i] = problems[0];
    }
    
    //Shuffle all Problems and assign them to lists and then to a Set of List problems
    for(int i = 0 ; i < nProbs ; ++i){
        Generator::shuffleTable(problems[i], 2*nRms);
        Lproblems.push_back(Generator::toList(problems[i]));
    }
    
    return Lproblems;
}
