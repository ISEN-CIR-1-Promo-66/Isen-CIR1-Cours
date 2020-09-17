#include <stdio.h>  
#include <stdlib.h>  
#include <locale.h>  
#include <math.h>  

// Un peu de code C pour vous donner des pistes sur la manière de manipuler et de   
// comprendre la nature binaire des données en informatique  
  

int main() {  
    // gestion des caractères accentués dans la console.  
    setlocale(LC_ALL, "fr-FR");  
    // voici une possibilité pour mettre la valeur décimale 65 dans la variable valeur1  
    // noter le préfixe 0b qui indique qu'il s'agit d'une valeur directement  
    // représentée en binaire dans votre code source.  

    unsigned char valeur1 = 0b01000001;  

    // Ce qui équivaut à écrire :  
    // unsigned char valeur1 = 65; Vérifiez cela à la calculatrice et sur le papier !  
    // Le compilateur n'a pas d'autre choix que de faire une traduction en binaire de cette valeur 65.  
    // Notez qu'en C, le type ‘char’ correspond à une valeur entière codée sur 8 bits.  
    // ce qui est aussi parfaitement adapté pour stocker le code d'un caractère ASCII, d'où le type char ..  
    // En ASCII, le code du caractère A est 65.  

    // pour obtenir de l'aide sur une fonction, sélectionnez le nom de cette fonction et   

    // appuyez sur la touche F1 en étant connecté à Internet.  

    printf(" la variable valeur1 contient la valeur %d et représente le caractère %c \n", valeur1, valeur1);  

    // Ecrire le code qui affiche la valeur binaire de valeur1  

    unsigned char tmp = valeur1; // recopie de la valeur de la variable valeur1 dans la variable tmp  

    // étudiez ce code et expliquez comment il permet de faire un affichage de valeurs en binaire,  
    // ce que ne permet pas la commande printf  
    // A quoi sert l'opérateur / ?  
    // A quoi sert l'opérateur % ?  
    // Vérifiez que tmp = tmp % 128 peut aussi s'écrire tmp %= 128  

  

    printf("\n Ce qui donne en binaire (version 1 :\n");  

  

    printf("%u", tmp / 128); tmp %= 128;  
    printf("%u", tmp / 64); tmp %= 64;  
    printf("%u", tmp / 32); tmp %= 32;  
    printf("%u", tmp / 16); tmp %= 16;  
    printf("%u", tmp / 8); tmp %= 8;  
    printf("%u", tmp / 4); tmp %= 4;  
    printf("%u", tmp / 2); tmp %= 2;  
    printf("%u", tmp % 2);  
    printf("\n");  

    // autre méthode qui utilise l'opérateur de décalage de bits  
    tmp = valeur1; // on replace la valeur 65 d'origine dans tmp  
    printf("\n Ce qui donne en binaire (version 2) :\n");  

    // expliquez le principe de fonctionnement de l'expression : variable = condition ? valeur1 : valeur2  
    // A quoi sert l'opérateur bit à bit ‘&’ de dans ce contexte ?   
    // A quoi sert l'opérateur << ?  

    printf("%u", (tmp & 128) == 0 ? 0 : 1);  
    tmp <<= 1;  
    printf("%u", (tmp & 128) == 0 ? 0 : 1);  
    tmp <<= 1;  

  

    // Ecrire la suite afin de traiter l’ensemble des bits   

  

  

    // Qu'est-ce que le bit de poids fort, MSB ?  
    // calcul du poids représentée par le bit de poids fort (MSB) dans un octet :  

  

    // Quelle valeur est fournie par sizeof pour le type ou la variable entre parenthèses ?  

  

    int nbOctets = sizeof(unsigned char);  

    int nbBits = nbOctets * 8;  

  

    int valeurMSB = (int)pow(2.0, (double) (nbBits) - 1);  

    printf("\n Le poids du MSB avec pow dans un octet est %d", valeurMSB);  

  

    // calcul de la valeur du bit de poids fort - version 2  

  

    valeurMSB = 1 << (nbBits - 1); // Que se passe t-il ici ?  

  

    printf("\n La valeur du MSB avec décalage à gauche de 1 , %d fois, est %d\n", nbBits - 1, valeurMSB);  

  

    // mettez un point d'arrêt et  

    // déroulez ce programme pas-à-pas en observant la valeur des variables locales pour mieux comprendre  

    printf("\n Ce qui donne en binaire (version 3) :\n");  

    tmp = valeur1;  

    for (int i = 0; i < nbBits; i++) {  

        printf("%u", (tmp & valeurMSB) == 0 ? 0 : 1);  

        tmp <<= 1;  

    }  

    // OK, ceci est une boucle POUR ! :-)  

    system("pause");  

  

    return(EXIT_SUCCESS);  

}  
