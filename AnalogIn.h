#ifndef ANALOGIN_H
#define ANALOGIN_h

class AnalogIn {
public:
AnalogIn();
AnalogIn(unsigned int n);
virtual unsigned int getNumber() { return m_number; }
virtual void setNumber(unsigned int n);
virtual int readADCsample();
virtual ~AnalogIn();
private:
unsigned int m_number;
};

#endif
