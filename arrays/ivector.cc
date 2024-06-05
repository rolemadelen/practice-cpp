#include "ivector.hh"

namespace img {
    // IVector::IVector() {}
    // IVector::~IVector() {}
    
    int IVector::get_size() { return size; }
    int IVector::get_capacity() { return capacity; }
    bool IVector::is_empty() { return size == 0; }
    
    int IVector::get_item_at(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return vec[index];
    }

    void IVector::push_back(int item){
        if (size == capacity) {
            resize(capacity * growth_factor);
        }
        vec[size++] = item;
    }

    void IVector::push_front(int item){
        if (size == capacity) {
            resize(capacity * growth_factor);
        }

        for(int i=size; i>0; --i) {
            vec[i] = vec[i-1];
        }
        vec[0] = item;
        ++size;
    }

    void IVector::insert(int index, int item){
        if(index == size) {
            push_back(item);
        }
        else if(index == 0) {
            push_front(item);
        }
        else {
            for(int i=size; i>index; --i) {
                vec[i] = vec[i-1];
            }
            vec[index] = item;
            ++size;
        }
        return;
    }


    void IVector::remove_all(int item){
        return;
    }

    void IVector::remove_at(int index){
        return;
    }

    int IVector::pop_back() {
        if (size == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return vec[--size];
    }

    int IVector::pop_front(){
        return 0;
    }

    int IVector::find(int item){
        return 0;
    }

    void IVector::resize(int new_capacity) {
        return;
    }
}

