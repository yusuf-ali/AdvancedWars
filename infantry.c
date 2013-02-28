#include <stdio.h>
#include "unit.h"
#include "util.h"

/*
 THIS IS THE FILE FOR INFANTRY METHODS
*/

/* methods declarion for all infantry units */
bool inf_atk(struct unt *slf, struct unt *def);             /* finished */
bool inf_def(struct unt *slf, struct unt *att,float *dmg);  
bool inf_can_atk(struct unt *slf, struct unt *def);
bool inf_can_mov(struct unt *slf, int *loc);                /* almost finished */
bool inf_move(struct unt *slf, int *loc);                   /* almost finished */
bool inf_promote(struct unt *slf);                          /* finished */
void inf_refresh(struct unt *slf);                          /* finished */

bool inf_atk(struct unt *slf, struct unt *def){
    
    /* determine if can attack */
    if(inf_can_atk(slf,def) == FALSE){return FALSE;}
    
    // make changes and "fire shot"
    slf->ammo--; slf->did_fire = TRUE;
    
    float tDMG = tDamage(slf,def);
    
    bool kill = def->def(def,slf,&tDMG);
    
    if(kill == TRUE){
        slf->promote(slf);
    }
    
    return TRUE;
}

bool inf_def(struct unt *slf, struct unt *att,float *dmg){
    return FALSE;
}

bool inf_can_atk(struct unt *slf, struct unt *def){
    return TRUE;
}

bool inf_can_mov(struct unt *slf, int *loc){
    /* determine if can move based on map characteristic */
    /* determine if can move if(board square == empty) */
    
    /* determine if can move using distance */
    float dis = distance(&slf->loc[0], loc);
    
    if(slf->cur_steps - (int)dis < 0){return FALSE;}
    
    return TRUE;
}

bool inf_move(struct unt *slf, int *loc){
    
    if(inf_can_mov(slf,loc) == FALSE){return FALSE;}
    
    float dis = distance(&slf->loc[0], loc);
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