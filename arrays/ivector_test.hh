#include <iostream>

namespace img {
    class IVectorTest {
        public:
            void run_tests();
            
            void test_get_size();
            void test_get_capacity();
            void test_get_item_at();
            void test_is_empty();

            void test_insert();
            void test_push_back();
            void test_push_front();

            void test_remove_all();
            void test_remove_at();
            void test_pop_back();
            void test_pop_front();

            void test_find();
            void test_resize();
            void test_shrink();
    };
}

