/* Servo Functions Header */
#ifndef F_CPU
#define F_CPU=16000000UL
#endif

void initPWM(void);
void sweepRightLeft(void);
void sweepLeftRight(void);
void sweepRightCenter(void);
void sweepLeftCenter(void);
void scanRightLeft(void);
void scanLeftRight(void);
void center(void);

