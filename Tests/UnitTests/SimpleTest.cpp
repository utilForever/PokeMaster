#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Simple test")
{
    CHECK(2 + 3 == 5);
}