/**
 * @file Picture.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTURE_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTURE_H
/**
 * The picture we are drawing.
 *
 * There will be one picture object that contains all of
 * our actors, which then contains the drawables.
 */
class Picture
{
private:

public:
    /**
     * Constructor
     */
    Picture() {}

    /// Copy Constructor (Disabled)
    Picture(const Picture &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Picture &) = delete;

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTURE_H
