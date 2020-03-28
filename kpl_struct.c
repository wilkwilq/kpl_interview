/**
 * @kpl_struct.c
 * @author Marcin Wilk 
 * @date 28.03.2020 
 * @brief File containing functions for interview 
 */

/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */

#include <kpl_struct.h>
#include "stdint.h"
#include "stddef.h"

/* ==================================================================== */
/* ======================== global variables ========================== */
/* ==================================================================== */

/* ==================================================================== */
/* ==================== function prototypes =========================== */
/* ==================================================================== */

kpl_struct_t* Add(kpl_struct_t* kpl_struct, int32_t start, int32_t end){
    if (NULL == kpl_struct)
        return NULL;

    if (start < kpl_struct->start) {
        kpl_struct->start = start;
    }
    if (end > kpl_struct->end && start <= kpl_struct->end) {
        kpl_struct->end = end;
    }

    return kpl_struct;
}
