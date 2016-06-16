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

    std::vector<Vector2f> float_cases;
    std::vector<Vector2i> int_cases;

    float getRandomFloat()
    {
        return LO + static_cast<float>(rand())/static_cast<float>(RAND_MAX/(HI - LO));
    }   

    protected:
        virtual void SetUp()
        {
            float_cases.reserve(N_TESTS);
            int_cases.reserve(N_TESTS);
        };

        virtual void TearDown()
        {
            float_cases.clear();
            int_cases.clear();
        };

};

TEST_F(Vector2Test, DefaultConstructorTest)
{
    for(int i = 0; i<N_TESTS; ++i)
    {
        float_cases.push_back(Vector2f());
        int_cases.push_back(Vector2i());

        ASSERT_EQ(int_cases[i].x, float_cases[i].x);
        ASSERT_EQ(int_cases[i].y, float_cases[i].y);
    }
}

TEST_F(Vector2Test, ConstructorTest)
{
    for(int i=0; i<N_TESTS; ++i)
    {
        
        float x = getRandomFloat();
        float y = getRandomFloat();
        
        Vector2f p(x,y);

        ASSERT_EQ(x, p.x);
        ASSERT_EQ(y, p.y);
    } 
}

TEST_F(Vector2Test, CopyConstructorTest)
{
    for(int i = 0; i<N_TESTS; ++i)
    {
        float x = getRandomFloat();
        float y = getRandomFloat();

        float_cases.push_back(Vector2f(x, y));
    }

    for(auto& p1:float_cases)
    {
        Vector2f p2(p1);

        ASSERT_EQ(p1.x, p2.x);
        ASSERT_EQ(p1.y, p2.y);
        ASSERT_NE(&p1, &p2);
    }
}
