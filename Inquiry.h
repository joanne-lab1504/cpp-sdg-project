#ifndef INQUIRY_H
#define INQUIRY_H

#include <string>
using namespace std;

class Inquiry {
private:
    string name;
    string email;

public:
    Inquiry();
    Inquiry(string n, string e);

    void setName(string n);
    void setEmail(string e);

    string getName() const;
    string getEmail() const;
};

#endif