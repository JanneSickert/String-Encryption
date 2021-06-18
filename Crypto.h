#pragma once

#include <string>

#define UNI_MAX 65535

std::string encrypt(std::string text, std::string key);
std::string decrypt(std::string text, std::string key);