#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
  private:
    string title;
    string author;
    int year;

  public:
    Book(string t, string a, int y) : title(t), author(a), year(y) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }

    void displayBook() const {
        cout << title << "\t\t" << author << "\t\t" << year << endl;
    }
};

class Library {
  private:
    vector<Book> books;

  public:
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book Added Successfully!" << endl;
    }

    void displayBooks() const {
        if (books.empty()) {
            cout << "No books in the library." << endl;
            return;
        }

        cout << "Book List:\nTitle\t\tAuthor\t\tYear" << endl;
        for (const auto& book : books) {
            book.displayBook();
        }
    }

    void searchBook(const string& title) const {
        for (const auto& book : books) {
            if (book.getTitle() == title) {
                cout << "Book found!" << endl;
                book.displayBook();
                return;
            }
        }
        cout << "Book not found!" << endl;
    }
};

int main() {
    Library library;
    int choice;
    string title, author;
    int year;

    do {
        cout << "\nMenu" << endl;
        cout << "1 - Add Book" << endl;
        cout << "2 - Display Books" << endl;
        cout << "3 - Search Book" << endl;
        cout << "4 - Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter Title: ";
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                cout << "Enter Year: ";
                cin >> year;
                library.addBook(Book(title, author, year));
                break;

            case 2:
                library.displayBooks();
                break;

            case 3:
                cout << "Enter a book title to search: ";
                getline(cin, title);
                library.searchBook(title);
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
