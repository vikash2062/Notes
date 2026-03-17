# Q4: Use a while loop to keep asking the user for a password until they enter "Python123".

# Initialize the password variable
password = ""

# Keep asking until the correct password is entered
while password != "Python123":
    password = input("Enter the password: ")

print("Access granted!")
