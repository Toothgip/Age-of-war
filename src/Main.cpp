#include "Main.h"
#include "Menu/Menu.h"
#include "Jeu/Jeu.h"

int main()
{
    // Create the main window
    sf::RenderWindow fenetre(sf::VideoMode(800, 600), "Thomas's window");
    Menu menuPrincipal;
    fenetre.setFramerateLimit(50);

    sf::Texture regleTexture;
    sf::Sprite imageRegle;

    regleTexture.loadFromFile("resource/Menu/Regle.PNG");
    imageRegle.setTexture(regleTexture);

    bool init = true;

    Jeu jeu;

    int etape = 1;//Main menu

    while (fenetre.isOpen())
    {
        // Process events
        sf::Event event;
        while (fenetre.pollEvent(event))
        {
            // Close window : exit
            if(event.type == sf::Event::Closed)
            {
                fenetre.close();
            }
        }
        fenetre.clear(sf::Color::White);
        if(etape == 1)
        {

            menuPrincipal.afficher(fenetre);
            menuPrincipal.actualiser(fenetre);
            if(menuPrincipal.actualiser(fenetre) == 1)
            {
                etape = 2;
            }
            else if(menuPrincipal.actualiser(fenetre) == 2)
            {
                etape = 3;
            }
        }
        else if(etape == 2) //Draw the game
        {
            jeu.actualiser(fenetre);
            jeu.afficher(fenetre);


        }
        else if(etape == 3) //The rules
        {
            fenetre.draw(imageRegle);   //Draw the rules

            if(sf::Mouse::getPosition(fenetre).x >= 208 && sf::Mouse::getPosition(fenetre).y >= 520 &&      //Bouton pour revenir au menu
               sf::Mouse::getPosition(fenetre).x <= 592 && sf::Mouse::getPosition(fenetre).y <= 543 &&
               sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                etape = 1;  //Return to main menu
            }
        }

        fenetre.display();
    }
    return EXIT_SUCCESS;
}

    //TODO: Changer commentaire en anglais
    //TODO: Possibilité de language changer image menu
    //TODO: Simplifier collision (simplifier les classes ?)
    //TODO: Resoudre affichage des sprites pour pas que l'image soit coupée
    //TODO: Ne plus afficher les unite a la queue
    //TODO: Regrouper methode attaquer dans unite avec ou class abstraite interface target
    //TODO: AJOUTER des skills
