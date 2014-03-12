#ifndef REFINEDRIVER_H
#define REFINEDRIVER_H

class RefineDriver
{
public:
    virtual void info() const = 0;
    virtual void input() = 0;
    virtual void driver() = 0;
    virtual void output() = 0;
    virtual ~RefineDriver();
};

#endif // REFINEDRIVER_H
