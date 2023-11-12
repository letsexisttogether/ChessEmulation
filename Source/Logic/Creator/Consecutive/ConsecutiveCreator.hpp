#pragma once

#include <stdexcept>

template <class _Instance>
class ConsecutiveCreator
{
public:
    ConsecutiveCreator() = delete;

    ConsecutiveCreator(const _Instance& start, const _Instance& step,
            const _Instance& lowest, const _Instance& highest)
        : m_NextInstance{ start }, m_Start{ start }, m_Step{ step },
        m_Lowest{ lowest }, m_Highest{ highest }
    {}

    ~ConsecutiveCreator() = default;

    _Instance CreateInstance() noexcept(false)
    {
        if (!CheckRowBoundries())
        {
            throw std::exception
            { 
                "The instance is out of the specified range" 
            };
        }

        _Instance instance{ m_NextInstance };

        ChangeNextInstance();

        return instance;
    }

protected:
    virtual void ChangeNextInstance() noexcept(false) = 0;

    virtual bool CheckColumnBoundries() const noexcept = 0;
    virtual bool CheckRowBoundries() const noexcept = 0;

protected:
    _Instance m_NextInstance;

    const _Instance m_Step;

    const _Instance m_Start;

    const _Instance m_Lowest;
    const _Instance m_Highest;
};
