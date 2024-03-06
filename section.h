

#ifndef PROJETOEDA_SECTION_H
#define PROJETOEDA_SECTION_H

struct Section{
    char id;
    int capacity;
    char category[100];
};

void printSection(Section& section);

//ID único, capacidade máxima e categoria

#endif //PROJETOEDA_SECTION_H
