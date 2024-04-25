class Solution
{
public:
  // https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/?envType=daily-question&envId=2024-04-08
  int countStudents(vector<int> &s, vector<int> &sa)
  {
    queue<int> q;

    for (auto it : s)
      q.push(it);

    int i = 0;
    while (true)
    {
      int k = q.size();
      int t = q.size();
      while (k--)
      {
        int front = q.front();
        q.pop();

        if (front == sa[i])
          i++;
        else
          q.push(front);
      }
      if (t == q.size())
        return t;
    }

    return q.size();
  }
};