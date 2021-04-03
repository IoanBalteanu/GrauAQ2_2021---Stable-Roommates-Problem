#include<iostream>
#include<vector>
#include<list>
#include<utility>
#include<algorithm>
using namespace std;

typedef pair<int,int> Proposal;

//##############################################
vector<list<int>> toList(vector<vector<int>>& p)
{
    vector<list<int>> lp;
    
    for (auto row : p)
    {
        list<int> aux(row.begin(), row.end());
        lp.push_back(aux);
    }

    return lp;
}

bool check_proposal(vector<Proposal>& proposals, int preffered)
{
    for(auto proposal: proposals)
    {
        if((proposal.second) == preffered) return true;
    }
    return false;
}

int getProposed(vector<Proposal>& proposals, int preffered)
{
    for(int i = 0 ; i < proposals.size() ; ++i)
    {
        if((proposals[i].second) == preffered) 
        {
            int ret = proposals[i].first;
            proposals[i] = make_pair(proposals[proposals.size()-1].first , proposals[proposals.size()-1].second);
            proposals.pop_back();
            return ret;
        }
    }
    return -1;
}

int checkGrade(list<int>& row, int actual, int proposed)
{
    list<int>::iterator it = row.begin();
    while(it != row.end())
    {
        if(*it == actual || *it == proposed) return *it;
        ++it;
    }
    
    return -1;
}

void eraseReferences(vector<list<int>>& Lproblem, int preffered, int proposed)
{
    Lproblem[preffered].remove(proposed);
    Lproblem[proposed].remove(preffered);
}

bool findNewProposal(vector<list<int>>& Lproblem,vector<Proposal>& proposals, int again, bool possible)
{
    list<int>::iterator it = Lproblem[again].begin();
    it++;
    int preffered = *it;
    if(Lproblem[again].size() < 2 or !possible) return false;
    
    if(!check_proposal(proposals,preffered))
    {
        proposals.push_back(make_pair(again,preffered));
        return true;
    }
    else
    {
        int proposed = getProposed(proposals, preffered);
        int best = checkGrade(Lproblem[preffered], again, proposed);
        proposals.push_back(make_pair(best,preffered));
        if(best == again)
        {
            eraseReferences(Lproblem,preffered,proposed);
            possible = findNewProposal(Lproblem,proposals,proposed,possible);
        }
        else
        {
            eraseReferences(Lproblem,preffered,again);
            possible = findNewProposal(Lproblem,proposals,again,possible);
        }
    }
    
}

void findCycle(vector<list<int>>& Lproblem, int i, bool& hasCycle, vector<int>& cycle)
{
    
    list<int>::iterator it = Lproblem[i].begin();
    advance(it, 2);
    if(Lproblem[*it].size() > 2)
    {
        cycle.push_back(i);
        if(cycle.size() > 1 and cycle[0] == cycle[cycle.size()-1]) hasCycle = true;
        else
        {
            findCycle(Lproblem, *it, hasCycle, cycle);
        }
    }
}

bool check_size(vector<list<int>>& Lproblem)
{
    for(auto l : Lproblem) if(l.size() < 2) return false;
    return true;
}

int main()
{
    vector<vector<int>> basicProblem;
    basicProblem = 
    {
        {0,1,2,3},
        {1,0,2,3},
        {2,3,0,1},
        {3,2,1,0}
    };
    
    vector<vector<int>> TProblem;
    TProblem = 
    {
        {0,1,3,5,4,2},
        {1,4,2,5,3,0},
        {2,1,5,4,0,3},
        {3,2,0,5,1,4},
        {4,1,0,5,2,3},
        {5,0,3,4,2,1}
    };
    
    vector<vector<int>> FProblem;
    FProblem = 
    {
        {0,2,1,3},
        {1,0,2,3},
        {2,1,0,3},
        {3,0,1,2}
    };
    
    vector<list<int>> Lproblem = toList(basicProblem);
    
    vector<Proposal> proposals;
    vector<bool> paired(Lproblem.size(), false);
    
    int actual = 0;
    bool possible = true;
    while(actual < Lproblem.size() && possible)
    {
        //Get first
        list<int>::iterator it = Lproblem[actual].begin();
        it++;
        int preffered = *it;        
        //Preffered is not paired
        if(!check_proposal(proposals,preffered))
        {
            proposals.push_back(make_pair(actual,preffered));
        }
        else
        {
            int proposed = getProposed(proposals, preffered);
            int best = checkGrade(Lproblem[preffered], actual, proposed);
            proposals.push_back(make_pair(best,preffered));
            if(best == actual)
            {
                eraseReferences(Lproblem,preffered,proposed);
                possible = findNewProposal(Lproblem,proposals,proposed,possible);
            }
            else
            {
                eraseReferences(Lproblem,preffered,actual);
                actual--;
            }
        }
        
        actual++;
        possible = check_size(Lproblem);
    }
    
    for(auto p : proposals)
    {
        list<int>::iterator it = find(Lproblem[p.second].begin(), Lproblem[p.second].end(), p.first);
        it++;
        auto end = Lproblem[p.second].end();
        
        while(it != end)
        {
            int aux = *it;
            it = Lproblem[p.second].erase(it);
            Lproblem[aux].remove(p.second);
        } 
    }
    
    bool hasCycle = false;
    vector<int> cycle;
    
    for(int i = 0 ; i < Lproblem.size() ; i++)
    {
        if(Lproblem[i].size() > 2)
        {
            findCycle(Lproblem,i,hasCycle,cycle);
            if(hasCycle)
            {
                for(int j = cycle.size()-1 ; j > 0 ; j -= 2)
                {
                    eraseReferences(Lproblem, cycle[j], cycle[j-1]);
                }
            }
        }
    }
    
    
    if(!possible) cout << "Not Possible" << endl;
    else
    {
        for(list<int> row : Lproblem)
        {
            for(int pos : row)
            {
                cout << pos << " ";
            }
            cout << "\b" << ""; 
            cout << endl;
        }
        cout << proposals.size() << endl;
    }
    return 0;
}
