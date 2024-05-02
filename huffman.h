#include <string>
#include <map>
#include "MYtree.h"

std::string encode(const std::string& text);
std::string decode(const std::string& encoded, std::map<char, std::string>& codes);
