#include <stdio.h>
#include "infantry.h"
#include "gameController.h"

/*
 THIS IS THE FILE FOR INFANTRY METHODS
 */

bool splash(struct unt *att,int *loc){
    return FALSE;
}

bool inf_can_atk(struct unt *slf,struct unt *def){
    
    if (slf->ammo <= 0){return FALSE;}          // need ammo to shoot
    if (slf->did_fire == TRUE){return FALSE;}    // can't fire twice!
    if (slf->team == def->team){return FALSE;} // no friendly fire
    
    // ensure target is within range //FIX DIS
    float dist =  vector_dis(&slf->loc[0], &def->loc[0]);
    if((int)dist < slf->min_range || (int)dist > slf->range){
        return FALSE;
    }
    
    // collision detection!!!
    
    return FALSE;
}

bool inf_atk(struct unt *slf,struct unt *def){
    
    /* determine if can attack */
    if(inf_can_atk(slf,def) == FALSE){return FALSE;}
    
    // make changes and "fire shot"
    slf->ammo--; slf->did_fire = TRUE;
    
    float tDMG = tDamage(slf,def);
    
    bool kill = def->def(def,slf,&tDMG);
    bool spKil =  splash(slf,&def->loc[0]);
    
    if(kill == TRUE || spKil == TRUE){
        slf->promote(slf);
    }
    
    return TRUE;
}

bool inf_def(struct unt *slf, struct unt *att,float *dmg){
    
    // determine actual damage, and make change to HP
    float damage = aDamage(slf,dmg);
    slf->hp -= damage;
    
    //determine if unit is dead
    if(slf->hp <= 100){return TRUE;}
    
    //do retaliation damage
    // ONLY DOES RETALIATION IF NOT UNITS TURN>>>>>
    
    return FALSE;
}


bool inf_can_mov(struct unt *slf, int *loc){
    /* determine if can move based on map characteristic */
    if(game.MAPS.restrictions[*loc][*(loc+1)][*(loc+2)] == slf->Class){return FALSE;}
    
    /* determine if can move if(board square == empty) */
    if(game.MAPS.maps[*loc][*(loc+1)][*(loc+2)] != 0){return FALSE;}
    
    /* determine if can move using distance */
    //FIX!!!
    float dis = vector_dis(&slf->loc[0], loc);
    
    if(slf->cur_steps - (int)dis < 0){return FALSE;}
    
    return TRUE;
}

bool inf_move(struct unt *slf, int *loc){
    
    if(inf_can_mov(slf,loc) == FALSE){return FALSE;}
    
    float dis = vector_dis(&(slf->loc[0]), loc);
    slf->cur_steps -= (int)dis;
    
    slf->loc[0] = *loc;
    slf->loc[1] = *(loc+1);
    slf->loc[2] = *(loc+2);
    
    /* give height range bonus.... */
    
    
    return TRUE;
}

bool inf_promote(struct unt *slf){
    
    if(slf->promo > 0){return FALSE;}
    
    slf->promo = 5 + slf->rank;
    slf->rank += 1;
    slf->max_ammo += 1;
    slf->range += 1;
    
    return TRUE;
}

void inf_refresh(struct unt *slf){
    slf->did_fire = FALSE;
    slf->cur_steps = slf->max_steps;
}