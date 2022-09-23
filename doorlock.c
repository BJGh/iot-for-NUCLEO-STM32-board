//doorlock code Nucleo Board
#include "mbed.h"
//pass 1320


DigitalIn button0(D2);
DigitalIn button1(D3);
DigitalIn button2(D8);
DigitalIn button3(D9);


DigitalOut led(LED1);
DigitalOut rel(D4);
 
int main() {
 printf("To open the door, enter pass\n");
  button0.mode(PullUp);
  button1.mode(PullUp);
  button2.mode(PullUp);
  button3.mode(PullUp);
  
  
  bool pass[4] = { false, false, false, false };
  rel = !rel;
  
  
  while(1) {
    if (button0 == 0)
    {
        
        if (pass[1] == true && pass[2] == true && pass[3] == true)
        {
            pass[0] = true;
        }
        else
        {
            pass[0] = false; pass[1] = false; pass[2] = false; pass[3] = false;
            printf("Wrong pass\n");
        }
        
    }
    else if (button1 == 0)
    {
        if (pass[0] == false && pass[2] == false && pass[3] == false)
        {
            pass[1] = true;
        } 
        else
        {
            pass[0] = false; pass[1] = false; pass[2] = false; pass[3] = false;
            //printf("Wrong pass");
        }
    }
    else if (button2 == 0)
    {
        if (pass[0] == false && pass[1] == true && pass[3] == true)
        {
            pass[2] = true;
        }
        else
        {
            pass[0] = false; pass[1] = false; pass[2] = false; pass[3] = false;
            //printf("Wrong pass\n");
        }
    }
    else if (button3 == 0)
    {
        if (pass[0] == false && pass[1] == true && pass[2] == false)
        {
            pass[3] = true;
        }
        else
        {
            pass[0] = false; pass[1] = false; pass[2] = false; pass[3] = false;
            //printf("Wrong pass\n");
        }
    }
    if (pass[0] == true && pass[1] == true && pass[2] == true && pass[3] == true)
    {
         //printf("door open");
        rel = !rel;
        for (int i = 0;i < 10;i++)
        {
             printf("door open\n");
             led = !led;
             wait_ms(1000);
        }
        rel = !rel;
        //printf("door open");
        pass[0] = false; pass[1] = false; pass[2] = false; pass[3] = false;
    }
  }
}