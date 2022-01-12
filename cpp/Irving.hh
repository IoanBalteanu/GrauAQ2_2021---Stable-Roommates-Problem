#include<iostream>
#include<vector>
#include<list>
#include<utility>
#include<algorithm>
using namespace std;

typedef pair<int,int> Proposal;

using namespace std;

class Irving
{
    private:
        static bool check_proposal(vector<Proposal>& proposals, int preffered);
        static int getProposed(vector<Proposal>& proposals, int preffered);
        static int checkGrade(list<int>& row, int actual, int proposed);
        static void eraseReferences(vector<list<int>>& Lproblem, int preffered, int proposed);
        static bool findNewProposal(vector<list<int>>& Lproblem,vector<Proposal>& proposals, int again, bool possible);
        static bool check_cycle(vector<int>& cycle, int i, int& start);
        static vector<int> solveCycle(vector<int>& cycle, int start);
        static void findCycle(vector<list<int>>& Lproblem, int i, bool& hasCycle, vector<int>& cycle);
        static bool check_size(vector<list<int>>& Lproblem);
    public:
        static bool executeAlgorithm(vector<list<int>>& Lproblem);
        
};
