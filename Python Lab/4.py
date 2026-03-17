# Q.Use a while loop to keep asking the user for a password until they enter "Python123".


while True:
    password = input("Enter password: ")
    if password == "123":
        print("Right Password")
        break
    else:
        print("Incorrect password")