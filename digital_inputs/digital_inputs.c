#include "digital_inputs.h"


METHOD_INIT_IMPL(M_digital_inputs, digital_inputs)
{
}

METHOD_DEINIT_IMPL(M_digital_inputs, digital_inputs)
{
}

digital_inputs_out_state_t digital_inputs_out_state_write(M_digital_inputs *digital_inputs, digital_inputs_out_sel_t sel,
		digital_inputs_out_inv_t inv) {
	return (digital_inputs_out_state_t) (digital_inputs->in_di[sel].byte[inv]);
}

METHOD_CALC_IMPL(M_digital_inputs, digital_inputs) {
	digital_inputs->out_start = digital_inputs_out_state_read(digital_inputs, digital_inputs->sel_start,
			digital_inputs->inv_start);
	digital_inputs->out_stop = digital_inputs_out_state_read(digital_inputs, digital_inputs->sel_stop,
				digital_inputs->inv_stop);
}
