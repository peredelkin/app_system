#include "logical_and.h"

static void recalc_values(M_logical_and *logical_and)
{
	for (int n = 0; n < LOGICAL_AND_IN_COUNT; n++) {
		logical_and->reg[n] = regs_find(logical_and->p_in[n].reg_id);
	}
}

METHOD_INIT_IMPL(M_logical_and, logical_and)
{
	recalc_values(logical_and);
}

METHOD_DEINIT_IMPL(M_logical_and, logical_and)
{
}

METHOD_CALC_IMPL(M_logical_and, logical_and)
{
	logical_and->and_counter = 0;
	logical_and->en_counter = 0;

	for (int n = 0; n < LOGICAL_AND_IN_COUNT; n++) {
		if (logical_and->p_in[n].enabled) {
			if (logical_and->reg[n] != NULL && reg_data(logical_and->reg[n]) != NULL) {
				switch (logical_and->reg[n]->type) {
				case REG_TYPE_I8:
					logical_and->en_counter++;
					if (reg_value(logical_and->reg[n], reg_i8_t))
						logical_and->and_counter++;
					break;
				case REG_TYPE_U8:
					logical_and->en_counter++;
					if (reg_value(logical_and->reg[n], reg_u8_t))
						logical_and->and_counter++;
					break;
				default:
				}
			}
		} else {
			logical_and->and_counter++;
		}
	}

	if (logical_and->en_counter) {
		if (logical_and->and_counter == LOGICAL_AND_IN_COUNT) {
			logical_and->out.u16 = UNION_U16_STATE_TRUE;
		} else {
			logical_and->out.u16 = UNION_U16_STATE_FALSE;
		}
	} else {
		logical_and->out.u16 = UNION_U16_STATE_FALSE;
	}
}

METHOD_IDLE_IMPL(M_logical_and, logical_and) {
	recalc_values(logical_and);
}
