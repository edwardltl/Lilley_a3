/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Lilley_a2AudioProcessorEditor  : public AudioProcessorEditor, Slider::Listener
{
public:
    Lilley_a2AudioProcessorEditor (Lilley_a2AudioProcessor&);
    ~Lilley_a2AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    
    // creating sliders
    Slider mixSlider;
    Slider bitSlider;
    
    // creating labels for above sliders
    Label mixLabel;
    Label bitLabel;
    
    void sliderValueChanged(Slider* slider) override;
    
    Lilley_a2AudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Lilley_a2AudioProcessorEditor)
    // a3 - one control for volume of wet signal / levels, one control for fx

};
