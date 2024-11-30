# Define an empty dictionary to store student information
students = {}

# Function to add a new student
def add_student():
    roll_number = input("Enter roll number: ")
    if roll_number in students:
        print("Student with this roll number already exists.")
        return
    name = input("Enter student's name: ")
    marks = float(input("Enter student's marks: "))
    students[roll_number] = {'Name': name, 'Marks': marks}
    print(f"Student {name} added successfully!\n")

# Function to display all students
def display_students():
    if not students:
        print("No student records available.\n")
        return
    print("Student Records:")
    for roll, info in students.items():
        print(f"Roll Number: {roll}, Name: {info['Name']}, Marks: {info['Marks']}")
    print()

# Function to search for a student by roll number
def search_student():
    roll_number = input("Enter roll number to search: ")
    if roll_number in students:
        info = students[roll_number]
        print(f"Student Found: Roll Number: {roll_number}, Name: {info['Name']}, Marks: {info['Marks']}\n")
    else:
        print("Student not found.\n")

# Menu-driven program
def main():
    while True:
        print("1. Add Student")
        print("2. Display All Students")
        print("3. Search Student by Roll Number")
        print("4. Exit")
        choice = input("Enter your choice: ")

        if choice == '1':
            add_student()
        elif choice == '2':
            display_students()
        elif choice == '3':
            search_student()
        elif choice == '4':
            print("Exiting the program. Goodbye!")
            break
        else:
            print("Invalid choice, please try again.\n")

# Run the main function
if __name__ == "__main__":
    main()
