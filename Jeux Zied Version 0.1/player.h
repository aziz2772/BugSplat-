
#include "structs.h"

extern Gestion jeu;
extern Hero player;
extern Input input;
extern Map map;
extern void centerScrollingOnPlayer(void);
/* Prototypes des fonctions utilisées */
void mapCollision(Hero *entity);

extern SDL_Surface *loadImage(char *name);
