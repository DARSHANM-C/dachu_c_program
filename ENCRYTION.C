def caesar_cipher(text, shift):
    """Encrypt or decrypt text using a Caesar cipher."""
    result = ""
    for char in text:
        if char.isalpha():  # Process only alphabetical characters
            shift_base = ord('A') if char.isupper() else ord('a')
            shifted_char = chr((ord(char) - shift_base + shift) % 26 + shift_base)
            result += shifted_char
        else:
            result += char  # Leave non-alphabet characters unchanged
    return result

def encrypt_file(input_file, output_file, shift):
    """Encrypt the contents of a file using a Caesar cipher."""
    with open(input_file, 'r') as file:
        plaintext = file.read()
    encrypted_text = caesar_cipher(plaintext, shift)
    with open(output_file, 'w') as file:
        file.write(encrypted_text)
    print(f"File '{input_file}' encrypted successfully to '{output_file}'.")

def decrypt_file(input_file, output_file, shift):
    """Decrypt the contents of a file using a Caesar cipher."""
    # Decryption is just encryption with the negative shift
    encrypt_file(input_file, output_file, -shift)

# Example usage
if __name__ == "__main__":
    choice = input("Do you want to (E)ncrypt or (D)ecrypt a file? ").lower()
    input_file = input("Enter the input file name: ")
    output_file = input("Enter the output file name: ")
    shift = int(input("Enter the shift value (e.g., 3): "))

    if choice == 'e':
        encrypt_file(input_file, output_file, shift)
    elif choice == 'd':
        decrypt_file(input_file, output_file, shift)
    else:
        print("Invalid choice. Please enter 'E' for encryption or 'D' for decryption.")
