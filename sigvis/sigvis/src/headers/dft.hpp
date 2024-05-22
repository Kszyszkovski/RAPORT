#pragma once

#include <vector>
#include <cmath>

struct Complex {
    double real, imaginary;

    double get_real() const { return real; }
    double get_imaginary() const { return imaginary; }

    Complex(double r, double i) : real(r), imaginary(i) {}
    Complex() = default;
};

std::vector<Complex> dft(std::vector<double> in, int N) {
    std::vector<Complex> out;
    std::vector<double> x_r; // real parts
    std::vector<double> x_i; // imaginary parts

    auto len = in.size();

    for (int k = 0; k < N; ++k) {
        x_r.push_back(0.0);
        x_i.push_back(0.0);
        for (int n = 0; n < len; ++n) {
            x_r[k] += (in[n] * std::cos(2 * 3.141592 * k * n / N));
            x_i[k] += (in[n] * std::sin(2 * 3.141592 * k * n / N));
        }
        out.push_back(Complex(x_r[k], x_i[k]));
    }

    return out;
}

std::vector<double> idft(std::vector<Complex> in, int N) {
    std::vector<double> out;

    auto len = in.size();

    for (int n = 0; n < N; ++n) {
        out.push_back(0.0);
        for (int k = 0; k < N; ++k) {
            int theta = (2 * 3.141592 * k * n) / N;
            out[n] += in[k].get_real() * std::cos(theta) + in[k].get_imaginary() * std::sin(theta);
        }
        out[n] /= N;
    }

    return out;
}
