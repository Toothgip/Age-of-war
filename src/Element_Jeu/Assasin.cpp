#include "Assasin.h"

Assasin::Assasin(): Unite("resource/Unite/Assasin/Assasin_PG.png", "resource/Unite/Assasin/Assasin_PiedDroit.png", "resource/Unite/Assasin/Assasin_A1.png", "resource/Unite/Assasin/Assasin_A2.png")
{
    vitesse = 2;
    vie= 180;
    value = 300;
    prix = 450;

    puissanceAttaque = 8, tempsAttaque = 0.3;
    portee = 0;
}

Assasin::~Assasin()
{
    //dtor
}
