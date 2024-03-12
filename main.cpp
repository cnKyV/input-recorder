#include "include/sequence.hpp"

int main()
{
    auto * sequence = new Sequence();

    sequence->begin();

    delete sequence;

    return 0;
}