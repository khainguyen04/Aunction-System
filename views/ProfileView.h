#ifndef PROFILEVIEW_H
#define PROFILEVIEW_H

#include <vector>
#include "../models/Member.h"

class ProfileView {
public:
    // Submenu for all profile-related actions
    static void showProfileMenu(Member &currentMember, std::vector<Member> &allMembers);

private:
    // 1) Top Up Credit Points
    static void topUpCreditPoints(Member &currentMember);

    // 2) Update Profile Details
    static void updateProfileDetails(Member &currentMember);

    // 3) Change Password
    static void changePassword(Member &currentMember);

    // Helper to display current profile info
    static void displayCurrentProfile(const Member &member);
};

#endif
