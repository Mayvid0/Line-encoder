#ifndef OPEN_WINDOW_H
#define OPEN_WINDOW_H

#include <string>

void lineEncoding(const std::string &dataStream, int &choice);
void handleAnalogOption();
void handleDigitalOption(std::string &dataStream);
void display();
std::string findLongestPalindrome(const std::string &s);

#endif
