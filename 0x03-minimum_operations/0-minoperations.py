#!/usr/bin/python3
"""Minimum Operations
In a text file, there is a single character H. Your text editor can execute
only two operations in this file: Copy All and Paste. Given a number n, write
a method that calculates the fewest number of operations needed to result in
exactly n H characters in the file.
"""


def minOperations(n):
    """Find the least amount of operations to get to a specific amount of Hs"""
    counter = 1
    pastebin = 0
    operations = 0

    if n <= 0:
        return 0
    while counter != n:
        if n % counter == 0:
            pastebin = counter
            operations += 1
        counter = counter + pastebin
        operations += 1
    return operations
