#!/usr/bin/python3
"""Minimum Operations
"""


def minOperations(n):
    """minOperations"""
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
