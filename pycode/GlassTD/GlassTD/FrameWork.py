# This code is in the Public Domain
# -----------------------------------------------------------------------------
# This source file is part of Python-Ogre
# For the latest info, see http://python-ogre.org/
#
# It is likely based on original code from OGRE and/or PyOgre
# For the latest info, see http://www.ogre3d.org/
#
# You may use this sample code for anything you like, it is not covered by the
# LGPL.
# -----------------------------------------------------------------------------

#
# 29 July 2008: Ensured that resources.cfg and plugins.cfg can exist in the parent directory
#
import sys
import os
import os.path

import ogre.renderer.OGRE as ogre
#import ogre.io.OIS as OIS
###import OgreRefApp
from FrameListener import *
from StageManager import *

def getPluginPath():
    """ Return the absolute path to a valid plugins.cfg file.
    look in the current directory for plugins.cfg followed by plugins.cfg.nt|linux|mac
    If not found look one directory up
    """ 
    
    paths = [os.path.join(os.getcwd(), 'plugins.cfg'),
             os.path.join(os.getcwd(), '..', 'plugins.cfg'),
             ]
    if os.sys.platform == 'darwin':
        paths.insert(1, os.path.join(os.getcwd(), 'plugins.cfg.mac'))
        paths.append(os.path.join(os.getcwd(), '..', 'plugins.cfg.mac'))
    else:
        paths.insert(1, os.path.join(os.getcwd(), 'plugins.cfg.' + os.name))
        paths.append(os.path.join(os.getcwd(), '..', 'plugins.cfg.' + os.name))
        
    for path in paths:
        if os.path.exists(path):
            return path

    sys.stderr.write("\n"
        "** Warning: Unable to locate a suitable plugins.cfg file.\n"
        "** Warning: Please check your ogre installation and copy a\n"
        "** Warning: working plugins.cfg file to the current directory.\n\n")
    raise ogre.Exception(0, "can't locate a suitable 'plugins' file", "")

# def isUnitTest():
#     """Looks for a magic file to determine if we want to do a unittest"""
#     paths = [os.path.join(os.getcwd(), 'unittest.now'),
#             os.path.join(os.getcwd(), '..','unittest.now')]
#     for path in paths:
#         if os.path.exists(path):
#             return True
#     return False
 
'''def isUnitTest():
    """ use an environment variable to define that we need to do unittesting"""
    env = os.environ
    if env.has_key ("PythonOgreUnitTestPath"):
        return True
    return False
    
def UnitTest_Duration():
    return 5

def UnitTest_Screenshot():
    if isUnitTest():
        env = os.environ
        path = env["PythonOgreUnitTestPath"]
        parentpath = os.getcwd().split(os.path.sep)[-1] # get the last part of the parent directory
        filename = parentpath + '.' + sys.modules['__main__'].__file__.split('.')[0] # file name is parent.demo.xx
        path = os.path.join (path, filename)
        return path
    else:
        return "test"'''
               
class Application(object):
    "This class is the base for an Ogre application."
    debugText = ""

    def __init__(self):
        self.frameListener = None
        self.root = None
        self.camera = None
        self.renderWindow = None
        self.sceneManager = None
        self.world = None
        # StageManager
        self.mStageManager = None
        #self.unittest = isUnitTest()

    def __del__(self):
        "Clear variables, this should not actually be needed."
        del self.camera
        del self.sceneManager
        del self.frameListener
        if self.world:
            del self.world
        del self.root
        del self.renderWindow

    def go(self):
        "Starts the rendering loop."
        if not self._setUp():
            return
        if self._isPsycoEnabled():
            self._activatePsyco()
        self.root.startRendering()
        
    def goOneFrame(self):
        "Starts the rendering loop. Show how to use the renderOneFrame Method"
        if not self._setUp():
            return
        if self._isPsycoEnabled():
            self._activatePsyco()
    
        self.root.getRenderSystem()._initRenderTargets()
        while True:
            ogre.WindowEventUtilities().messagePump()
            if not self.root.renderOneFrame():
                break

    def _setUp(self):
        """This sets up the ogre application, and returns false if the user
        hits "cancel" in the dialog box."""
        
        pluginFile = getPluginPath()  ## option here to switch to manually loading file if it doesn't exist
        '''if self.unittest:
            if os.path.isfile('ogre.cfg'):
                self.root = ogre.Root(pluginFile)
            else:
                self.root = ogre.Root(pluginFile, '../ogre.cfg')
        else:'''
        self.root = ogre.Root(pluginFile)
        self.root.setFrameSmoothingPeriod (5.0)

        self._setUpResources()
        if not self._configure():
            return False
        
        self._chooseSceneManager()
        self._createWorld()
        self._createCamera()
        self._createViewports()

        ogre.TextureManager.getSingleton().setDefaultNumMipmaps (5)

        self._createResourceListener()
        self._loadResources()

        self._createScene()
        self._createFrameListener()
        
        #Stage Manager
        self.mStageManager = StageManager(self.sceneManager)
        
        return True

    def _setUpResources(self):
        """This sets up Ogre's resources, which are required to be in
        resources.cfg."""
        config = ogre.ConfigFile()
        try:
            config.load('resources.cfg') 
        except ogre.OgreFileNotFoundException:
            try:
                config.load('../resources.cfg')
            except:
                raise                
        except:
            raise               
                    
        seci = config.getSectionIterator()
        while seci.hasMoreElements():
            SectionName = seci.peekNextKey()
            Section = seci.getNext()
            for item in Section:
                ogre.ResourceGroupManager.getSingleton().\
                    addResourceLocation(item.value, item.key, SectionName)
                    
    def _createResourceListener(self):
        """This method is here if you want to add a resource listener to check
        the status of resources loading."""
        pass
        
    def _createWorld (self):
        """ this should be overridden when supporting the OgreRefApp framework.  Also note you 
        will have to override __createCamera"""
        pass

    def _loadResources(self):
        """This loads all initial resources.  Redefine this if you do not want
        to load all resources at startup."""
        ogre.ResourceGroupManager.getSingleton().initialiseAllResourceGroups()

    def _configure(self):
        """This shows the config dialog and creates the renderWindow."""
        #if not self.unittest:   # we show this if not doing a unittest
        carryOn = self.root.showConfigDialog() 
        #else:
        #    carryOn = self.root.restoreConfig()            
        if carryOn:
            windowTitle = "Glass TD!"
            self.renderWindow = self.root.initialise(True, windowTitle)
        return carryOn

    def _chooseSceneManager(self):
        """Chooses a default SceneManager."""
        #typedef uint16 SceneTypeMask;
        #md=ogre.SceneManagerMetaData()
        #md.sceneTypeMask=ogre.ST_GENERIC
        #print dir(self.root)    
        self.sceneManager = self.root.createSceneManager(ogre.ST_GENERIC, "ExampleSMInstance")

    def _createCamera(self):
        """Creates the camera."""        
        self.camera = self.sceneManager.createCamera('PlayerCam')
        self.camera.setPosition(ogre.Vector3(0, 0, 500))
        self.camera.lookAt(ogre.Vector3(0, 0, -300))
        self.camera.NearClipDistance = 5

    def _createViewports(self):
        """Creates the Viewport."""
        ## We want a single sampleframework so this work around is to support OgreRefApp Framework
        ## if using the RefApp camera is based upon World etc etc
        try:    
            self.viewport = self.renderWindow.addViewport(self.camera.getRealCamera())
        except AttributeError:
            self.viewport = self.renderWindow.addViewport(self.camera)
        self.viewport.BackgroundColour = ogre.ColourValue(0, 0, 0)
        
    def _createScene(self):
        """Creates the scene.  Override this with initial scene contents."""
        sceneManager = self.sceneManager 
        sceneManager.ambientLight = ogre.ColourValue (1, 1, 1) 
 
        ent1 = sceneManager.createEntity ("Robot", "robot.mesh") 
        #mAnimationState = ent1.getAnimationState("Walk")
        #mAnimationState.setLoop(True)
        #mAnimationState.setEnabled(True)
        node1 = sceneManager.getRootSceneNode().createChildSceneNode("RobotNode") 
        node1.attachObject(ent1) 
        node1.attachObject(self.camera)
        #self.camera.setPosition(-100, 100, 0)
        #self.camera.lookAt(10000, 0, 0)
        
        

    def _createFrameListener(self):
        """Creates the FrameListener."""
        #,self.frameListener, self.frameListener.Mouse 
        self.frameListener = FrameListener(self)
        self.frameListener.showDebugOverlay(True)
        self.root.addFrameListener(self.frameListener)

    def _isPsycoEnabled(self):
        """Override this function and return True to turn on Psyco"""
        return False

    def _activatePsyco(self):        
        """Import Psyco if available"""
        try:
            import psyco
            psyco.full()
        except ImportError:
            pass

if __name__ == '__main__': 
    import exceptions 
    try: 
        application = Application() 
        application.go() 
    except ogre.OgreException, e: 
        print e
