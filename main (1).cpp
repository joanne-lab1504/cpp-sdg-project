#include <iostream>
#include "ChatbotManager.h"

using namespace std;

int main() {

    ChatbotManager chatbot;

    chatbot.loadFromFile();

    int choice;

    do {

        cout << "\n===== She4Tech AI Chatbot System =====\n";
        cout << "1. Start Chatbot\n";
        cout << "2. View Customer Inquiries (Admin)\n";
        cout << "3. Generate Summary Report (Admin)\n";
        cout << "4. Save Data\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {

            case 1:
                chatbot.chatbotConversation();
                break;

            case 2:
                if (chatbot.adminLogin()) {
                    chatbot.viewInquiries();
                }
                break;

            case 3:
                if (chatbot.adminLogin()) {
                    chatbot.generateReport();
                }
                break;

            case 4:
                chatbot.saveToFile();
                cout << "Data saved successfully!\n";
                break;

            case 5:
                chatbot.saveToFile();
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}