#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool issued;

    void addBook() {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        issued = false;
    }

    void display() {
        cout << "\nBook ID: " << id;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nStatus: " << (issued ? "Issued" : "Available") << endl;
    }
};

class Member {
public:
    int memberId;
    string name;

    void addMember() {
        cout << "Enter Member ID: ";
        cin >> memberId;
        cin.ignore();

        cout << "Enter Member Name: ";
        getline(cin, name);
    }
};

class Library {
    Book books[100];
    Member members[100];
    int bookCount = 0;
    int memberCount = 0;

public:

    void addBook() {
        books[bookCount].addBook();
        bookCount++;
        saveBooks();
        cout << "\nBook added successfully!\n";
    }

    void addMember() {
        members[memberCount].addMember();
        memberCount++;
        cout << "\nMember added successfully!\n";
    }

    void searchBook() {
        string key;
        cin.ignore();

        cout << "Enter title or author to search: ";
        getline(cin, key);

        bool found = false;

        for (int i = 0; i < bookCount; i++) {
            if (books[i].title.find(key) != string::npos ||
                books[i].author.find(key) != string::npos) {
                books[i].display();
                found = true;
            }
        }

        if (!found)
            cout << "\nBook not found.\n";
    }

    void issueBook() {
        int id;
        cout << "Enter Book ID to issue: ";
        cin >> id;

        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == id) {
                if (!books[i].issued) {
                    books[i].issued = true;
                    saveBooks();
                    cout << "\nBook issued successfully!\n";
                } else {
                    cout << "\nBook is already issued.\n";
                }
                return;
            }
        }

        cout << "\nBook not found.\n";
    }

    void returnBook() {
        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;

        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == id) {
                if (books[i].issued) {
                    books[i].issued = false;
                    saveBooks();
                    cout << "\nBook returned successfully!\n";
                } else {
                    cout << "\nBook was not issued.\n";
                }
                return;
            }
        }

        cout << "\nBook not found.\n";
    }

    void displayBooks() {
        if (bookCount == 0) {
            cout << "\nNo books available.\n";
            return;
        }

        for (int i = 0; i < bookCount; i++)
            books[i].display();
    }

    void saveBooks() {
        ofstream file("books.txt");

        for (int i = 0; i < bookCount; i++) {
            file << books[i].id << "|"
                 << books[i].title << "|"
                 << books[i].author << "|"
                 << books[i].issued << endl;
        }

        file.close();
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. Add Member";
        cout << "\n3. Search Book";
        cout << "\n4. Issue Book";
        cout << "\n5. Return Book";
        cout << "\n6. Display Books";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            library.addBook();
            break;

        case 2:
            library.addMember();
            break;

        case 3:
            library.searchBook();
            break;

        case 4:
            library.issueBook();
            break;

        case 5:
            library.returnBook();
            break;

        case 6:
            library.displayBooks();
            break;

        case 7:
            cout << "\nThank you!\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}
