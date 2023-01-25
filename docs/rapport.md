# Carcassonne game

Carcassonne est un jeu de plateau pour deux à six joueurs, conçu par Klaus-Jürgen Wrede et publié en 2000. Le jeu est joué avec des tuiles qui représentent diverses caractéristiques d'un paysage médiéval, comme des villes, des routes, des champs et des monastères. Les joueurs se relaient pour placer des tuiles et placer leurs pièces de jeu de couleur, appelées "meeples", sur les tuiles pour revendiquer la propriété des caractéristiques. Le jeu se termine lorsque toutes les tuiles ont été placées et les joueurs marquent des points en fonction de la taille et de la complexité des caractéristiques qu'ils ont revendiquées.

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

I- COMPOSITION DU JEU DE BASE :

1. 40 pions en bois réparties en 4 couleurs: Les partisans.
2. 72 cartes de paysage (une carte de départ avec le dos plus foncé). Elles représentent les différents quartiers de la ville, les chemins, les carrefours, les prés et les abbayes.
3. 1 tableau pour compter les points des différents joueurs (taille réelle du tableau = 26 x18 cm).

II- RÈGLE DU JEU :

1. But du jeu :
Les joueurs posent, à tour de rôle, les cartes de paysage sur la table pour créer des chemins, des villes, des prés et des abbayes. Ils peuvent placer leurs partisans sur les cartes pour gagner des points. Les points peuvent être obtenus pendant la partie ou à la fin et on ne peut donc pas connaître l'heureux vainqueur avant l'évaluation finale.

2. Les préparatifs :
Posez la carte de départ au milieu de la table, côté recto visible. Ensuite mélangez les cartes de paysage, formez plusieurs piles et posez-les sur la table, face cachée, de manière à ce que chaque joueur puisse piocher facilement des cartes. Posez le tableau pour compter les points au bord de la table. Chaque joueur reçoit les huit partisans correspondant à la couleur de son choix. Il pose, ensuite, un des ses partisans devant lui sur la table. C'est le joueur le plus jeune qui décide qui commence la partie.

3. Les participants jouent à tour de rôle en suivant le sens des aiguille d'une montre. A chaque tour, ils doivent réaliser les actions suivantes en respectant l'ordre indiqué ci-dessous.
- Ils doivent piocher une carte de paysage et la poser sur la table.
- Ils peuvent prendre l'un de leur partisans et le placer sur la carte qu'il viennent de poser sur la table.
- Si grâce à cette carte, ils réussissent à achever des chemins, des villes, ou des abbayes, ils doivent les évaluer et compter les
     points correspondants.

3.1 Poser une carte sur la table.
Au début, le joueur pioche une carte de paysage dans l'une des piles de son choix. Il la retourne et la montre aux autres joueurs (pour qu'il puisse le "conseiller"). Ensuite, il pose la carte de paysage à côté des cartes qui se trouvent déjà sur la table en les faisant correspondre. Il doit respecter les règles suivantes:
   - La nouvelle carte introduite (encadrée en rouge dans les exemples) doit obligatoirement toucher au moins une des cartes qui se
     trouvent déjà sur la table. Il est interdit de poser une carte qui ne toucherait une autre carte que par un coin.
   - Les joueurs doivent achever la création de tous les prés, les chemins, et les villes sur les cartes de paysage, mais les abbayes,
     elles ne doivent pas être transformées.

Étant donné les règles du jeu, il est presque impossible que le joueur ne puisse pas placer une carte. Mais si le cas se présente il doit mettre cette carte paysage de côté et piocher une nouvelle carte.

3.2 Placer un partisan
Après avoir placé sa carte de paysage, le joueur peut placer un de ses partisans. Il doit respecter les règles suivantes:
   - Il ne doit placer qu'un seul partisan à la fois.
   - Il doit utiliser un partisan qui se trouve encore devant lui sur la table.
   - Il ne peut le placer que sur la carte de paysage qu'il vient d'introduire.
   - Il doit choisir la partie de la carte su laquelle il veut le placer. Il à le choix entre...

Il ne peut placer son partisan sur la partie de son choix que si il n'y a pas encore d'autres partisans dans les villes, sur les chemins ou dans les prés qu'il a complété avec sa carte de paysage et ceci indépendamment de la distance qui le sépare de l'autre partisan. Les deux exemples suivants expliquent cette règles.

Si au cours d'une partie un joueur n'a plus de partisans, il ne peur que se débarrasser de sa carte, mais soyez sans crainte: il est possible de récupérer des partisans.
Maintenant c'est au tour du joueur suivant.
Exception: Si on a terminé une ville, un chemin ou une abbaye en plaçant sa carte, on doit tout de suite compter les points correspondants.

Évaluer un chemin, une ville ou une abbaye achevés:

  Un chemin achevé
Un chemin est achevé lorsque les deux extrémités sont délimitées par un carrefour, une ville ou un abbaye. le nombre de cartes qui forment un chemin continu entre ces deux limites est variable.
Le joueur, dont le voleur se trouve sur le chemin, compte alors les cartes qui lui ont permis de le créer et il reçoit le nombre de points correspondant. Il déplace son partisan sur le tableau en fonction des points qu'il reçoit.
 
Le tableau comprend 50 cases. Si le joueur a déjà obtenu plus de 50 points, il "couche" son pion sur la table et se remet sur la case zéro. Ceci permet aux joueurs de savoir quels sont les pions qui ont déjà gagné 50 points ou plus.

  Une ville achevé
Une ville est achevée lorsque tous les quartiers sont clôturés par des remparts et qu'il n'y a plus d'espace ouvert. Le nombre de quartier nécessaire pour former une ville est variable. Au moment où la ville est achevée, le joueur dont le chevalier se trouve sur une carte de cette ville reçoit 2 points par carte utilisée pour former la ville. En outre, il reçoit 2 points par symbole.
Seule exception: Une ville n'a que deux quartiers. Dans ce cas-là le joueur rouge ne reçoit que 2 points !!!

Qu'est ce qui ce passe s'il y a plusieurs partisans dans une ville ou sur un chemin achevés?
Si le joueur a placé ses cartes en suivant une certaine tactique, il peut arriver qu'on trouve plusieurs chevaliers dans une ville ou plusieurs voleurs sur un chemin. Si c'est le cas, c'est le joueur qui possède le plus grand nombre de chevaliers dans cette ville ou le plus grand nombre de voleur sur le chemin, qui remporte les points. En cas d'égalité, tous les joueurs concernés reçoivent la somme totale des points.

  Une abbaye est achevée
Une abbaye est achevé lorsque le bâtiment est entouré par huit cartes de paysage.
Le joueur qui a placé un moine dans l'abbaye, reçoit tout de suite 9 points (un pour la carte de l'abbaye et un point pour chaque carte qui l'entoure).

Récupération des partisans
Après avoir évalué une ville, un chemin ou une abbaye (et seulement dans ce cas là), les joueurs récupèrent les partisans qu'il avaient placés, comme chevalier, voleur, ou moine, sur les cartes de paysages correspondantes. au tour suivant, les joueurs peuvent les réutiliser sur de nouvelles cartes de paysage qu'ils décident de placer.

Il est possible de placer un partisan sur une carte , de recevoir des points et de récupérer le partisan dans le même tour en jouant comme suit:
- 1 Terminer une ville ou un chemin avec une carte de paysage.
- 2 Placer un chevalier ou un voleur.
- 3 Évaluer la ville ou le chemin terminé.
- 4 Récupérer le chevalier ou le voleur.

  Le pré
Le pré est formé de plusieurs cartes de paysage mises les unes à cotés des autres pour obtenir un dessin continu. pendant la partie on ne peut pas donner une valeur aux prés ou aux partie de prés, mais on peut y placer des paysans. On ne reçoit les points correspondant qu'à la fin de la partie. Les paysans reste par conséquent, sur les cartes de paysage pendant toute la partie et les joueurs ne peuvent pas les récupérer.
Les prés sont délimités par des chemins, des villes et le bout des cartes sur la table. C'est important pour l'évaluation finale.

La fin de la partie :
Au moment où un joueur pioche la dernière carte de paysage, la partie est finie. Il introduit la carte dans le jeu et peut placer un dernier partisan. Ensuite, l'évaluation finale peut commencer.

Évaluation du jeu :
pour effectuer l'évaluation finale, on regarde d'abord les villes, les chemins, et les abbayes inachevés. Pour chaque chemin, ville et abbaye inachevé, le propriétaire du voleur, du chevalier et du moine reçoit un point par carte de paysage qui en fait partie. Maintenant, chaque symbole ne rapporte plus qu'un seul point.

Ensuite, les paysans approvisionnent les villes et reçoivent des points.
Les règles à respecter sont les suivantes:
- Les paysans ne reçoivent des points que pour le villes achevées.
- Le pré du paysan doit touché la ville achevée. peu importe la distance qui sépare le paysan de la ville, c'est -à-dire le nombre
  de cartes de paysage qui se trouvent entre la paysan et la ville.
- Le propriétaire du paysan reçoit 4 points pour chaque ville achevées (peu importe le nombre de cartes qui forment la ville)

Une ville se trouve souvent juste à côté de plusieurs prés. Si le cas se présente, tous les paysans dont les prés touchent la ville, sont pris en compte. Mais c'est seulement le joueur qui a le plus grands nombre de paysans qui reçoit 4 points. En cas d'égalité, les différents joueurs concernés reçoivent 4 points. C'est ainsi qu'on évalue toutes les villes. Lorsque les joueurs ont évalué toutes les villes, l'évaluation est finie.
Le joueur qui a le plus grand nombre de points gagne la partie.