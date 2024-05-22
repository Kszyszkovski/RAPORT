#pragma once

#include <string>
#include <vector>

void save_plot(
  std::string filename,
  std::vector<std::vector<double>> in,
  std::vector<std::string> labels = {},
  std::string title = "", std::string x_lab = "", std::string y_lab = ""
) {
  using namespace matplot;
  matplot::title(title);
  for (const auto &g : in) {
    plot(g);
    hold(on);
  }
  hold(off);
  if (labels.size() != 0) ::matplot::legend(labels);
  else ::matplot::legend(off);
  xlabel(x_lab);
  ylabel(y_lab);
  save(filename);
  return;
}

void show_plot(
  std::vector<std::vector<double>> in,
  std::vector<std::string> labels = {},
  std::string title = "", std::string x_lab = "", std::string y_lab = ""
) {
  using namespace matplot;
  for (const auto &g : in) {
    plot(g);
    hold(on);
  }
  hold(off);
  if (labels.size() != 0) ::matplot::legend(labels);
  else ::matplot::legend(off);
  matplot::title(title);
  xlabel(x_lab);
  ylabel(y_lab);
  show();
  return;
}

void save_plot_xy(
  std::string filename,
  std::vector<double> in_x,
  std::vector<double> in_y,
  std::string title = "", std::string x_lab = "", std::string y_lab = ""
) {
  using namespace matplot;
  plot(in_x, in_y);
  matplot::title(title);
  xlabel(x_lab);
  ylabel(y_lab);
  ylim({
    *std::min_element(in_y.cbegin(), in_y.cend()) * 1.2,
    *std::max_element(in_y.cbegin(), in_y.cend()) * 1.2,
  });
  save(filename);
  return;
}

void show_plot_xy(
  std::vector<double> in_x,
  std::vector<double> in_y,
  std::string title = "", std::string x_lab = "", std::string y_lab = ""
) {
  using namespace matplot;
  plot(in_x, in_y);
  matplot::title(title);
  xlabel(x_lab);
  ylabel(y_lab);
  ylim({
    *std::min_element(in_y.cbegin(), in_y.cend()) * 1.2,
    *std::max_element(in_y.cbegin(), in_y.cend()) * 1.2,
  });
  show();
  return;
}

