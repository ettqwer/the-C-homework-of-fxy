#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class Model
{
public:
    Model();
    static bool strMatch(const char *str1, const char *str2);
};
#endif // MODEL_H
