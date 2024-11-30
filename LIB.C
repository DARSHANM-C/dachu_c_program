import csv

FILE_NAME = 'books.csv'

# Initialize CSV file with headers
def initialize_file():
    try:
        with open(FILE_NAME, 'x', newline='') as file:
            writer = csv.writer(file)
            writer.writerow(['ID', 'Title', 'Author', 'Year'])
    except FileExistsError:
        pass  # File already exists

# Display menu
def display_menu():
    print("\nBook Record Management")
    print("1. Add Book")
    print("2. View Books")
    print("3. Update Book")
    print("4. Delete Book")
    print("5. Search Book")
    print("6. Exit")

# Add a book record
def add_book():
    book_id = input("Enter Book ID: ")
    title = input("Enter Book Title: ")
    author = input("Enter Author: ")
    year = input("Enter Publication Year: ")

    with open(FILE_NAME, 'a', newline='') as file:
        writer = csv.writer(file)
        writer.writerow([book_id, title, author, year])
    print("Book added successfully.")

# View all books
def view_books():
    try:
        with open(FILE_NAME, 'r') as file:
            reader = csv.reader(file)
            books = list(reader)
            if len(books) == 1:
                print("No books found.")
                return
            for book in books:
                print(book)
    except FileNotFoundError:
        print("No records found. Add books first.")

# Update book details
def update_book():
    book_id = input("Enter Book ID to update: ")
    updated_data = []
    found = False

    with open(FILE_NAME, 'r') as file:
        reader = csv.reader(file)
        books = list(reader)

    for row in books:
        if row[0] == book_id:
            print(f"Current Data: {row}")
            row[1] = input("Enter new Title: ") or row[1]
            row[2] = input("Enter new Author: ") or row[2]
            row[3] = input("Enter new Year: ") or row[3]
            found = True
        updated_data.append(row)

    if found:
        with open(FILE_NAME, 'w', newline='') as file:
            writer = csv.writer(file)
            writer.writerows(updated_data)
        print("Book updated successfully.")
    else:
        print("Book ID not found.")

# Delete a book
def delete_book():
    book_id = input("Enter Book ID to delete: ")
    updated_data = []
    found = False

    with open(FILE_NAME, 'r') as file:
        reader = csv.reader(file)
        books = list(reader)

    for row in books:
        if row[0] == book_id:
            print(f"Deleting: {row}")
            found = True
        else:
            updated_data.append(row)

    if found:
        with open(FILE_NAME, 'w', newline='') as file:
            writer = csv.writer(file)
            writer.writerows(updated_data)
        print("Book deleted successfully.")
    else:
        print("Book ID not found.")

# Search for a book
def search_book():
    query = input("Enter title or author to search: ").lower()
    with open(FILE_NAME, 'r') as file:
        reader = csv.reader(file)
        next(reader)  # Skip headers
        found_books = [row for row in reader if query in row[1].lower() or query in row[2].lower()]

    if found_books:
        for book in found_books:
            print(book)
    else:
        print("No matching books found.")

# Main function
def main():
    initialize_file()
    while True:
        display_menu()
        choice = input("Enter your choice: ")
        if choice == '1':
            add_book()
        elif choice == '2':
            view_books()
        elif choice == '3':
            update_book()
        elif choice == '4':
            delete_book()
        elif choice == '5':
            search_book()
        elif choice == '6':
            print("Exiting program.")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == '__main__':
    main()
