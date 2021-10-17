/*
#include <functional>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>

namespace gazebo
{
  class ModelPush : public ModelPlugin
  {
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr)
    {
      // Store the pointer to the model
      this->model = _parent;

      // Listen to the update event. This event is broadcast every
      // simulation iteration.
      this->updateConnection = event::Events::ConnectWorldUpdateBegin(
          std::bind(&ModelPush::OnUpdate, this));
    }

    // Called by the world update start event
    public: void OnUpdate()
    {
      // Apply a small linear velocity to the model.
      this->model->SetLinearVel(ignition::math::Vector3d(.3, 0, 0));
    }

    // Pointer to the model
    private: physics::ModelPtr model;

    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
    };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(ModelPush)
}
*/
#include "model_push_plugin.h"
#include <string>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>
#include <typeinfo>

namespace gazebo
{

void ModelPushPlugin::Load(physics::ModelPtr _parent, sdf::ElementPtr _sdf)
{
    ROS_INFO("Initializing model_push plugin.");

    // This sets gazebo msg publisher
    std::cout<<"help "<<_parent->GetName()<<std::endl;
    std::cout<<"help "<< _parent->GetWorld()->Name()<<std::endl;
    _parent->GetWorld()->PrintEntityTree();
    node = transport::NodePtr(new transport::Node());
    node->Init(_parent->GetWorld()->Name());
    physics::Link_V links = _parent->GetLinks();
    std::cout<<"PRINTING LINKS"<<std::endl;
    for(auto const& link : links)
      std::cout<<link->GetName()<<std::endl;
    ROS_INFO("parent get link of name is ");
    std::cout<<_parent->GetLink("link")<<std::endl;
    std::cout<<_parent->GetWorld()->Name()<<std::endl;
    std::cout<<"_parent is: "<<_parent<<std::endl;
    std::cout<<"---------------------MODEL BEING INITIALIZED---------------------"<<std::endl;
    modelPush = ModelPush("link", _parent);
    std::cout<<"---------------------MODEL INITIALIZED---------------------"<<std::endl;
    ROS_INFO("ModelPush.get_name(): ");
    std::cout<<modelPush.get_name()<<std::endl;
    ROS_INFO("ModelPush.get_LinkPtr(): ");
    std::cout<<typeid(modelPush.get_LinkPtr()).name()<<std::endl;
    ROS_INFO("ModelPush.get_Frame(): ");
    std::cout<<typeid(modelPush.get_Frame()).name()<<std::endl;

    // Set up Update to be called every simulation update
    // (which is frequently)
    updateConnection = event::Events::ConnectWorldUpdateBegin(
            boost::bind(&ModelPushPlugin::Update, this));

    ROS_INFO("ModelPush plugin successfully initialized.");
}

void ModelPushPlugin::Update()
{
    /*
     * Add link forces to the frame from each model_push.
     */
    modelPush.addLinkForce();
}

GZ_REGISTER_MODEL_PLUGIN(ModelPushPlugin)
}
