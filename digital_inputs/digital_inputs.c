#include "digital_inputs.h"


METHOD_INIT_IMPL(M_digital_inputs, digital_inputs)
{
}

METHOD_DEINIT_IMPL(M_digital_inputs, digital_inputs)
{
}


digital_inputs_data_out_t digital_inputs_out_state_write(M_digital_inputs *digital_inputs, digital_inputs_param_out_sel_t sel,
		digital_inputs_param_out_inv_t inv) {
	return (digital_inputs_data_out_t) (digital_inputs->internal_in[sel].u8[inv]);
}

METHOD_CALC_IMPL(M_digital_inputs, digital_inputs) {
	for (int n = 0; n < DIGITAL_INPUTS_IN_COUNT; n++) {
		digital_inputs->internal_in[n].u16 =
				(digital_inputs->d_in[n]) ? UNION_U16_STATE_TRUE : UNION_U16_STATE_FALSE;
	}

	digital_inputs->d_out_start = digital_inputs_out_state_write(digital_inputs, digital_inputs->p_sel_start,
			digital_inputs->p_inv_start);
	digital_inputs->d_out_stop = digital_inputs_out_state_write(digital_inputs, digital_inputs->p_sel_stop,
			digital_inputs->p_inv_stop);

}
