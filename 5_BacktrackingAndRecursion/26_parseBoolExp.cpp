class Solution
{
public:
  bool parseBoolExpr(string exp)
  {
    stack<char> st;
    for (int i = 0; i < exp.size(); i++)
    {
      if (exp[i] == ')')
      {
        unordered_map<char, bool> hash;

        while (st.top() != '(')
        {
          hash[st.top()] = true;
          st.pop();
        }
        st.pop(); // ( ye hatane ke liye
        char op = st.top();
        st.pop();

        if (op == '&')
        {
          st.push(hash['f'] ? 'f' : 't');
        }
        else if (op == '|')
        {
          st.push(hash['t'] ? 't' : 'f');
        }
        else
        {
          st.push(hash['t'] ? 'f' : 't');
        }
      }
      else if (exp[i] != ',')
      {
        st.push(exp[i]);
      }
    }

    return st.top() == 't';
  }
};

//======================

class Solution
{
public:
  bool parseBoolExpr(string e)
  {
    auto it = e.begin();
    return parse(it);
  }

  bool parse(auto &it)
  {
    switch (*(it++))
    {
    case 't':
      return true;
    case 'f':
      return false;
    case '|':
      return parse(it, false, [](bool init, bool val)
                   { return init || val; });
    case '&':
      return parse(it, true, [](bool init, bool val)
                   { return init && val; });
    case '!':
      return parse(it, false, [](bool init, bool val)
                   { return !val; });
    }

    return false;
  }

  bool parse(auto &it, bool init, function<bool(bool, bool)> op)
  {
    it++;
    while (true)
    {
      auto b = parse(it);
      init = op(init, b);
      if (*it == ')')
        break;
      it++;
    }
    it++;
    return init;
  }
};