#include <iostream>
#include "GladeUi.h"
#include <gtkmm/drawingarea.h>
#include <glibmm.h>



// We are derived from Gtk::ApplicationWindow
GladeUi::GladeUi() :
refBuilder(Gtk::Builder::create())
{
    // Test for issues with the glade file.
    try
    {
    refBuilder->add_from_file("GladeTut1.glade");
    }
    catch(const Glib::FileError& ex)
    {
    std::cerr << "FileError: " << ex.what() << std::endl;
    return;
    }
    catch(const Glib::MarkupError& ex)
    {
    std::cerr << "MarkupError: " << ex.what() << std::endl;
    return;
    }
    catch(const Gtk::BuilderError& ex)
    {
    std::cerr << "BuilderError: " << ex.what() << std::endl;
    return;
    }

    //get the container from the builder
    refBuilder->get_widget("fixed1", pFixed);

    //get the button from the builder and connect it to a function
    refBuilder->get_widget("button1", pButton);
    //pButton->signal_clicked().connect(sigc::ptr_fun(OnButtonClicked) );  //Why doesn't this work?

    // Get the drawing area and connect it to a function
    refBuilder->get_widget_derived("draw1", pDrawingArea);
    //pDrawingArea = Glib::RefPtr<Gtk::DrawingArea>::cast_dynamic(refBuilder->get_object("draw1"));

    add(*pFixed);
    set_title("VM205 Oscilloscope");
    //set_default_size(1280, 720);

    show_all();

}
GladeUi::~GladeUi() 
{}


void GladeUi::OnButtonClicked()
{
    puts("Clicking...");

}
