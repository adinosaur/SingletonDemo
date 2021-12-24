#pragma once

template<class T> class Singleton
{
public:
    static T* instance()
    {
        if (!inst_)
            inst_ = new T();
        return inst_;
    }

protected:
    static T* inst_;
};

template<class T>
T* Singleton<T>::inst_ = 0;