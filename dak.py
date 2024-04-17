import pygame
import sys
import random
import numpy as np
from queue import PriorityQueue

# Initialize pygame
pygame.init()

# Screen dimensions
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600

# Colors
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
BLACK = (0, 0, 0)

# Parameters
BOT_COUNT = 10
MAX_SPEED = 3
CHASE_RADIUS = 100
CHASE_FORCE = 0.1
OBSTACLE_RADIUS = 30

# Screen
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption('Chasing Steering Behavior with A*')

clock = pygame.time.Clock()

class Bot:
    def __init__(self):
        self.position = np.array([random.randint(0, SCREEN_WIDTH), random.randint(0, SCREEN_HEIGHT)], dtype=np.float64)
        self.velocity = np.array([0.0, 0.0], dtype=np.float64)

    def update(self, target_position, obstacles):
        path = self.astar(self.position, target_position, obstacles)
        
        if len(path) > 1:
            next_position = np.array(path[1], dtype=np.float64)
            desired_velocity = (next_position - self.position)
            distance = np.linalg.norm(desired_velocity)
            
            if distance < CHASE_RADIUS:
                desired_velocity = desired_velocity / distance * MAX_SPEED
                steer = desired_velocity - self.velocity
                steer = np.clip(steer, -CHASE_FORCE, CHASE_FORCE)
                self.velocity = np.clip(self.velocity + steer, -MAX_SPEED, MAX_SPEED)
            
            # Update position
            self.position += self.velocity

    def astar(self, start, goal, obstacles):
        open_set = PriorityQueue()
        open_set.put((0, tuple(start)))
        came_from = {}
        g_score = {tuple(start): 0}

        while not open_set.empty():
            current = open_set.get()[1]

            if np.allclose(current, goal):
                path = []
                while current in came_from:
                    path.append(current)
                    current = came_from[current]
                return path[::-1]

            for next_position in self.get_neighbors(current, obstacles):
                new_g_score = g_score[tuple(current)] + 1

                if tuple(next_position) not in g_score or new_g_score < g_score[tuple(next_position)]:
                    g_score[tuple(next_position)] = new_g_score
                    f_score = new_g_score + self.heuristic(next_position, goal)
                    open_set.put((f_score, tuple(next_position)))
                    came_from[tuple(next_position)] = current

        return []

    def get_neighbors(self, position, obstacles):
        neighbors = []
        for i in range(-1, 2):
            for j in range(-1, 2):
                neighbor = position + [i, j]
                if not any(np.allclose(neighbor, obstacle.position) for obstacle in obstacles):
                    if 0 <= neighbor[0] < SCREEN_WIDTH and 0 <= neighbor[1] < SCREEN_HEIGHT:
                        neighbors.append(neighbor)
        return neighbors

    def heuristic(self, a, b):
        return np.linalg.norm(a - b)

    def draw(self, screen):
        pygame.draw.circle(screen, RED, (int(self.position[0]), int(self.position[1])), 10)

class Obstacle:
    def __init__(self, position):
        self.position = position

    def draw(self, screen):
        pygame.draw.circle(screen, BLACK, (int(self.position[0]), int(self.position[1])), OBSTACLE_RADIUS)

player_position = np.array([SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2], dtype=np.float64)
bots = [Bot() for _ in range(BOT_COUNT)]
obstacles = [Obstacle(np.array([random.randint(0, SCREEN_WIDTH), random.randint(0, SCREEN_HEIGHT)], dtype=np.float64)) for _ in range(BOT_COUNT)]

# Main loop
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Update player position
    player_position = np.array(pygame.mouse.get_pos(), dtype=np.float64)

    # Update bots
    for bot in bots:
        bot.update(player_position, obstacles)

    # Draw
    screen.fill(WHITE)
    pygame.draw.circle(screen, BLUE, (int(player_position[0]), int(player_position[1])), 20)
    for bot in bots:
        bot.draw(screen)
    for obstacle in obstacles:
        obstacle.draw(screen)

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
sys.exit()
