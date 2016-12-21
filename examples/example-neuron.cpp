#include <iostream>
using namespace std;

#include <neuron/neuron.h>

int main()
{
    InputNeuron in("in", 1);
    in.input(2.5);
    cout << in.read() << endl;
}
