#ifndef DIGITAL_OUTPUTS_H
#define DIGITAL_OUTPUTS_H

#include "module/base.h"

//! Перечисление возможных бит управления.
enum _E_Digital_Outputs_Control {
    DIGITAL_OUTPUTS_CONTROL_NONE = CONTROL_NONE,
};

//! Перечисление возможных бит статуса.
enum _E_Digital_Outputs_Status {
    DIGITAL_OUTPUTS_STATUS_NONE = STATUS_NONE,
};

#define DIGITAL_OUTPUTS_OUT_COUNT 32

typedef reg_u8_t digital_outputs_data_in_t;
typedef reg_u8_t digital_outputs_data_out_t;
typedef reg_u8_t digital_outputs_param_in_sel_t;
typedef reg_u8_t digital_outputs_param_out_inv_t;
typedef union_u16_t digital_outputs_internal_data_t;

//! Предварительная декларация типа модуля.
typedef struct _S_Digital_Outputs M_digital_outputs;

//! Структура модуля.
struct _S_Digital_Outputs {
    // Базовые поля.
    control_t control; //!< Слово управления.
    status_t status; //!< Слово состояния.
    // Входные данные.
    digital_outputs_data_in_t d_warning;
    digital_outputs_data_in_t d_error;
    // Выходные данные.
    digital_outputs_data_out_t d_out[DIGITAL_OUTPUTS_OUT_COUNT];
    // Параметры.
    digital_outputs_param_in_sel_t p_sel_warning;
    digital_outputs_param_in_sel_t p_sel_error;
    digital_outputs_param_out_inv_t p_inv_out[DIGITAL_OUTPUTS_OUT_COUNT];
    // Регистры.
    // Методы.
    METHOD_INIT(M_digital_outputs);
    METHOD_DEINIT(M_digital_outputs);
    METHOD_CALC(M_digital_outputs);
    // Коллбэки.
    // Внутренние данные.
    digital_outputs_internal_data_t internal_out[DIGITAL_OUTPUTS_OUT_COUNT];
};

EXTERN METHOD_INIT_PROTO(M_digital_outputs);
EXTERN METHOD_DEINIT_PROTO(M_digital_outputs);
EXTERN METHOD_CALC_PROTO(M_digital_outputs);

#define DIGITAL_OUTPUTS_DEFAULTS {\
        /* Базовые поля */\
        0, /* control */\
        0, /* status */\
        /* Входные данные */\
		0, /* d_warning */\
		0, /* d_error */\
        /* Выходные данные */\
		{0}, /* d_out */\
        /* Параметры */\
		0, /* p_sel_warning */\
		1, /* p_sel_error */\
		{0}, /* p_inv_out */\
        /* Регистры */\
        /* Методы */\
        METHOD_INIT_PTR(M_digital_outputs),\
        METHOD_DEINIT_PTR(M_digital_outputs),\
        METHOD_CALC_PTR(M_digital_outputs),\
        /* Коллбэки */\
        /* Внутренние данные */\
		{{0}}, /* internal_out */\
    }

#endif /* DIGITAL_OUTPUTS_H */
