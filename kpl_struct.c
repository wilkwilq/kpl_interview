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
#include "stdlib.h"

/* ==================================================================== */
/* ==================static function declarations ===================== */
/* ==================================================================== */
static kpl_struct_t* CreateNewKplStruct(int32_t start, int32_t end); 
static kpl_struct_t* CreateNewKplStructBefore(kpl_struct_t* kpl_struct, int32_t start, int32_t end); 
static kpl_struct_t* CreateNewKplStructAfter(kpl_struct_t* kpl_struct, int32_t start, int32_t end); 
static kpl_struct_t* UpdateKplStructEndAndMergeIfNeeded(kpl_struct_t* kpl_struct, int32_t end);

/* ==================================================================== */
/* ==================== function prototypes =========================== */
/* ==================================================================== */

kpl_struct_t* Add(kpl_struct_t* kpl_struct, int32_t start, int32_t end){
    if (NULL == kpl_struct) {
        return CreateNewKplStruct(start, end); 
    }

    if (end < kpl_struct->start) {
        return CreateNewKplStructBefore(kpl_struct, start, end); 
    }

    if (start < kpl_struct->start) {
        kpl_struct->start = start;
    }

    if (start > kpl_struct->end && kpl_struct->next == NULL) {
        return CreateNewKplStructAfter(kpl_struct, start, end); 
    } else if (start > kpl_struct->end) {
	return (Add(kpl_struct->next, start, end))->prev;
    }

    if (end > kpl_struct->end && kpl_struct->next == NULL) {
	kpl_struct->end = end;
    } else if (end > kpl_struct->end) {
        kpl_struct = UpdateKplStructEndAndMergeIfNeeded(kpl_struct, end);
    }
    
    return kpl_struct;
}

static kpl_struct_t* CreateNewKplStruct(int32_t start, int32_t end)
{
    kpl_struct_t* new_struct;

    new_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    new_struct->start = start;
    new_struct->end = end;
    new_struct->next = NULL;
    new_struct->prev = NULL;

    return new_struct;
} 

static kpl_struct_t* CreateNewKplStructBefore(kpl_struct_t* kpl_struct, int32_t start, int32_t end) {
    kpl_struct_t* new_struct;

    new_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    new_struct->start = start;
    new_struct->end = end;
    new_struct->next = kpl_struct;
    new_struct->prev = NULL;
    kpl_struct->prev = new_struct;

    return new_struct;
}

static kpl_struct_t* CreateNewKplStructAfter(kpl_struct_t* kpl_struct, int32_t start, int32_t end) {
    kpl_struct_t* new_struct;

    new_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    new_struct->start = start;
    new_struct->end = end;
    new_struct->next = NULL;
    new_struct->prev = kpl_struct;
    kpl_struct->next = new_struct;

    return kpl_struct;
} 

static kpl_struct_t* UpdateKplStructEndAndMergeIfNeeded(kpl_struct_t* kpl_struct, int32_t end){
    kpl_struct_t* next_kpl_struct;
    kpl_struct_t* temp_kpl_struct;

    next_kpl_struct = kpl_struct->next;
    while(next_kpl_struct->next != NULL && end > next_kpl_struct->end) {
        next_kpl_struct->prev->next = next_kpl_struct->next;
        temp_kpl_struct = next_kpl_struct;
        next_kpl_struct = next_kpl_struct->next;
        free(temp_kpl_struct);
    };
    if (end > next_kpl_struct->end) {
        kpl_struct->end = end;
    } else {
       kpl_struct->end = next_kpl_struct->end;
    }
    if (next_kpl_struct->next != NULL) {
        kpl_struct->next = next_kpl_struct->next;
        free(next_kpl_struct);
    } else {
        kpl_struct->next = NULL;
        free(next_kpl_struct);
    }

    return kpl_struct;
} 
