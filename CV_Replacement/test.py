#Python implementation of functions
#File created by Steven Anzivino 1/30/2021
#Class: Capstone  | On behalf of XMOS

#run with python3 <filename>.py

def test():
    print("Test reached")

#This function finds the highest x and y values passed to it from a set.
import random
def FindBounds():
    random.seed()
    NumberOfPoints = 5
    XLimit = 15
    YLimit = 20
    randomNumbers = [0,0]
    lists = []


    for i in range(5):
        randomNumbers[0] = random.randint(0,XLimit)
        randomNumbers[1] = random.randint(0,YLimit)
        lists.append(randomNumbers[:])

        
    print(lists)
    print(lists[1][0])

    maxX = lists[0][0]
    maxY = lists[0][1]
    minX = lists[0][0]
    minY = lists[0][1]
    for point in lists:
        if point[0] > maxX:
            maxX = point[0]
        if point[0] < minX:
            minX = point[0]
        if point[1] > maxY:
            maxY = point[1]
        if point[1] < minY:
            minY = point[1]

    print("MaxX=" + str(maxX))
    print("MaxY=" + str(maxY))
    print("MinX=" + str(minX))
    print("MinY=" + str(minY))

FindBounds()