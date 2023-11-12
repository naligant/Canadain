/**
 * @file HeadTop.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HEADTOP_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HEADTOP_H
#include "ImageDrawable.h"
/**
 * Class that draws head of harold seperately
 */
class HeadTop : public ImageDrawable
{
private:

public:
    /**
     * constructor
     * @param name
     * @param filename
     */
    HeadTop(const std::wstring &name, const std::wstring &filename);
    /**
     * draw override
     * @param graphics
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    /**
     * is movable override
     * @return true or false
     */
    bool IsMovable() override;
    wxPoint TransformPoint(wxPoint p);

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HEADTOP_H
