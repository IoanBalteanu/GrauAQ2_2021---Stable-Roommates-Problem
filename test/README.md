# PracticaAQ2_2021
## R
### Execució
  - cd R/
  - Rscript script_GeneradorIrving.R
  - Rscript script_Analisis.R

Requeriments scripts R:
  - script_GeneradorIrving.R -> library(matchingR), es pot instal.lar fent install.packages("matchingR")
  - script_Analisis.R        -> library(ggplot2),   es pot instal.lar fent install.packages("ggplot2")

Recommanació: executar R fent `R` en la consola i fer els dos install.packages("matchingR") i install.packages("ggplot2")

Continguts:
  - script_GeneradorIrving.R > fa la generació de solucions i posteriorment executa l'algoritme de Irving per solucionar cada problema generat.
  - script_Analisis.R -> llegeix els fitxer experiment_size_11.csv que fa l'altre script, fa els testos, els fa print i guarda les figures.

Recommanació: No es recomana executar el script Analisis d'aquesta forma, es millor si s'obra amb R i es van llegint els comentaris per entendre els experiments realitzats i els seus outputs. Per executar el script d'analisi, tambe incorporem el fitxer experiment_size_11.csv que es el resultat del script generador.


## C++
### Execució
  - cd cpp/
  - make       (ignorar el warning)
  - ./Program

Generació de problemes:
  - Generar m problemes de mida n.
  - Els problemes tenen la forma d'una array de mida n x n i es guarden en un vector de mida m.
  - Aquest vector es la sortida del programa de generació i la entrada del programa que gestiona l'algorisme principal.

Estructura del programa :
  - Generació de problemes -> classe c++ amb mètodes estàtics per evitar la creació d'objectes "Generador"  (Generador.cpp, Generador.h)
  - Execució de problemes -> classe c++ amb mètodes estàtics per evitar la creació d'objectes "Martens" (Martens.cpp, Martens.h)
  - Càlcul de resultats i visualització d'aquests -> script Python. 
  - Main c++ que gestioni la greació de problemes aleatories, l'execució de l'algorisme, i la generació de resultats contra els que s'executará un script


## Estructura de GITHUB
1.Branca main òn es guardar la primera instància d'un programa complert (es pot prescindir del script python en aquesta instància).
2.és creara una branca dev idèntica a la main que s'anira canviant cada vegada que es faci un canvi en el codi o documentació, per aixi poder testejar canvis mantenint sempre una còpia d'un programa funcional a la branca main.
3.Per fer canvis a dev s'han de crear altres branques (basades en dev)  i un cop els canvis estiguin fets, fer una pull request a dev per fusionar les branques(això és per la situació òn haguem de fer canvis al mateix arxiu, poder fer-ho a al vegada, sino es poden generar problemes de fusió.)
