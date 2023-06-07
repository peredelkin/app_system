/*
 * union.h
 *
 *  Created on: 7 июн. 2023 г.
 *      Author: Ruslan
 */

#ifndef UNION_UNION_H_
#define UNION_UNION_H_

#include "reg/reg_types.h"

enum _Union_U16_State {
	UNION_U16_STATE_NONE = 0,
	UNION_U16_STATE_TRUE = 1,
	UNION_U16_STATE_FALSE = (1<<8)
};

typedef union _union_u16 {
	reg_u16_t all;
	reg_u8_t byte[2];
} union_u16_t;

#endif /* UNION_UNION_H_ */
