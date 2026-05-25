#include "raylib.h"
#include "terminal.h"
#include "commands.h"
#include "game.h"

// Theme - Controlled Size

int main()
{
    InitWindow(1280, 720, "Terminal");
    SetTargetFPS(60);
    Terminal terminal;
    GameState gameState;
    CommandSystem commandSystem;
    commandSystem.RegisterCommands();
    while (!WindowShouldClose())
    {
        terminal.HandleInput();
        if (terminal.submitPressed())
        {
            commandSystem.Execute(terminal.inputBuffer,gameState);
            terminal.inputBuffer.clear();
        }
        BeginDrawing();
            ClearBackground(BLACK);
            terminal.Draw(gameState.terminalLines);
        EndDrawing();
    }
    CloseWindow();
}