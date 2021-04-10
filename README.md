# PracticaAQ2_2021
Generació de problemes:
  - Generar m problemes de mida n.
  - Els problemes tenen la forma d'una array de mida n x n i es guarden en un vector de mida m.
  - Aquest vector es la sortida del programa de generació i la entrada del programa que gestiona l'algorisme principal.

Algorimse principal:

Estructura del programa :
  - Generació de problemes -> classe c++ amb mètodes estàtics per evitar la creació d'objectes "Generador"  (Generador.cpp, Generador.h)
  - Execució de problemes -> classe c++ amb mètodes estàtics per evitar la creació d'objectes "Martens" (Martens.cpp, Martens.h)
  - Càlcul de resultats i visualització d'aquests -> script Python. 
  - Main c++ que gestioni la greació de problemes aleatories, l'execució de l'algorisme, i la generació de resultats contra els que s'executará un script Python per la comapració i visualització de les dades. ###SI DONA TEMPS, PROVAR DE FER-HO DE FORMA PRAL·LELA###

Script R:
  - generador_solver.R -> fa la generació de solucions i posteriorment executa l'algoritme de Irving per solucionar el problema. 
  - analisis.R -> llegeix els fitxers que surten del generador_solver, fa els testos i els fa print.

#Estructura de GITHUB
1.Branca main òn es guardar la primera instància d'un programa complert (es pot prescindir del script python en aquesta instància).
2.és creara una branca dev idèntica a la main que s'anira canviant cada vegada que es faci un canvi en el codi o documentació, per aixi poder testejar canvis mantenint sempre una còpia d'un programa funcional a la branca main.
3.Per fer canvis a dev s'han de crear altres branques (basades en dev)  i un cop els canvis estiguin fets, fer una pull request a dev per fusionar les branques(això és per la situació òn haguem de fer canvis al mateix arxiu, poder fer-ho a al vegada, sino es poden generar problemes de fusió.)

Ens podem estalviar aquestes restriccions si els canvis són petits i molt clars, com pot ser un ; que falta, o una referència mal posada, pero en general si la podem seguir millor.

Més endavant també es pot fer servir per donar les instruccions de compilació i execució.
