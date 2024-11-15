# Prerequisites
* Install [Arduino IDE](https://www.arduino.cc/en/software)
* Have an Arduino Pro Micro (Centipede)

# Setup
* Plug in your arduino pro micro
* Ensure it is selected in the IDE
* Paste in the `ChromeAutoEnrollV130.ino` from this repository
* Upload to the Arduino
  * NOTE: The Arduino will automatically start running the script after it is uploaded, You may want to unplug it after the upload finishes

# Using the autoenroll
* After a fresh install of Chrome os, before you boot the device up, make sure you have an ethernet cable connected with a known good internet connection
* Boot the chrome device for the first time
* Once you see the "Getting Started" screen, plug in the Arduino to usb
* Wait for the process to complete, then unplug
* Rinse and repeat

# Changing or adjusting the script
* You can prevent the script from automatically running, but shorting pin 2 to ground
* To make this easier, you can connect a Normally Open, Momentary switch between ping 2 and ground, so that you can hold the button while plugging in the arduino to put it into "Programming" mode
* The arduino will indicate it is in developer mode with 3 flashes in quick succession, followed by a 2 second pause, before repeating.
