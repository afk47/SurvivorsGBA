#pragma once
#ifndef CORE_H
#define CORE_H


#define BIT(x) (1 << x)

#define WAIT(x) for(int i = 0; i<x; ++i){ bn::core::update(); }

#endif // CORE_H
