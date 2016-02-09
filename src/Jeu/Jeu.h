#ifndef JEU_H
#define JEU_H

#include "../Element_Jeu/Base.h"    //Main.h is included
#include "../Menu/BoutonUnite.h"    //Unit class is included
#include "IA.h" //Units of age 1 and age2 are already included

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

        bool init;
};

#endif // JEU_H
