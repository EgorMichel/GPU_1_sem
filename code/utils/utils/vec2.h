#pragma once
#include "types.h"
#include <cmath>

struct vec2{

    f32 x, y;

    f32       &operator[](u64 const i)       noexcept {return (&x)[i];}
    f32 const &operator[](u64 const i) const noexcept {return (&x)[i];}

};

inline vec2 operator+(vec2 const v1, vec2 const v2) noexcept{
    return{
    .x = v1.x + v2.x,
    .y = v1.y + v2.y
    };
}

inline vec2 operator-(vec2 const v1, vec2 const v2) noexcept{
    return{
    .x = v1.x - v2.x,
    .y = v1.y - v2.y
    };
}

inline vec2 operator-(vec2 const v) noexcept{
    return{
    .x = -v.x,
    .y = -v.y
    };
}

inline vec2 operator*(vec2 const v1, vec2 const v2) noexcept{
    return{
    .x = v1.x * v2.x,
    .y = v1.y * v2.y
    };
}

inline vec2 operator*(vec2 const v, f32 const f) noexcept{
    return{
    .x = v.x * f,
    .y = v.y * f
    };
}

inline vec2 operator/(vec2 const v1, vec2 const v2) noexcept{
    return{
    .x = v1.x / v2.x,
    .y = v1.y / v2.y
    };
}

inline vec2 operator/(vec2 const v, f32 const f) noexcept{
    return{
    .x = v.x / f,
    .y = v.y / f
    };
}

inline f32 dot(vec2 const v1, vec2 const v2) noexcept{
    return v1.x * v2.x
         + v1.y * v2.y;
}

inline f32 length(vec2 const v) noexcept{
    return std::sqrt(dot(v, v));
}

inline vec2 normalize(vec2 const v) noexcept{
    return v / length(v);
}


inline vec2 min(vec2 const v1, vec2 const v2) noexcept{
    return{
    v1.x < v2.x ? v1.x : v2.x,
    v1.y < v2.y ? v1.y : v2.y
    };
}

inline vec2 max(vec2 const v1, vec2 const v2) noexcept{
    return{
    v1.x > v2.x ? v1.x : v2.x,
    v1.y > v2.y ? v1.y : v2.y
    };
}
