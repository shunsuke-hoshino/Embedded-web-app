#ifndef _KERNEL_H
#define _KERNEL_H

#include <functional>
#include <stdint.h>
#include <task.h>

class TaskBase
{
public:
    using Callback = std::function<void (TaskBase *)>;

    TaskBase(uint8_t );

    TaskBase() = default;

    void Run();

    void Wait(uint32_t );

private:
    void Mainloop(TaskBase *);

};

#endif // _KERNEL_H