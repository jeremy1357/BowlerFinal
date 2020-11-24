// Jeremy Bowler

#include "GPIO.h"
#include "AnalogIn.h"
#include <iostream>
#include <unistd.h> // For sleep

using namespace exploringBB;

const float V_PER_STEP = 1.80f / 4096.0f;



float convertToTempF(int ADCvalue) {
float x = ((ADCvalue * (1.80f / 4096.0f)) - 0.75f) / 0.01f;
return (((x + 25.0f) * 9) / 5) + 32 ;
}



// USE ANALOG INPUT 6
float convertToVoltage(int adcStep) {
return V_PER_STEP * (float)adcStep;
}

int main(int argc, char* argv[]) {
// LED
GPIO led(60);
led.setDirection(OUTPUT);
// Pushbutton
GPIO pushbutton(46);
pushbutton.setDirection(INPUT);

// AIN0 connected to TMP36
// AIN6 connected to voltage divider
AnalogIn temperature(0);
AnalogIn voltageDivider(6);


int pushbuttonReading = pushbutton.getValue();
std::cout << "Button reading " << pushbuttonReading << std::endl;
if (pushbuttonReading == 0) {
std::cout << "Button is pushed!" << std::endl;
std::cout << "Displaying resistance and LED will be blinked twice" << std::endl;
int ain0Reading = voltageDivider.readADCsample();
float voltage = convertToVoltage(ain0Reading);
float resistance = (voltage * 10000.0f) / (1.8f - voltage);
std::cout << "Calculated resistance = " << resistance << std::endl;

led.setValue(HIGH);
sleep(1);
led.setValue(LOW);
sleep(1);
led.setValue(HIGH);
sleep(1);
led.setValue(LOW);

}
else if (pushbuttonReading == 1)
{
std::cout << "Button is not pressed!" << std::endl;
std::cout << "Reading temperature and blinking LED once" << std::endl;
std::cout << "Raw temperature is " << temperature.readADCsample() << std::endl;
std::string temp = std::to_string(convertToTempF(temperature.readADCsample()));
std::cout << "Temperature F " << temp << std::endl;
led.setValue(HIGH);
sleep(1);
led.setValue(LOW);
sleep(1);
}



}
