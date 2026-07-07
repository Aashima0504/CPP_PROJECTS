#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void Green() {
    cout << "\033[0;32m";
}

void ResetTextColor() {
    cout << "\033[0m";
}

class Authentication {
private:
    string userName;
    string password;
    string fullName;
    string emailId;

public:
    void login() {
        string uName;
        string pass;

        cout << "Login Tab....!" << endl;
        cout << "--------------------------" << endl;

        cout << "Enter user-Name : ";
        getline(cin, uName);

        cout << "Enter Password : ";
        getline(cin, pass);

        cout << "--------------------------" << endl;

        ifstream fin(uName + ".txt");

        if (fin.is_open()) {
            if (getline(fin, fullName) &&
                getline(fin, emailId) &&
                getline(fin, userName) &&
                getline(fin, password)) {

                if (password == pass) {
                    Green();
                    cout << "Login Successful!" << endl;
                    ResetTextColor();
                } else {
                    cout << "Invalid Password" << endl;
                }
            }
            fin.close();
        } else {
            cout << "Wrong Username" << endl;
        }
    }

    void registration() {
        cout << "Registration Tab....!" << endl;
        cout << "--------------------------" << endl;

        cout << "Enter Full Name : ";
        getline(cin, fullName);

        cout << "Enter Email Id : ";
        getline(cin, emailId);

        cout << "Enter user-Name : ";
        getline(cin, userName);

        ifstream check(userName + ".txt");
        if (check.is_open()) {
            cout << "Username already exists!" << endl;
            check.close();
            return;
        }

        cout << "Enter Password : ";
        getline(cin, password);

        cout << "--------------------------" << endl;

        ofstream fout(userName + ".txt");

        if (fout.is_open()) {
            fout << fullName << "\n";
            fout << emailId << "\n";
            fout << userName << "\n";
            fout << password << "\n";

            fout.close();

            system("clear");

            cout << "-------------------------------" << endl;
            Green();
            cout << "Registration Completed Successfully!" << endl;
            ResetTextColor();

            cout << "Username : ";
            Green();
            cout << userName << endl;
            ResetTextColor();

            cout << "Password : ";
            Green();
            cout << password << endl;
            ResetTextColor();
        } else {
            cout << "Registration Failed!" << endl;
        }
    }
};

int main() {
    Authentication a1;

    while (true) {
        int x;

        cout << "\n==============================" << endl;
        cout << "1. Login" << endl;
        cout << "2. Registration" << endl;
        cout << "3. Exit" << endl;
        cout << "==============================" << endl;
        cout << "Enter Choice : ";

        cin >> x;
        cin.ignore();

        switch (x) {
        case 1:
            a1.login();
            break;

        case 2:
            a1.registration();
            break;

        case 3:
            cout << "Thank You!" << endl;
            return 0;

        default:
            cout << "Invalid Choice!" << endl;
        }
    }

    return 0;
}