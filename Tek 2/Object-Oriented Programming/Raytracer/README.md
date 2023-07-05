# Raytracer

*Vous trouverez ci dessous les parametres à entrer dans le fichier de configuration pour créer une nouvelle scene.*

## **Camera :**

    resolution = {width = value; height = value; }; definit la resolution de l'image finale<br>
    position = {x = value; y = value; z = value; }; definit la position de la caméra<br>
    rotation = {x = value; y = value; z = value; }; definit la rotation de la caméra<br>
    fieldOfView = value; definit le champ de vision de la caméra<br>
    antialiasing = value; change le niveau d'anticrénelage pour avoir une image + ou - "lisse"<br>
    postProcessing = value; ajoute un filtre à l'image parmis ces trois : BlackAndWhite, Blur, Sepia<br>
    
------

## **Primitives :**

### Sphere :
    center = {x = value; y = value; z = value; }; definit coordonnées du centre de la sphère
    radius = value; definit rayon de la sphère
    rotation = {x = value; y = value; z = value; }; definit la rotation de la sphère
    color = { r = value; g = value; b = value; }; definit la couleur de la sphère
    material = { transparency = 0.0; reflection = 0.0; ior = 0.0; }; definit les materieux de la sphère

### Plan :
    origin = {x = value; y = value; z = value; }; definit coordonnées de l'origine du plan
    axis = "X, Y ou Z" definit l'axe du plan
    rotation = {x = value; y = value; z = value; }; definit la rotation du plan
    color = { r = value; g = value; b = value; }; definit la couleur du plan
    material = { transparency = 0.0; reflection = 0.0; ior = 0.0; }; efinit les materiaux du plan

### Cylindre :
    center = {x = value; y = value; z = value; }; definit les coordonnées du centre de la base du cylindre
    radius = value; definit le rayon de la base du cylindre
    height = value; definit la hauteur du cylindre
    rotation = {x = value; y = value; z = value; }; definit la rotation du cylindre
    color = { r = value; g = value; b = value; }; definit la couleur du cylindre
    material = { transparency = 0.0; reflection = 0.0; ior = 0.0; }; efinit les materiaux du cylindre

### Cone :
    center: {x = value; y = value; z = value; }; definit les coordonnées du centre de la base du cône
    radius = value; definit le rayon de la base du cône
    height = value; definit la hauteur du cône
    rotation = {x = value; y = value; z = value; }; definit la rotation du cône
    color = { r = value; g = value; b = value; }; definit la couleur du cône
    material = { transparency = 0.0; reflection = 0.0; ior = 0.0; }; efinit les materiaux du cône

### Ruban de Mobius :
    center: {x = value; y = value; z = value; }; definit les coordonnées du centre du mobiusStrips
    radius = value; definit le rayon du mobiusStrip
    width: definit la largeur du mobiusStrip
    rotation = {x = value; y = value; z = value; }; definit la rotation du mobiusStrip
    color = { r = value; g = value; b = value; }; definit la couleur du mobiusStrip
    material = { transparency = 0.0; reflection = 0.0; ior = 0.0; }; efinit les materiaux du mobiusStrip

-----

## **Lights:**

    ambient = value; definit la luminosité<br>
    diffuse = value; definit la diffusion de la lumière<br>
    isAmbiant = bool; definit si la lumiere est ambiante ou directionnelle<br>

    point = (
        { position = {x = value; y = value; z = value; }; } definit la position de la lumière
    );
