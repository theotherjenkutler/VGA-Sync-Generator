# VGA Sync Generator for Arduino


Tested on the Sparkfun Pro Micro 16MHz 5V version but should work with any Leonardo based board.


Hardware connections:

- Pin 9 outputs H sync
- Pin 5 outputs V sync
- Make sure at least one GND pin is connected to the GND rail of the VGA jack


For instructions to upload to your SparkFun Pro Micro 5V 16MHz board:
- https://support.arduino.cc/hc/en-us/articles/4733418441116-Upload-a-sketch-in-Arduino-IDE


Instructions to add board definitions for Sparkfun Pro Micro 5V board:

- In the Arduino IDE go to preferences.</br>
- In the "Additional Boards Manager URLs" text entry box paste:

```
https://raw.githubusercontent.com/sparkfun/Arduino_Boards/main/IDE_Board_Manager/package_sparkfun_index.json
```

- Click "OK"
- In the main Arduino IDE window select the second tab from the top - the boards manager icon.
- Select "Sparkfun AVR Boards" and click "Install"
