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


/*----------------------counter BCD------------------------
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


*/


#include "system.h"
#include <stdio.h>
#include "sys/alt_irq.h"
#include "altera_avalon_pio_regs.h"
#include "altera_avalon_timer_regs.h"

int i=0,j=0,k=0;

static void timer_interrupts(void)
{
	if (k<9){
		k++;
	}
	else{
		k=0;
		if(j<9){
			j++;
		}
		else{
			j=0;
			if (i<9){
				i++;
			}
			else{
				i=0;
			}
		}
	}
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,i<<8|j<<4|k);
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);
}


int main(void){

    IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);    // Clear IRQ status
    // Register the ISR for timer event
    alt_ic_isr_register(TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID,TIMER_0_IRQ, timer_interrupts, NULL, 0);
    // Start timer
    IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0x0007);
	
	
	while(1){}
	return 0;
}