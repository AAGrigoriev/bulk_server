#pragma once

#include <cstddef>

namespace logic {

class global_context {
 public:
  static global_context& get_instance(std::size_t bulk_size);
};

}  // namespace logic
