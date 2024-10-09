#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void backtrack(const string& s, int start, vector<string>& path, vector<vector<string>>& result) {
    if (start >= s.size()) {
        result.push_back(path);
        return;
    }

    for (int end = start; end < s.size(); end++) {
        if (isPalindrome(s, start, end)) {
            path.push_back(s.substr(start, end - start + 1)); // Add the palindrome substring to the path
            backtrack(s, end + 1, path, result); // Recur for the remaining substring
            path.pop_back(); // Backtrack
        }
    }
}

vector<vector<string>> palindromePartitioning(const string& s) {
    vector<vector<string>> result;
    vector<string> path;
    backtrack(s, 0, path, result);
    return result;
}

int main() {
    string s = "aab";
    vector<vector<string>> partitions = palindromePartitioning(s);

    cout << "Palindrome partitions for the string \"" << s << "\":" << endl;
    for (const auto& partition : partitions) {
        for (const auto& str : partition) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
