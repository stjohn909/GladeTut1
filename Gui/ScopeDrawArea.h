#ifndef GTKMM_SCOPEDRAWAREA_H
#define GTKMM_SCOPEDRAWAREA_H


#include <gtkmm/builder.h>
#include <gtkmm/applicationwindow.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/label.h>
#include <gtkmm/fixed.h>
#include <glibmm.h>
#include <cairomm/cairomm.h>

class ScopeDrawArea : public Gtk::DrawingArea
{

private:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
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

        return true;
    }

public:
    ScopeDrawArea(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder):
    Gtk::DrawingArea(cobject)
    {
    }
    const Cairo::RefPtr<Cairo::Context>& cr;
    bool DoDraw()
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
        cr->set_source_rgb(0,0,1);
        cr->paint();
        cr->restore();
        this->queue_draw();
    }

};

#endif //ScopeDrawArea