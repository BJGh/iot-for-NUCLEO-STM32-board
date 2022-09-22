#include "mbed.h"

#include "Sht31.h"


Sht31 sht31(I2C_SDA, I2C_SCL);
DigitalOut led(LED1);
float read_temp()
{
      float temp = sht31.readTemperature();
      return temp;
}
float read_humidity()
{
      float humidity = sht31.readHumidity();
      return humidity;
}

int main() {
    printf("Set the temperature and humidity above 25 degrees and 65 percent to trigger the warning LED\n");

    while (1) {
    
        float temp = sht31.readTemperature();
        float humidity = sht31.readHumidity();
       printf("Temperature: %.2f C", read_temp());
    
      printf("Humidity: %.2f %%", read_humidity());

        // turn on LED if the temperature is above 25 degrees
        if(temp > 25.0f && humidity > 65)
        {
            led =!led;
        }

        wait(0.5f);
    }
}