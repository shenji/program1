#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Book {
    string isbn;
    string title;
    string author;
    int year;
    string publisher;
};

void bubbleSort(vector<Book>& books) {
    int n = books.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (books[j].isbn > books[j + 1].isbn) {
                swap(books[j], books[j + 1]);
            }
        }
    }
}

int binarySearch(const vector<Book>& books, const string& key) {
    int left = 0;
    int right = books.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (books[mid].isbn == key) {
            return mid;
        } else if (books[mid].isbn < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    ifstream inputFile("books.txt");
    if (!inputFile) {
        cerr << "Failed to open the input file." << endl;
        return 1;
    }

    vector<Book> books;
    string line;
    while (getline(inputFile, line)) {
        Book book;
        book.isbn = line;
        getline(inputFile, book.title);
        getline(inputFile, book.author);
        inputFile >> book.year;
        inputFile.ignore();
        getline(inputFile, book.publisher);
        books.push_back(book);
    }
    inputFile.close();

    bubbleSort(books);

    string searchKey;
    cout << "Enter the ISBN number to find (or <enter> to quit): ";
    while (getline(cin, searchKey) && !searchKey.empty()) {
        int index = binarySearch(books, searchKey);
        if (index != -1) {
            const Book& foundBook = books[index];
            cout << "ISBN: " << foundBook.isbn << endl;
            cout << "Title: " << foundBook.title << endl;
            cout << "Author: " << foundBook.author << endl;
            cout << "Year: " << foundBook.year << endl;
            cout << "Publisher: " << foundBook.publisher << endl;
        } else {
            cout << "Book not found." << endl;
        }
        cout << "Enter the ISBN number to find (or <enter> to quit): ";
    }

    cout << "Exiting..." << endl;

    return 0;
}