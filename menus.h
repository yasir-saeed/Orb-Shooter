
Rectangle playButton = {300, 275, 200, 75};
Rectangle playAgainButton = {260, 300, 275, 75};

bool mainMenu(Rectangle button, Vector2 mouse, bool menuState) {

    DrawText("ORB SHOOTER", 225, 100, 50, BLACK);
    DrawText("2022 - Developed by: Yasir Saeed ", 285, 500, 15, BLACK);

    // Play Button
    DrawRectangle(button.x, button.y, button.width, button.height,
                  RED);

    DrawText("PLAY", (GetScreenWidth() / 2) - 28, 300, 20, WHITE);

    // Check if player clicks play button
    if (CheckCollisionPointRec(mouse, button)
        && ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))) {
        menuState = false;

    }
    return menuState;
}

void GameOver(){
    DrawText("GAME OVER", (GetScreenWidth() / 2) - 95, 200, 30, RED);
    DrawRectangle(playAgainButton.x,playAgainButton.y,playAgainButton.width,playAgainButton.height, RED);
    DrawText("BACK TO MAIN MENU", playAgainButton.x+25, playAgainButton.y+25, 20, WHITE);

}
