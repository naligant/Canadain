/**
 * @file ViewEdit.cpp
 * @author Charles B. Owen
 */
#include "pch.h"
#include <wx/dcbuffer.h>
#include "ViewEdit.h"
#include "Picture.h"

using namespace std;


/**
 * Constructor
 * @param parent Pointer to wxFrame object, the main frame for the application
 */
ViewEdit::ViewEdit(wxFrame* parent) : wxWindow(parent, wxID_ANY)
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &ViewEdit::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &ViewEdit::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &ViewEdit::OnLeftUp, this);
    Bind(wxEVT_MOTION, &ViewEdit::OnMouseMove, this);
}




/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void ViewEdit::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);

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
    GetPicture()->UpdateObservers();
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
}

/**
 * Force an update of this window when the picture changes.
 */
void ViewEdit::UpdateObserver()
{
    Refresh();
}

