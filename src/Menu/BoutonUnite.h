#ifndef BOUTONUNITE_H
#define BOUTONUNITE_H
#include "../Main.h"
#include "../Element_Jeu/Unite.h"

class BoutonUnite
{
    public:
        BoutonUnite(sf::Vector2f Pos, sf::Vector2f PosDelta);

        bool actualiser(sf::RenderWindow &window);

        virtual ~BoutonUnite();
    protected:
    private:
        sf::Vector2f Position, PositionDelta;
        int selected;
};

#endif // BOUTONUNITE_H
