#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Inquiry {
private:
    int id;
    string name;
    string message;

public:
    Inquiry(int i, string n, string m) {
        id = i;
        name = n;
        message = m;
    }

    int getId() {
        return id;
    }

    void display() {
        cout << "\nID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Inquiry: " << message << endl;
    }
};

class ChatbotManager {
private:
    vector<Inquiry> inquiries;

public:
    void addInquiry(Inquiry inquiry) {
        inquiries.push_back(inquiry);
    }

    void viewInquiries() {
        if (inquiries.empty()) {
            cout << "\nNo inquiries found.\n";
            return;
        }

        for (size_t i = 0; i < inquiries.size(); i++) {
            inquiries[i].display();
            cout << "----------------------" << endl;
        }
    }

    void searchInquiry(int id) {
        bool found = false;

        for (size_t i = 0; i < inquiries.size(); i++) {
            if (inquiries[i].getId() == id) {
                inquiries[i].display();
                found = true;
            }
        }

        if (!found) {
            cout << "\nInquiry not found.\n";
        }
    }
};

int main() {
    ChatbotManager manager;
    int choice;

    do {
        cout << "\n===== She4Tech SDG Inquiry System =====" << endl;
        cout << "1. Add Inquiry" << endl;
        cout << "2. View Inquiries" << endl;
        cout << "3. Search Inquiry" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid input.\n";
            continue;
        }

        switch (choice) {

        case 1: {
            int id;
            string name, message;

            cout << "Enter ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter Inquiry: ";
            getline(cin, message);

            Inquiry inquiry(id, name, message);

            manager.addInquiry(inquiry);

            cout << "\nInquiry added successfully.\n";
            break;
        }

        case 2:
            manager.viewInquiries();
            break;

        case 3: {
            int id;

            cout << "Enter Inquiry ID: ";
            cin >> id;

            manager.searchInquiry(id);
            break;
        }

        case 0:
            cout << "\nProgram Ended.\n";
            break;

        default:
            cout << "\nInvalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}