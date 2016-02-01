#include "IA.h"

IA::IA(): uniteIA(5)
{
    //Initialisation de l'or et de l'experience au meme niveau que le joueur
    gold = 2000;
    exp = 0;
    age = 1;
    nbUnite = 0;
    debut = 0;
}

Unite* IA::actualiserUnite(Unite* Unitejeu, int position)
{
    Unitejeu = uniteIA[position];   //Actualise les unit�s

    return Unitejeu;
}

int IA::actualiserGold()
{
    return gold;
}

int IA::actualiserNbUnite() //Actualise le nombre d'unit� avec le jeu
{
    return nbUnite;
}

void IA::ajouterGold(int goldGagner)
{
    gold += goldGagner;     //Ajouter l'or gagn�
}

void IA::actualiserExp(int expJeu)  //Actualise le nombre d'exp�rience avec le jeu
{
    exp = expJeu;
}

void IA::mortUnite(Unite* Unitejeu, int position)    //Lorsque une unit� IA meur
{
    uniteIA[position] =  Unitejeu;
    nbUnite --; //Enleve une unit�
}

int IA::getAge() //Renvoit l'age de l'ia
{
    return age;
}

void IA::strategie()
{
    if(age == 1)    //Si l'age actuel est l'age prehistorique
    {
        if(debut == 0)    //Action de depart
        {
            this->creerUnite(HOMMES);  // 1 Homme + 2 Archer
            this->creerUnite(ARCHERS);
            this->creerUnite(ARCHERS); //il reste 370 gold
            debut = 1;
        }

        if(nbUnite < 1) //Si il n y a plus de 3 unit�s
        {
            if(gold < 630)
            {
                if(gold >= 190 && gold < 350) //Si les gold sont dans l'intervalle 190;350
                {
                    this->creerUnite(HOMMES); //Cree un homme
                }
                else if(gold >= 350 && gold < 400)
                {
                    this->creerUnite(GUERRIERS); //Cree un guerrier
                }
                else if(gold >= 400)
                {

                    this->creerUnite(HOMMES); //Cree un homme
                    this->creerUnite(ARCHERS); //Cree un archer
                }
            }
            else if(gold >= 630 && nbUnite <= 2)
            {
                if(gold < 770 )
                {
                    this->creerUnite(HOMMES); //Cree un homme
                    this->creerUnite(ARCHERS); //Cree un archer
                    this->creerUnite(ARCHERS); //Cree un archer
                }
                else if(gold >= 770)
                {
                    this->creerUnite(GUERRIERS); //Cree un homme
                    this->creerUnite(ARCHERS); //Cree un archer
                    this->creerUnite(ARCHERS); //Cree un archer
                }
            }
        }
    }
    else if(age == 2)
    {
        if(gold >= 450 && gold < 600)
        {
            this->creerUnite(ASSASINS);
        }
        else if(gold >= 600 && gold < 800)
        {
            this->creerUnite(TANKS);
        }
        else if(gold >= 800 && gold < 950)
        {
            this->creerUnite(TANKS);
            this->creerUnite(TIREURS);
        }
        else if(gold >= 950 && gold < 1150)
        {
            this->creerUnite(ASSASINS);
            this->creerUnite(TIREURS);
        }
        else if(gold >= 1150 && gold < 1300)
        {
            this->creerUnite(ASSASINS);
            this->creerUnite(TIREURS);
            this->creerUnite(TIREURS);
        }
        else if(gold >= 1300)
        {
            this->creerUnite(TANKS);
            this->creerUnite(TIREURS);
            this->creerUnite(TIREURS);
        }
    }
}

void IA::actualiser()
{
    if(chrono.getElapsedTime().asSeconds() >= 2)    //Temporise l'IA
    {
        this->strategie();
        chrono.restart();
    }

}


void IA::creerUnite(int typeUnite)
{
        for(int i = 0; i < 5; i++)
        {
            if(uniteIA[i] == NULL)
            {
                switch(typeUnite)
                {
                    case HOMMES:
                       uniteIA[i] = new Homme();
                    break;
                    case ARCHERS:
                       uniteIA[i] = new Archer();
                    break;
                    case GUERRIERS:
                       uniteIA[i] = new Guerrier();
                    break;
                    case ASSASINS:
                       uniteIA[i] = new Assasin();
                    break;
                    case TIREURS:
                       uniteIA[i] = new Tireur();
                    break;
                    case TANKS:
                       uniteIA[i] = new Tank();
                    break;
                }

                gold -= uniteIA[i]->getPrix();
                nbUnite ++;

                uniteIA[i]->setFaction(IAFACTION);  //L'unit� est de la faction IA
                break;

            }
        }
}

void IA::changementAge()
{
    exp -= 1200; //Enleve 1200 a l'exp de l'ia pour passer l'age suivant
    age = 2;
}

IA::~IA()//Destructeur
{

}
