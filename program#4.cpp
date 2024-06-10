#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void printPlaylist(string* playlist, int size) {
    cout << "Current Playlist:\n";
    cout << "----------------\n";
    for (int i = 0; i < size; i++) {
        cout << playlist[i] << endl;
    }
    cout << endl;
}

void shufflePlaylist(string* playlist, int size) {
    srand(time(0));
    for (int i = size - 1; i > 0; i--) {
        int swapidx = rand() % (i + 1);
        string tmp = playlist[i];
        playlist[i] = playlist[swapidx];
        playlist[swapidx] = tmp;
    }
    cout << "Shuffling...\n";
    printPlaylist(playlist, size);
}

int main() {
    string* playlist = nullptr;
    int size = 0;
    int choice;

    do {
        cout << "Menu\n";
        cout << "1) Create playlist\n";
        cout << "2) Shuffle playlist\n";
        cout << "3) Show playlist\n";
        cout << "4) Quit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                delete[] playlist;
                cout << "How many songs? ";
                cin >> size;
                playlist = new string[size];
                cout << "Created a new playlist of size " << size << endl;
                for (int i = 0; i < size; i++) {
                    cout << "Enter song # " << i + 1 << " to add: ";
                    cin >> playlist[i];
                }
                break;
            }
            case 2: {
                if (playlist != nullptr) {
                    shufflePlaylist(playlist, size);
                } else {
                    cout << "No playlist created yet!\n";
                }
                break;
            }
            case 3: {
                if (playlist != nullptr) {
                    printPlaylist(playlist, size);
                } else {
                    cout << "No playlist created yet!\n";
                }
                break;
            }
            case 4: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }

        cout << endl;

    } while (choice != 4);

    delete[] playlist;

    return 0;
}