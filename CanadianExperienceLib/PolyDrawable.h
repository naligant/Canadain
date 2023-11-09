/**
 * @file PolyDrawable.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_POLYDRAWABLE_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_POLYDRAWABLE_H

/**
 * A drawable based on polygon images.
 *
 * This class has a list of points and draws a polygon
 * drawable based on those points.
 */
#include "Drawable.h"
class PolyDrawable : public Drawable
{
private:
    /// The polygon color
    wxColour mColor = *wxBLACK;

    /// Points
    std::vector<wxPoint> mPoints;

    /// The transformed graphics path used
    /// to draw this polygon
    wxGraphicsPath mPath;
public:

    /// Default constructor (disabled)
    PolyDrawable() = delete;

    /// Copy constructor (disabled)
    PolyDrawable(const PolyDrawable &) = delete;

    /// Assignment operator
    void operator=(const PolyDrawable &) = delete;

    ///Getter for polygon color
    wxColour GetColor() {return mColor;}

    ///Setter fot polygon color
    void SetColor(wxColour color) {mColor = color;}

    PolyDrawable(const std::wstring &name);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    bool HitTest(wxPoint pos) override;

    /**
     * Add a point
     * @param point
     */
     void AddPoint(wxPoint point);

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_POLYDRAWABLE_H
