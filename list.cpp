#include "list.hpp"
#include <cassert>

namespace blgt {

std::int32_t& list::iterator::operator*() {
    assert(_data && _data->_data);
    return *(_data->_data);
}

list::iterator list::iterator::operator++() {
    if (_data)
        _data = _data->_next;
    return *this;
}

list::iterator list::iterator::operator++(int) {
    iterator temp = *this;
    ++(*this);
    return temp;
}

list::list() : _head(nullptr) {}

list::~list() {
    while (_head) {
        node* temp = _head;
        _head = _head->_next;
        delete temp->_data;
        delete temp;
    }
}

list::iterator list::begin() {
    return iterator{_head};
}

list::iterator list::end() {
    return iterator{nullptr};
}

void list::insert_front(std::int32_t value) {
    node* new_node = new node;
    new_node->_data = new std::int32_t(value);
    new_node->_next = _head;
    _head = new_node;
}

void list::insert_back(std::int32_t value) {
    node* new_node = new node;
    new_node->_data = new std::int32_t(value);
    new_node->_next = nullptr;

    if (!_head) {
        _head = new_node;
    } else {
        node* current = _head;
        while (current->_next)
            current = current->_next;
        current->_next = new_node;
    }
}

void list::erase_front() {
    if (!_head) return;
    node* temp = _head;
    _head = _head->_next;
    delete temp->_data;
    delete temp;
}

void list::erase_back() {
    if (!_head) return;
    if (!_head->_next) {
        delete _head->_data;
        delete _head;
        _head = nullptr;
        return;
    }

    node* prev = _head;
    node* curr = _head->_next;
    while (curr->_next) {
        prev = curr;
        curr = curr->_next;
    }

    delete curr->_data;
    delete curr;
    prev->_next = nullptr;
}

bool list::empty() {
    return _head == nullptr;
}

std::size_t list::size() {
    std::size_t count = 0;
    for (node* n = _head; n != nullptr; n = n->_next)
        ++count;
    return count;
}

bool operator==(const list::iterator& lhs, const list::iterator& rhs) {
    return lhs._data == rhs._data;
}

bool operator!=(const list::iterator& lhs, const list::iterator& rhs) {
    return !(lhs == rhs);
}

} 
