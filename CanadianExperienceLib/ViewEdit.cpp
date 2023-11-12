/**
 * @file ViewEdit.cpp
 * @author Charles B. Owen
 */
#include "pch.h"
#include <wx/dcbuffer.h>
#include <wx/xrc/xmlres.h>
#include "ViewEdit.h"
#include "Actor.h"
#include "Drawable.h"
#include "Picture.h"

using namespace std;

/// A scaling factor, converts mouse motion to rotation in radians
const double RotationScaling = 0.02;

/**
 * Constructor
 * @param parent Pointer to wxFrame object, the main frame for the application
 */
ViewEdit::ViewEdit(wxFrame* parent) : wxScrolledCanvas(parent, wxID_ANY)
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &ViewEdit::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &ViewEdit::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &ViewEdit::OnLeftUp, this);
    Bind(wxEVT_MOTION, &ViewEdit::OnMouseMove, this);

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &ViewEdit::OnEditMove, this, XRCID("EditMove"));
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &ViewEdit::OnEditRotate, this, XRCID("EditRotate"));
    parent->Bind(wxEVT_UPDATE_UI, &ViewEdit::OnUpdateEditMove, this, XRCID("EditMove"));
    parent->Bind(wxEVT_UPDATE_UI, &ViewEdit::OnUpdateEditRotate, this, XRCID("EditRotate"));
}




/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void ViewEdit::OnPaint(wxPaintEvent& event)
{
    auto size = GetPicture()->GetSize();
    SetVirtualSize(size.GetWidth(), size.GetHeight());
    SetScrollRate(1, 1);

    wxAutoBufferedPaintDC dc(this);
    DoPrepareDC(dc);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create( dc ));

    GetPicture()->Draw(graphics);


}



/**
 * Handle the left mouse button down event
 * @param event
 */
void ViewEdit::OnLeftDown(wxMouseEvent &event)
{
    auto click = CalcUnscrolledPosition(event.GetPosition());
    mLastMouse = click;

    //
    // Did we hit anything?
    //

    std::shared_ptr<Actor> hitActor;
    std::shared_ptr<Drawable> hitDrawable;
    for (auto actor : *GetPicture())
    {
        // Note: We do not exit when we get the first hit, since
        // we are looking at these in drawing order. Instead, we
        // keep the last hit.
        std::shared_ptr<Drawable> drawable =
            actor->HitTest(wxPoint(click.x, click.y));
        if (drawable != nullptr)
        {
            hitActor = actor;
            hitDrawable = drawable;
        }
    }

    // If we hit something determine what we do with it based on the
    // current mode.
    if (hitActor != nullptr)
    {
        mSelectedActor = hitActor;
        mSelectedDrawable = hitDrawable;
    }
}

/**
* Handle the left mouse button up event
* @param event
*/
void ViewEdit::OnLeftUp(wxMouseEvent &event)
{
    OnMouseMove(event);
}

/**
* Handle the mouse move event
* @param event
*/
void ViewEdit::OnMouseMove(wxMouseEvent &event)
{
    auto click = CalcUnscrolledPosition(event.GetPosition());

    wxPoint newMouse(click.x, click.y);
    wxPoint delta = newMouse - mLastMouse;
    mLastMouse = newMouse;

    if (event.LeftIsDown())
    {
        switch (mMode)
        {
            case Mode::Move:
                if (mSelectedDrawable != nullptr)
                {
                    if (mSelectedDrawable->IsMovable())
                    {
                        mSelectedDrawable->Move(delta);
                    }
                    else
                    {
                        mSelectedActor->SetPosition(mSelectedActor->GetPosition() + delta);
                    }
                    GetPicture()->UpdateObservers();
                }
                break;

            case Mode::Rotate:
                if (mSelectedDrawable != nullptr)
                {
                    mSelectedDrawable->SetRotation(mSelectedDrawable->GetRotation() + delta.y * RotationScaling);
                    GetPicture()->UpdateObservers();
                }
                break;

            default:
                break;
        }

    }
    else
    {
        mSelectedDrawable = nullptr;
        mSelectedActor = nullptr;
    }
}

/**
 * Force an update of this window when the picture changes.
 */
void ViewEdit::UpdateObserver()
{
    Refresh();
}
/**
 * move mode
 * @param event
 */
void ViewEdit::OnEditMove(wxCommandEvent& event)
{
    mMode = Mode::Move;
}
/**
 * rotate mode
 * @param event
 */
void ViewEdit::OnEditRotate(wxCommandEvent& event)
{
    mMode = Mode::Rotate;
}
/**
 * update move
 * @param event
 */
void ViewEdit::OnUpdateEditMove(wxUpdateUIEvent& event)
{
    if (mMode == Mode::Move)
    {
        event.Check(true);
        event.Enable(false);
    }
    else
    {
        event.Check(false);
        event.Enable(true);
    }
}
/**
 * update rotate
 * @param event
 */
void ViewEdit::OnUpdateEditRotate(wxUpdateUIEvent& event)
{
    if (mMode == Mode::Rotate)
    {
        event.Check(true);
        event.Enable(false);
    }
    else
    {
        event.Check(false);
        event.Enable(true);
    }
}

