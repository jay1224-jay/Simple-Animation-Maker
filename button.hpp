

class Button : public rect {

    public :
        bool isClick( sf::Event::MouseButtonEvent );

} ;

bool Button::isClick( sf::Event::MouseButtonEvent mouse_pos ) {

    return this->getGlobalBounds().contains( mouse_pos.x, mouse_pos.y );

}
