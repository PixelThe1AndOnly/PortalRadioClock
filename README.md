# Portal Radio Clock

![React Version](https://img.shields.io/badge/release-v1.0.0-blue.svg)


#### Description
This project is a replica of the radio from Portal that displays the time in an arch.

## Table of content

- [**Getting Started**](#getting-started)
- [Built With](#built-with)
- [Contributing](#contributing)
- [Get Help](#get-help)
- [Motivation](#motivation)
- [Acknowledgments](#acknowledgements)

## Getting Started
#### Environnment Preperation
1. Using Arduino IDE Boards Manager
	- [Instructions for Boards Manager](https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/boards_manager.md)
2. Libraries that are used in the project need to be added through the Library Manager. (Include Library)
	- Some of the libraries can be installed through Manage Libraries in the Include Library section under the Sketch tab.
	- The libraries can also be installed through Add .ZIP Libraries in the Include Library section under the Sketch tab.
3. Modifications need to be made to the TFT_eSPI.cpp file to allow it to work with other display drivers and display types.
4. The project needs a WiFi connection in order to get the time. The SSID and Password need to be added.
```c++
const char *ssid     = "<SSID>";
const char *password = "<PASSWORD>";
```
5. The project needs the server pool for your region as well as the time from UTC (Coordinated Universal Time)
```c++
// You can specify the time server pool and the offset (in seconds, can be
// changed later with setTimeOffset() ). Additionaly you can specify the
// update interval (in milliseconds, can be changed using setUpdateInterval() ).
NTPClient timeClient(ntpUDP, "north-america.pool.ntp.org", -25200, 60000);
```
6. The .STL files can be found here. some modifications need to be made after printing in order to duplicate project.
	- [STL files](https://www.thingiverse.com/thing:4705587)

## Built With

- Arduino IDE
>It may be possible to use another IDE.

- ESP32
- 1.8" TFT LCD display with spi interface.
>Display used had ST7735 driver.
- Google nest mini gen 2
>Does not interact with code but is used in the project.

## Contributing

#### Issues
In the case of a bug report, bugfix or a suggestions, please feel very free to open an issue.

#### Pull request
Pull requests are always welcome, and I'll do my best to do reviews as fast as I can.

## Get Help
- If appropriate, [open an issue](https://github.com/PixelThe1AndOnly/PortalRadioClock/issues) on GitHub

## Motivation
I have always wanted to make my own alarm clock and I felt that making the alarm clock look like the radio from Portal would be nice. I decided to make it as a present for my brother. I had to scale down my original idea for the sake of time.

## Acknowledgements
- [Arduino-esp32](https://github.com/espressif/arduino-esp32)
- [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI)
- [TFT_eFEX](https://github.com/Bodmer/TFT_eFEX)
- [NTPClient](https://github.com/arduino-libraries/NTPClient)
- [JPEGDecoder](https://github.com/Bodmer/JPEGDecoder)
- [Adafruit-ST7735-Library](https://github.com/adafruit/Adafruit-ST7735-Library)
>Some libraries may not be used or be the correct library so let me know if it isn't working.
>There may also be some libraries that I missed so please let me know if something isn't working.





