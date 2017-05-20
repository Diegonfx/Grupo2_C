//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_CAMERA_H
#define GRUPO2_C_CAMERA_H

typedef struct camera Camera;

struct camera {
    int megapixels;
    int screenSize;
    int zoom;
    char **type;
};

Camera* newCamera(int megapixels, int screenSize, int zoom );
void annihilateCamera(Camera* camera1);

#endif //GRUPO2_C_CAMERA_H
