 #include "structs.h"

  /* Prototypes des fonctions utilisées */

  extern void init(char *);
  extern void cleanup(void);
  extern void getInput(void);
  extern void draw(void);
 
  extern void loadGame(void);
  extern void delay(unsigned int frameLimit);

extern void drawanimatedplayer(void);
extern void updatePlayer(void);
Hero player;
extern void initializePlayer(void);
extern void mapCollision(Hero);

  /* Déclaration des structures globales utilisées par le jeu */

  Input input;
  Gestion jeu;

  Map map;
