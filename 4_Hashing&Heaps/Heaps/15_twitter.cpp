class Twitter
{
public:
  priority_queue<pair<int, pair<int, int>>> tweets;
  priority_queue<pair<int, pair<int, int>>> temp;
  int id = 1;
  map<int, map<int, bool>> followList;
  Twitter()
  {
  }

  void postTweet(int userId, int tweetId)
  {
    tweets.push({++id, {tweetId, userId}});
  }

  vector<int> getNewsFeed(int userId)
  {
    map<int, bool> follow = followList[userId];
    vector<int> ans;

    while (!tweets.empty())
    {
      auto t = tweets.top();
      auto top = t.second;
      tweets.pop();

      temp.push(t);

      if (ans.size() < 10 && (follow[top.second] == true || top.second == userId))
      {
        ans.push_back(top.first);
      }
    }
    swap(tweets, temp);

    return ans;
  }

  void follow(int followerId, int followeeId)
  {
    followList[followerId][followeeId] = true;
  }

  void unfollow(int followerId, int followeeId)
  {
    followList[followerId].erase(followeeId);
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

class Twitter
{
public:
  vector<pair<int, int>> posts;
  unordered_map<int, unordered_map<int, bool>> followList;
  Twitter()
  {
  }

  void postTweet(int userId, int tweetId)
  {
    posts.push_back({tweetId, userId});
  }

  vector<int> getNewsFeed(int userId)
  {
    auto follow = followList[userId];
    vector<int> ans;

    for (int i = posts.size() - 1; i >= 0; i--)
    {
      int tweetId = posts[i].first;
      int user = posts[i].second;
      if (ans.size() < 10 && (follow[user] == true || user == userId))
      {
        ans.push_back(tweetId);
      }
    }
    return ans;
  }

  void follow(int followerId, int followeeId)
  {
    followList[followerId][followeeId] = true;
  }

  void unfollow(int followerId, int followeeId)
  {
    followList[followerId][followeeId] = false;
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */