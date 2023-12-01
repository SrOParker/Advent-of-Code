#include <iostream>
#include <fstream>
#include <string>
#include <vector>


const u_int16_t resolveLine(std::string line){
    char c1{'0'},c2{'0'};
    u_int8_t couple{0};

    for (int i{0}; i < line.length(); i++){
        if(std::isdigit(line.at(i))){
            c1 = line.at(i);
            i = line.length();
        }
    }
    for (int i{static_cast<int>(line.length()-1)}; i >= 0; i--){
        if(std::isdigit(line.at(i))){
            c2 = line.at(i);
            i = -1;
        }
    }
    
    return std::stoi(std::string(1, c1) + std::string(1, c2));
}

const u_int16_t readStars(const std::string fileName) {
    u_int16_t calibrationSumatory{0};
    const std::string file {fileName};
    std::ifstream archive(file);

    if (!archive.is_open()){
        std::cout << "Wrong File\n";
        return 0;
    }

    std::string line;
    while (std::getline(archive, line)) {
        calibrationSumatory += resolveLine(line);
    }

    archive.close();
    return calibrationSumatory;
}

int main (){
    std::cout << "Calibration Value is "<< readStars("files/stars.txt") << "\n";
    return 0;
}