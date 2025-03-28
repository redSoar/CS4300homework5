Implmented Features:
- We have extended the parser(ScenegraphImporter) so that light can be added to any node. 
- We also made changes to SGNode so that any node can store multiple lights with functionallity to add light to a sepcific node. 
- We incorporated the lighting shaders that use per-fragment (Phong) shading.
- We wrote a function that traverses through all the nodes and gathers the lights.
- Scene graph's drawing is modified so that drawing a leaf should now pass material properties instead of simply a “color”.
- We've added suitable material properties to all parts of our scene 

Incomplete Features:
- Light is not properly implemented and does not appear in the scene causing the scene to be just pitch black. 
  - We would like to believe that we passed all necessary data to the shader for light, but we do not understand why we cannot get it to work
- Support for spotlight is not implemented at all
- Texture Mapping is also attempted but does not work. All texture mapping functionality has been COMMENTED OUT to allow the program to at least run
  - We attempted to implement support in the ScenegraphImporter for the "image" and "assign-texture" commands by introducing a texture field in LeafNode.
  - We then tried to add texture mapping functionality to visitLeafNode in the Renderer, and this caused our program to stop working
  - Further attempts such as adding blocks of code from the LightsAndTextures demo to the init() function in View.cpp are shown (but commented out), but none of them worked.


Work Split:
- We tried to collaborate in implementing the lighting; we got as far as extending the ScenegraphImporter and SGNode to support the new commands in the scenegraph files
- After that, we split up the work:
  - Jae-Min focused on implmenting the rest of the lighting
  - Akash focused on implementing the texturing