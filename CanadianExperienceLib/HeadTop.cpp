/**
 * @file HeadTop.cpp
 * @author Prajeeth Naliganti
 */
#include "pch.h"
#include "HeadTop.h"

HeadTop::HeadTop(const std::wstring &name, const std::wstring &filename) : ImageDrawable(name, filename)
{
}

bool HeadTop::IsMovable()
{
    return true;
}

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* @param  p Point to transform
* @returns Transformed point
*/
wxPoint HeadTop::TransformPoint(wxPoint p)
{
    // Make p relative to the image center
    p = p - GetCenter();

    // Rotate as needed and offset
    return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

void HeadTop::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    ImageDrawable::Draw(graphics);

    float wid = 15.0f;
    float hit = 20.0f;

    //random line
    wxPoint leftEye = TransformPoint(wxPoint(40, 75));
    wxPoint rightEye = TransformPoint(wxPoint(70, 75));
    wxPoint leftEyebrowOne = TransformPoint(wxPoint(40 + wid/2 - 2, 75 - hit/2 - 6));
    wxPoint rightEyebrowOne = TransformPoint(wxPoint(70 + wid/2 + 2, 75 - hit/2 - 5));
    wxPoint leftEyebrowTwo = TransformPoint(wxPoint(40 - wid/2 - 2, 75 - hit/2 - 5));
    wxPoint rightEyebrowTwo = TransformPoint(wxPoint(70 - wid/2 + 2, 75 - hit/2 - 6));
    wxPen eyebrowPen(*wxBLACK, 2);
    graphics->SetPen(eyebrowPen);
    graphics->SetBrush(*wxBLACK);

    //left and right eyebrow
    graphics->StrokeLine(leftEyebrowOne.x, leftEyebrowOne.y, leftEyebrowTwo.x, leftEyebrowTwo.y);
    graphics->StrokeLine(rightEyebrowOne.x, rightEyebrowOne.y, rightEyebrowTwo.x, rightEyebrowTwo.y);

    //left eye
    graphics->PushState();
    graphics->Translate(leftEye.x, leftEye.y);
    graphics->Rotate(-mPlacedR);
    graphics->DrawEllipse(-wid/2, -hit/2, wid, hit);
    graphics->PopState();

    //right eye
    graphics->PushState();
    graphics->Translate(rightEye.x, rightEye.y);
    graphics->Rotate(-mPlacedR);
    graphics->DrawEllipse(-wid/2, -hit/2, wid, hit);
    graphics->PopState();
}