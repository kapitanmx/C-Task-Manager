#include "id_generator.hpp"

#define __IDGENERATOR

auto IDGenerator::next() -> uint32_t{
    return _id++;
}

auto IDGenerator::instance() -> IDGenerator{
    if (!this->only_copy) {
        this->only_copy = new IDGenerator();
    }
    return *only_copy;
}