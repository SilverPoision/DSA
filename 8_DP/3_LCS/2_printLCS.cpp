// Tabulation code

#include <bits/stdc++.h>

int lcs(string s, string t)
{
  int size1 = s.size();
  int size2 = t.size();

  // Create a bigger matrix than required, because we'll need space for the base cases
  vector<vector<int>> memory(size1 + 1, vector<int>(size2 + 1, -1));

  // If one of the strings is of size 0, there are no common subsequences
  for (int index1 = 0; index1 <= size1; index1++)
    memory[index1][0] = 0; // or you could have filled the memory vector with 0 initially

  // If one of the strings is of size 0, there are no common subsequences
  for (int index2 = 0; index2 <= size2; index2++)
    memory[0][index2] = 0; // or you could have filled the memory vector with 0 initially

  // Fill the remaining memory matrix
  for (int index1 = 1; index1 <= size1; index1++)
  {
    for (int index2 = 1; index2 <= size2; index2++)
    {
      // start comparing indices from the very first character
      if (s[index1 - 1] == t[index2 - 1])
      {
        // One common character found, decrement both indices
        memory[index1][index2] = 1 + memory[index1 - 1][index2 - 1];
      }
      else
      {
        // Skip this element and continue finding, separately for both strings
        memory[index1][index2] = max(memory[index1 - 1][index2],
                                     memory[index1][index2 - 1]);
      }
    }
  }

  // store the LCS
  string ans;

  // indexes to traverse within the 2D matrix
  int index1 = size1; // for string s
  int index2 = size2; // for string t

  // ignoring first row and first col of the 2D matrix
  while (index1 > 0 and index2 > 0)
  {
    // If character in both strings match, move diagonally left
    if (s[index1 - 1] == t[index2 - 1])
    {
      ans += s[index1 - 1]; // insert the common character in the answer

      index1--;
      index2--;
    }
    // else move in the direction of the maximum value
    else if (memory[index1 - 1][index2] > memory[index1][index2 - 1])
      index1--;
    else
      index2--;
  }

  // Reverse to get the correct LCS
  reverse(ans.begin(), ans.end());

  // Print the LCS
  cout << ans << endl;

  // Return the length of the LCS (if required)
  return memory[size1][size2];
}