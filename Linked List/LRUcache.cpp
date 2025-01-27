#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/lru-cache/

// Brute Force
class LRUCache
{
private:
    vector<pair<int, int>> cache;
    int n;

public:
    // Brute Force
    LRUCache(int capacity)
    {
        n = capacity;
    }

    int get(int key)
    {
        for (int i = 0; i < cache.size(); i++)
        {
            if (cache[i].first == key)
            {
                int val = cache[i].second;
                pair<int, int> temp = cache[i];
                cache.erase(cache.begin() + i);
                cache.push_back(temp);

                return val;
            }
        }

        return -1;
    }

    void put(int key, int value)
    {
        for (int i = 0; i < cache.size(); i++)
        {
            if (cache[i].first == key)
            {
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }

        if (cache.size() == n)
        {
            cache.erase(cache.begin());
            cache.push_back({key, value});
        }
        else
        {
            cache.push_back({key, value});
        }
    }
};

// Optimal
class LRUCache2
{
private:
    list<int> dll; // key
    map<int, pair<list<int>::iterator, int>> mp;
    int n;

public:
    LRUCache2(int capacity)
    {
        n = capacity;
    }

    void makeRecentlyUsed(int key)
    {
        dll.erase(mp[key].first);

        dll.push_front(key);

        mp[key].first = dll.begin();
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;

        makeRecentlyUsed(key);

        return mp[key].second;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            mp[key].second = value;
            makeRecentlyUsed(key);
        }
        else
        {
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }

        if (n < 0)
        {
            int key_tobe_del = dll.back();
            mp.erase(key_tobe_del);

            dll.pop_back();

            n++;
        }
    }
};

int main()
{
    // Create a cache with capacity of 3
    LRUCache cache(3);

    // Put some values into the cache
    cache.put(1, 10); // Cache: {1=10}
    cache.put(2, 20); // Cache: {1=10, 2=20}
    cache.put(3, 30); // Cache: {1=10, 2=20, 3=30}

    // Retrieve values from the cache
    cout << "Get(1): " << cache.get(1) << endl; // Output: 10, Cache: {2=20, 3=30, 1=10}
    cout << "Get(2): " << cache.get(2) << endl; // Output: 20, Cache: {3=30, 1=10, 2=20}

    // Add a new entry, causing the LRU (least recently used) entry (3) to be evicted
    cache.put(4, 40); // Cache: {1=10, 2=20, 4=40}

    // Try to get the evicted key
    cout << "Get(3): " << cache.get(3) << endl; // Output: -1 (because 3 was evicted)

    // Add another entry
    cache.put(5, 50); // Cache: {1=10, 2=20, 5=50}

    // Check remaining entries in the cache
    cout << "Get(1): " << cache.get(1) << endl; // Output: 10, Cache: {2=20, 5=50, 1=10}
    cout << "Get(2): " << cache.get(2) << endl; // Output: 20, Cache: {5=50,1=10, 2=20}

    return 0;
}