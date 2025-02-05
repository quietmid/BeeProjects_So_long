# So_Long

## Project

<p>So_Long is a graphical project using the MLX42 library. The goal is to create a simple 2D topdown game in C (imagine Bomberman or Pacman but a super budgeted version).
Through this project, I was introduced to the basic of window management, event handling, textures/images handling and introducing testing and checks early on of the project.
The school that I am at, Hive Helsinki, allows us to use MLX42 instead of MinilibX. </p>

## Example
<h4>Gameplay with Monster</h4>
<img src="https://i.imgur.com/PBWpSSz.gif" >

## Core Features:
- Event handling with the movement input
- textures and images 
- Randomized movement of the monsters

## How to Play the Game
The project states that the player's goal is to collect all the chest and then enter the exit. The exit shouldn't open before all the chests are collected. 

• The player is moved by `W, A, S, and D` keys (you can choose ZQSD if you prefer) \
• The player should be able to move in four directions: up, down, left and right. \
• The player can't walk into the walls or the exit before all the chests are collected. \
• The number of the player's movement should be recorded and display in the shell. \
• For the bonus, I added the move counts and collected counts directy on the window. The player will be able to see the current moves they are on and how many chests they have collected. \
• For the second bonus, I added monster that moved around randomly and the player has to avoid them and collect the chests. 

<h3>My Approach</h3>

Similar to other projects, I first checked for errors, such as # of arugments, the map file extension, then the validity of the map (map need to be rectangular, surrounded by wall, has one Player, one exit, and at least one chest), and finally there needs to be a valid path for the player to reach all the chests and reach the exit. I store all these information to my t_game struct, so I can use these information to compare and check. 

After we make sure the map is valid, we then uses the MLX42 library to allocate memories to the PNG files, assign them to the corresponding variables, fill and render the map according the map file. \
In input managment, I use the MLX_KEY function and check if the the direction that the player is moving in is not `1` or `E` (Wall or Exit), if it is not, then it checks if a chest is present. If a chest is present, my code runs through all the location of the chests on the map and finds the one that my player is standing on and disable the image of that one. Finally, after each move, I check the game status to see if the game winning condition is reached, if it is reached, I turn the exit into `0` and when the player's location matches the exit location, the game ends. 

<h3>To Play</h3>

Git clone the repo and cd into the folder
```
  git clone https://github.com/quietmid/BeeProjects_So_long.git <FolderName>
  cd <FolderName>
```

Check if there is a MLX42 folder already in the folder if there is then delete the MLX42 folder

Compile the program by make and make re
```
  make
```

See that the excutable so_long is present then call the program with 
```
  ./so_long maps/midMap.ber
```
Then you can play!


