#ifndef _GLSCENEGRAPHTEXTRENDERER_H_
#define _GLSCENEGRAPHTEXTRENDERER_H_

#include "SGNodeVisitor.h"
#include "GroupNode.h"
#include "LeafNode.h"
#include "TransformNode.h"
#include "RotateTransform.h"
#include "ScaleTransform.h"
#include "TranslateTransform.h"
#include <ShaderProgram.h>
#include <ShaderLocationsVault.h>
#include "ObjectInstance.h"
#include <stack>
#include <iostream>
using namespace std;

namespace sgraph {
    /**
     * This visitor implements a text rendering that includes the tabs and hyphens used to show levels, and prints the names of each node as shown.
     */
    class GLScenegraphTextRenderer: public SGNodeVisitor {
        public:
        /**
         * @brief Construct a new GLScenegraphRenderer object
         * 
         * @param mv a reference to modelview stack that will be used while rendering
         * @param os the map of ObjectInstance objects
         * @param shaderLocations the shader locations for the program used to render
         */
        GLScenegraphTextRenderer() {
        }

        void visitGroupNode(GroupNode *groupNode) {
            vector<util::Light> lights;
            if(depth > 0) {
                cout << "- " << groupNode->getName() << endl;
            }
            else {
                cout << groupNode->getName() << endl;
            }
            if(groupNode->hasLight()){
                lights = groupNode->getLights();
                for(int i = 0; i < lights.size(); i++) {
                    cout << "lights " << i << endl;
                }
            }
            depth+= indentation;
            for (int i=0;i<groupNode->getChildren().size();i=i+1) {
                std::string stuff(depth, ' ');
                cout << stuff;
                groupNode->getChildren()[i]->accept(this);
            }
            depth-= indentation;
            
        }

        void visitLeafNode(LeafNode *leafNode) {
            vector<util::Light> lights;
            cout << "- " << leafNode->getName() << endl;
            if(leafNode->hasLight()){
                lights = leafNode->getLights();
                for(int i = 0; i < lights.size(); i++) {
                    cout << "lights " << i << endl;
                }
            }
        }

        void visitTransformNode(TransformNode * transformNode) {
            vector<util::Light> lights;
            cout << "- " << transformNode->getName() << endl;
            depth+= indentation;
            if (transformNode->getChildren().size()>0) {
                std::string stuff(depth, ' ');
                cout << stuff;
                if(transformNode->hasLight()){
                    lights = transformNode->getLights();
                    for(int i = 0; i < lights.size(); i++) {
                        cout << "lights " << i << endl;
                    }
                }
                transformNode->getChildren()[0]->accept(this);
            }
            depth-= indentation;
        }

        void visitScaleTransform(ScaleTransform *scaleNode) {
            visitTransformNode(scaleNode);
        }

        void visitTranslateTransform(TranslateTransform *translateNode) {
            visitTransformNode(translateNode);
        }

        void visitRotateTransform(RotateTransform *rotateNode) {
            visitTransformNode(rotateNode);
        }


        private:
        int depth = 0;
        int indentation = 3;
   };
}

#endif