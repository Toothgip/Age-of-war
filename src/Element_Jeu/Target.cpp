#include "Target.h"

Target::Target()
{
    vie = 100;
    dead = false; //Definit si l'unité est morte ou non
}

 void Target::receveoirdegat(int degats)
{
    if(vie < degats) //Enleve la possibilité de nombre négatif si la vie de l'unité est inferieur au dégats subis
    {
        vie = 0;
        dead = true;    //The target is dead
    }
    else
    {
        vie -= degats;
    }
}

bool Target::isDead()
{
    return dead;
}

Target::~Target()
{
    //dtor
}
