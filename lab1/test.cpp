#include <iostream>

int main() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Outer loop iteration: " << i << std::endl;
        int choice = i % 2; // Simulate a condition for the switch

        switch (choice) {
            case 0:
                std::cout << "  Inside switch, case 0." << std::endl;
                // If 'continue' is here, it will skip the remaining part of the 'for' loop for this 'i'
                if (i == 2) {
                    continue; // This 'continue' affects the 'for' loop
                }
                break;
            case 1:
                std::cout << "  Inside switch, case 1." << std::endl;
                break;
            default:
                std::cout << "  Inside switch, default." << std::endl;
                break;
        }
        std::cout << "After switch, in outer loop." << std::endl;
    }
    return 0;
}