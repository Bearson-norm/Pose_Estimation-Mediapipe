# Pose_Estimation-Mediapipe

<br>  _️**[DISCLAIMER] This is modified version of the [Modified repo](https://github.com/kinivi/hand-gesture-recognition-mediapipe) and this [original repo](https://github.com/Kazuhito00/hand-gesture-recognition-using-mediapipe).**_ 
<br> 

## 1.Introduction

Here we implement the Mediapipe Handpose pipeline by extracting characteristics from the sensing results to be used in the control system, which in this repository is Servos that been controlled by ESP with MQTT protocol communication between the esp and the pipeline.

## 2.Requirement

Same as original repo, we used the essential mediapipe framework such as :
* mediapipe 0.8.1
* OpenCV 3.4.2 or Later
* Tensorflow 2.3.0 or Later<br>tf-nightly 2.5.0.dev or later (Only when creating a TFLite for an LSTM model)
* scikit-learn 0.23.2 or Later (Only if you want to display the confusion matrix) 
* matplotlib 3.3.2 or Later (Only if you want to display the confusion matrix)

but in this repo, we have additional repo such as :
* paho.mqtt.client

## 3.Demo
Here's how to run the demo using your webcam.
```bash
python app.py
```

The following options can be specified when running the demo.
* --device<br>Specifying the camera device number (Default：0)
* --width<br>Width at the time of camera capture (Default：960)
* --height<br>Height at the time of camera capture (Default：540)
* --use_static_image_mode<br>Whether to use static_image_mode option for MediaPipe inference (Default：Unspecified)
* --min_detection_confidence<br>
Detection confidence threshold (Default：0.5)
* --min_tracking_confidence<br>
Tracking confidence threshold (Default：0.5)

YOU HAVE TO SPECIFIED BROKER ADDRESS FIRST TO MAXIMIZE THE FUNCTION, HOWEVER MEDIAPIPE STILL WORKS
