/*
Award Budget Cuts

The awards committee of your alma mater (i.e. your college/university) asked for your assistance with a budget allocation problem they’re facing.
Originally, the committee planned to give N research grants this year. However, due to spending cutbacks, the budget was reduced to newBudget dollars
and now they need to reallocate the grants. The committee made a decision that they’d like to impact as few grant recipients as possible by applying
a maximum cap on all grants. Every grant initially planned to be higher than cap will now be exactly cap dollars.
Grants less or equal to cap, obviously, won’t be impacted.

Given an array grantsArray of the original grants and the reduced budget newBudget,
write a function findGrantsCap that finds in the most efficient manner a cap such that the least number of recipients is impacted
and that the new budget constraint is met (i.e. sum of the N reallocated grants equals to newBudget).


input:  grantsArray = [2, 100, 50, 120, 1000], newBudget = 190

output: 47 # and given this cap the new grants array would be
           # [2, 47, 47, 47, 47]. Notice that the sum of the
           # new grants is indeed 190

*/

// same
double findGrantsCap(vector<int> grants, int newBudget)
{
  // your code goes here
  int n = grants.size();

  sort(grants.begin(), grants.end());

  double amount_budget_left = (double)newBudget;

  int count_grants_left = n;

  for (int i = 0; i < n; i++)
  {
    int money_req = grants[i] * count_grants_left;
    if (money_req >= amount_budget_left)
    {
      float cap = amount_budget_left / count_grants_left;
      return cap;
    }
    amount_budget_left -= grants[i];
    count_grants_left -= 1;
  }

  return newBudget;
}

double valid(vector<int> &grants, double newBudget)
{
  double sum = 0;
  for (auto it : grants)
  {
    if (it <= newBudget)
      sum += it;
    else
      sum += newBudget;
  }

  return sum;
}

double findGrantsCap(vector<int> grants, int newBudget)
{
  // your code goes here
  int n = grants.size();
  double low = (double)newBudget / n, high = newBudget;

  double diff = 1e-2;

  while ((high - low) > diff)
  {
    double mid = (high + low) / 2.0;

    int val = (int)(mid * 10 + .4);
    mid = (double)val / 10;

    double v = valid(grants, mid);

    if (v > newBudget)
    {
      high = mid;
    }
    else if (v < newBudget)
    {
      low = mid;
    }
    else
    {
      return mid;
    }
  }

  return -1;
}
