#include<stdio.h>
#include<string.h>
#include<math.h>
typedef struct Livre{
     char titre[80];
     char auteur[100];
     float prix;
     int quantite;
}Livre ;
void ajouter(Livre livres[], int *cmp){
       int n;
       printf("vous voulez ajouter : \n 1-un element \n 2-plusieurs elements\n");
       scanf("%d",&n);
       if(n==1){
        printf("entrer le titre de livre : ");
        scanf("%s",livres[*cmp].titre);
        printf("entrer l'auteur de livre :");
        scanf("%s",livres[*cmp].auteur);
        printf("entrer le prix de livre : ");
        scanf("%f",&livres[*cmp].prix);
        printf("entrer la quantite de livre : ");
        scanf("%d",&livres[*cmp].quantite);
        printf("\n");
          (*cmp)++;
       } else {
         int nmblivres;
        printf("combiet de livre vous voulez entrer :");
        scanf("%d",&nmblivres);
        for(int i=0; i< nmblivres ; i++){
         printf("entrer le titre de livre %d : ", i+1);
        scanf("%s",livres[*cmp].titre);
        printf("entrer l'auteur de livre %d : ", i+1);
        scanf("%s",livres[*cmp].auteur);
        printf("entrer le prix de livre %d : ", i+1);
        scanf("%f",&livres[*cmp].prix);
        printf("entrer la quantite de livre %d : ", i+1);
        scanf("%d",&livres[*cmp].quantite);
        printf("\n");
          (*cmp)++;
        }
        }

}
void afficher(Livre livres[] , int cmp){
    printf("\n%-20s | %-20s | %-20s | %-20s | ","Titre", "Auteur", "Prix", "Qauntite");
    for(int i=0 ; i<cmp ; i++){
        printf("\n%-20s | %-20s | %-20f | %-20d | ",livres[i].titre,livres[i].auteur,livres[i].prix,livres[i].quantite);

    }
}
void rechercher(Livre livres[], int cmp){
    char titre[50];
    int found=-1;
    printf("qu'il est le titre de livre que vous voulez chercher : ");
    scanf("%s",titre);
    for(int i=0 ; i< cmp ; i++){
        if(strcmp(livres[i].titre , titre) == 0){
        printf("\n%-20s | %-20s | %-20f | %-20d | ",livres[i].titre,livres[i].auteur,livres[i].prix,livres[i].quantite);
        found=i;
        break;
        }
    }
    if (found<0) printf("ce livre n'est existe pas :");
}
int index_rechercher(Livre livres[],char titre[], int cmp){
    int found=-1;
    for(int i=0 ; i< cmp ; i++){
        if(strcmp(livres[i].titre , titre) == 0){
        found=i;
        break;
        }
    }
   return found;
}

void supprimer(Livre livre[] , int *cmp){
    char titre[50];
    printf("qu'il est le titre de livre que vous voulez suppremer : ");
    scanf("%s",titre);
    int found = index_rechercher(livre , titre , *cmp);
    if(found>=0){
        int valide ;
        printf("voulez-vous vraiment supprimer ce livre ? 1 - Oui 2 - Non : ");
        scanf("%d",&valide);
        if(valide==1){
        for(int j=found ; j<(*cmp)-1 ; j++){
         strcpy(livre[j].titre, livre[j+1].titre);
         strcpy(livre[j].auteur, livre[j+1].auteur);
         livre[j].prix=livre[j+1].prix;
         livre[j].quantite=livre[j+1].quantite;
            }
            (*cmp)--;
            printf("Livre supprime avec succes.\n");
        } else {
            printf("Suppression annulee.\n");
        }
    }else   printf("ce livre n'est existe pas :");
}

void modifier(Livre livre[], int cmp){
    char titre[50];
    printf("qu'il est le titre de livre que vous voulez modifier : ");
    scanf("%s",titre);
    int found = index_rechercher(livre , titre , cmp);
    if(found>=0){
            int new_qauntite;
            printf("entrer la nouvelle qauntite de ce livre : ");
            scanf("%d",&new_qauntite);
            livre[found].quantite= new_qauntite;
            printf("quantite mise a jour.\n");
    } else printf("ce livre n'est existe pas :");
}
void swap(Livre *l1, Livre *l2){
    Livre temp;
    temp = *l1;
    *l1=  *l2;
    *l2 = temp;
}
void croissant_heapSort(Livre livres[], int n){
    for(int i= n/2-1 ; i>=0 ;i--) { heap(livres , n, i);}
    for (int i = n-1; i >= 0; i--)
    {
        swap(&livres[i],&livres[0]);
        croissant_heap(livres,i,0);
    }
}
 void croissant_heap(Livre livres[],int n, int i){
    int index =i;
    int j = i*2+1;
    int k = i*2+2;
    if (j<n &&  strcasecmp(livres[j].titre ,livres[index].titre)>0) index =j;
    if (k<n &&  strcasecmp(livres[k].titre ,livres[index].titre)>0) index =k;
    if(index !=i){
        swap(&livres[i],&livres[index]);
        croissant_heap(livres , n, index);
    }
 }

 void decroissant_heapSort(Livre livres[], int n){
    for(int i= n/2-1 ; i>=0 ;i--) { heap(livres , n, i);}
    for (int i = n-1; i >= 0; i--)
    {
        swap(&livres[i],&livres[0]);
        decroissant_heap(livres,i,0);
    }
}
 void decroissant_heap(Livre livres[],int n, int i){
    int index =i;
    int j = i*2+1;
    int k = i*2+2;
    if (j<n &&  strcasecmp(livres[j].titre ,livres[index].titre)<0) index =j;
    if (k<n &&  strcasecmp(livres[k].titre ,livres[index].titre)<0) index =k;
    if(index !=i){
        swap(&livres[i],&livres[index]);
        decroissant_heap(livres , n, index);
    }
 }
void livresPlusCherEtMoinsCher(Livre livres[], int cmp) {
    if (cmp == 0) {
        printf("Aucun livre dans la collection.\n");
        return;
    }
    Livre plusCher = livres[0];
    Livre moinsCher = livres[0];
    for (int i = 1; i < cmp; i++) {
        if (livres[i].prix > plusCher.prix)  plusCher = livres[i];
        if (livres[i].prix < moinsCher.prix)  moinsCher = livres[i];
    
    }
    printf("Livre le plus cher : %s - Prix : %.2f\n", plusCher.titre, plusCher.prix);
    printf("Livre le moins cher : %s  - Prix : %.2f\n", moinsCher.titre, moinsCher.prix);
}
void nombreTotalLivres(int cmp) {
    printf("nombre total de livres : %d\n", cmp);
}
void quantiteTotaleLivres(Livre livres[], int cmp) {
    int quantiteTotale = 0;
    for (int i = 0; i < cmp; i++) {
        quantiteTotale += livres[i].quantite;
    }
    printf("quantite totale des livres : %d\n", quantiteTotale);
}
void prixTotalEtMoyenne(Livre livres[], int cmp) {
    float totPrix = 0.0;
    for (int i = 0; i < cmp; i++) {
        totPrix += livres[i].prix;
    }
    float moyPrix = totPrix / cmp;
    printf("Prix total des livres : %.2f\n", totPrix);
    printf("Prix moyen des livres : %.2f\n", moyPrix);
}
void statistique (Livre livre[], int cmp){
    int choix;
printf("\n--- Menu ---\n");
printf("1: nombre Total de Livres\n");
printf("2: prix total et moyen\n");
printf("3: le Plus Cher et le Moins Cher des livres\n");
printf("4: quantite Totale de Livres\n");
printf("0: Quitter\n");
printf("\nVeuillez entrer votre choix: ");
scanf("%d",&choix);
switch (choix)
{
case 1:
    nombreTotalLivres(cmp);
    break;
case 2:
    prixTotalEtMoyenne(livre , cmp);
    break;
case 3:
    livresPlusCherEtMoinsCher(livre , cmp);
    break;    
case 4:
    quantiteTotaleLivres(livre , cmp);
    break;    
default:
    break;
}   
}

int menu(){
int choix;
printf("\n--- Menu ---\n");
printf("1: Ajouter\n");
printf("2: Modifier\n");
printf("3: Supprimer\n");
printf("4: Rechercher\n");
printf("5: Trier\n");
printf("6: Statistique\n");
printf("0: Quitter\n");
printf("\nVeuillez entrer votre choix: ");
scanf("%d",&choix);
return choix;}


int main(){
Livre livres[150];
int cmp =0;
int choix;
do
{
choix = menu;
switch (choix)
  {
    case 1:
    ajouter(livres,&cmp);
    afficher(livres,cmp);
    break;
    case 2:
    afficher(livres,cmp);
    modifier(livres,cmp);
    afficher(livres,cmp);
    break;
    case 3:
    afficher(livres,cmp);
    supprimer(livres,&cmp);
    afficher(livres,cmp);
    break;
    case 4:
    afficher(livres,cmp);
    rechercher(livres,cmp);
    break;
    case 5:
       int n ;
       printf("Trier les livres :\n1 - Croissant (A-Z)\n2 - Décroissant (Z-A)\nChoix : ");
       scanf("%d", &n);
        if (n==1 )
        {
            croissant_heapSort(livres , cmp);
        } else {
            decroissant_heapSort(livres , cmp);
        }    
    break;
    case 6:
    statistique(livres, cmp);
    break;
  default:
    break;
  }
} while (choix != 0);
}
