class Direction:
	'''a vector, represents direction'''
	
	def __init__(self, x = 0.0, y = 0.0, z = 0.0):
		self.mX = x
		self.mY = y
		self.mZ = z

		
if __name__ == '__main__':
	d = Direction()
	print d.mX, d.mY, d.mZ

	import os
	os.system('pause')