#ifndef REFINEDRIVER_H
#define REFINEDRIVER_H

class RefineDriver
{
public:
    virtual void info() const = 0;
    virtual void input() = 0;
    virtual void driver() = 0;
};

#endif // REFINEDRIVER_H
