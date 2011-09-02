#ifndef __INDEX_TEST_H
#define __INDEX_TEST_H
#include "test.h"

BOOST_AUTO_TEST_SUITE(IndexTest)

BOOST_AUTO_TEST_CASE(Null)
{
    Index i1;
    BOOST_CHECK(i1.is_null());

    Index i2("i2");
    BOOST_CHECK(i2.is_not_null());
}

BOOST_AUTO_TEST_SUITE_END()

#endif