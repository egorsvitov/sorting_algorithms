#include <SFML/Graphics.hpp>
#include <vector>
#include <numeric>

void make_a_frame(int* array, int array_size, int max_elem, int number_of_frame) {
    int width = 1920 / array_size;
    int height = 1080 / max_elem;

    sf::Image background;
    background.create(1920, 1080, sf::Color::Black); 
    for (int i = 0; i < array_size; i++) {
        sf::Color column_color{255, 255, 255};
        sf::Image column;
        column.create(width, array[i]*height, column_color);
        background.copy(column, width*i, (1080 - array[i]*height));
    }
    background.saveToFile("frame_" + std::to_string(number_of_frame) + ".png");
}

int* make_shuffled_array(int size) {
    std::vector<int> array_v(size);
    std::iota(array_v.begin(), array_v.end(), 1);
    std::random_shuffle(array_v.begin(), array_v.end());
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = array_v[i];
    }
    return array;
}

