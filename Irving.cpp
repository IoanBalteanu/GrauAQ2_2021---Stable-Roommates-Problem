#include "Irving.hh"

bool Irving::check_proposal(vector<Proposal>& proposals, int preffered)
{
    for(auto proposal: proposals)
    {
        if((proposal.second) == preffered) return true;
    }
    return false;
}

int Irving::getProposed(vector<Proposal>& proposals, int preffered)
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

int Irving::checkGrade(list<int>& row, int actual, int proposed)
{
    list<int>::iterator it = row.begin();
    while(it != row.end())
    {
        if(*it == actual || *it == proposed) return *it;
        ++it;
    }
    
    return -1;
}

void Irving::eraseReferences(vector<list<int>>& Lproblem, int preffered, int proposed)
{
    Lproblem[preffered].remove(proposed);
    Lproblem[proposed].remove(preffered);
}

bool Irving::findNewProposal(vector<list<int>>& Lproblem,vector<Proposal>& proposals, int again, bool possible)
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
        int proposed = Irving::getProposed(proposals, preffered);
        int best = Irving::checkGrade(Lproblem[preffered], again, proposed);
        proposals.push_back(make_pair(best,preffered));
        if(best == again)
        {
            Irving::eraseReferences(Lproblem,preffered,proposed);
            possible = Irving::findNewProposal(Lproblem,proposals,proposed,possible);
        }
        else
        {
            Irving::eraseReferences(Lproblem,preffered,again);
            possible = Irving::findNewProposal(Lproblem,proposals,again,possible);
        }
    }
}

bool Irving::check_cycle(vector<int>& cycle, int i, int& start)
{
    for(int j = cycle.size()-2 ; j >= 0 ; --j)
    {
        if(cycle[j] == i)
        {
            start = j;
            return true;
        }
    }
    
    return false;
}

vector<int> Irving::solveCycle(vector<int>& cycle, int start)
{
    vector<int> aux;
    for(int i = start; i < cycle.size() ; ++i)
    {
        aux.push_back(cycle[i]);
    }
    
    return aux;
}

void Irving::findCycle(vector<list<int>>& Lproblem, int i, bool& hasCycle, vector<int>& cycle)
{
    
    list<int>::iterator it = Lproblem[i].begin();
    advance(it, 2);
    int start = 0;
    if(Lproblem[*it].size() > 2)
    {
        cycle.push_back(i);
        if(Irving::check_cycle(cycle,i,start))
        {
            hasCycle = true;
            cycle = Irving::solveCycle(cycle,start);
        }
        else
        {
            Irving::findCycle(Lproblem, *it, hasCycle, cycle);
        }
    }
}

bool Irving::check_size(vector<list<int>>& Lproblem)
{
    for(auto l : Lproblem) if(l.size() < 2) return false;
    return true;
}

bool Irving::executeAlgorithm(vector<list<int>>& Lproblem)
{
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
        if(!Irving::check_proposal(proposals,preffered))
        {
            proposals.push_back(make_pair(actual,preffered));
        }
        else
        {
            int proposed = Irving::getProposed(proposals, preffered);
            int best = Irving::checkGrade(Lproblem[preffered], actual, proposed);
            proposals.push_back(make_pair(best,preffered));
            if(best == actual)
            {
                Irving::eraseReferences(Lproblem,preffered,proposed);
                possible = Irving::findNewProposal(Lproblem,proposals,proposed,possible);
            }
            else
            {
                Irving::eraseReferences(Lproblem,preffered,actual);
                actual--;
            }
        }
        
        actual++;
        possible = Irving::check_size(Lproblem);
    }
    //Step 2
    if(possible)
    {
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
    }
    
    if(possible)
    {
        bool hasCycle = false;
        vector<int> cycle;
        
        for(int i = 0 ; i < Lproblem.size() ; i++)
        {
            if(Lproblem[i].size() > 2)
            {
                Irving::findCycle(Lproblem,i,hasCycle,cycle);
                if(hasCycle)
                {
                    for(int j = cycle.size()-1 ; j > 0 ; j -= 2)
                    {
                        Irving::eraseReferences(Lproblem, cycle[j], cycle[j-1]);
                    }
                }
            }
        }
    }
    
    return possible and Irving::check_size(Lproblem);
}

