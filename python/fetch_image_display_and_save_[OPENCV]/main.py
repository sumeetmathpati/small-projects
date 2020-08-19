import argparse
import cv2

ap = argparse.ArgumentParser()
ap.add_argument('-i', '--image', required=True, help='Path to the image')
args = vars(ap.parse_args())

image = cv2.imread(args['image'])
print(image)
# print(f'Weidth of the image is {image.shape[1]}')
# print(f'Height of the image is {image.shape[0]}')
# print(f'channel of the image is {image.shape[2]}')

cv2.imshow('imae', image)
cv2.waitKey(5000)
cv2.imwrite('./newimg.jpg', image)