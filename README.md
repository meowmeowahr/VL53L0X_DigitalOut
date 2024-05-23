# AutoLight VL53L0X over DigitalOut 

An alternate and simpler control system for AutoLight. Takes periodic readings from a VL53L0X sensor and outputs whether it is tripped to a Digital Pin. Recommended if you are running sensora over a long wire.

## Setup
* Install [VSCode](https://code.visualstudio.com/) and the [PlatformIO](https://platformio.org/) extension.
* Configure target Arduino device in `platformio.ini`

  Example targets

  | Board                             | ID               |
  |-----------------------------------|------------------|
  | Arduino Nano (New Bootloader)     | nanoatmega328new |
  | Arduino Nano (Old Bootloader)     | nanoatmega328    |
  | Arduino Pro Mini (Old Bootloader) | nanoatmega328    |

  A full list ia available at https://docs.platformio.org/en/latest/boards/
* Configure settings in `config.h`