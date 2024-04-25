#include <bits/stdc++.h>
using namespace std;

#define n 4
/*
You are in a party of N people, where only one person is known
to everyone. Such a person may be present at the party, if yes,
(s)he doesn’t know anyone at the party. Your task is to find the
celebrity at the party in Time Complexity O(n) Asked in: Google,
Flipkart, Amazon, Microsoft

Solution:
1. Just check in which row all the elements are zero and there cab be
only one 1 and that also when i == j and zero = 0;
*/

// Person with 2 is celebrity
bool MATRIX[n][n] = {{0, 0, 1, 0},
                     {0, 0, 1, 0},
                     {0, 0, 0, 0},
                     {0, 0, 1, 0}};

bool knows(int a, int b)
{
  return MATRIX[a][b];
}

int findCelebrityMy()
{
  stack<int> S;

  for (int i = 0; i < n; i++)
  {
    S.push(i);
  }

  while (S.size() > 1)
  {
    int a = S.top();
    S.pop();
    int b = S.top();
    S.pop();

    if (!knows(a, b))
    {
      S.push(a);
    }
    if (!knows(b, a))
    {
      S.push(b);
    }
  }

  int C = S.top();
  S.pop();

  for (int i = 0; i < n; i++)
  {
    // If any person doesn't
    // know 'C' or 'C' doesn't
    // know any person, return -1
    if ((i != C) &&
        (knows(C, i) ||
         !knows(i, C)))
      return -1;
  }

  return C;
}

int main()
{
  int id = findCelebrityMy();
  id == -1 ? cout << "No celebrity Found" : cout << "Celebrity ID is " << id;
  return 0;
}

/* Try more Inputs
case 1:
static int matrix[][] = {{0 1 0},
                         {0 0 0},
                         {0 1 0}};
expected = 1

case2:
static int matrix[][] = {{0 1},
                        {1 0}};
 expected = -1

Note: The two people at the party both
know each other. None of them is a celebrity

case 3:
static int matrix[][] = { {0, 0, 1, 0},
                            {0, 0, 1, 0},
                         {0, 1, 0, 0},
                         {0, 0, 1, 0} };
expected = -1
*/
