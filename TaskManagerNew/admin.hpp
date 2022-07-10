#include <stdio.h>
#include <iostream>
using namespace std;

class Admin {
    private:
        string email, password;
        uint32_t ID;
    public:
        Admin CreateAccount(string, string);
        void Login(string, string);
        void Edit(string);
        void Delete(string, string);
}