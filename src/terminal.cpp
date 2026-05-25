#include "terminal.h"
#include "raylib.h"

void Terminal::HandleInput()
{
    int key = GetCharPressed();
    while (key > 0)
    {
        if ((key >= 32) && (key <= 125))
        {
            inputBuffer += (char)key;
        }
        key = GetCharPressed();
    }
    if (IsKeyPressed(KEY_BACKSPACE) && !inputBuffer.empty())
    {
        inputBuffer.pop_back();
    }
}

bool Terminal::submitPressed()
{
    return IsKeyPressed(KEY_ENTER);
}

void Terminal::Draw(const std::vector<std::string>& lines)
{
    int maxVisibleLines = 20;
    int start = std::max(0, (int)lines.size() - maxVisibleLines);
    int y = 40;
    for (int i = start; i < lines.size(); i++)
    {
        DrawText(lines[i].c_str(), 40, y, 24, GREEN);
        y += 30;
    }

    DrawText("> ", 40, 660, 30, GREEN);
    DrawText(inputBuffer.c_str(), 80, 660, 30, GREEN);

    if (((int)(GetTime() * 2) % 2) == 0)
    {
        int width = MeasureText(inputBuffer.c_str(), 30);
        DrawText("_", 80 + width, 660, 30, GREEN);
    }
}