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

#ifndef AdvancedWars_unit_h
#define AdvancedWars_unit_h


struct unt{
    
    /* int variable section */
    int type;           /* sub class of the unit */
    int Class;          /* class of unit, for infantry it is 0 */
    int rank;           /* the rank of a unit */
    int loc[3];         /* this is an array of XYZ co-ords */
    int promo;          /* keeps count of kills needed for promotion */
    int dmg[5];         /* damage modifiers to specific classes */

    /* float variable section */
    float hp;           /* health points of a unit */

    /* method declaration section */
        /* attack and defend methods, slf refers to the "self" or "this" unit 
            def or att refers to the target unit */
    bool (*atk_u)(struct unt *slf, struct unt *def);      bool (*def_u)(struct unt *slf, struct unt *att);
    bool (*atk_v)(struct unt *slf, struct veh *def);      bool (*def_v)(struct unt *slf, struct veh *att);
    bool (*atk_s)(struct unt *slf, struct shp *def);      bool (*def_s)(struct unt *slf, struct shp *att);
    bool (*atk_a)(struct unt *slf, struct air *def);      bool (*def_a)(struct unt *slf, struct air *att);
    bool (*atk_b)(struct unt *slf, struct bld *def);      bool (*def_b)(struct unt *slf, struct bld *att);
    
    /* general methods for other uses */
    bool (*move)(struct unt *slf, int *loc);
    bool (*promote)(struct unt *slf);

};

#endif
