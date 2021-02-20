#pragma once

#include <creational/Singleton.h>

#include <thread>
#include <chrono>

#include <gtest/gtest.h>

namespace test {

class CreationalPatternsTests : public ::testing::Test {
public:
    static void firstInstance() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        auto& address = not_safe::Singleton::getInstance();
        std::cout << &address <<std::endl;
    }

    static void secondInstance() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        auto& address = not_safe::Singleton::getInstance();
        std::cout << &address <<std::endl;
    }
};

TEST_F(CreationalPatternsTests, BaseTest) {
    EXPECT_EQ(&not_safe::Singleton::getInstance(), &not_safe::Singleton::getInstance());
}

TEST_F(CreationalPatternsTests, TwoThreads) {
        std::thread t1(firstInstance);
        std::thread t2(secondInstance);

        t1.join();
        t2.join();
}

}
