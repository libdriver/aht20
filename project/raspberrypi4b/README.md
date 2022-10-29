### 1. Chip

#### 1.1 Chip Info

chip name : Raspberry Pi 4B.

iic pin: SCL/SDA GPIO3/GPIO2.

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

​          aht20 is a basic command which can test all aht20 driver function:

​           -h        show aht20 help 

​           -i         show aht20 chip and driver information.

​           -p       show aht20 pin connections of the current board.

​           -t read <times>        run aht20 read test. times means test times. 

​           -c read <times>        run aht20 read function. times means test times.

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
./aht20 -t read 3

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
aht20: temperature: 20.5C.
aht20: humidity: 51%.
aht20: temperature: 20.4C.
aht20: humidity: 50%.
aht20: temperature: 20.4C.
aht20: humidity: 49%.
aht20: finish read test.
```

```shell
./aht20 -c read 3

aht20: 1/3.
aht20: temperature is 26.61C.
aht20: humidity is 78%.
aht20: 2/3.
aht20: temperature is 27.76C.
aht20: humidity is 77%.
aht20: 3/3.
aht20: temperature is 28.59C.
aht20: humidity is 76%.
```

```shell
./aht20 -h

aht20 -h
	show aht20 help.
aht20 -i
	show aht20 chip and driver information.
aht20 -p
	show aht20 pin connections of the current board.
aht20 -t read <times>
	run aht20 read test.times means test times.
aht20 -c read <times>
	run aht20 read function.times means test times.
```

