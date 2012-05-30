'''
Created on 2012-5-30

@author: Kid
'''

import ogre.renderer.OGRE as ogre

class Bullet:
    """Super class of all kinds of bullet"""
    
    def __init__(self, sceneNode, entity, sceneManager):
        
        # static properties
        # these properties are define by child class, 
        # depends on specific kind of bullets
        self.mMass = 0
        
        # dynamic properties
        # these properties are evaluate while render loop
        self.mVelocity = ogre.Vector3(0, 0, 0)
        self.mPosition = ogre.Vector3(0, 0, 0)
        self.mGravity = 0
        
        # render reference
        self.mSceneNode = sceneNode
        self.mEntity = entity
        self.mSceneManager = sceneManager
        
        # initial this bullet to un visible
        self.mSceneNode.setVisible(False)
    
    def fire(self, velocity, gravity = 10):
        """Fire a bullet.
        @param velocity: ogre.Vector3 type, decide the direction and speed of the initial velocity
        @param gravity: the gravity, default by 10 
        @note: This function should called by cannon.
        """
        self.mVelocity = velocity
        self.mGravity = gravity
        self.mSceneNode.setVisible(True)
        #TODO:...
        
    def clone(self):
        return Bullet(self.mSceneNode)
        