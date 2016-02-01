#ifndef UNITE_H
#define UNITE_H
#include "../Main.h"
#include "Base.h"
class Unite
{
    public:
        Unite(string mouvement1, string mouvement2, string mouvement3, string mouvement4);

        Unite();

        void afficher(sf::RenderWindow &window);

        void actualiserHitBox();

        sf::IntRect getHitbox();

        sf::IntRect getHitbox(int portee);

        void actualiser();

        void setMouvement(bool mouvement);

        bool isDead();

        bool estDistance();

        int getPortee();

        void setFaction(int factionEntrer);

        int getFaction();

        int getValue();

        int getPrix();

        bool getAttaque();

        void deplacer();

        void attaquerBase(Base &base);

        void attaquerUnite(Unite *unite);

        void animationDeplacer();

        void animationAttaquer();

        void receveoirdegat(int degat);

        virtual ~Unite();
    protected:

        int vie, vitesse, puissanceAttaque, selected, faction, portee, value, prix;
        float tempsAttaque;
        bool mouvement, attaque, dead, affichage;

        sf::Image imageBonhomme, imageBonhomme2, imageBonhommeAttaque, imageBonhommeAttaque2;
        sf::Texture TextureBonhomme, TextureBonhomme2, TextureBonhommeAttaque, TextureBonhommeAttaque2;
        sf::Sprite spriteBonhomme;
        sf::Clock chrono, chrono2, chrono3;
        sf::IntRect hitbox, hitboxPortee;
        sf::RectangleShape barredeVie;

    private:


};

#endif // UNITE_H
