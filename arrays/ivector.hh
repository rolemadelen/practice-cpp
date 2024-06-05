#include <iostream>

namespace img {
    static const int minimum_capacity = 16;
    static const int growth_factor = 2;
    static const int shrink_factor = 4;

    class IVector {
        public:
            IVector() = default;
            ~IVector() = default;

            int get_size();
            int get_capacity();
            int get_item_at(int index);
            bool is_empty();
            
            void insert(int index, int item);
            void push_back(int item);
            void push_front(int item);
            
            void remove_all(int item);
            void remove_at(int index);
            int pop_back();
            int pop_front();

            int find(int item);

        private:
            // the total number of elements in the container
            int size{0};
            // the actual number of elements that can be stored in the container
            int capacity{minimum_capacity};
            // a dynamic array representing the vector
            std::unique_ptr<int[]> vec{new int[capacity]};

            void resize(int new_capacity);
    };
}