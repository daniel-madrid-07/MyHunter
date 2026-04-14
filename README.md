# My Hunter 2 🎮

**A fast-paced arcade shooting game with animated targets and dynamic difficulty** — Challenge yourself to hit as many Kirby creatures as possible while managing limited ammunition.

## Overview

My Hunter 2 is a graphical arcade game built with CSFML that challenges players to shoot at rapidly moving Kirby characters before they escape the screen. The game features multiple difficulty levels, animated sprites, sound effects, and a scoring system. It's a fun reimagining of classic arcade hunting games with colorful graphics and engaging gameplay mechanics.

## Features

🎯 **Gameplay:**
- 🎪 **Dynamic Target Spawning** - Kirby creatures spawn in waves at increasing speeds
- 💥 **Hit Detection System** - Precise click detection with visual feedback
- 📊 **Scoring System** - Track hits, misses, and escapes in real-time
- 🔔 **Multiple Movement Patterns** - Targets move in waves, ellipses, or zigzag patterns
- ⚡ **Progressive Difficulty** - Speed increases as you advance through the game
- 🎵 **Audio & Sound Effects** - Background music, hit sounds, and game-over audio

## Game Mechanics

### Controls
- **Mouse Click** - Shoot at targets (crosshair follows cursor)
- **Start Button** - Begin the game (60-second countdown)
- **ESC** - Pause/Resume or exit during gameplay

### Scoring
- **Hit** - +1 point when you successfully shoot a Kirby
- **Miss** - Target runs off-screen (reduces ammo counter)
- **Escape** - Kirby escapes if not hit in time
- **Game Over** - After 3 misses, game ends

### Visual Elements
- 🎨 **Kirby Sprites** - Animated characters with directional facing
- 🎯 **Crosshair** - Custom cursor that animates on shots
- 💣 **Ammo Counter** - Visual bullet indicator showing remaining shots
- ⏱️ **Counter Display** - Animated 60-second countdown timer

## Architecture

```
Myhunter2/
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
│   ├── kirby.png           # Kirby sprite sheet
│   ├── background.jpg      # Game background
│   ├── crosshair.png       # Crosshair sprite
│   ├── bullets-*.png       # Ammo counter sprites
│   ├── counter.png         # Timer display sprite
│   ├── music.mp3           # Background music
│   ├── shot.mp3            # Hit sound effect
│   ├── gameover.mp3        # Game over sound
│   └── font.TTF            # Text font
└── Makefile
```

## Data Structures

### Core Types
- **kirby_t** - Game target with sprite, position, movement pattern, and animation state
- **game_data_t** - Global game state (active targets, spawn timer, miss count)
- **crosshair_t** - Mouse cursor with sprite animation on click
- **bullets_t** - Ammo display with empty/filled bullet sprites
- **counter_t** - Animated countdown timer display
- **text_t** - Score text rendering
- **button_t** - Start button with click detection and sound

## Building

```bash
# Build the game
make

# Clean object files
make clean

# Remove all build artifacts
make fclean

# Build with debug symbols
make debug

# Run the game
./my_hunter
```

### Requirements
- **Compiler**: GCC with C99 support
- **Dependencies**:
  - CSFML libraries (graphics, system, window, audio)
  - libm (math library)
  - Standard C libraries

## How to Play

1. **Start Screen** - Click the "START BUTTON" to begin
2. **60-Second Timer** - You have exactly 60 seconds to shoot as many Kirby creatures as possible
3. **Target Practice** - Click on Kirby characters as they move across the screen
4. **Track Your Ammo** - You have 3 misses before Game Over
5. **Beat Your Score** - Try to maximize hits before time runs out
6. **Game Over Screen** - Shows final score, hits, and escapes

## Project Stats

- **Lines of Code**: ~1,279 (game source)
- **Project Size**: ~8.9MB (includes assets & music)
- **Language**: C (C99 standard)
- **Graphics Library**: CSFML (C binding for SFML)
- **Build System**: Make
- **Asset Format**: PNG sprites, JPG background, MP3 audio

## Technical Highlights

✨ **Key Features:**
- **Sprite Animation** - Frame-based animation using texture rects
- **Event-Driven Architecture** - CSFML event loop for responsive input
- **Collision Detection** - Bounding box collision with mouse position
- **Audio Management** - Multiple sound effects and background music
- **Performance Optimization** - Clock-based frame timing
- **Memory Management** - Proper resource allocation and cleanup

## Game States

1. **Menu** - Wait for start button click
2. **Counter** - 60-second countdown before game starts
3. **Playing** - Active gameplay with spawning and shooting
4. **Paused** - ESC key pauses the game
5. **Game Over** - Final score display

## Notes

- The game includes a custom `my_printf` implementation for score rendering
- Kirby movement patterns can be customized (wave, ellipse, zigzag)
- Difficulty increases dynamically with score
- Audio plays automatically; hit sounds are synchronized with click events
- The game maintains a 60-second session regardless of difficulty

## Credits

Epitech Graphical Programming Project (2025)

---

**Project Type**: Game Development / Graphics Programming  
**Difficulty**: Intermediate  
**Key Concepts**: Event-Driven Programming, Sprite Animation, Collision Detection, Audio Integration
