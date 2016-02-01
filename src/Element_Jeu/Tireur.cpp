#include "Tireur.h"

Tireur::Tireur(): Unite("resource/Unite/Tireur/Tireur_PiedD.png", "resource/Unite/Tireur/Tireur_PG.png", "resource/Unite/Tireur/Tireur_A1.png", "resource/Unite/Tireur/Tireur_A2.png")
{
    vitesse = 2;
    vie= 160;
    value = 280;
    prix = 350;

    puissanceAttaque= 8, tempsAttaque = 0.5;
    portee = 300;
}

Tireur::~Tireur()
{
    //dtor
}
