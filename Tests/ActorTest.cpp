/**
 * @file ActorTest.cpp
 * @author Prajeeth Naliganti
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Actor.h>

TEST(ActorTest, Constructor)
{
    Actor actor(L"Harold");
    ASSERT_EQ(std:: wstring(L"Harold"), actor.GetName());
}

TEST(ActorTest, Enabled)
{
    Actor actor(L"Harold");
    ASSERT_TRUE(actor.IsEnabled());

    actor.SetEnabled(false);
    ASSERT_TRUE(!actor.IsEnabled());

}

TEST(ActorTest, Clickable)
{
    Actor actor(L"Harold");
    ASSERT_TRUE(actor.IsClickable());

    actor.SetClickable(false);
    ASSERT_TRUE(!actor.IsClickable());
}

TEST(ActorTest, Position)
{
    Actor actor(L"Harold");
    auto point = actor.GetPosition();
    ASSERT_EQ(0, actor.GetPosition().x);
    ASSERT_EQ(0, actor.GetPosition().y );

    auto newPoint = wxPoint(24, 500);
    actor.SetPosition(newPoint);
    ASSERT_EQ(24, actor.GetPosition().x);
    ASSERT_EQ(500, actor.GetPosition().y);
}