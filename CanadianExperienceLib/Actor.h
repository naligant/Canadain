/**
 * @file Actor.h
 * @author Prajeeth Naliganti
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ACTOR_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ACTOR_H
class Drawable;
class Picture;

/**
 * Class for actors in our drawings.
 *
 * An actor is some graphical object that consists of
 * one or more parts. Actors can be animated.
 */

class Actor
{
private:
    /// The actor name
    std::wstring mName;

    /// Is this actor enabled (drawable)?
    bool mEnabled = true;

    /// The actor position
    wxPoint mPosition;

    /// Is this actor mouse clickable?
    bool mClickable = true;

    /// The root drawable
    std::shared_ptr<Drawable> mRoot;

    /// The picture using this actor
    Picture *mPicture = nullptr;

    /// The drawables in drawing order
    std::vector<std::shared_ptr<Drawable>> mDrawablesInOrder;
public:
    /// Destructor
    virtual ~Actor() {}

    Actor(const std::wstring &name);

    /// Default constructor disabled
    Actor() = delete;
    /// Copy Constructor (Disabled)
    Actor(const Actor &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Actor &) = delete;

    void SetRoot(std::shared_ptr<Drawable> root);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    std::shared_ptr<Drawable> HitTest(wxPoint pos);
    void AddDrawable(std::shared_ptr<Drawable> drawable);
    /**
     * Gets picture
     * @return picture
     */
    Picture* GetPicture() {return mPicture;}

    /**
     * Get the actor name
     * @return Actor name
     */
    std::wstring GetName() const { return mName; }

    /**
     * The actor position
     * @return The actor position as a point
     */
    wxPoint GetPosition() const { return mPosition; }

    /**
     * The actor position
     * @param pos The new actor position
     */
    void SetPosition(wxPoint pos) { mPosition = pos; }


    /**
     * Actor is enabled
     * @return enabled status
     */
    bool IsEnabled() const { return mEnabled; }

    /**
     * Set Actor Enabled
     * @param enabled New enabled status
     */
    void SetEnabled(bool enabled) { mEnabled = enabled; }

    /**
     * Actor is clickable
     * @return true if actor is clickable
     */
    bool IsClickable() const { return mClickable; }

    /**
     * Actor clickable
     * @param clickable New clickable status
     */
    void SetClickable(bool clickable) { mClickable = clickable; }

    /**
     * Sets picture
     * @param picture
     */
    void SetPicture(Picture* picture) {mPicture = picture;}
protected:


};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_ACTOR_H
