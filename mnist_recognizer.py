from __future__ import print_function
from tensorflow.python import keras
from tensorflow.python.keras import backend as K
import numpy as np
import cv2

def mnist_recognizer(image):
	cv2.imwrite("img_last.bmp", image)
	K.clear_session()
	model = keras.models.load_model('double_layer_model.h5')
	image = np.expand_dims(image,axis=0)
	image = image.reshape(image.shape[0],28,28,1)
	answer = model.predict(image)
	result = np.argmax(answer)
	print(answer)
	print(result)
	return result