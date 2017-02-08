#include <MCP23017.h>
#include <Wire.h>

MCP23017::MCP23017(int address)
{
	_address = address;
}

int MCP23017::test()
{
	Wire.beginTransmission(_address);
	  int retval = Wire.endTransmission();
	  return retval;
	}
	
	void MCP23017::pinMode(int pin, int direction)
	{
		//if (pin<8) // register A will be all we handle for now
		int x = getRegister(IODIRA);
		if (direction == INPUT)
			x |= 1<<pin;
		else
			x &= ~(1<<pin);
			
		setRegister(IODIRA, x);	
	}
	
	void MCP23017::digitalWrite(int pin, int value)
	{
		//if (pin<8) // register A will be all we handle for now
		int x = getRegister(GPIOA);
		if (value == HIGH)
			x |= 1<<pin;
		else
			x &= ~(1<<pin);
		
		setRegister(GPIOA, x);	
		
	}
	
	
	int MCP23017::getRegister(int reg)
	{
		Wire.beginTransmission(_address);
		Wire.write(reg);
		Wire.endTransmission();
		Wire.requestFrom(_address, 1);
		while(Wire.available()<1) // necessary?
		{
			;
		}
		int retval = Wire.read();
		return retval;
	}
	
	void MCP23017::setRegister(int reg, int val)
	{
		Wire.beginTransmission(_address);
		Wire.write(reg);
		Wire.write(val);
		Wire.endTransmission();
	}
	