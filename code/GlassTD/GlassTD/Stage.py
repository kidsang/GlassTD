'''
Created on 2012-5-29

@author: Kid
'''

from StageJumpEnum import StageJumpEnum

class Stage:
    """A game stage define the scene content, resources and logics.
    This is the super class of all other stage"""
    
    def __init__(self, sceneManager):
        self.mSceneManager = sceneManager
        self.mIsInitialized = False
    
    def initialize(self):    
        pass
       
    def release(self):
        pass
       
    def run(self):
        pass
       
    def onEvent(self):
        pass
       
    def getNextStage(self):
        pass
    
    def isInitialized(self):
        return self.mIsInitialized
    
