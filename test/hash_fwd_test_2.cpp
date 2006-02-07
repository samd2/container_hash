//  (C) Copyright Daniel James 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// This test just makes sure a header which uses hash_fwd can compile without
// the main hash headers.

#include "./hash_fwd_test.hpp"

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

template <class T> void unused(T const&) {}

BOOST_AUTO_TEST_CASE(fwd_test)
{
    test::test_type1<int> x1(3);
    test::test_type1<std::string> y1("Black");
    test::test_type2<int> x2(25, 16);
    test::test_type2<std::string> y2("White", "Green");

    std::vector<int> empty;
    std::vector<std::string> empty2;

    test::test_type3<int> x3(empty.begin(), empty.end());
    test::test_type3<std::string> y3(empty2.begin(), empty2.end());

    // Prevent gcc warnings:
    unused(x1); unused(x2); unused(x3);
    unused(y1); unused(y2); unused(y3);
}