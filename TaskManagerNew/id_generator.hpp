#include <iostream>

class IDGenerator {
public:
    IDGenerator instance();
    uint32_t next();

private:
    IDGenerator() : _id(0) {
        this->only_copy = NULL;
    }
    IDGenerator* only_copy;
    uint32_t _id;
};