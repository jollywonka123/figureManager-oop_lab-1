#ifndef CONSTANTS_H
#define CONSTANTS_H

enum Option {
    DEFAULT = -1,
    EXIT,
    ADD_FIGURE,
    OUTPUT_PARAM,
    OUTPUT_PERIM,
    PRINT_PERIM_SUM,
    SORT_PERIM_ASC,
    DELETE_BY_NUM,
    DELETE_LARGER_PERIM,
};

typedef struct {
    double x;
    double y;
} Dot;

#endif //CONSTANTS_H
