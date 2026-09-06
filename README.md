# Ball Spawner (Top Dağıtma)

A small Qt Widgets demo where each button click spawns a new ball that bounces around
inside the window under simple velocity-based motion.

## How it works

- Each `Top` (ball) is an independent `QWidget` with its own position (`px`, `py`) and
  velocity (`dx`, `dy`), randomized on creation.
- A `QTimer` ticks every 16ms (~60fps) and moves the ball by its velocity each frame.
- When a ball reaches the edge of the parent window, its velocity on that axis is
  inverted, producing a bounce.
- One of four images is picked at random for each new ball, so repeated clicks produce
  a small crowd of differently-skinned, independently bouncing balls.

## Tech stack

- **Language:** C++
- **Framework:** Qt Widgets (`QWidget`, `QTimer`, `QPainter`)

## Running it

1. Open the project file in Qt Creator.
2. Build and run.
3. Click the button to spawn balls — click repeatedly to see multiple balls bouncing
   independently.

## Notes

- Ball speed is randomized per spawn (`rand() % 10 - 5` on each axis); a commented-out
  `hizBulma` function suggests an earlier attempt at controlling speed more precisely —
  worth revisiting if you extend this.
- Collision is only against the window edges — balls currently pass through each other.
