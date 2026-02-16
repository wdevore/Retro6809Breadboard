# Lwasm

> lwasm -9 -f hex -la.list count.asm 

or for programming to ROM chip

> lwasm -9 -f raw count.asm 

then (optional)

> hexdump -C a.bin > a.txt

# Minipro
> minipro -p 'AT29C256@DIP28' -e -w a.bin

# Tenstar Robot Mega 2560
```
Microcontroller: ATmega2560-16AU
USB-to-Serial Chip: CH340G (requires drivers)
Operating Voltage: 5V
Input Voltage: 7-12V recommended (via DC jack)
Digital I/O Pins: 54 (15 provide PWM output)
Analog Input Pins: 16
Flash Memory: 256 KB
Clock Speed: 16 MHz
Interface: MicroUSB connector 
```

```
[719757.816769] ch341-uart ttyUSB0: ch341-uart converter now disconnected from ttyUSB0
[719757.816959] ch341 3-1.1.4:1.0: device disconnected
[719767.968086] usb 3-1.1.4: new full-speed USB device number 40 using xhci_hcd
[719768.053588] usb 3-1.1.4: New USB device found, idVendor=1a86, idProduct=7523, bcdDevice= 2.54
[719768.053594] usb 3-1.1.4: New USB device strings: Mfr=0, Product=2, SerialNumber=0
[719768.053596] usb 3-1.1.4: Product: USB2.0-Serial
[719768.061606] ch341 3-1.1.4:1.0: ch341-uart converter detected
[719768.062255] usb 3-1.1.4: ch341-uart converter now attached to ttyUSB0

```