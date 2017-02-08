#include <Arduino.h>

//const int IODIRA = 0x00;
#define IODIRA  0x00
#define GPIOA 0x12


class MCP23017
{
  // user-accessible "public" interface
  public:
    MCP23017(int address);

	void pinMode(int pin, int mode);
	void digitalWrite(int pin, int value);
	int test();
	int getRegister(int reg); // make private
	void setRegister(int reg, int val); // make private
	
    
  // library-accessible "private" interface
  private:
	int _address;
    
};