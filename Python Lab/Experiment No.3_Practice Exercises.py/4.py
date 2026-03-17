# Q4: Implement a program to write a user’s input to a file until they enter "STOP". 

# Function to write user input to a file until "STOP" is entered
def write_to_file_until_stop(file_name):
    with open(file_name, 'a') as file:  # Open the file in append mode
        while True:
            user_input = input("Enter something (or type 'STOP' to stop): ")
            if user_input == "STOP":
                print("Stopping input and closing the file.")
                break
            else:
                file.write(user_input + "\n")  # Write input to the file

# Example usage
file_name = "user_input.txt"  # Replace with your desired file name
write_to_file_until_stop(file_name)
