#include <stdio.h>
#include "infantry.h"

/* initializes the basic infantry unit file */
void initialize(struct unt *unit,int type,int team, int *loc){
    /* point functions to the empty functions in the struct */
    unit->promote = promote;    unit->move = move;
    
    /* spawn unit to a location */
    unit->loc[0] = *loc; unit->loc[1] = *(loc+1); unit->loc[2] = *(loc+2);
    
    /* initialize universal stats */
    unit->team = team; unit->type = type; unit->Class = 0;
    unit->dmg[2] = 0; unit->max_steps = 3; unit->max_ammo = 6;
    unit->rank = 1; unit->promo = 5; unit->cur_steps = unit->max_steps;
    unit->did_fire = FALSE; unit->ammo = 6; unit->hp = 100; unit->rank =0;
    
    /* initialize specific infantry stats */
    unit->range = data[0][type][5];
    
    unit->dmg[0] = data[0][type][0];
    unit->dmg[1] = data[0][type][1];
    unit->dmg[2] = data[0][type][2];
    unit->dmg[3] = data[0][type][3];
    unit->dmg[4] = data[0][type][4];
}


/* these methods are the basic functions */
bool move(struct unt *slf, int *loc){
    /* determine if move is possible */
    if(slf->cur_steps <= 0){return FALSE;}
    
    /* compute if magnitude of walk vector is possible */
    int dist = (int)distance(&slf->loc[0],loc);
    if(dist - slf->cur_steps < 0){return FALSE;}
    
    /* map is empty etc, possible to move to that square */
    
    
    slf->cur_steps -= dist;
    slf->loc[0] = *loc; slf->loc[1] = *(loc+1); slf->loc[2] = *(loc+2);
    
    return TRUE;
}

/* finished */
bool promote(struct unt *slf){
    /* determine if unit is able to be promoted */
    if(slf->promo != 0){return FALSE;}
    
    slf->promo += slf->rank;
    slf->max_ammo++;
    slf->rank++;
    slf->max_steps++;
    
    return TRUE;
}

bool can_attk(struct unt *slf,int *loc){
    /* determins if unit can shoot */
    if(slf->ammo == 0){return FALSE;}
    if(slf->did_fire == TRUE){return FALSE;}
    
    /* gets the minimum range to determine if withing range */
    int min_range = (slf->range - (int)slf->range ) * 10;
    if(distance(&slf->loc[0],loc) > slf->range || distance(&slf->loc[0],loc) < min_range){return FALSE;}
    
    
    return TRUE;
}