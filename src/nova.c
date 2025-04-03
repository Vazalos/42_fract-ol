#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "../fractol.h"

typedef struct {
    double x;
    double y;
} vec2;

typedef struct {
    double x;
    double y;
    double z;
} vec3;

vec3 magma(double t) {
    const vec3 c0 = {-0.002136485053939582, -0.000749655052795221, -0.005386127855323933};
    const vec3 c1 = {0.2516605407371642, 0.6775232436837668, 2.494026599312351};
    const vec3 c2 = {8.353717279216625, -3.577719514958484, 0.3144679030132573};
    const vec3 c3 = {-27.66873308576866, 14.26473078096533, -13.64921318813922};
    const vec3 c4 = {52.17613981234068, -27.94360607168351, 12.94416944238394};
    const vec3 c5 = {-50.76852536473588, 29.04658282127291, 4.23415299384598};
    const vec3 c6 = {18.65570506591883, -11.48977351997711, -5.601961508734096};

    t *= 2.0;
    if (t >= 1.0) {
        t = 2.0 - t;
    }

    vec3 result = {
        c0.x + t * (c1.x + t * (c2.x + t * (c3.x + t * (c4.x + t * (c5.x + t * c6.x))))),
        c0.y + t * (c1.y + t * (c2.y + t * (c3.y + t * (c4.y + t * (c5.y + t * c6.y))))),
        c0.z + t * (c1.z + t * (c2.z + t * (c3.z + t * (c4.z + t * (c5.z + t * c6.z)))))
    };

    return result;
}

vec2 cmul(vec2 a, vec2 b) {
    return (vec2){ a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x };
}

vec2 cdiv(vec2 a, vec2 b) {
    double d = b.x * b.x + b.y * b.y;
    return (vec2){ (a.x * b.x + a.y * b.y) / d, (a.y * b.x - a.x * b.y) / d };
}

vec2 cpowa(vec2 z, double n) {
    double r = sqrt(z.x * z.x + z.y * z.y);
    double a = atan2(z.y, z.x);
    return (vec2){ pow(r, n) * cos(a * n), pow(r, n) * sin(a * n) };
}

double map(vec2 z, vec2 c, double n, bool mouseDown, vec2 mouse, vec2 resolution) {
    double i = 0.0;
    double p = 3.0; // Degree
    vec2 z_prev = {0, 0};
    if (mouseDown) {
        c = (vec2){ 0.75 * (2.0 * mouse.x - resolution.x) / resolution.y - 0.5, 0.75 * (2.0 * mouse.y - resolution.y) / resolution.y };
    } else {
        z = (vec2){ 1.0, 0.0 };
    }
    for (i = 0.0; i < n; i++) {
        z_prev = z;
        z = (vec2){ z.x - ((cpowa(z, p).x - 1) / (3 * cpowa(z, p - 1).x)) + c.x, z.y - ((cpowa(z, p).y - 1) / (3 * cpowa(z, p - 1).y)) + c.y };
        if (fabs((z.x - z_prev.x) * (z.x - z_prev.x) + (z.y - z_prev.y) * (z.y - z_prev.y)) < 0.0001) {
            break;
        }
    }
    return i / n;
}

int nova() {
    vec2 resolution = {WIDTH, HEIGHT};
    vec2 mouse = {400, 300};
    bool mouseDown = false;

    vec2 uv = (vec2){ 0.75 * (2.0 * mouse.x - resolution.x) / resolution.y - 0.5, 0.75 * (2.0 * mouse.y - resolution.y) / resolution.y };
    double t = map(uv, uv, 64.0, mouseDown, mouse, resolution);
    vec3 color = magma(t);

    printf("Color: R=%f, G=%f, B=%f\n", color.x, color.y, color.z);

    return 0;
}
