// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include <list>

#include "catch.hpp"

#include "animals.hpp"
#include "rabbit.hpp"
#include "foods.hpp"
#include "distributions.hpp"

TEST_CASE("1: Tests on Animals")
{
    Animals<Rabbit> rabbits;
    REQUIRE(rabbits.empty());
    REQUIRE(rabbits.getNb() == 0);
    REQUIRE(rabbits.getNbEaten() == 0);
    REQUIRE(rabbits.getNbBirths() == 0);
    rabbits.init(30);
    REQUIRE(rabbits.getNb() == 30);
    REQUIRE_FALSE(rabbits.empty());
}

TEST_CASE("2: Tests on Foods")
{
    Foods foods;
    foods.init(10);
    REQUIRE(foods.getList()->size() == 10);
}

TEST_CASE("3: Random distribution")
{
    float n;
    for (size_t i = 0; i < 100; i++)
    {
        n = RAND_DISTRIBUTION(RANDOM_ENGINE);
        REQUIRE((n >= 0 && n <= 1));
    }
}

// TODO to complete
