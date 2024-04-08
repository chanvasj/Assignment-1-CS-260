#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

// Class representing an individual marble
class Marble {
public:
    string color;
    string size;

    Marble(string col, string sz) : color(col), size(sz) {}
};

// Class representing the bag of marbles
class BagOfMarbles {
private:
    vector<Marble> marbles;

public:
    void add_marble(Marble marble) {
        marbles.push_back(marble);
    }

    Marble remove_random_marble() {
        if (marbles.empty()) {
            cerr << "The bag is empty! Cannot remove a marble.\n";
            exit(EXIT_FAILURE);
        }

        // Seed the random number generator
        srand(time(nullptr));
        int random_index = rand() % marbles.size();

        Marble removed_marble = marbles[random_index];
        marbles.erase(marbles.begin() + random_index);
        return removed_marble;
    }

    int get_marble_count() {
        return marbles.size();
    }

    vector<Marble> get_all_marbles() {
        return marbles;
    }
};

int main() {
    // Create a new bag of marbles
    BagOfMarbles bag;

    // Add some marbles to the bag
    Marble marble1("red", "small");
    bag.add_marble(marble1);

    Marble marble2("blue", "medium");
    bag.add_marble(marble2);

    // Get the count of marbles in the bag
    cout << "Total marbles in bag: " << bag.get_marble_count() << endl;

    // Remove a random marble from the bag
    Marble removed_marble = bag.remove_random_marble();
    cout << "Removed marble: " << removed_marble.color << " " << removed_marble.size << endl;

    // Verify that the marble is no longer in the bag
    cout << "Total marbles in bag after removal: " << bag.get_marble_count() << endl;

    // Verify that the removed marble is not in the bag
    vector<Marble> all_marbles = bag.get_all_marbles();
    for (const auto& marble : all_marbles) {
        if (marble.color == removed_marble.color && marble.size == removed_marble.size) {
            cout << "Removed marble still in bag!" << endl;
            break;
        }
    }

    return 0;
}
