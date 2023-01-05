#include "lru-cpp.h"
#include <iostream>

int main()
{
	LRUCache<int, int> cache {2};
	cache.put(1, 4);
	cache.put(2, 8);

	std::cout << "Key `1`: " << cache.get(1).value().lock()->second << "\n";
	std::cout << "Key `2`: " << cache.get(2).value().lock()->second << "\n";
	std::cout << "Size: " << cache.size() << "\n";

	cache.put(1, 9);
	std::cout << "Key `1`: " << cache.get(1).value().lock()->second << "\n";
	std::cout << "Size: " << cache.size() << "\n";

	cache.put(4, 2);
	std::cout << "Key `4`: " << cache.get(4).value().lock()->second << "\n";
	std::cout << "Size: " << cache.size() << "\n";
	return 0;
}
