
#include "unit.h"
#include "util.h"

#ifndef AdvancedWars_infantry_h
#define AdvancedWars_infantry_h


/* methods declarion for all infantry units */
bool inf_atk(struct unt *slf, struct unt *def);             /* finished */
bool inf_def(struct unt *slf, struct unt *att,float *dmg);  /* almost finished */
bool inf_can_atk(struct unt *slf,struct unt *def);          /* almost finised */
bool inf_can_mov(struct unt *slf, int *loc);                /* almost finished */
bool inf_move(struct unt *slf, int *loc);                   /* almost finished */
bool inf_promote(struct unt *slf);                          /* finished */
void inf_refresh(struct unt *slf);                          /* finished */

/* special method for those who can do splash damage */
bool splash(struct unt *att,int *loc);

#endif
