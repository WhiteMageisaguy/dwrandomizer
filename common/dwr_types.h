
#ifndef _DWR_TYPES_H_
#define _DWR_TYPES_H_

#include <inttypes.h>

#define ROM_SIZE 81936

#define ABS(x) ((x < 0) ? -x : x)
#define MAX(x,y) ((x > y) ? x : y)
#define MIN(x,y) ((x < y) ? x : y)

typedef enum {
    false,
    true,
} bool;

typedef enum {
    NO_MAP,
    OVERWORLD,
    CHARLOCK,
    HAUKSNESS,
    TANTEGEL,
    TANTEGEL_THRONE_ROOM, /* 5 */
    CHARLOCK_THRONE_ROOM,
    KOL,
    BRECCONARY,
    GARINHAM,
    CANTLIN, /* 10 */
    RIMULDAR,
    TANTEGEL_BASEMENT,
    NORTHERN_SHRINE,
    SOUTHERN_SHRINE,
    CHARLOCK_CAVE_1, /* 15 */
    CHARLOCK_CAVE_2,
    CHARLOCK_CAVE_3,
    CHARLOCK_CAVE_4,
    CHARLOCK_CAVE_5,
    CHARLOCK_CAVE_6, /* 20 */
    SWAMP_CAVE,
    MOUNTAIN_CAVE,
    MOUNTAIN_CAVE_2,
    GARINS_GRAVE_1,
    GARINS_GRAVE_2, /* 25 */
    GARINS_GRAVE_3,
    GARINS_GRAVE_4,
    ERDRICKS_CAVE,
    ERDRICKS_CAVE_2
} dw_map_index;

typedef enum {
    SLIME,       /* 0 */
    RED_SLIME,
    DRAKEE,
    GHOST,
    MAGICIAN,
    MAGIDRAKEE,  /* 5 */
    SCORPION,
    DRUIN,
    POLTERGEIST,
    DROLL,
    DRAKEEMA,    /* 10 */
    SKELETON,
    WARLOCK,
    METAL_SCORPION,
    WOLF,
    WRAITH,      /* 15 */
    METAL_SLIME,
    SPECTER,
    WOLFLORD,
    DRUINLORD,
    DROLLMAGI,   /* 20 */
    WYVERN,
    ROGUE_SCORPION,
    WRAITH_KNIGHT,
    GOLEM,
    GOLDMAN,     /* 25 */
    KNIGHT,
    MAGIWYVERN,
    DEMON_KNIGHT,
    WEREWOLF,
    GREEN_DRAGON,/* 30 */
    STARWYVERN,
    WIZARD,
    AXE_KNIGHT,
    BLUE_DRAGON,
    STONEMAN,   /* 35 */
    ARMORED_KNIGHT,
    RED_DRAGON,
    DRAGONLORD_1,
    DRAGONLORD_2
} dw_enemies;

typedef enum {
    HERB = 0x2,
    KEY,
    TORCH,
    FAIRY_WATER, /* 5 */
    WINGS,
    DRAGONS_SCALE,
    FLUTE,
    RING,
    TOKEN, /* 10 */
    GWAELINS_LOVE,
    CURSED_BELT,
    HARP,
    NECKLACE,
    STONES, /* 15 */
    STAFF,
    SWORD,
    GOLD_5,
    GOLD_6,
    GOLD_10, /* 20 */
    GOLD_500,
    GOLD_120,
    TABLET,
} dw_chest_content;

typedef enum {
    BAMBOO_POLE,
    CLUB,
    COPPER_SWORD,
    HAND_AXE,
    BROAD_SWORD,
    FLAME_SWORD,
    ERDRICKS_SWORD,
    CLOTHES,
    LEATHER_ARMOR,
    CHAIN_MAIL,
    HALF_PLATE,
    FULL_PLATE,
    MAGIC_ARMOR,
    ERDRICKS_ARMOR,
    SMALL_SHIELD,
    LARGE_SHIELD,
    SILVER_SHIELD,
    SHOP_END = 0xfd,
} dw_shop_item;

typedef struct {
    uint8_t y;
    uint8_t code[27];
    uint8_t x;
} dw_love_calc;

typedef struct {
    uint8_t code1[3];
    uint8_t map;
    uint8_t code2[5];
    uint8_t x;
    uint8_t code3[5];
    uint8_t y;
} dw_forced_encounter;

typedef struct {
    uint8_t code1[3];
    uint8_t map;
    uint8_t code2[5];
    uint8_t x;
    uint8_t code3[5];
    uint8_t y;
} dw_searchable;

typedef struct {
    uint8_t map;
    uint8_t x;
    uint8_t y;
    uint8_t item;
} dw_chest;

typedef struct {
    uint8_t str;
    uint8_t agi;
    uint8_t hp;
    uint8_t pattern;
    uint8_t s_ss_resist; /* sleep/stopspell resist */
    uint8_t hr_dodge; /* hurt resist/dodge */
    uint8_t xp;
    uint8_t gold;
    uint64_t graphics;
} dw_enemy;

typedef struct {
    uint8_t str;
    uint8_t agi;
    uint8_t hp;
    uint8_t mp;
    uint16_t spells;
} dw_stats;

typedef struct {
    uint8_t code1;
    uint8_t level;
    uint8_t code2[2];
} dw_new_spell;

typedef struct {
    uint8_t pointer[2]; /* if we use uint16_t here it causes memalign issues */
    uint8_t width;      /* This causes the struct to be size 6 instead of 5, */
    uint8_t height;     /* which breaks things */
    uint8_t border;
} dw_map_meta;

typedef struct {
    uint8_t map;
    uint8_t x;
    uint8_t y;
} dw_warp;

typedef struct {
    uint8_t map;
    uint8_t code1[3];
    uint8_t x;
    uint8_t code2[7];
    uint8_t y;

} dw_return_point;

typedef struct {
    uint8_t code1[3];
    uint8_t map;
    uint8_t code2[5];
    uint8_t x;
    uint8_t code3[5];
    uint8_t y;
} dw_rainbow_drop;

typedef struct {
    uint16_t *pointers;
    uint8_t *encoded;
    uint64_t flags;
    dw_map_meta *meta;
    dw_warp *warps_from;
    dw_warp *warps_to;
    dw_love_calc *love_calc;
    dw_return_point *return_point;
    dw_rainbow_drop *rainbow_drop;
    dw_rainbow_drop *rainbow_bridge;
    uint8_t tiles[120][120];
    uint8_t walkable[120][120];
} dw_map;

typedef struct {
    uint8_t *data;
    uint64_t flags;
    uint64_t seed;
    dw_map map;
    dw_stats *stats;
    dw_new_spell *new_spells;
    uint8_t *mp_reqs;
    uint16_t *xp_reqs;
    dw_enemy *enemies;
    uint8_t *zones;
    uint8_t *zone_layout;
    dw_chest *chests;
    dw_forced_encounter *axe_knight;
    dw_forced_encounter *green_dragon;
    dw_forced_encounter *golem;
    uint8_t *encounter_types[3];
    dw_searchable *token;
    dw_searchable *flute;
    dw_searchable *armor;
    uint8_t *weapon_shops;
    uint8_t *music;
    uint8_t *title_text;
} dw_rom;

#endif
