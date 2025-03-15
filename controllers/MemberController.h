#ifndef MEMBERCONTROLLER_H
#define MEMBERCONTROLLER_H

#include <vector>
#include "../models/Member.h"

class MemberController {
public:
    static std::vector<Member> loadMembersFromFile(const std::string& filePath);
    static void saveMembersToFile(const std::string& filePath, const std::vector<Member>& members);
};

#endif
