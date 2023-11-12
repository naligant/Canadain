/**
 * @file PictureFactory.cpp
 * @author Prajeeth Naliganti
 */
#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "Actor.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "ImageDrawable.h"

using namespace std;

/**
 * Factory method to create a new picture.
 * @param imagesDir Directory that contains the images for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring imagesDir)
{
    shared_ptr<Picture> picture = make_shared<Picture>();

    // Create the background and add it
    auto background = make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI = make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background.jpg");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);
    // Create and add characters
    HaroldFactory haroldFactory;
    SpartyFactory spartyFactory;
    auto harold = haroldFactory.Create(imagesDir);
    auto sparty = spartyFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(300, 500));
    picture->AddActor(harold);

    // This is where Sparty will start out.
    sparty->SetPosition(wxPoint(700, 450));
    picture->AddActor(sparty);

    return picture;
}