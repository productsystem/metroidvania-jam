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
    gameState.world.AddEdge("docking_bay", "plaza");
    gameState.world.AddEdge("right_atrium", "plaza");
    gameState.world.AddEdge("left_atrium", "plaza");
    gameState.player.leftArm.name = "LEFT ARM";
    gameState.player.rightArm.name = "RIGHT ARM";
    gameState.player.leftLeg.name = "LEFT LEG";
    gameState.player.rightLeg.name = "RIGHT LEG";
    gameState.player.sensorModule.name = "SENSOR SUITE";
    gameState.player.reactorShield.name = "REACTOR SHIELD";
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