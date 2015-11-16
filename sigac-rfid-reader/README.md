# SIGAC RFID Reader module

This module is used to read RFID tags and send them to the SIGAC main server.
These tags are used to identify people, each one being associated with one
person.

## Requirements

- [Requests library][2]  
- [RFID library][3] 

**Note**: The required file (MFRC522.py) from RFID library was copied here for
simplicity. It is necessary to install this library dependency, though. Check
the next section.

## Connections

With [this image][1] and the table below (from [the rfid lib][3]), it is easy to connect the cables.

| Name | Pin # | Pin name   |
|------|-------|------------|
| SDA  | 24    | GPIO8      |
| SCK  | 23    | GPIO11     |
| MOSI | 19    | GPIO10     |
| MISO | 21    | GPIO9      |
| IRQ  | None  | None       |
| GND  | Any   | Any Ground |
| RST  | 22    | GPIO25     |
| 3.3V | 1     | 3V3        |

## Installation

1. Clone the `MFRC522-python` dependency: https://github.com/lthiery/SPI-Py
1. Enter the cloned directory and run `sudo python setup.py install`
1. Install the `requests` library: `sudo pip install requests`
1. Clone this repo and cd into the created directory
1. Run `sudo python sigac-rfid-reader.py`

[1]: http://www.jameco.com/Jameco/workshop/circuitnotes/raspberry_pi_circuit_note_fig2a.jpg
[2]: http://docs.python-requests.org/en/latest/user/install/#install
[3]: https://github.com/mxgxw/MFRC522-python
