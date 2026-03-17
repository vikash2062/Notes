# Q3:  Find the sum of all even numbers from 1 to 50 using a loop. 

# Initialize the sum
even_sum = 0

# Loop through numbers from 1 to 50
for i in range(1, 51):
    if i % 2 == 0:
        even_sum += i

# Print the result
print("Sum of all even numbers from 1 to 50 is:", even_sum)
