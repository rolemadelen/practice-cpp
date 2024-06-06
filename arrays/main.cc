#include <iostream>
#include <cassert>
#include <vector>
#include "ivector.hh"
#include "ivector_test.hh"

void standard_testing() {
    std::vector<int> vec;

    assert(vec.size() == 0);
    assert(vec.capacity() == 0);
    assert(vec.empty() == true);

    for(int i=0; i<5; ++i) {
        vec.push_back(i+1);
    }

    assert(vec.size() == 5);
    assert(vec.capacity() == 8);
    assert(vec.empty() == false);

    for(int i=0; i<5; ++i) {
        vec.push_back(i+1);
    }
    
    assert(vec.size() == 10);
    assert(vec.capacity() == 16);

    while(vec.size() > 4) {
        vec.pop_back();
    }

    vec.shrink_to_fit();

    assert(vec.size() == 4);
    assert(vec.capacity() == 4);

    assert(vec.front() == 1);
    assert(vec.back() == 4);

    std::vector<int>::iterator it = vec.begin();
    ++it;
    vec.insert(it, 17);
    assert(vec.at(1) == 17);
}

int main(void) {
    standard_testing();

    img::IVectorTest test;
    test.run_tests();

    return 0;
}

