#pragma once
#include <string>
#include <vector>

namespace anatomy::core {
struct Name {
  std::string english;
  std::string latin;
  std::vector<std::string> synonyms;
};

enum class Laterality { None, Left, Right, Bilateral, Midline };

struct Codes {
  std::string fma;
  std::string snomed;
  std::string mesh;
};
} // namespace anatomy::core
