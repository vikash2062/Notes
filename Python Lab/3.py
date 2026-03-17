# Q.Find the sum of all even numbers from 1 to 50 using a loop.

sum = 0;

for i in range(1, 51):
    if(i%2==0):
        sum = sum+i;

print(sum)