#include "Tank.h"

Tank::Tank(): Unite("resource/Unite/Tank/Tank.png", "resource/Unite/Tank/Tank.png", "resource/Unite/Tank/Tank.png", "resource/Unite/Tank/Tank_A.png")
{
    vitesse = 3;
    vie = 250 ;
    value = 200;
    prix = 600;

    puissanceAttaque=20, tempsAttaque = 0.9;
    portee = 150;
}

Tank::~Tank()
{
    //dtor
}
