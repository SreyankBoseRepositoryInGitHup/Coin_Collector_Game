#include "raylib.h"

int main(void)
{
    int Score = 0;

    float Rectx = 10;
    float Recty = 10;

    float CircleX = GetRandomValue(25, 800 - 25);
    float CircleY = GetRandomValue(25, 450 - 25);

    InitWindow(800, 450, "Coin Collecter");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(GREEN);

        DrawText(TextFormat("Score: %i", Score), 25, 25, 50, GRAY);

        DrawRectangle(Rectx, Recty, 25, 25, WHITE);

        if (IsKeyDown(KEY_W)) {
            Recty -= 5;
        }
        else if (IsKeyDown(KEY_A)) {
            Rectx -= 5;
        }
        else if (IsKeyDown(KEY_S)) {
            Recty += 5;
        }
        else if (IsKeyDown(KEY_D)) {
            Rectx += 5;
        }

        DrawCircle(CircleX, CircleY, 10, YELLOW);

        if (CheckCollisionCircleRec(Vector2{ CircleX,CircleY }, 10, Rectangle{ Rectx,Recty,25,25 })) {
            CircleX = GetRandomValue(25, 800 - 25);
            CircleY = GetRandomValue(25, 450 - 25);

            Score++;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}