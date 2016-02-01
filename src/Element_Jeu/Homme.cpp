#include "Homme.h"

Homme::Homme(): Unite("resource/Unite/Homme/Homme_PG.png", "resource/Unite/Homme/Homme_PD.png", "resource/Unite/Homme/Homme_A1.png", "resource/Unite/Homme/Homme_A2.png")
{
    vitesse = 2;
    vie=100;
    value = 100;
    prix = 190;

    puissanceAttaque= 3, tempsAttaque = 0.55;
    portee = 0;
}

Homme::~Homme()
{
    //dtor
}
