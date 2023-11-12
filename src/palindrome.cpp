#include <iostream>
#include <string>
#include <vector>


std::string preprocessString(const std::string& s) {
    std::string result = "#";
    for (char c : s) {
        result += c;
        result += '#';
    }
    return result;
}

std::string findLongestPalindrome(const std::string& s) {
    std::string processedString = preprocessString(s);
    int n = processedString.length();

    std::vector<int> P(n, 0);
    int center = 0, rightBoundary = 0;
    int maxRadius = 0, maxCenter = 0;

    for (int i = 0; i < n; ++i) {
        if (i < rightBoundary) {
            int mirror = 2 * center - i;
            P[i] = std::min(rightBoundary - i, P[mirror]);
        }

        // Attempt to expand palindrome centered at i
        int a = i + (1 + P[i]);
        int b = i - (1 + P[i]);
        while (a < n && b >= 0 && processedString[a] == processedString[b]) {
            P[i]++;
            a++;
            b--;
        }

        // If palindrome centered at i expands past rightBoundary, adjust center and rightBoundary
        if (i + P[i] > rightBoundary) {
            center = i;
            rightBoundary = i + P[i];
        }

        // Update the maximum palindrome information
        if (P[i] > maxRadius) {
            maxRadius = P[i];
            maxCenter = i;
        }
    }

    // Extract the longest palindrome substring from the original string
    int start = (maxCenter - maxRadius) / 2;
    int length = maxRadius;
    return s.substr(start, length);
}

