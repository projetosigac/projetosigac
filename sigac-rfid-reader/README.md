# SIGAC RFID Reader module

This module is used to read RFID tags and send them to the SIGAC main server.
These tags are used to identify people, each one being associated with one
person.

## Requirements

https://github.com/mxgxw/MFRC522-python

**Note**: The required file (MFRC522.py) was copied here for simplicity. It is
necessary to install this module dependency, though. Check the next section.

## Installation

1. Clone the `MFRC522-python` dependency: https://github.com/lthiery/SPI-Py.
2. Enter the cloned directory and run `sudo python setup.py install`.
3. Run `sudo python sigac-rfid-reader.py`
