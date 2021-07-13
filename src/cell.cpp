#include "cell.h"

SDL_Color Cell::sCellColour = {0, 0, 0, 0};
SDL_Color Cell::sPressedCellColour = {0, 0, 0, 0};
SDL_Texture** Cell::sTextureOfNumbers = nullptr;
SDL_Texture* Cell::sFlagTexture = nullptr;
SDL_Texture* Cell::sBombTexture = nullptr;

Cell::Cell(const SDL_Rect& rect, const SDL_Color& colour)
    : Button(rect, colour), mNumber(0), mPressed(false), mFlag(false), mBomb(false) {

}

void Cell::plantBomb() {
    mBomb = true;
}

void Cell::plantNumber(int number) {
    mNumber = number;
}

void Cell::setPressed() {
    if (!mPressed && !mFlag) {
        mPressed = true;
        mColour = Cell::sPressedCellColour;
        setTexture(mNumber ? Cell::sTextureOfNumbers[mNumber] : mBomb ? Cell::sBombTexture : mTexture);
    }
}

void Cell::setFlag() {
    if (!mPressed) {
        mFlag = !mFlag;
        setTexture(mFlag ? Cell::sFlagTexture : nullptr);
    }
}