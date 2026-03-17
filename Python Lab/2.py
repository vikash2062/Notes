# Q.Print the multiplication table of a given number using a loop.

num = int(input("Enter a number: "))

for i in range(1, 11):
    print(f"{num} x {i} = {num * i}")