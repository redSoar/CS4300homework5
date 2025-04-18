#ifndef __VIEW_H__
#define __VIEW_H__

#ifndef GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_NONE
#endif
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include <ShaderProgram.h>
#include "sgraph/SGNodeVisitor.h"
#include "ObjectInstance.h"
#include "PolygonMesh.h"
#include "VertexAttrib.h"
#include "TextureImage.h"
#include "Callbacks.h"
#include "sgraph/IScenegraph.h"
#include <glm/gtc/quaternion.hpp>

#include <stack>
using namespace std;


class View
{
    class LightLocation {
        public:
            int ambient,diffuse,specular,position;
            LightLocation()
            {
            ambient = diffuse = specular = position = -1;
            }
    
        };
    typedef enum {GLOBAL, CHOPPER, FPS} TypeOfCamera;

public:
    View();
    ~View();
    void init(Callbacks* callbacks,map<string,util::PolygonMesh<VertexAttrib>>& meshes);
    void display(sgraph::IScenegraph *scenegraph);
    bool shouldWindowClose();
    void closeWindow();
    void findMousePos(bool init);
    void resetTrackball();
    void decreasePropellorSpeed();
    void increasePropellorSpeed();
    void sidewaysRoll();
    void moveDroneForward();
    void moveDroneBackward();
    void moveDroneFace(int direction);
    void resetDronePosition();
    void changeCam(int cam);
    void shaderVariables();
    void findLights(sgraph::IScenegraph *scenegraph);
    void initLights();
    void setTextures(map<string,util::TextureImage> texts);

private: 

    GLFWwindow* window;
    util::ShaderProgram program;
    util::ShaderLocationsVault shaderLocations;
    map<string,util::ObjectInstance *> objects;
    glm::mat4 projection;
    stack<glm::mat4> modelview;
    vector<util::Light> lights;
    map<string,util::TextureImage> textures;
    //the shader locations for all lights, for convenience
    vector<LightLocation> lightLocations;
    //either name of object, or world, or view
    vector<string> lightCoordinateSystems;
    map<string,unsigned int> textureIds;
    sgraph::SGNodeVisitor *renderer;
    sgraph::SGNodeVisitor *textRenderer;
    int count;
    float prevpos[2];
    stack<glm::mat4> rotateAmount;
    glm::vec3 correctUp;
    float speed;
    float previousTime;
    bool rolling = false;
    float rollingTotal = 0.0f;
    float droneMovement = 0.0f;
    TypeOfCamera cameraMode;
    glm::vec3 droneOriginalPos = glm::vec3(0.0f, 0.0f, 0.0f);
    bool resetDrone = false;
    float droneTotalLR = 0.0f;
    float droneTotalUD = 0.0f;
    glm::quat totalQuaternion;
};

#endif