#include <fstream>
#include <iostream>
#include <vector>

void readFile(std::string fileName);

int main(int argc, char const *argv[]) {
  if (argc == 1 || argc > 2) {
    std::cout << "Debe introducir la ruta del archivo o el nombre si está en "
                 "la misma carpeta"
              << std::endl;
    return 1;
  } else {
    readFile(argv[1]);
  }
  return 0;
}

void readFile(std::string fileName) {
  std::vector<std::string> last_five_lines;
  std::fstream newfile;
  newfile.open(fileName, std::ios::in);
  if (newfile.is_open()) {
    std::string tp;
    while (getline(newfile, tp)) {
      if (last_five_lines.size() == 5) {
        last_five_lines.erase(last_five_lines.begin());
      }
      last_five_lines.push_back(tp);
    }
    newfile.close();
  } else {
    std::cout << "Error al abrir el archivo" << std::endl;
  }

  for (size_t i = 0; i < last_five_lines.size(); i++) {
    std::cout << last_five_lines.at(i) << std::endl;
  }
}
