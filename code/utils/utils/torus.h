//
// Created by egorich on 18.09.23.
//
#include "ray.h"
#include "vec3.h"
#include "vec2.h"
#include <optional>
#include <iostream>

struct Torus
{
    vec3 origin;
    f32 r1;
    f32 r2;
};

float sdTorus(vec3 p, const Torus& t) {
    auto tmp = p - t.origin;
    return length(vec2(length(vec2{tmp.x, tmp.z}) - t.r1, tmp.y)) - t.r2;
}


inline std::optional<RayRange> rayIntersection(Ray const ray, Torus const torus) noexcept{
    RayRange r{};
    const f32 eps = 1e-2f;
    f32 t = sdTorus(ray.origin, torus) / length(ray.direction);
    f32 prev_dist, dist;

    dist = sdTorus(ray.origin + ray.direction * t, torus);

    while (dist > eps) {
        t += sdTorus(ray.origin + ray.direction * t, torus) / length(ray.direction);
        prev_dist = dist;
        dist = sdTorus(ray.origin + ray.direction * t, torus);

        if (dist > prev_dist)
            return std::nullopt;
    }

    r.tMin = t;
//    r.tMax = t;
//
//    return nonempty(r)
//           ? std::optional{r}
//           : std::nullopt;

    t += eps;
    dist = sdTorus(ray.origin + ray.direction * t, torus);

    while (dist < eps){
        t += eps;
        dist = sdTorus(ray.origin + ray.direction * t, torus);
    }
    r.tMax = t;

    return nonempty(r)
           ? std::optional{r}
           : std::nullopt;

//    auto const &[O, d] = ray;
//
//    f32 const maxDist = 100.f;
//
//    auto const raymarch = [&](vec3 const pos) noexcept -> f32
//    {
//        f32 dist = 0;
//        auto const raymarchImpl = [&](auto const self, vec3 const p) noexcept -> f32
//        {
//            f32 const latest = sdTorus(p, torus);
//            dist += latest;
//            return (latest > 1e-4f && dist < maxDist)
//                   ? self(self, O + d * dist)
//                   : dist;
//        };
//        return raymarchImpl(raymarchImpl, pos);
//    };
//
//    f32 const t = raymarch(O);
//    f32 const res = t < maxDist
//                    ? t
//                    : -1.f;
//
//    return std::optional{RayRange{res, res}};
}
