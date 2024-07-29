#pragma once

#include <string>

namespace logic {

class i_writer {
 public:
  virtual void write(const std::string& str) const = 0;

  virtual ~i_writer() = default;
};

}  // namespace logic
