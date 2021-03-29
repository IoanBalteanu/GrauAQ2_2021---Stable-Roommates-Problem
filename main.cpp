#include"Generator.hh"

using namespace std;

void printTables(vector<vector<vector<int>>>& table, int probs, int habs) {
    
    habs *= 2;
    
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
}

int main()
{
    int nProbs = 0, nRms = 0;
    cout << "Input number of problems to be generated: ";
    cin >> nProbs;
    cout << "Input number of available rooms: ";
    cin >> nRms;
    
    vector<vector<vector<int>>> Problems = Generator::getProblems(nProbs,nRms);
    
    printTables(Problems, nProbs, nRms);
    
    return 0;
}
