#include "ivector_test.hh"
#include "ivector.hh"
#include <cassert>
#include <iostream>

#define ASSERT(expr, message) assert(expr && message)

namespace img {
    void IVectorTest::run_tests() {
        test_get_size();
        test_get_capacity();
        test_get_item_at();
        test_is_empty();
        
        test_push_back();
        test_push_front();
        test_insert();

        test_pop_back();
        test_pop_front();
        test_remove_all();
        test_remove_at();
        
        test_find();
        test_resize();
        test_shrink();
    }

    void IVectorTest::test_get_size() {
        std::cout << "TESTING : get_size" << std::endl;

        IVector tester;

        ASSERT(tester.get_size() == 0, "test case 1 FAILED");
        tester.push_back(1);
        ASSERT(tester.get_size() == 1, "test case 2 FAILED");
        tester.push_back(2);
        ASSERT(tester.get_size() == 2, "test case 3 FAILED");
        tester.pop_back();
        ASSERT(tester.get_size() == 1, "test case 4 FAILED");
        tester.pop_back();
        ASSERT(tester.get_size() == 0, "test case 5 FAILED");

        std::cout << "TESTING : get_size PASSED\n" << std::endl;
    }

    void IVectorTest::test_get_capacity() {
        std::cout << "TESTING : get_capacity" << std::endl;

        IVector tester;

        ASSERT(tester.get_capacity() == minimum_capacity, "test case 1 FAILED");

        for(int i=0; i<16; ++i) {
            tester.push_back(i);
        }

        ASSERT(tester.get_capacity() == minimum_capacity, "test case 2 FAILED");
        tester.push_back(17);
        std::cout << tester.get_capacity() << std::endl;
        ASSERT(tester.get_capacity() == minimum_capacity * growth_factor, "test case 3 FAILED");

        std::cout << "TESTING : get_capacity PASSED\n" << std::endl;
    }

    void IVectorTest::test_get_item_at() {
        std::cout << "TESTING : get_item_at" << std::endl;

        IVector tester;

        tester.push_back(1);
        tester.push_back(3);
        tester.push_back(5);

        ASSERT(tester.get_item_at(0) == 1, "test case 1 FAILED");
        ASSERT(tester.get_item_at(1) == 3, "test case 2 FAILED");
        ASSERT(tester.get_item_at(2) == 5, "test case 3 FAILED");

        tester.insert(1, 2);

        ASSERT(tester.get_item_at(1) == 2, "test case 4 FAILED");
        ASSERT(tester.get_item_at(2) == 3, "test case 5 FAILED");

        std::cout << "TESTING : get_item_at PASSED\n" << std::endl;
    }

    void IVectorTest::test_is_empty() {
        std::cout << "TESTING : is_empty" << std::endl;

        IVector tester;

        ASSERT(tester.is_empty() == true, "test case 1 FAILED");
        tester.push_back(1);
        ASSERT(tester.is_empty() == false, "test case 2 FAILED");
        tester.pop_back();
        ASSERT(tester.is_empty() == true, "test case 3 FAILED");

        std::cout << "TESTING : is_empty PASSED\n" << std::endl;
    }

    void IVectorTest::test_insert() {
        std::cout << "TESTING : insert" << std::endl;

        IVector tester;

        // 5
        tester.insert(0, 5);
        ASSERT(tester.get_item_at(0) == 5, "test case 1 FAILED");

        // 4 5
        tester.insert(0, 4);
        ASSERT(tester.get_item_at(0) == 4, "test case 2 FAILED");
        // 4 6 5
        tester.insert(1, 6);
        // 4 6 5 10
        tester.insert(3, 10);

        ASSERT(tester.get_item_at(1) == 6, "test case 3 FAILED");
        ASSERT(tester.get_item_at(2) == 5, "test case 4 FAILED");
        ASSERT(tester.get_item_at(3) == 10, "test case 5 FAILED");

        std::cout << "TESTING : insert PASSED\n" << std::endl;
    }

    void IVectorTest::test_push_back() {
        std::cout << "TESTING : push_back" << std::endl;

        IVector tester;

        for(int i=0; i<10; ++i) {
            tester.push_back(i);
        }

        ASSERT(tester.get_item_at(0) == 0, "test case 1 FAILED");
        ASSERT(tester.get_item_at(5) == 5, "test case 2 FAILED");
        ASSERT(tester.get_item_at(9) == 9, "test case 3 FAILED");

        std::cout << "TESTING : push_back PASSED\n" << std::endl;
    }

    void IVectorTest::test_push_front() {
        std::cout << "TESTING : push_front" << std::endl;

        IVector tester;

        for(int i=0; i<10; ++i) {
            tester.push_front(i);
        }

        // 9 8 7 6 5 4 3 2 1
        ASSERT(tester.get_item_at(0) == 9, "test case 1 FAILED");
        ASSERT(tester.get_item_at(5) == 4, "test case 2 FAILED");
        ASSERT(tester.get_item_at(9) == 0, "test case 3 FAILED");

        std::cout << "TESTING : push_front PASSED\n" << std::endl;
    }

    void IVectorTest::test_remove_all() {
        std::cout << "TESTING : remove_all" << std::endl;

        IVector tester;

        tester.push_back(1);
        tester.push_back(3);
        tester.push_back(1);
        tester.push_back(4);
        tester.push_back(5);
        tester.push_back(1);

        tester.remove_all(1);
        ASSERT(tester.get_size() == 3, "test case 1 FAILED");
        ASSERT(tester.get_item_at(0) == 3, "test case 2 FAILED");
        ASSERT(tester.get_item_at(1) == 4, "test case 3 FAILED");
        ASSERT(tester.get_item_at(2) == 5, "test case 4 FAILED");

        tester.remove_all(3);
        ASSERT(tester.get_size() == 2, "test case 5 FAILED");
        ASSERT(tester.get_item_at(0) == 4, "test case 6 FAILED");
        ASSERT(tester.get_item_at(1) == 5, "test case 7 FAILED");

        tester.remove_all(4);
        tester.remove_all(5);
        ASSERT(tester.get_size() == 0, "test case 8 FAILED");

        tester.remove_all(1);
        ASSERT(tester.get_size() == 0, "test case 9 FAILED");

        std::cout << "TESTING : remove_all PASSED\n" << std::endl;
    }

    void IVectorTest::test_remove_at() {
        std::cout << "TESTING : remove_at" << std::endl;

        IVector tester;

        // 1 3 5 7 9
        tester.push_back(1);
        tester.push_back(3);
        tester.push_back(5);
        tester.push_back(7);
        tester.push_back(9);

        // 1 3 7 9
        tester.remove_at(2);
        ASSERT(tester.get_size() == 4, "test case 1 FAILED");
        ASSERT(tester.get_item_at(2) == 7, "test case 2 FAILED");

        // 3 7 9
        tester.remove_at(0);
        ASSERT(tester.get_size() == 3, "test case 3 FAILED");
        ASSERT(tester.get_item_at(0) == 3, "test case 4 FAILED");

        // 3 9
        tester.remove_at(1);
        ASSERT(tester.get_size() == 2, "test case 5 FAILED");
        ASSERT(tester.get_item_at(1) == 9, "test case 6 FAILED");

        std::cout << "TESTING : remove_at PASSED\n" << std::endl;
    }

    void IVectorTest::test_pop_back() {
        std::cout << "TESTING : pop_back" << std::endl;

        IVector tester;

        tester.push_back(1);
        tester.push_back(3);
        tester.push_back(5);
        tester.push_back(7);
        tester.push_back(9);

        ASSERT(tester.pop_back() == 9, "test case 1 FAILED");
        ASSERT(tester.pop_back() == 7, "test case 2 FAILED");
        ASSERT(tester.pop_back() == 5, "test case 3 FAILED");
        ASSERT(tester.pop_back() == 3, "test case 4 FAILED");
        ASSERT(tester.pop_back() == 1, "test case 5 FAILED");
        ASSERT(tester.get_size() == 0, "test case 6 failed");

        std::cout << "TESTING : pop_back PASSED\n" << std::endl;
    }

    void IVectorTest::test_pop_front() {
        std::cout << "TESTING : pop_front" << std::endl;

        IVector tester;

        tester.push_back(1);
        tester.push_back(3);
        tester.push_back(5);
        tester.push_back(7);
        tester.push_back(9);

        ASSERT(tester.pop_front() == 1, "test case 1 FAILED");
        ASSERT(tester.pop_front() == 3, "test case 2 FAILED");
        ASSERT(tester.pop_front() == 5, "test case 3 FAILED");
        ASSERT(tester.pop_front() == 7, "test case 4 FAILED");
        ASSERT(tester.pop_front() == 9, "test case 5 FAILED");
        ASSERT(tester.get_size() == 0, "test case 6 FAILED");

        std::cout << "TESTING : pop_front PASSED\n" << std::endl;
    }

    void IVectorTest::test_find() {
        std::cout << "TESTING : find" << std::endl;

        IVector tester;

        tester.push_back(1);
        tester.push_back(3);
        tester.push_back(5);
        tester.push_back(7);
        tester.push_back(9);

        ASSERT(tester.find(1) == 0, "test case 1 FAILED");
        ASSERT(tester.find(3) == 1, "test case 2 FAILED");
        ASSERT(tester.find(5) == 2, "test case 3 FAILED");
        ASSERT(tester.find(7) == 3, "test case 4 FAILED");
        ASSERT(tester.find(9) == 4, "test case 5 FAILED");
        ASSERT(tester.find(0) == -1, "test case 6 FAILED");

        std::cout << "TESTING : find PASSED\n" << std::endl;
    }

    void IVectorTest::test_resize() {
        std::cout << "TESTING : resize" << std::endl;

        IVector tester;

        ASSERT(tester.get_capacity() == minimum_capacity, "test case 1 FAILED");

        for(int i=0; i<minimum_capacity + 5; ++i) {
            tester.push_back(i);
        }

        ASSERT(tester.get_capacity() == minimum_capacity * growth_factor, "test case 2 FAILED");
        
        std::cout << "TESTING : resize PASSED\n" << std::endl;
    }

    void IVectorTest::test_shrink() {
        std::cout << "TESTING : shrink" << std::endl;

        IVector tester;

        for(int i=0; i<20; ++i) {
            tester.push_back(i);
        }

        ASSERT(tester.get_capacity() == minimum_capacity * growth_factor, "test case 1 FAILED");

        while (tester.get_size() > 8) {
            tester.pop_back();
        }

        ASSERT(tester.get_size() == 8, "test case 2 FAILED");
        ASSERT(tester.get_capacity() == minimum_capacity, "test case 3 FAILED");

        while (tester.get_size() > 4) {
            tester.pop_back();
        }

        ASSERT(tester.get_size() == 4, "test case 4 FAILED");
        ASSERT(tester.get_capacity() == minimum_capacity >> 1, "test case 5 FAILED");

        IVector tester2;

        for(int i=0; i<10; ++i) {
            tester2.push_front(i);
            tester2.push_back(i+1);
        }

        while(tester2.get_size() > 8) {
            tester2.pop_front();
            tester2.pop_back();
        }

        ASSERT(tester2.get_size() == 8, "test case 6 FAILED");
        ASSERT(tester2.get_capacity() == minimum_capacity, "test case 7 FAILED");

        std::cout << "TESTING : shrink PASSED\n" << std::endl;
    }
}

