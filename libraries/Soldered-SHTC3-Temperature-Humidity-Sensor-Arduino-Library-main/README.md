# Temperature and humidity sensor SHTC3 breakout Arduino library

[![Make docs and publish to GitHub Pages](https://github.com/SolderedElectronics/Soldered-SHTC3-Temperature-Humidity-Sensor-Arduino-Library/actions/workflows/make_docs.yml/badge.svg?branch=dev)](https://github.com/SolderedElectronics/Soldered-SHTC3-Temperature-Humidity-Sensor-Arduino-Library/actions/workflows/make_docs.yml)

| ![Temperature and humidity sensor SHTC3 breakout](https://upload.wikimedia.org/wikipedia/commons/8/8f/Example_image.svg) |
| :----------------------------------------------------------------------------------------------------------------------: |
|                      [Temperature and humidity sensor SHTC3 breakout](https://www.solde.red/333032)                      |

Want to keep track of both the humidity and temperature in your room? Or maybe in the greenhouse to protect your crops? The SHTC3 breakout board is the solution you’re looking for! The digital sensor measures the changes in humidity and temperature very precisely. Since it’s very accurate and the temperature range is wide, it is a go-to sensor if you want precise climate information.

The breakout board uses the I2C communication protocol. Thus, it has two easyC ports so no soldering, nor distinguishing between SDA and SCL is required. The hardware-defined I2C address is 0x70. The design is 3.3V ready with an onboard regulator for 5V. The board’s standard current consumption is low, only 430 µA.

- Dimensions: 22 mm x 22 mm
- Standard current consumption: 430 µA
- Standby current consumption: 45 µA
- Logic voltage level: 3.3V
- Operating voltage: 3.3 (onboard regulator for 5V)
- Temperature measurement span: -40°C to 125°C; ± 0.2°C
- Relative humidity measurement span: 0% to 100%; ± 2% RH
- Communication: I2C (address: 0x70)
- Connectors: easyC x2
- Mounting holes: 2 (https://www.soldered.com/en/easyC)

### Repository Contents

- **/src** - source files for the library (.h & .cpp)
- **/examples** - examples for using the library
- **_other_** - _keywords_ file highlights function words in your IDE, _library.properties_ enables implementation with Arduino Library Manager.

### Hardware design

You can find hardware design for this board in [_Temperature and humidity sensor SHTC3 breakout_](https://github.com/SolderedElectronics/NAZIVPROIZVODA-hardware-design) hardware repository.

### Documentation

Access Arduino library documentation [here](https://SolderedElectronics.github.io/Soldered-SHTC3-Temperature-Humidity-Sensor-Arduino-Library/).

- Tutorial for using the Temperature & humidity sensor SHTC3 breakout board
- Installing an Arduino library

### Board compatibility

The library is compatible with board & microcontroller families shown in green below:

[![Compile Sketches](http://github-actions.40ants.com/e-radionicacom/Soldered-SHTC3-Temperature-Humidity-Sensor-Arduino-Library/matrix.svg?branch=dev&only=Compile%20Sketches)](https://github.com/SolderedElectronics/Soldered-SHTC3-Temperature-Humidity-Sensor-Arduino-Library/actions/workflows/compile_test.yml)

### About Soldered

<img src="https://raw.githubusercontent.com/e-radionicacom/Soldered-SHTC3-Temperature-Humidity-Sensor-Arduino-Library/dev/extras/Soldered-logo-color.png" alt="soldered-logo" width="500"/>

At Soldered, we design and manufacture a wide selection of electronic products to help you turn your ideas into acts and bring you one step closer to your final project. Our products are intented for makers and crafted in-house by our experienced team in Osijek, Croatia. We believe that sharing is a crucial element for improvement and innovation, and we work hard to stay connected with all our makers regardless of their skill or experience level. Therefore, all our products are open-source. Finally, we always have your back. If you face any problem concerning either your shopping experience or your electronics project, our team will help you deal with it, offering efficient customer service and cost-free technical support anytime. Some of those might be useful for you:

- [Web Store](https://www.soldered.com/shop)
- [Tutorials & Projects](https://soldered.com/learn)
- [Community & Technical support](https://soldered.com/community)

### Open-source license

Soldered invests vast amounts of time into hardware & software for these products, which are all open-source. Please support future development by buying one of our products.

Check license details in the LICENSE file. Long story short, use these open-source files for any purpose you want to, as long as you apply the same open-source licence to it and disclose the original source. No warranty - all designs in this repository are distributed in the hope that they will be useful, but without any warranty. They are provided "AS IS", therefore without warranty of any kind, either expressed or implied. The entire quality and performance of what you do with the contents of this repository are your responsibility. In no event, Soldered (TAVU) will be liable for your damages, losses, including any general, special, incidental or consequential damage arising out of the use or inability to use the contents of this repository.

## Have fun!

And thank you from your fellow makers at Soldered Electronics.
