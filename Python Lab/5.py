# Q.Write a program that prints numbers from 1 to 10, but skips multiples of 3 using continue.

for i in range(1, 10  ):
    if i % 3 == 0:
        continue
    print(i)