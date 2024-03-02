class RandomizedCollection
{
  // Dups allowed
public:
  unordered_map<int, vector<int>> hash;
  vector<pair<int, int>> data;
  RandomizedCollection()
  {
  }

  bool insert(int val)
  {
    bool ret = true;
    if (hash.find(val) != hash.end())
    {
      ret = false;
    }
    hash[val].push_back(data.size());
    data.push_back({val, hash[val].size() - 1});

    return ret;
  }

  bool remove(int val)
  {
    if (hash.find(val) == hash.end())
    {
      return false;
    }
    auto lastOfarr = data.back();
    int valInd = hash[val].back();
    data[hash[val].back()] = lastOfarr;
    data.pop_back();
    hash[val].pop_back();
    hash[lastOfarr.first][lastOfarr.second] = valInd;
    if (hash[val].size() == 0)
      hash.erase(val);
    return true;
  }

  int getRandom()
  {
    return data[rand() % data.size()].first;
  }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */