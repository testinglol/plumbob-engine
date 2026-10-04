#include <SDL3/SDL.h>

// SDL's 64-bit flag macros (SDL_UINT64_C) do not import into Swift; re-export the ones the client uses as constants.
static const SDL_WindowFlags CSDL_WINDOW_RESIZABLE = SDL_WINDOW_RESIZABLE;
static const SDL_WindowFlags CSDL_WINDOW_HIGH_PIXEL_DENSITY = SDL_WINDOW_HIGH_PIXEL_DENSITY;
