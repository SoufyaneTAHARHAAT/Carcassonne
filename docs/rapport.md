# Carcassonne game

***Carcassonne** is a tile-laying game where players collectively construct the area around the medieval French city of Carcassonne while competing to place followers on various features and score the most points.*

# Programs Structures



## CONSTANTS
MAX_TILES 
MAX_PLAYERS



## Tile Structure

1. **id**: id for the tile. (maybe from 1..Max number of tiles)
2. **borders**: Eenum to  repseent the borders of each Tile
3. **state**: I don't remember
4. **player**: the player who put the tile 
5. **coordinates**: the place of the tile in the grid
6. **special**: I don't remember (maybe for dark side)

|  | ATTRIBUT  | DATA TYPE |
|---|-------------|---------|
|   | id  | INT|
|   | borders | ENUM(ROUTE,VILLE,VILLAGE,PRE,ABBAYE,BLASON)|
|   | state | Boolean |
|   | player| Structure |
|   | coordinates| Structure |
|   | special |    boolean |

## Grid Structure

*Grid strucutre is 2D array of pointers to struct Tile*
*array of pointers to make easy to represent the empty squares with NULL*

|  | ATTRIBUT  | DATA TYPE |
|---|-------------|---------|
|   |  tab |  Pointer (Struct Tile)    |


## Player 

1. **id**: as a unique  identifeir for every player
2. **color**: regarding the color of the meeple he is playing with 
3. **name**: string for player's name
4. **turn_to_play**: boolean to indicate the turn for each Player
5. **score**: to know who won in the end of the game
6. **played_tiles**: an array of pointers to Tile structure where we keep track of all tiles played by the player

|  | ATTRIBUT  | DATA TYPE |
|---|-------------|---------|
|   | id  | INT     |
|   | color    |    Enum()     |
|   | name | char[] |
|   | turn_to_play  |  Boolean |
|   | score   | INT |
|   | played_tiles  |  Pointer(Tile)[] |


## Stack_Tiles 
*A stack is the best way to represent the Tiles that are not yet in the grid*

1. **stack**: we hold every Tile structure
2. **number_tiles**: the current number of tiles in the stack;


|  | ATTRIBUT  | DATA TYPE |
|---|-------------|---------|
|   | stack  | Pointer(Stack(Tile)) | 
|   | number_tiles | int |



## Game

1. **player_tabs** :  an array that contains the list of players starting the game we get the number of players as an argument when the game executes , now that array contains the IDs of each player.(to reconsider)
2. **grid**: a pointer that points to the grid structure
3. **stack_tiles**: a pointer to  a stack of Tiles
4. **state**: to represent if the game is over or not
5. **ranking**: to represent the currend standing of the game (it will be helpful in case for resume game)
6. **History_game_movements**: history of the moves played


|  | ATTRIBUT  | DATA TYPE |
|---|-------------|---------|
|   | player_tabs  | Int[] | 
|   | grid | Pointer(Grid)     |
|   | stack_tiles  | Pointer(Stack_Tiles)| 
|   | state | Boolean |
|   | ranking | Int[] |
|   | History_games | |  
|   | History_game_movements | |  


## Meeple 

1.**id**: to represents which player is owning the meeple (I think we don't need an id as we can get the player easly looking to the color)

2.**state**: Either posed or not on the grid
3.**color**: Meeple color
3.**place**: for the position the meeple is placed on the grid

|   | ATTRIBUT  | DATA TYPE | 
|---|-------------|---------|
|   | id |   INT  |
|   | state | Enum(IN , OUT) |
|   | color  | Enum(GREEN , RED , YELLOW , ) | 
|   | place  | struct Coordinate | 

## Coordinate


|   | ATTRIBUT  | DATA TYPE | 
|---|-------------|---------|
|   | x | INT  |
|   | y | INT     |


## Carcassone Rules 





 

