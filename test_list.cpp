#include <iostream>
#include <cassert>
#include "list.hpp"

using namespace blgt;

void test_insert_front() {
    list lst;
    lst.insert_front(10);
    lst.insert_front(20);
    lst.insert_front(30);
    assert(lst.size() == 3);

    auto it = lst.begin();
    assert(*it == 30); ++it;
    assert(*it == 20); ++it;
    assert(*it == 10);
}

void test_insert_back() {
    list lst;
    lst.insert_back(1);
    lst.insert_back(2);
    lst.insert_back(3);
    assert(lst.size() == 3);

    auto it = lst.begin();
    assert(*it == 1); ++it;
    assert(*it == 2); ++it;
    assert(*it == 3);
}

void test_erase_front() {
    list lst;
    lst.insert_back(100);
    lst.insert_back(200);
    lst.erase_front();
    assert(lst.size() == 1);
    assert(*lst.begin() == 200);
}

void test_erase_back() {
    list lst;
    lst.insert_back(5);
    lst.insert_back(6);
    lst.erase_back();
    assert(lst.size() == 1);
    assert(*lst.begin() == 5);
}

void test_empty() {
    list lst;
    assert(lst.empty() == true);
    lst.insert_front(42);
    assert(lst.empty() == false);
}

void test_size() {
    list lst;
    assert(lst.size() == 0);
    lst.insert_front(1);
    lst.insert_back(2);
    lst.insert_back(3);
    assert(lst.size() == 3);
}

void test_iterator_equality() {
    list lst;
    lst.insert_back(1);
    auto it1 = lst.begin();
    auto it2 = lst.begin();
    assert(it1 == it2);
    ++it1;
    assert(it1 != it2);
}

void test_iterator_traversal() {
    list lst;
    lst.insert_back(10);
    lst.insert_back(20);
    lst.insert_back(30);

    int expected[] = {10, 20, 30};
    int i = 0;
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        assert(*it == expected[i++]);
    }
}

void test_combined_operations() {
    list lst;
    lst.insert_back(1);
    lst.insert_back(2);
    lst.insert_front(0); 
    lst.erase_back();    
    lst.erase_front();   
    assert(lst.size() == 1);
    assert(*lst.begin() == 1);
}

void test_multiple_erasures() {
    list lst;
    lst.insert_back(100);
    lst.insert_back(200);
    lst.insert_back(300);
    lst.erase_back();
    lst.erase_front();
    assert(lst.size() == 1);
    assert(*lst.begin() == 200);
}

int main() {
    test_insert_front();
    test_insert_back();
    test_erase_front();
    test_erase_back();
    test_empty();
    test_size();
    test_iterator_equality();
    test_iterator_traversal();
    test_combined_operations();
    test_multiple_erasures();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
