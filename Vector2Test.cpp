#include "gtest/gtest.h"
#include "Vector2.hpp"
#include<iostream>
#include<cstdlib>
#include <vector>

#define N_TESTS 1000
#define HI 50000
#define LO -50000

class Vector2Test: 
    public ::testing::Test
{
    public:

    using  Vector2f = Vector2<float>;
    using  Vector2i = Vector2<int>;
    using  limitf = std::numeric_limits<float>;

    std::vector<Vector2f> r_float_cases;

    Vector2Test()
    {
        for(int i=0; i<N_TESTS; ++i)
        {
            float x = getRandomFloat();
            float y = getRandomFloat();

            r_float_cases.push_back(Vector2f(x, y));
        } 
    }

    float getRandomFloat()
    {
        return LO + static_cast<float>(rand())/static_cast<float>(RAND_MAX/(HI - LO));
    }   

    protected:

        virtual void SetUp(){};

        virtual void TearDown(){};
};

TEST_F(Vector2Test, DefaultConstructorTest)
{
    std::vector<Vector2f> z_float_cases(N_TESTS);

    for(auto& p:z_float_cases)
    {

        ASSERT_EQ(0, p.x)
            <<"Vector2 was not initialized to zero";
        
        ASSERT_EQ(0, p.y)
            <<"Vector2 was not initialized to zero";
    }
}

TEST_F(Vector2Test, ConstructorTest)
{
    for(int i = 0; i<N_TESTS; ++i)
    {
        float x = getRandomFloat();
        float y = getRandomFloat();
        Vector2f p(x, y);

        ASSERT_EQ(x, p.x);
        ASSERT_EQ(y, p.y);         
    }
}

TEST_F(Vector2Test, CopyConstructorTest)
{
    std::vector<Vector2f> float_cases(r_float_cases);

    for(int i=0; i< N_TESTS; ++i)
    {
        ASSERT_EQ(float_cases[i].x, r_float_cases[i].x);
        ASSERT_EQ(float_cases[i].y, r_float_cases[i].y);
    }
}

TEST_F(Vector2Test, CopyAssignmentTest)
{    
    for(auto& p1:r_float_cases)
    {
        Vector2f p2;
        p2 = p1;

        ASSERT_EQ(p1.x, p2.x);
        ASSERT_EQ(p1.y, p2.y);
    }  
}

