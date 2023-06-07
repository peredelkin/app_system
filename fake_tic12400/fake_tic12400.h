#ifndef FAKE_TIC12400_H
#define FAKE_TIC12400_H

#include "module/base.h"
#include "tic12400/tic12400_reg.h"

//! Перечисление возможных бит управления.
enum _E_fake_tic12400_Control {
    FAKE_TIC12400_CONTROL_NONE = CONTROL_NONE,
};

//! Перечисление возможных бит статуса.
enum _E_fake_tic12400_Status {
    FAKE_TIC12400_STATUS_NONE = STATUS_NONE,
};

#define TIC12400_DI_COUNT 24
#define TIC12400_AI_COUNT 26

typedef union_u16_t tic12400_di_state_t;
typedef reg_u16_t tic12400_ai_state_t;

typedef struct {
	TIC12400_INT_STAT_REG INT_STAT;
	TIC12400_IN_STAT_COMP_REG IN_STAT_COMP;
	TIC12400_ANA_STAT_REG ANA_STAT1;
	TIC12400_ANA_STAT_REG ANA_STAT2;
	TIC12400_ANA_STAT_REG ANA_STAT3;
	TIC12400_ANA_STAT_REG ANA_STAT9;
	TIC12400_ANA_STAT_REG ANA_STAT12;
} tic12400_data_t;

//! Предварительная декларация типа модуля.
typedef struct _S_Fake_Tic12400 M_fake_tic12400;

//! Структура модуля.
struct _S_Fake_Tic12400 {
    // Базовые поля.
    control_t control; //!< Слово управления.
    status_t status; //!< Слово состояния.
    // Входные данные.
    // Выходные данные.
    tic12400_di_state_t out_di[TIC12400_DI_COUNT];
    tic12400_ai_state_t out_ai[TIC12400_AI_COUNT];
    // Параметры.
    // Регистры.
    // Методы.
    METHOD_INIT(M_fake_tic12400);
    METHOD_DEINIT(M_fake_tic12400);
    METHOD_CALC(M_fake_tic12400);
    // Коллбэки.
    // Внутренние данные.
    tic12400_data_t data;
};

EXTERN METHOD_INIT_PROTO(M_fake_tic12400);
EXTERN METHOD_DEINIT_PROTO(M_fake_tic12400);
EXTERN METHOD_CALC_PROTO(M_fake_tic12400);

#define FAKE_TIC12400_DEFAULTS {\
        /* Базовые поля */\
        0,/* control */\
		0,/* status */\
        /* Входные данные */\
        /* Выходные данные */\
		{{0}},/* out_di */\
		{0},/* out_ai */\
        /* Параметры */\
        /* Регистры */\
        /* Методы */\
        METHOD_INIT_PTR(M_fake_tic12400),\
		METHOD_DEINIT_PTR(M_fake_tic12400),\
        METHOD_CALC_PTR(M_fake_tic12400),\
        /* Коллбэки */\
        /* Внутренние данные */\
		{{0}}/* data */\
    }

#endif /* FAKE_TIC12400_H */
