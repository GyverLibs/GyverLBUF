This is an automatic translation, may be incorrect in some places. See sources and examples!

# Gyverlbuf
Linear buffer for Arduino
- Keeps and gives access to the latter n records
- can be used for:
    - approximation according to the latter n measurements
    - search for the difference between the current and the last in the buffer
- Static size
- Type of data type

## compatibility
Compatible with all arduino platforms (used arduino functions)

## Content
- [installation] (# Install)
- [initialization] (#init)
- [use] (#usage)
- [Example] (# Example)
- [versions] (#varsions)
- [bugs and feedback] (#fedback)

<a id="install"> </a>
## Installation
- The library can be found by the name ** gyverlbuf ** and installed through the library manager in:
    - Arduino ide
    - Arduino ide v2
    - Platformio
- [download the library] (https://github.com/gyverlibs/gyverlbuf/archive/refs/heads/main.zip) .Zip archive for manual installation:
    - unpack and put in * C: \ Program Files (X86) \ Arduino \ Libraries * (Windows X64)
    - unpack and put in * C: \ Program Files \ Arduino \ Libraries * (Windows X32)
    - unpack and put in *documents/arduino/libraries/ *
    - (Arduino id) Automatic installation from. Zip: * sketch/connect the library/add .Zip library ... * and specify downloaded archive
- Read more detailed instructions for installing libraries [here] (https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%BD%D0%BE%BE%BE%BED0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)
### Update
- I recommend always updating the library: errors and bugs are corrected in the new versions, as well as optimization and new features are added
- through the IDE library manager: find the library how to install and click "update"
- Manually: ** remove the folder with the old version **, and then put a new one in its place.“Replacement” cannot be done: sometimes in new versions, files that remain when replacing are deleted and can lead to errors!


<a id="init"> </a>
## initialization
`` `CPP
Gyverlbuf <data type, buffer size> buf;
// Type of data: any.byte/int/float ...
// buffer size: the code is executed faster with the size of the buffer, a multiple of the degree of deuces (2, 4, 8, 16, 32 ...)
`` `

<a id="usage"> </a>
## Usage
`` `CPP
// type - specified in the initialization of the data type
VOID Write (Type NewVal);// Add to the buffer
VOID Write (Int Num, Type Val);// entry in the buffer by num number
Type Read (int num);// Reading from the buffer
int size ();// buffer size
`` `

<a id="EXAMPLE"> </a>
## Example
The rest of the examples look at ** Examples **!
`` `CPP
#include <gyverlbuf.h>
Gyverlbuf <int, 8> buf;
// Type of data: any.byte/int/float ...
// buffer size: the code is executed faster at
// the size of the buffer, a multiple of the degree of deuces (2, 4, 8, 16, 32 ...)

VOID setup () {
  Serial.Begin (9600);

  for (int i = 0; i <12; i ++) {
    buf.write (i);
    for (int j = 0; j <8; j ++) {
      Serial.print (buf.read (j));
      Serial.print (',');
    }
    Serial.println ();
  }

  /*
    0.0.0.0.0.0.0.0,
    0.0,0,0,0,0,0,1,
    0.0,0,0,0,0,1,2,
    0.0,0,0,0,1,2,3,
    0.0,0,0,1,2,3,4,
    0.0,0,1,2,3,4,5,
    0.0.1,2,3,4,5,6,
    0.1,2,3,4,5,6,7,
    1.2,3,4,5,6,7,8,
    2.3,4,5,6,7,8,9,
    3.4,5,6,7,8,9,10,
    4,5,6,7,8,9,10,11,
  */
}

VOID loop () {
}
`` `

<a ID= "Versions"> </a>
## versions
- V1.0

<a id="feedback"> </a>
## bugs and feedback
Create ** Issue ** when you find the bugs, and better immediately write to the mail [alex@alexgyver.ru] (mailto: alex@alexgyver.ru)
The library is open for refinement and your ** pull Request ** 'ow!


When reporting about bugs or incorrect work of the library, it is necessary to indicate:
- The version of the library
- What is MK used
- SDK version (for ESP)
- version of Arduino ide
- whether the built -in examples work correctly, in which the functions and designs are used, leading to a bug in your code
- what code has been loaded, what work was expected from it and how it works in reality
- Ideally, attach the minimum code in which the bug is observed.Not a canvas of a thousand lines, but a minimum code