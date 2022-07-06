#include <stdio.h>
#include <iostream>
using namespace std;

class Admin {
    private:
        string email, password;
    public:
        Admin CreateAccount(string, string);
        Admin Edit(string);
}