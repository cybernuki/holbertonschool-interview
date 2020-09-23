#!/usr/bin/python3
"""
valid if a given array of data set represents a valid utf-8 encoding
"""


def validUTF8(data):
    """Validates if a given data is a correct utf-8 encode text """
    bytes = 0

    for byte in data:
        # Get the 8th first bits
        byte = byte & 0xFF

        if bytes:
            # Get the 2 most significant bits
            msb = byte >> 6
            # if msb has the combination of 11 or 01
            # Then char is malformed
            if (msb == 1 or msb == 3):
                return False
            bytes -= 1
            continue

        while 5 - bytes and byte & (1 << (7 - bytes)):
            bytes += 1
        if (bytes == 1 or bytes > 4):
            return False

    return False if bytes else True
