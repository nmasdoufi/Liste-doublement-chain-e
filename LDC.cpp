#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>


using namespace std;
typedef long long ll;


#define REP(i,a,b) for (int i = a; i < b; i++)



/*Quesiton 1: Creation d'une liste de points dynamiques a partir d'une classe point et d'une classe liste */

class point
{
    protected:
        float x, y;

    public:

        point(float a = 0, float b = 0)
        {
            x = a;
            y = b;
        }

};
//-----------------------------------------
class liste : public point
 {

     float a,b;
     liste* next;
     liste* prev;

     public:

     liste(){}
     liste(float a,float b) : point(a,b)
     {next = NULL;}


     void affiche(liste* lista);
     void addAuDebut(liste** lista,float x,float y);
     void addALaFin(liste** lista,float x, float y);
     void addAuMileu(liste** lista,float x_aj,float y_aj,float x_ch,float y_ch);
     void nouvelleListe(liste** lista,float x_aj,float y_aj,float x_ch,float y_ch);
     void suppAuMilieu(liste** lista,float x_supp, float y_supp);
     void ajouterAuMilieuApres(liste** lista,float x_aj,float y_aj,float x_ch,float y_ch);

     liste* saisirListe(liste **L,int N);
     liste* pointVisualise(liste** lista,float pos);

     ~liste(){}

};

//------------------------------------------------
int main()
{
    liste* t=NULL;
    int nb,choix,x,y;
    cout << "Bonjour \n\n";
    do{
        cout << "Choisissez une operation : \n\n";
        cout << "0 : Quitter\n1 : Saisir une liste\n2 : Afficher la liste \n3 : Ajouter un element au debut\n4 : Ajouter un element a la Fin \n";
        cout << "5 : Ajouter un point au milieu avant un autre point\n6 : Ajouter un point au milieu apres un autre point\n";
        cout << "7 : Modifier un point de la liste\n8 : Supprimer un point de la liste\n9 : Visualiser un point de la liste \n\n\t=====>  ";
        cin >> choix;
        switch(choix)
        {
            case 0 : cout << "\n\t\t***** Au Revoir *****\n\n";break;
            case 1 : cout << "\tSaisir le nombre d'element : ";cin >> nb;t=t->saisirListe(&t,nb);break;

            case 2 :
                    if(t==NULL)
                        cout << "\nVous devez d'abord saisir une liste :D\n\n";

                    else
                       t->affiche(t);
                    break;

            case 3 :
                    cout << "\n\tSaisir le point a ajouter : "; cin >> x; cin>> y;
                    t->addAuDebut(&t,x,y);
                    break;

            case 4 :
                    cout << "\n\tSaisir le point a ajouter : "; cin >> x; cin>> y;
                    t->addALaFin(&t,x,y);
                    break;

            case 5 :
                    if(t==NULL)
                        cout << "\nVous devez d'abord saisir une liste :D\n\n";
                    else
                    {
                        /*Il faut saisir d'abord le point a cote de laquelle on veut ajouter notre point*/
                        float x_ch,y_ch;
                        cout << "\n\tSaisir le point avant lequel vous voulez ajouter votre point : "; cin >> x_ch; cin>> y_ch;
                        cout << "\n\tSaisir le point a ajoute : "; cin >> x; cin>> y;
                        t->addAuMileu(&t,x,y,x_ch,y_ch);
                    }
                    break;

            case 6 :
                    if(t==NULL)
                        cout << "\nVous devez d'abord saisir une liste :D\n\n";
                    else
                    {
                        /*Il faut saisir d'abord le point a cote de laquelle on veut ajouter notre point*/
                        float x_ch1,y_ch1;
                        cout << "\n\tSaisir le point apres lequel vous voulez ajouter votre point : "; cin >> x_ch1; cin>> y_ch1;
                        cout << "\n\tSaisir le point ajoute : "; cin >> x; cin>> y;
                        t->ajouterAuMilieuApres(&t,x,y,x_ch1,y_ch1);
                    }
                    break;
            case 7 :
                    if(t==NULL)
                        cout << "\nVous devez d'abord saisir une liste :D\n\n";
                    else
                    {
                        float x_cherche,y_cherche;
                        cout << "\n\tSaisir le point que vous voulez modifier : "; cin >> x_cherche; cin>> y_cherche;
                        cout << "\tSaisir le nouveau point : "; cin >> x; cin>> y; cout << "\n";
                        t->nouvelleListe(&t,x,y,x_cherche,y_cherche);
                    }
                    break;
            case 8 :
                    if(t==NULL)
                        cout << "\nVous devez d'abord saisir une liste :D\n\n";
                    else
                    {
                        float x_supp,y_supp;
                        cout << "\n\tSaisir le point que vous voulez supprimer : ";
                        cin >> x_supp >> y_supp;
                        t->suppAuMilieu(&t,x_supp,y_supp);
                        break;
                    }
            case 9 :
                    if(t==NULL)
                        cout << "\nVous devez d'abord saisir une liste :D\n\n";
                    else
                    {
                        float pos;
                        cout << "\n\tSaisir la posiiton du point que vous voulez visualiser : ";
                        cin >> pos;
                        t=t->pointVisualise(&t,pos);
                        break;
                    }

        }
    }while(choix!=0);
    //delete []t;

}
//---------------------------------------------------
liste* liste :: saisirListe(liste **L,int N)
{

    float x,y;

    REP(i,0,N)
    {
        cout << "\n\t\tSaisir l'element "<< i+1 << " : ";
        cin >> x >> y;
        (*L)->addALaFin(L,x,y);
    }
    cout << "\n******* Votre operation est realisee. Essayer d'afficher votre liste pour visualiser les changements realises *******\n\n";
    return *L;
}

//-------------------------------------------

/* Question 2 : Fonction permettant d'ajouter un point au debut de la liste */

void liste :: addAuDebut(liste** lista,float x_elem,float y_elem)
{


    //Preparer notre element
    liste *elmt;
    elmt = (liste *)malloc(sizeof(liste));
    elmt->next=elmt->prev=NULL;
    elmt -> a = x_elem;
    elmt -> b = y_elem;
    elmt -> next = *lista;

    if(*lista!=NULL) (*lista)->prev = elmt;
    *lista = elmt;

    cout << "\n******* Votre operation est realisee. Essayer d'afficher votre liste pour visualiser les changements realises *******\n\n";
}

//-------------------------------------------

/* Question 3 : Fonction permettant d'ajouter un point a la fin de la liste */

void liste :: addALaFin(liste** lista,float x, float y)
{
    //Reservtion d'un element
    liste* elmt;
    liste* tmp; //Elmt intermedire
    elmt=(liste*)malloc(sizeof(liste));
    elmt->a = x;
    elmt->b = y;
    elmt->next=elmt->prev=NULL;

    //Liste vide
    if(*lista==NULL)
    {
        *lista=elmt;
    }

    //Liste non vide
    else
    {
        tmp=*lista;
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        elmt->prev=tmp;
        tmp->next=elmt;

    }
}

//-------------------------------------------

/* Question 4 : Fonction permettant d'ajouter un point a une position donnee de la liste */

void liste :: addAuMileu(liste** lista,float x_aj,float y_aj,float x_ch,float y_ch)
{
    liste* elmt;
    liste* tmp; //Elmt intermedire

    if(lista==NULL)
        cout << "La liste est vide";
    else
    {
        tmp=*lista;
        elmt=(liste*)malloc(sizeof(liste));
        elmt->a=x_aj;
        elmt->b=y_aj;
        while(tmp!=NULL && tmp->a!=x_ch && tmp->b!=y_ch)
            tmp=tmp->next;
        if(tmp->a==x_ch && tmp->b==y_ch)
        {
            elmt->prev=tmp->prev;
            elmt->next=tmp;
            //Si l'element cherche est au debut
            if(tmp->prev!=NULL)
                tmp->prev->next=elmt;
            else
                *lista=elmt;

            tmp->prev=elmt;
        }
        else
            cout << "Le point ("<< x_ch << "," << y_ch << ") n'existe pas. ";
    }
    cout << "\n******* Votre operation est realisee. Essayer d'afficher votre liste pour visualiser les changements realises *******\n\n";
}

//-------------------------------------------

void liste :: ajouterAuMilieuApres(liste** lista,float x_aj,float y_aj,float x_ch,float y_ch)
{
    liste *elmt,*temp;
    if(*lista!=NULL)
    {
        temp=*lista;
        elmt=(liste*)malloc(sizeof(liste));
        elmt->a=x_aj;
        elmt->b=y_aj;
        temp=*lista;
        while(temp!=NULL && temp->a!=x_ch && temp->b!=y_ch)
            temp=temp->next;
        if(temp->a==x_ch && temp->b==y_ch)
        {
            elmt->next=temp->next;
            elmt->prev=temp;

            //Si on n'est pas arrive a la fin de la Liste
            if(temp->next!=NULL)
                temp->next->prev=elmt;

            temp->next=elmt;
        }
    }
    cout << "\n******* Votre operation est realisee. Essayer d'afficher votre liste pour visualiser les changements realises *******\n\n";

}

//-------------------------------------------------------------

/* Question 5 : Fonction permettant de modifier un point de la liste */

void liste :: nouvelleListe(liste** lista,float x_aj,float y_aj,float x_ch,float y_ch)
{
    liste* tmp; //Element intermediere


    if(*lista!=NULL)
    {
        //Element recherche est au debut
        if((*lista)->a==x_ch && (*lista)->b==y_ch)
        {
            (*lista)->a=x_aj;
            (*lista)->b=y_aj;
        }
        else
        {
            tmp=*lista;
            while(tmp->next!=NULL && tmp->next->a!=x_ch && tmp->next->b!=y_ch)
                tmp=tmp->next;
            if(tmp->next!=NULL)
            {
                tmp->next->a=x_aj;
                tmp->next->b=y_aj;
            }
            else
                cout << "Le point ("<< x_ch << "," << y_ch << ") n'existe pas dans la liste.\n\n ";
        }

    }
    cout <<"\n******* Votre operation est realisee. Essayer d'afficher votre liste pour visualiser les changements realises *******\n\n";
}

//-------------------------------------------

/* Question 6 : Fonction permettant de supprimer un point de la liste */

void liste :: suppAuMilieu(liste** lista,float x_supp, float y_supp)
{
    liste *temp;
    if(*lista!=NULL)
    {
        temp=*lista;
        while(temp->a!=x_supp && temp->b!=y_supp && temp->next!=NULL)
            temp=temp->next;
        if(temp->a==x_supp && temp->b==y_supp)
        {
            if(temp->prev!=NULL) //S'assurer que l'element a Supprimer n'est pas au debut
                temp->prev->next=temp->next;
            else //Si l'element a supprimer est au debut
                *lista=temp->next;
            if(temp->next!=NULL) //S'assurer que l'element a supprimer n'est pas a la fin
                temp->next->prev=temp->prev;
            //delete[] temp;
        }
    }
    cout << "\n******* Votre operation est realisee. Essayer d'afficher votre liste pour visualiser les changements realises *******\n\n";

}

//-------------------------------------------

/* Question 7 : Fonction permettant de visualiser un point de la liste */

liste* liste :: pointVisualise(liste** lista,float pos)
{
    liste *tmp;
    float choix = 0;
    if(lista!=NULL)
    {

        tmp=*lista;
        while(choix!=pos && tmp!=NULL)
            {tmp=tmp->next; choix++;}
        if(tmp!=NULL)
            cout << "\n\tLe point cherche est ("<< tmp->a << "," << tmp->b << ").\n\n ";
        else
            cout << "\n\tLe point chercher n'existe pas dans la liste.\n\n ";
    }

    cout << "\n******* Votre operation est realisee. Essayer d'afficher votre liste pour visualiser les changements realises *******\n\n";
    return *lista;
}

//-------------------------------------------

/* Question 8 : Fonction permettant de visualiser tous les points de la liste */

void liste :: affiche(liste* lista)
{
    liste* temp;
    temp=lista;
    if(lista==NULL)
    {
        cout <<"Liste vide";
    }
    else
    {
        while(temp!=NULL)
        {
            cout << "(" << temp->a << "," << temp->b << ")" << " ";
            temp=temp->next;
        }
    }
    cout << "\n\n";
}
