#include "CombFilterController.h"

#define LEFT 0
#define RIGHT 1

#define MAX_DELAY 0.5

void CombFilterController::init(float sampleRate) {
    this->sampleRate = sampleRate;
    delayLeft.init(sampleRate, MAX_DELAY);
    delayRight.init(sampleRate, MAX_DELAY);

    displayPage.initTitle("Comb Filter (Flanger)", "COMB");
}

void CombFilterController::process(float **in, float **out, size_t size) {
    for (size_t i = 0; i < size; i++) {
        float delayTime = delayTimeInput.getValue();
        delayTimeSlewLimiter.update();
        delayLeft.setDelay(delayTimeSlewLimiter.getValue());
        delayRight.setDelay(delayTimeSlewLimiter.getValue());
        out[LEFT][i] = delayLeft.process(in[LEFT][i]);
        out[RIGHT][i] = delayRight.process(in[RIGHT][i]);
    }
}

void CombFilterController::setDelay(float delayTime) {
    delayLeft.setDelay(delayTime);
    delayRight.setDelay(delayTime);
}

void CombFilterController::update() {
    if(delayTimeInput.update()) {
        delayTimeSlewLimiter.setTargetValue(delayTimeInput.getValue());
    }
    feedbackInput.update();
    dryWetMixInput.update();
    delayLeft.setFeedbackLevel(feedbackInput.getValue());
    delayRight.setFeedbackLevel(feedbackInput.getValue());
    delayLeft.setDryLevel(dryWetMixInput.getDryLevel());
    delayRight.setDryLevel(dryWetMixInput.getDryLevel());
    delayLeft.setWetLevel(dryWetMixInput.getWetLevel());
    delayRight.setWetLevel(dryWetMixInput.getWetLevel());
}