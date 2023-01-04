#pragma once

#include <list>
#include <map>
#include <optional>

template <typename K, typename V>
class LRUCache {
public:
	LRUCache(int cap) : capacity(cap)
	{

	}

	std::optional<const V&> Get(K key) {
		
	}

	void Put(K key, V value) {
	}
private:
	std::list<std::pair<K, V>> elements;
	std::map<K, std::list<std::pair<K, V>>::iterator> element_map;
	int capacity;
};