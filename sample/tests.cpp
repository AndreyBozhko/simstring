#include <cmath>
#include <iostream>
#include "simstring/simstring.h"

using simstring::measure::dice;


#define IS_EQUAL(x, y) { if (!(x == y)) std::cout << "Assertion failed in " << __FILE__ << ", line " << __LINE__ << ": " << (x) << " not equal to " << (y) << std::endl; }


void test_dice_min_size()
{
    IS_EQUAL(std::max(dice::min_size(1, 0.5), 1), 1);
    IS_EQUAL(std::max(dice::min_size(2, 0.5), 1), 1); // leads to undefined behavior
    IS_EQUAL(std::max(dice::min_size(5, 0.5), 1), 1); // should be 2
    IS_EQUAL(std::max(dice::min_size(10, 0.5), 1), 1); // should be 4
    IS_EQUAL(std::max(dice::min_size(15, 0.5), 1), 1); // should be 5
    IS_EQUAL(std::max(dice::min_size(20, 0.5), 1), 1); // should be 7
}

int main() {
    test_dice_min_size();
    return 0;
}
