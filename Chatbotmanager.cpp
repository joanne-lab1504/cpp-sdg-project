#include "ChatbotManager.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

using namespace std;

// Typing Effect
void ChatbotManager::typingEffect(string text) {
    for (char c : text) {
        cout << c;
        this_thread::sleep_for(chrono::milliseconds(30));
    }
    cout << endl;
}

// Load File
void ChatbotManager::loadFromFile() {
    ifstream file("INPUT_DATA/inquiries.txt");

    string name, email;

    while (getline(file, name) && getline(file, email)) {
        inquiries.push_back(Inquiry(name, email));
    }

    file.close();
}

// Save File
void ChatbotManager::saveToFile() {
    ofstream file("INPUT_DATA/inquiries.txt");

    for (Inquiry inquiry : inquiries) {
        file << inquiry.getName() << endl;
        file << inquiry.getEmail() << endl;
    }

    file.close();
}

// Chatbot
void ChatbotManager::chatbotConversation() {
    string name, email, message;

    cout << "\n--- Chatbot Started ---\n";

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your email: ";
    getline(cin, email);

    if (name.empty() || email.empty()) {
        cout << "Invalid input!\n";
        return;
    }

    inquiries.push_back(Inquiry(name, email));

    typingEffect("Chatbot: Hello " + name + "! How can I assist you today?");

    do {
        cout << "You: ";
        getline(cin, message);

        if (message == "exit")
            break;

        typingEffect("Chatbot: " + generateBotResponse(message));

    } while (true);

    cout << "--- Chat Ended ---\n";
}

// Bot Response
string ChatbotManager::generateBotResponse(string input) {

    if (input.find("price") != string::npos ||
        input.find("cost") != string::npos) {

        return "Our pricing depends on your needs.";

    } else if (input.find("service") != string::npos) {

        return "We provide AI chatbot solutions.";

    } else if (input.find("help") != string::npos) {

        return "Sure! Tell me your concern.";

    } else {

        return "Please clarify your concern.";
    }
}

// View Inquiries
void ChatbotManager::viewInquiries() {

    if (inquiries.empty()) {
        cout << "No inquiries found.\n";
        return;
    }

    cout << "\n--- Customer Inquiries ---\n";

    for (int i = 0; i < inquiries.size(); i++) {

        cout << i + 1
             << ". Name: " << inquiries[i].getName()
             << " | Email: " << inquiries[i].getEmail()
             << endl;
    }
}

// Generate Report
void ChatbotManager::generateReport() {

    int count = inquiries.size();

    cout << "\n--- Summary Report ---\n";
    cout << "Total Inquiries: " << count << endl;

    if (count == 0)
        cout << "Engagement Level: None\n";

    else if (count <= 3)
        cout << "Engagement Level: Low\n";

    else if (count <= 7)
        cout << "Engagement Level: Moderate\n";

    else
        cout << "Engagement Level: High\n";
}

// Admin Login
bool ChatbotManager::adminLogin() {

    string password;

    cout << "Enter admin password: ";
    getline(cin, password);

    if (password == "admin123") {
        return true;
    }

    cout << "Access Denied!\n";
    return false;
}