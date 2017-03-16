# include "surface_operations.h"
// Apply GrayScale on Image
SDL_Surface* generateGrayScaleImage(SDL_Surface *img)
{
        size_t width;
        size_t height;
        int sum;
        SDL_Surface *result;
        Uint32 pix;
        Uint8 r;
        Uint8 g;
        Uint8 b;

        width = img->w;
        height = img->h;
        result = generateEmptySurface(width, height);
        for (size_t x = 0; x < width; ++x)
        {
                for (size_t y = 0; y < height; ++y)
                {
                        pix = getpixel(img, x, y);
                        SDL_GetRGB(pix, img->format, &r, &g, &b);
                        sum = 0.30f * r + 0.59f * g + 0.11f * b;
                        pix = SDL_MapRGB(img->format, sum, sum, sum);
                        putpixel(result, x, y, pix);
                }
        }
        return result;
}

// Generate BlackAndWhite from GrayScaleImage
SDL_Surface* generateBlackAndWhiteFromGS(SDL_Surface *img)
{
        size_t width;
        size_t height;
        int val;
        SDL_Surface *result;
        Uint32 pix;
        Uint8 r;
        Uint8 g;
        Uint8 b;

        width = img->w;
        height = img->h;
        result = generateEmptySurface(width, height);
        for (size_t x = 0; x < width; ++x)
        {
                for (size_t y = 0; y < height; ++y)
                {
                        pix = getpixel(img, x, y);
                        SDL_GetRGB(pix, img->format, &r, &g, &b);
                        val = (r > 127 ? 255 : 0);
                        pix = SDL_MapRGB(img->format, val, val, val);
                        putpixel(result, x, y, pix);
                }
        }
        return result;
}

SDL_Surface* copySurface(SDL_Surface *img)
{
        size_t width;
        size_t height;
        SDL_Surface *result;
        Uint32 pix;
        Uint8 r;
        Uint8 g;
        Uint8 b;

        width = img->w;
        height = img->h;
        result = generateEmptySurface(width, height);

        for (size_t x = 0; x < width; ++x)
        {
                for (size_t y = 0; y < height; ++y)
                {
                        pix = getpixel(img, x, y);
                        SDL_GetRGB(pix, img->format, &r, &g, &b);
                        pix = SDL_MapRGB(img->format, r, g, b);
                        putpixel(result, x, y, pix);
                }
        }

        return result;
}

// Generate Black and White image from Matrix
SDL_Surface* genBWImgFromMat(struct s_matrix *mat)
{
        SDL_Surface *result;
        size_t width;
        size_t height;
        Uint32 pix;
        Uint8 pixCol;

        width = mat->lines;
        height = mat->cols;
        result = generateEmptySurface(width, height);
        for (size_t x = 0; x < width; ++x)
        {
                for (size_t y = 0; y < height; ++y)
                {
                        pixCol = (Uint8)(mat->data[x * height + y] * 255);
                        pix = SDL_MapRGB(result->format, pixCol, pixCol, pixCol);
                        putpixel(result, x, y, pix);
                }
        }
        return result;
}
    

