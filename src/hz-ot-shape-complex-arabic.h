#ifndef HZ_OT_SHAPE_COMPLEX_ARABIC_H
#define HZ_OT_SHAPE_COMPLEX_ARABIC_H

#include "hz-base.h"
#include "util/hz-array.h"

typedef enum hz_arabic_joining_type_t {
    JOINING_TYPE_R = 0x0100, /* Right-Joining */
    JOINING_TYPE_L = 0x0200, /* Left-Joining */
    JOINING_TYPE_D = 0x0400, /* Dual-Joining */
    JOINING_TYPE_C = 0x0800, /* Join-Causing */
    JOINING_TYPE_U = 0x1000, /* Non-Joining */
    JOINING_TYPE_T = 0x2000, /* Transparent */
} hz_arabic_joining_type_t;

typedef enum hz_arabic_joining_group_t {
    /* Arabic */
    NO_JOINING_GROUP = 0,
    JOINING_GROUP_ALEF = 1,
    JOINING_GROUP_TEH_MARBUTA,
    JOINING_GROUP_TEH_MARBUTA_GOAL,
    JOINING_GROUP_DAL,
    JOINING_GROUP_REH,
    JOINING_GROUP_WAW,
    JOINING_GROUP_STRAIGHT_WAW,
    JOINING_GROUP_YEH_WITH_TAIL,
    JOINING_GROUP_YEH_BARREE,
    JOINING_GROUP_ROHINGYA_YEH,
    JOINING_GROUP_BEH,
    JOINING_GROUP_HAH,
    JOINING_GROUP_SEEN,
    JOINING_GROUP_SAD,
    JOINING_GROUP_TAH,
    JOINING_GROUP_AIN,
    JOINING_GROUP_FEH,
    JOINING_GROUP_QAF,
    JOINING_GROUP_KAF,
    JOINING_GROUP_LAM,
    JOINING_GROUP_MEEM,
    JOINING_GROUP_NOON,
    JOINING_GROUP_HEH,
    JOINING_GROUP_YEH,
    JOINING_GROUP_SWASH_KAF,
    JOINING_GROUP_GAF,
    JOINING_GROUP_NYA,
    JOINING_GROUP_KNOTTED_HEH,
    JOINING_GROUP_HEH_GOAL,
    JOINING_GROUP_FARSI_YEH,
    JOINING_GROUP_BURUSHASKI_YEH_BARREE,
    JOINING_GROUP_AFRICAN_FEH,
    JOINING_GROUP_AFRICAN_QAF,
    JOINING_GROUP_AFRICAN_NOON,

    /* Syriac */
    JOINING_GROUP_ALAPH,
    JOINING_GROUP_BETH,
    JOINING_GROUP_GAMAL,
    JOINING_GROUP_DALATH_RISH,
    JOINING_GROUP_HE,
    JOINING_GROUP_SYRIAC_WAW,
    JOINING_GROUP_ZAIN,
    JOINING_GROUP_HETH,
    JOINING_GROUP_TETH,
    JOINING_GROUP_YUDH,
    JOINING_GROUP_YUDH_HE,
    JOINING_GROUP_KAPH,
    JOINING_GROUP_LAMADH,
    JOINING_GROUP_MIM,
    JOINING_GROUP_NUN,
    JOINING_GROUP_SEMKATH,
    JOINING_GROUP_FINAL_SEMKATH,
    JOINING_GROUP_E,
    JOINING_GROUP_PE,
    JOINING_GROUP_REVERSED_PE,
    JOINING_GROUP_SADHE,
    JOINING_GROUP_QAPH,
    JOINING_GROUP_SHIN,
    JOINING_GROUP_TAW,
    JOINING_GROUP_ZHAIN,
    JOINING_GROUP_KHAPH,
    JOINING_GROUP_FE,

    /* Malayalam */
    JOINING_GROUP_MALAYALAM_NGA,
    JOINING_GROUP_MALAYALAM_JA,
    JOINING_GROUP_MALAYALAM_NYA,
    JOINING_GROUP_MALAYALAM_TTA,
    JOINING_GROUP_MALAYALAM_NNA,
    JOINING_GROUP_MALAYALAM_NNNA,
    JOINING_GROUP_MALAYALAM_BHA,
    JOINING_GROUP_MALAYALAM_RA,
    JOINING_GROUP_MALAYALAM_LLA,
    JOINING_GROUP_MALAYALAM_LLLA,
    JOINING_GROUP_MALAYALAM_SSA,

    /* Manichaean */
    JOINING_GROUP_MANICHAEAN_ALEPH,
    JOINING_GROUP_MANICHAEAN_BETH,
    JOINING_GROUP_MANICHAEAN_GIMEL,
    JOINING_GROUP_MANICHAEAN_DALETH,
    JOINING_GROUP_MANICHAEAN_WAW,
    JOINING_GROUP_MANICHAEAN_ZAYIN,
    JOINING_GROUP_MANICHAEAN_HETH,
    JOINING_GROUP_MANICHAEAN_TETH,
    JOINING_GROUP_MANICHAEAN_YODH,
    JOINING_GROUP_MANICHAEAN_KAPH,
    JOINING_GROUP_MANICHAEAN_LAMEDH,
    JOINING_GROUP_MANICHAEAN_DHAMEDH,
    JOINING_GROUP_MANICHAEAN_THAMEDH,
    JOINING_GROUP_MANICHAEAN_MEM,
    JOINING_GROUP_MANICHAEAN_NUN,
    JOINING_GROUP_MANICHAEAN_SAMEKH,
    JOINING_GROUP_MANICHAEAN_AYIN,
    JOINING_GROUP_MANICHAEAN_PE,
    JOINING_GROUP_MANICHAEAN_SADHE,
    JOINING_GROUP_MANICHAEAN_QOPH,
    JOINING_GROUP_MANICHAEAN_RESH,
    JOINING_GROUP_MANICHAEAN_TAW,
    JOINING_GROUP_MANICHAEAN_ONE,
    JOINING_GROUP_MANICHAEAN_FIVE,
    JOINING_GROUP_MANICHAEAN_TEN,
    JOINING_GROUP_MANICHAEAN_TWENTY,
    JOINING_GROUP_MANICHAEAN_HUNDRED,

    /* Rohingya */
    JOINING_GROUP_HANIFI_ROHINGYA_PA,
    JOINING_GROUP_HANIFI_ROHINGYA_KINNA_YA,

} hz_arabic_joining_group_t;

typedef struct hz_arabic_joining_entry_t {
    hz_unicode_t codepoint;
    const char *name;
    uint16_t joining;
} hz_arabic_joining_entry_t;

#include "hz-ot-shape-complex-arabic-joining-list.h"

hz_bool
hz_ot_shape_complex_arabic_join(hz_feature_t feature, hz_sequence_node_t *node);

#endif /* HZ_OT_SHAPE_COMPLEX_ARABIC_H */
