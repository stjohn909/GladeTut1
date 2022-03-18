#ifndef GTKMM_GLADEUI_H
#define GTKMM_GLADEUI_H

#include <gtkmm/builder.h>
#include <gtkmm/applicationwindow.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/label.h>
#include <gtkmm/fixed.h>
#include <cairomm/cairomm.h>

class GladeUi : public Gtk::Window
{

private:
    // Derived DrawingArea subclass.  We use a derived class
    // so we can do interesting things directly on our own Cairo 
    // context.
    // Also, gtkmm3 doesn't have any convenience methods for
    // painting on the Cairo context of a builder widget.  I
    // suppose a hack could be to create a cairo context in a
    // blank widget, but this is nicer.
    class ScopeDrawArea : public Gtk::DrawingArea
    {
        private:
        //Drawing event handler
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
        // TODO: Add a function pionter parameter for scope data. 
        // This should be the byte array for the scope channel
        // being drawn
        {
            Gtk::Allocation allocation = get_allocation();
            const int width = allocation.get_width();
            const int height = allocation.get_height();
            int xc, yc;
            xc = width/2;
            yc = height/2;

            //SetBackground
            cr->set_line_width(5.0);
            cr->save();
            cr->set_source_rgb(0,0,0);
            cr->paint();
            cr->restore();

            // draw red lines out from the center of the window
            cr->set_source_rgb(0.8, 0.0, 0.0);
            cr->move_to(0, 0);
            cr->line_to(xc, yc);
            cr->line_to(0, height);
            cr->move_to(xc, yc);
            cr->line_to(width, yc);
            cr->stroke();

            return true;  
        };
        public:
            ScopeDrawArea(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder):
            Gtk::DrawingArea(cobject)
            {
            }
            void DoDraw()
            {

                this->queue_draw();
            }
        
    };
    


protected:
    //Signal handlers
    void OnButtonClicked();


    //Member widgets
    Gtk::Fixed* pFixed;
    Gtk::Button* pButton;
    Gtk::Label* pLabel;
    ScopeDrawArea* pDrawingArea;
    //Gtk::DrawingArea* ScopeDrawArea;

    Glib::RefPtr<Gtk::Builder> refBuilder;

public:
    GladeUi();
    virtual ~GladeUi();


};
#endif //GTKMM_GLADEUI_H