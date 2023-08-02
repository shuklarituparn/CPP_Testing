//
// Created by rituparn on 02.08.23.
//

#include <iostream>
#include <gtest/gtest.h>

struct BankAccount{
    int balance=4;  //test failed as we have the value as 4

    BankAccount(){  //empty constructor

    }

    explicit BankAccount(const int balance) :balance{balance}{

    }
};

TEST(AccountTest, BankAccountStartsEmpty){  //test wriiten with caps and grouping of the tests

    BankAccount account;


    EXPECT_EQ(0, account.balance);
}




int main(int argc, char* argv[]){

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}