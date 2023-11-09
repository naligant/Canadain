/**
 * @file PictureFactory.cpp
 * @author Prajeeth Naliganti
 */
#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "Actor.h"
#include "HaroldFactory.h"

using namespace std;

/**
 * Factory method to create a new picture.
 * @param imagesDir Directory that contains the images for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring imagesDir)
{
    shared_ptr<Picture> picture = make_shared<Picture>();

    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(300, 500));
    picture->AddActor(harold);

    return picture;
}