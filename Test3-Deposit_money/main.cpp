//
// Created by rituparn on 02.08.23.
//

#include <iostream>
#include <gtest/gtest.h>

struct BankAccount{
    int balance {0};

    BankAccount(){
    }

    explicit BankAccount(const int balance) :balance{balance}{

    }
    void deposit(int amount){
        balance=amount;
    }
};

struct BankAccountTest:testing::Test{

    BankAccount *account;
    BankAccountTest(){
        account= new BankAccount;
    }

    ~BankAccountTest(){
        delete account;
    }
};
TEST_F(BankAccountTest, canDepositMoney){
    account->deposit(100);
    EXPECT_EQ(100, account->balance);
}






int main(int argc, char* argv[]){

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}