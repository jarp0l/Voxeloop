#include "FileHandler.hpp"

std::string getFileData(const char *filename) {
  std::ifstream in(filename, std::ios::binary);
  if (in) {
    std::string out;
    in.seekg(0, std::ios::end);
    out.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&out[0], out.size());
    in.close();

    return out;
  }
  throw(errno);
}
