'''
Created on 2012-5-29

@author: Kid
'''

from Stage import *

class StageManager:
    """Provide management on stages, include initialize, 
    release, run and jump.
    """
    
    def __init__(self, sceneManager):
        self.mSceneManager = sceneManager
        self.mStages = {}
        self.mCurrentStage = None
        self.mIsStageInitialized = False
        
    def addStage(self, stage, stageId):
        """Add a stage to stage manager.
        @param stage: the stage you want to add
        @param stageId: the enum id that represent the stage,@see: StageJumpEnum
        """
        self.mStages[stageId] = stage
         
    def setStartStage(self, stageId):
        """Define which stage will be the entry.
        @param stageId: the enum id that represent the stage"""
        self.mCurrentStage = self.mStages[stageId]
        
    def runStages(self):
        """Run the stages"""
        # verify start stage
        if (self.mCurrentStage == None):
            raise Exception, \
                "None current stage, you must first call setStartStage()"
        # ini
        if (not self.mCurrentStage.isInitialized()):
            self.mCurrentStage.initialize()
        # run
        if (not self.mCurrentStage.run()):
            # jump and release
            nextStage = self.mCurrentStage.getNextStage()
            self.mCurrentStage.release()
            self.mCurrentStage = self.mStages[nextStage]
            
        
        
        
    