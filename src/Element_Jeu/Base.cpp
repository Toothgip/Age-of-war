#include "Base.h"


Base::Base(float positionX, float positionY, bool tourner)
: barreVie(sf::Vector2f(60, 6)), dead(false), retourner(tourner)
{

    arial.loadFromFile("resource/arial.ttf");

    image.loadFromFile("resource/Base/Grotte.png"); //Texture de l'age 1

    if (retourner == true)
    {
        image.flipHorizontally();   //Symetrie horizontal
    }
    TextureBase.create(image.getSize().x, image.getSize().y);   //Creation texture aux dimension de l'image
    TextureBase.update(image);//Initialisation de l'image de la base

    imageBase.setTexture(TextureBase);            //Image de la base est celle de l'age 1
    imageBase.setPosition(positionX, positionY);  //Position établi lors de la création de l'objet




    imageAge2.loadFromFile("resource/Base/Hangar.png");// Texture de l'age 2
    if (retourner == true)
    {
        imageAge2.flipHorizontally();   //Symetrie horizontal
    }
    TextureBaseAge2.create(imageAge2.getSize().x, imageAge2.getSize().y);   //Creation texture aux dimension de l'image
    TextureBaseAge2.update(imageAge2);                                         //Actualisation de l'image de la base

    barreVie.setFillColor(sf::Color::Red);
    barreVie.setPosition(positionX+5, positionY - 5);

    vie =1000;

    textVie.setString("1000");   //Flux converti en string et assigné  au texte

    textVie.setColor(sf::Color::Red);   //Couleur caractère
    textVie.setCharacterSize(26);     //Taille des caractères

    textVie.setPosition(barreVie.getPosition().x+7, barreVie.getPosition().y-28);
    textVie.setFont(arial);

    this->actualiserHitBox();

}

void Base::recevoirdegat(int degat)
{
    if(vie >= 0)
    {
        if(vie < degat) //Enleve la possibilité de nombre négatif
        {
            vie = 0;
            dead = true;    //La base est morte
        }
        else
        {
            vie = vie - degat;
        }
    }

}



sf::IntRect Base::getHitbox()   //Renvoit la Position de la base
{
    return hitbox;
}

void Base::actualiserHitBox()
{
    hitbox.left = imageBase.getPosition().x;   //Actualisa la postion de la hitBox en x puis en y
    hitbox.top = imageBase.getPosition().y;

    hitbox.width = TextureBase.getSize().x;     //Definis la largeur et la hauteur de la hitBox
    hitbox.height = TextureBase.getSize().y;
}

void Base::ameliorer()  //Methode ameliorant la base lors de l'age 2
{
    vie = vie +500; //Ajout de 500 point de vie

    imageBase.setTexture(TextureBaseAge2);

}

void Base::actualiser()
{
    if(vie >= 0)    //Si la base est vivante
    {
        barreVie.setSize(sf::Vector2f(60 * vie/1000, 6));   //Actualise la taille de la barre de vie
    }
    flux << vie;    //On met la valeur dans le flux

    textVie.setString(flux.str()); //Flux converti en string et assigné  au texte

    flux.str(""); //Réinitialise le flux

}

void Base::afficher(sf::RenderWindow &window)
{
    window.draw(imageBase);

    window.draw(barreVie);


    window.draw(textVie);   //Afiiche la vie en nombre
}

bool Base::isDead()
{
    return dead;
}


Base::~Base()
{
    //dtor
}
