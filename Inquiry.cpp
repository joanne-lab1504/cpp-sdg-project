#include "Inquiry.h"

Inquiry::Inquiry() {
    name = "";
    email = "";
}

Inquiry::Inquiry(string n, string e) {
    name = n;
    email = e;
}

void Inquiry::setName(string n) {
    name = n;
}

void Inquiry::setEmail(string e) {
    email = e;
}

string Inquiry::getName() const {
    return name;
}

string Inquiry::getEmail() const {
    return email;
}