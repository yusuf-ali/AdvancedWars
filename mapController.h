#include "unit.h"

#ifndef AdvancedWars_mapController_h
#define AdvancedWars_mapController_h

/*
 this file will controll all map details
 that and also some details pertaining to every map
 again, using a struct just for simplicity to support multiple maps!
 
 by default all maps will be rectangle or square sized,
 "curved shapes" can be done in map design
*/

struct map{
    int x;      /* size dimensions for the map */
    
    /* 
     
     the map will contain the class of every object, 0 means empty
     it will also contain object details
        eg: trees and rocks and what not
     
    */
    int maps[10][10][10];            /* create map the size of the map */
    struct unt UNITS[10][10][10];   /* list of units */
    
    /*
     restrictions will basically be a list of whether or not unit can move there
     for example:
     restrictions[1,0,0] = 1                means any unit but class=1 can move there
     restrictions[0,3,1] = 3                means any unit but class=3 can move there
     restrictions[0,3,1] = 13               class 1 and 3 cannot move there
    */
    int restrictions[10][10][10];
    
    int default_spawn_height;   /* what we call "ground level", used for range calculations */
    
};



#endif
