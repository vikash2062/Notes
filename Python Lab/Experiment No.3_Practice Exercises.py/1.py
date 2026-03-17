# Q1: Write a function to check if a number is even or odd. 

# Function to check if a number is even or odd
def check_even_odd(num):
    if num % 2 == 0:
        return "Even"
    else:
        return "Odd"

# Example usage
number = int(input("Enter a number: "))
result = check_even_odd(number)
print(f"The number {number} is {result}.")
