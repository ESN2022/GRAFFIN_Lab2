# GRAFFIN_Lab2


## Introduction

Dans ce deuxième Lab, je vais mettre en œuvre un flow de conception dans un autre exemple simple : l'afficheur 7 segments. Je vais utiliser la carte de développement DE10 Lite avec son FPGA. Je vais aussi utiliser la suite d'intel : Quartus 18.1 avec Platform Designer. Le but est ainsi d'afficher un timer sur les afficheurs 7 segments présents sur la carte de développement DE10 Lite. 

## Architecture

Pour ce deuxième Lab, j'ai utilisé un Nios2 avec ses périphériques nécessaire pour fonctionner : Mémoire RAM, JTAG debugger, Clock. Pour interfacer l'autre  périphérique (7 segments) j'ai utilisé un PIO, pour la partie QSYS et ensuite un programme vhdl qui convertit les valeurs données par le nios en un signal affichable sur les 7 segments. Le tout communiquant avec le bus Avalon. Le montage final sur Platform Designer se trouve sur l'image ci-dessous avec le schéma:

![image](https://user-images.githubusercontent.com/75631006/213161743-562d3302-e02c-4fc2-a474-70bfbb9adcfd.png)

![image](https://user-images.githubusercontent.com/75631006/213637512-8a64f5a0-683b-4687-a750-cb61247dd039.png)

J'ai utilisé un seul PIO pour gérer les 3 périphérique 7 segments, car ce sont les même périhpérique, qui ont la même direction et qui sont liées.
Pour convertir ce qui était généré par le nios2 sur la pio j'ai utilisé un bloc HW qui prend le binaire qui sort de la PIO et le transforme en signal permettant d'afficher le chiffre sur un afficheur 7 segments.


## Progress

### Etape 1

La première étape dans ce Lab était d'afficher un compteur sur un seul afficheur 7 segments. Pour cela, j'ai paramétré le PIO du système QSYS en 4 bit, car un afficheur ne peut aller jusqu'à 9. Ainsi, la première étape niveau soft est juste un simple compteur qui écrit dans la PIO. Voici la vidéo du système fonctionnant : 

https://user-images.githubusercontent.com/75631006/212300353-1117d11b-96de-4171-87d6-44dfa58e506a.mp4


### Etape 2

La deuxième étape est d'ajouter les deux autres afficheur 7 segments pour compter jusqu'à 999. Ici, c'est juste une extention de la première étape, cependant, il faut faire attention aux valeurs qu'on envoie de la PIO vers le bloc HW. En effet, si on envoie 10,11,12..., c'est la valeur binaire qui est lue donc l'afficheur voudrat afficher A,B,C,...,F. Ainsi il faut faire en sort que le code C envoie bien la valeur binaire 0001 0000 pour afficher 10, et non 1010. Ainsi, j'obtiens le résultat sur la vidéo ci-dessous :

https://user-images.githubusercontent.com/75631006/212300363-69cf2f32-0520-4773-a05d-f53c7b33cbb0.mp4


### Etape 3


La dernière étape était d'ajouter le Timer pour cadencer le compteur écrit dans le code en C. Pour cela, j'ai modifié l'architecture de mon projet, en ajoutant un timing au QSYS, comme on peut le voir ci-dessous : 

![image](https://user-images.githubusercontent.com/75631006/213637602-73dd2842-2b76-4202-bd4f-5d66371f970d.png)

On obtient le résultat final ci-desous:

https://user-images.githubusercontent.com/75631006/212300366-5657d34c-83e4-4f22-b72f-1b39a9ce7b16.mp4



## Conclusion

Dans ce Lab, j'ai appris à utiliser un PIO pour donner une information à un bloc hardware qui sera une nouvelle fois traité après celui-ci, dans notre cas pour afficher sur un afficheur 7 segments. J'ai aussi apris à utiliser un timer pour cadencer le code C à une vitesse donnée. J'ai pu aussi approfondir ce qui j'avais appris dans le Lab 1 avec les PIO. Je suis arrivé au bout de ce Lab avec quelque difficulté lors de la conversion à l'étape 2, pour passer afficher 10 après 9 sur l'afficheur.
