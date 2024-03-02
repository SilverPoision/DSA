// https://practice.geeksforgeeks.org/problems/minimum-window-subsequence/1
string minWindow(string S, string T)
{
    // Write your Code here
    int s = S.size();
    int t = T.size();

    int start = 0, end = 0;
    int a = 0, b = 0;

    int minLen = 1e9;
    string minStr;

    while (a < s)
    {
        if (S[a] == T[b])
        {
            if (b == t - 1)
            {
                end = a;

                while (b >= 0)
                {
                    if (S[a] == T[b])
                    {
                        b--;
                    }
                    a--;
                }

                start = a + 1;

                int len = end - start + 1;

                if (len < minLen)
                {
                    minLen = len;
                    minStr = S.substr(start, len);
                }

                a = a + 1;
                b = 0;
            }
            else
            {
                b++;
            }
        }
        a++;
    }

    return minStr;
}