### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

IIC Pin: SCL/SDA GPIO3/GPIO2.

### 2. Install

#### 2.1 Dependencies

Install the necessary dependencies.

```shell
sudo apt-get install libgpiod-dev pkg-config cmake -y
```

#### 2.2 Makefile

Build the project.

```shell
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

#### 2.3 CMake

Build the project.

```shell
mkdir build && cd build 
cmake .. 
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

Test the project and this is optional.

```shell
make test
```

Find the compiled library in CMake. 

```cmake
find_package(aht20 REQUIRED)
```

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
./aht20 -i

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
./aht20 -p

aht20: SCL connected to GPIO3(BCM).
aht20: SDA connected to GPIO2(BCM).
```

```shell
./aht20 -t read --times=3

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
aht20: temperature: 27.7C.
aht20: humidity: 24%.
aht20: temperature: 27.6C.
aht20: humidity: 24%.
aht20: temperature: 27.6C.
aht20: humidity: 24%.
aht20: finish read test.
```

```shell
./aht20 -e read --times=3

aht20: 1/3.
aht20: temperature is 27.67C.
aht20: humidity is 23%.
aht20: 2/3.
aht20: temperature is 27.66C.
aht20: humidity is 23%.
aht20: 3/3.
aht20: temperature is 27.68C.
aht20: humidity is 23%.
```

```shell
./aht20 -h

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

