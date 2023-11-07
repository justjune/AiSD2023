#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "Karatsuba_algorithm.cpp"
#include <initializer_list>

TEST_CASE("Testing the constructors") {
    SUBCASE("Testing the default constructor") {
        LongValue a;
        CHECK(a.getLength() == 0);
        CHECK(a.getSign() == 1);
    }

    SUBCASE("Testing the constructor with integer parameter 123") {
        LongValue a(123);
        CHECK(a.getLength() == 3);
        CHECK(a.getSign() == 1);
        CHECK(a[0] == 3);
        CHECK(a[1] == 2);
        CHECK(a[2] == 1);
    }
    SUBCASE("Testing the constructor with integer parameter -34567") {
        LongValue a(-34567);
        CHECK(a.getLength() == 5);
        CHECK(a.getSign() == -1);
        CHECK(a[0] == 7);
        CHECK(a[1] == 6);
        CHECK(a[2] == 5);
        CHECK(a[3] == 4);
        CHECK(a[4] == 3);
        
    }

    SUBCASE("Testing the copy constructor 123") {
        LongValue a(123);
        LongValue b(a);
        CHECK(b.getLength() == 3);
        CHECK(b.getSign() == 1);
        CHECK(b[0] == 3);
        CHECK(b[1] == 2);
        CHECK(b[2] == 1);
    }
    SUBCASE("Testing the copy constructor -123") {
        LongValue a(-123);
        LongValue b(a);
        CHECK(b.getLength() == 3);
        CHECK(b.getSign() == -1);
        CHECK(b[0] == 3);
        CHECK(b[1] == 2);
        CHECK(b[2] == 1);
    }


    SUBCASE("Testing the operator= 123") {
        LongValue a(123);
        LongValue b = a;
        CHECK(b.getLength() == 3);
        CHECK(b.getSign() == 1);
        CHECK(b[0] == 3);
        CHECK(b[1] == 2);
        CHECK(b[2] == 1);
    }
}
TEST_CASE("Testing comparison operators") {
    SUBCASE("Testing the operator== 123==123") {
        LongValue a(123);
        LongValue b(123);
        CHECK((a==b)==true);
    }
    SUBCASE("Testing the operator== 123==-123") {
        LongValue a(123);
        LongValue b(-123);
        CHECK((a==b)==false);
    }
    SUBCASE("Testing the operator== 123==113") {
        LongValue a(123);
        LongValue b(113);
        CHECK((a==b)==false);
    }
    SUBCASE("Testing the operator== 123==1230") {
        LongValue a(123);
        LongValue b(1230);
        CHECK((a==b)==false);
    }
    SUBCASE("Testing the operator== 10000000==10000001") {
        LongValue a(10000000);
        LongValue b(10000001);
        CHECK((a==b)==false);
    }
    SUBCASE("Testing the operator== 000001==001") {
        LongValue a({1,0,0,0,0,0},1);
        LongValue b({1,0,0},1);
        CHECK((a==b)==true);
    }
    SUBCASE("Testing the operator== +0==-0") {
        LongValue a({0},1);
        LongValue b({0},-1);
        CHECK((a==b)==true);
    }

}

TEST_CASE("Testing the operator+"){
    SUBCASE("Testing 123+456") {
        LongValue a(123);
        LongValue b(456);
        LongValue res(579);
        LongValue c = a + b;
        CHECK(c.getLength() == 3);
        CHECK(c.getSign() == 1);
        CHECK(c==res);
    }
    SUBCASE("Testing 123-956") {
        LongValue a(123);
        LongValue b(-956);
        LongValue res(-833);
        LongValue c = a + b;
        CHECK(c.getLength() == 3);
        CHECK(c.getSign() == -1);
        CHECK(c==res);
    }
    SUBCASE("Testing -956+123") {
        LongValue a(123);
        LongValue b(-956);
        LongValue res(-833);
        LongValue c = b + a;
        CHECK(c.getLength() == 3);
        CHECK(c.getSign() == -1);
        CHECK(c==res);
    }
    SUBCASE("Testing -9099211+990") {
        LongValue a(+990);
        LongValue b(-9100201);
        LongValue res(-9099211);
        LongValue c = b + a;
        CHECK(c.getLength() == 7);
        CHECK(c.getSign() == -1);
        CHECK(c==res);
    }
        SUBCASE("Testing -9099211+ -990") {
        LongValue a(-990);
        LongValue b(-9100201);
        LongValue res(-9101191);
        LongValue c = b + a;
        CHECK(c.getLength() == 7);
        CHECK(c.getSign() == -1);
        CHECK(c==res);
    }
    SUBCASE("Testing 990-9099211") {
        LongValue a(+990);
        LongValue b(-9100201);
        LongValue res(-9099211);
        LongValue c = a + b;
        CHECK(c.getLength() == 7);
        CHECK(c.getSign() == -1);
        CHECK(c==res);
    }
    SUBCASE("Testing 1000000000000000000000000-1") {
        LongValue a({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},1);
        LongValue b(-1);
        LongValue res({9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,0,0,0,0},1);
        LongValue c = a + b;
        CHECK(c.getLength() == 24);
        CHECK(c.getSign() == 1);
        CHECK(c==res);
    }
    SUBCASE("Testing 0000001000000000000000000000010-0000000000000000000001000000000000900000000001") {
        LongValue a({0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,},1);
        LongValue b({1,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},-1);
        LongValue res({1,9,9,9,9,9,9,9,9,9,9,9,9,8},-1);
        LongValue c = a + b;
        CHECK(c.getLength() == 14);
        CHECK(c.getSign() == -1);
        CHECK(c==res);
    }
}

TEST_CASE("Testing the operator*") {
    SUBCASE("Testing 123*456") {
        LongValue a(123);
        LongValue b(456);
        LongValue res(56088);
        LongValue c = a * b;
        CHECK(c.getLength() == 5);
        CHECK(c.getSign() == 1);
        CHECK(c==res);
    }
    SUBCASE("Testing 123*-956") {
        LongValue a(123);
        LongValue b(-956);
        LongValue res(-117588);
        LongValue c = a * b;
        CHECK(c.getLength() == 6);
        CHECK(c.getSign() == -1);
        CHECK(c==res);
    }
    SUBCASE("Testing -956*123") {
        LongValue a(123);
        LongValue b(-956);
        LongValue res(-117588);
        LongValue c = b * a;
        CHECK(c.getLength() == 6);
        CHECK(c.getSign() == -1);
        CHECK(c==res);
    }
    SUBCASE("Testing -9099211*990") {
        LongValue a(+990);
        LongValue b(-9100201);
        LongValue res({0,9,9,8,9,1,9,0,0,9},-1);
        LongValue c = b * a;
        CHECK(c.getLength() == 10);
        CHECK(c.getSign() == -1);
        CHECK(c==res);
    }
        SUBCASE("Testing -9099211* -990") {
        LongValue a(-990);
        LongValue b(-9100201);
        LongValue res({0,9,9,8,9,1,9,0,0,9},1);
        LongValue c = b * a;
        CHECK(c.getLength() == 10);
        CHECK(c.getSign() == 1);
        CHECK(c==res);
    }
    SUBCASE("Testing 990*-9099211") {
        LongValue a(+990);
        LongValue b(-9100201);
        LongValue res({0,9,9,8,9,1,9,0,0,9},-1);
        LongValue c = b * a;
        CHECK(c.getLength() == 10);
        CHECK(c.getSign() == -1);
        CHECK(c==res);
    }
    SUBCASE("Testing 1000000000000000000000000*-1") {
        LongValue a({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},1);
        LongValue b(-1);
        LongValue res({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},-1);
        LongValue c = a * b;
        CHECK(c.getLength() == 25);
        CHECK(c.getSign() == -1);
        CHECK(c==res);
    }
    SUBCASE("Testing 0000001000000000000000000000010*-0000000000000000000001000000000000900000000001") {
        LongValue a({0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},1);
        LongValue b({1,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},-1);
        LongValue res({0,1,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,1},-1);
        LongValue c = a * b;
        CHECK(c.getLength() == 49);
        CHECK(c.getSign() == -1);
        CHECK(c==res);
    }
}
