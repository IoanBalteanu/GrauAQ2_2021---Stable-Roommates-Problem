#include"Generator.hh"

using namespace std;

void printTables(vector<PROBLEM>& table, int probs, int habs) {
    
    habs *= 2;
    
    cout << "### SET WITH " << probs << " PROBLEMS OF SIZE " <<  habs << " ###" <<  endl; 
    
    for (int p = 0 ; p < probs ; ++p){
        for (int i = 0; i < habs; ++i) {
            for (int j = 0; j < habs; ++j) {
                if (j < habs - 1) cout << table[p][i][j] << " ";
                else cout << table[p][i][j];
            }

            cout << endl;
        }
        
        if(p < probs-1)cout << endl;
    }
    
    cout << endl;
}

int main()
{
    int generationType = -1;
    cout << "0: One set of problems." << endl <<  "1: N sets of problems with size within [R,L] where |N| = L - R" << endl << "#R must be greater or equal to 2#" << endl <<"Choose generation type: ";
    
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
            
            vector<PROBLEM> Problems = Generator::getProblems(nProbs,nRms);
            
            printTables(Problems, nProbs, nRms);
        }
        else if (generationType == 1)
        {
            correctGT = true;
            int nProbs = 0, nRms = 0;
            cout << "Input number of problems to be generated per set: ";
            cin >> nProbs;
            
            cout << "Input minimum size of a problem (L): ";
            
            
        }
        else
        {
            cout << "Incorrect generation type, try again: ";
        }
    }
    
    return 0;
}
