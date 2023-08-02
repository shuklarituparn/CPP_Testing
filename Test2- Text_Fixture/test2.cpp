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
};

struct BankAccountTest:testing::Test{  //Inherits from testing::Test

    BankAccount *account;
    BankAccountTest(){
        account= new BankAccount;
    }

    ~BankAccountTest(){
        delete account;
    }
};
TEST_F(BankAccountTest, BankAccountStartsEmpty){   //test fixture

  //  BankAccount account; as we dont't want to call it explicitely


    EXPECT_EQ(0, account->balance);
}






int main(int argc, char* argv[]){

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

//The test passed