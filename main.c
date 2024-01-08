#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"datePost2000.h"

//<>
int main(){
    int annee=2023,mois=10,jour=12;

  //  printf("Entrez une date(jour mois annee):\n");
  //  scanf("%d %d %d",&jour,&mois,&annee);

    int D=decalage_annee(annee)+decalage_seculaire(annee)+decalage_bissextile(annee,mois)+decalage_mois(annee,mois)+decalage_jour(jour);
    
    char*andro=getResult(D);
    
    return 0;
}