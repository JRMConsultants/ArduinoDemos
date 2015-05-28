# ArduinoDemos
Demos using the Arduino Yun

## Note on Arduino Software Serial limitations

In my testing, I've found that Arduino Software Serial cannot reliably receive data at baud rates higher than 38400.
To change the baud rate on the Raspberry Pi, you will need to alter two files:
* `/boot/cmdline.txt`
* `/etc/inittab`
By default the Pi uses a baud rate of 115200; simply search for all occurrences of the string "115200" in these two
files and replace them with "38400."