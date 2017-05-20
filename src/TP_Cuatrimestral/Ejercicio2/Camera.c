//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Camera.h"

Camera* newCamera(int megapixels, int screenSize, int zoom){

    Camera* camera1 = malloc(sizeof(Camera));

    camera1->type = malloc(sizeof(char*) * 2);

    camera1->type[0] = "Reflex";
    camera1->type[1] = "Compact";

    camera1->megapixels = megapixels;
    camera1->screenSize = screenSize;
    camera1->zoom = zoom;

    return camera1;
}

void annihilateCamera(Camera* camera1){
    free(camera1->type[0]);
    free(camera1->type[1]);
    free(camera1->type);
    free(camera1);
}