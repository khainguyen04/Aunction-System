#include "MemberController.h"
#include "../utils/FileHandler.h"

std::vector<Member> MemberController::loadMembersFromFile(const std::string& filePath) {
    return FileHandler::readMembersFromCSV(filePath);
}

void MemberController::saveMembersToFile(const std::string& filePath, const std::vector<Member>& members) {
    FileHandler::writeMembersToCSV(filePath, members);
}
