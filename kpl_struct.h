/**
 * @kpl_struct.h
 * @author Marcin Wilk 
 * @date 28.03.2020 
 * @brief File containing functions for interview 
 */

#ifndef _KPL_STRUCT_H
#define _KPL_STRUCT_H

/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */

#include <kpl_struct.h>
#include "stdint.h"

/* ==================================================================== */
/* ============================ constants ============================= */
/* ==================================================================== */

/* ==================================================================== */
/* ============================== data ================================ */
/* ==================================================================== */

typedef struct kpl_struct_t kpl_struct_t;

struct kpl_struct_t {
    int32_t start;
    int32_t end;
    kpl_struct_t* prev;
    kpl_struct_t* next;
};

/* ==================================================================== */
/* ====================== function declarations ======================= */
/* ==================================================================== */
kpl_struct_t* Add(kpl_struct_t* kpl_struct, int32_t start, int32_t end);
kpl_struct_t* Delete(kpl_struct_t* kpl_struct, int32_t start, int32_t end); 
kpl_struct_t* Get(kpl_struct_t* kpl_struct, int32_t start, int32_t end);

#endif /* _KPL_STRUCT_H */
