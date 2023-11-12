/**
 * @file ImageDrawable.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_IMAGEDRAWABLE_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_IMAGEDRAWABLE_H
#include "Drawable.h"
/**
 * class that hosts all images that are drawable
 */
class ImageDrawable : public Drawable
{
private:
    wxPoint mCenter = wxPoint(0, 0);

public:
    ImageDrawable(const std::wstring &name, const std::wstring &filename);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    bool HitTest(wxPoint pos) override;

    ///getter for the center of image
    wxPoint GetCenter() {return mCenter;}

    /// setter for the center of image
    void SetCenter(wxPoint center) {mCenter = center;}

protected:
    /// The image we are drawing
    std::unique_ptr<wxImage> mImage;

    /// The graphics bitmap we will use
    wxGraphicsBitmap mBitmap;


};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_IMAGEDRAWABLE_H
