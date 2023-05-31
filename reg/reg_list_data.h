#ifndef REG_LIST_DATA_H
#define REG_LIST_DATA_H


// THIS FILE IS GENERATED AUTOMATICALLY!
// DO NOT EDIT THIS FILE!

// Modules for registers
#include "modules/modules.h"

// Begin
REGS_BEGIN(REG_ARRAY_NAME)

// Conf
// Nominal values
REG(REG_ID_CONF_U_NOM, conf.p_U_nom, REG_TYPE_IQ15, REG_FLAG_CONF)
REG(REG_ID_CONF_I_NOM, conf.p_I_nom, REG_TYPE_IQ15, REG_FLAG_CONF)


// ADC
// Phases voltage
// Raw
REG(REG_ID_ADC_UA_RAW, adc.out_Ua_raw, REG_TYPE_U32, REG_FLAG_NONE)
REG(REG_ID_ADC_UB_RAW, adc.out_Ub_raw, REG_TYPE_U32, REG_FLAG_NONE)
REG(REG_ID_ADC_UC_RAW, adc.out_Uc_raw, REG_TYPE_U32, REG_FLAG_NONE)
// Rel
REG(REG_ID_ADC_UA, adc.out_Ua, REG_TYPE_IQ24, REG_FLAG_NONE)
REG(REG_ID_ADC_UB, adc.out_Ub, REG_TYPE_IQ24, REG_FLAG_NONE)
REG(REG_ID_ADC_UC, adc.out_Uc, REG_TYPE_IQ24, REG_FLAG_NONE)
// Calibration
REG(REG_ID_ADC_UA_GAIN, adc.p_Ua_gain, REG_TYPE_IQ24, REG_FLAG_CONF)
REG(REG_ID_ADC_UA_OFFSET, adc.p_Ua_offset, REG_TYPE_U32, REG_FLAG_CONF)
REG(REG_ID_ADC_UB_GAIN, adc.p_Ub_gain, REG_TYPE_IQ24, REG_FLAG_CONF)
REG(REG_ID_ADC_UB_OFFSET, adc.p_Ub_offset, REG_TYPE_U32, REG_FLAG_CONF)
REG(REG_ID_ADC_UC_GAIN, adc.p_Uc_gain, REG_TYPE_IQ24, REG_FLAG_CONF)
REG(REG_ID_ADC_UC_OFFSET, adc.p_Uc_offset, REG_TYPE_U32, REG_FLAG_CONF)

// Phase and Amplitude.
REG(REG_ID_PHASE_AMPL_UA_PHASE, Ua_phase_ampl.out_phase, REG_TYPE_IQ24, REG_FLAG_NONE)
REG(REG_ID_PHASE_AMPL_UA_AMPL, Ua_phase_ampl.out_ampl, REG_TYPE_IQ24, REG_FLAG_NONE)
REG(REG_ID_PHASE_AMPL_UB_PHASE, Ub_phase_ampl.out_phase, REG_TYPE_IQ24, REG_FLAG_NONE)
REG(REG_ID_PHASE_AMPL_UB_AMPL, Ub_phase_ampl.out_ampl, REG_TYPE_IQ24, REG_FLAG_NONE)
REG(REG_ID_PHASE_AMPL_UC_PHASE, Uc_phase_ampl.out_phase, REG_TYPE_IQ24, REG_FLAG_NONE)
REG(REG_ID_PHASE_AMPL_UC_AMPL, Uc_phase_ampl.out_ampl, REG_TYPE_IQ24, REG_FLAG_NONE)

REG(REG_ID_RMS_UA, Ua_rms.out_value, REG_TYPE_IQ24, REG_FLAG_NONE)
REG(REG_ID_RMS_UB, Ub_rms.out_value, REG_TYPE_IQ24, REG_FLAG_NONE)
REG(REG_ID_RMS_UC, Uc_rms.out_value, REG_TYPE_IQ24, REG_FLAG_NONE)


// End
REGS_END()

#define REGS_COUNT REGS_COUNT_VALUE(REG_ARRAY_NAME)

#endif /* REG_LIST_DATA_H */
