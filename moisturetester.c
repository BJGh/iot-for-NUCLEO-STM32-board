//NUCLEO Moisture tester
#include "mbed.h"
#include "DHT.h"



DigitalOut led(LED1);
//sda, sdl

DHT sensor(D7,DHT11);

Thread thread();



void print_humidity()
{   float h;
    while(true){
    h = sensor.ReadHumidity();
    printf(" %f\n\r", h);
    wait_ms(500);
    led = !led;
    }
}

void print_thread()
{
    while(true)
    {
      wait(1);
      print_humidity(); 
       
    }
}

int main()
{
    thread.start(print_thread);
}