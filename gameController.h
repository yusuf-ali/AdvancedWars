#include "mapController.h"

#ifndef AdvancedWars_gameController_h
#define AdvancedWars_gameController_h

/* game controlled used to control the flow of the game */
struct {
    
    /* game characteristics */
    int turn;       /* team 1 is 1, team 2 is 2  */
    int gold[2];    /* gold of team 1 and team 2 */
    struct map MAPS;  /* mapController structure */
    int status;     /* if game is done, status is not 0 */
    
    
} game = {.status = 0, .turn = 1};



#endif
