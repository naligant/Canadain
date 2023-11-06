/**
 * @file PictureObserver.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTUREOBSERVER_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTUREOBSERVER_H

/**
 * Observer base class for a picture.
 *
 * This class implements the base class functionality for
 * an observer in the observer pattern.
 */
class PictureObserver
{
private:

public:
    ~PictureObserver();
    /// Copy Constructor (Disabled)
    PictureObserver(const PictureObserver &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const PictureObserver &) = delete;
    /// This function is called to update any observers
    virtual void UpdateObserver() = 0;
protected:
    /// Constructor
    PictureObserver() {}

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_PICTUREOBSERVER_H
