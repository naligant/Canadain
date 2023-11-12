/**
 * @file SpartyFactory.cpp
 * @author Prajeeth Naliganti
 */

#include "pch.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "HeadTop.h"
#include "SpartyTop.h"
#include "PolyDrawable.h"
#include "ImageDrawable.h"


std::shared_ptr<Actor> SpartyFactory::Create(std::wstring imagesDir)
{
    shared_ptr<Actor> actor = make_shared<Actor>(L"Sparty");

    auto torso = make_shared<ImageDrawable>(L"Torso", imagesDir + L"/sparty_torso.png");
    torso->SetCenter(wxPoint(44, 138));
    torso->SetPosition(wxPoint(0, -114));
    actor->SetRoot(torso);

    auto lleg = make_shared<ImageDrawable>(L"Left Leg", imagesDir + L"/sparty_lleg.png");
    lleg->SetCenter(wxPoint(11, 9));
    lleg->SetPosition(wxPoint(27, 30));
    torso->AddChild(lleg);

    auto rleg = make_shared<ImageDrawable>(L"Right Leg", imagesDir + L"/sparty_rleg.png");
    rleg->SetCenter(wxPoint(39, 9));
    rleg->SetPosition(wxPoint(-3, 25));
    torso->AddChild(rleg);

    auto headb = make_shared<ImageDrawable>(L"Head Bottom", imagesDir + L"/sparty_lhead.png");
    headb->SetCenter(wxPoint(44, 31));
    headb->SetPosition(wxPoint(17, -100));
    torso->AddChild(headb);

    auto headt = make_shared<SpartyTop>(L"Head Top", imagesDir + L"/sparty_head.png");
    headt->SetCenter(wxPoint(55, 109));
    headt->SetPosition(wxPoint(15, -60));
    headb->AddChild(headt);

//    auto leye = make_shared<SpartyTop>(L"Left Eye", imagesDir + L"/sparty_leye.png");
//    leye->SetCenter(wxPoint(17, -51));
//    leye->SetPosition(wxPoint(15, -60));
//    headt->AddChild(leye);
//
//    auto reye = make_shared<SpartyTop>(L"Right Eye", imagesDir + L"/sparty_reye.png");
//    reye->SetCenter(wxPoint(49, -50));
//    reye->SetPosition(wxPoint(15, -60));
//    headt->AddChild(reye);

    auto larm = make_shared<ImageDrawable>(L"Left Arm", imagesDir + L"/sparty_larm.png");
    larm->SetCenter(wxPoint(-7, -7));
    larm->SetPosition(wxPoint(50, -130));
    torso->AddChild(larm);

    auto rarm = make_shared<ImageDrawable>(L"Right Arm", imagesDir + L"/sparty_rarm.png");
    rarm->SetCenter(wxPoint(100, -7));
    rarm->SetPosition(wxPoint(-10, -130));
    torso->AddChild(rarm);

    actor->AddDrawable(rleg);
    actor->AddDrawable(lleg);
    actor->AddDrawable(torso);
    actor->AddDrawable(larm);
    actor->AddDrawable(rarm);
    actor->AddDrawable(headb);
    actor->AddDrawable(headt);
//    actor->AddDrawable(leye);
//    actor->AddDrawable(reye);

    return actor;
}