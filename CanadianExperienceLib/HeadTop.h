/**
 * @file HeadTop.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HEADTOP_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HEADTOP_H
#include "ImageDrawable.h"

class HeadTop : public ImageDrawable
{
private:

public:
    HeadTop(const std::wstring &name, const std::wstring &filename);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    bool IsMovable() override;
    wxPoint TransformPoint(wxPoint p);

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_HEADTOP_H
