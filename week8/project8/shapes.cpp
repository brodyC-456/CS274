#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <limits>
#include "shapes.h"


int usage(){
    std::cout << "usage: shapes [c | r | rp | rt | s vals]\n";
    return 1;
}

int main(int argc, char *argv[]){
    std::vector<Shape*> shapes;

    if(argc < 3){
        return usage();
    }

    // Filling the vector with command line shapes

    for(int i = 1; i < argc; ){
        std::string arg{argv[i]};
        if(arg == "c"){
            if(i + 1 >= argc){return usage();}
            shapes.push_back(new Circle(std::stof(argv[i + 1])));
            i += 2;
        }
        else if(arg == "r"){
            if(i + 2 >= argc){return usage();}
            shapes.push_back(new Rectangle(std::stof(argv[i + 1]), std::stof(argv[i + 2])));
            i += 3;
        }
        else if(arg == "rp"){
            if(i + 2 >= argc){return usage();}
            shapes.push_back(new RegPolygon(std::stoi(argv[i + 1]), std::stof(argv[i + 2])));
            i += 3;
        }
        else if(arg == "rt"){
            if(i + 2 >= argc){return usage();}
            shapes.push_back(new RightTriangle(std::stof(argv[i + 1]), std::stof(argv[i + 2])));
            i += 3;
        }
        else if(arg == "s"){
            if(i + 1 >= argc){return usage();}
            shapes.push_back(new Square(std::stof(argv[i + 1])));
            i += 2;
        }
        else{
            return usage();
        }

    }

    float max_area = -std::numeric_limits<double>::infinity();
    float max_circ = -std::numeric_limits<double>::infinity();
    std::vector<std::string> max_area_shapes;
    std::vector<std::string> max_circ_shapes;
    
    for (Shape* shape : shapes) {
        float area = shape->area();
        float circ = shape->circumference();
        std::string name = shape->name();
        
        if(area > max_area){
            max_area = area;
            max_area_shapes.clear();
            max_area_shapes.push_back(name);
        }
        else if(area == max_area){max_area_shapes.push_back(name);}

        if(circ > max_circ){
            max_circ = circ;
            max_circ_shapes.clear();
            max_circ_shapes.push_back(name);
        }
        else if(circ == max_circ){max_circ_shapes.push_back(name);}


        std::cout << std::format("{}\n", name);
        std::cout << std::format("  area: {}\n", area);
        std::cout << std::format("  circ: {}\n\n", circ);
    }

    std::cout << std::format("Shapes with max area {}\n", max_area);
    for(std::string shape : max_area_shapes){std::cout << std::format("  {}\n", shape);}
    std::cout << "\n";

    std::cout << std::format("Shapes with max circumference {}\n", max_circ);
    for(std::string shape : max_circ_shapes){std::cout << std::format("  {}\n", shape);}
    std::cout << "\n";

    for (Shape* shape : shapes) {
        delete shape;
    }
}