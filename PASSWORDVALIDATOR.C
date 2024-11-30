import re

def check_password_strength(password):
    # Criteria definitions
    min_length = 8
    uppercase_regex = r'[A-Z]'
    lowercase_regex = r'[a-z]'
    digit_regex = r'\d'
    special_char_regex = r'[!@#$%^&*(),.?":{}|<>]'

    # Check each criterion
    if len(password) < min_length:
        return "Password must be at least 8 characters long."
    if not re.search(uppercase_regex, password):
        return "Password must contain at least one uppercase letter."
    if not re.search(lowercase_regex, password):
        return "Password must contain at least one lowercase letter."
    if not re.search(digit_regex, password):
        return "Password must contain at least one digit."
    if not re.search(special_char_regex, password):
        return "Password must contain at least one special character (!@#$%^&*(), etc.)."

    return "Password meets all criteria."

# Example usage
password = input("Enter your password: ")
print(check_password_strength(password))
