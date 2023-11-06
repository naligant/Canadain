/**
 * @file PictureObserverTest.cpp
 * @author Prajeeth Naliganti
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <PictureObserver.h>

class PictureObserverMock : public PictureObserver
{
public:
    PictureObserverMock() : PictureObserver() {}

};

TEST(PictureObserverTest, Construct) {
    PictureObserverMock observer;
}