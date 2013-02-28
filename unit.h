#import "util.h"

/*
 header is the universal unit "class"
 
 NOTE: This is not a true class, it is a struct with
        pointers to method
 
 Yusuf Ali
*/

#ifndef AdvancedWars_infantry_h
#define AdvancedWars_infantry_h


struct unt{
    /* constant, NEVER SHOULD CHANGE */
    int team;           /* team idenifier of the unit */
    int type;           /* sub class of the unit */
    int Class;          /* class of unit, for infantry it is 0 */
    int max_steps;      /* maximum steps this unit can make */
    
    /* static, change only with promotion */
    int max_ammo;        /* maximum unit */
    float range;          /* the range this unit can shoot */
    int rank;           /* the rank of a unit */
    int dmg[5];         /* damage modifiers to specific classes */
    
    /* dynamic, change atleast once per turn */
    int promo;          /* keeps count of kills needed for promotion */
    bool did_fire;      /* did the unit fire this turn */
    int cur_steps;      /* current steps used */
    int ammo;           /* current ammo of the unit */
    int loc[3];         /* this is an array of XYZ co-ords */
    float hp;           /* health points of a unit */
    int fuel;           /* fuel, for vehicles and stuff */

    /* METHOD DECLARATION SECTION
     
     attack and defence methods
        slf refers to this unit, or current unit
        def or att refers to the attacker or defender
        dmg is the theoretical damage inflicted
    */
    bool (*atk)(struct unt *slf, struct unt *def);
    bool (*def)(struct unt *slf, struct unt *att,float *dmg);
    
    bool (*can_atk)(struct unt *slf, struct unt *def);
    bool (*can_mov)(struct unt *slf, int *loc);
    
    bool (*move)(struct unt *slf, int *loc); /* moves units */
    bool (*promote)(struct unt *slf);   /* promotes units after cetain amount of kills */
    void (*refresh)(struct unt *slf);   /* resets the did_fire counter and cur_steps counter etc */
    
};

/* massive initialize method to initialize all units!! */
void initialize(struct unt *unit,int type,int team, int *loc);

/*
 these methods are for formulas used to calculate
 events in the game, theoretical damage etc.
 */
float tDamage(struct unt *atk,struct unt *def);                      // calculates theoretical damage
float aDamage(struct unt *def,int *tdmg);                      // calculates the actual damage inflicted
float rDamage(struct unt *def,struct unt *atk);                       // calculates the retaliation damage
float distance(int *loc1,int *loc2);                    // determins distance of 2 x,y,z vectors



#endif
