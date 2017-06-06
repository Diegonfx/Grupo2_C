/**
 * Declaration of a label.
 * @authors Tomas Iturralde, Diego Mancini.
 */
#ifndef GRUPO2_C_LABEL_H
#define GRUPO2_C_LABEL_H

typedef struct label Label;

struct label {
    char* id;
    char* name;
};

Label* newLabel(char* id, char* name);
void destroyLabel(Label* label1);


#endif //GRUPO2_C_LABEL_H