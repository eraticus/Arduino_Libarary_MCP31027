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
		if (pin<8)
		{
		int x = getRegister(IODIRA);
		if (direction == INPUT)
			x |= 1<<pin;
		else
			x &= ~(1<<pin);
		setRegister(IODIRA, x);	
		}
		else if (pin<16)
		{
			int x = getRegister(IODIRB);
			if (direction == INPUT)
				x |= 1<<(pin-8);
			else
				x &= ~(1<<(pin-8));
			setRegister(IODIRB, x);	
		}
		else
		{
			// exception goes here
		}
	}
	
	void MCP23017::digitalWrite(int pin, int value)
	{
		if (pin<8)
		{
		int x = getRegister(GPIOA);
		if (value == HIGH)
			x |= 1<<pin;
		else
			x &= ~(1<<pin);
		
		setRegister(GPIOA, x);
		}
		else if (pin<16)
		{
			int x = getRegister(GPIOB);
			if (value == HIGH)
				x |= 1<<(pin-8);
			else
				x &= ~(1<<(pin-8));

			setRegister(GPIOB, x);
			
		}
		else
		{
			// exception goes here
		}	
		
	}
	
	void MCP23017::setDDRA(int value)
	{
		setRegister(IODIRA, ~value);
	}
	
	void MCP23017::setDDRB(int value)
	{
		setRegister(IODIRB, ~value);
	}
	
	
	void MCP23017::setPORTA(int value)
	{
		setRegister(GPIOA, value);
	}
	
	void MCP23017::setPORTB(int value)
	{
		setRegister(GPIOB, value);
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
	