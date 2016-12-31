import cv2

image = cv2.imread('lena_256_gray.jpg')

cv2.imshow('lena',image)

cv2.waitKey(0)

