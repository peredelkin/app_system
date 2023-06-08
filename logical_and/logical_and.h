#ifndef LOGICAL_AND_H
#define LOGICAL_AND_H

#include "module/base.h"

//! Перечисление возможных бит управления.
enum _E_Logical_And_Control {
    LOGICAL_AND_CONTROL_NONE = CONTROL_NONE,
};

//! Перечисление возможных бит статуса.
enum _E_Logical_And_Status {
    LOGICAL_AND_STATUS_NONE = STATUS_NONE,
};

#define LOGICAL_AND_IN_COUNT 4

typedef union_u16_t logical_and_data_out_t;
typedef reg_u16_t logical_and_internal_counter_t;
typedef reg_u8_t logical_and_internal_data_t;

typedef struct _S_Logical_And_Param {
	reg_u16_t enabled;
	reg_id_t reg_id;
} logical_and_param_t;

//! Предварительная декларация типа модуля.
typedef struct _S_Logical_And M_logical_and;

//! Структура модуля.
struct _S_Logical_And {
    // Базовые поля.
    control_t control; //!< Слово управления.
    status_t status; //!< Слово состояния.
    // Входные данные.
    // Выходные данные.
    logical_and_data_out_t out;
    // Параметры.
    logical_and_param_t p_in[LOGICAL_AND_IN_COUNT];
    // Регистры.
    // Методы.
    METHOD_INIT(M_logical_and);
    METHOD_DEINIT(M_logical_and);
    METHOD_CALC(M_logical_and);
    METHOD_IDLE(M_logical_and);
    // Коллбэки.
    // Внутренние данные.
    logical_and_internal_counter_t en_counter;
    logical_and_internal_data_t data[LOGICAL_AND_IN_COUNT];
    reg_t* reg[LOGICAL_AND_IN_COUNT];
};

EXTERN METHOD_INIT_PROTO(M_logical_and);
EXTERN METHOD_DEINIT_PROTO(M_logical_and);
EXTERN METHOD_CALC_PROTO(M_logical_and);
EXTERN METHOD_IDLE_PROTO(M_logical_and);

#define LOGICAL_AND_DEFAULTS {\
        /* Базовые поля */\
        0, /* control */\
        0, /* status */\
        /* Входные данные */\
        /* Выходные данные */\
		{0}, /* out */\
        /* Параметры */\
		{{0}}, /* p_in */\
        /* Регистры */\
        /* Методы */\
        METHOD_INIT_PTR(M_logical_and),\
        METHOD_DEINIT_PTR(M_logical_and),\
        METHOD_CALC_PTR(M_logical_and),\
		METHOD_IDLE_PTR(M_logical_and),\
        /* Коллбэки */\
        /* Внутренние данные */\
		0, /* en_counter */\
		{0}, /* counter */\
		{0}, /* internal_reg */\
    }

#endif /* LOGICAL_AND_H */
