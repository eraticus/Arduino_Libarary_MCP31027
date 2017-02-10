MCP23017(address) constructor for MCP23017 chip interface. Address is I2C
address of chip.

pinMode(int pin, int mode)
same as Arduino pinMode
Set pin input or output. Input functions are not currently implemented.
pins 0 through 7 are port A, and 8 through 15 are port B.

digitalWrite(int pin, int value)
same as Arduino digitalWrite

setDDRA and setDDRB
set Data Direction Register A and B
Same as the DDRX registers in ATMEL ASM
Sets the entire port A or Port B direction at the same time. Uses Atmel
convension of 0 for input and 1 for output.

setPORTA setPORTB
sets the value of portA and portB
Same as the PORTX output port registers in ATMEL ASM.
Sets the entire port A or Port B value.
