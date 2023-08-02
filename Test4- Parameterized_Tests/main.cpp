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

    bool withdraw(int amount){
        if (amount>balance){
            return false;
        }else{
            balance=balance-amount;
            return true;
        }
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
/*
TEST_F(BankAccountTest, canDepositMoney){
    account->deposit(100);
    EXPECT_EQ(100, account->balance);
}
*/

struct account_state{
    int initial_balance;
    int withdrawal_amount;
    int final_balance;
    bool success;
};

struct WithdrawAccountTest:BankAccountTest, testing::WithParamInterface<account_state>{
    WithdrawAccountTest(){
        account->balance=GetParam().initial_balance;
    }
};

TEST_P(WithdrawAccountTest, FinalBalance){
    auto as = GetParam();
    auto success = account->withdraw(as.withdrawal_amount);
    EXPECT_EQ(as.final_balance, account->balance);
    EXPECT_EQ(as.success, success);
}

INSTANTIATE_TEST_SUITE_P(Default, WithdrawAccountTest, testing::Values(account_state{100,50,50, true}, account_state{100,200,100, false}));
int main(int argc, char* argv[]){

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}