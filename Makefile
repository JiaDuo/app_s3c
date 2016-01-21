CROSS_COMPILE=arm-linux-
app.bin:app.out
	$(CROSS_COMPILE)objcopy -O binary app.out app.bin
app.out:app_led.o
	$(CROSS_COMPILE)ld -e main -Ttext 0x33000000 app_led.o  -o app.out
app_led.o:app_led.c
	$(CROSS_COMPILE)gcc -c app_led.c -o app_led.o

.PHONY:clean
clean:
	rm -rf *.o *.out
