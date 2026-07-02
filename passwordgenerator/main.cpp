#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

string generatePassword(int length) {
    const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()";
    string password;
    srand(time(0));
    for (int i = 0; i < length; ++i) {
        password += characters[rand() % characters.length()];
    }
    return password;
}

int main() {
    int passwordLength = 10;
    string newPassword = generatePassword(passwordLength);
    cout << "Generated Password: " << newPassword << endl;
    return 0;
}
