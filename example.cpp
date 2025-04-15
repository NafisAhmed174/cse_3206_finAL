#include<iostream>
using namespace std;
#include <gtest/gtest.h>

/*
clang++ -std=c++17 -I /opt/homebrew/Cellar/googletest/1.16.0/include \
    -L /opt/homebrew/Cellar/googletest/1.16.0/lib \
    -lgtest -lgtest_main -pthread banking.cpp -o banking
*/

/*
g++ -std=c++17 test.cpp \
-I/opt/homebrew/opt/googletest/include \
-L/opt/homebrew/opt/googletest/lib \
-lgtest -lgtest_main -pthread \
-o test && ./test
*/

class bankAccount{
    string name;
    int amount;

    public:
        bankAccount(string name, int amount){
            this->name = name;
            this->amount = amount;
        }
        void add_money(int amount){
            cout << "add money successful" << endl;
            this->amount += amount;
        }
        void withdraw(int amount){
            if(this->amount < amount){
                cout << "Invalid amount" << endl;
            }
            else{
                cout << "withdraw successful" << endl;
                this->amount -= amount;
            }
        }
        int getamount(){
            return amount;
        }
};

bankAccount acc("Nafis", 1000);

TEST(InitialBalanceTest, ZeroBalance)
{
    EXPECT_EQ(acc.getamount(), 1000);
}

TEST(AddMoneyTest, AddMoneyCorrect)
{
    acc.add_money(500);
    EXPECT_EQ(acc.getamount(), 1500);
}

TEST(WithDraw, ValidWithdraw)
{
    acc.withdraw(1000);
    EXPECT_EQ(acc.getamount(), 500);
}

TEST(WithDraw, InvalidWithdraw)
{
    EXPECT_THROW(acc.withdraw(1000), runtime_error);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


