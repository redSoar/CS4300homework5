#ifndef _LEAFNODE_H_
#define _LEAFNODE_H_

#include "AbstractSGNode.h"
#include "SGNodeVisitor.h"
#include "ImageLoader.h"
#include "PPMImageLoader.h"
#include "Material.h"
#include "glm/glm.hpp"
#include <map>
#include <stack>
#include <string>
using namespace std;

namespace sgraph
{

/**
 * This node represents the leaf of a scene graph. It is the only type of node that has
 * actual geometry to render.
 * \author Amit Shesh
 */
class LeafNode: public AbstractSGNode
{
    /**
     * The name of the object instance that this leaf contains. All object instances are stored
     * in the scene graph itself, so that an instance can be reused in several leaves
     */
protected:
    string objInstanceName;
    /**
     * The material associated with the object instance at this leaf
     */
    util::Material material;
    //util::TextureImage texture;

public:
    LeafNode(const string& instanceOf,util::Material& material,const string& name,sgraph::IScenegraph *graph)
        :AbstractSGNode(name,graph) {
        this->objInstanceName = instanceOf;
        this->material = material;
        //this->texture = baseTexture();
    }

    LeafNode(const string& instanceOf,const string& name,sgraph::IScenegraph *graph)
        :AbstractSGNode(name,graph) {
        this->objInstanceName = instanceOf;
        //this->texture = baseTexture();
    }
	
	~LeafNode(){}



    /*
	 *Set the material of each vertex in this object
	 */
    void setMaterial(const util::Material& mat) {
        material = mat;
    }

    // util::TextureImage baseTexture() {
    //     ImageLoader *loader = new PPMImageLoader();
    //     loader->load("textures/white.ppm");
    //     util::TextureImage *image = new util::TextureImage(loader->getPixels(), loader->getWidth(), loader->getHeight(), name);
    //     return *image;
    // }

    // void setTexture(util::TextureImage& tex) {
    //     texture = tex;
    // }

    // util::TextureImage getTexture() {
    //     return texture;
    // }

    /*
     * gets the material
     */
    util::Material getMaterial()
    {
        return material;
    }

    /**
     * Get the name of the instance this leaf contains
     * 
     * @return string 
     */
    string getInstanceOf() {
        return this->objInstanceName;
    }

    /**
     * Get a copy of this node.
     * 
     * @return SGNode* 
     */

    SGNode *clone() {
        LeafNode *newclone = new LeafNode(this->objInstanceName,material,name,scenegraph);
        return newclone;
    }

    /**
     * Visit this node.
     * 
     */
    void accept(SGNodeVisitor* visitor) {
      visitor->visitLeafNode(this);
    }
};
}
#endif
