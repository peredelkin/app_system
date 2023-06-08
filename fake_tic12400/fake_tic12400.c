#include "fake_tic12400/fake_tic12400.h"
#include "modules/modules.h"


METHOD_INIT_IMPL(M_fake_tic12400, fake_tic12400)
{
}

METHOD_DEINIT_IMPL(M_fake_tic12400, fake_tic12400)
{
}

static void gen_fake_tic_data(M_fake_tic12400* fake_tic12400)
{
	if(sys_tim.out_counter == 20){
		fake_tic12400->regs_data.IN_STAT_COMP.bit.inc_8 = 1;
	}
	if(sys_tim.out_counter == 10){
		fake_tic12400->regs_data.IN_STAT_COMP.bit.inc_9 = 1;
	}
	if(sys_tim.out_counter == 30){
		fake_tic12400->regs_data.IN_STAT_COMP.bit.inc_9 = 0;
	}
	if(sys_tim.out_counter == 40){
		fake_tic12400->regs_data.IN_STAT_COMP.bit.inc_8 = 0;
	}
	if(sys_tim.out_counter == 50){
		fake_tic12400->regs_data.IN_STAT_COMP.bit.inc_9 = 1;
	}
	if(sys_tim.out_counter == 60){
		fake_tic12400->regs_data.IN_STAT_COMP.bit.inc_8 = 1;
	}

}

METHOD_CALC_IMPL(M_fake_tic12400, fake_tic12400) {
	gen_fake_tic_data(fake_tic12400);

	for (int n = 0; n < TIC12400_DI_COUNT; n++) {
		fake_tic12400->out_di[n] = (fake_tic12400->regs_data.IN_STAT_COMP.all & (1 << n)) ? 1 : 0;
	}
}
