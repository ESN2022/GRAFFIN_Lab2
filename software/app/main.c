#include "system.h"
#include "unistd.h"
#include "altera_avalon_pio_regs.h"


int main(void){
	int i=0;
	while(1){
		for (i=0;i<10;i++){
			IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,i);
			usleep(200000);
		}
	}
	return 0;
}


