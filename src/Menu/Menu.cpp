#include "Menu.h"

Menu::Menu()
{
    menuTexture.loadFromFile("resource/Menu/Menu.png");

    imageMenu.setTexture(menuTexture);

    boutonJouer.loadFromFile("resource/Menu/Bouton_Jouer.png"); //Texture du bouton jouer

    boutonRegle.loadFromFile("resource/Menu/Bouton_regle.png"); //Texture du bouton regle

    imageRegle.setTexture(boutonRegle);
    imageRegle.setPosition(292, 393); //Position sur le bouton Regle

    imageJouer.setPosition(248, 188); //Position du bouton jouer
    imageJouer.setTexture(boutonJouer);
}



void Menu::afficher(sf::RenderWindow &window)
{
    window.draw(imageMenu);
}

int Menu::actualiser(sf::RenderWindow &window)
{
        if(sf::Mouse::getPosition(window).x >= 247 && sf::Mouse::getPosition(window).y >= 188 &&        //Clic avec la Souris sur le bouton jouer
                sf::Mouse::getPosition(window).x <= 552 && sf::Mouse::getPosition(window).y <= 345 &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            return 1;
        }

        else if(sf::Mouse::getPosition(window).x >= 247 && sf::Mouse::getPosition(window).y >= 188 &&   //Souris passe sur le bouton jouer
           sf::Mouse::getPosition(window).x <= 552 && sf::Mouse::getPosition(window).y <= 345)
        {
            window.draw(imageJouer);

            return 0;
        }
        else if(sf::Mouse::getPosition(window).x >= 295 && sf::Mouse::getPosition(window).y >= 423 &&   //Clic avec la Souris sur le bouton regle
                sf::Mouse::getPosition(window).x <= 499 && sf::Mouse::getPosition(window).y <= 505 &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            return 2;
        }
        else if(sf::Mouse::getPosition(window).x >= 292 && sf::Mouse::getPosition(window).y >= 393 &&   //Souris passe sur le bouton regle
                sf::Mouse::getPosition(window).x <= 501 && sf::Mouse::getPosition(window).y <= 480)
        {
            window.draw(imageRegle);

            return 0;
        }
       else
       {
           imageMenu.setTexture(menuTexture);
           return 0;
       }



}




Menu::~Menu()
{

}
