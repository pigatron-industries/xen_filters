#ifndef ChordController_h
#define ChordController_h

#include "Controller.h"
#include "modules/oscillators/OscillatorBank.h"

class ChordController : public Controller {
    public:
        ChordController() {}
        virtual void init(float sampleRate);
        virtual void process(float **in, float **out, size_t size);
        virtual void update();

    private:
        ExpInput<> frequencyInput = ExpInput<>(AnalogInputPin(A0));
        LinearInput<> chordInput = LinearInput<>(AnalogInputPin(A1), -4.9, 4.9, 0, 1);
        LinearInput<> gainInput = LinearInput<>(AnalogInputPin(A5), 0, 5, 0, 1);

        pigatron::OscillatorBank oscillatorBank;
        float gain;
};

#endif
