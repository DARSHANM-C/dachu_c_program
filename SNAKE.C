import random
import os
import time

# Constants for the grid size
WIDTH = 10
HEIGHT = 10

# Directions
UP = (-1, 0)
DOWN = (1, 0)
LEFT = (0, -1)
RIGHT = (0, 1)

def print_grid(grid):
    os.system('cls' if os.name == 'nt' else 'clear')  # Clear the screen
    for row in grid:
        print(" ".join(row))
    print("\nControls: W (Up), S (Down), A (Left), D (Right). Press Ctrl+C to quit.\n")

def create_food(grid, snake):
    while True:
        x, y = random.randint(0, HEIGHT-1), random.randint(0, WIDTH-1)
        if (x, y) not in snake:
            grid[x][y] = 'F'  # Food
            return (x, y)

def move_snake(snake, direction):
    head_x, head_y = snake[0]
    new_head = (head_x + direction[0], head_y + direction[1])
    return new_head

def main():
    # Initialize the grid, snake, and direction
    grid = [[' ' for _ in range(WIDTH)] for _ in range(HEIGHT)]
    snake = [(HEIGHT//2, WIDTH//2)]
    direction = RIGHT
    food = create_food(grid, snake)
    score = 0

    while True:
        # Update the grid
        grid = [[' ' for _ in range(WIDTH)] for _ in range(HEIGHT)]
        for x, y in snake:
            grid[x][y] = 'O'  # Snake body
        grid[food[0]][food[1]] = 'F'

        print_grid(grid)
        print(f"Score: {score}")

        # Get user input for direction
        key = input("Move (W/A/S/D): ").strip().upper()
        if key == 'W' and direction != DOWN:
            direction = UP
        elif key == 'S' and direction != UP:
            direction = DOWN
        elif key == 'A' and direction != RIGHT:
            direction = LEFT
        elif key == 'D' and direction != LEFT:
            direction = RIGHT

        # Move the snake
        new_head = move_snake(snake, direction)

        # Check for collisions with walls or itself
        if (new_head in snake) or not (0 <= new_head[0] < HEIGHT and 0 <= new_head[1] < WIDTH):
            print("Game Over!")
            print(f"Your final score is: {score}")
            break

        snake.insert(0, new_head)  # Add new head

        # Check if food is eaten
        if new_head == food:
            score += 1
            food = create_food(grid, snake)
        else:
            snake.pop()  # Remove the tail if no food eaten

if __name__ == "__main__":
    main()
