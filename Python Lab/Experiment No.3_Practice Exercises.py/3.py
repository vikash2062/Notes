# Q3:Write a function that reads a file and prints only the first 5 lines. 


def print_first_5_lines(file_name):
    try:
        with open(file_name, 'r') as file:
            
            for i in range(5):
                line = file.readline()
                if line:  
                    print(line.strip())  
                else:
                    break  
    except FileNotFoundError:
        print(f"The file {file_name} does not exist.")


file_name = "hello.txt"  
print_first_5_lines(file_name)
