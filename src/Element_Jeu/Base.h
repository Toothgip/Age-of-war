#ifndef BASE_H
#define BASE_H
#include "../Main.h"
#include "Target.h"

class Base: public Target
{
    public:

        Base(float positionX, float positionY, bool tourner);


        void afficher(sf::RenderWindow &window);

        sf::IntRect getHitbox();

        void actualiserHitBox();

        void ameliorer();

        void actualiser();

        virtual ~Base();
    protected:
    private:
        sf::Sprite imageBase;
        sf::Texture TextureBase, TextureBaseAge2;
        sf::RectangleShape barreVie;
        sf::Image image, imageAge2;
        sf::Text textVie;
        sf::Font arial;

        bool retourner;

       sf::IntRect hitbox;

        stringstream flux;  //Flux qui permet de convertir tout en string
};

#endif // BASE_H
