#include "../include/raylib.h"
#include <stdbool.h>
#define width 1280
#define HEIGHT 720
#define title "Title"
int main() {
  InitWindow(width, HEIGHT, title);
  InitAudioDevice();
  Sound hitWall = LoadSound("./resources/sound/test.wav");
  Sound hitGame = LoadSound("./resources/sound/collision.wav");
  SetTargetFPS(144);
  int factor = 1;
  int rectangle_width = 50;
  int rectangle_HEIGHT = 25;
  float x = rectangle_width + 1;
  float height1 = HEIGHT / 2.0;
  float height2 = HEIGHT / 2.0;
  bool collision = false;
  Rectangle left = {50.0f, height1, 25, 50 * 2};
  Rectangle right = {width - 50.0f, height2, 25, 50 * 2};
  Vector2 circle = {.x = 151.0, .y = HEIGHT / 2.0};
  const float radius = 25.0;
  const float MOVE_AMOUNT = 12.5;
  float dY = 1.0;
  float dX = 1.0;
  while (!WindowShouldClose()) {
    if (circle.x + radius >= width - 1 || circle.x <= radius) {
      PlaySound(hitWall);
      factor *= -1;
    } else if (circle.y + radius / 2.0 >= HEIGHT - 1 || circle.y <= radius) {
      PlaySound(hitWall);
      factor *= -1;
    } else if (CheckCollisionCircleRec(circle, radius, right) ||
               CheckCollisionCircleRec(circle, radius, left)) {
      PlaySound(hitGame);
      factor *= -1;
    }

    if (IsKeyPressed(KEY_W) || IsKeyPressedRepeat(KEY_W)) {
      if ((right.y - MOVE_AMOUNT > -MOVE_AMOUNT)) {
        right.y -= MOVE_AMOUNT;
      }
    } else if (IsKeyPressed(KEY_S) || IsKeyPressedRepeat(KEY_S)) {
      if ((right.y + right.height + MOVE_AMOUNT < HEIGHT + MOVE_AMOUNT)) {
        right.y += MOVE_AMOUNT;
      }
    }

    circle.x += GetFrameTime() * 250 * factor;
    BeginDrawing();
    {
      ClearBackground(RAYWHITE);
      DrawCircle(circle.x, circle.y, radius, GOLD);
      DrawRectangleRec(left, BLUE);
      DrawRectangleRec(right, RED);
    }
    EndDrawing();
  }
  UnloadSound(hitWall);
  UnloadSound(hitGame);
  CloseAudioDevice();
  CloseWindow();
  return 0;
}
