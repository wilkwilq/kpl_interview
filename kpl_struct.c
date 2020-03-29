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
    kpl_struct_t* new_struct;
    kpl_struct_t* output;
    kpl_struct_t* temp;

    if (NULL == kpl_struct)
        return NULL;

    if (end < kpl_struct->start) {
	new_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
	new_struct->start = start;
	new_struct->end = end;
	new_struct->next = kpl_struct;
	new_struct->prev = NULL;
	kpl_struct->prev = new_struct;
	return new_struct;
    }

    if (start > kpl_struct->end && kpl_struct->next == NULL) {
	new_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
	new_struct->start = start;
	new_struct->end = end;
	new_struct->next = NULL;
	new_struct->prev = kpl_struct;
	kpl_struct->next = new_struct;
	return kpl_struct;
    } else if (start > kpl_struct->end) {
	output = Add(kpl_struct->next, start, end);
	return output->prev; 
    }

    if (start < kpl_struct->start) {
        kpl_struct->start = start;
    }

    if (end > kpl_struct->end && kpl_struct->next == NULL) {
	kpl_struct->end = end;
    } else if (end > kpl_struct->end) {
        temp = kpl_struct->next;
        while(temp->next != NULL && end > temp->end) {
            temp->prev->next = temp->next;
            output = temp;
            temp = temp->next;
            free(output);
        };
        if (end > temp->end) {
            kpl_struct->end = end;
            if (temp->next != NULL) {
    	        kpl_struct->next = temp->next;
    	        free(temp);
    	    } else {
                free(temp);
    	    }
        } else {
           kpl_struct->end = temp->end;
           if (temp->next != NULL) {
    	       kpl_struct->next = temp->next;
    	       free(temp);
    	   } else {
               free(temp);
    	   }
        }       
    }
    
    return kpl_struct;
}
