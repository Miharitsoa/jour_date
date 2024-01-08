#ifndef __DATEPOST2000_H_
#define __DATEPOST2000_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//<>

//Bibliothèques permettant de déterminer le jour d'une date donnée après l'année 2000
/* La date dont nous nous refereront est le 1er Janvier 2000 qui est un samedi. 
Le principe est de savoir le principe des décalages, des notions
sur les années comme les années séculaires et bissextiles. Alors, vous devez vous documenter sur
ces requis pour pouvoir comprendre les fonctions fournies par cette bibliothèque même pour son analogue qui fait l'inverse
c'est à dire détermine le jour d'une date qui est avant l'annnée 2000. */

//Ces deux tableaux représentent deux tableaux qui correspondent aux décalages dans les 12 mois, dans L1 pour une année 
//civile et dans L2 pour une année bissextile.
int L1[12]={3,0,3,2,3,2,3,3,2,3,2,3};
int L2[12]={3,1,3,2,3,2,3,3,2,3,2,3};

/*//Codons les jours comme suivant en allant du dimanche au samedi
int codeJour[7]={0,1,2,3,4,5,6};
char jour[7][15]={"Alahady","Alatsinainy","Talata","Alarobia","Alakamisy","Zoma","Sabotsy"};
*/

//Les fonctions à utiliser pour trouver le résultat attendu
int decalage_annee(int annee){
    int annee1=annee-2000;
    return annee1;
}

int decalage_seculaire(int annee){
    int count=0;
    int count1=0;
    for(int i=2000;i<=annee;i++){
        int nombre=i;
        if(nombre%100==0){
            count++;
        }
        if(((nombre%100==0) && (nombre%4==0))){
            count1++;
        }
    }
    int D=-count+count1-2;
    return D;
}

int decalage_bissextile(int annee,int mois){
    int count2=0;
    for(int i=2001;i<=annee;i++){
        if(i%4==0){
            count2++;
        }
    }
    int D=count2;
    if(annee%4==0 && mois<=2){
        D=D-1;
    }
    else 
        D=D+0;
    return D;
}

int decalage_mois(int annee,int mois){
    int D1;
    if(annee%4!=0){
        for(int i=0;i<=mois-1;i++){
            D1+=L1[i];
        }
    }
    else{
        for(int i=0;i<=mois-1;i++){
            D1+=L2[i];
        }
    }
    return D1;
}

int decalage_jour(int jour){
    int D2;
    D2=jour-1;
    return D2;
}

char*getResult(int D2){
    int n=D2%7;
    char jours[7][15]={"Sabotsy","Alahady","Alatsinainy","Talata","Alarobia","Alakamisy","Zoma"};
    char*result;
    for(int i=0;i<7;i++){
        if(n==i){
            result=jours[i];
        }
    } 
    printf("%s\n",result);
    return result;
}

#endif