#include <cstdlib>
#include <iostream>
#include "NGLDraw.h"
#include <ngl/NGLInit.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>



int main()
{

  // Request a 24-bits depth buffer when creating the window
  sf::ContextSettings contextSettings;
  contextSettings.depthBits = 24;
  contextSettings.majorVersion=4;
  contextSettings.minorVersion=1;
  contextSettings.attributeFlags=sf::ContextSettings::Attribute::Core;
  // Create the main window
  sf::RenderWindow window(sf::VideoMode(1024,720), "SFML graphics with OpenGL", sf::Style::Default, contextSettings);
  window.setVerticalSyncEnabled(true);


  // we need to initialise the NGL lib which will load all of the OpenGL functions, this must
  // be done once we have a valid GL context but before we call any GL commands. If we dont do
  // this everything will crash
  ngl::NGLInit::instance();
  NGLDraw scene;
  while (window.isOpen())
  {
    // Process events
    sf::Event event;
    while (window.pollEvent(event))
    {
        // Close window: exit
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }

        // Escape key: exit
        if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
        {
            window.close();
        }
  // Adjust the viewport when the window is resized
        if (event.type == sf::Event::Resized)
        {
          scene.resize(event.size.width, event.size.height);
        }
     } // end pollEvents

    window.setActive(true);
    // Finally, display the rendered frame on screen

    scene.draw();

    window.display();

  } // end isOpen





}

