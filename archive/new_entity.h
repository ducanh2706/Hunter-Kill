// class Entity {
// private:
//     Vector position;
//     Vector velocity;
//     Vector acceleration;

//     Texture texture;
//     Sprite sprite;
//     Direction direction;

//     bool side;
//     int health;

// public:
//     Entity(SDL_Renderer* _renderer);

//     const Vector& getPosition() const;
//     const Vector& getVelocity() const;
//     const Vector& getAcceleration() const;
//     bool getSide() const;
//     int getHealth() const;
//     Texture getTexture() const;
//     Sprite getSprite() const;
//     Direction getDirection() const;

//     double getTextureWidth() const;
//     double getTextureHeight() const;

//     void setPosition(Vector _position);
//     void setVelocity(Vector _velocity);
//     void setAcceleration(Vector _acceleration);
//     void setSide(bool _side);
//     void setHealth(int _health);
//     void setTexture(Texture _texture);
//     void setSprite(Sprite _sprite);
//     void setDirection(Direction _direction);
//     bool collide(const Entity &other) const;
// };

// class Player : public Entity {
// public:
//     Player(SDL_Renderer* _renderer);
// };

// class Enemy : public Entity {
// private:
//     double radius;
//     int reload;

// public:
//     Enemy(SDL_Renderer* _renderer);
//     double getRadius() const;
//     int getReload() const;

//     void setRadius(double _radius);
//     void setReload(int _reload);

//     bool inRange(const Player &player) const;
// };

// class Bullet : public Entity {
// public:
//     Bullet(SDL_Renderer* _renderer);
// };