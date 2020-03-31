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
static kpl_struct_t* DeleteRangeFromTheMiddle(kpl_struct_t* kpl_struct, int32_t start, int32_t end);
static kpl_struct_t* DeleteWholeRange(kpl_struct_t* kpl_struct);
static kpl_struct_t* CreateNewKplStructAfterOrFirstIf(kpl_struct_t* kpl_struct, int32_t start, int32_t end); 

/* ==================================================================== */
/* ==================== function prototypes =========================== */
/* ==================================================================== */

kpl_struct_t* Add(kpl_struct_t* kpl_struct, int32_t start, int32_t end) {
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

kpl_struct_t* Delete(kpl_struct_t* kpl_struct, int32_t start, int32_t end) {
    kpl_struct_t* temp_kpl_struct;
    
    if (NULL == kpl_struct) {
        return NULL;
    }

    temp_kpl_struct = kpl_struct;
    while (temp_kpl_struct != NULL) { 
        if (start < temp_kpl_struct->end && start > temp_kpl_struct->start && end > temp_kpl_struct->end) {
            temp_kpl_struct->end = start;
        }
        if (end < temp_kpl_struct->end && end > temp_kpl_struct->start && start < temp_kpl_struct->start) {
            temp_kpl_struct->start = end;
        }
        if (start > temp_kpl_struct->start && end < temp_kpl_struct->end) {
            DeleteRangeFromTheMiddle(temp_kpl_struct, start, end); 
        }
	if (start <= temp_kpl_struct->start && end >= temp_kpl_struct->end) {
            temp_kpl_struct = DeleteWholeRange(temp_kpl_struct); 
	    continue;
	}
	temp_kpl_struct = temp_kpl_struct->next;
    }
    return kpl_struct;
}

kpl_struct_t* Get(kpl_struct_t* kpl_struct, int32_t start, int32_t end) {
    kpl_struct_t* return_kpl_struct = NULL;
    kpl_struct_t* temp_kpl_struct;
    
    if (NULL == kpl_struct) {
	return NULL;
    }

    temp_kpl_struct = kpl_struct;
    while (temp_kpl_struct != NULL) { 
	if (start >= temp_kpl_struct->start && start < temp_kpl_struct->end ||
	    end > temp_kpl_struct->start && end < temp_kpl_struct->end || 
	    start < temp_kpl_struct->start && end >= temp_kpl_struct->end) {

                return_kpl_struct = CreateNewKplStructAfter(return_kpl_struct, temp_kpl_struct->start, temp_kpl_struct->end);
		if (return_kpl_struct->next != NULL) {
                    return_kpl_struct = return_kpl_struct->next;
		}	
	}
	temp_kpl_struct = temp_kpl_struct->next;
    }
    while(return_kpl_struct->prev != NULL) {
	return_kpl_struct = return_kpl_struct->prev;
    }
    return return_kpl_struct;
}

static kpl_struct_t* CreateNewKplStruct(int32_t start, int32_t end) {
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

    if (NULL == kpl_struct) {
        return CreateNewKplStruct(start, end);
    }
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

    if (NULL == kpl_struct) {
        return CreateNewKplStruct(start, end);
    }
    new_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    new_struct->start = start;
    new_struct->end = end;
    new_struct->next = NULL;
    new_struct->prev = kpl_struct;
    kpl_struct->next = new_struct;

    return kpl_struct;
} 

static kpl_struct_t* UpdateKplStructEndAndMergeIfNeeded(kpl_struct_t* kpl_struct, int32_t end) {
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

static kpl_struct_t* DeleteRangeFromTheMiddle(kpl_struct_t* kpl_struct, int32_t start, int32_t end) {
    kpl_struct_t* new_struct;

    new_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    if (kpl_struct->next != NULL) {
        new_struct->next = kpl_struct->next;
    } else {
        new_struct->next = NULL;
    }
    new_struct->prev = kpl_struct;	
    new_struct->start = end;
    new_struct->end = kpl_struct->end; 
    kpl_struct->end = start;
    kpl_struct->next = new_struct;

    return kpl_struct;
}

static kpl_struct_t* DeleteWholeRange(kpl_struct_t* kpl_struct) {
    kpl_struct_t* temp_kpl_struct;

    if (kpl_struct->prev != NULL && kpl_struct->next != NULL) {
        kpl_struct->prev->next = kpl_struct->next;
        kpl_struct->next->prev = kpl_struct->prev;
    } else if (kpl_struct->next != NULL) {
        kpl_struct->next->prev = NULL;
    }
    temp_kpl_struct = kpl_struct;
    kpl_struct = kpl_struct->next;
    free(temp_kpl_struct);

    return kpl_struct;
}
