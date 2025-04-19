#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <windows.h>

using namespace std;

class Hostel {
private:
    string Name;
    int Rent, Bed;

public:
    Hostel(string name, int rent, int bed) : Name(name), Rent(rent), Bed(bed) {}

    string getName() {
        return Name;
    }

    int getRent() {
        return Rent;
    }

    int getBed() {
        return Bed;
    }

    void reserve() {
        ifstream in("C:/Hostel.txt");
        ofstream out("C:/Hostel_Temp.txt");
        string line;

        while (getline(in, line)) {
            int pos = line.find("3star");
            if (pos != string::npos) {
                int bed = Bed - 1;
                Bed = bed;

                stringstream ss;
                ss << bed;
                string strBed = ss.str();

                int bedPos = line.find_last_of(':');
                line.replace(bedPos + 1, string::npos, strBed);
            }

            out << line << endl;
        }

        out.close();
        in.close();
        remove("C:/Hostel.txt");
        rename("C:/Hostel_Temp.txt", "C:/Hostel.txt");
        cout << "\tBed Reserved Successfully" << endl;
    }
};

class Student {
private:
    string Name, RollNo, Address;

public:
    Student() : Name(" "), RollNo(" "), Address(" ") {}

    void setName(const string& name) {
        Name = name;
    }

    void setRollNo(const string& rollno) {
        RollNo = rollno;
    }

    void setAddress(const string& address) {
        Address = address;
    }

    string getName() const {
        return Name;
    }

    string getRollNo() const {
        return RollNo;
    }

    string getAddress() const {
        return Address;
    }
};

int main() {
    Hostel h("3Star", 5000, 2);
    ofstream out("C:/Hostel.txt");
    out << "\t" << h.getName() << " : " << h.getRent() << " : " << h.getBed() << endl << endl;
    cout << "Hostel Data Saved" << endl;
    out.close();

    Student s;
    bool exit = false;

    while (!exit) {
        system("cls");
        int val;
        cout << "\nWelcome To Hostel Accommodation System" << endl;
        cout << "\n*************************************" << endl;
        cout << "\t1. Reserve a bed." << endl;
        cout << "\t2. Exit." << endl;
        cout << "\tEnter Choice: ";
        cin >> val;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        if (val == 1) {
            system("cls");
            string name, rollno, address;

            cout << "\tEnter Name Of Student: ";
            getline(cin, name);
            s.setName(name);

            cout << "\tEnter RollNo of Student: ";
            getline(cin, rollno);
            s.setRollNo(rollno);

            cout << "\tEnter Address of Student: ";
            getline(cin, address);
            s.setAddress(address);

            if (h.getBed() > 0) {
                h.reserve();
            } else {
                cout << "\tSorry, Bed Not Available" << endl;
            }

            ofstream outFile("C:/Student.txt", ios::app);
            outFile << "\t" << s.getName() << " : " << s.getRollNo() << " : " << s.getAddress() << endl << endl;
            outFile.close();

            Sleep(5000);
        } else if (val == 2) {
            system("cls");
            exit = true;
            cout << "Good Luck" << endl;
            Sleep(3000);
        }
    }

    return 0;
}
