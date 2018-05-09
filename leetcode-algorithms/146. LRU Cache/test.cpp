class LRUCache
{
public:
	LRUCache(int capacity) : capacity(capacity) { }

	int get(int key)
	{
		auto got = ump.find(key);
		if (got == ump.end())
			return -1;
		auto it = got->second;
		l.erase(it);
		l.push_front(*it);
		ump[key] = l.begin();
		return it->second;
	}

	void put(int key, int val)
	{
		if (get(key) == -1)
		{
			if (capacity == ump.size())
			{
				ump.erase(l.back().first);
				l.pop_back();
			}
			l.push_front(make_pair(key, val));
			ump[key] = l.begin();
		}
		else
			l.front().second = val;
	}

private:
	int capacity;
	list<pair<int, int>> l;
	unordered_map<int, list<pair<int, int>>::iterator> ump;
};
