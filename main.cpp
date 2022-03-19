/*
Programme : DEPLACER PIECES
But : Déplacer une piece à une position spécifique.
Date de dernière modification : 20 octobre 2021
Auteur : A.FAKHFAKH A.GARCIA
Remarques : Le nombre minimal de coups nécessaires pour réussir est 18.
*/

#include <iostream>
#include <string>
#include "game-tools.h"
using namespace std;

int main (void)
{
    // CONSTANTES
    //***********************************************************************************************************************************************************************
    
    const unsigned short int NB_CASES = 10; // Nombre des cases du tableau.
    
    // VARIABLES************************************************************************************************************************************************************
    //***********************************************************************************************************************************************************************
    
    int tab[NB_CASES]; // Tableau contenant le nombre de pièces dans chaque case.
    int posDebut; // L'indice de la case qui contient une seule piéce en début du jeu
    int nbrCoups; // Le nombre de coups jouer par le joueur.
    int nbrPiece; // La somme des nombres pièces dans le tableau.
    int indiceChoix; // indice choisi par l'utilisateur.
    unsigned short int i; // Indice de la boucle.
    string choix; // le coup du joueur.
    bool verif; // La condition d'arret.

    // Traitements************************************************************************************************************************************************************
    //************************************************************************************************************************************************************************

    // tab, NB_CASES >> Initialiser la partie >> tab, posDebut,nbrCoups, verif
    //************************************************************************************************************************************************************************
   
    // clavier >> Afficher les regles du jeu >> ecran
    cout << "Le plateau contient un tableau de 10 cases, numerotees de 0 a 9." << endl;
    cout << "La case d'indice 1 ou 7  contient 1 piece de monnaie." << endl;
    cout << "La reussite consiste a deplacer cette piece de monnaie dans la case d'indice 7 ou 1," << endl;
    cout << "sans qu'il ne reste a la fin d'autre piece dans le tableau que celle de la case 7 ou 1." << endl;
    cout << "Les operations disponibles pour le faire sont : " << endl;
    cout << "" << endl;
    cout << "- Ajouter -i : Ajouter 1 piece en case i-1 et i+1 et supprimer 1 piece de la case i" << endl;    
    cout << "               si la case i a bien 2 cases voisines i-1 et i+1 et si elle contient au moins 1 piece" << endl;
    cout << "- Supprimer -i : Supprimer 1 piece en case i-1 et i+1 et ajouter 1 piece de la case i" << endl;    
    cout << "               si la case i contient au moins 1 piece et si elle a bien 2 cases voisines i-1 et i+1" << endl;
    cout << "Le jeu se termine lorsque le tableau atteint son etat final ou par abandon du joueur." << endl;    
    cout << "Le nombre minimal d'actions necessaires est 18." << endl;
    cout << "\n" << endl;
    cout << "Chaque action de l'utilisateur est comptabilisee des lors que : " << endl;    
    cout << "- L'indice fourni correspond a un indice du tableau \n et  " << endl; 
    cout << "- L'action demandee est bien un Ajout ou une Supression" << endl; 
    cout << "\n" << endl;

    // Choisir position initiale >> posDebut
    do
    {
        cout << "Si vous voulez que le deplacement se fasse de la case 1 a la case 7 tapez 1, si non, tapez 7 : " ; 
        cin >> posDebut;
    } while (posDebut != 1 && posDebut !=7);
    

    // posDebut, tab, NB_CASES >> remplir le tableau >> tab
    for (i = 0 ; i <= NB_CASES - 1  ; i++)
    {
        tab[i]=0;
    }
    if (posDebut == 1)
    {
        tab[1]=1;
    }
    else
    {
        tab[7]=1;
    }

    // tab,NB_CASES >> Afficher le tableau a l'etat inisial >> nbrCoups
    // >> Initialiser le nombre de coup >> nbrCoups
    nbrCoups = 0;
    // tab,NB_CASES >> Afficher le tableau >> ecran 
    cout<<"          ----------------------------------------"<<endl;
    cout <<"Pieces : | ";
    for (i = 0; i <= NB_CASES - 1 ; i++)
    {
        cout << tab[i] << " | ";
    }
    cout<<"\n          ----------------------------------------\n           ";
    for (i = 0; i <= NB_CASES - 1 ; i++)
    {
        cout<<i<<"   ";
    }
    cout<<"\n"; 
    // nbrCoups >> Afficher le nombre de coup >> ecran
    cout << "                                                        nombre de coups = " << nbrCoups << endl;
    
    // >> Initialiser la Conditiond d'arret >> verif
    verif = false;

    // tab, NB_CASES, posDebut, nbrCoups, verif>> Joueur la partie >> tab,nbrCoups, verif
    //************************************************************************************************************************************************************************
    
    do
    {
       // tab >> Saisir et vérifier choix joueur et initialiser indiceChoix >> choix, indiceChoix 
       do
       {
           //Saisir le coup du joueur >> choix
           cout <<"Taper A ou S (Ajouter ou Supprimer) + indice choisi OU BIEN Q (Quitter) : ";
           cin >> choix;
           // choix >> initialiser indiceChoix >> indiceChoix
           indiceChoix=int(choix[1]-48);
           // choix, tab, indiceChoix >> Verification de la reponse du joueur >> ;
           if (choix=="Q" || choix =="q")
           {
               break;
           }
           if ((choix[0]=='A' || choix[0]=='a') && (choix.size()==2) && (indiceChoix ==1 || indiceChoix ==2 || indiceChoix ==3 || indiceChoix ==4 || indiceChoix ==5 || indiceChoix ==6 || indiceChoix ==7 || indiceChoix ==8) && tab[indiceChoix] >= 1 )
           {
               break;
           }
           if ((choix[0]=='S' || choix[0]=='s') && (choix.size()==2) && (indiceChoix ==1 || indiceChoix ==2 || indiceChoix ==3 || indiceChoix ==4 || indiceChoix ==5 || indiceChoix ==6 || indiceChoix ==7 || indiceChoix ==8) && tab[indiceChoix-1] >= 1 && tab[indiceChoix+1] >= 1 )
           {
               break;
           } 
     
        } while (true) ;
        // choix >> Condition d'arret (Arreter de jouer)
        if (choix=="Q" || choix=="q")
        {
            break;
        }
        // tab, choix, indiceChoix >> Deroulement de la manche >> tab
        if (choix[0]=='A' || choix[0]=='a')
        {
            // Ajout de pieces
            tab[indiceChoix] -=1;
            tab[indiceChoix-1] +=1;
            tab[indiceChoix+1] +=1;
        }
        else
        {
            // Suppression de pieces
            tab[indiceChoix] +=1;
            tab[indiceChoix-1] -=1;
            tab[indiceChoix+1] -=1;
        }
        
        // tab,NB_CASES, nbrCoups >> Afficher le tableau >> nbrCoups
        // nbrCoups>> Incrementation du nombre de coups >> nbrCoups
        nbrCoups += 1;
        // tab,NB_CASES >> Afficher le tableau >> ecran 
        cout<<"          ----------------------------------------"<<endl;
        cout <<"Pieces : | ";
        for (i = 0; i <= NB_CASES - 1 ; i++)
        {
            cout << tab[i] << " | ";
        }
        cout<<"\n          ----------------------------------------\n           ";
        for (i = 0; i <= NB_CASES - 1 ; i++)
        {
            cout<<i<<"   ";
        }
        cout<<"\n";
        // nbrCoups >> Afficher le nombre de coup >> ecran
        cout << "                                                        nombre de coups = " << nbrCoups << endl;
        
        //tab, NB_CASES, verif, posDebut >> Condition d'arret (joueur gagne) >> verif

        // >> Initialiser le nombre de piece >> nbrPiece 
        nbrPiece = 0;

        //tab, NB_CASES, nbrPiece >> Compter le nombre de pieces >> nbrPiece
        for (i = 0; i <= NB_CASES -1; i++)
        {
            nbrPiece += tab[i];
        }

        // nbrPiece, posDebut, verif, tab >> Verification de la victoire >> verif
        if (nbrPiece ==1)
        {
            if(posDebut == 1)
            {
                if (tab[7]==1)
                {
                    verif = true;
                    break;
                }
            }  
            else
            {
                if (tab[1]==1)
                {
                    verif = true;
                    break;
                }    
            }
        }
    } while (true);
    
    // tab, NB_CASES, verif, nbrCoups, posDebut >> Finaliser la partie >>
    
    // tab, NB_CASES >> Afficher le tableau a l'etat finale
    cout<<"----------Fin de partie----------"<<endl;
    cout<<"          ----------------------------------------"<<endl;
    cout <<"Pieces : | ";
    for (i = 0; i <= NB_CASES - 1 ; i++)
    {
        cout << tab[i] << " | ";
    }
    cout<<"\n          ----------------------------------------\n           ";
    for (i = 0; i <= NB_CASES - 1 ; i++)
    {
        cout<<i<<"   ";
    }
    cout<<"\n";
    
    // verif, nbrCoups >> Afficher message du fin du partie >> ecran
    if (verif==true)
    {
        // Afficher message de reussite
        cout<<"\nB R A V O "<<endl;
        cout<<"Vous avez reussi en "<< nbrCoups << " coups." << endl;
    }
    else
    {
        // Afficher message d'abandon
        cout<<"\nAbandon apres "<< nbrCoups <<endl;
    }
        
    // posDebut >> Afficher le nombre minimum de coups possible pour gagner >> ecran
    if (posDebut == 1)
    {
        cout<<"Le nombre minimal de coups pour deplacer la piece de la case 1 a la case 7 est 18";
    }
    else
    {
        cout<<"Le nombre minimal de coups pour deplacer la piece de la case 7 a la case 1 est 18";
    }
    return (0);
}