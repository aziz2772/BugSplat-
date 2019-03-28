#ifndef MENU2_H_INCLUDED
#define MENU2_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
  #include <math.h>


    //Valeurs attribuées aux états/directions
   #define WALK_RIGHT 1
   #define WALK_LEFT 2
   #define IDLE 3
   #define JUMP_RIGHT 4
   #define JUMP_LEFT 5
   #define RIGHT 1
   #define LEFT 2

  #define GRAVITY_SPEED 0.6
   #define MAX_FALL_SPEED 10
   #define JUMP_HEIGHT 13


#define PLAYER_SPEED 4
   /* Constantes pour l'animation */
   #define TIME_BETWEEN_2_FRAMES 10
  /* Taille du sprite de notre héros (largeur = width et hauteur = heigth) */
   #define PLAYER_WIDTH 67
   #define PLAYER_HEIGTH 55


 /* Taille de la fenêtre / résolution en plein écran */
  #define SCREEN_WIDTH 800
  #define SCREEN_HEIGHT 820

 /* Valeur RGB pour la transparence (canal alpha) */
 #define TRANS_R 255
 #define TRANS_G 0
 #define TRANS_B 255


 /* Taille maxi de la map : on voit large : 400 x 300 tiles */
 #define MAX_MAP_X 400
 #define MAX_MAP_Y 300

 /* Taille d'une tile (32 x 32 pixels) */
 #define TILE_SIZE 32



void menu2(SDL_Surface* ecran);
void menu1(SDL_Surface* ecran);
void settings(SDL_Surface* ecran);
void sound(SDL_Surface* ecran);
void jouer(SDL_Surface* ecran);
#endif // MENU2_H_INCLUDED
