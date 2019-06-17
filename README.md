# Indie Studio

## Compilation
### Linux
* \$> mkdir build
* \$> cd build
* \$> cmake ..
* \$> make

### Windows
* \$> mkdir build
* \$> cd build
* \$> cmake -A x64 ..
* \$> cmake --build .
* L'exécutable se trouve dans le dossier /Debug, pour fonctionner correctement il doit être à la racine dans /build

## Personnage
### Power-ups
|**Power**|**Description**|
|---:|:---|
|SpeedUp|Augmente la vitesse de déplacement du joueur de 1|
|BombUp|Augmente le nombre de bombes qu'un joueur peut avoir sur le terrain en même temps|
|WallPass|Permet au joueur de marcher librement dans les blocs souples|
|FireUp|Augmente la portée du souffle de la bombe de 1|

## Ennemies
|**Ennemies**|**Images**|
|---:|:---|
|Matango|<img src="img/Matango.jpg" alt="Matango" width="100"/>|
|Seeker Balloon|<img src="img/SeekerBalloon.png" alt="SeekerBalloon" width="80"/>|
|Gingerbread Man|<img src="img/GingerbreadMansprite.png" alt="GingerbreadMan" width="80"/>|

## Gameplay
|**Personnage**|**Touches**|**Effet**|
|---:|:---|:---|
|Principal|Flèche du haut<br/>Flèche du bas<br/>Flèche de gauche<br/>Flèche de droite<br/>Touche 'M'|Vers le haut<br/>Vers le bas<br/>Vers la gauche<br/>Vers la droite<br/>Pose de bombe|
|Second|Touche 'Z'<br/>Touche 'S'<br/>Touche 'Q'<br/>Touche 'D'<br/>Touche 'A'|Vers le haut<br/>Vers le bas<br/>Vers la gauche<br/>Vers la droite<br/>Pose de bombe|
