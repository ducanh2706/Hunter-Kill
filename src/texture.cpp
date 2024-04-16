// #include "../library/texture.h"

// Texture::Texture(SDL_Renderer* _renderer)
//     : texture(nullptr), renderer(_renderer), width(0), height(0) {}

// Texture::~Texture() {
//     free();
// }

// void Texture::load(const std::string fileName) {
//     free();

//     texture = IMG_LoadTexture(renderer, fileName.c_str());

//     if (texture == nullptr){
//         logErrorAndExit("Can't create texture of " + fileName, SDL_GetError());
//     }

//     SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
// }

// void Texture::free() {
//     if (texture != nullptr){
//         SDL_DestroyTexture(texture);
//         texture = nullptr;
//         width = height = 0;
//     }
// }

// int Texture::getWidth() const {
//     return width;
// }

// int Texture::getHeight() const {
//     return height;
// }