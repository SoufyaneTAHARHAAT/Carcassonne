# structres of the program 

## CONSTANTS



## Tile Structure

|  | ATTRIBUT  | DATA TYPE |
|---|-------------|---------|
|   | id  | INT     |
|   |  borders | Strucutre     |
|   |   state |    Boolean |
|   | player      | Structure |
|   | coordinates  |    Structure |
|   | special        |    boolean |

## Grid Structure

|  | ATTRIBUT  | DATA TYPE |
|---|-------------|---------|
|   |  tab |  Pointer (Struct Tile)    |


## Player 


|  | ATTRIBUT  | DATA TYPE |
|---|-------------|---------|
|   | id  | INT     |
|   | color    |    Enum()     |
|   | name | char[] |
|   | turn_to_play  |  Boolean |
|   | score   | INT |
|   | tuile_tracked  |  [] |
|   | won        |    Boolean |


## Stack_Tiles 


|  | ATTRIBUT  | DATA TYPE |
|---|-------------|---------|
|   | stack  | Pointer(Stack(Tile)) | 
|   | number_tuiles | char[]     |



## Game


|  | ATTRIBUT  | DATA TYPE |
|---|-------------|---------|
|   | player_tabs  | Int[] | 
|   | grid | Pointer(Grid)     |
|   | stack_tiles  | Pointer(Stack_Tiles)| 
|   | state | Boolean |
|   | History_games | |  
|   | History_game_movements | |  


## Meeple 

|   | ATTRIBUT  | DATA TYPE | 
|   | id |   INT  |
|   | state | Enum() |
|   | color  | Enum() | 
|   | place  | Enum() | 








 

