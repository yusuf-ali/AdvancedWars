#ifndef AdvancedWars_util_h
#define AdvancedWars_util_h

/*
 UTIL CONTAINS USEFUL FUNCTIONS, TYPEDEFS, ETC
*/

/* 
 boolean typedef, see http://stackoverflow.com/questions/1608318/is-bool-a-native-c-type
*/
typedef int bool;
#define TRUE 1 
#define FALSE 0


/* 
 
 the use of pointers allows us to modify the value,
 without having to return the value in order to be
 changed
 
 these methods are applied to all stats, in order to protect from
 memory scans (Cheat Engine, Moon Light Engine etc.)
 
*/
void encry(int *value);        /* this encrypts integer values */
void encryf(float *value);     /* this encrypts float values */
void encryd(double *value);    /* this encrypts double values */

void dcry(int *value);          /* this decrypes integer values */
void dcryf(float *value);       /* this decrypts float values */
void dcryd(double *value);      /* this decrypts double values */

/*
 these methods are for formulas used to calculate
 events in the game, theoretical damage etc.
*/
float tDamage(int *att,int *def,int *rank,int *mod);    // calculates theoretical damage
float aDamage(int *def,int *rank,int *tdmg);            // calculates the actual damage inflicted
float rDamage(int *def,int *att,int *rank,int *mod);    // calculates the retaliation damage
float distance(int *loc1,int *loc2);                    // determins distance of 2 x,y,z vectors

/* this data holds the table data for Units */
float data[5][9][7];
/*
 first dimension contains class identifier
 second dimension contains type identifier
 third dimension contains damage modifiers
        second last element contains the range
        last element of third dimension contains price
*/

#endif
