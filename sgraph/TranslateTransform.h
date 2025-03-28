#ifndef _TRANSLATETRANSFORM_H_
#define _TRANSLATETRANSFORM_H_


#include "TransformNode.h"
#include <glm/gtc/matrix_transform.hpp>

namespace sgraph {
    /**
     * This node represents a specific kind of transform: translation
     * 
     */
    class TranslateTransform: public TransformNode {
        protected:
            float tx,ty,tz;

        ParentSGNode *copyNode() {
            return new TranslateTransform(tx,ty,tz,name,scenegraph);
        }

        public:
            TranslateTransform(float tx,float ty,float tz,const string& name,sgraph::IScenegraph *graph) 
                :TransformNode(name,graph) {
                    this->tx = tx;
                    this->ty = ty;
                    this->tz = tz;
                    glm::mat4 transform = glm::translate(glm::mat4(1.0),glm::vec3(tx,ty,tz));
                    setTransform(transform);
            }

            
            /**
             * Visit this node.
             * 
             */
            void accept(SGNodeVisitor* visitor) {
                visitor->visitTranslateTransform(this);
            }

            glm::vec3 getTranslate() {
            return glm::vec3(tx,ty,tz);
            }

            // Set this translate tranformation to given translate
            void setTranslate(glm::vec3 newTranslate) {
                this->tx = newTranslate.x;
                this->ty = newTranslate.y;
                this->tz = newTranslate.z;
                glm::mat4 transform = glm::translate(glm::mat4(1.0), glm::vec3(tx,ty,tz));
                setTransform(transform);
            }

            // Add given translate to this translate
            void moveForwardBackward(glm::vec3 forwardVector){
                this->tx += forwardVector.x;
                this->ty += forwardVector.y;
                this->tz += forwardVector.z;
                glm::mat4 transform = glm::translate(glm::mat4(1.0),glm::vec3(tx,ty,tz));
                setTransform(transform);
            }

    };
}

#endif