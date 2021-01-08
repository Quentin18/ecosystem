// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "animals.hpp"
#include "rabbit.hpp"

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

// TODO to complete
