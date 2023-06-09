#include "digital_outputs.h"


METHOD_INIT_IMPL(M_digital_outputs, digital_outputs)
{
}

METHOD_DEINIT_IMPL(M_digital_outputs, digital_outputs)
{
}

METHOD_CALC_IMPL(M_digital_outputs, digital_outputs)
{
	digital_outputs->internal_out[digital_outputs->p_sel_warning].u16 =
			(digital_outputs->d_warning) ? UNION_U16_STATE_TRUE : UNION_U16_STATE_FALSE;

	digital_outputs->internal_out[digital_outputs->p_sel_error].u16 =
				(digital_outputs->d_error) ? UNION_U16_STATE_TRUE : UNION_U16_STATE_FALSE;

	for(int n = 0; n < DIGITAL_OUTPUTS_OUT_COUNT; n++) {
		digital_outputs->d_out[n] = digital_outputs->internal_out[n].u8[digital_outputs->p_inv_out[n]];
	}
}
