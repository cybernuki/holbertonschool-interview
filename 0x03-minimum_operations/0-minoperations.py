#!/usr/bin/python3
# from math import sqrt


def minOperations(n):
    if n <= 1:
        return 0

    if (isPrime(n)):
        return n
    else:
        return sumPrimeFactors(n)


def isPrime(n):

    for i in range(2, int(sqrt(n)) + 1):
        if n % i == 0:
            return 0
    return 1


def sumPrimeFactors(n):
    sum = 0
    i = 2

    while n % i == 0:
        n //= i
        sum += i
    i = 3
    while n > 1:
        if n % i == 0:
            n //= i
            sum += i
        else:
            i += 2
        if n > 1 and isPrime(n):
            sum += n
            break

    return sum
