/**
 * @file PictureTest.cpp
 * @author Prajeeth Naliganti
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Picture.h>


TEST(PictureTest, Get)
{
    Picture picture;

    auto size = picture.GetSize();
    ASSERT_EQ(1500, size.GetWidth());
    ASSERT_EQ(800, size.GetHeight());

    picture.SetSize(wxSize(123, 456));
    size = picture.GetSize();
    ASSERT_EQ(123, size.GetWidth());
    ASSERT_EQ(456, size.GetHeight());
}