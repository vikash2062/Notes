# Q5: Write a program that prints numbers from 1 to 10, but skips multiples of 3 using continue. 

# Loop from 1 to 10
for i in range(1, 11):
    if i % 3 == 0:
        continue  # Skip multiples of 3
    print(i)
