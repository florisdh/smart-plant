# smart-plant
Automatic plant watering system using the ESP-12 (ESP8266).
- Does an hourly deep sleep to save power
- Starts pumping water every 24 sleep cycles using the attached water pump with a relay in between
- Restarts counter and cycle using a hard reboot

## Prerequisite
- https://github.com/esp8266/Arduino#installing-with-boards-manager
- https://platformio.org/platformio-ide

## Development
- Remove the connection between D0 and RTS
- Deploy the code using the platformio upload button

## TODO
- Add photos, part numbers, schema
- Plan improved version using remote config
