#ifndef PROJETOEDA_SECTIONS_H
#define PROJETOEDA_SECTIONS_H

struct Section{
    char id;
    int capacity;
    char category[100];
};

void printSection(Section& section);

#endif //PROJETOEDA_SECTIONS_H
