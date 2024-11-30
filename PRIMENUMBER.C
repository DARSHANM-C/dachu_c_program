def is_prime(n):
    """Check if a number is prime."""
    if n <= 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True

def find_primes_in_range(start, end):
    """Find all prime numbers in a given range."""
    primes = [num for num in range(start, end + 1) if is_prime(num)]
    return primes

def save_primes_to_file(primes, filename):
    """Save a list of prime numbers to a file."""
    with open(filename, 'w') as file:
        for prime in primes:
            file.write(f"{prime}\n")

# Example usage:
if __name__ == "__main__":
    start_range = int(input("Enter the start of the range: "))
    end_range = int(input("Enter the end of the range: "))
    
    primes = find_primes_in_range(start_range, end_range)
    print(f"Found {len(primes)} prime numbers.")

    filename = "prime_numbers.txt"
    save_primes_to_file(primes, filename)
    print(f"Prime numbers saved to {filename}.")
