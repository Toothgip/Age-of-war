#include "BoutonUnite.h"

BoutonUnite::BoutonUnite(sf::Vector2f Pos, sf::Vector2f PosDelta): selected(0)
{
    Position = Pos;
    PositionDelta = PosDelta;

}

bool BoutonUnite::actualiser(sf::RenderWindow &window)
{
    if((sf::Mouse::getPosition(window).x >= Position.x && sf::Mouse::getPosition(window).y >= Position.y &&
                sf::Mouse::getPosition(window).x <= Position.x + PositionDelta.x && sf::Mouse::getPosition(window).y <= Position.y + PositionDelta.y &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)))
       {

           selected = 1;    //Le bouton subit pression de la souris
       }
       if(selected == 1 && sf::Mouse::isButtonPressed(sf::Mouse::Left) == false) //Si le bouton a subie une pression et que la souris a été relaché
       {
           selected = 0;
           return true;
       }

       return false;
}

BoutonUnite::~BoutonUnite()
{
    //dtor
}
