#include <iostream>
#include "GladeTut1.h"

GladeTut1::GladeTut1()
: m_button("GladeTut1 Button")   // creates a new button with label "Hello World".
{
  // Sets the margin around the button.
  m_button.set_border_width(1);

  // When the button receives the "clicked" signal, it will call the
  // on_button_clicked() method defined below.
  m_button.signal_clicked().connect(sigc::mem_fun(*this,
              &GladeTut1::on_button_clicked));

  // This packs the button into the Window (a container).
  add(m_button);

  // This reveals the button in the window
  m_button.show();
  
}

GladeTut1::~GladeTut1()
{
}

void GladeTut1::on_button_clicked()
{
  std::cout << "Hello World" << std::endl;
}