
# Example: Check if a number is even or odd
try:
    num = int(input("Enter a number: "))
    if num % 2 == 0:
        print(num, "is even.")
    else:
        print(num, "is odd.")
except ValueError:
    print("Invalid input! Please enter a valid integer.")



