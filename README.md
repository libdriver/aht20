[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver AHT20

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/aht20/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

As a new generation of temperature and humidity sensors, AHT20 sets a new standard in terms of size and performance: a two-row flat pin less SMD package suitable for reflow soldering, bottom face 3x3mm, height 1.0mm.The sensor outputs calibrated digital signals in standard IIC format.AHT20 is equipped with a newly designed ASIC dedicated chip, an improved MEMS semiconductor capacitive humidity sensor element and a standard on-chip temperature sensor element. Its performance has been greatly improved or even exceeded the reliability level of the previous generation of sensors. A generation of temperature and humidity sensors have been improved to make their performance more stable in harsh environments.Each sensor is calibrated and tested, and the product lot number is printed on the surface of the product. Due to improvements and miniaturization of the sensor, it is more cost-effective, and ultimately all devices will benefit from cutting-edge energy-saving operation modes. It is used in consumer electronics, medical, automotive, industrial, meteorological and other fields.

LibDriver AHT20 is the full function driver of AHT20 launched by LibDriver.It provides the function of reading temperature and relative humidity. LibDriver is MISRA compliant.

### Table of Contents

  - [Instruction](#Instruction)
  - [Install](#Install)
  - [Usage](#Usage)
    - [example basic](#example-basic)
  - [Document](#Document)
  - [Contributing](#Contributing)
  - [License](#License)
  - [Contact Us](#Contact-Us)

### Instruction

/src includes LibDriver AHT20 source files.

/interface includes LibDriver AHT20 IIC platform independent template.

/test includes LibDriver AHT20 driver test code and this code can test the chip necessary function simply.

/example includes LibDriver AHT20 sample code.

/doc includes LibDriver AHT20 offline document.

/datasheet includes AHT20 datasheet.

/project includes the common Linux and MCU development board sample code. All projects use the shell script to debug the driver and the detail instruction can be found in each project's README.md.

/misra includes the LibDriver MISRA code scanning results.

### Install

Reference /interface IIC platform independent template and finish your platform IIC driver.

Add the /src directory, the interface driver for your platform, and your own drivers to your project, if you want to use the default example drivers, add the /example directory to your project.

### Usage

You can refer to the examples in the /example directory to complete your own driver. If you want to use the default programming examples, here's how to use them.

#### example basic

```C
#include "driver_aht20_basic.h"

uint8_t res;
uint8_t i;
float temperature;
uint8_t humidity;

res = aht20_basic_init();
if (res != 0)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    aht20_interface_delay_ms(2000);
    res = aht20_basic_read((float *)&temperature, (uint8_t *)&humidity);
    if (res != 0)
    {
        (void)aht20_basic_deinit();

        return 1;
    }
    aht20_interface_debug_print("aht20: temperature is %0.2fC.\n", temperature);
    aht20_interface_debug_print("aht20: humidity is %d%%.\n", humidity); 
    
    ...
        
}

...

(void)aht20_basic_deinit();

return 0;
```

### Document

Online documents: [https://www.libdriver.com/docs/aht20/index.html](https://www.libdriver.com/docs/aht20/index.html).

Offline documents: /doc/html/index.html.

### Contributing

Please refer to CONTRIBUTING.md.

### License

Copyright (c) 2015 - present LibDriver All rights reserved



The MIT License (MIT) 



Permission is hereby granted, free of charge, to any person obtaining a copy

of this software and associated documentation files (the "Software"), to deal

in the Software without restriction, including without limitation the rights

to use, copy, modify, merge, publish, distribute, sublicense, and/or sell

copies of the Software, and to permit persons to whom the Software is

furnished to do so, subject to the following conditions: 



The above copyright notice and this permission notice shall be included in all

copies or substantial portions of the Software. 



THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR

IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,

FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE

AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER

LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,

OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE

SOFTWARE. 

### Contact Us

Please send an e-mail to lishifenging@outlook.com.