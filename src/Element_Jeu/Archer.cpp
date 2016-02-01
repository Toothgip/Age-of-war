#include "Archer.h"

Archer::Archer(): Unite("resource/Unite/Archer/Archer_PiedD.png", "resource/Unite/Archer/Archer_PiedG.png", "resource/Unite/Archer/Archer_A1.png", "resource/Unite/Archer/Archer_A2.png")
{
    vitesse = 2;
    vie= 80;
    value = 120;
    prix = 210;

    puissanceAttaque=3, tempsAttaque = 0.65;
    portee = 200;
}

Archer::~Archer()
{
    //dtor
}
