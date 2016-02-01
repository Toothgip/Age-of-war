#ifndef JEU_H
#define JEU_H

#include "../Main.h"
#include "../Element_Jeu/Base.h"
//#include "Unite.h"
#include "../Menu/BoutonUnite.h"
#include "IA.h"

#include "../Element_Jeu/Homme.h"
#include "../Element_Jeu/Archer.h"
#include "../Element_Jeu/Guerrier.h"
#include "../Element_Jeu/Assasin.h"
#include "../Element_Jeu/Tireur.h"
#include "../Element_Jeu/Tank.h"



class Jeu
{
    public:
        Jeu();

        void collision();

        Unite* mortUnite(Unite *uniteMorte);

        void MenuUnite(sf::RenderWindow &window);

        void actualiser(sf::RenderWindow &window);

        void afficher(sf::RenderWindow &window);

        virtual ~Jeu();
    protected:
    private:

        sf::Texture textureFond, textureMenuUnite, textureMenuUnite2, textureFond2;
        sf::Sprite spriteFond, imageMenuUnite;

        sf::Text Unitetext, FinishText, orText, ExpText ;
        sf::Font arial;

        stringstream flux;

        IA ordinateur;
        Base baseJoueur, baseIA;
        BoutonUnite bouton1, bouton2, bouton3, bouton4;
        vector<Unite*> joueur, ia;

        int nbJoueur, nbIA, orJoueur, expJoueur, age, expIA;
};

#endif // JEU_H
