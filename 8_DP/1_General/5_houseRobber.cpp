long long int recure(vector<long long int> val)
{
  long long int prev = val[0], prev1 = 0;

  for (long long int i = 1; i < val.size(); i++)
  {
    long long int notPick = val[i];
    if (i - 2 >= 0)
    {
      notPick += prev1;
    }
    long long int pick = prev;

    long long int curr = max(pick, notPick);
    prev1 = prev;
    prev = curr;
  }

  return prev;
}

long long int houseRobber(vector<int> &valueInHouse)
{
  long long int n = valueInHouse.size();
  vector<long long int> temp1;
  vector<long long int> temp2;

  if (n == 1)
  {
    return valueInHouse[0];
  }

  for (long long int i = 0; i < n; i++)
  {
    if (i != 0)
      temp1.push_back(valueInHouse[i]);
    if (i != n - 1)
      temp2.push_back(valueInHouse[i]);
  }
  long long int robbed = max(recure(temp1), recure(temp2));
  return robbed;
}