#ifndef BASE_H
#define BASE_H
#include "../Main.h"

class Base
{
    public:

        Base(float positionX, float positionY, bool tourner);


        void afficher(sf::RenderWindow &window);

        void recevoirdegat(int degat);

        sf::IntRect getHitbox();

        void actualiserHitBox();

        void ameliorer();

        void actualiser();

        bool isDead(); // Verifie si la base est morte ou non

        virtual ~Base();
    protected:
    private:
        int vie;
        sf::Sprite imageBase;
        sf::Texture TextureBase, TextureBaseAge2;
        sf::RectangleShape barreVie;
        sf::Image image, imageAge2;
        sf::Text textVie;
        sf::Font arial;

        bool retourner;

        sf::IntRect hitbox;

        stringstream flux;  //Flux qui permet de convertir tout en string

        bool dead;
};

#endif // BASE_H
