#pragma once
#include<memory>

std::shared_ptr<int> mt1(new int(3));

std::shared_ptr<int> mt2 = std::make_shared<int>(3);
int main(){
    
}