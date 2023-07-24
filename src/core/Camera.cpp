#include "core/Camera.h"
#include "Camera.h"

#include <SFML/Graphics.hpp>

#include "shared/pch.h"

// Constructor
Camera::Camera(sf::RenderTarget &target)
{
    float screenPercent = 0.95f;
    originalViewsize = sf::Vector2f(400.f, 400.f);
    currentZoom = 1.f;
    maxZoom = 0.5f;
    minZoom = 1.f;

	view.setCenter(sf::Vector2f(
        target.getSize().x / 2.f, 
        target.getSize().y / 2.f
    ));

	view.setSize(originalViewsize);
    // view.zoom(0.25f);
	
	// Viewport
	view.setViewport(sf::FloatRect(
        1.f - screenPercent,    // Left pos
        1.f - screenPercent,    // Top pos
        screenPercent,          // Width
        screenPercent         // height
    ));

	// Activate viewport
	target.setView(view);
}

// Destructur
Camera::~Camera()
{
}

// Move camera
void Camera::moveCamera(float x, float y, sf::RenderTarget &target)
{
    view.move(x, y);
    target.setView(view);
}

void Camera::zoom(float delta, sf::RenderTarget& target)
{
    // Update zoom property
    float factor = 200.f;

    if (view.getSize().x + factor * delta > originalViewsize.x * maxZoom &&
        view.getSize().x + factor * delta < originalViewsize.y * minZoom) {
        // Set zoom to view
        view.setSize({
            view.getSize().x + factor * delta,
            view.getSize().y + factor * delta 
        });

        // Apply to window
        target.setView(view);
    }
}
