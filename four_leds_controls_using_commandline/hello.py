#!/usr/bin/env python

# Uses pySerial to communicate with the AVR: http://pyserial.sourceforge.net/
import serial  

# The serial port that the AVR is connected to.
TTY_PORT = '/dev/ttyS0'

# The baud rate which must match the BAUD defined in main.c
BAUD = 9600

ON = [0x01, 0x02, 0x03, 0x04]
OFF = [0x11, 0x1A, 0x1B, 0x1C]
#command to send AVR
s = serial.Serial(TTY_PORT, BAUD, timeout=1)
while True:
    enter1 = ['one_on','two_on','three_on','four_on']
    enter2 = ['one_off', 'two_off', 'three_off', 'four_off']
    cmd = raw_input("LED ON/OFF SWITCH :")
    for i in range(4):
        if cmd == enter1[i]:
           s.write(chr(ON[i]))
        
        elif cmd == enter2[i]: 
           s.write(chr(OFF[i]))
    if cmd == 'exit':
        break
         
s.close()

