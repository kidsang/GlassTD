'''
Created on 2012-5-29

@author: Kid
'''

from StageJumpEnum import *

class Stage:
    """A game stage define the scene content, resources and logics.
    This is the super class of all other stage"""
    
    def __init__(self, sceneManager):
        self.mSceneManager = sceneManager
        self.mIsInitialized = False
    
    def initialize(self):
        """You should create you scene in this function"""
        pass
       
    def release(self):
        """Called when jump to another stage.
        Release all resources.
        """
        pass
       
    def run(self):
        """Run the stage.
        @return: True means continue to run this stage.
                 False means need to change another stage.
        """
        pass
       
    def onEvent(self):
        pass
       
    def getNextStage(self):
        """Get the stage id of next stage.
        @return: The id of next stage.
        """
        pass
    
    def isInitialized(self):
        """Return if the stage is ready to run."""
        return self.mIsInitialized
    
