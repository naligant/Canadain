/**
 * @file PictureObserverTest.cpp
 * @author Prajeeth Naliganti
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <PictureObserver.h>
#include <Picture.h>

class PictureObserverMock : public PictureObserver
{
public:
    PictureObserverMock() : PictureObserver() {}
    bool mUpdated = false;
    virtual void UpdateObserver() override { mUpdated = true; }

};

TEST(PictureObserverTest, Construct) {
    PictureObserverMock observer;
}

TEST(PictureObserverTest, OneObserver) {
    // Allocate a Picture object
    auto picture = std::make_shared<Picture>();

    // Create a mock observer object
    PictureObserverMock observer;

    // And set it for the observer:
    observer.SetPicture(picture);

    picture->UpdateObservers();

    ASSERT_TRUE(observer.mUpdated);

}

TEST(PictureObserverTest, Getpicture) {
    // Allocate a Picture object
    auto picture = std::make_shared<Picture>();

    // Create a mock observer object
    PictureObserverMock observer;

    // And set it for the observer:
    observer.SetPicture(picture);

    auto temp = observer.GetPicture();

    ASSERT_EQ(temp, picture);
}

TEST(PictureObserverTest, TwoObservers) {
    // Allocate a Picture object
    auto picture = std::make_shared<Picture>();

    // Create mock observer objects
    PictureObserverMock observerOne;
    PictureObserverMock observerTwo;


    // And set it for the observers:
    observerOne.SetPicture(picture);
    observerTwo.SetPicture(picture);

    picture->UpdateObservers();

    ASSERT_TRUE(observerOne.mUpdated);
    ASSERT_TRUE(observerTwo.mUpdated);
}

TEST(PictureObserverTest, DestroyObserver) {
    // Allocate a Picture object
    auto picture = std::make_shared<Picture>();

    // Create mock observer objects
    PictureObserverMock observerOne;


    // And set it for the observers:
    observerOne.SetPicture(picture);

    {
        //Create a second observer
        PictureObserverMock observerTwo;
        //Add second observer to picture
        observerTwo.SetPicture(picture);
    }

    //Check if the first observer is still updated fine
    picture->UpdateObservers();

    ASSERT_TRUE(observerOne.mUpdated);


}