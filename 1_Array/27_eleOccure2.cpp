#include <bits/stdc++.h>
using namespace std;

/*
Given an array in which all numbers except two are repeated once.
 (i.e. we have 2n+2 numbers and n numbers are occurring twice
 and the remaining two have occurred once). Find those two
 numbers in the most efficient way

 Solution:
 Approach :
Step 1: Xor all the elements of the array into a variable sum thus
 all the elements present twice in an array will get removed as for
  example, 4 = “100” and if 4 xor 4 => “100” xor “100” thus answer
  will be “000”.
Step 2: Thus in the sum the final answer will be 3 xor 5 as both
2 and 4 are xor with itself giving 0, therefore
sum = “011” xor “101” i.e sum = “110” = 6.
Step 3: Now we will take 2’s Complement of sum
i.e (-sum) = “010”.
Step 4: Now bitwise And the 2’s of sum with the sum
i.e “110” & “010” gives the answer “010”
(Aim for bitwise & is that we want to get a number that contains
only the rightmost set bit of the sum).
Step 5: bitwise & all the elements of the array with this
obtained sum,
2 = “010” & “010” = 2, 3 = “011” & “010” = “010” , 4 = “100” & “010” = “000”, 5 = “101” & “010” = “000”.
Step 6: As we can see that the bitwise & of 2,3 > 0 thus they
will be xor with sum1 and bitwise & of 4,5 is resulting into 0
thus they will be xor with sum2.
Step 7: As 2 is present two times so getting xor with sum1 two
times only the result 3 is being stored in it and As 4 is also
present two times thus getting xor with sum2 will cancel it’s
value and thus only 5 will remain there.
*/

void get2NonRepeatingNos(int arr[], int n, int *x, int *y)
{
  /* Will hold Xor of all elements */
  int Xor = arr[0];

  /* Will have only single set bit of Xor */
  int set_bit_no;
  int i;
  *x = 0;
  *y = 0;

  /* Get the Xor of all elements */
  for (i = 1; i < n; i++)
  {
    Xor ^= arr[i];
  }

  /* Get the rightmost set bit in set_bit_no */
  set_bit_no = Xor & ~(Xor - 1);

  /* Now divide elements in two sets by
  comparing rightmost set bit of Xor with bit
  at same position in each element. */
  for (i = 0; i < n; i++)
  {

    /*Xor of first set */
    if (arr[i] & set_bit_no)
      *x = *x ^ arr[i];
    /*Xor of second set*/
    else
    {
      *y = *y ^ arr[i];
    }
  }
}

/* Driver code */
int main()
{
  int arr[] = {2, 3, 7, 9, 11, 2, 3, 11};
  int n = sizeof(arr) / sizeof(*arr);
  int *x = new int[(sizeof(int))];
  int *y = new int[(sizeof(int))];
  get2NonRepeatingNos(arr, n, x, y);
  cout << "The non-repeating elements are " << *x
       << " and " << *y;
}

// Same
class Solution
{
public:
  vector<int> singleNumber(vector<int> &nums)
  {
    int xors = 0;
    for (auto it : nums)
    {
      xors ^= it;
    }

    int cnt = 0;
    while (xors)
    {
      if (xors & 1)
        break;
      cnt++;
      xors = xors >> 1;
    }

    int xors1 = 0;
    int xors2 = 0;
    for (auto it : nums)
    {
      if (it & 1 << cnt)
      {
        xors1 ^= it;
      }
      else
      {
        xors2 ^= it;
      }
    }
    vector<int> ans = {xors1, xors2};
    return ans;
  }
};