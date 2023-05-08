# RUSH_HOUR_ON_GLUT_FSML
 FSML (Finite State Machine Language) is a programming language used to describe the behavior of finite state machines, which are mathematical models used to describe the behavior of a system.

# Rush Hour Game README

This C++ code is for a simple Rush Hour game where the player controls a taxi and has to pick up passengers and drop them off at their randomly generated destinations. The game ends after 3 minutes.

## Game Components

The game includes the following components:

1. Taxi (Player-controlled)
2. Passengers
3. Destinations
4. Score
5. Timer (3 minutes)

## Functions

### 1. SetCanvasSize(int width, int height)

This function sets the canvas size (drawing area) in pixels. The bottom-left coordinate has a value (0,0), and the top-right coordinate has a value (width-1, height-1).

### 2. game_indexarray()

This function initializes all the coordinates with zero to give them an equal background after creating the car and initializing with 1.

### 3. gamescore()

This function calculates and displays the game score in red.

### 4. pehlatimer(int m)

This function calculates the elapsed time and terminates the game after 3 minutes (180 seconds).

### 5. drawpassenger()

This function draws a passenger at a random location on the canvas. The passenger will not be drawn on top of the taxi or other passengers.

### 6. drawpassenger1()

This function draws another passenger at a random location on the canvas. The passenger will not be drawn on top of the taxi or other passengers.

### 7. drawpassenger2()

This function draws a third passenger at a random location on the canvas. The passenger will not be drawn on top of the taxi or other passengers.

### 8. genp()

This function generates a random destination for the first passenger and adds 10 points to the score.

### 9. genp1()

This function generates a random destination for the second passenger and adds 10 points to the score.

### 10. genp2()

This function generates a random destination for the third passenger and adds 10 points to the score.

## How to Play

1. Control the taxi using arrow keys.
2. Pick up passengers by moving the taxi on top of them.
3. Drop off passengers at their randomly generated destinations.
4. The game ends after 3 minutes (180 seconds), and your score will be displayed.

## Note

This README does not include information on how to set up and run the game. You will need to include the necessary libraries and setup instructions for your specific environment.
