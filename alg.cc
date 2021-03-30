#include<iostream>
#include<vector>

using namespace std;

typedef vector<bool> F; //VECTOR DE BOOL PARA COMPROBAR SI ESTA APAREJADO O NO (NO SE USA)
typedef vector<int> Prioritats; 
typedef vector<Prioritats> Problema; //CONJUNTO PROBLEMA
typedef vector<int> Parella; //GUARDA EN LA POSICION i EL INDICE DE LA PAREJA DE i
typedef vector<int> Grado; //GUARDA PARA CADA PERSONA LA PRIORIDAD A LA CUAL ESTA SU PAREJA

void Inicialitar(Problema& p){
    for(int i = 0; i < p.size(); ++i){
        for(int j = 0; j < p[0].size(); ++j){
            cin >> p[i][j];
        }
    }
}

void printParelles(Parella Par){
    for(int i = 0; i < Par.size(); ++i){
        cout << i << " es parella de -> " << Par[i] << endl;
    }
}

bool es_estable(Problema p,  Parella& Par, Grado& G){
    for(int fila = 0; fila < Par.size(); ++fila){
        //cout << fila << endl;
        if(Par[fila] == -1){       //si esta persona no tiene pareja               
          
            bool ok = false;
            for(int columna = 1; columna < p[fila].size() and !ok; ++columna){ //comprovamos preferencias
                ok = false;
                if(Par[p[fila][columna]] == -1){ //si la preferencia no tiene pareja adjudicamos la pareja
                        ok = true;
                        G[fila] = columna;  //Grado de preferencia
                        Par[fila] = p[fila][columna]; 
                       //cout << fila << " tiene como pareja " << Par[fila] << endl;
                        Par[p[fila][columna]] = fila;
                        //cout << p[fila][columna] << " tiene como pareja " << Par[p[fila][columna]] << endl;
                       bool acabar = false;
                        for(int aux = 1; aux < p[p[fila][columna]].size() and !acabar; ++aux){
                          //  cout << "AAH" <<endl;
                           // cout << p[fila][columna] << " " << aux << endl;
                        if(p[p[fila][columna]][aux] == fila){    //Buscamos en que preferencia se encuentra el primer integrante de la pareja respecto al segundo
                            G[p[fila][columna]] = aux;  //Grado de preferencia
                            //cout << p[fila][columna] << " tiene grado " << aux << endl;
                            acabar = true;
                            }
                        }
                        
                        //columna = p[fila].size();
                      
                }
                
                else{ //si tiene pareja comprovamos si prefiere a la que tiene o no
                    
                    //cout << "EL VALOR DE fila ES = " << fila << " JAJAJAJ" << endl;
                    //cout << "EL VALOR DE columna ES = "<< columna << " JEJEJEJEJ " << endl;
                    
                    for(int columnaAux = 1; columnaAux < p[p[fila][columna]].size() and !ok; ++columnaAux){ //comprovamos preferencias del segundo integrante de la pareja
                        
                        if(p[p[fila][columna]][columnaAux] == fila){ //hemos encontrado a la persona que queremos comprovar si la quiere como pareja o no
                            
                            if(columnaAux < G[p[fila][columna]]){ //prefiere a esta persona que a la otra
                           // cout << "ADIOS"  << endl;
                                G[p[fila][columna]] = columnaAux; //actualizamos preferencia
                             //   cout << p[fila][columna] << " tiene grado nuevo " << G[p[fila][columna]] << endl;
                               // cout << Par[Par[fila]]<< endl;
                                Par[Par[fila]] = -1; //borramos pareja anterior
                               // cout << "la pareja anterior era " << Par[fila] << endl;
                                G[p[fila][columna]] = 0;
                                Par[p[fila][columna]] = fila;  //ponemos a true el nuevo integrante de la pareja
                                Par[fila] = p[fila][columna];
                                fila = Par[fila] - 1;
                               // cout << "VALOR DE REINICIO DE FILA = "  << fila << endl;
                                ok = true;
                            }
                            
                        }
                    }
                }

            }
            if (not ok) return false; //se han descartado todas las parejas
        }
    }
    return true;
                            
                    
}

int main(){
    int n;
    cin >> n;
    Parella Par (2*n,-1);
    Problema p (2*n,Prioritats(2*n));
    Grado G(2*n,2*n);
    Inicialitar(p);
    if(es_estable(p,Par,G)) printParelles(Par);
    
    else cout << "Parella no estable" << endl;
    
}
