#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>


int time;


int main(void){

	DDRB = 0xFF;
	DDRD = 0x00;
	PORTD = 0xFF;
	DDRB = 0x00;


	while(1){
		time = 0;

		if((PIND & (1<<PIND0))==(1<<PIND0)){
			time = time+1;
		};
		if((PIND & (1<<PIND1))==(1<<PIND1)){
			time = time+2;
		};
		if((PIND & (1<<PIND2))==(1<<PIND2)){
			time = time+4;
		};
		if((PIND & (1<<PIND3))==(1<<PIND3)){
			time = time+8;
		};
		if((PIND & (1<<PIND4))==(1<<PIND4)){
			time = time+16;
		};
		if((PIND & (1<<PIND5))==(1<<PIND5)){
			time = time+32;
		};
		if((PIND & (1<<PIND6))==(1<<PIND6)){
			time = time+64;
		};

		while(time>0){
			if((PIND & (1<<PIND7))==(1<<PIND7)){
				//PORTB = time;
				time--;
				_delay_ms(1000);
				if(time==0){
					PORTB|=(1<<PORTB6);
					_delay_ms(50);
					PORTB&=~(1<<PORTB6);
				}else{
					PORTB&=~(1<<PORTB6);
				}

			}else{
				PORTB&=~(1<<PORTB6);
				time = 0;
			}
		}
	}
}
