/**
 * @file PolyDrawable.cpp
 * @author Prajeeth Naliganti
 */

#include "pch.h"
#include "PolyDrawable.h"

/**
 * Constructor
 * @param name The drawable name
 */
PolyDrawable::PolyDrawable(const std::wstring &name) : Drawable(name)
{
}

/**
 * Draw our polygon.
 * @param  graphics The graphics context to draw on
 */
void PolyDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
}