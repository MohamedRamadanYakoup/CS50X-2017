import sys

F = True
while F:
    n = int(input("Height: "))
    F = False
    if n <= 0 and n > 23:
        print("uncompitable Number from (1 to 23)")
        break
    if n > 0 and n <= 23:
        spaces = n
        for i in range(n):
            for j in range(i < n):
                print(" " * spaces, end="")
                spaces -= 1

            for hashs in range(i):
                print("#", end="")

            for j in range(i < n):
                print(" ", end="")

            for hashs in range(i):
                print("#", end="")
            print()