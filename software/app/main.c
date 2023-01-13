/*------------------counter 1 segment--------------------------

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


*/

#include "system.h"
#include "unistd.h"
#include "altera_avalon_pio_regs.h"


int main(void){
	int i=0,j=0,k=0;
	while(1){
		for (i=0;i<10;i++){
			for (j=0;j<10;j++){
				for (k=0;k<10;k++){
					IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,i<<8|j<<4|k);
					usleep(100000);
				}
			}
		}
	}
	return 0;
}