#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Function to find the lexicographically minimal rotation using Booth's Algorithm
int minimal_rotation(const std::string &s) {
  std::string doubled = s + s;
  int n = s.size();
  std::vector<int> f(2 * n, -1); // Failure function
  int k = 0; // Least rotation of string found so far

  for (int j = 1; j < 2 * n; ++j) {
    char sj = doubled[j];
    int i = f[j - k - 1];
    while (i != -1 && sj != doubled[k + i + 1]) {
      if (sj < doubled[k + i + 1]) k = j - i - 1;
      i = f[i];
    }
    if (sj != doubled[k + i + 1]) {
      if (sj < doubled[k]) k = j;
      f[j - k] = -1;
    } else {
      f[j - k] = i + 1;
    }
  }

  return k;
}

int main() {
  std::string s;
  std::cin >> s;
  int rotation_index = minimal_rotation(s);
  std::string result = s.substr(rotation_index) + s.substr(0, rotation_index);
  std::cout << result << std::endl;
  return 0;
}
