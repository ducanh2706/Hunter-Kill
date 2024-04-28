// #include "../library/texture.h"

// void Sprite::init(SDL_Texture* _texture, int frames, int width, int height) {
//     direction = RIGHT;
//     texture = _texture;
//     counter = 0;

//     SDL_Rect clip;
//     for (int j = 0; j < 4; j++){
//         for (int i = 0; i < frames; i++) {
//             clip.y = j * width;
//             clip.x = i * height;
//             clip.w = width;
//             clip.h = height;
//             clips[j].push_back(clip);
//         }
//     }
// }


// void Sprite::tick(Direction _direction) {
//     if (direction != _direction) {
//         direction = _direction;
//         currentFrame = 0;
//     }
//     else {
//         ++counter;
//         if (counter % (FPS / 10) == 0)
//             currentFrame = (currentFrame + 1) % clips[_direction].size();
//     }
    
// }

// const SDL_Rect* Sprite::getCurrentClip(Direction _direction) const {
//     return &(clips[_direction][currentFrame]);
// }

// // Texture::Texture(SDL_Renderer* _renderer)
// //     : texture(nullptr), renderer(_renderer), width(0), height(0) {}

// // Texture::~Texture() {
// //     free();
// // }

// // void Texture::load(const std::string fileName) {
// //     free();

// //     texture = IMG_LoadTexture(renderer, fileName.c_str());

// //     if (texture == nullptr){
// //         logErrorAndExit("Can't create texture of " + fileName, SDL_GetError());
// //     }

// //     SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
// // }

// // void Texture::free() {
// //     if (texture != nullptr){
// //         SDL_DestroyTexture(texture);
// //         texture = nullptr;
// //         width = height = 0;
// //     }
// // }

// // int Texture::getWidth() const {
// //     return width;
// // }

// // int Texture::getHeight() const {
// //     return height;
// // }