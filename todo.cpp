#include "todo.h"
#include <stdexcept>
#include <iostream>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    for (int i=0; i<MAX_TASKS; i++) {
        tasks[i] = nullptr;
    }
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    size = 0;
    for (int i=0; i<MAX_TASKS; i++) {
        delete tasks[i];
        tasks[i] = nullptr;
    }
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int i = 0;
    
    while (1) {
        if (str[i] == '\0') {
            break;
        }
        i++;
    }

    return i;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int strlen = string_length(src);
    for (int j=0; j<strlen+1; j++) {
        dest[j] = src[j];
    }
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if(size == 32) {
        throw std::overflow_error("too many tasks");
    }
    else {
        int strlen = string_length(task);
        tasks[size] = new char[strlen+1];
        string_copy(tasks[size], task);
        size = size + 1;
    }

    std::cout<<tasks[size-1]<<std::endl;
    

}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if ((index >= size) || (index < 0)) {
        throw std::invalid_argument("invalid index");
    }
    else {
        for (int i=0; i < size - index - 1; i++) {
            delete tasks[index+i];
            int strlen = string_length(tasks[index+i+1]);
            tasks[index+i] = new char[strlen+1];
            string_copy(tasks[index+i], tasks[index+i+1]);
        }
        
        delete tasks[size-1];
        size = size - 1;

        std::cout<<tasks[0]<<std::endl;
        std::cout<<tasks[1]<<std::endl;
    }
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count = size;
    if (size == 0) {
        return nullptr;
    }
    else {
        char** newtasks = new char*[size];
        for (int i=0; i<size; i++) {
            int strlen = string_length(tasks[i]);
            newtasks[i] = new char[strlen+1];
            string_copy(newtasks[i], tasks[i]);
        }
        return const_cast<const char**>(newtasks);
    }
}

