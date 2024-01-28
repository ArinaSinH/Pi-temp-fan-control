#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <errno.h>

#define PWM_PIN 147
#define WPPWM_PIN 2

int main()
{
    if (wiringPiSetup() == -1)
    {
        perror("Failed to setup wiringPi");
        return -1;
    }
    // pinMode(PWM_PIN, PWM_OUTPUT);
    // int status = OrangePi_set_gpio_mode(PWM_PIN, PWM_OUTPUT);

    // int status = OrangePi_set_gpio_mode(PWM_PIN, INPUT);

    // int trueStatus = OrangePi_get_gpio_mode(PWM_PIN);

    //printf("Actual status: %d", trueStatus);

    pinMode(WPPWM_PIN, OUTPUT);
    int status = softPwmCreate(WPPWM_PIN, 0, 100);

    printf("Status: %d", status);

    fflush(stdout);

    int value = 0;

    while(1){
        //OrangePi_digitalWrite(PWM_PIN, value);
        softPwmWrite(WPPWM_PIN, value);

        value += 10;
        if(value > 100){
            value = 0;
        }
        delay(1000);
    }

    return 0;
}
