#include <SFML/Graphics.hpp>
#include <vector>
#include <numeric>
#include <vector>

using namespace std;

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

std::vector<int> merge(const std::vector<int>& lhs, const std::vector<int>& rhs) {
    std::vector<int> merged;
    auto i = 0, j = 0;
    for (; i < lhs.size() && j < rhs.size();) {
        if (lhs[i] < rhs[j]) {
                merged.push_back(lhs[i++]);
            } else {
                merged.push_back(rhs[j++]);
        }
    }
    for(; i < lhs.size(); merged.push_back(lhs[i++]));
    for(; j < rhs.size(); merged.push_back(rhs[j++]));
    return merged;
}

std::vector<int> merge_sort(const std::vector<int>& array) {
    if (array.size() > 1) {
        auto middle = array.size() / 2;
        std::vector<int> left, right;
        for(auto i = 0; i < middle; i++) {
            left.push_back(array[i]);
        }
        for(auto i = middle; i < array.size(); i++) {
            right.push_back(array[i]);
        }
        auto sorted_left = merge_sort(left);
        auto sorted_right = merge_sort(right);
        return merge(sorted_left, sorted_right);
    }
    return array;

}
// To find gap between elements
int getNextGap(int gap)
{
	// Shrink gap by Shrink factor
	gap = (gap*10)/13;

	if (gap < 1)
		return 1;
	return gap;
}

// Function to sort a[0..n-1] using Comb Sort
void combSort(int a[], int n)
{
    int countttt = 0;
	// Initialize gap
	int gap = n;

	// Initialize swapped as true to make sure that
	// loop runs
	bool swapped = true;

	// Keep running while gap is more than 1 and last
	// iteration caused a swap
	while (gap != 1 || swapped == true)
	{
		// Find next gap
		gap = getNextGap(gap);

		// Initialize swapped as false so that we can
		// check if swap happened or not
		swapped = false;

		// Compare all elements with current gap
		for (int i=0; i<n-gap; i++)
		{
			if (a[i] > a[i+gap])
			{
				swap(a[i], a[i+gap]);
				swapped = true;
                countttt++;
                make_a_frame(a, 96, 96, countttt);
			}
		}
	}
}

// Sorts array a[0..n-1] using Cocktail sort
void CocktailSort(int a[], int n)
{
    int count = 0;
	bool swapped = true;
	int start = 0;
	int end = n - 1;

	while (swapped) {
		// reset the swapped flag on entering
		// the loop, because it might be true from
		// a previous iteration.
		swapped = false;

		// loop from left to right same as
		// the bubble sort
		for (int i = start; i < end; ++i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
                count++;
                make_a_frame(a, 96, 96, count);
			}
		}

		// if nothing moved, then array is sorted.
		if (!swapped)
			break;

		// otherwise, reset the swapped flag so that it
		// can be used in the next stage
		swapped = false;

		// move the end point back by one, because
		// item at the end is in its rightful spot
		--end;

		// from right to left, doing the
		// same comparison as in the previous stage
		for (int i = end - 1; i >= start; --i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}

		// increase the starting point, because
		// the last stage would have moved the next
		// smallest number to its rightful spot.
		++start;
	}
}

/* Prints the array */
void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

// Driver code

// C++ program for insertion sort

// Function to sort an array using
// insertion sort
void insertionSort(int arr[], int n)
{
    int count = 0;
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		// Move elements of arr[0..i-1],
		// that are greater than key, to one
		// position ahead of their
		// current position
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
        count++;
        make_a_frame(arr, 96, 96, count);
	}
}

// A utility function to print an array
// of size n


int main() {
    int* a = make_shuffled_array(96);
    insertionSort(a, 96);
}