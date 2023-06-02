#ifndef BLINK_H
#define BLINK_H

#include "module/base.h"

//! Перечисление возможных бит управления.
enum _E_Blink_Control {
    BLINK_CONTROL_NONE = CONTROL_NONE,
};

//! Перечисление возможных бит статуса.
enum _E_Blink_Status {
    BLINK_STATUS_NONE = STATUS_NONE,
};

//! Предварительная декларация типа модуля.
typedef struct _S_Blink M_blink;

//! Структура модуля.
struct _S_Blink {
    // Базовые поля.
    control_t control; //!< Слово управления.
    status_t status; //!< Слово состояния.
    // Входные данные.
    // Выходные данные.
    reg_u32_t out_value;
    // Параметры.
    // Регистры.
    // Методы.
    METHOD_INIT(M_blink);
    METHOD_DEINIT(M_blink);
    METHOD_CALC(M_blink);
    // Коллбэки.
    // Внутренние данные.
};

EXTERN METHOD_INIT_PROTO(M_blink);
EXTERN METHOD_DEINIT_PROTO(M_blink);
EXTERN METHOD_CALC_PROTO(M_blink);

#define BLINK_DEFAULTS {\
        /* Базовые поля */\
        0, 0, /* control, status */\
        /* Входные данные */\
        /* Выходные данные */\
		0, /* out_value */\
        /* Параметры */\
        /* Регистры */\
        /* Методы */\
        METHOD_INIT_PTR(M_blink), METHOD_DEINIT_PTR(M_blink),\
        METHOD_CALC_PTR(M_blink),\
        /* Коллбэки */\
        /* Внутренние данные */\
    }

#endif /* BLINK_H */
