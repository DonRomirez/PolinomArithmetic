#include <gtest.h>
#include <Functions.h>
//Polynom tests
TEST(Polynom_Methods, Add_Monoms_with_same_s)
{
	MonomValue m1(1, 1, 0, 0), m2(2, 1, 0, 0),res(3,1,0,0);
	Polynom P1, P2;
	P1.AddMonom(m1);
	P1.AddMonom(m2);
	P2.AddMonom(res);
	EXPECT_EQ(P1, P2);
 
}
TEST(Polynom_Methods, Add_Monoms_with_different_s)
{
	MonomValue m1(1, 1, 0, 0), m2(2, 2, 1, 0);
	Polynom P1,P2;
	P1.AddMonom(m1);
	P1.AddMonom(m2);
	P2.AddMonom(m2);
	P2.AddMonom(m1);
	EXPECT_EQ(P1, P2);
}
TEST(Polynom_Methods, Get_Size)
{
	MonomValue m1(1, 1, 0, 0), m2(2, 2, 1, 0);
	Polynom P1, P2;
	P1.AddMonom(m1);
	P1.AddMonom(m2);
	P2.AddMonom(m1);
	EXPECT_EQ(P1.GetSize(), 2);
	EXPECT_EQ(P2.GetSize(), 1);
}
//Operators tests

TEST(Polynom_Operators, Add_with_Same_s)
{
	MonomValue m1(1, 1, 0, 0), m2(2, 1, 0, 0), m3(3, 1, 0, 0);
	Polynom P1, P2, RES;
	P1.AddMonom(m1);
	P2.AddMonom(m2);
	RES.AddMonom(m3);
	EXPECT_EQ(P1 + P2, RES);
}
TEST(Polynom_Operators, Add_with_Not_Same_s)
{
	MonomValue m1(1, 1, 0, 0), m2(2, 1, 0, 0);
	Polynom P1, P2, RES;
	P1.AddMonom(m1);
	P2.AddMonom(m2);
	RES.AddMonom(m1);
	RES.AddMonom(m2);

	EXPECT_EQ(P1 + P2, RES);

}
TEST(Polynom_Operators, Sub_with_Same_s)
{
	MonomValue m1(2, 1, 0, 0), m2(1, 1, 0, 0), m3(1, 1, 0, 0);
	Polynom P1, P2, RES;
	P1.AddMonom(m1);
	P2.AddMonom(m2);
	RES.AddMonom(m3);
	EXPECT_EQ(P1 - P2, RES);
}
TEST(Polynom_Operators, Sub_with_not_Same_s)
{
	MonomValue m1(2, 1, 0, 0), m2(1, 2, 0, 0), m3(1, 1, 1, 0), m3res(-1, 1, 1, 0);
	Polynom P1, P2, RES;
	P1.AddMonom(m1);
	P1.AddMonom(m2);
	P2.AddMonom(m3);
	RES.AddMonom(m1);
	RES.AddMonom(m2);
	RES.AddMonom(m3res);
	EXPECT_EQ(P1 - P2, RES);
}
TEST(Polynom_Operators, Mult_same_s)
{
	MonomValue m1(1, 1, 0, 0), m2(1, 1, 0, 0), m3(1, 2, 0, 0);
	Polynom P1, P2, RES;
	P1.AddMonom(m1);
	P2.AddMonom(m2);
	RES.AddMonom(m3);
	EXPECT_EQ(P1 * P2, RES);
}
TEST(Polynom_Operators, Mult_not_same_s)
{
	MonomValue m1(1, 1, 0, 0), m2(1, 0, 1, 0), m3(1, 1, 1, 0);
	Polynom P1, P2, RES;
	P1.AddMonom(m1);
	P2.AddMonom(m2);
	RES.AddMonom(m3);
	EXPECT_EQ(P1 * P2, RES);
}
TEST(Polynom_Operators, Mult_s_Null)
{
	MonomValue m1(1, 0, 0, 0), m2(1, 0, 1, 0);
	Polynom P1, P2, RES;
	P1.AddMonom(m1);
	P2.AddMonom(m2);
	RES.AddMonom(m2);
	EXPECT_EQ(P1 * P2, RES);
}
TEST(Polynom_Operators, Hard_Mult)
{
    MonomValue m1(1, 3, 4, 6), m2(3, 0, 0, 0), m3(6,1,2,0), m4(1,1,0,0);
	MonomValue res1(1, 4,4,6), res2(6,4,6,6), res3(18,1,2,0), res4(3,1,0,0);
	Polynom P1, P2, RES;
	P1.AddMonom(m1);
	P1.AddMonom(m2);
	P2.AddMonom(m3);
	P2.AddMonom(m4);
	RES.AddMonom(res1);
	RES.AddMonom(res2);
	RES.AddMonom(res3);
	RES.AddMonom(res4);
	EXPECT_EQ(P1 * P2, RES);
}
TEST(Polynom_Operators, Hard_Add)
{
	MonomValue m1(1,2,4,0), m2(10, 0, 0, 0), m3(-4, 0, 0, 0), m4(1, 3, 6, 2);
	MonomValue res1(1, 3, 6, 2), res2(1, 2, 4, 0), res3(6, 0, 0, 0);
	Polynom P1, P2, RES;
	P1.AddMonom(m1);
	P1.AddMonom(m2);
	P2.AddMonom(m3);
	P2.AddMonom(m4);
	RES.AddMonom(res1);
	RES.AddMonom(res2);
	RES.AddMonom(res3);
	EXPECT_EQ(P1 + P2, RES);
}
TEST(Polynom_Operators, Hard_Sub)
{
	MonomValue m1(1, 2, 4, 0), m2(10, 0, 0, 0), m3(-4, 0, 0, 0), m4(1, 3, 6, 2);
	MonomValue res1(-1, 3, 6, 2), res2(1, 2, 4, 0), res3(14, 0, 0, 0);
	Polynom P1, P2, RES;
	P1.AddMonom(m1);
	P1.AddMonom(m2);
	P2.AddMonom(m3);
	P2.AddMonom(m4);
	RES.AddMonom(res1);
	RES.AddMonom(res2);
	RES.AddMonom(res3);
	EXPECT_EQ(P1 - P2, RES);
}

