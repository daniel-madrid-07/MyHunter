# MyHunter — technical reference

## Architecture

```
MyHunter/
├── src/                      # Main source files
│   ├── my_hunter.c          # Main game loop and event handling
│   ├── game.c               # Game state management & updates
│   ├── init.c               # Game initialization
│   ├── kirby.c              # Kirby sprite and animation
│   ├── crosshair.c          # Crosshair cursor management
│   ├── bullets.c            # Ammo/bullet counter display
│   ├── counter.c            # Countdown timer
│   ├── game_spawn.c         # Kirby spawning logic
│   ├── game_utils.c         # Collision & hit detection
│   ├── background.c         # Background rendering
│   ├── start_button.c       # Start button UI
│   ├── text.c               # Text rendering & scoring
│   ├── help.c               # Help menu
│   └── game_cleanup.c       # Resource cleanup
├── include/
│   └── my.h                 # Main header with data structures
├── my_printf/               # Custom printf implementation
├── content/                 # Game assets (sprites, sounds, music)
│   ├── kirby.png            # Kirby sprite sheet
│   ├── background.jpg       # Game background
│   ├── crosshair.png        # Crosshair sprite
│   ├── bullets-*.png        # Ammo counter sprites
│   ├── counter.png          # Timer display sprite
│   ├── music.mp3            # Background music
│   ├── shot.mp3             # Hit sound effect
│   ├── gameover.mp3         # Game over sound
│   └── font.TTF             # Text font
└── Makefile
```

### Core data types

- **kirby_t** — game target with sprite, position, movement pattern, and animation state
- **game_data_t** — global game state (active targets, spawn timer, miss count)
- **crosshair_t** — mouse cursor with sprite animation on click
- **bullets_t** — ammo display with empty/filled bullet sprites
- **counter_t** — animated countdown timer display
- **text_t** — score text rendering
- **button_t** — start button with click detection and sound

## How to play

1. Start screen — click the "START BUTTON" to begin
2. 60-second timer — you have exactly 60 seconds to shoot as many Kirby creatures as possible
3. Target practice — click on Kirby characters as they move across the screen
4. Track your ammo — you have 3 misses before Game Over
5. Beat your score — try to maximize hits before time runs out
6. Game over screen — shows final score, hits, and escapes

## Controls

- Mouse click — shoot at targets (crosshair follows cursor)
- Start button — begin the game (60-second countdown)
- ESC — pause/resume or exit during gameplay

## Scoring

- Hit — +1 point when you successfully shoot a Kirby
- Miss — target runs off-screen (reduces ammo counter)
- Escape — Kirby escapes if not hit in time
- Game over — after 3 misses, the game ends

## Game states

1. Menu — wait for start button click
2. Counter — 60-second countdown before game starts
3. Playing — active gameplay with spawning and shooting
4. Paused — ESC key pauses the game
5. Game over — final score display

## Notes

- The game includes a custom `my_printf` implementation for score rendering
- Kirby movement patterns can be customized (wave, ellipse, zigzag)
- Difficulty increases dynamically with score
- Audio plays automatically; hit sounds are synchronized with click events
- The game maintains a 60-second session regardless of difficulty
