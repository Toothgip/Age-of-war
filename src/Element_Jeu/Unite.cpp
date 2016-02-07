#include "Unite.h"

Unite::Unite(string mouvement1, string mouvement2, string mouvement3, string mouvement4)
: mouvement(true), selected(0), attaque(false), barredeVie(sf::Vector2f(60, 3))
{
    affichage = false; //Initialize the boolean for know if the health bar need to be draw

    imageBonhomme.loadFromFile(mouvement1);         //Charge toutes les images
    imageBonhomme2.loadFromFile(mouvement2);
    imageBonhommeAttaque.loadFromFile(mouvement3);
    imageBonhommeAttaque2.loadFromFile(mouvement4);

    TextureBonhomme.create(imageBonhomme.getSize().x, imageBonhomme.getSize().y);   //Creer les textures à la taille de l'image qui lui correspond
    TextureBonhomme2.create(imageBonhomme2.getSize().x, imageBonhomme2.getSize().y);
    TextureBonhommeAttaque.create(imageBonhommeAttaque.getSize().x, imageBonhommeAttaque.getSize().y);
    TextureBonhommeAttaque2.create(imageBonhommeAttaque2.getSize().x, imageBonhommeAttaque2.getSize().y);

    TextureBonhomme.update(imageBonhomme);                      //Actualise chaque pixel de la texture par celui de l'image
    TextureBonhomme2.update(imageBonhomme2);
    TextureBonhommeAttaque.update(imageBonhommeAttaque);
    TextureBonhommeAttaque2.update(imageBonhommeAttaque2);

    spriteBonhomme.setTexture(TextureBonhomme);

    portee = 0;

    vie = 100;
    vitesse = 2;
    puissanceAttaque = 3, tempsAttaque = 0.25;

    barredeVie.setFillColor(sf::Color::Red);
}

Unite::Unite(): mouvement(true), selected(0)    //Second constructeur utiliser par le tableau de vecteur de la classe jeu
{

}

void Unite::afficher(sf::RenderWindow &window)
{
     window.draw(spriteBonhomme);
     if(affichage == true)
     {
         window.draw(barredeVie);
     }
}

void Unite::actualiser()
{
    if(mouvement == true)
    {
        this->deplacer();
    }

    barredeVie.setPosition(spriteBonhomme.getPosition().x + 10, spriteBonhomme.getPosition().y - 10);
    barredeVie.setSize(sf::Vector2f(60 * vie/100, 3 )); //Actualise la barre de vie
}

void Unite::actualiserHitBox()
{
    hitbox.left = spriteBonhomme.getPosition().x;   //Actualisa la postion de la hitBox en x puis en y
    hitbox.top = spriteBonhomme.getPosition().y;

    hitbox.width = TextureBonhomme.getSize().x;     //Definis la largeur et la hauteur de la hitBox
    hitbox.height = TextureBonhomme.getSize().y;

}


sf::IntRect Unite::getHitbox()
{
    return hitbox;
}

sf::IntRect Unite::getHitbox(int portee)
{
    hitboxPortee = hitbox;      //Copie la hitbox de base et permet de l'actualiser lorsque l'unité bouge

    if(faction == JOUEUR)
    {
        hitboxPortee.width = TextureBonhomme.getSize().x + portee; //Ajoute la portee a la droite de la hitbox
    }
    else
    {
        hitboxPortee.left = spriteBonhomme.getPosition().x - portee; //Ajoute la portee a la gauche de la hitbox
    }
    return hitboxPortee;
}

void Unite::receveoirdegat(int degat)
{
    Target::receveoirdegat(degat);
    affichage = true; //Active l'affichage de la barre de vie
}

void Unite::attaquerTarget(Target *target)
{
    if(chrono.getElapsedTime().asSeconds() >= tempsAttaque && target != NULL)
    {
        target->receveoirdegat(puissanceAttaque);
        chrono.restart();

        this->animationAttaquer();

        if(target->isDead() == true) //Si l'unité morte alors
        {
            attaque = false;    //L'unite n'attaque plus
        }
    }
}

void Unite::animationDeplacer()
{
    if(attaque == false)
    {
        if(chrono2.getElapsedTime().asMilliseconds() >= 468)
        {
            spriteBonhomme.setTexture(TextureBonhomme);
        }
        else if(chrono2.getElapsedTime().asMilliseconds() <= 234)
        {
            spriteBonhomme.setTexture(TextureBonhomme2);
        }
        if(chrono2.getElapsedTime().asMilliseconds() >= 702)
        {
            chrono2.restart();
        }
    }
}

void Unite::animationAttaquer()
{
    attaque = true;      //L'unité est en train d'attaquer
    if(selected == 0)
    {
        spriteBonhomme.setTexture(TextureBonhommeAttaque);
        selected = 1;
    }
    else if(selected == 1)
    {
        spriteBonhomme.setTexture(TextureBonhommeAttaque2);
        selected = 0;
    }
}

void Unite::setMouvement(bool moove)
{
/*    if(portee == 0 && moove == true)
    {
        attaque = false;
    }*/
    mouvement = moove;
}

void Unite::setFaction(int factionEntrer)   //Fonction qui permet d'assigner un faction a une unité
{
    faction = factionEntrer;

    if(faction == 1)        //Definis le lieu d'apparition en fonction de la faction 1 = Joueur et 2 IA
    {
        spriteBonhomme.setPosition(45, 555 - TextureBonhomme.getSize().y);
    }
    else if(faction == 2)   //Faction IA
    {
        spriteBonhomme.setPosition(700, 555 - TextureBonhomme.getSize().y); //Defini le lieu d'apparition

        imageBonhomme.flipHorizontally();       //Fais une symetrie horizontale pour chaque image
        imageBonhomme2.flipHorizontally();
        imageBonhommeAttaque.flipHorizontally();
        imageBonhommeAttaque2.flipHorizontally();

        TextureBonhomme.update(imageBonhomme);  //Et Actualise chaque pixel de la texture par celui de l'image
        TextureBonhomme2.update(imageBonhomme2);
        TextureBonhommeAttaque.update(imageBonhommeAttaque);
        TextureBonhommeAttaque2.update(imageBonhommeAttaque2);
    }
}

int Unite::getFaction() //Renvoi la variable faction
{
    return faction;
}

int Unite::getValue()   //Renvoi la variable value
{
    return value;
}

int Unite::getPrix()
{
    return prix;
}

bool Unite::getAttaque()
{
    return attaque;
}


bool Unite::estDistance()
{
    if(portee ==0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int Unite::getPortee()
{
    return portee;
}


void Unite::deplacer()
{
    if(chrono3.getElapsedTime().asMilliseconds() >= 56 && mouvement == true && faction == 1)   // Faction Joueur
    {
        spriteBonhomme.setPosition(spriteBonhomme.getPosition().x + vitesse, spriteBonhomme.getPosition().y);
        chrono3.restart();
        this->actualiserHitBox();
        this->animationDeplacer();
    }
    else if(chrono3.getElapsedTime().asMilliseconds() >= 56 && mouvement == true && faction == 2)   //Faction IA
    {
        spriteBonhomme.setPosition(spriteBonhomme.getPosition().x - vitesse, spriteBonhomme.getPosition().y);
        chrono3.restart();
        this->actualiserHitBox();
        this->animationDeplacer();
    }

}

Unite::~Unite() //Destructeur
{

}
