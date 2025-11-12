#include <fstream>

const char *readFileToString(const char *filename) {
  std::ifstream file(filename, std::ios::binary | std::ios::ate);

  if (!file.is_open()) {
    return nullptr;
  }

  std::streamsize size = file.tellg();
  file.seekg(0, std::ios::beg);
  char *buffer = new char[size + 1];

  if (!file.read(buffer, size)) {
    delete[] buffer;
    return nullptr;
  }

  buffer[size] = '\0';
  return buffer;
}
