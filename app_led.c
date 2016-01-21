
#define GPBCON	(*((volatile unsigned int *)0x56000010))
#define GPBDAT	(*((volatile unsigned int *)0x56000014))
void led_init(void);
void led_on(void);
void led_off(void);
void delay(unsigned int);
void main(void) /* make sure: 'main'.test = Ttext */
{
	unsigned int i=0;
	led_init();
	for(i=0;i<10;i++)
	{
		led_on();
		delay(100);
		led_off();
		delay(100);
	}
}
void led_init(void)
{
        GPBCON &= ~(3<<10);
        GPBCON |= (1<<10);
}
void led_on(void)
{
	GPBDAT &= ~(1<<5);
}
void led_off(void)
{
	GPBDAT |= (1<<5);
}
void delay(unsigned int c)
{
	unsigned int i=0;
	while(c--)
	{
		for(i=0;i<100000;i++);
	}
}


