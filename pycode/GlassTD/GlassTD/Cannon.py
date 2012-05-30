import Direction
import AbstractMagazine

class Cannon:
	'''abstract cannon base class'''
	
	def __init__(self):
		self.mDirection = Direction()
		self.mMagazine = AbstractMagazine()
		
	def setDirection(direction):
		self.mDirection = direction
	
	def getDirection():
		return self.mDirection
		
	def setMagazine(magazine):
		self.mMagazine = magazine
		
	def generateBullte():
		self.mMagazine.generateBullet()
		
		

if __name__ == '__main__':
	cannon = Cannon()
	
	import os
	os.system('pause')
