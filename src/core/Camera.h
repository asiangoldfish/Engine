#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>

class Camera
{
private:
    sf::View view;
    float currentZoom;

    sf::Vector2f originalViewsize;
    float maxZoom;  ///< Max zoom based on original view <size
    float minZoom;  ///< Min zoom based on original view <size

public:
    Camera(sf::RenderTarget &target);
    virtual ~Camera();
    sf::View getView() { return view; }

    /**
     * @brief Move the camera view relative to where it was.
     * The x and y inputs signify by how much it should move relative to the
     * current position.
     * 
     * @param x X direction
     * @param y Y direction
     */
    void moveCamera(float x, float y, sf::RenderTarget &target);

    void zoom(float delta, sf::RenderTarget &target);
};

#endif