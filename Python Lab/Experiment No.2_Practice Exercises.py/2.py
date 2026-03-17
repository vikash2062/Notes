# Q2: Print the multiplication table of a given number using a loop. 

# Take user input
num = int(input("Enter a number  multiplication: "))

# Print the multiplication table
print(f"Multiplication Table of {num}:")
for i in range(1, 11):
    print(f"{num} x {i} = {num * i}")
