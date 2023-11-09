/**
 * @file PolyDrawableTest.cpp
 * @author Prajeeth Naliganti
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <PolyDrawable.h>

TEST(PolyDrawableTest, Constructor)
{
    PolyDrawable polyDrawable(L"Harold");
    ASSERT_EQ(std::wstring(L"Harold"), polyDrawable.GetName());
}

TEST(PolyDrawableTest, Color)
{
    PolyDrawable polyDrawable(L"Harold");
    ASSERT_EQ(*wxBLACK, polyDrawable.GetColor());

    polyDrawable.SetColor(*wxWHITE);
    ASSERT_EQ(*wxWHITE, polyDrawable.GetColor());
}