#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
void main()

{

    SDL_Surface *ecran = NULL, *image = NULL;
Mix_Music* backgroundSound = NULL ;

Mix_Chunk* boutton;

Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
backgroundSound = Mix_LoadMUS("musika.mp3");

  



    SDL_Rect positionFond,positionClic;

    positionFond.x = 0;
    positionFond.y = 0;
boutton=Mix_LoadWAV("boutton.wav");


 ecran = SDL_SetVideoMode(900, 644, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
image= IMG_Load("menu play.png");
SDL_BlitSurface(image, NULL, ecran, &positionFond);

        SDL_Flip(ecran);

    SDL_Init(SDL_INIT_EVERYTHING);

    
   // ecran = SDL_SetVideoMode(900, 644, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);


    int i=1,x;

    int continuer = 1;
    //bool done;
    SDL_Event event;
Mix_PlayMusic(backgroundSound,-1);
   
    while (continuer)
    {
        x=0;
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
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


        //les images des boutons

        if(i==1)
        {
            image= IMG_Load("menu play.png");

        }

        if(i==2)
        {
            image= IMG_Load("menu.png");

        }
        if(i==4)
        {
            image = IMG_Load("menu quit.png");

        }
        if(i==3)
        {
            image = IMG_Load("menu credit finale.png");


        }
      
        SDL_BlitSurface(image, NULL, ecran, &positionFond);

        SDL_Flip(ecran);


        //aprés apuis des boutons

        }
        
        

    SDL_FreeSurface(image);
Mix_FreeChunk(boutton);
Mix_FreeMusic(backgroundSound);
Mix_CloseAudio();
   
    
  
    SDL_Quit();
            

    return;
            
}
