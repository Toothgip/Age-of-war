#include "Guerrier.h"

Guerrier::Guerrier(): Unite("resource/Unite/Guerrier/Guerrier_PG.png", "resource/Unite/Guerrier/Guerrier_PiedsD.png", "resource/Unite/Guerrier/Guerrier_A1.png", "resource/Unite/Guerrier/Guerrier_A2.png")
{
    vitesse = 2;
    vie= 150;
    value = 200;
    prix = 350;

    puissanceAttaque = 7, tempsAttaque = 0.6;
    portee = 0;
}

Guerrier::~Guerrier()
{
    //dtor
}
