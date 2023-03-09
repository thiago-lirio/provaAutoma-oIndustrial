/*
 * Solucao_Microcontrolada_Problema_3.c
 *
 * Created: 19/04/2021 12:21:01
 * Author : Thiago G. Lirio
 */ 
#define F_CPU 16000000UL
#include <stdlib.h>
#include <avr/io.h>
#include <stdio.h>
#include <stdbool.h>

#define set_bit(adress, bit) (adress=(1<<bit))
#define clr_bit(adress, bit) (adress&=(1<<bit)) 
#define rd_bit(adress, bit) (adress&(1<<bit))

#define Cil_A PORTB0 
#define Cil_B PORTB1 
#define Cil_C PORTB2		 

#define B_Start PORTD0
#define A0 PORTD1
#define A1 PORTD2
#define B0 PORTD3
#define B1 PORTD4
#define C0 PORTD5
#define C1 PORTD6

int K1 = 0;
int K2 = 0;
int K3 = 0;
int K4 = 0;
int K5 = 0;


int main(void)
{
    /* Replace with your application code */
	DDRB = 0xFF;
	DDRD = 0x00;
    while (1) 
    {	
		if (K5 == 0 && ((rd_bit(PIND, B_Start) == 1 && (rd_bit(PIND, A0) == 1) || K1 == 1)))
		{
			K1 = 1;
		}
		else K1 = 0;
	
		if (K1 == 1  && ((rd_bit(PIND, C1) == 1 || K2 == 1)))
		{
			K2 = 1;
		}
		else K2 = 0;
		if (K2 == 1 && ((rd_bit(PIND, C0) == 1 || K3 == 1)))
		{
			K3 = 1;
		}
		else K3 = 0;
		if (K3 == 1 && ((rd_bit(PIND, B1) == 1 || K4 == 1)))
		{
			K4 = 1;
		}
		else K4 = 0;
		if (K4 == 1 && ((rd_bit(PIND, B0) == 1 || K5 == 1)))
		{
			K5 = 1;
		}
		else K5 = 0;
		
		if (K1 == 1 && K5 == 0)
		{
			set_bit(PORTB, Cil_A);
		}
		else clr_bit(PORTB, Cil_A);
		if (K3 == 1 && K4 == 0)
		{
			set_bit(PORTB, Cil_B);
		}
		else clr_bit(PORTB, Cil_B);
		if (K1 == 1 && K2 == 0)
		{
			set_bit(PORTB, Cil_C);
		}
		else clr_bit(PORTB, Cil_C);
    }
}

