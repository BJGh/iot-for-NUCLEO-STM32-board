//serial_pass
#include "mbed.h"
 
RawSerial  pc(USBTX, USBRX);
RawSerial  dev(D8, D2);
DigitalOut led1(LED1);
 
void dev_recv()
{
    led1 = !led1;
    while(dev.readable()) {
        pc.putc(dev.getc());
    }
}
 
void pc_recv()
{
    while(pc.readable()) {
        dev.putc(pc.getc());
    }
}
 
int main()
{
    pc.baud(115200);
    dev.baud(115200);
 
    pc.attach(&pc_recv, Serial::RxIrq);
    dev.attach(&dev_recv, Serial::RxIrq);
 
    while(1) {
        sleep();
    }
}
