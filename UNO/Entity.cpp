#include "Entity.h"

Entity::Entity()
{
	shape.setSize(Vector2f(50.f, 50.f));
	shape.setFillColor(Color::White);
	movement_speed = 100.f;
}

Entity::~Entity()
{
}

void Entity::move(const float &_dt, const float & _x_direction, const float & _y_direction)
{
	shape.move(_x_direction * movement_speed * _dt, _y_direction * movement_speed * _dt);
}

void Entity::update(const float & _dt)
{
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		this->move(_dt, 0.f, 0 - 1.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		this->move(_dt, -1.f, 0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		this->move(_dt, 0.f, 1.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		this->move(_dt, 1.f, 0.f);
	}

}

void Entity::render(RenderTarget *_target)
{
	_target->draw(shape);
}
