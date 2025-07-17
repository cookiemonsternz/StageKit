# Stagekit

Stagekit is a 3D-printable, completely hand-solderable diy lighting previs kit. 

It consists of various fixtures, truss elements, and set dressing pieces, all modelled at a fairly accurate 1:10 scale. The truss pieces are modelled after standard Eurotruss, and the lights after various fixtures, but due to design requirements, sizing and design liberties have had to be taken. 

## Fixtures

Currently, Stagekit has 3 fixture designs available, but more designs are coming in the future.

| Fixture     | Estimated Material Cost (USD) | Images                               |
|-------------|-------------------------------| ------------------------------------ |
| RGB Par     | $4                            | ![RGB Par](/img/rgbpar-complete.png) |
| RGB Tube    | $5                            | ![RGB Tube](img/rgbtube-full.png)    |
| RGB Blinder | $4                            | ![RGB Blinder](img/blinder-full.png) |

The RGB Blinder and RGB Tube both utilize neopixels, and the RGB Par uses a RGB Led. All fixtures use an ATTiny85 acting as an i2c slave, controlled by a RPi Zero 2 W or other i2c capable controller. The controller acts as an art net node, and sends i2c over 4 wire Molex Picoblade connectors, daisy chained together akin to DMX.

## Truss Pieces

There are currently four main truss pieces available, with more options in the future again.
All parts should be easily printable, and there are versions of each file which should be able to be printed without supports. 

Truss piece straight - 100mm
![Truss piece straight](img/truss-1m-final.png)

Truss piece corner
![Truss piece corner](img/corner-truss-final.png)

Truss base piece
![Truss base piece](img/truss_base.png)

Truss connector bracket
![Truss connector bracket](img/truss-connector.png)

## Set elements

There are a variety of set pieces available.
Ashdown ABM-600 EVO IV:
![Ashdown head front](img/ashdown_front.png)

Ampeg Classic 8x10 Cab:
![8x10 Ampeg cab](img/8x10cab.png)

Fender Rumble 100:
![Rumble Front view](img/rumble-front.png)

Markbass 1x15 cab:
![1x15 Cab](img/1x15cab.png)

Generic 4x10 cab:
![4x10 cab](img/4x10cab.png)

Generic Roadcase:
![Roadcase](img/roadcase.png)

Generic Wedge Monitor:
![Wedge monitor](img/monitor-wedge.png)

Generic Subwoofer:
![Subwoofer](img/subwoofer.png)

Generic Line Array:
![Line array](img/line-array.png)
*Note: scale should be checked before printing, while this is to scale, it is very large*

Generic Fence:
![Generic fence](img/pipe_fence.png)

Stage platform 1x1:
![Stage Platform](img/stage-platform1x1-legs.png)

Stage platform 1x2:
![1x2 platform](img/stage-platform1x2.png)

Stage platform 2x2:
![2x2 Platform](img/stage-platform2x2.png)

Stage stairs:
![Stairs](img/stairs.png)

## Firmware

To program the ATTiny85 chips, you will need either a dedicated programmer or an Arduino Uno or similar. The source code for all of the lights can be found in the firmware directory.

Unfortunately, due to size and budget limitations, light addresses must be hardcoded into each chip individually. This means that when flashing firmware, ensure each light has a different address assigned, by editing the `.ino` file and changing the value of `I2C_SLAVE_ADDRESS` to any unused value between 0x01 and 0x7F before programming.

PCB Source files can be found in the respective folder (Blinder, RGB Par, RGB Tube) and all 3D models can be found inside the cad folder.

## BOM

Better formatted BOM's are also available at [this google sheet](https://docs.google.com/spreadsheets/d/1baBuS65jXXmk7wej5hXxSFTJ-pqP7fWwTh28TKW3xLs).

**RGB PAR**
| Item       | Part Name       | Quantity | Source     | Link                                                  | Unit Cost | Total Cost | Notes                                                                                                                                                                                            |
|------------|-----------------|----------|------------|-------------------------------------------------------|-----------|------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| U1         | ATTiny85        | 1        | Aliexpress | https://www.aliexpress.com/item/1005007400913382.html | 1.75      | 1.75       | Looking for cheaper ones                                                                                                                                                                         |
| D1         | RGB LED         | 1        | Aliexpress | https://www.aliexpress.com/item/1005005768279384.html | 0.46      | 0.46       | I have designed this for the 3x3w 6 pin rgb, as that is what I had on hand, but the 3x1w 6 pin rgb will almost certainly work as well, and the led driver does not even close to deliver 3 watts |
| R1         | 150Ω Resistor   | 1        | Aliexpress | https://www.aliexpress.com/item/1005001627995396.html | 0.02      | 0.02       | Comes in pack of 100, 1.65 per resistor value                                                                                                                                                    |
| R2, R3     | 100Ω Resistor   | 2        | Aliexpress | https://www.aliexpress.com/item/1005001627995396.html | 0.02      | 0.04       | Comes in pack of 100, 1.65 per resistor value                                                                                                                                                    |
| R4         | 10KΩ Resistor   | 1        | Aliexpress | https://www.aliexpress.com/item/1005001627995396.html | 0.02      | 0.02       | Comes in pack of 100, 1.65 per resistor value                                                                                                                                                    |
| J1, J3     | Molex Conn      | 2        | Aliexpress | https://aliexpress.com/item/4000127192324.html        | 0.06      | 0.12       | If you buy more than 50 you can bring this down to a total cost of 0.16                                                                                                                          |
| PCB        | PCB             | 1        | JLCPCB     | https://jlcpcb.com/                                   | 0.42      | 0.42       |                                                                                                                                                                                                  |
| CASEB      | Bottom Case     | 1        | 3D Printed | NA                                                    | 0.08      | 0.08       | around 4g of filament, if done through jlc3dp with standard resin, costs 0.36                                                                                                                    |
| CASET      | Top Case        | 1        | 3D Printed | NA                                                    | 0.04      | 0.04       | If printed on fdm printer, its approx 2g of filament, if ordered through jlcpcb with standard resin, cost 0.3 (min possible)                                                                     |
| PAPER      | Diffusion Paper | 1        | NA         | NA                                                    | NA        | NA         | The diffusion paper can be any semi transparent paper like material, I'm using white baking paper, and thus have ommitted the cost as it feels pointless to measure this                         |
| Total Cost |                 |          |            |                                                       |           |            |                                                                                                                                                                                                  |
|            |                 |          |            |                                                       |           | 2.95       | Economy of scale does come into play here, especially with the attiny and the pcbs                                                                                                               |

**RGB Tube**
| Item                   | Part Name       | Quantity | Source     | Link                                                  | Unit Cost | Total Cost | Notes                                                                                                                                                                                                                    |
|------------------------|-----------------|----------|------------|-------------------------------------------------------|-----------|------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| U1                     | ATTiny85        | 1        | Aliexpress | https://www.aliexpress.com/item/1005007400913382.html | 1.75      | 1.75       | Looking for cheaper ones                                                                                                                                                                                                 |
| R4                     | 10KΩ Resistor   | 1        | Aliexpress | https://www.aliexpress.com/item/1005001627995396.html | 0.02      | 0.02       | Comes in pack of 100, 1.65 per resistor value                                                                                                                                                                            |
| J1, J2                 | Molex Conn      | 2        | Aliexpress | https://aliexpress.com/item/4001254843951.html        | 0.04      | 0.08       | This is for 100 unfortunately, but I can't find anything else on aliexpress and lcsc shipping is insane                                                                                                                  |
| D1, D2, D3, D4, D5, D6 | Neopixel        | 6        | Aliexpress | https://www.aliexpress.com/item/4001345875756.html    | 0.03      | 0.18       | This is assuming ordering a batch of 100                                                                                                                                                                                 |
| PCB                    | PCB             | 1        | JLCPCB     | https://jlcpcb.com/                                   | 0.84      | 0.84       | Batch of five                                                                                                                                                                                                            |
| CASEB                  | Bottom Case     | 1        | 3D Printed | NA                                                    | NA        | NA         | Cura says 0g of filament lol, if done through jlc3dp with standard resin, cost 0.3                                                                                                                                       |
| CASET1                 | Top Case Body   | 1        | 3D Printed | NA                                                    | 0.05      | 0.05       | around 3g of filament, if done through jlc3dp with standard resin, costs 0.30. This piece includes the clamp connected to the print, but it can also be printed seperately                                               |
| CASET2                 | Top Case Cap    | 1        | 3D Printed | NA                                                    | NA        | NA         | Again, 0g of filament, will also cost 0.3 because that is the minimum cost                                                                                                                                               |
| TUBE                   | PMMA Tube       | 1        | Aliexpress | https://www.aliexpress.com/item/1005004505505004.html | 0.98      | 0.98       | OD 12mm, ID 10mm, 130mm long                                                                                                                                                                                             |
| PAPER                  | Diffusion Paper | 1        | NA         | NA                                                    | NA        | NA         | The diffusion paper can be any semi transparent paper like material, I'm not including this in mine as the pmma tube serves this purpose, but if you use acrylic for example, you may want to add some form of diffusion |
| Total Cost             |                 |          |            |                                                       |           |            |                                                                                                                                                                                                                          |
|                        |                 |          |            |                                                       |           | 3.9        | Economy of scale does come into play here, especially with the attiny and the pcbs                                                                                                                                       |

**RGB Blinder**
| Item       | Part Name       | Quantity | Source     | Link                                                  | Unit Cost | Total Cost | Notes                                                                                                                                                                      |
|------------|-----------------|----------|------------|-------------------------------------------------------|-----------|------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| U1         | ATTiny85        | 1        | Aliexpress | https://www.aliexpress.com/item/1005007400913382.html | 1.75      | 1.75       | Looking for cheaper ones                                                                                                                                                   |
| R4         | 10KΩ Resistor   | 1        | Aliexpress | https://www.aliexpress.com/item/1005001627995396.html | 0.02      | 0.02       | Comes in pack of 100, 1.65 per resistor value                                                                                                                              |
| J1, J2     | Molex Conn      | 2        | Aliexpress | https://aliexpress.com/item/4000127192324.html        | 0.06      | 0.12       | If you buy more than 50 you can bring this down to a total cost of 0.16                                                                                                    |
| D1, D2     | Neopixel        | 2        | Aliexpress | https://www.aliexpress.com/item/4001345875756.html    | 0.03      | 0.06       | This is assuming ordering a batch of 100                                                                                                                                   |
| PCB        | PCB             | 1        | JLCPCB     | https://jlcpcb.com/                                   | 0.82      | 0.82       | Batch of five                                                                                                                                                              |
| CASEB      | Bottom Case     | 1        | 3D Printed | NA                                                    | 0.08      | 0.08       | around 4g of filament, if done through jlc3dp with standard resin, costs 0.3 - This piece includes the clamp connected to the print, but it can also be printed seperately |
| CASET      | Top Case        | 1        | 3D Printed | NA                                                    | 0.06      | 0.06       | around 3g of filament, if done through jlc3dp with standard resin, costs 0.3                                                                                               |
| PAPER      | Diffusion Paper | 1        | NA         | NA                                                    | NA        | NA         | The diffusion paper can be any semi transparent paper like material, I would reccomend some form of diffusion for this light, as the raw leds look a bit ugly              |
| Total Cost |                 |          |            |                                                       |           |            |                                                                                                                                                                            |
|            |                 |          |            |                                                       |           | 2.91       | Economy of scale does come into play here, especially with the attiny and the pcbs                                                                                         |

**Total**

| Part Name           | Quantity | Source             | Link                                              | Unit Cost | Total Cost | Notes                                                                                                                                                         |
|---------------------|----------|--------------------|---------------------------------------------------|-----------|------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------|
| RGB Par             | 12       | SEE INDIVIDUAL BOM | NA                                                | 2.95      | 35.4       | Looking for cheaper ones                                                                                                                                      |
| RGB Tube            | 12       | SEE INDIVIDUAL BOM | NA                                                | 3.9       | 46.8       | Comes in pack of 100, 1.65 per resistor value                                                                                                                 |
| RGB Blinder         | 6        | SEE INDIVIDUAL BOM | NA                                                | 2.91      | 17.46      | If you buy more than 50 you can bring this down to a total cost of 0.16                                                                                       |
| Cables              | 20       | Aliexpress         | https://aliexpress.com/item/1005007774081283.html | 0.184     | 3.68       | The diffusion paper can be any semi transparent paper like material, I would reccomend some form of diffusion for this light, as the raw leds look a bit ugly |
| ATTiny Programmer   | 1        | Aliexpress         | https://aliexpress.com/item/1005005704723470.html | 1.43      | 1.43       |                                                                                                                                                               |
| 3D Printer filament | 1        | Aliexpress         | https://aliexpress.com/item/1005006861804231.html | 26.33     | 26.33      | I am printing >1kg of material. This includes: 16 Truss Straight (800g) + 4 Truss Corner (172g) + Various other elements                                      |
| Total Cost          |          |                    |                                                   |           |            |                                                                                                                                                               |
|                     |          |                    |                                                   |           | 131.1      | Excl shipping                                                                                                                                                 |
|                     |          |                    |                                                   |           | 119.57     | Incl. Shipping - Aliexpress (93.72) - JLCPCB (25.85)                                                                                                          |