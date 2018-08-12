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
	HAL_Init();                     //��ʼ��HAL��   
	Stm32_Clock_Init(360,25,2,8);   //����ʱ��,180Mhz
	delay_init(180);                //��ʼ����ʱ����
	uart_init(115200);              //��ʼ��USART	 
	usmart_dev.init(90); 		    //��ʼ��USMART	
	LED_Init();                     //��ʼ��LED 

	
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
