/**
 * @file SpartyTop.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_SPARTYTOP_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_SPARTYTOP_H
#include "ImageDrawable.h"
/**
 * Draws top of sparty's head separately
 */
class SpartyTop : public ImageDrawable
{
private:

public:
    /**
     * constructor
     * @param name
     * @param filename
     */
    SpartyTop(const std::wstring &name, const std::wstring &filename);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    bool IsMovable()override;
    wxPoint TransformPoint(wxPoint p);

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_SPARTYTOP_H
