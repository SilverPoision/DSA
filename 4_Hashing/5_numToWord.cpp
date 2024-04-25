// Int to English words International
class Solution
{
public:
  const vector<string> one{
      "", "One", "Two", "Three", "Four",
      "Five", "Six", "Seven", "Eight", "Nine",
      "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
      "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  const vector<string> ten{"", "", "Twenty", "Thirty", "Forty",
                           "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

  string helper(int num)
  {
    string s;

    if (num < 20)
    {
      s = one[num];
    }
    else if (num < 100)
    {
      s = ten[num / 10] + " " + one[num % 10];
    }
    else if (num < 1000)
    {
      s = helper(num / 100) + " Hundred " + helper(num % 100);
    }
    else if (num < 1000000)
    {
      s = helper(num / 1000) + " Thousand " + helper(num % 1000);
    }
    else if (num < 1000000000)
    {
      s = helper(num / 1000000) + " Million " + helper(num % 1000000);
    }
    else
    {
      s = helper(num / 1000000000) + " Billion " + helper(num % 1000000000);
    }

    trim(s);
    return s;
  }

  void trim(string &s)
  {
    s.erase(0, s.find_first_not_of(' ')); // remove all the space in front;
    s.erase(s.find_last_not_of(' ') + 1); // remove all the space in back;
  }

  string numberToWords(int n)
  {
    if (n == 0)
      return "Zero";
    return helper(n);
  }
};

// Int to Word indian;

#include <bits/stdc++.h>
using namespace std;

/*
Write an efficient algorithm to convert a given number into words. Asked in : Oracle,Amazon,Microsoft
*/

string one[] = {"", "one ", "two ", "three ", "four ",
                "five ", "six ", "seven ", "eight ",
                "nine ", "ten ", "eleven ", "twelve ",
                "thirteen ", "fourteen ", "fifteen ",
                "sixteen ", "seventeen ", "eighteen ",
                "nineteen "};

// strings at index 0 and 1 are not used, they is to
// make array indexing simple
string ten[] = {"", "", "twenty ", "thirty ", "forty ",
                "fifty ", "sixty ", "seventy ", "eighty ",
                "ninety "};

string numToWords(int n, string s)
{
  string str = "";

  if (n > 19)
  {
    str += ten[n / 10] + one[n % 10];
  }
  else
  {
    str += one[n];
  }

  if (n)
  {
    str += s;
  }

  return str;
};

// Function to print a given number in words
string convertToWords(long n)
{
  string out;

  cout << n % 100 << endl;

  out += numToWords(((n / 10000000) % 100), "crore") + " ";
  out += numToWords(((n / 100000) % 100), "lakh") + " ";
  out += numToWords(((n / 1000) % 100), "thousand") + " ";
  out += numToWords(((n / 100) % 10), "hundred") + " ";

  if (n > 100 && n % 100)
  {
    out += "and ";
  }

  out += numToWords((n % 100), "");

  return out;
};

int main()
{
  // long handles upto 9 digit no
  // change to unsigned long long int to
  // handle more digit number
  long n = 12349567;

  // convert given number in words
  cout << convertToWords(n) << endl;

  return 0;
};

/* Try more Inputs
Case 1:
 long n = 123;
 convertToWords(n)
 expected = [one hundred twenty three]

Case 2:
NumberToWords("1200".toCharArray());
 expected = [one thousand two hundred]
*/
