#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Calculate the signal quality of a tower at a given coordinate
int signalQuality(int x, int y, int q, int radius, int cx, int cy) {
    int d = sqrt(pow(x-cx, 2) + pow(y-cy, 2));
    if (d > radius) {
        return 0;
    } else {
        return q / (1 + d);
    }
}

// Calculate the network quality at a given coordinate
int networkQuality(vector<vector<int>>& towers, int radius, int cx, int cy) {
    int quality = 0;
    for (auto& tower : towers) {
        quality += signalQuality(tower[0], tower[1], tower[2], radius, cx, cy);
    }
    return quality;
}

vector<int> findBestLocation(vector<vector<int>>& towers, int radius) {
    int n = towers.size();
    int bestQuality = 0;
    vector<int> bestLocation = {0, 0};

    // Iterate over all integral coordinates and find the one with maximum network quality
    for (int x = 0; x <= 50; x++) {
        for (int y = 0; y <= 50; y++) {
            int quality = networkQuality(towers, radius, x, y);
            if (quality > bestQuality) {
                bestQuality = quality;
                bestLocation = {x, y};
            }
        }
    }

    return bestLocation;
}

int main() {
    vector<vector<int>> towers = {{1,2,5},{2,1,7},{3,1,9}};
    int radius = 2;
    vector<int> bestLocation = findBestLocation(towers, radius);
    cout << "Best location: (" << bestLocation[0] << ", " << bestLocation[1] << ")" << endl;
    return 0;
}