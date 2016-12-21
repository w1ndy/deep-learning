#ifndef __NEURON_NEURON_H__
#define __NEURON_NEURON_H__

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <cassert>


class Neuron
{
protected:
    virtual void activate(const Neuron &n) = 0;
    virtual void reset(const Neuron &n) = 0;

public:
    virtual void input(Neuron &n) = 0;
    virtual void output(Neuron &n) = 0;

    virtual double read() const = 0;
    virtual bool has(const Neuron &n) const = 0;

    virtual const std::string &name() const = 0;

public:
    typedef std::reference_wrapper<Neuron> ref;

    friend class InputNeuron;
};

class InputNeuron: public Neuron
{
private:
    double _value;
    std::string _name;
    std::unordered_map<std::string, Neuron::ref> _targets;

protected:
    void activate(const Neuron &n) {
        assert(false && "InputNeuron cannot be activated by other neurons.");
    }

    void reset(const Neuron &n) {
        assert(false && "InputNeuron cannot be reset by other neurons.");
    }

public:
    InputNeuron(const std::string &name, double initialValue = 0) {
        input(initialValue);
    }

    void input(Neuron &n) {
        assert(false && "InputNeuron does not accept neurons as input.");
    }

    void input(double value) {
        _value = value;
    }

    double read() const {
        return _value;
    }

    bool has(const Neuron &n) const {
        return _targets.find(n.name()) != _targets.end();
    }

    void output(Neuron &n) {
        assert(has(n) && "Neuron already associated to this InputNeuron.");
        _targets.insert(
            std::make_pair<const std::string &, Neuron::ref>(n.name(), n));
    }

    void activate() {
        for (auto &ptr: _targets)
            ptr.second.get().activate(*this);
    }

    void reset() {
        for (auto &ptr: _targets)
            ptr.second.get().reset(*this);
    }

    const std::string &name() const {
        return _name;
    }
};

#endif // __NEURON_NEURON_H__
