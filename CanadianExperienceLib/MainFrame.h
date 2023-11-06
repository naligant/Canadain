/**
 * @file MainFrame.h
 * @author Charles B. Owen
 *
 * The top-level (main) frame of the application
 */
#ifndef _MAINFRAME_H_
#define _MAINFRAME_H_

/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame
{
private:


public:
    MainFrame();
    void Initialize();
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent&event);
};

#endif //_MAINFRAME_H_
