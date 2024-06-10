#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool isGoodPassword(const string& password, const string commonPasswords[], int numCommonPasswords) {
    if (password.size() < 8)
        return false;

    bool hasUppercase = false;
    bool hasNumber = false;
    bool hasPunctuation = false;

    for (char ch : password) {
        if (isupper(ch))
            hasUppercase = true;
        else if (isdigit(ch))
            hasNumber = true;
        else if (ispunct(ch))
            hasPunctuation = true;
    }

    if (!hasUppercase || !hasNumber || !hasPunctuation)
        return false;

    if (binary_search(commonPasswords, commonPasswords + numCommonPasswords, password))
        return false;

    return true;
}

int main() {
    ifstream passwordFile("testpwd.txt");
    ifstream commonPasswordFile("200sorted.txt");

    string password;
    string commonPasswords[200];
    int numCommonPasswords = 0;

    while (getline(commonPasswordFile, password)) {
        commonPasswords[numCommonPasswords++] = password;
    }

    int goodCount = 0;
    int badCount = 0;

    while (getline(passwordFile, password)) {
        if (isGoodPassword(password, commonPasswords, numCommonPasswords))
            goodCount++;
        else
            badCount++;
    }

    cout << "Checked " << goodCount + badCount << " passwords." << endl;
    cout << "Good: " << goodCount << endl;
    cout << "Bad: " << badCount << endl;

    passwordFile.close();
    commonPasswordFile.close();

    return 0;
}

