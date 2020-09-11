#!/usr/bin/python3
"""
Write a script that reads stdin line by line and computes metrics:
"""
import sys


counters = {
    "size": 0,
    "lines": 1
}

contCode = {
    "200": 0, "301": 0, "400": 0, "401": 0,
    "403": 0, "404": 0, "405": 0, "500": 0
}


def printCodes():
    """
    function print the codes and the number
    """
    # print file size
    print("File size: {}".format(counters["size"]))
    # print all codes
    for key in sorted(contCode.keys()):
        # if a val is not 0
        if contCode[key] != 0:
            print("{}: {}".format(key, contCode[key]))


def countCodeSize(listData):
    """
    count the codes and file size
    """
    # count file size
    counters["size"] += int(listData[-1])
    # if exists
    if listData[-2] in contCode:
        # count status code
        contCode[listData[-2]] += 1


if __name__ == "__main__":
    try:
        for line in sys.stdin:
            try:
                countCodeSize(line.split(" "))
            except:
                pass
            if counters["lines"] % 10 == 0:
                printCodes()
            counters["lines"] += 1
    except KeyboardInterrupt:
        printCodes()
        raise
    printCodes()
