from __future__ import print_function
from tensorflow.python import keras
from tensorflow.python.keras import backend as K
import numpy as np


def mnist_recognizer(image):
	image = 1.0 - np.asarray(image,dtype="float32") / 255
	image = image.reshape((1,784))
	model = keras.models.load_model('double_layer_model.h5',compile=False)
	answer = model.predict(image,batch_size=1)
	result = np.argmax(answer)
	return result