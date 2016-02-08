#ifndef IA_H
#define IA_H
#include "../Main.h"
#include "../Element_Jeu/Base.h"
#include "../Element_Jeu/Homme.h"
#include "../Element_Jeu/Archer.h"
#include "../Element_Jeu/Guerrier.h"
#include "../Element_Jeu/Assasin.h"
#include "../Element_Jeu/Tireur.h"
#include "../Element_Jeu/Tank.h"

    //Assigne a chaque type d'unite une valeur
    #define HOMMES 1
    #define ARCHERS 2
    #define GUERRIERS 3
    #define ASSASINS 4
    #define TIREURS 5
    #define TANKS 6

class IA
{
    public:
        IA();

        Unite* actualiserUnite(Unite* Unitejeu, int position);//Ajouté au jeu

        void ajouterGold(int goldGagner);   //Ajouté au jeu

       void synchronize(int *nbUniteJeu, int *expJeu);

        void mortUnite(Unite* Unitejeu, int position);   //Ajouté au jeu

        int getAge();

        void creerUnite( int typeUnite);

        void strategie();

        void actualiser();

        void changementAge();

        virtual ~IA();
    protected:
    private:
        vector<Unite*> uniteIA;
        int gold, exp, age, nbUnite, debut;
        sf::Clock chronoStrat, chronoUnite;

        bool init;
};

#endif // IA_H
