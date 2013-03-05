#include <LPC17xx.H>
// do some include here
#include <lpc17xx_gpio.h>


// do some defines here
#define PORT0	0
#define PORT1 1
#define PORT2 2
#define PORT3 3

#define LED  (1<<29)

#define ENABLE_OUTPUT  1
#define ENABLE_INPUT   0
#define TRUE  1
#define FALSE 0
#define MAX_TIME_TRIGGER 10

uint32_t bLEDStatus;

void SysTick_Handler(){
	if(bLEDStatus){  
		/* If LED is on, switch it off*/
		GPIO_ClearValue(PORT1, LED);
		bLEDStatus = FALSE;  /* Set the status of led*/
	} else {
		/* else switch it on */
		GPIO_SetValue(PORT1, LED);
		bLEDStatus = TRUE;   /* Set the status of led*/
	}
}


int main(void){
	int retCode = 0;  /* Define the variable defining return code */
	
	// Enable output on the following pin
	GPIO_SetDir(PORT1, LED, ENABLE_OUTPUT);
	
	// Clear the Port
	GPIO_ClearValue(PORT1, LED);
	
	// Set Led Status to false
	bLEDStatus = FALSE;
	
	//Configure the trigger time of SysTick_Handler
	retCode = SysTick_Config(SystemCoreClock/MAX_TIME_TRIGGER);  /*SystemCoreClock -- global variable which contains clock speed*/
	//if it could not be defined plung process
	if (retCode != 0){
		// Handle Error ..
	}
	while(1);
}
