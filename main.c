#include <stdio.h>
#include <stdlib.h>

typedef struct elm {
    int info;
    struct elm* svt;
}Liste;



Liste* initialier_liste(int val) {
    Liste*  NE;
    NE =(Liste*)malloc(sizeof(Liste)); //Allocation memoire new elem;
    if (!NE) {
        printf("Error d'allocation memoire!!");
        exit(0);
    }
    NE->info = val;
    NE->svt = NULL;
    return NE;
}

Liste* Inserer_Debut_Liste(Liste*L,int val) {
    Liste*NE;
    NE = initialier_liste(val); //Appel pour inilialiser la liste;
    NE->svt = L;
    L = NE;

};//fin de la fonction;

Liste *Inserer_Fin_Liste(Liste*L1,int val) {
    Liste*NE=NULL;
    Liste *crt=NULL;
    NE = initialier_liste(val);
    crt=L1;
    if (L1 == NULL) {//Si laliste vide donc return NE;
        return NE;
    }
    while (crt->svt) { //Tant qu'il ya des elements dans la liste, alors enteste sur le svt de crt
        crt = crt->svt; //s'il n'existe pas on affecte NE Comme son suivant.
    }
    crt->svt = NE;
    return L1;
}//fin de la fonction;
int Taille_Liste(Liste*L) {
    if (!L) {

    }
    Liste*CRT;
    CRT = L;
    int T=1;
    while (CRT->svt) {
        CRT = CRT->svt;
        T++;
    }
    return T;
}
Liste*Inserer_pos_Liste(Liste*L,int val,int pos) {
    Liste*NE=NULL;
    Liste *crt=NULL;
    crt = L;

    NE = initialier_liste(val);
    if (!L) {
        printf("la liste etait vide: \n");
        return NE;
    }
    else if (pos<0 || pos>Taille_Liste(L)) {
        printf("La position n'existe pas!!\n");
    }
    else if (pos == 1) {
        L = Inserer_Debut_Liste(L,val);
    }
    else if (pos == Taille_Liste(L)) {
        L = Inserer_Fin_Liste(L,val);
    }
    else {
        for (int i=2;i<pos;i++) {
            crt=crt->svt;
        }
        NE->svt = crt->svt;
        crt->svt = NE;

    }
    return L;
}

Liste*Suppression_au_debut(Liste*L)
{
    Liste*crt;
    crt = L;
    if (!L) {
        printf("La liste n'existe pas!!\n");
        exit(0);
    }
    L->svt = crt->svt;
    crt->svt = NULL;
    free(crt);
    return L;

}//FIN  DE LA FONCTION


void Afficher_Liste(Liste*L3) {
    Liste*crt=NULL;//
    crt = L3;
    printf("Ma Liste: ");
    while (crt) {
        printf("%d ",crt->info);
        crt = crt->svt;
    }
    printf("\n");

}
void AfficherInverser(Liste*L)
{
    if (L == NULL) return;
    AfficherInverser(L->svt);
    printf(" %d",L->info);

}//

Liste* InverseListe(Liste*L) {
    Liste*prec=NULL;
    Liste*crt=L;
    Liste*suiv=NULL;
    while (crt != NULL) {
        suiv = crt->svt;
        crt->svt = prec;
        prec = crt;
        crt = suiv;
    }
    return prec;

}
void AfficherInverse(Liste*L) {
    Liste*crt = L;
    L= InverseListe(L);
    while (crt) {
        printf("%d",crt->info);
        crt = crt->svt;

    }
}//

void LibererListe(Liste*L) {
    Liste *crt = L;
    Liste *supp =NULL;
    while (crt->svt) {
        L = crt->svt;
        crt->svt = NULL;
        free(crt);
    }
}

Liste*SupprimerDoublons(Liste*L) {
    Liste*crt=NULL;
    Liste*Temp = L;
    if (L == NULL) {
        return NULL;
    }

}

/*------------------------Les Piles-----------------------*/
typedef struct pl {
    int info;
    struct pl* svt;
}Pile;


Pile* Creer_init_Pile(int val) {
    Pile *sommet;
    sommet = (Pile*)malloc(sizeof(Pile));
    if (!sommet) {
        printf("\nErreur d'allocation memoire");
        exit(0);
    }
    sommet->svt=NULL;
    sommet->info = val;
    return ((Pile*)sommet);
}

Pile* Empiler_Pile(Pile*mapile,int val) {
    Pile *NE;
    NE = Creer_init_Pile(val);
    if (!mapile) return((Pile*)NE);
    NE->svt = mapile;
    return ((Pile*)NE);
}

Pile* Depiler_Pile(Pile*mapile) {
    Pile* ptr = NULL;
    if (!mapile) return((Pile*)NULL);
    ptr = mapile;
    mapile=mapile->svt;
    //ptr->svt = NULL;
    free(ptr);
    return ((Pile*)mapile);
}

Pile*Empiler_Pile_cellule(Pile *mapile,Pile*Npile) {
    if (!mapile)return((Pile*)NULL);
    Pile*Crt=mapile;
    mapile=mapile->svt;
    Npile=Crt;
    Crt->svt=NULL;
    return ((Pile*)Npile);
}
// Pile*est_vide_Pile(Pile *Mapile) {
//
// }

void Afficher_Pile(Pile* Mapile) {
    Pile* crt=NULL;
    int i=0;
    // if (est_vide_Pile(*Mapile)) {
    //     printf("La pile est vide!!\n");
    // }
    while (Mapile) {
        printf("Element[%d]=%d \n",i,Mapile->info);
        crt = Empiler_Pile(Mapile,Mapile->info);
        Mapile = Depiler_Pile(Mapile);
        i++;
    }
    while (crt) {
        Mapile=Empiler_Pile(Mapile,crt->info);
        crt = Depiler_Pile(crt);
    }
}

Pile*Inverser_Pile(Pile*p) {
    Pile*crt1=NULL;
    Pile*crt2=NULL;
    while (p) {
        crt1=Empiler_Pile(crt1,p->info);
        p=Depiler_Pile(p);
    }
    while (crt1) {
        crt2=Empiler_Pile(crt2,crt1->info);
        crt1=Depiler_Pile(crt1);
    }
    while (crt2) {
        p=Empiler_Pile(p,crt2->info);
        crt2=Depiler_Pile(crt2);
    }
    return ((Pile*)p);

}

Pile* Afficher_Pilee(Pile* Mapile) {
    Pile* aux = NULL;
    int i = 0;

    // Dépiler, afficher, stocker dans aux
    while (Mapile) {
        printf("Element[%d] = %d\n", i, Mapile->info);
        aux = Empiler_Pile(aux, Mapile->info);
        Mapile = Depiler_Pile(Mapile);
        i++;
    }

    // Reconstituer la pile d'origine
    while (aux) {
        Mapile = Empiler_Pile(Mapile, aux->info);
        aux = Depiler_Pile(aux);
    }

    return Mapile; // Retourner la pile reconstruite
}
void Afficher_recursivement_pile(Pile*Mapile) {
    if (!Mapile)return;
    printf("L'element: %d\n",Mapile->info);
    Mapile=Depiler_Pile(Mapile);///DESTROY THE PILE
    Afficher_recursivement_pile(Mapile);
    exit(0);

}



int pos_elemet_pile(Pile **Mapile, int val) {
    int pos = 1;
    int k = -1;

    Pile *courant = NULL;
    Pile *p = *Mapile;

    // Dépiler en cherchant
    while (p) {
        if (p->info == val)
            k = pos;

        courant = Empiler_Pile(courant, p->info);
        p = Depiler_Pile(p);
        pos++;
    }

    // Reconstruire la pile d'origine
    while (courant) {
        *Mapile = Empiler_Pile(*Mapile, courant->info);
        courant = Depiler_Pile(courant);
    }

    return k;
}


int NbOccurence_val(Pile* Mapile, int val) {
    int NbOcc = 0;
    Pile* aux = NULL;

    // Dépiler la pile pour compter
    while (Mapile) {
        if (Mapile->info == val)
            NbOcc++;

        aux = Empiler_Pile(aux, Mapile->info);
        Mapile = Depiler_Pile(Mapile);
    }

    // Restaurer la pile originale
    while (aux) {
        Mapile = Empiler_Pile(Mapile, aux->info);
        aux = Depiler_Pile(aux);
    }

    return NbOcc;
}


///---------------------------LES FILES------------------------------
typedef struct cl {
    int info;
    struct cl*svt;
}Cellule;
typedef struct fl {
    Cellule *debut;
    Cellule* fin;
}File;

Cellule* Creer_Cellule(int val) {
    Cellule* NE = (Cellule*)malloc(sizeof(Cellule));
    if (NE == NULL) {
        // Gérer l'échec de l'allocation mémoire
        return NULL;
    }
    NE->info = val;
    NE->svt = NULL;
    return NE;
}


File* Creer_initia_file() { // Simplification: ne prend pas de paramètre inutile
    File* F = (File*)malloc(sizeof(File));
    if (F == NULL) {
        return NULL; // Échec de l'allocation
    }
    F->debut = NULL;
    F->fin = NULL;
    return F;
}


int Est_vide_file(File* F) {
    // Il suffit de vérifier un seul des pointeurs car ils doivent toujours être cohérents
    if (F == NULL || F->debut == NULL) {
        return 1;
    }
    return 0;
}


int Enfiler_file(File* F, int valeur) {
    if (F == NULL) {
        return -1; // La file n'existe pas
    }
    Cellule* NE = Creer_Cellule(valeur);
    if (NE == NULL) {
        return -1; // Échec de la création de la cellule
    }

    // Si la file est vide, le nouveau nœud devient le début ET la fin
    if (Est_vide_file(F)) {
        F->debut = NE;
        F->fin = NE;
    }
    // Sinon, on l'ajoute après l'élément de fin actuel et on met à jour le pointeur fin
    else {
        F->fin->svt = NE;
        F->fin = NE;
    }
    return 1;
}


int Defiler_file(File* F) {
    Cellule* C = NULL;
    if (F == NULL) {
        return -1; // File inexistante
    }
    if (Est_vide_file(F)) {
        return 0; // File vide
    }

    C = F->debut; // Cellule à libérer
    F->debut = F->debut->svt; // Le nouveau début est le suivant

    // Si le début est devenu NULL, cela signifie que la file est devenue vide,
    // il faut donc aussi mettre à jour le pointeur fin à NULL.
    if (F->debut == NULL) {
        F->fin = NULL;
    }

    free(C);
    return 1;
}


int Afficher_File(File* FL) {
    if (FL == NULL || Est_vide_file(FL)) {
        printf("La file est vide.\n");
        return 0;
    }

    Cellule* C_courant = FL->debut;
    printf("Contenu de la file (DEBUT -> FIN): ");
    while (C_courant != NULL) {
        printf("%d", C_courant->info);
        if (C_courant->svt != NULL) {
            printf(" -> ");
        }
        C_courant = C_courant->svt;
    }
    printf("\n");
    return 1;
}

// --- Fonction Principale ---

int main(void) {
    /*--------------FILE----------*/
    // int verif = -5;
    // File* f1 = NULL; // Initialiser f1 à NULL
    //
    // // 1. **Correction essentielle:** Créer et initialiser la file
    // f1 = Creer_initia_file();
    // if (f1 == NULL) {
    //     printf("Erreur d'allocation pour la file.\n");
    //     return 1;
    // }
    //
    // //printf("Opérations d'enfilement:\n");
    // Enfiler_file(f1, 1);
    // Enfiler_file(f1, 9);
    // Enfiler_file(f1, 3);
    // Enfiler_file(f1, 2);
    // Enfiler_file(f1, 8);
    //
    // //printf("\n--- Affichage initial ---\n");
    // verif = Afficher_File(f1);
    //
    // //printf("\n--- Opération de défilement ---\n");
    // if (Defiler_file(f1) == 1) {
    //     printf("Element défilé avec succès.\n");
    // }
    //
    // //printf("\n--- Affichage après défilement ---\n");
    // Afficher_File(f1);






    /*--------------------------Pile-----------------------*/
    Pile* PL;
    PL = Creer_init_Pile(8);
    PL=Empiler_Pile(PL,5);
    PL=Empiler_Pile(PL,5);
    PL=Empiler_Pile(PL,3);
    PL=Empiler_Pile(PL,9);
    PL=Empiler_Pile(PL,5);
    PL=Empiler_Pile(PL,3);
    //Afficher_recursivement_pile(PL);
    PL=Inverser_Pile(PL);
    Afficher_Pile(PL);
    // // PL=Empiler_Pile(PL,1000);
    // // Afficher_recursivement_pile(PL);
    //
    //
    // int posi=0;
    // posi = pos_elemet_pile(&PL,3);
    // printf("\n La position de l'element 29 dans la pile est:%d",posi);
    // int nbocc=-1;
    // nbocc = NbOccurence_val(PL,3);
    // printf("\n Le nombre d'occurence de 3 est:%d",nbocc);

    /*--------------------------Listes-----------------------*/

    // Liste*L;
    // Liste*L2;
    // Liste*L4;
    // L=NULL;
    // L2=NULL;
    // int taille=0;
    // L=Inserer_Debut_Liste(L,1);
    // L=Inserer_Debut_Liste(L,2);
    // L=Inserer_Debut_Liste(L,3);
    // L=Inserer_Debut_Liste(L,4);
    // L=Inserer_Debut_Liste(L,5);
    // L=Inserer_Debut_Liste(L,6);
    // Afficher_Liste(L);
    // //LibererListe(L);
    // Afficher_Liste(L);
    // //printf("Ma Liste: ");
    // //AfficherInverse(L);
    // //L=InverseListe(L);
    // //Afficher_Liste(L);
    // //printf("Ma Liste inverser: ");
    // //AfficherInverser(L);
    // taille = Taille_Liste(L);
    // printf("\nLa Taille de la liste est: %d \n",taille);
    // //Afficher_Liste(L);
    // L2=Inserer_Fin_Liste(L2,87);
    // L2=Inserer_Fin_Liste(L2,99);
    // L2=Inserer_Fin_Liste(L2,10);
    // L2=Inserer_Fin_Liste(L2,4);
    // L2=Inserer_Fin_Liste(L2,5);
    // L2=Inserer_Fin_Liste(L2,6);
    // L2=Inserer_Fin_Liste(L2,16);
    // Afficher_Liste(L2);
    // taille = Taille_Liste(L2);
    // printf("La Taille de la liste est: %d \n",taille);
    // //L2 = Suppression_au_debut(L2);
    // L2 = Inserer_pos_Liste(L2,100,1);
    // Afficher_Liste(L2);
    // L2 = Inserer_pos_Liste(L2,100,2);
    // Afficher_Liste(L2);
    // L2 = Inserer_pos_Liste(L2,100,3);
    // Afficher_Liste(L2);
    // L2 = Inserer_pos_Liste(L2,100,4);
    // Afficher_Liste(L2);
    // L2 = Inserer_pos_Liste(L2,100,5);
    // Afficher_Liste(L2);
    // L2 = Inserer_pos_Liste(L2,100,6);
    // Afficher_Liste(L2);
    // L2 = Inserer_pos_Liste(L2,100,7);
    // Afficher_Liste(L2);
    // taille = Taille_Liste(L2);
    // printf("La Taille de la liste est: %d \n",taille);
    // //L2 = Suppression_au_debut(L2);
    // Afficher_Liste(L2);
    // taille = Taille_Liste(L2);
    // printf("La Taille de la liste est: %d \n",taille);
    // Afficher_Liste(L);
    // L4=Inserer_Debut_Liste(L4,40);
    // L4=Inserer_Debut_Liste(L4,50);
    // L4=Inserer_Debut_Liste(L4,60);
    // Afficher_Liste(L4);

}
