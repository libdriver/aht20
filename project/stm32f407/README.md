### 1. Chip

#### 1.1 Chip Info

Chip Name: STM32F407ZGT6.

Extern Oscillator: 8MHz.

UART Pin: TX/RX PA9/PA10.

IIC Pin: SCL/SDA PB8/PB9.

### 2. Development and Debugging

#### 2.1 Integrated Development Environment

LibDriver provides both Keil and IAR integrated development environment projects.

MDK is the Keil ARM project and your Keil version must be 5 or higher.Keil ARM project needs STMicroelectronics STM32F4 Series Device Family Pack and you can download from https://www.keil.com/dd2/stmicroelectronics/stm32f407zgtx.

EW is the IAR ARM project and your IAR version must be 9 or higher.

#### 2.2 Serial Port Parameter

Baud Rate: 115200.

Data Bits : 8.

Stop Bits: 1.

Parity: None.

Flow Control: None.

#### 2.3 Serial Port Assistant

We use '\n' to wrap lines.If your serial port assistant displays exceptions (e.g. the displayed content does not divide lines), please modify the configuration of your serial port assistant or replace one that supports '\n' parsing.

### 3. AHT20

#### 3.1 Command Instruction

1. Show aht20 chip and driver information.

   ```shell
   aht20 (-i | --information)
   ```

2. Show aht20 help.

   ```shell
   aht20 (-h | --help)
   ```

3. Show aht20 pin connections of the current board.

   ```shell
   aht20 (-p | --port)
   ```

4. Run aht20 read test, num means test times.

   ```shell
   aht20 (-t read | --test=read) [--times=<num>]
   ```

5. Run aht20 read function, num means test times.

   ```shell
   aht20 (-e read | --example=read) [--times=<num>]
   ```

#### 3.2 Command Example

```shell
aht20 -i

aht20: chip is ASAIR AHT20.
aht20: manufacturer is ASAIR.
aht20: interface is IIC.
aht20: driver version is 1.0.
aht20: min supply voltage is 2.2V.
aht20: max supply voltage is 5.5V.
aht20: max current is 0.98mA.
aht20: max temperature is 85.0C.
aht20: min temperature is -40.0C.
```

```shell
aht20 -p

aht20: SCL connected to GPIOB PIN8.
aht20: SDA connected to GPIOB PIN9.
```

```shell
aht20 -t read --times=3

aht20: chip is ASAIR AHT20.
aht20: manufacturer is ASAIR.
aht20: interface is IIC.
aht20: driver version is 1.0.
aht20: min supply voltage is 2.2V.
aht20: max supply voltage is 5.5V.
aht20: max current is 0.98mA.
aht20: max temperature is 85.0C.
aht20: min temperature is -40.0C.
aht20: start read test.
aht20: temperature: 31.5C.
aht20: humidity: 21%.
aht20: temperature: 31.3C.
aht20: humidity: 21%.
aht20: temperature: 31.2C.
aht20: humidity: 20%.
aht20: finish read test.
```

```shell
aht20 -e read --times=3

aht20: 1/3.
aht20: temperature is 30.16C.
aht20: humidity is 21%.
aht20: 2/3.
aht20: temperature is 30.10C.
aht20: humidity is 21%.
aht20: 3/3.
aht20: temperature is 30.05C.
aht20: humidity is 21%.
```

```shell
aht20 -h

Usage:
  aht20 (-i | --information)
  aht20 (-h | --help)
  aht20 (-p | --port)
  aht20 (-t read | --test=read) [--times=<num>]
  aht20 (-e read | --example=read) [--times=<num>]

Options:
  -e <read>, --example=<read>    Run the driver example.
  -h, --help                     Show the help.
  -i, --information              Show the chip information.
  -p, --port                     Display the pin connections of the current board.
  -t <read>, --test=<read>       Run the driver test.
      --times=<num>              Set the running times.([default: 3])
```

