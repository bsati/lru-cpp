#pragma once

#include <list>
#include <map>
#include <optional>
#include <iterator>
#include <memory>

template <typename K, typename V>
class LRUCache {
public:
	typedef std::list<std::shared_ptr<std::pair<K, V>>>::iterator t_iterator;

	LRUCache(int cap) : capacity(cap)
	{

	}

	std::optional<std::weak_ptr<std::pair<K, V>>> get(K key) {
		auto it = element_map.find(key);
		if (it == element_map.end()) {
			return {};
		}

		elements.splice(elements.begin(), elements, it->second);
		auto ptr = *it->second;
		return { ptr };
	}

	void put(K key, V value) {
		auto it = element_map.find(key);
		if (it != element_map.end()) {
			elements.erase(it->second);
			element_map.erase(it->first);
		}
		std::pair<K, V> pair{ key, value };
		elements.push_front(std::make_shared<std::pair<K, V>>(pair));
		element_map[key] = elements.begin();

		if (elements.size() > capacity) {
			auto rmIt = elements.end();
			--rmIt;
			element_map.erase((*rmIt)->first);
			elements.erase(rmIt);
		}
	}

	int size() {
		return elements.size();
	}
private:
	std::list<std::shared_ptr<std::pair<K, V>>> elements;
	std::map<K, t_iterator> element_map;
	int capacity;
};