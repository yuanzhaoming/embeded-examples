#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "usmart.h"
/************************************************
************************************************/

extern unsigned char BMP1[];
int main(void)
{
	int i = 0;
	u8 key;
	u8 t;
	HAL_Init();                     //初始化HAL库   
	Stm32_Clock_Init(360,25,2,8);   //设置时钟,180Mhz
	delay_init(180);                //初始化延时函数
	uart_init(115200);              //初始化USART	 
	usmart_dev.init(90); 		    //初始化USMART	
	LED_Init();                     //初始化LED 

	
	IIC_Init();
	OLED_Init();
	OLED_ShowStr(90,1,"yuan",1); 
	
	for(i=0;i<4;i++) 
	{ 
		OLED_ShowCN(10+i*16,0,i);  
	}
	
	OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP1);
	while(1){
		
	}
}
