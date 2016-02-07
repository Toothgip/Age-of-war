#include "Target.h"

Target::Target()
{
    vie = 100;
    dead = false; //Definit si l'unit� est morte ou non
}

 void Target::receveoirdegat(int degats)
{
    if(vie < degats) //Enleve la possibilit� de nombre n�gatif si la vie de l'unit� est inferieur au d�gats subis
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
