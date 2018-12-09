#!/usr/bin/env python3
import sys

if len(sys.argv) != 2:
    print("Missing command line argument\n", end="")
    sys.exit
k = sys.argv[1]
for i in range(len(k)):
    if k[i].isalpha() == 0:
        print("Nope")
        sys.exit
pt = input("plaintext:")
j = 0
m = len(k)
print("ciphertext:", end="")
for i in pt:
    j = j % m
    if i.isalpha():
        if i.islower() and k[j].islower():
            print("{}".format(chr((((ord(i) - 97) + (ord(k[j]) - 97)) % 26) + 97)), end="")
        elif i.isupper() and k[j].islower():
            print("{}".format(chr((((ord(i) - 65) + (ord(k[j]) - 97)) % 26) + 65)), end="")
        elif i.islower() and k[j].isupper():
            print("{}".format(chr((((ord(i) - 97) + (ord(k[j]) - 65)) % 26) + 97)), end="")
        elif i.isupper() and k[j].isupper():
            print("{}".format(chr((((ord(i) - 65) + (ord(k[j]) - 65)) % 26) + 65)), end="")
        j = j + 1
    else:
        print("{}".format(str(pt[i])), end="")
print()