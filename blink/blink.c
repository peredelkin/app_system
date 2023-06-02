#include "blink.h"


METHOD_INIT_IMPL(M_blink, blink)
{
	blink->out_value = 0;
}

METHOD_DEINIT_IMPL(M_blink, blink)
{
}

METHOD_CALC_IMPL(M_blink, blink)
{
	blink->out_value = !blink->out_value;
}
