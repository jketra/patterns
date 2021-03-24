#pragma once

#include <creational/Singleton.h>

#include <thread>
#include <chrono>

#include <gtest/gtest.h>

namespace patterns {
namespace test {

class SingletonTests : public ::testing::Test {
public:
    static void firstInstance() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        auto& address = Singleton::getInstance();
        std::cout << &address <<std::endl;
    }

    static void secondInstance() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        auto& address = Singleton::getInstance();
        std::cout << &address <<std::endl;
    }
};

TEST_F(SingletonTests, BaseTest) {
    EXPECT_EQ(&Singleton::getInstance(), &Singleton::getInstance());
}

TEST_F(SingletonTests, TwoThreads) {
    std::thread t1(firstInstance);
    std::thread t2(secondInstance);
    
    t1.join();
    t2.join();
}

}
}
