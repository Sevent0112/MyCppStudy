#include<memory>
#include<cassert>

std::unique_ptr<int> mt1 = std::make_unique<int>(10);
std::unique_ptr<int> mt2 = std::make_unique<int>(80);
std::unique_ptr<int> mt3 = std::move(mt1);