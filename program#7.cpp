#include <iostream>
#include <string>
#include <map>
using namespace std;

class emailContactList {
private:
    map<string, string> emailMap;

public:
    int getCount() {
        return emailMap.size();
    }

    void addAddress(const string name, const string address) {
        emailMap[name] = address;
        cout << "Added 1 entry (new total: " << getCount() << ")" << endl << endl;
    }

    void removeAddress(const string name) {
        if (emailMap.find(name) != emailMap.end()) {
            emailMap.erase(name);
            cout << "Deleted 1 entry (new total: " << getCount() << ")" << endl << endl;
        } else {
            cout << "No entry found with name: " << name << endl << endl;
        }
    }

    string searchByName(const string name) {
        if (emailMap.find(name) != emailMap.end()) {
            return emailMap[name];
        } else {
            return "";
        }
    }
};

int main() {
    emailContactList contacts;
    int choice;
    string name, address;

    do {
        cout << "Menu" << endl;
        cout << "----" << endl;
        cout << "1) Add an email address" << endl;
        cout << "2) Remove an email address" << endl;
        cout << "3) Search for an address with a name" << endl;
        cout << "4) Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                cout << "Enter the name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter their email address: ";
                getline(cin, address);
                cout << endl;
                contacts.addAddress(name, address);
                break;
            case 2:
                cout << "Enter the name to remove: ";
                cin.ignore();
                getline(cin, name);
                cout << endl;
                contacts.removeAddress(name);
                break;
            case 3:
                cout << "Enter the name to find: ";
                cin.ignore();
                getline(cin, name);
                cout << endl;
                address = contacts.searchByName(name);
                if (!address.empty()) {
                    cout << "Name: " << name << endl;
                    cout << "Address: " << address << endl << endl;
                } else {
                    cout << "No entry found with name: " << name << endl << endl;
                }
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl << endl;
        }
    } while (choice != 4);

    return 0;
}