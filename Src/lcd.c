/*
##########################################################################
## Dosya Ad�		: Character_LCD.c				##
## Yazar		: H�seyin Cemre Y�lmaz				##
## �leti�im		: hcemreyilmaz@gmail.com			##
## S�r�m		: 1.00						##
## 									##
## A��klama		: Bu k�t�phane Karakter LCD �al��malar�nda kul-	##
##			  lan�lmak amac�yla haz�rlanm��t�r. K�t�phaneyi ##
##			  kullanabilmeniz i�in ST HAL K�t�phaneleri kul-##
##			  lan�yor olman�z gerekmektedir.		##
##									##
##			  CubeMX kullanarak olu�turulan projelerde	##
##			  ��k�� pinlerinizin User Label k�s�mlar�n�	##
##			  LCD_RS	LCD_D4		LCD_D6		##
##			  LCD_EN	LCD_D5		LCD_D7		##
##			  �eklinde tan�mlaman�z gerekiyor.		##
##########################################################################
*/

#include "stm32f1xx_hal.h"
#include "main.h"
#include "lcd.h"
	
void LCD_Delay(void)
{
	HAL_Delay(_LCD_DELAY);
}

void lcd_cmd(char out_char)
{
	LCD_RS_GPIO_Port->BRR  = LCD_RS_Pin;
	
	LCD_EN_GPIO_Port->BRR  = LCD_EN_Pin;
	LCD_D4_GPIO_Port->BRR  = LCD_D4_Pin;
	LCD_D5_GPIO_Port->BRR  = LCD_D5_Pin;
	LCD_D6_GPIO_Port->BRR  = LCD_D6_Pin;
	LCD_D7_GPIO_Port->BRR  = LCD_D7_Pin;
	
	LCD_Delay();
	
	LCD_EN_GPIO_Port->ODR |= LCD_EN_Pin;
		
	if((out_char & 0x10)>>4) LCD_D4_GPIO_Port->BSRR = LCD_D4_Pin; else LCD_D4_GPIO_Port->BSRR = (uint32_t)LCD_D4_Pin << 16;
	if((out_char & 0x20)>>5) LCD_D5_GPIO_Port->BSRR = LCD_D5_Pin; else LCD_D5_GPIO_Port->BSRR = (uint32_t)LCD_D5_Pin << 16;
	if((out_char & 0x40)>>6) LCD_D6_GPIO_Port->BSRR = LCD_D6_Pin; else LCD_D6_GPIO_Port->BSRR = (uint32_t)LCD_D6_Pin << 16;
	if((out_char & 0x80)>>7) LCD_D7_GPIO_Port->BSRR = LCD_D7_Pin; else LCD_D7_GPIO_Port->BSRR = (uint32_t)LCD_D7_Pin << 16;
	
	LCD_Delay();
	
	LCD_EN_GPIO_Port->BRR = LCD_EN_Pin;
	LCD_D4_GPIO_Port->BRR = LCD_D4_Pin;
	LCD_D5_GPIO_Port->BRR = LCD_D5_Pin;
	LCD_D6_GPIO_Port->BRR = LCD_D6_Pin;
	LCD_D7_GPIO_Port->BRR = LCD_D7_Pin;
	
	LCD_Delay();
	
	LCD_EN_GPIO_Port->ODR |= LCD_EN_Pin;
	
	if(out_char & 0x01) LCD_D4_GPIO_Port->BSRR = LCD_D4_Pin; else LCD_D4_GPIO_Port->BSRR = (uint32_t)LCD_D4_Pin << 16;
	if((out_char & 0x02)>>1) LCD_D5_GPIO_Port->BSRR = LCD_D5_Pin; else LCD_D5_GPIO_Port->BSRR = (uint32_t)LCD_D5_Pin << 16;
	if((out_char & 0x04)>>2) LCD_D6_GPIO_Port->BSRR = LCD_D6_Pin; else LCD_D6_GPIO_Port->BSRR = (uint32_t)LCD_D6_Pin << 16;
	if((out_char & 0x08)>>3) LCD_D7_GPIO_Port->BSRR = LCD_D7_Pin; else LCD_D7_GPIO_Port->BSRR = (uint32_t)LCD_D7_Pin << 16;

	LCD_Delay();
	
	LCD_EN_GPIO_Port->BRR = LCD_EN_Pin;
	LCD_D4_GPIO_Port->BRR = LCD_D4_Pin;
	LCD_D5_GPIO_Port->BRR = LCD_D5_Pin;
	LCD_D6_GPIO_Port->BRR = LCD_D6_Pin;
	LCD_D7_GPIO_Port->BRR = LCD_D7_Pin;
}

void LCD_Char_CP(char out_char)
{
	LCD_RS_GPIO_Port->ODR |= LCD_RS_Pin;
	
	LCD_EN_GPIO_Port->BRR  = LCD_EN_Pin;
	LCD_D4_GPIO_Port->BRR  = LCD_D4_Pin;
	LCD_D5_GPIO_Port->BRR  = LCD_D5_Pin;
	LCD_D6_GPIO_Port->BRR  = LCD_D6_Pin;
	LCD_D7_GPIO_Port->BRR  = LCD_D7_Pin;
	
	LCD_Delay();
	
	LCD_EN_GPIO_Port->ODR |= LCD_EN_Pin;
		
	if((out_char & 0x10)>>4) LCD_D4_GPIO_Port->BSRR = LCD_D4_Pin; else LCD_D4_GPIO_Port->BSRR = (uint32_t)LCD_D4_Pin << 16;
	if((out_char & 0x20)>>5) LCD_D5_GPIO_Port->BSRR = LCD_D5_Pin; else LCD_D5_GPIO_Port->BSRR = (uint32_t)LCD_D5_Pin << 16;
	if((out_char & 0x40)>>6) LCD_D6_GPIO_Port->BSRR = LCD_D6_Pin; else LCD_D6_GPIO_Port->BSRR = (uint32_t)LCD_D6_Pin << 16;
	if((out_char & 0x80)>>7) LCD_D7_GPIO_Port->BSRR = LCD_D7_Pin; else LCD_D7_GPIO_Port->BSRR = (uint32_t)LCD_D7_Pin << 16;
	
	LCD_Delay();
	
	LCD_EN_GPIO_Port->BRR = LCD_EN_Pin;
	LCD_D4_GPIO_Port->BRR = LCD_D4_Pin;
	LCD_D5_GPIO_Port->BRR = LCD_D5_Pin;
	LCD_D6_GPIO_Port->BRR = LCD_D6_Pin;
	LCD_D7_GPIO_Port->BRR = LCD_D7_Pin;
	
	LCD_Delay();
	
	LCD_EN_GPIO_Port->ODR |= LCD_EN_Pin;
	
	if(out_char & 0x01) LCD_D4_GPIO_Port->BSRR = LCD_D4_Pin; else LCD_D4_GPIO_Port->BSRR = (uint32_t)LCD_D4_Pin << 16;
	if((out_char & 0x02)>>1) LCD_D5_GPIO_Port->BSRR = LCD_D5_Pin; else LCD_D5_GPIO_Port->BSRR = (uint32_t)LCD_D5_Pin << 16;
	if((out_char & 0x04)>>2) LCD_D6_GPIO_Port->BSRR = LCD_D6_Pin; else LCD_D6_GPIO_Port->BSRR = (uint32_t)LCD_D6_Pin << 16;
	if((out_char & 0x08)>>3) LCD_D7_GPIO_Port->BSRR = LCD_D7_Pin; else LCD_D7_GPIO_Port->BSRR = (uint32_t)LCD_D7_Pin << 16;

	LCD_Delay();
	
	LCD_EN_GPIO_Port->BRR = LCD_EN_Pin;
	LCD_D4_GPIO_Port->BRR = LCD_D4_Pin;
	LCD_D5_GPIO_Port->BRR = LCD_D5_Pin;
	LCD_D6_GPIO_Port->BRR = LCD_D6_Pin;
	LCD_D7_GPIO_Port->BRR = LCD_D7_Pin;
}

void LCD_Out_CP(char *out_char)
{
	while(*out_char)
	{
		//LCD_Delay();
		LCD_Char_CP(*out_char++);
	}
	LCD_Delay();
}


//void lcd_init(char bits, char font, char lines)
void lcd_init(void)
{		
	lcd_cmd (0x01);  //ben ekledim
	lcd_cmd (0x02);
	lcd_cmd (0x28);
	lcd_cmd (0x0C);
	lcd_cmd (0x80);

	/*HAL_Delay(250000);
		lcd_cmd(_RETURN_HOME);
    HAL_Delay(50000);
    lcd_cmd(0x20 | bits | font | lines);
    HAL_Delay(50000);
    lcd_cmd(_LCD_INIT);
    HAL_Delay(50000);
    lcd_cmd(0x0E);
    HAL_Delay(50000);
    lcd_cmd(0x0C);
    HAL_Delay(50000);
    lcd_cmd(0x01);
		HAL_Delay(100000);*/
}

void LCD_Goto(unsigned char row, unsigned char column)
{	
	if(row == 1)
	{
		lcd_cmd(0x80 + (column - 1));
	}
	else if(row == 2)
	{
		lcd_cmd(0xC0 + (column - 1));
	} 
}

void lcd_char(unsigned char row, unsigned char column, char out_char)
{
	LCD_Goto(row, column);
	LCD_Char_CP(out_char);
}

void lcd_printf(unsigned char row, unsigned char column, char *out_char)
{
	LCD_Goto(row, column);
	LCD_Out_CP(out_char);
}

void main_menu(void)
{
	/*uint8_t a = 0;

    //lcd_cmd(0x01);
    HAL_Delay(10);

    //lcd_printf(1,1, " ALVEMSIS A.S.  ");

    if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15))
    {
    	a++;*/

    	/*if(a=0 && a=1 && a=2 && a=3 && a=4 && a=5)
    	{
    		a++;
    	}*/
    	/*if(a == 6)
    	{
    		a=5;
    	}
    	if(a == 22)
    	{
    		a=21;
    	}
    }

    if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10))
    {
   		if(a == 0)
   		{
   			a=20;
   		}
   		if(a == 1)
   		{
   			a=30;
   		}
   		if(a == 2)
   		{
   			a=40;
   		}
   		if(a == 3)
   		{
   			a=50;
   		}
   		if(a == 4)
   		{
   			a=60;
   		}
   		if(a == 5)
   		{
   			a=70;
   		}
    }

    if(a == 0)
    {
    	lcd_printf(1,1, ">1.Led Ayari    ");
    	lcd_printf(2,1, " 2.STM Led Ayari");
    }

    if(a == 1)
    {
        lcd_printf(1,1, " 1.Led Ayari    ");
		lcd_printf(2,1, ">2.STM Led Ayari");
    }

    if(a == 2)
    {
        lcd_printf(1,1, ">3.Bluetooth    ");
		lcd_printf(2,1, " 4.Wifi         ");
    }

    if(a == 3)
    {
        lcd_printf(1,1, " 3.Bluetooth    ");
		lcd_printf(2,1, ">4.Wifi         ");
    }

    if(a == 4)
    {
    	lcd_printf(1,1, ">5.Genel Ayarlar");
    	lcd_printf(2,1, " 6.İsimler      ");
    }

    if(a == 5)
    {
    	lcd_printf(1,1, " 5.Genel Ayarlar");
    	lcd_printf(2,1, ">6.İsimler      ");
    }

    if(a == 20)
    {
    	lcd_printf(1,2,">AC             ");
    	lcd_printf(2,2," KAPAT          ");
    }

    if(a == 21)
    {
    	lcd_printf(1,2," AC             ");
    	lcd_printf(2,2,">KAPAT          ");
    }*/
}


void tus_enter(void)
{
	//uint8_t tus = 1;
	lcd_cmd(0x01);
	lcd_cmd(0x02);
}

void tus_up(void)
{
	//uint8_t tus = 10;
	lcd_cmd(0x80);
	lcd_printf(1,1, ">               ");
}

void tus_down(void)
{
	//uint8_t tus = 100;
	lcd_cmd(0xC0);
    lcd_printf(1,1, ">               ");
}

void led(void)
{
      if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10))
	   {
		    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
		    lcd_printf(1,1, "   Led Yaniyor  ");
		    HAL_Delay(10);
       }
	  else
	  {
            //lcd_cmd(0x01);
		    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
            lcd_printf(1,1, " Led Yanmiyor  ");
            HAL_Delay(10);
	  }
}

