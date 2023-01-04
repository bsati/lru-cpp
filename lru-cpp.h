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
		auto it = element_map.find(key);
		if (it == element_map.end()) {
			return {};
		}

		elements.splice(elements.begin(), elements, it->second);
		return { it->second->second };
	}

	void Put(K key, V value) {
	}
private:
	std::list<std::pair<K, V>> elements;
	std::map<K, std::list<std::pair<K, V>>::iterator> element_map;
	int capacity;
};