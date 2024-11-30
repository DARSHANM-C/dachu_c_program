def convert_length():
    print("\nLength Conversion:")
    print("1. Kilometers to Meters")
    print("2. Meters to Kilometers")
    choice = input("Choose an option (1 or 2): ")
    
    if choice == '1':
        km = float(input("Enter distance in kilometers: "))
        meters = km * 1000
        print(f"{km} kilometers = {meters} meters")
    elif choice == '2':
        meters = float(input("Enter distance in meters: "))
        km = meters / 1000
        print(f"{meters} meters = {km} kilometers")
    else:
        print("Invalid choice")

def convert_weight():
    print("\nWeight Conversion:")
    print("1. Grams to Kilograms")
    print("2. Kilograms to Grams")
    choice = input("Choose an option (1 or 2): ")
    
    if choice == '1':
        grams = float(input("Enter weight in grams: "))
        kg = grams / 1000
        print(f"{grams} grams = {kg} kilograms")
    elif choice == '2':
        kg = float(input("Enter weight in kilograms: "))
        grams = kg * 1000
        print(f"{kg} kilograms = {grams} grams")
    else:
        print("Invalid choice")

def main():
    while True:
        print("\nUnit Converter")
        print("1. Length Conversion")
        print("2. Weight Conversion")
        print("3. Exit")
        choice = input("Choose an option (1-3): ")
        
        if choice == '1':
            convert_length()
        elif choice == '2':
            convert_weight()
        elif choice == '3':
            print("Exiting the program...")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
