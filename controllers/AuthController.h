#ifndef AUTHCONTROLLER_H
#define AUTHCONTROLLER_H

#include <string>
#include <vector>
#include "../models/Member.h"

class AuthController {
public:
    AuthController();
    
    // Returns true if login successful, false otherwise
    bool login(std::vector<Member>& members, const std::string& username, const std::string& password);
    
    // Returns true if registration is successful, false otherwise
    bool registerMember(std::vector<Member>& members, const Member& newMember);
};

#endif
