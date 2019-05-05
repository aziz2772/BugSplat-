/**
* @file game.c
* @brief Testing Program.
* @author BUG SPLAT
* @version 0.1
* @date May 05, 2019
*
* Testing program for integration
*
*/
#include "main.h"
void jouer(SDL_Surface* ecran)
    
   {

SDL_Rect posmini,posnokta;
posmini.x=250;
posmini.y=40;


SDL_Surface* fond=NULL;


point.image=IMG_Load("point.png");

   unsigned int frameLimit = SDL_GetTicks() + 16;
    int go;
Mix_Music* backgroundSound = NULL;

int test8;

Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
backgroundSound = Mix_LoadMUS("musika.mp3");

Mix_PlayMusic(backgroundSound,0);
Mix_HaltMusic();
Cinematique cine;
	cine.numero_cinematique=1;
	cine.nbr_image=899;
    /* Initialisation de la SDL dans une fonction séparée (voir après) */
        init("PIZZEUS");
  /* On initialise le joueur */
     initializePlayer();

  initvie();
initializeMonster();
loadbestscore();

     /* Chargement des ressources (graphismes, sons) */
         loadGame();

	
	charge_image_cinematique(&cine);
	play_cinematique(&cine,jeu.screen);
jeu.screen = SDL_SetVideoMode(820, 700, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
   /* Appelle la fonction cleanup à la fin du programme */
     char chrono[16];    atexit(cleanup);
fond=IMG_Load("mini2.png");

    go = 1;
int x=0;
int y=0;
SDL_Rect waa;
SDL_Surface *image;
    /* Boucle infinie, principale, du jeu */

  SDL_Event event;

  SDL_Init(SDL_INIT_VIDEO);
Uint32 t1, t2, ok = 1;
  SDL_Surface *texte2 =  NULL;
  SDL_Color noir = {255,255,255,0}, rouge = {255,0,0};
 t1 = SDL_GetTicks();
 SDL_Rect positionFond,positionenigme;
positionFond.x=400;
positionFond.y=0;
  
 //SDL_WM_SetCaption("Timee", 0);
  TTF_Init();
TTF_Font *font,*police;
font = TTF_OpenFont("angelina.TTF", 56);
 
jeu.go=1;
int k;
 score.score = 0;
police = TTF_OpenFont("angelina.TTF", 50);
 
	 char actualScore[100];
        SDL_Color color;
        color.r = 255 ;
        color.g = 255 ;
        color.b = 255 ;

 SDL_Color color2;
        color2.r = 255 ;
        color2.g = 0 ;
        color2.b = 0 ;
        
        SDL_Rect pospoints,pospoints2;
        pospoints.x=570;
        pospoints.y=30;
positionenigme.x=200;
positionenigme.y=500;

pospoints2.x=240;
        pospoints2.y=300;

 
   SDL_BlitSurface(point.image,NULL,jeu.screen,&point.posnokta);

     while (jeu.go == 1)
    {



test8=0;

sprintf (actualScore,"score : %d",score.score);
game.points = TTF_RenderText_Blended(font,actualScore,color);
SDL_BlitSurface	(game.points,NULL,jeu.screen,&pospoints);

  temps.temps = SDL_GetTicks() - t1;         //Minute       //Seconde   //Dixieme
    sprintf(chrono, "%02u:%02u", (temps.temps)/1000/60%60, (temps.temps)/1000%60);
    texte2 = TTF_RenderText_Shaded(police, chrono, rouge,noir);
 
    SDL_BlitSurface(texte2, NULL, ecran, &positionFond);

                SDL_Flip(jeu.screen); 
   SDL_Delay(10);

    
        /* On vérifie l'état des entrées (clavier puis plus tard joystick) */

        getInput();

 updatePlayer();

calculate(&score.score);
        draw();

moveEnemy();
        /* On affiche tout */
                /* On met à jour le jeu */

drawEnemy(&Enemie);
gotHitByEnemy();

SDL_BlitSurface(fond,NULL,jeu.screen,&posmini);
SDL_BlitSurface(point.image,NULL,jeu.screen,&point.posnokta);
 


if ((player.x==2320)&&(test8==0))
{ 
k=functionenigme(jeu.screen);
if (k==0)
{
score.score-=1000;
}
}

SDL_Flip(jeu.screen); 
if (score.score>score.best)
{ score.best=score.score;
}
/**
* @brief Condition fin de jeu .
* @param player.x (position)
* @param ecran SDL_Surface
* @return Nothing
*/
if (player.x==2400)
{ drawWin(jeu.screen);
sprintf (actualScore,"score :  %d",score.score);
game.points = TTF_RenderText_Blended(font,actualScore,color2);
SDL_BlitSurface	(game.points,NULL,jeu.screen,&pospoints);

sprintf (actualScore,"Best SCORE :  %d",score.best);
game.score = TTF_RenderText_Blended(font,actualScore,color2);
SDL_BlitSurface	(game.score,NULL,jeu.screen,&pospoints2);
SDL_Flip(jeu.screen);

SDL_Delay(5000);
level2(ecran);
}

if (input.attack==1)
{
savinggame();
savingbestscore();
}
        /* Gestion des 60 fps ( 60 images pas seconde : soit 1s ->1000ms/60 = 16.6 -> 16
        On doit donc attendre 16 ms entre chaque image (frame) */
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;

    }

      
    TTF_Quit();

Mix_FreeMusic(backgroundSound);
Mix_CloseAudio();

    /* Exit */
    exit(0);

    


}
