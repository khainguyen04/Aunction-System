#ifndef AUTHVIEW_H
#define AUTHVIEW_H

#include <vector>
#include "../models/Member.h"

class AuthView {
public:
    static void showLoginMenu(std::vector<Member>& members);

    // ADD THESE:
    static void showRegularLoginScreen(std::vector<Member>& members);
    static void showAdminLoginScreen(std::vector<Member>& members);

    static void showRegisterScreen(std::vector<Member>& members);
};

#endif
