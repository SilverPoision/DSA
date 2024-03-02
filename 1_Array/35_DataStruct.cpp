#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
private:
  vector<int> values;
  map<int, int> m;

public:
  RandomizedSet() {}

  bool insert(int val)
  {
    if (m.find(val) != m.end())
      return false;
    int ind = values.size();
    values.push_back(val);
    m[val] = ind;
    return true;
  }

  bool remove(int val)
  {
    if (m.find(val) == m.end())
      return false;

    int ind = m[val];
    int last = values.back();
    values[ind] = last;
    values.pop_back();
    m[last] = ind;
    m.erase(val);
    return true;
  }

  int getRandom()
  {
    int rand_idx = rand() % values.size();
    return values[rand_idx];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
  RandomizedSet random;
  cout << random.insert(1) << endl;
  cout << random.insert(2) << endl;
  cout << random.insert(20) << endl;
  cout << random.insert(21) << endl;
  cout << random.insert(3) << endl;
  // cout << random.search(20) << endl;
  cout << random.remove(3) << endl;
  cout << random.remove(3) << endl;
  cout << random.getRandom() << endl;
  return 0;
}

/* Try more Inputs

Case 1:
findRandom random;
random.insert(1)
random.insert(2)
random.insert(3)
result = random.remove(3)
expected = [True]
Case 2:
findRandom random;
random.insert(1)
random.insert(2)
random.remove(1)
result = random.remove(2)
expected = [True]

*/