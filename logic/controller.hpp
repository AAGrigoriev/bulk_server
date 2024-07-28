#pragma once

#include <strstream>

#include "global_context.hpp"

namespace logic {

class controller {
 public:
  controller(global_context& context);

  void process_command(std::istream& stream);

 private:
  global_context& context_;
};
}  // namespace logic
