#import "vehicles.h"
#import "ships.h"
#import "aircraft.h"
#import "buildings.h"
#import "util.h"

/*
 header declaration file for the infantry class
 this will contain all declaration statements for 
    - methods
    - structures
    - needed variables
 
 NOTE: This is not a true class, it is a struct with
        pointers to variables
 
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

    /* method declaration section 
     
     attack and defence methods
        slf refers to this unit, or current unit
        def or att refers to the attacker or defender
        dmg is the theoretical damage inflicted
    */
    bool (*atk_u)(struct unt *slf, struct unt *def);      bool (*def_u)(struct unt *slf, struct unt *att,float *dmg);
    bool (*atk_v)(struct unt *slf, struct veh *def);      bool (*def_v)(struct unt *slf, struct veh *att,float *dmg);
    bool (*atk_s)(struct unt *slf, struct shp *def);      bool (*def_s)(struct unt *slf, struct shp *att,float *dmg);
    bool (*atk_a)(struct unt *slf, struct air *def);      bool (*def_a)(struct unt *slf, struct air *att,float *dmg);
    bool (*atk_b)(struct unt *slf, struct bld *def);      bool (*def_b)(struct unt *slf, struct bld *att,float *dmg);
    
    /* general methods for other uses */
    bool (*move)(struct unt *slf, int *loc);
    bool (*promote)(struct unt *slf);
    
};


void initialize(struct unt *unit,int type,int team, int *loc);

/* typical unit methods */
bool move(struct unt *slf, int *loc);
bool promote(struct unt *slf);
bool can_attk(struct unt *slf,int *loc);

bool atk_u(struct unt *slf, struct unt *def);      bool def_u(struct unt *slf, struct unt *att,float *dmg);
bool atk_v(struct unt *slf, struct veh *def);      bool def_v(struct unt *slf, struct veh *att,float *dmg);
bool atk_s(struct unt *slf, struct shp *def);      bool def_s(struct unt *slf, struct shp *att,float *dmg);
bool atk_a(struct unt *slf, struct air *def);      bool def_a(struct unt *slf, struct air *att,float *dmg);
bool atk_b(struct unt *slf, struct bld *def);      bool def_b(struct unt *slf, struct bld *att,float *dmg);




#endif
