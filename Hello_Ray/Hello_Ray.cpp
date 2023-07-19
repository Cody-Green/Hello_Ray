#include "raylib.h"
#include "hello.h"

//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //---------------------------------------------------------
    R_WINDOW win = { 1920, 1080, "Window" };
    /*const int screenWidth = 800;
    const int screenHeight = 450;*/
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT | FLAG_WINDOW_ALWAYS_RUN);
    InitWindow(win.width, win.height, win.title);
    SetExitKey(KEY_NULL);

    Ball ball;
    ball.position.x = float(GetScreenWidth() / 2.0f);
    ball.position.y = float(GetScreenHeight() / 2.0f);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //----------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //-----------------------------------------------------
        if (IsKeyPressed(KEY_SPACE)) win.pause = !win.pause;

        if (!win.pause)
        {
            ball.position.x += ball.position.x;
            ball.position.y += ball.position.y;

            // Check walls collision for bouncing
            if ((ball.position.x >= (GetScreenWidth() - ball.radius)) || (ball.position.x <= ball.radius)) ball.velocity.x *= -1.0f;
            if ((ball.position.y >= (GetScreenHeight() - ball.radius)) || (ball.position.y <= ball.radius)) ball.velocity.y *= -1.0f;
        }
        else win.framecount++;
        //-----------------------------------------------------

        // Draw
        //-----------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawCircleV(ball.position, ball.radius, MAROON);
        DrawText("PRESS SPACE to PAUSE BALL MOVEMENT", 10, GetScreenHeight() - 25, 20, LIGHTGRAY);

        // On pause, we draw a blinking message
        if (win.pause && ((win.framecount / 30) % 2)) DrawText("PAUSED", ball.position.x, ball.position.y, 30, GRAY);

        DrawFPS(10, 10);

        EndDrawing();
        //-----------------------------------------------------
    }

    // De-Initialization
    //---------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //----------------------------------------------------------

    return 0;
}