# Q5: Write a Python function to count the number of words in a file. 

# Function to count the number of words in a file
def count_words_in_file(file_name):
    try:
        with open(file_name, 'r') as file:
            content = file.read()  # Read the entire content of the file
            words = content.split()  # Split content into words based on whitespace
            return len(words)  # Return the count of words
    except FileNotFoundError:
        print(f"The file {file_name} does not exist.")
        return 0

# Example usage
file_name = "example.txt"  # Replace with your file name
word_count = count_words_in_file(file_name)
print(f"The number of words in the file is: {word_count}")
