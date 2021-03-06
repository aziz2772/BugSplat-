#include "draw.h"

   void drawImage(SDL_Surface *image, int x, int y)
  {
       SDL_Rect dest,rect;

       /* Règle le rectangle à blitter selon la taille de l'image source */

       dest.x = x;
       dest.y = y;
       dest.w = 800;
       dest.h = 820;


rect.x=200;
rect.y=300;

       /* Blitte l'image entière sur l'écran aux coordonnées x et y */

       SDL_BlitSurface(image, NULL, jeu.screen, &dest);

   }



   void draw(void)
{

    /* Affiche le fond (background) aux coordonnées (0,0) */
    drawImage(map.background, -map.startX, -map.startY);

    /* Affiche la map de tiles */
   
    /* Affiche le joueur */
    drawanimatedplayer();

    /* Affiche l'écran */
    SDL_Flip(jeu.screen);

    /* Delai */

    SDL_Delay(1);

}
   SDL_Surface *loadImage(char *name)
   {
       /* Charge une image temporaire avec SDL Image */

       SDL_Surface *temp = IMG_Load(name);
       SDL_Surface *image;

       /* Si elle n'est pas chargée on quitte avec une erreur */
      if (temp == NULL)
      {
           printf("Failed to load image %s\n", name);

          return NULL;
       }

       /* Ajoute la transparence à l'image temporaire en accord avec les defines TRANS_R, G, B */

       SDL_SetColorKey(temp, (SDL_SRCCOLORKEY | SDL_RLEACCEL), SDL_MapRGB(temp->format, 
                                                   TRANS_R, TRANS_G,    TRANS_B)); 


       /* Convertit l'image au format de l'écran (screen) pour un blit plus rapide */

       image = SDL_DisplayFormat(temp);
       
       /* Libère l'image temporaire */
       SDL_FreeSurface(temp);

       if (image == NULL)
       {
           printf("Failed to convert image %s to native format\n", name);

           return NULL;
       }

       /* Retourne l'image au format de l'écran pour accélérer son blit */

       return image;


   }
  void delay(unsigned int frameLimit)
  {

    /* Gestion des 60 fps (images/stories/seconde) */

    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
  }
