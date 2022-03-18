#include <gtkmm/application.h>
#include <gtkmm/drawingarea.h>
#include <glibmm.h>
#include <iostream>

#include "GladeUi.h"



// Instatiate the window.
int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create();
    //GladeTut1 hw;
    GladeUi Ui;

    return app->run(Ui);

}

