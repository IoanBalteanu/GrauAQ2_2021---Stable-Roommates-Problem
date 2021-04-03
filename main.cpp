#include"Generator.hh"

using namespace std;

void printTables(vector<LProblemSet>& table, int probs) {
    
    /*int habs = 0;
    
    for(int i = 0 ; i < table.size() ; ++i)
    {
        habs = table[i][0][0].size();
        cout << endl << "### SET WITH " << probs << " PROBLEMS OF SIZE " <<  habs << " ###" <<  endl << endl;
        for(int j = 0 ; j < probs ; ++j)
        {
            for(int k = 0 ; k < habs ; ++k)
            {
                for(int l = 0 ; l < habs ; ++l)
                {
                    if(l < habs - 1) cout << table[i][j][k][l] << " ";
                    else cout << table[i][j][k][l];
                }
                cout << endl;
            }
            cout << endl;
        }         
    }*/
    
    for(LProblemSet ps : table)
    {
        for(LProblem lp : ps)
        {
            for(list<int> row : lp)
            {
                for(int pos : row)
                {
                    cout << pos << " ";
                }
                cout << "\b" << ""; 
                cout << endl;
            }
            cout << endl;
        }
    }
}

int main()
{
    srand(time(0));
    int generationType = -1;
    cout << "0: One set of problems." << endl <<  "1: N sets of problems with size within [L,R] where |N| = R - L + 1" << endl <<"Choose generation type: ";
    
    bool correctGT = false;
    
    while(!correctGT)
    {
        cin >> generationType;
        
        if(generationType == 0)
        {
            correctGT = true;
            int nProbs = 0, nRms = 0;
            cout << "Input number of problems to be generated: ";
            cin >> nProbs;
            cout << "Input number of available rooms: ";
            cin >> nRms;
            
            LProblemSet problems = Generator::getProblems(nProbs,nRms);
            vector<LProblemSet> out;
            out.push_back(problems);
            printTables(out, nProbs);
        }
        /*else if (generationType == 1)
        {
            correctGT = true;
            int nProbs = 0, L = 0, R = 0;
            cout << "Input number of problems to be generated per set: ";
            cin >> nProbs;
            
            while(L < 2){
                cout << "Input minimum size of a problem (L). Must greater or eaqual to 2: ";
                cin >> L;
            }
            
            cout << "Input maximum size of a problem (R): " ;
            cin >> R;
            
            vector<ProblemSet> out;
            
            while(L <= R){
                out.push_back(Generator::getProblems(nProbs,L));
                L++;
            }
            
            printTables(out, nProbs);
            
        }*/
        else
        {
            cout << "Incorrect generation type, try again: ";
        }
    }
    
    return 0;
}
