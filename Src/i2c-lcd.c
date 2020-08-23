
/** Put this in the src folder **/

#include "i2c-lcd.h"
//extern I2C_HandleTypeDef hi2c1;  // change your handler here accordingly

/*#define SLAVE_ADDRESS_LCD 0x4E // change this according to ur setup

void lcd_cmd (char cmd)
{
  char data_h, data_l;
	uint8_t data_t[4];
	data_h = (cmd&0xf0);
	data_l = ((cmd<<4)&0xf0);
	data_t[0] = data_h|0x0C;  //en=1, rs=0
	data_t[1] = data_h|0x08;  //en=0, rs=0
	data_t[2] = data_l|0x0C;  //en=1, rs=0
	data_t[3] = data_l|0x08;  //en=0, rs=0
	//HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_send_data (char data)
{
	char data_h, data_l;
	uint8_t data_t[4];
	data_h = (data&0xf0);
	data_l = ((data<<4)&0xf0);
	data_t[0] = data_h|0x0D;  //en=1, rs=0
	data_t[1] = data_h|0x09;  //en=0, rs=0
	data_t[2] = data_l|0x0D;  //en=1, rs=0
	data_t[3] = data_l|0x09;  //en=0, rs=0
	//HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_gotoxy(unsigned char row, unsigned char column)
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

void lcd_init (void)
{
	lcd_cmd (0x01);  //ben ekledim
	lcd_cmd (0x02);
	lcd_cmd (0x28);
	lcd_cmd (0x0c);
	lcd_cmd (0x80);
}

void main_menu(void)
{
    lcd_printf(" ALVEMSIS A.S.");

    if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3))
    {
    	lcd_cmd(0x01);
    	lcd_printf("  1.sefa");
    	lcd_cmd(0xC0);
    	lcd_printf("  2.erdem");

    	lcd_cmd(0x01);
    	lcd_printf("  3.bekir");
    	lcd_cmd(0xC0);
    	lcd_printf("  4.hatice");

    	lcd_cmd(0x01);
    	lcd_printf("  5.muhittin");
    	lcd_cmd(0xC0);
    	lcd_printf("  6.zeliha");

    	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3))
    	{
    		tus_enter();
    	}

    	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4))
    	{
    		tus_up();
    	}

    	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5))
    	{
    	    tus_down();
    	}
    }
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
	lcd_printf(">               ");
}

void tus_down(void)
{
	//uint8_t tus = 100;
	lcd_cmd(0xC0);
    lcd_printf(">               ");
}

void lcd_printf (char *str)
{
	while (*str) lcd_send_data (*str++);
}

*/
