#pragma once

#include <list>
#include <map>
#include <optional>
#include <iterator>

template <typename K, typename V>
class LRUCache {
public:
	typedef std::list<std::pair<K, V>>::iterator t_iterator;

	LRUCache(int cap) : capacity(cap)
	{

	}

	std::optional<V> get(K key) {
		auto it = element_map.find(key);
		if (it == element_map.end()) {
			return {};
		}

		elements.splice(elements.begin(), elements, it->second);
		return it->second->second ;
	}

	void put(K key, V value) {
		auto it = element_map.find(key);
		if (it != element_map.end()) {
			elements.erase(it->second);
			element_map.erase(it->first);
		}
		elements.push_front({ key, value });
		element_map[key] = elements.begin();

		if (elements.size() > capacity) {
			auto rmIt = elements.end();
			--rmIt;
			element_map.erase(rmIt->first);
			elements.erase(rmIt);
		}
	}

	int size() {
		return elements.size();
	}
private:
	std::list<std::pair<K, V>> elements;
	std::map<K, t_iterator> element_map;
	int capacity;
};