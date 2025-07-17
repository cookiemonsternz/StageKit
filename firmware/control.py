# Control Demo
# I'm waiting for physical hardware to implement Art-net input, 
# This should be able to flash all the lights red, green then blue.

# In this demo, there are 3 lights, one rgb par, one rgb tube, and one rgb blinder
# at addresses 0x30, 0x31, and 0x32 respectively.

import smbus
import time
bus = smbus.SMBus(0)
fixtures = [
    {
        "address": 0x30,
        "type": 0 # RGB Par
    },
    {
        "address": 0x31,
        "type": 1 # RGB Tube
    },
    {
        "address": 0x32,
        "type": 2 # RGB Blinder
    }, 
]

color = [1, 0, 0]

while True:
    for fixture in fixtures:
        if fixture.type == 0:
            bus.write_byte(fixture.address, color[0])
            bus.write_byte(fixture.address, color[1])
            bus.write_byte(fixture.address, color[2])
        if fixture.type == 1:
            for i in range(6):
                bus.write_byte(fixture.address, color[3 * i])
                bus.write_byte(fixture.address, color[3 * i + 1])
                bus.write_byte(fixture.address, color[3 * i + 2])
        if fixture.type == 2:
            for i in range(2):
                bus.write_byte(fixture.address, color[3 * i])
                bus.write_byte(fixture.address, color[3 * i + 1])
                bus.write_byte(fixture.address, color[3 * i + 2])
    
    if color == [1, 0, 0]:
        color = [0, 1, 0]
    elif color == [0, 1, 0]:
        color = [0, 0, 1]
    elif color == [0, 0, 1]:
        color = [1, 0, 0]
    
    time.sleep(1)