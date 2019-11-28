#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "../header/Reader.hpp"

using namespace std;

TEST(TESTONE,SINGLETEST) {
	Reader* reader = new Reader;
	string input = "echo Hello";
	EXPECT_EQ(reader->doInput(input), true);
}

TEST(TESTTWO,DOUBLETEST) {
        Reader* reader = new Reader;
        string input = "echo Hello; echo Goodbye";
        EXPECT_EQ(reader->doInput(input), true);
}

TEST(TESTTHREE, ORTEST) {
        Reader* reader = new Reader;
        string input = "echo Hello || echo Goodbye";
        EXPECT_EQ(reader->doInput(input), true);
}

TEST(TESTFOUR, ANDTEST) {
        Reader* reader = new Reader;
        string input = "echo Hello && echo Goodbye";
        EXPECT_EQ(reader->doInput(input), true);
}

TEST(TESTFIVE,COMMATEST) {
        Reader* reader = new Reader;
        string input = "ls; echo goodbye";
        EXPECT_EQ(reader->doInput(input), true);
}

TEST(TESTSIX,NESTEDTEST) {
        Reader* reader = new Reader;
        string input = "echo HELLO || echo GOODBYE && ls";
        EXPECT_EQ(reader->doInput(input), true);
}

TEST(TESTSEVEN,COMMENTTEST) {
        Reader* reader = new Reader;
        string input = "ls; #DoesThisWork?";
        EXPECT_EQ(reader->doInput(input), true);
}

TEST(TESTEIGHT,QUOTETEST) {
        Reader* reader = new Reader;
        string input = "ls; echo \"HELLO WORLD\"";
        EXPECT_EQ(reader->doInput(input), true);
}

TEST(TESTNINE, EXITTEST) {
        Reader* reader = new Reader;
        string input = "exit";
        EXPECT_EQ(reader->doInput(input), true);
}

TEST(TESTTEN, FALSETEST) {
        Reader* reader = new Reader;
        string input = "hello";
        EXPECT_EQ(reader->doInput(input), true);

}
TEST(TESTELEVEN, TESTLITERALTEST) {
        Reader* reader = new Reader;
        string input = "test -e Reader.cpp";
        EXPECT_EQ(reader->doInput(input), true);
}

TEST(TESTTWELVE, TESTSTRINGTEST) {
        Reader* reader = new Reader;
        string input = "[ -e Reader.cpp ]";
        EXPECT_EQ(reader->doInput(input), true);
}








int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
