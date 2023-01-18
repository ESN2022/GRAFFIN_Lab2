# GRAFFIN_Lab2


Report content:
a. Introduction
b. System architecture:
QSYS components and their interaction, HW blocks, design choices
c. Progress, results (take photos if needed)
d. Conclusion: What have you learned, comment progress, pitfalls and solutions

###Introduction

Dans ce deuxième Lab, je vais mettre en œuvre un flow de conception dans un autre exemple simple : l'afficheur 7 segment. Je vais utiliser la carte de développement DE10 Lite avec son FPGA. Je vais aussi utiliser la suite d'intel : Quartus 18.1 avec Platform Designer. Le but est ainsi d'afficher un timer sur les afficheurs 7 segements présents sur la carte de développement DE10 Lite. 

###Architecture

Pour ce deuxième Lab, j'ai utilisé un Nios2 avec ses périphériques nécessaire pour fonctionner : Mémoire RAM, JTAG debugger, Clock. Pour interfacer l'autre  périphérique (7 segement) j'ai utilisé un PIO, pour la partie QSYS et ensuite un programe vhdl qui convertie les valeurs donnée par le nios en un signal affichable sur les 7 segements. Le tout communiquant avec le bus Avalon. Le montage final sur Platform Designer se trouve sur l'image ci-dessous avec le schéma:


![image](https://user-images.githubusercontent.com/75631006/213161743-562d3302-e02c-4fc2-a474-70bfbb9adcfd.png)


![image](https://user-images.githubusercontent.com/75631006/212274691-0b18c7d9-08c7-44fa-b067-af03dfee2df5.png)

J'ai utilisé un seul PIO pour gérer les 3 périphérique 7 segements car ce sont les même périhpérique, qui ont la même direction et qui sont lié.
Pour convertir ce qui était généré par le nios2 sur la pio j'ai utilisé un bloc HW qui me permet de convertir le binaire qui sort de la PIO en signal permettant d'affiché le chiffre sur les 7 segement.

https://user-images.githubusercontent.com/75631006/212300353-1117d11b-96de-4171-87d6-44dfa58e506a.mp4


![image](https://user-images.githubusercontent.com/75631006/212274613-f78a5d1d-ba8a-4da9-94af-4430d4c6f589.png)

![image](https://user-images.githubusercontent.com/75631006/212288358-5158ec74-512a-4edc-b7ff-9e2418e4daca.png)




https://user-images.githubusercontent.com/75631006/212300363-69cf2f32-0520-4773-a05d-f53c7b33cbb0.mp4



https://user-images.githubusercontent.com/75631006/212300366-5657d34c-83e4-4f22-b72f-1b39a9ce7b16.mp4






