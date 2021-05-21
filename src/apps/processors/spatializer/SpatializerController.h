#ifndef SpatializerController_h
#define SpatializerController_h

#include "Spatializer.h"
#include "Controller.h"

class SpatializerController : public Controller {
    public:
        SpatializerController() {}
        virtual void init(float sampleRate);
        virtual void process(float **in, float **out, size_t size);
        virtual void update();

    private:
        LinearInput<> x1Input = LinearInput<>(AnalogPin(A0), -5, 5, -10, 10);
        LinearInput<> y1Input = LinearInput<>(AnalogPin(A1), -5, 5, -10, 10);
        LinearInput<> x2Input = LinearInput<>(AnalogPin(A2), -5, 5, -10, 10);
        LinearInput<> y2Input = LinearInput<>(AnalogPin(A3), -5, 5, -10, 10);

        Spatializer spatializer1;
        Spatializer spatializer2;
};

#endif
