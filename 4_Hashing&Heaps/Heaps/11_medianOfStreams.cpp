class MedianFinder
{
public:
  priority_queue<double> max;
  priority_queue<double, vector<double>, greater<double>> min;

  MedianFinder()
  {
  }

  void addNum(int num)
  {
    if (max.empty() || num < max.top())
    {
      max.push(num);
    }
    else
    {
      min.push(num);
    }

    if (min.size() > max.size() + 1)
    {
      max.push(min.top());
      min.pop();
    }
    else if (max.size() > min.size() + 1)
    {
      min.push(max.top());
      max.pop();
    }
  }

  double findMedian()
  {
    int lsize = max.size();
    int rsize = min.size();
    if (lsize == rsize)
    {
      return (min.top() + max.top()) / 2.0;
    }
    else if (lsize > rsize)
    {
      return max.top();
    }

    return min.top();
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */