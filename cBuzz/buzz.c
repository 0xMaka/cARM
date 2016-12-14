#include <avr/io.h>
#include <util/delay.h>

enum t0_prescaler {

 	T0_PRESCALER_1 = _BV(CS00),

 	T0_PRESCALER_8 = _BV(CS01),

 	T0_PRESCALER_64 = _BV(CS00) | _BV(CS01),

 	T0_PRESCALER_256 = _BV(CS02),

 	T0_PRESCALER_1024 = _BV(CS02) | _BV(CS00), 

};

static void t0_set_prescaler (enum t0_prescaler ps)
{
	TCCR0B = ps;
}

static unsigned short t0_get_prescaler_rate(enum t0_prescaler ps)
{
	unsigned short rate;
	switch (ps)
	{
		case T0_PRESCALER_1:
			rate = 1;
			break;

		case T0_PRESCALER_64:
			rate = 64;
			break;

		case T0_PRESCALER_256:
			rate = 256;
			break;

		case T0_PRESCALER_1024:
			rate = 1024;
			break;
			
		default: 
			rate = 0;
			break;
	}
}

static unsigned long div_round(unsigned long d, unsigned long q) 
{
	return (d + (q/2)) / q;
}

static void t0_set_ctc_a(unsigned long hz, unsigned long timer_freq)
{
	OCR0A = div_round(timer_freq, hz*2) -1;
	TCCR0A = 
		_BV(COM0A0) // Toggle
	      | _BV(WGM01); // CTC
}

int main (void) {
	unsigned long timer_freq;

	enum t0_prescaler ps = T0_PRESCALER_256;

	DDRD |= _BV(DDD6);
	t0_set_prescaler (ps);
	timer_freq = div_round(F_CPU, t0_get_prescaler_rate(ps)); 

	while (1)
	{
		t0_set_ctc_a(440, timer_freq);
		_delay_ms(200);
		t0_set_ctc_a(880, timer_freq);
		_delay_ms(200);

	}
	return 0;
}
