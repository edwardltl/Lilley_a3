/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Lilley_a2AudioProcessorEditor::Lilley_a2AudioProcessorEditor (Lilley_a2AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setOpaque (true);
    
    // custom coding by ed to make sliders
    setSize (300, 150); // sets default size to 300x150 pixels
    
    mixSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, true, 40, 12); // creates text box to show value below slider
    mixSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag); // sets the style of slider as a rotating knob controlled by vertical dragging
    mixSlider.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::teal); // sets the colour of slider to teal
    mixSlider.setValue(0.5f); // sets default value of dry/wet signal to 50%
    mixSlider.setRange(0.0f, 1.0f); // sets range of dry/wet signal between 0-100%
    mixSlider.setNumDecimalPlacesToDisplay(2); // only displays two decimal places
    mixSlider.setColour(Slider::ColourIds::textBoxTextColourId, Colours::red); // sets text box to red
    mixSlider.addListener(this); // creates slider listener
    addAndMakeVisible(mixSlider); // makes slider visible
    
    mixLabel.setText ("Dry / Wet", dontSendNotification); // sets label text
    addAndMakeVisible (mixLabel); // makes label for slider visible

    
    bitSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, true, 40, 12); // creates text box to show value below slider
    bitSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag); // sets the style of slider as a rotating knob controlled by vertical dragging
    bitSlider.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::teal); // sets the colour of slider to teal
    bitSlider.setValue(8.0f); // sets default value of bit crushing to none
    bitSlider.setRange(1.0f, 8.0f); // sets value range of bit crushing between 1 & 8
    bitSlider.setNumDecimalPlacesToDisplay(2); // only displays two decimal places
    bitSlider.setColour(Slider::ColourIds::textBoxTextColourId, Colours::red); // sets text box to red
    bitSlider.addListener(this); // creates slider listener
    addAndMakeVisible(bitSlider); // makes slider visible
    
    bitLabel.setText ("Intensity", dontSendNotification); // sets label text
    addAndMakeVisible (bitLabel); // makes label for slider visible
}

Lilley_a2AudioProcessorEditor::~Lilley_a2AudioProcessorEditor()
{
}

//==============================================================================
void Lilley_a2AudioProcessorEditor::paint (Graphics& g)
{
    // custom coding by ed to set graphics
    g.fillAll (Colours::black); // sets background colour to black
    
    g.setColour (Colours::azure); // sets font colour to azure
    g.setFont (Font ("Georgia", 20.0f, Font::bold)); // sets typeface, size
    g.drawFittedText ("B I T C R U S H E R", getLocalBounds(), Justification::centredTop, 1); // desired text
    
    g.setColour (Colours::azure); // sets font colour to azure
    g.setFont (Font ("Georgia", 10.0f, Font::plain)); // sets typeface, size
    g.drawFittedText ("Lilley_a3 - Graphical User Interface", getLocalBounds(), Justification::centredBottom, 1); // desired text
    }

void Lilley_a2AudioProcessorEditor::resized()
{
    // slider & label positioning
    mixSlider.setBounds(40, getHeight()-130, 80, 80);
    mixLabel.setBounds(45, getHeight()-75, 80, 80);
    
    bitSlider.setBounds(180, getHeight()-130, 80, 80);
    bitLabel.setBounds(190, getHeight()-75, 80, 80);
}

void Lilley_a2AudioProcessorEditor::sliderValueChanged(Slider *slider) {
    if (slider == &mixSlider)
    {
        // get the value on current slider, pass that value to our audio processor
        processor.mixLevel.setTargetValue(mixSlider.getValue());
    }
    
    if (slider == &bitSlider)
    {
        // get the value on current slider, pass that value to our audio processor
        processor.bitValue.setTargetValue(bitSlider.getValue());
    }
}
