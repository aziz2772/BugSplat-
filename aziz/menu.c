#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
void main()

{
     int argc;
 char *argv[100];
    SDL_Surface *ecran = NULL, *image = NULL, *play = NULL,*option = NULL,*credit = NULL,*quit = NULL,*texte = NULL;

   SDL_Event eventa;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
    int continuer = 1;
    int tempsActuel = 0, tempsPrecedent = 0, compteur = 0;
    char temps[20] = ""; /* Tableau de char suffisamment grand */
 SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();




    SDL_Rect positionFond,positionClic,positionoption,positioncredit,positionquit,position;

    positionFond.x = 0;
    positionFond.y = 0;

positionClic.x=640;
positionClic.y=150;

positionoption.x=640;
positionoption.y=220;

positioncredit.x=640;
positioncredit.y=290;

positionquit.x=640;
positionquit.y=360;

 ecran = SDL_SetVideoMode(920, 644, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);
    /* Chargement de la police */
    police = TTF_OpenFont("angelina.ttf", 65);

    /* Initialisation du temps et du texte */
    tempsActuel = SDL_GetTicks();
    sprintf(temps, "Temps : %d", compteur);
    texte = TTF_RenderText_Shaded(police, temps, couleurNoire, couleurBlanche);
image= IMG_Load("vierge.png");
option= IMG_Load("option 1.png");
play= IMG_Load("play 2.png");
credit=IMG_Load("credit 1.png");
quit=IMG_Load("quit 1.png");
//option2= IMG_Load("option 2.png");
//play2= IMG_Load("play 1.png");
//credit2=IMG_Load("credit 2.png");
//quit2=IMG_Load("quit 2.png");
SDL_BlitSurface(image, NULL, ecran, &positionFond);
SDL_BlitSurface(play, NULL, ecran, &positionClic);
SDL_BlitSurface(option, NULL, ecran, &positionoption);
SDL_BlitSurface(credit, NULL, ecran, &positioncredit);
SDL_BlitSurface(quit, NULL, ecran, &positionquit);

        SDL_Flip(ecran);

    SDL_Init(SDL_INIT_EVERYTHING);

    
   // ecran = SDL_SetVideoMode(900, 644, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);


    int i=1,x=1;

    int continuer = 1;
    //bool done;
    SDL_Event event;
   
    while (continuer)
    {
        x=0;
        SDL_WaitEvent(&event);
switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
     SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));


        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent >= 100) /* Si 100ms au moins se sont écoulées */
        {
            compteur += 100; /* On rajoute 100ms au compteur */
            sprintf(temps, "Temps : %d", compteur); /* On écrit dans la chaîne "temps" le nouveau temps */
            SDL_FreeSurface(texte); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
            texte = TTF_RenderText_Shaded(police, temps, couleurNoire, couleurBlanche); /* On écrit la chaine temps dans la SDL_Surface */
            tempsPrecedent = tempsActuel; /* On met à jour le tempsPrecedent */
        }

        position.x = 180;
        position.y = 210;
        SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte contenant le temps */
        SDL_Flip(ecran);
 case SDL_KEYDOWN:

            switch(event.key.keysym.sym)

            {

            case SDLK_UP:

                if (i==1)
                    i=4;

                else


                    i--;
                break;

            case SDLK_DOWN:


                if(i==4)
                    i=1;

                else



                    i++;
                break;

            }

        if(i==1)
        {
            play= IMG_Load("play 2.png");
option= IMG_Load("option 1.png");
quit = IMG_Load("quit 1.png");
credit = IMG_Load("credit 1.png");

        }

        if(i==2)
        {
play= IMG_Load("play 1.png");

quit = IMG_Load("quit 1.png");
credit = IMG_Load("credit 1.png");
            option= IMG_Load("option 2.png");

        }
        if(i==4)
        {
play= IMG_Load("play 1.png");


credit = IMG_Load("credit 1.png");
            option= IMG_Load("option 1.png");
            quit = IMG_Load("quit 2.png");

        }
        if(i==3)
        {
play= IMG_Load("play 1.png");



            option= IMG_Load("option 1.png");
            quit = IMG_Load("quit 1.png");

            credit = IMG_Load("credit 2.png");


        }
}



        //les images des boutons

        

        SDL_BlitSurface(image, NULL, ecran, &positionFond);
SDL_BlitSurface(play, NULL, ecran, &positionClic);
SDL_BlitSurface(option, NULL, ecran, &positionoption);
SDL_BlitSurface(credit, NULL, ecran, &positioncredit);
SDL_BlitSurface(quit, NULL, ecran, &positionquit);

        SDL_Flip(ecran);


        //aprés apuis des boutons

        }
        
        
TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(texte);
    SDL_FreeSurface(image);
    SDL_FreeSurface(play);
SDL_FreeSurface(option);
  SDL_FreeSurface(credit);
 SDL_FreeSurface(quit);

   
   
    
  
    SDL_Quit();
            

    return;
            
}
