class Solution
{
public:
  static bool cmp(pair<int, int> a, pair<int, int> b)
  {
    if (a.first == b.first)
    {
      return a.second < b.second;
    }
    return a.first < b.first;
  }
  vector<std::vector<int>> getSkyline(vector<vector<int>> &buildings)
  {
    vector<vector<int>> ans;
    vector<pair<int, int>> v;
    for (auto i : buildings)
    {
      v.push_back({i[0], -i[2]});
      v.push_back({i[1], i[2]});
    }
    sort(v.begin(), v.end(), cmp);
    multiset<int> heights;
    heights.insert(0);
    int curH = 0;
    for (int i = 0; i < v.size(); i++)
    {
      int x = v[i].first;
      int h = v[i].second;
      if (h < 0)
      {
        heights.insert(-h);
      }
      else
      {
        heights.erase(heights.find(h));
      }
      if (curH != *heights.rbegin())
      {
        ans.push_back({x, *heights.rbegin()});
        curH = *heights.rbegin();
      }
    }
    return ans;
  }
};

class Heap
{
public:
  vector<int> arr;

  Heap(vector<int> arr)
  {
    this->arr = arr;
    int ind = arr.size() / 2 - 1;
    for (int i = ind; i >= 0; i--)
    {
      heapify(i);
    }
  }

  void heapify(int index)
  {
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    int largest = index;

    if (left < arr.size() && arr[largest] < arr[left])
    {
      largest = left;
    }

    if (right < arr.size() && arr[largest] < arr[right])
    {
      largest = right;
    }

    if (largest != index)
    {
      swap(arr[index], arr[largest]);
      heapify(largest);
    }
  }

  void push(int a)
  {
    int key = arr.size();
    arr.push_back(a);

    while (key > 0 && arr[key] > arr[(key - 1) / 2])
    {
      swap(arr[key], arr[(key - 1) / 2]);
      key = (key - 1) / 2;
    }
  }

  void pop(int key, int ele)
  {
    if (key == -1)
    {
      for (int i = 0; i < arr.size(); i++)
      {
        if (arr[i] == ele)
        {
          key = i;
          break;
        }
      }
    }
    arr[key] = arr[arr.size() - 1];
    arr.pop_back();
    heapify(key);
  }

  int top()
  {
    return arr[0];
  }
};

class Solution
{
public:
  static bool compare(vector<int> a, vector<int> b)
  {
    if (a[0] == b[0])
    {
      return a[1] < b[1];
    }

    return a[0] < b[0];
  }
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
  {
    vector<vector<int>> ans, arr;

    for (auto it : buildings)
    {
      arr.push_back({it[0], -it[2]});
      arr.push_back({it[1], it[2]});
    }

    sort(arr.begin(), arr.end(), compare);

    for (auto it : arr)
    {
      cout << "{";
      cout << it[0] << " " << it[1];
      cout << "} ";
    }

    Heap q({});
    q.push(0);
    int prev = 0;

    for (auto it : arr)
    {
      if (it[1] < 0)
      {
        q.push(-it[1]);
      }
      else
      {
        q.pop(-1, it[1]);
      }

      int curr = q.top();

      if (curr != prev)
      {
        ans.push_back({it[0], curr});
        prev = curr;
      }
    }

    return ans;
  }
};