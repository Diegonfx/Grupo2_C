//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_LABEL_H
#define GRUPO2_C_LABEL_H

typedef struct label Label;

struct label {
    char* id;
    char* name;
};

Label* newLabel(char* id, char* name);
void annihilateLabel(Label* label1);


#endif //GRUPO2_C_LABEL_H
