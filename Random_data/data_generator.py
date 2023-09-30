import random

# Function to generate a random 512-byte hexadecimal string
def generate_hex_string():
    return ''.join(random.choice('0123456789abcdef') for _ in range(512))

# Generate 100 different strings
data_strings = [generate_hex_string() for _ in range(1500)]

# Combine the strings with commas
data_combined = ','.join(data_strings)

# Save the data to a file
with open('hexadecimal_data.txt', 'w') as file:
    file.write(data_combined)

print("Data has been saved to 'hexadecimal_data.txt'")