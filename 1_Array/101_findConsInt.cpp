class DataStream
{
private:
  const int value_;
  const int k_;
  int count_ = 0;

public:
  DataStream(int value, int k) : value_(value), k_(k)
  {
  }

  bool consec(int num)
  {
    if (num == value_)
      ++count_;
    else
      count_ = 0;
    return count_ >= k_;
  }
};

// same
class DataStream
{
public:
  // https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/
  queue<int> stream;
  int k;
  int cnt;
  int value;
  DataStream(int value, int k)
  {
    this->k = k;
    this->cnt = 0;
    this->value = value;
  }

  bool consec(int num)
  {
    if (stream.size() == k)
    {
      if (stream.front() == value)
        cnt--;
      stream.pop();
    }
    stream.push(num);
    if (num == value)
      cnt++;

    if (cnt == k)
      return true;
    if (stream.size() < k)
      return false;
    return false;
  }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */