#ifndef DIGITAL_INPUTS_H
#define DIGITAL_INPUTS_H

#include "module/base.h"

//! Перечисление возможных бит управления.
enum _E_Digital_Inputs_Control {
    DIGITAL_INPUTS_CONTROL_NONE = CONTROL_NONE,
};

//! Перечисление возможных бит статуса.
enum _E_Digital_Inputs_Status {
    DIGITAL_INPUTS_STATUS_NONE = STATUS_NONE,
};

#define DIGITAL_INPUTS_IN_COUNT 32

typedef reg_u8_t digital_inputs_data_in_t;
typedef reg_u8_t digital_inputs_data_out_t;
typedef reg_u8_t digital_inputs_param_out_sel_t;
typedef reg_u8_t digital_inputs_param_out_inv_t;
typedef union_u16_t digital_inputs_internal_data_t;

//! Предварительная декларация типа модуля.
typedef struct _S_Digital_Inputs M_digital_inputs;

//! Структура модуля.
struct _S_Digital_Inputs {
    // Базовые поля.
    control_t control; //!< Слово управления.
    status_t status; //!< Слово состояния.
    // Входные данные.
    digital_inputs_data_in_t d_in[DIGITAL_INPUTS_IN_COUNT];
    // Выходные данные.
    digital_inputs_data_out_t d_out_start;
    digital_inputs_data_out_t d_out_stop;
    // Параметры.
    digital_inputs_param_out_sel_t p_sel_start;
    digital_inputs_param_out_inv_t p_inv_start;
    digital_inputs_param_out_sel_t p_sel_stop;
    digital_inputs_param_out_inv_t p_inv_stop;
    // Регистры.
    // Методы.
    METHOD_INIT(M_digital_inputs);
    METHOD_DEINIT(M_digital_inputs);
    METHOD_CALC(M_digital_inputs);
    // Коллбэки.
    // Внутренние данные.
    digital_inputs_internal_data_t internal_in[DIGITAL_INPUTS_IN_COUNT];
};

EXTERN METHOD_INIT_PROTO(M_digital_inputs);
EXTERN METHOD_DEINIT_PROTO(M_digital_inputs);
EXTERN METHOD_CALC_PROTO(M_digital_inputs);

#define DIGITAL_INPUTS_DEFAULTS {\
        /* Базовые поля */\
        0, /* control */\
        0, /* status */\
        /* Входные данные */\
		{0},/* in_di */\
        /* Выходные данные */\
		0, /* out_start */\
		0, /* out_stop */\
        /* Параметры */\
		8, /* sel_start */\
		0, /* inv_start */\
		9, /* sel_stop */\
		0, /* inv_stop */\
        /* Регистры */\
        /* Методы */\
        METHOD_INIT_PTR(M_digital_inputs),\
        METHOD_DEINIT_PTR(M_digital_inputs),\
        METHOD_CALC_PTR(M_digital_inputs),\
        /* Коллбэки */\
        /* Внутренние данные */\
		{{0}}, /*internal_in_di*/\
    }

#endif /* DIGITAL_INPUTS_H */
