#pragma once

namespace patterns {

class Singleton {
public:
    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;

    static Singleton& getInstance();

private:
    Singleton() = default;
};

Singleton& Singleton::getInstance(){
    static Singleton singleton;
    return singleton;
}

}
