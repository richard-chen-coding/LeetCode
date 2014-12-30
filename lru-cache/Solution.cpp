
class LRUCache
{
private:
	map<int, int> dict;
	list<int> lru_list;
	map<int, list<int>::iterator> lru_dict;

	
	int currentSize;
	int capacity;

public:
    LRUCache(int _capacity) : capacity(_capacity), currentSize(0)
	{

    }
    
    int get(int key) 
	{
		auto itr = dict.find(key);
		if(itr != dict.end())
		{
			auto lru_itr = lru_dict.find(key);
			auto list_itr = lru_itr->second;
			
			lru_list.erase(list_itr);
			lru_list.push_front(key);
			lru_itr->second = lru_list.begin();
			return itr->second;
		}
		else
		{
			return -1;
		}
    }
    
	void add(int key, int value)
	{
		if(currentSize == capacity)
		{
			if(lru_list.empty())
			{
				throw exception();
			}
			
			int key_to_remove = *lru_list.rbegin();
			dict.erase(key_to_remove);
			currentSize--;
			lru_dict.erase(key_to_remove);
			lru_list.pop_back();
		}
		dict.insert(std::pair<int, int>(key, value));
		lru_list.push_front(key);
		lru_dict.insert(std::pair<int, list<int>::iterator>(key, lru_list.begin()));
		currentSize++;
	}

	void modify(map<int, int>::iterator dict_itr, int value)
	{
		int key = dict_itr->first;
		dict[key] = value;
		auto list_itr = lru_dict[key];
		lru_list.erase(list_itr);
		lru_list.push_front(key);
		lru_dict[key] = lru_list.begin();
	}

    void set(int key, int value) 
	{
		auto itr = dict.find(key);
		if(itr != dict.end())
		{
			modify(itr, value);
		}
		else
		{
			add(key,value);
		}
    }
};
