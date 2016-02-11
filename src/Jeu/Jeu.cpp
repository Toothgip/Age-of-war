#include "Jeu.h"

Jeu::Jeu(): baseJoueur(0, 430, false), baseIA(710, 430, true),  //Initialization of bases
bouton1(sf::Vector2f(20, 10), sf::Vector2f(60, 94)), bouton2(sf::Vector2f(120, 10), sf::Vector2f(60, 94)),
bouton3(sf::Vector2f(210, 10), sf::Vector2f(65, 94)),
bouton4(sf::Vector2f(360, 10), sf::Vector2f(75, 75)) //Initialization of constructors of buttons
{
    nbJoueur = nbIA = 0;
    age = 1; // Game begins at age 1

    textureFond.loadFromFile("resource/Decor/foret.png");     //Background Texture of age 1
    textureFond2.loadFromFile("resource/Decor/desert.jpg");     //Background Texture of age 2
    spriteFond.setTexture(textureFond);

    textureMenuUnite.loadFromFile("resource/MenuUnite/MenuUnite.png");    //Picture of Menu units age 1
    textureMenuUnite2.loadFromFile("resource/MenuUnite/MenuUnite2.png");  //Picture of Menu units age 2
    imageMenuUnite.setTexture(textureMenuUnite);

    arial.loadFromFile("resource/arial.ttf"); //Load font
    Unitetext.setFont(arial);

    Unitetext.setColor(sf::Color::Black);   //Couleur caractère
    Unitetext.setCharacterSize(22);     //Taille des caractères
    Unitetext.setPosition(281, 115); //Position du texte
    Unitetext.setString("0");       //Valeur au début : 0

    orText = Unitetext;          //Reprends les meme parametres que l'Unité text
    orText.setColor(sf::Color::Yellow);
    orText.setPosition(550, 108);

    Unitetext.setCharacterSize(24);     //Taille des caractères
    ExpText = Unitetext;                //Copie les attributs du texte du nombre d'unité
    ExpText.setPosition(635, 76);

    FinishText.setFont(arial);
    FinishText.setCharacterSize(100);     //Taille des caractères
    FinishText.setPosition(250, 220);

    orJoueur  = 2000; //Initialisation de l'or et de l'experience
    expJoueur = expIA = 0;

    init = true;

    for(int i =0; i < MAX_UNIT; i++)   //Initialize unit of two faction to NULL
    {
        joueur[i] = NULL;
        ia[i]= NULL;
    }
}

void Jeu::collision()    //Gere les collision entre unités
{
    for(int i = 0; i < MAX_UNIT; i++) //Boucle des unités de la faction joueur
    {
        //Collision entre unité
                if(joueur[i] != NULL && joueur[i+1] != NULL && i < 4) //Si les unités existent et verifie la collision jusqu'a l'avant derniere
                {

                    if(joueur[i]->getHitbox().intersects(joueur[i+1]->getHitbox()) == true)         //Collision entre unité de meme faction joueur
                    {
                        joueur[i+1]->setMouvement(STOP);     //L'unité arrete d'avancer
                    }

                    else if(joueur[i]->getHitbox().intersects(joueur[i+1]->getHitbox()) == false)       //Si pas de collision
                    {
                        joueur[i+1]->setMouvement(AVANCE);  //L'unite re-avance
                    }
                }
                if(joueur[i] == NULL && joueur[i+1] != NULL && i < 4 && joueur[i+1]->getAttaque() == false) //Si l'unité de devant est morte
                {
                    joueur[i+1]->setMouvement(AVANCE);          //l'unité repart
                }

        for(int j = 0; j < MAX_UNIT; j++)
        {
            //Attaque de faction differentes
                    if(ia[j] != NULL && joueur[i] != NULL)   //Si les unités existent
                    {
                        //Distance
                        if( (ia[j]->estDistance() == true &&   //Si IA distant
                            ia[j]->getHitbox( ia[j]->getPortee() ).intersects(joueur[i]->getHitbox()) == true) ||   //Et ils qu'il sont dans la portee
                            ( ia[j]->getHitbox( ia[j]->getPortee() ).contains( joueur[i]->getHitbox().left, joueur[i]->getHitbox().top + 20) ) ) //Ou rentre en collision
                        {
                            ia[j]->attaquerTarget(joueur[i]); //Attaque entre unité si Unité corps a corps

                            if(joueur[i]->isDead()== true && ia[j-1] != NULL)  //Si l'unité joueur meurt
                            {
                                ia[j-1]->setMouvement(AVANCE);    //L'unité IA avance
                            }
                            else if(joueur[i]->isDead()== true && ia[j-2] != NULL)
                            {
                                ia[j-2]->setMouvement(AVANCE);    //L'unité IA avance
                            }
                        }

                        if ( (joueur[i]->estDistance() == true &&  //Si Joueur distant
                                 joueur[i]->getHitbox( joueur[i]->getPortee() ).intersects( ia[j]->getHitbox() ) == true) ||   //Et ils qu'il sont dans la portee
                                 (joueur[i]->getHitbox( joueur[i]->getPortee() ).contains( ia[j]->getHitbox().left, ia[j]->getHitbox().top + 20)) )    //Ou rentre en collision
                        {
                            joueur[i]->attaquerTarget(ia[j]); //Attaque entre unité si Unité corps a corps

                            if(ia[j]->isDead()== true && joueur[i-1] != NULL)  //Si l'unité joueur meurt
                            {
                                printf("test 1");
                                joueur[i-i]->setMouvement(AVANCE);    //L'unité IA avance

                            }

                        }

                        //Corps a corps
                        if(ia[j]->getHitbox().intersects(joueur[i]->getHitbox()) == true || joueur[i]->getHitbox().intersects(ia[j]->getHitbox())) //Collision entre unité des factions
                        {

                            ia[j]->attaquerTarget(joueur[i]); //Attaque entre unité si Unité corps a corps
                            joueur[i]->attaquerTarget(ia[j]);

                            joueur[i]->setMouvement(STOP);     //Les unités arretent d'avancer
                            ia[j]->setMouvement(STOP);

                            if(joueur[i]->isDead()== true)  //Si l'unité joueur meurt
                            {
                                ia[j]->setMouvement(AVANCE);    //L'unité IA avance
                            }
                            if(ia[j]->isDead()== true)   //Si l'unité IA meurt
                            {
                                printf("test 3");
                                joueur[i]->setMouvement(AVANCE);    //L'unité Joueur avance
                            }
                        }
                    }
        }

            //Attaque de Base de l'IA par les Unité joueurs
            if(joueur[i] != NULL)                   //Si l'unité existe
            {
                    //Corps a corps
                    if(joueur[i]->getHitbox().intersects( baseIA.getHitbox() ) )   //Collision avec la base Joueur
                    {
                        if(joueur[i]->estDistance() == false)
                        {
                            joueur[i]->attaquerTarget(&baseIA);        //Attaquer la base Joueur
                        }

                        joueur[i]->setMouvement(STOP);           //Les unités arretent d'avancer
                    }
                    //Distance
                    if(joueur[i]->estDistance() && joueur[i]->getHitbox( joueur[i]->getPortee() ).intersects( baseIA.getHitbox() ) )    //Si le personne est distance et Base dans sa portee
                    {
                        joueur[i]->attaquerTarget(&baseIA);    //Alors elle attaque
                    }
            }
    }

    for(int i =0; i< MAX_UNIT; i++) //Boucle des unités de la faction IA
    {
        //Collision entre unité de meme faction IA
                if(ia[i] != NULL && ia[i+1] != NULL && i < 4)    //Si les unités existent et verifie la collision jusqu'a l'avant derniere
                {
                    if(ia[i]->getHitbox().intersects(ia[i+1]->getHitbox()) == true && i < nbIA)
                    {
                        ia[i+1]->setMouvement(STOP);              //L'unité arrete d'avancer
                    }
                    else if(ia[i]->getHitbox().intersects(ia[i+1]->getHitbox()) == false)
                    {
                        ia[i+1]->setMouvement(AVANCE);          //l'unité repart
                    }
                }
                if(ia[i] == NULL && ia[i+1] != NULL && i < 4 && ia[i+1]->getAttaque() == false)
                {
                    ia[i+1]->setMouvement(AVANCE);          //l'unité repart
                }

        //Attaque de Base du Joueur par les Unité IA

                 if(ia[i] != NULL)  //Si l'unité existe
                 {
                    //Corps a corps
                    if(ia[i]->getHitbox().intersects( baseJoueur.getHitbox() ) )   //Collision avec la base Joueur
                    {
                        if(ia[i]->estDistance() == false)   //Si l'unité n'est pas distant
                        {
                            ia[i]->attaquerTarget(&baseJoueur);        //Attaquer la base Joueur
                        }

                        ia[i]->setMouvement(STOP);           //Les unités arretent d'avancer
                    }

                    //Distance
                    if(ia[i]->estDistance() && ia[i]->getHitbox( ia[i]->getPortee() ).intersects( baseJoueur.getHitbox() ) )    //Si le personne est distant et la Base est dans sa portee
                    {
                        ia[i]->attaquerTarget(&baseJoueur);
                    }
                }
    }
}

Unite* Jeu::mortUnite(Unite *uniteMorte)
{
    if(uniteMorte->getFaction() == JOUEUR)   //Si l'unité morte est de la faction joueur
    {
        ordinateur.ajouterGold(uniteMorte->getValue()); //Ajoute de l'or et exp a l'ia
        expIA += uniteMorte->getValue()/2;  //Recupere la valeur de l'unité
        nbJoueur --;
    }
    else if(uniteMorte->getFaction() == IAFACTION)  //Si l'unité morte est de la faction IA
    {
        //Ajoute de l'or et exp aux joueur
        orJoueur = orJoueur + uniteMorte->getValue();
        expJoueur = expJoueur + uniteMorte->getValue()/2;  //Recupere la valeur de l'unité
    }
    uniteMorte = NULL;

    return uniteMorte;
}

void Jeu::MenuUnite(sf::RenderWindow &window)   //Gere le menu en haut à gauche avec la cration d'unité
{
    if(nbJoueur < MAX_UNIT)    //Si le nombre d'unité max n'est pas atteint
    {
        if( (bouton1.actualiser(window) == true) &&
          (orJoueur >= 190 && age == 1 || orJoueur >= 450 && age == 2)  )  //Si on clique sur le bouton de l'homme ou de l'assasin et qu'il y a l'or necessaire
        {
            if(age == 1)    //Alors création de l'unité suivant l'age actuel
            {
                for(int i = 0; i < MAX_UNIT; i++)
                {
                    if(joueur[i] == NULL)   //Si il n'ya pas d'unité a la case i
                    {
                        joueur[i] = new Homme();     //Alors creation de l'unité
                        joueur[i]->setFaction(JOUEUR);   //Assigne la faction joueur a l'unité
                        orJoueur = orJoueur - joueur[i]->getPrix();  //Enleve le prix de l'unité à l'or du Joueur
                        break;                      //Break permet de terminer la boucle avant la fin
                    }
                }
            }
            else if(age == 2)
            {
                for(int i = 0; i < MAX_UNIT; i++)
                {
                    if(joueur[i] == NULL)   //Si il n'ya pas d'unité a la case i
                    {
                        joueur[i] = new Assasin();   //Alors creation de l'unité
                        joueur[i]->setFaction(JOUEUR);   //Assigne la faction joueur a l'unité
                        orJoueur = orJoueur - joueur[i]->getPrix();  //Enleve le prix de l'unité à l'or du Joueur
                        break;                      //Break permet de terminer la boucle avant la fin
                    }
                }
            }

            nbJoueur ++;    //Augment le nombre d'unité présent
        }
        else if( (bouton2.actualiser(window) == true) &&
               (orJoueur >= 210 && age == 1 || orJoueur >= 350 && age == 2) ) //Si on clique sur le bouton de l'archer ou du Tireur et qu'il y a l'or necessaire
        {
            if(age == 1)    //Alors création de l'unité suivant l'age actuel
            {
                for(int i = 0; i < MAX_UNIT; i++)
                {
                    if(joueur[i] == NULL)   //Si il n'ya pas d'unité a la case i
                    {
                        joueur[i] = new Archer();    //Alors creation de l'unité
                        joueur[i]->setFaction(JOUEUR);   //Assigne la faction joueur a l'unité
                        orJoueur = orJoueur - joueur[i]->getPrix();  //Enleve le prix de l'unité à l'or du Joueur
                        break;                       //Break permet de terminer la boucle avant la fin
                    }
                }
            }
            else if(age == 2)
            {
                for(int i = 0; i < MAX_UNIT; i++)
                {
                    if(joueur[i] == NULL)   //Si il n'ya pas d'unité a la case i
                    {
                        joueur[i] = new Tireur();    //Alors creation de l'unité
                        joueur[i]->setFaction(JOUEUR);   //Assigne la faction joueur a l'unité
                        orJoueur = orJoueur - joueur[i]->getPrix();  //Enleve le prix de l'unité à l'or du Joueur
                        break;                      //Break permet de terminer la boucle avant la fin
                    }
                }
            }

            nbJoueur ++;    //Augment le nombre d'unité présent
        }
        else if( (bouton3.actualiser(window) == true) &&
               (orJoueur >= 350 && age == 1 || orJoueur >= 600 && age == 2) ) //Si on clique sur le bouton du guerrier ou du Tank et qu'il y a l'or necessaire
        {
            if(age == 1)   //Alors création de l'unité suivant l'age actuel
            {
                for(int i = 0; i < MAX_UNIT; i++)
                {
                    if(joueur[i] == NULL)   //Si il n'ya pas d'unité a la case i
                    {
                        joueur[i] = new Guerrier(); //Alors creation de l'unité
                        joueur[i]->setFaction(JOUEUR);   //Assigne la faction joueur a l'unité
                        orJoueur = orJoueur - joueur[i]->getPrix();  //Enleve le prix de l'unité à l'or du Joueur
                        break;                      //Break permet de terminer la boucle avant la fin
                    }
                }
            }
            else if(age == 2)
            {
                for(int i = 0; i < MAX_UNIT; i++)
                {
                    if(joueur[i] == NULL)   //Si il n'ya pas d'unité a la case i
                    {
                        joueur[i] = new Tank();  //Alors creation de l'unité
                        joueur[i]->setFaction(JOUEUR);   //Assigne la faction joueur a l'unité
                        orJoueur = orJoueur - joueur[i]->getPrix();  //Enleve le prix de l'unité à l'or du Joueur
                        break;                  //Break permet de terminer la boucle avant la fin
                    }
                }
            }

            nbJoueur ++;    //Augment le nombre d'unité présent
        }
    }
    if(bouton4.actualiser(window) == true && expJoueur >= 1200)    //Changement de l'age si il y a l'experience necessaire
    {
        age = 2;        //Passage a l'age 2
        expJoueur = expJoueur -1200;
        spriteFond.setTexture(textureFond2);          //Changement de texture du paysage
        imageMenuUnite.setTexture(textureMenuUnite2); //Changement de  texture du Menu Unités
        baseJoueur.ameliorer(); //La base du joueur passe a l'age 2
    }

    flux << nbJoueur;               //Actualise le nombre d'unité presentent
    Unitetext.setString(flux.str());
    flux.str(""); //Reinitialisation du flux
}

void Jeu::actualiser(sf::RenderWindow &window)
{
    if(baseJoueur.isDead() == false && baseIA.isDead() == false)  //Si les bases en vie continue de jouer
    {

        baseIA.actualiser();
        baseJoueur.actualiser();

        this->MenuUnite(window);

        this->collision();

        ordinateur.actualiser(); //IA is update and do his startegy

        if(ordinateur.getAge() == 1 && expIA >= 1200)  //If AI have necessary exp age ->2
        {
            ordinateur.changementAge(); //Update the available units for AI
            baseIA.ameliorer();     //Upgrade AI base
        }

        for(int i =0; i < MAX_UNIT; i++)
        {
            //UPDATE PLAYERS'S UNIT

            if(joueur[i] != NULL) //If unit exist
            {
                if(joueur[i]->isDead() == true) //If unit have no life
                {
                    joueur[i] = mortUnite(joueur[i]);   //Destruct unit
                }
                else
                {
                    joueur[i]->actualiser();   //Update her
                }
            }

            //UPDATE AI'S UNIT
           ia[i] = ordinateur.actualiserUnite(ia[i], i);   //Update unite spawned by IA class

            if(ia[i] != NULL ) //If unit exist
            {
                if(ia[i]->isDead() == true) //If unit have no life
                {
                    ia[i] = mortUnite(ia[i]);  //Destruct unit
                    ordinateur.mortUnite(ia[i], i); //Update number of unite in AI class
                }
                else
                {
                    ia[i]->actualiser();
                }
            }
        }

        //UPDATE TEXT GOLD AND EXP
        flux << orJoueur;   //Store gold
        orText.setString(flux.str()); //Convert number as string
        flux.str("");   //Reset Flux

        flux << expJoueur; //Store exp
        ExpText.setString(flux.str()); //Convert number as string
        flux.str("");  //Reset Flux

        ordinateur.synchronize(&nbIA); //Recover number of unit of AI
    }

    else if(baseJoueur.isDead() == true)     //If player loose
    {
        FinishText.setColor(sf::Color::Red);
        FinishText.setString("Defaite");
    }

    else if(baseIA.isDead() == true)     //If player win
    {
        FinishText.setColor(sf::Color::Yellow);
        FinishText.setString("Victoire");
    }
}

void Jeu::afficher(sf::RenderWindow &window)
{
    window.draw(spriteFond);    //§Affiche le paysage

    if(baseIA.isDead() == false)    //Si la base est vivante
    {
       baseIA.afficher(window);     //Alors affiche la base IA
    }

    if(baseJoueur.isDead() == false) //N'affiche les bases que si elles sont en vie
    {
        baseJoueur.afficher(window);    //Alors affiche la base joueur
    }


    if(baseJoueur.isDead() == true || baseIA.isDead() == true)   //Si une des deux bases est morte
    {
        window.draw(FinishText);    // Afficher texte de fin
    }


    for(int i =0; i < MAX_UNIT; i++)
    {
        if(ia[i] != NULL)   //Si La case n'est pas vide alors unité et elle est afficher
        {
            ia[i]->afficher(window);
        }
    }


    for(int i =0; i < MAX_UNIT; i++)
    {
        if(joueur[i] != NULL)   //Si La case n'est pas vide alors unité et elle est afficher
        {
            joueur[i]->afficher(window);
        }
    }

    window.draw(imageMenuUnite); //Affiche Menu des unités

    window.draw(orText);    //Affiche l'or

    window.draw(ExpText);   //Affiche l'expérience

    window.draw(Unitetext); //Texte du nb d'unité
}

Jeu::~Jeu() //Destructor
{

}
