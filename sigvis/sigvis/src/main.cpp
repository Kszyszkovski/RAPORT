#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/complex.h>

#include <matplot/matplot.h>

#include <vector>
#include <string>

#include "headers/dft.hpp"
#include "headers/plot.hpp"
#include "headers/generators.hpp"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)


PYBIND11_MODULE(_core, m) {
    namespace py = pybind11;

    py::class_<Complex>(m, "Complex")
        .def(py::init<double, double>())
        .def("get_real", &Complex::get_real)
        .def("get_imaginary", &Complex::get_imaginary);

    m.doc() = "pybind11 example plugin";

    m.def("dft", &dft);
    m.def("idft", &idft);

    m.def(
        "save_plot",
        &save_plot,
        py::arg("filename"),
        py::arg("in"),
        py::arg("labels") = std::vector<std::string>(),
        py::arg("title") = "",
        py::arg("x_lab") = "",
        py::arg("y_lab") = ""
    );
    m.def(
        "show_plot",
        &show_plot,
        py::arg("in"),
        py::arg("labels") = std::vector<std::string>(),
        py::arg("title") = "",
        py::arg("x_lab") = "",
        py::arg("y_lab") = ""
    );
    m.def(
        "save_plot_xy",
        &save_plot_xy,
        py::arg("filename"),
        py::arg("in_x"),
        py::arg("in_y"),
        py::arg("title") = "",
        py::arg("x_lab") = "",
        py::arg("y_lab") = ""
    );
    m.def(
        "show_plot_xy",
        &show_plot_xy,
        py::arg("in_x"),
        py::arg("in_y"),
        py::arg("title") = "",
        py::arg("x_lab") = "",
        py::arg("y_lab") = ""
    );

    m.def(
        "gen_sin",
        &gen_sin,
        py::arg("amp") = 1,
        py::arg("freq") = 1,
        py::arg("resolution") = 256,
        py::arg("cycles") = 1
    );
    m.def(
        "gen_cos",
        &gen_cos,
        py::arg("amp") = 1,
        py::arg("freq") = 1,
        py::arg("resolution") = 256,
        py::arg("cycles") = 1
    );
    m.def(
        "gen_saw",
        &gen_saw,
        py::arg("amp") = 1,
        py::arg("freq") = 1,
        py::arg("resolution") = 256,
        py::arg("cycles") = 1
    );
    m.def(
        "gen_square",
        &gen_square,
        py::arg("amp") = 1,
        py::arg("freq") = 1,
        py::arg("resolution") = 256,
        py::arg("cycles") = 1
    );

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
