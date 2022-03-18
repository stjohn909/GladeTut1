#ifndef GTKMM_EXAMPLE_GLADETUT1_H
#define GTKMM_EXAMPLE_GLADETUT1_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/builder.h>

class GladeTut1 : public Gtk::Window
{

public:
  GladeTut1();
  virtual ~GladeTut1();

protected:
  //Signal handlers:
  void on_button_clicked();

  //Member widgets:
  Gtk::Button m_button;
};

#endif // GTKMM_EXAMPLE_GLADETUT1_H