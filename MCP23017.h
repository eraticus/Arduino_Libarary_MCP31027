#include <Arduino.h>

//const int IODIRA = 0x00;
const int IODIRA = 0x00;
const int IODIRB = 0x01;
const int GPIOA = 0x12;
const int GPIOB = 0x13;

class MCP23017
{
  // user-accessible "public" interface
  public:
    MCP23017(int address);

	void pinMode(int pin, int mode);
	void digitalWrite(int pin, int value);
	int test();
	
  // library-accessible "private" interface
  private:
	int _address;
	
	// interface to I2C
	int getRegister(int reg); // make private
	void setRegister(int reg, int val); // make private
	
	
    
};