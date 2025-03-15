#ifndef MEMBERVIEW_H
#define MEMBERVIEW_H

#include <vector>
#include "../models/Member.h"

class MemberView {
public:
    static void showMemberMenu(Member &currentMember, std::vector<Member> &allMembers);
};

#endif
