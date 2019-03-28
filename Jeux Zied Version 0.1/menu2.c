#include "defs.h"

#include "main.h"


void menu2(SDL_Surface* ecran)
{
int exp=0;
    SDL_Surface *image = NULL, *play = NULL,*option = NULL,*credit = NULL,*quit = NULL,*fond = NULL,*texte = NULL;
    int argc;
int k=1;
int test=1;
    char *argv[100];
TTF_Font *police = NULL;
Mix_Music* backgroundSound = NULL;

Mix_Chunk* boutton;

Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
backgroundSound = Mix_LoadMUS("musika.mp3");
boutton=Mix_LoadWAV("boutton.wav");
Mix_PlayMusic(backgroundSound,-1);
    SDL_Color couleurNoire = {0, 0, 0};

    TTF_Init();
int plz=1;



    SDL_Rect positionFond,positionClic,positionoption,positioncredit,positionquit;

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
  SDL_WM_SetCaption("PIZZEUS", NULL);



image= IMG_Load("sscape.png");
play= IMG_Load("new2.png");



            option= IMG_Load("continue 1.png");
            quit = IMG_Load("vide.png");

            credit = IMG_Load("loadlvl 1.png");
SDL_BlitSurface(image, NULL, ecran, &positionFond);
SDL_BlitSurface(fond, NULL, ecran, &positionFond);
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
SDL_Event event2;
 /* Chargement de la police */
    police = TTF_OpenFont("angelina.TTF", 40);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "Bug Splat", couleurNoire);
       positionFond.x = 0;
        positionFond.y = 600;
        SDL_BlitSurface(texte, NULL, ecran, &positionFond); /* Blit du texte */
        SDL_Flip(ecran);
while (continuer)
    {
        
SDL_WaitEvent(&event);

        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
test=0;
            break;
            
case SDL_KEYDOWN:

            switch(event.key.keysym.sym)

            {

            case SDLK_UP:
Mix_PlayChannel(-1,boutton,0);
                if (k==1)
                    k=3;

                else


                    k--;
                break;

            case SDLK_DOWN:
Mix_PlayChannel(-1,boutton,0);

                if(k==3)
                    k=1;

                else



                    k++;
                break;
            
case SDLK_ESCAPE: // C'est la touche Échap
            
             menu1(ecran);

// Action à faire lorsque l'utilisateur relâche la touche Échap
            
            break;
case SDLK_RETURN:
Mix_PlayChannel(-1,boutton,0);
                if(k==1)
                {
                    jouer(ecran);
break;
                }
}
        }

       if(k==1)
        {
            play= IMG_Load("new2.png");
option= IMG_Load("continue 1.png");
quit = IMG_Load("vide.png");
credit = IMG_Load("loadlvl 1.png");

        }

        if(k==2)
        {
play= IMG_Load("new1.png");
option= IMG_Load("continue 2.png");
quit = IMG_Load("vide.png");
credit = IMG_Load("loadlvl 1.png");

        }
        if(k==3)
        {
play= IMG_Load("new1.png");
option= IMG_Load("continue 1.png");
quit = IMG_Load("vide.png");
credit = IMG_Load("loadlvl 2.png");
        }

SDL_BlitSurface(fond, NULL, ecran, &positionFond);
SDL_BlitSurface(play, NULL, ecran, &positionClic);
SDL_BlitSurface(option, NULL, ecran, &positionoption);
SDL_BlitSurface(credit, NULL, ecran, &positioncredit);
SDL_BlitSurface(quit, NULL, ecran, &positionquit);
SDL_Flip(ecran);



}

    Mix_FreeChunk(boutton);
Mix_FreeMusic(backgroundSound);
Mix_CloseAudio();
    SDL_FreeSurface(image);
    SDL_FreeSurface(play);
SDL_FreeSurface(option);
  SDL_FreeSurface(credit);
 SDL_FreeSurface(quit);



      TTF_CloseFont(police);
    TTF_Quit();
SDL_FreeSurface(texte);

    SDL_Quit();


}
void menu1(SDL_Surface* ecran){
int exp=0;
    SDL_Surface *image = NULL, *play = NULL,*option = NULL,*credit = NULL,*quit = NULL,*fond = NULL,*texte = NULL;
    int argc;
int k=1;
int test=1;
    char *argv[100];
TTF_Font *police = NULL;
Mix_Music* backgroundSound = NULL;

Mix_Chunk* boutton;

Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
backgroundSound = Mix_LoadMUS("musika.mp3");
boutton=Mix_LoadWAV("boutton.wav");
Mix_PlayMusic(backgroundSound,-1);
    SDL_Color couleurNoire = {0, 0, 0};

    TTF_Init();
int plz=1;



    SDL_Rect positionFond,positionClic,positionoption,positioncredit,positionquit;

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
  SDL_WM_SetCaption("PIZZEUS", NULL);

 //fond = IMG_Load("vierge.png");
image= IMG_Load("sscape.png");
option= IMG_Load("option 1.png");
play= IMG_Load("play 2.png");
credit=IMG_Load("credit 1.png");
quit=IMG_Load("quit 1.png");
//option2= IMG_Load("option 2.png");
//play2= IMG_Load("play 1.png");
//credit2=IMG_Load("credit 2.png"

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
SDL_Event event2;
 /* Chargement de la police */
    police = TTF_OpenFont("angelina.TTF", 40);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "Bug Splat", couleurNoire);
       positionFond.x = 0;
        positionFond.y = 600;
        SDL_BlitSurface(texte, NULL, ecran, &positionFond); /* Blit du texte */
        SDL_Flip(ecran);

    while (continuer)
    {




exp=0;
//positionFond.x = 500;
        //positionFond.y = 360;
        //SDL_BlitSurface(texte, NULL, ecran, &positionFond); /* Blit du texte */
        //SDL_Flip(ecran);
        x=0;
        SDL_WaitEvent(&event);
SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
test=0;
plz=0;
            break;


        case SDL_KEYDOWN:

            switch(event.key.keysym.sym)

            {

            case SDLK_UP:
Mix_PlayChannel(-1,boutton,0);
                if (i==1)
                    i=4;

                else


                    i--;
                break;

            case SDLK_DOWN:
Mix_PlayChannel(-1,boutton,0);

                if(i==4)
                    i=1;

                else



                    i++;
                break;


            
case SDLK_RETURN:
Mix_PlayChannel(-1,boutton,0);
                if(i==1)
                {
                    menu2(ecran);
break;
                }
                if(i==2)
                {
                    x=2;
settings(ecran);

                }
                if(i==3)
                {

                    x=3;


                }
                if(i==4)
                {
                    x=4;
continuer=0;


                }

                break;


            }

             case SDL_MOUSEMOTION:
            if (event.motion.x>640 && event.motion.x<841 && event.motion.y>150 && event.motion.y<210)
            {
                i=1;

            }

            else if (event.motion.x>640 && event.motion.x<841 && event.motion.y>220 && event.motion.y<270)
            {
                i=2;

            }
            else if (event.motion.x>640 && event.motion.x<841 && event.motion.y>290 && event.motion.y<350)
            {
                i=3;

            }
            else if (event.motion.x>640 && event.motion.x<841 && event.motion.y>361 && event.motion.y<410)
            {
                i=4;

            }
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




        //les images des boutons



 SDL_BlitSurface(fond, NULL, ecran, &positionFond);
SDL_BlitSurface(play, NULL, ecran, &positionClic);
SDL_BlitSurface(option, NULL, ecran, &positionoption);
SDL_BlitSurface(credit, NULL, ecran, &positioncredit);
SDL_BlitSurface(quit, NULL, ecran, &positionquit);

        SDL_Flip(ecran);
}


    Mix_FreeChunk(boutton);
Mix_FreeMusic(backgroundSound);
Mix_CloseAudio();
    SDL_FreeSurface(image);
    SDL_FreeSurface(play);
SDL_FreeSurface(option);
  SDL_FreeSurface(credit);
 SDL_FreeSurface(quit);



      TTF_CloseFont(police);
    TTF_Quit();
SDL_FreeSurface(texte);

    SDL_Quit();


}
void settings(SDL_Surface* ecran)
{
int exp=0;
    SDL_Surface *image = NULL, *play = NULL,*option = NULL,*credit = NULL,*quit = NULL,*fond = NULL,*texte = NULL;
    int argc;
int k=1;
int test=1;
    char *argv[100];
TTF_Font *police = NULL;
Mix_Music* backgroundSound = NULL;

Mix_Chunk* boutton;

Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
backgroundSound = Mix_LoadMUS("musika.mp3");
boutton=Mix_LoadWAV("boutton.wav");
Mix_PlayMusic(backgroundSound,-1);
    SDL_Color couleurNoire = {0, 0, 0};

    TTF_Init();
int plz=1;



    SDL_Rect positionFond,positionClic,positionoption,positioncredit,positionquit;

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
  SDL_WM_SetCaption("PIZZEUS", NULL);



image= IMG_Load("sscape.png");
play= IMG_Load("sound 2.png");
option= IMG_Load("quit 1.png");

SDL_BlitSurface(image, NULL, ecran, &positionFond);
SDL_BlitSurface(fond, NULL, ecran, &positionFond);
SDL_BlitSurface(play, NULL, ecran, &positionClic);
SDL_BlitSurface(option, NULL, ecran, &positionoption);



 SDL_Flip(ecran);
  SDL_Init(SDL_INIT_EVERYTHING);

 int i=1,x=1;

    int continuer = 1;
    //bool done;
    SDL_Event event;
SDL_Event event2;
 /* Chargement de la police */
    police = TTF_OpenFont("angelina.TTF", 40);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "Bug Splat", couleurNoire);
       positionFond.x = 0;
        positionFond.y = 600;
        SDL_BlitSurface(texte, NULL, ecran, &positionFond); /* Blit du texte */
        SDL_Flip(ecran);
while (continuer)
    {
        
SDL_WaitEvent(&event);

        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
test=0;
            break;
            
case SDL_KEYDOWN:

            switch(event.key.keysym.sym)

            {
  case SDLK_UP:
Mix_PlayChannel(-1,boutton,0);
                if (k==1)
                    k=2;

                else


                    k--;
                break;

            case SDLK_DOWN:
Mix_PlayChannel(-1,boutton,0);

                if(k==2)
                    k=1;

                else



                    k++;
                break;
case SDLK_RETURN:
Mix_PlayChannel(-1,boutton,0);
if (k==1){
               sound(ecran);}

break;
case SDLK_ESCAPE: // C'est la touche Échap
            
             menu1(ecran);

// Action à faire lorsque l'utilisateur relâche la touche Échap
            
            break;
}
}
if(k==1)
        {
            play= IMG_Load("sound 2.png");
option= IMG_Load("quit 1.png");
quit = IMG_Load("vide.png");
credit = IMG_Load("vide.png");

        }

        if(k==2)
        {
play= IMG_Load("sound 1.png");
option= IMG_Load("quit 2.png");
quit = IMG_Load("vide.png");
credit = IMG_Load("vide.png");

        }
 SDL_BlitSurface(fond, NULL, ecran, &positionFond);
SDL_BlitSurface(play, NULL, ecran, &positionClic);
SDL_BlitSurface(option, NULL, ecran, &positionoption);
SDL_BlitSurface(credit, NULL, ecran, &positioncredit);
SDL_BlitSurface(quit, NULL, ecran, &positionquit);
SDL_Flip(ecran);

}

Mix_FreeChunk(boutton);
Mix_FreeMusic(backgroundSound);
Mix_CloseAudio();
    SDL_FreeSurface(image);
    SDL_FreeSurface(play);
SDL_FreeSurface(option);
  SDL_FreeSurface(credit);
 SDL_FreeSurface(quit);



      TTF_CloseFont(police);
    TTF_Quit();
SDL_FreeSurface(texte);

    SDL_Quit();


}


void sound(SDL_Surface* ecran)
{

int exp=0;
    SDL_Surface *image = NULL, *play = NULL,*option = NULL,*credit = NULL,*quit = NULL,*fond = NULL,*texte = NULL;
    int argc;
int k=1;
int test=1;
    char *argv[100];
TTF_Font *police = NULL;
Mix_Music* backgroundSound = NULL;

Mix_Chunk* boutton;

Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
backgroundSound = Mix_LoadMUS("musika.mp3");
boutton=Mix_LoadWAV("boutton.wav");
Mix_PlayMusic(backgroundSound,-1);
    SDL_Color couleurNoire = {0, 0, 0};

    TTF_Init();
int plz=1;



    SDL_Rect positionFond,positionClic,positionoption,positioncredit,positionquit;

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
  SDL_WM_SetCaption("PIZZEUS", NULL);



image= IMG_Load("sscape.png");
play= IMG_Load("on 1.png");



            option= IMG_Load("off 2.png");
            quit = IMG_Load("vide.png");

            credit = IMG_Load("vide.png");
SDL_BlitSurface(image, NULL, ecran, &positionFond);
SDL_BlitSurface(fond, NULL, ecran, &positionFond);
SDL_BlitSurface(play, NULL, ecran, &positionClic);
SDL_BlitSurface(option, NULL, ecran, &positionoption);
SDL_BlitSurface(credit, NULL, ecran, &positioncredit);
SDL_BlitSurface(quit, NULL, ecran, &positionquit);

 SDL_Flip(ecran);
  SDL_Init(SDL_INIT_EVERYTHING);


 int i=1,x=1;

    int continuer = 1;
    //bool done;
    SDL_Event event;
SDL_Event event2;
 /* Chargement de la police */
    police = TTF_OpenFont("angelina.TTF", 40);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "Bug Splat", couleurNoire);
       positionFond.x = 0;
        positionFond.y = 600;
        SDL_BlitSurface(texte, NULL, ecran, &positionFond); /* Blit du texte */
        SDL_Flip(ecran);
while (continuer)
    {
        
SDL_WaitEvent(&event);

        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
test=0;
            break;

case SDL_KEYDOWN:

            switch(event.key.keysym.sym)

            {

             case SDLK_UP:
Mix_PlayChannel(-1,boutton,0);
                if (k==1)
                    k=2;

                else


                    k--;
                break;

            case SDLK_DOWN:
Mix_PlayChannel(-1,boutton,0);

                if(k==2)
                    k=1;

                else



                    k++;
                break;
            case SDLK_ESCAPE: // C'est la touche Échap
            
             settings(ecran);

// Action à faire lorsque l'utilisateur relâche la touche Échap
            
            break;
}

}
if(k==1)
        {
            play= IMG_Load("on 1.png");
option= IMG_Load("off 2.png");
quit = IMG_Load("vide.png");
credit = IMG_Load("vide.png");

        }

        if(k==2)
        {
play= IMG_Load("on 2.png");
option= IMG_Load("off 1.png");
quit = IMG_Load("vide.png");
credit = IMG_Load("vide.png");

        }
 SDL_BlitSurface(fond, NULL, ecran, &positionFond);
SDL_BlitSurface(play, NULL, ecran, &positionClic);
SDL_BlitSurface(option, NULL, ecran, &positionoption);
SDL_BlitSurface(credit, NULL, ecran, &positioncredit);
SDL_BlitSurface(quit, NULL, ecran, &positionquit);
SDL_Flip(ecran);

}
 

Mix_FreeChunk(boutton);
Mix_FreeMusic(backgroundSound);
Mix_CloseAudio();
    SDL_FreeSurface(image);
    SDL_FreeSurface(play);
SDL_FreeSurface(option);
  SDL_FreeSurface(credit);
 SDL_FreeSurface(quit);



      TTF_CloseFont(police);
    TTF_Quit();
SDL_FreeSurface(texte);

    SDL_Quit();

}
void jouer(SDL_Surface* ecran)
    
   {
   unsigned int frameLimit = SDL_GetTicks() + 16;
    int go;

    /* Initialisation de la SDL dans une fonction séparée (voir après) */
        init("Aron");
  /* On initialise le joueur */
     initializePlayer();

     /* Chargement des ressources (graphismes, sons) */
         loadGame();


   /* Appelle la fonction cleanup à la fin du programme */
         atexit(cleanup);

    go = 1;


    /* Boucle infinie, principale, du jeu */

     while (go == 1)
    {

        /* On vérifie l'état des entrées (clavier puis plus tard joystick) */
        getInput();


        
 updatePlayer();

        /* On affiche tout */
                /* On met à jour le jeu */
draw();

        /* Gestion des 60 fps ( 60 images pas seconde : soit 1s ->1000ms/60 = 16.6 -> 16
        On doit donc attendre 16 ms entre chaque image (frame) */
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;

    }

    /* Exit */
    exit(0);

    }







