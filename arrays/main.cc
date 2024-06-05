#include <iostream>
#include <cassert>
#include <vector>
#include "ivector.hh"
#include "ivector_test.hh"

void standard_testing() {
    std::vector<int> vec;

}

int main(void) {
    standard_testing();

    img::IVectorTest test;
    test.run_tests();

    return 0;
}

