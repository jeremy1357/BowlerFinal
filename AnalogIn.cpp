#include "AnalogIn.h"
#include <sstream>
#include <fstream>

const std::string ADC_PATH = "/sys/bus/iio/devices/iio:device0/in_voltage";

AnalogIn::AnalogIn() {
}

AnalogIn::AnalogIn(unsigned int n) {
m_number = n;
}

void AnalogIn::setNumber(unsigned int n) {
m_number = n;
}

int AnalogIn::readADCsample() {
int result = 0;
std::stringstream s;
s << ADC_PATH << m_number << "_raw";
std::fstream fs;
fs.open(s.str().c_str(), std::fstream::in);
fs >> result;
fs.close();
return result;
}

AnalogIn::~AnalogIn() {

}
