#ifndef MENU_H
#define MENU_H
#include "../Main.h"

class Menu
{
    public:
        Menu();
        void afficher(sf::RenderWindow &window);
        int actualiser(sf::RenderWindow &window);

        virtual ~Menu();
    protected:
    private:
        sf::Texture menuTexture, boutonJouer, boutonRegle;
        sf::Sprite imageMenu, imageJouer, imageRegle;
};

#endif // MENU_H
