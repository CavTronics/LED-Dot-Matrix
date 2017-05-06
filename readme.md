[![cavtronics logo](https://cldup.com/BhJv2ZU0rj.jpg)](http://www.cavtronics.com "cavtronics")

# The LED Dot Matrix display

## 

## Light Emitting Diode (LED) identification

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/f9/LED%2C_5mm%2C_green_%28en%29.svg/450px-LED%2C_5mm%2C_green_%28en%29.svg.png" alt="Drawing" style="width: 300px;"/>

Parts of a conventional LED. The flat bottom surfaces of the anvil and post embedded inside the epoxy act as anchors, to prevent the conductors from being forcefully pulled out via mechanical strain or vibration.


## Datasheets


## Identifying pin 1 on Matrix

## Libraries

## Matrix color types
### Monochrome
### Bi-Color
### Tri-color

## LED Dot Matrix sizes
### LED Dot Matrix 5x7
### LED Dot Matrix 8x8
### LED Dot Matrix 16x32
### LED Dot Matrix 8x32

#### Modifications  
There is a model that is a 4 in 1 that requires changes to the header file for it to operate correctly.
 
make changes to the file "MD_MAX72xx.h" located in "[username]/Arduino/libraries/MD_MAX72XX/src" to the following:

	#define	USE_PAROLA_HW	0

	#define	USE_FC16_HW	1
	

Ensure the pins from the 4 in 1 module is connected to the following pins on Arduino and adjust the parameter MAX_DEVICES to 4.

	// Define the number of devices we have in the chain and the hardware interface
	// NOTE: These pin numbers will probably not work with your hardware and may
	// need to be adapted
	#define MAX_DEVICES 4
	// Standard SPI connection
	#define CLK_PIN   13 // CLK
	#define DATA_PIN  11 // DIN	
	#define CS_PIN    10 // CS

### LED Array
### LED Cube

# Cascading

# Controlling Dot Matrix

## Direct control

## Using Integrated Circuits (IC)

### MAX7219

### 74hc595

### PCF8574T: Remote 8-bit I/O expander for I²C‑bus with interrupt

[nxp datasheet and Overview](http://www.nxp.com/products/interfaces/ic-bus-portfolio/ic-general-purpose-i-o/remote-8-bit-i-o-expander-for-icbus-with-interrupt:PCF8574T?fpsp=1&tab=Overview )


## Video 
[You Tube - Dot matrix Demo type 8x8 red](https://youtu.be/1OdQt88ySwY)

[Vimeo - matrix Demo type 8x8 red](https://vimeo.com/215792351)


# Fault Finding

# Circuit Diagram

# Using Adafruit Libraries

# Using your settings


#p.s:
I **LOVE** coffee! Buy me a coffee at:   

[![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=ZHBUNDXJXVW4U)



 