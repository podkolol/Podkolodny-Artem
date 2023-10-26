//Подколодный Артем летучка 4 ИУ10-16

#include <iostream>

struct MobilePhone{
    double weight;
    bool is_broken;
    double price;
};

int main(){
    int numofnum;
    std::cout << "Enter number of phones:" << std::endl;
    std::cin >> numofnum;
    if (numofnum > 0) {
        MobilePhone numbers[numofnum];
        std::cout << "Enter weight, condition, price:" << std::endl;
        for (int i = 0; i < numofnum; i++) {
            std::cin >> numbers[i].weight >> numbers[i].is_broken >> numbers[i].price;
        }
        std::cout << "<MobilePhone>" << std::endl;
        for (int i = 0; i < numofnum; i++) {
            if (numbers[i].is_broken) {
                std::cout << "\t<MobilePhone id=\""<< i << "\" weight=\"" << numbers[i].weight << "\" is_broken=\""<< "true" << "\" price=\"" << numbers[i].price << "\"/>\n"; }
            else {
                std::cout << "\t<MobilePhone id="<< i << "\" weight=\"" << numbers[i].weight << "\" is_broken=\""<< "false" << "\" price=\"" << numbers[i].price << "\"/>\n";
            }
        }
        std::cout << "</MobilePhone>" << std::endl;
    }
    
}