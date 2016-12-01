#pragma once

#include <atomic>

class spinlock
{
public:
    void lock()
    {
        while(!try_lock())
        {
            _locked = true;
        }
    }
    bool try_lock()
    {
        return !_locked.exchange(true);
    }
    void unlock()
    {
        assert(_locked);
        _locked = false;
    }

private:
    std::atomic<bool> _locked { false };
};
