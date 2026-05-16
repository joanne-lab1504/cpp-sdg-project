#ifndef CHATBOTMANAGER_H
#define CHATBOTMANAGER_H

#include <vector>
#include "Inquiry.h"

class ChatbotManager {
private:
    vector<Inquiry> inquiries;

public:
    void chatbotConversation();
    string generateBotResponse(string input);

    void viewInquiries();
    void generateReport();

    bool adminLogin();

    void saveToFile();
    void loadFromFile();

    void typingEffect(string text);
};

#endif