#pragma once

#include <vector>
#include <cmath>
#include <numbers>
 
constexpr double pi = std::numbers::pi;

std::vector<std::vector<double>> gen_sin(double amp = 1, double freq = 1, size_t resolution = 256, size_t cycles = 1) {
  auto period = 1 / freq;
  // [0] - x axis
  // [1] - y axis
  std::vector<std::vector<double>> out(2);
  out[0] = std::vector<double>(resolution * cycles);
  out[1] = std::vector<double>(resolution * cycles);
  for (size_t i = 0; i < resolution * cycles; ++i) {
    auto frac = ((double)i / (resolution - 1));
    out[0][i] = frac * period;
    out[1][i] = std::sin(frac * 2 * pi) * amp;
  }

  return out;
}

std::vector<std::vector<double>> gen_cos(double amp = 1, double freq = 1, size_t resolution = 256, size_t cycles = 1) {
  auto period = 1 / freq;
  // [0] - x axis
  // [1] - y axis
  std::vector<std::vector<double>> out(2);
  out[0] = std::vector<double>(resolution * cycles);
  out[1] = std::vector<double>(resolution * cycles);
  for (size_t i = 0; i < resolution * cycles; ++i) {
    auto frac = ((double)i / (resolution - 1));
    out[0][i] = frac * period;
    out[1][i] = std::cos(frac * 2 * pi) * amp;
  }

  return out;
}

std::vector<std::vector<double>> gen_saw(double amp = 1, double freq = 1, size_t resolution = 256, size_t cycles = 1) {
  auto period = 1 / freq;
  // [0] - x axis
  // [1] - y axis
  std::vector<std::vector<double>> out(2);
  out[0] = std::vector<double>(resolution * cycles);
  out[1] = std::vector<double>(resolution * cycles);
  for (size_t i = 0; i < resolution * cycles; ++i) {
    auto frac = ((double)i / (resolution - 1));
    out[0][i] = frac * period;
    out[1][i] = -(amp/2) + std::fmod(frac * amp, amp);
  }

  return out;
}

std::vector<std::vector<double>> gen_square(double amp = 1, double freq = 1, size_t resolution = 256, size_t cycles = 1) {
  auto period = 1 / freq;
  // [0] - x axis
  // [1] - y axis
  std::vector<std::vector<double>> out(2);
  out[0] = std::vector<double>(resolution * cycles);
  out[1] = std::vector<double>(resolution * cycles);
  for (size_t i = 0; i < resolution * cycles; ++i) {
    auto frac = ((double)i / (resolution - 1));
    out[0][i] = frac * period;
    out[1][i] = std::fmod(frac, 1) < 0.5 ? -(amp/2) : (amp/2);
  }

  return out;
}
