// #include "../library/Entity.h"

// Entity::Entity(SDL_Renderer *_renderer) : position(), velocity(), acceleration(), side(false), health(100), texture(_renderer) {}

// const Vector& Entity::getPosition() const {
//     return position;
// }

// const Vector& Entity::getVelocity() const {
//     return velocity;
// }

// const Vector& Entity::getAcceleration() const {
//     return acceleration;
// }

// bool Entity::getSide() const {
//     return side;
// }

// int Entity::getHealth() const {
//     return health;
// }

// Texture Entity::getTexture() const {
//     return texture;
// }

// Sprite Entity::getSprite() const {
//     return sprite;
// }

// Direction Entity::getDirection() const {
//     return direction;
// }

// double Entity::getTextureWidth() const {
//     return getTexture().getWidth();
// }

// double Entity::getTextureHeight() const {
//     return getTexture().getHeight();
// }

// void Entity::setPosition(Vector _position) {
//     position = _position;
// }

// void Entity::setVelocity(Vector _velocity) {
//     velocity = _velocity;
// }

// void Entity::setAcceleration(Vector _acceleration) {
//     acceleration = _acceleration;
// }

// void Entity::setSide(bool _side) {
//     side = _side;
// }

// void Entity::setHealth(int _health) {
//     health = _health;
// }

// void Entity::setTexture(Texture _texture) {
//     texture = _texture;
// }

// void Entity::setSprite(Sprite _sprite) {
//     sprite = _sprite;
// }

// void Entity::setDirection(Direction _direction) {
//     direction = _direction;
// }

// bool Entity::collide(const Entity &other) const {
//     return (std::max(position.getX(), other.position.getX()) < std::min(position.getX() + texture.getWidth(), other.position.getX() + other.texture.getWidth())) && (std::max(position.getY(), other.position.getY()) < std::min(position.getY() + texture.getHeight(), other.position.getY() + other.texture.getHeight()));
// }