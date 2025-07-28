#include <iostream>
using namespace std;

class Device {
public:
    void identify() {
        cout << "I am a generic device.\n";
    }
};

class Phone : virtual public Device {};

class Camera : virtual public Device {};

class SmartPhone : public Phone, public Camera {
    // Inherits from both Phone and Camera
};

int main() {
    SmartPhone s;
    s.identify();  //  Ambiguity here! if we don't use virtual for inheriting.
    return 0;
}
