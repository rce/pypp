#include <pybind11/embed.h>
#include <iostream>

namespace py = pybind11;
using namespace py::literals;

int main() {
  std::cout << "Using python " << PY_VERSION << std::endl;

  py::scoped_interpreter guard{};

  std::cout << "Hello from C++!" << std::endl;

  py::module example = py::module::import("scripts.example");
  py::object result = example.attr("init")();
  int n = result.cast<int>();
  assert(n == 42);
}

PYBIND11_EMBEDDED_MODULE(native_code, m) {
  m.def("some_function", [](){
    std::cout << "Hello from C++ callback!" << std::endl;
  });

  m.def("add", [](int a, int b) { return a + b; });
}
