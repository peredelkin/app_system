#ifndef MODULES_H
#define MODULES_H


#include "conf/conf.h"
#include "sys_main/sys_main.h"
#include "sys_timer/sys_timer.h"
#include "ms_timer/ms_timer.h"
#include "data_log/data_log.h"
#include "fake_tic12400/fake_tic12400.h"
#include "digital_inputs/digital_inputs.h"
#include "digital_outputs/digital_outputs.h"
#include "logical_and/logical_and.h"
#include "blink/blink.h"

extern M_conf conf;
extern M_sys_main sys;
extern M_sys_timer sys_tim;
extern M_ms_timer ms_tim;
extern M_data_log dlog;

extern M_fake_tic12400 fake_tic12400;
extern M_digital_inputs digital_inputs;
extern M_digital_outputs digital_outputs;
extern M_blink blink;

#endif /* MODULES_H */
