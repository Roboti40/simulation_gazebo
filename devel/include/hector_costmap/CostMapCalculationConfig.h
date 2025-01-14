//#line 2 "/opt/ros/noetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
//
// File autogenerated for the hector_costmap package
// by the dynamic_reconfigure package.
// Please do not edit.
//
// ********************************************************/

#ifndef __hector_costmap__COSTMAPCALCULATIONCONFIG_H__
#define __hector_costmap__COSTMAPCALCULATIONCONFIG_H__

#if __cplusplus >= 201103L
#define DYNAMIC_RECONFIGURE_FINAL final
#else
#define DYNAMIC_RECONFIGURE_FINAL
#endif

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace hector_costmap
{
  class CostMapCalculationConfigStatics;

  class CostMapCalculationConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l,
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      virtual ~AbstractParamDescription() = default;

      virtual void clamp(CostMapCalculationConfig &config, const CostMapCalculationConfig &max, const CostMapCalculationConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const CostMapCalculationConfig &config1, const CostMapCalculationConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, CostMapCalculationConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const CostMapCalculationConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, CostMapCalculationConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const CostMapCalculationConfig &config) const = 0;
      virtual void getValue(const CostMapCalculationConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template <class T>
    class ParamDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level,
          std::string a_description, std::string a_edit_method, T CostMapCalculationConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T CostMapCalculationConfig::* field;

      virtual void clamp(CostMapCalculationConfig &config, const CostMapCalculationConfig &max, const CostMapCalculationConfig &min) const override
      {
        if (config.*field > max.*field)
          config.*field = max.*field;

        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const CostMapCalculationConfig &config1, const CostMapCalculationConfig &config2) const override
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, CostMapCalculationConfig &config) const override
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const CostMapCalculationConfig &config) const override
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, CostMapCalculationConfig &config) const override
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const CostMapCalculationConfig &config) const override
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const CostMapCalculationConfig &config, boost::any &val) const override
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      virtual ~AbstractGroupDescription() = default;

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, CostMapCalculationConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template<class T, class PT>
    class GroupDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const override
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const override
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, CostMapCalculationConfig &top) const override
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const override
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T PT::* field;
      std::vector<CostMapCalculationConfig::AbstractGroupDescriptionConstPtr> groups;
    };

class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(CostMapCalculationConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("max_delta_elevation"==(*_i)->name){max_delta_elevation = boost::any_cast<double>(val);}
        if("use_grid_map"==(*_i)->name){use_grid_map = boost::any_cast<bool>(val);}
        if("use_elevation_map"==(*_i)->name){use_elevation_map = boost::any_cast<bool>(val);}
        if("allow_kinect_to_clear_occupied_cells"==(*_i)->name){allow_kinect_to_clear_occupied_cells = boost::any_cast<bool>(val);}
        if("allow_elevation_map_to_clear_occupied_cells"==(*_i)->name){allow_elevation_map_to_clear_occupied_cells = boost::any_cast<bool>(val);}
        if("max_clear_size"==(*_i)->name){max_clear_size = boost::any_cast<int>(val);}
        if("slize_min_height"==(*_i)->name){slize_min_height = boost::any_cast<double>(val);}
        if("slize_max_height"==(*_i)->name){slize_max_height = boost::any_cast<double>(val);}
        if("update_radius_world"==(*_i)->name){update_radius_world = boost::any_cast<double>(val);}
      }
    }

    double max_delta_elevation;
bool use_grid_map;
bool use_elevation_map;
bool allow_kinect_to_clear_occupied_cells;
bool allow_elevation_map_to_clear_occupied_cells;
int max_clear_size;
double slize_min_height;
double slize_max_height;
double update_radius_world;

    bool state;
    std::string name;

    
}groups;



//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double max_delta_elevation;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool use_grid_map;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool use_elevation_map;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool allow_kinect_to_clear_occupied_cells;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool allow_elevation_map_to_clear_occupied_cells;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int max_clear_size;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double slize_min_height;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double slize_max_height;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double update_radius_world;
//#line 231 "/opt/ros/noetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("CostMapCalculationConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }

    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }

    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const CostMapCalculationConfig &__max__ = __getMax__();
      const CostMapCalculationConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const CostMapCalculationConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }

    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const CostMapCalculationConfig &__getDefault__();
    static const CostMapCalculationConfig &__getMax__();
    static const CostMapCalculationConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();

  private:
    static const CostMapCalculationConfigStatics *__get_statics__();
  };

  template <> // Max and min are ignored for strings.
  inline void CostMapCalculationConfig::ParamDescription<std::string>::clamp(CostMapCalculationConfig &config, const CostMapCalculationConfig &max, const CostMapCalculationConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class CostMapCalculationConfigStatics
  {
    friend class CostMapCalculationConfig;

    CostMapCalculationConfigStatics()
    {
CostMapCalculationConfig::GroupDescription<CostMapCalculationConfig::DEFAULT, CostMapCalculationConfig> Default("Default", "", 0, 0, true, &CostMapCalculationConfig::groups);
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.max_delta_elevation = 0.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.max_delta_elevation = 0.15;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.max_delta_elevation = 0.1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(CostMapCalculationConfig::AbstractParamDescriptionConstPtr(new CostMapCalculationConfig::ParamDescription<double>("max_delta_elevation", "double", 0, "Max traversable hight", "", &CostMapCalculationConfig::max_delta_elevation)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(CostMapCalculationConfig::AbstractParamDescriptionConstPtr(new CostMapCalculationConfig::ParamDescription<double>("max_delta_elevation", "double", 0, "Max traversable hight", "", &CostMapCalculationConfig::max_delta_elevation)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.use_grid_map = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.use_grid_map = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.use_grid_map = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(CostMapCalculationConfig::AbstractParamDescriptionConstPtr(new CostMapCalculationConfig::ParamDescription<bool>("use_grid_map", "bool", 0, "Use grid map", "", &CostMapCalculationConfig::use_grid_map)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(CostMapCalculationConfig::AbstractParamDescriptionConstPtr(new CostMapCalculationConfig::ParamDescription<bool>("use_grid_map", "bool", 0, "Use grid map", "", &CostMapCalculationConfig::use_grid_map)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.use_elevation_map = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.use_elevation_map = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.use_elevation_map = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(CostMapCalculationConfig::AbstractParamDescriptionConstPtr(new CostMapCalculationConfig::ParamDescription<bool>("use_elevation_map", "bool", 0, "Use elevation map", "", &CostMapCalculationConfig::use_elevation_map)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(CostMapCalculationConfig::AbstractParamDescriptionConstPtr(new CostMapCalculationConfig::ParamDescription<bool>("use_elevation_map", "bool", 0, "Use elevation map", "", &CostMapCalculationConfig::use_elevation_map)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.allow_kinect_to_clear_occupied_cells = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.allow_kinect_to_clear_occupied_cells = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.allow_kinect_to_clear_occupied_cells = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(CostMapCalculationConfig::AbstractParamDescriptionConstPtr(new CostMapCalculationConfig::ParamDescription<bool>("allow_kinect_to_clear_occupied_cells", "bool", 0, "Allow kinect to clear occupied cells", "", &CostMapCalculationConfig::allow_kinect_to_clear_occupied_cells)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(CostMapCalculationConfig::AbstractParamDescriptionConstPtr(new CostMapCalculationConfig::ParamDescription<bool>("allow_kinect_to_clear_occupied_cells", "bool", 0, "Allow kinect to clear occupied cells", "", &CostMapCalculationConfig::allow_kinect_to_clear_occupied_cells)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.allow_elevation_map_to_clear_occupied_cells = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.allow_elevation_map_to_clear_occupied_cells = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.allow_elevation_map_to_clear_occupied_cells = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(CostMapCalculationConfig::AbstractParamDescriptionConstPtr(new CostMapCalculationConfig::ParamDescription<bool>("allow_elevation_map_to_clear_occupied_cells", "bool", 0, "Allows elevation map to clear occupied cells", "", &CostMapCalculationConfig::allow_elevation_map_to_clear_occupied_cells)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(CostMapCalculationConfig::AbstractParamDescriptionConstPtr(new CostMapCalculationConfig::ParamDescription<bool>("allow_elevation_map_to_clear_occupied_cells", "bool", 0, "Allows elevation map to clear occupied cells", "", &CostMapCalculationConfig::allow_elevation_map_to_clear_occupied_cells)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.max_clear_size = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.max_clear_size = 9;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.max_clear_size = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(CostMapCalculationConfig::AbstractParamDescriptionConstPtr(new CostMapCalculationConfig::ParamDescription<int>("max_clear_size", "int", 0, "max clear size", "", &CostMapCalculationConfig::max_clear_size)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(CostMapCalculationConfig::AbstractParamDescriptionConstPtr(new CostMapCalculationConfig::ParamDescription<int>("max_clear_size", "int", 0, "max clear size", "", &CostMapCalculationConfig::max_clear_size)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.slize_min_height = -2.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.slize_min_height = 2.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.slize_min_height = 0.3;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(CostMapCalculationConfig::AbstractParamDescriptionConstPtr(new CostMapCalculationConfig::ParamDescription<double>("slize_min_height", "double", 0, "cloud slice width min height", "", &CostMapCalculationConfig::slize_min_height)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(CostMapCalculationConfig::AbstractParamDescriptionConstPtr(new CostMapCalculationConfig::ParamDescription<double>("slize_min_height", "double", 0, "cloud slice width min height", "", &CostMapCalculationConfig::slize_min_height)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.slize_max_height = -2.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.slize_max_height = 2.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.slize_max_height = 0.4;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(CostMapCalculationConfig::AbstractParamDescriptionConstPtr(new CostMapCalculationConfig::ParamDescription<double>("slize_max_height", "double", 0, "cloud slice width max height", "", &CostMapCalculationConfig::slize_max_height)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(CostMapCalculationConfig::AbstractParamDescriptionConstPtr(new CostMapCalculationConfig::ParamDescription<double>("slize_max_height", "double", 0, "cloud slice width max height", "", &CostMapCalculationConfig::slize_max_height)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.update_radius_world = 0.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.update_radius_world = 6.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.update_radius_world = 5.0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(CostMapCalculationConfig::AbstractParamDescriptionConstPtr(new CostMapCalculationConfig::ParamDescription<double>("update_radius_world", "double", 0, "window size for generating cost map around robot", "", &CostMapCalculationConfig::update_radius_world)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(CostMapCalculationConfig::AbstractParamDescriptionConstPtr(new CostMapCalculationConfig::ParamDescription<double>("update_radius_world", "double", 0, "window size for generating cost map around robot", "", &CostMapCalculationConfig::update_radius_world)));
//#line 246 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 246 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(CostMapCalculationConfig::AbstractGroupDescriptionConstPtr(new CostMapCalculationConfig::GroupDescription<CostMapCalculationConfig::DEFAULT, CostMapCalculationConfig>(Default)));
//#line 369 "/opt/ros/noetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<CostMapCalculationConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__);
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__);
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__);
    }
    std::vector<CostMapCalculationConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<CostMapCalculationConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    CostMapCalculationConfig __max__;
    CostMapCalculationConfig __min__;
    CostMapCalculationConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const CostMapCalculationConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static CostMapCalculationConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &CostMapCalculationConfig::__getDescriptionMessage__()
  {
    return __get_statics__()->__description_message__;
  }

  inline const CostMapCalculationConfig &CostMapCalculationConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }

  inline const CostMapCalculationConfig &CostMapCalculationConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }

  inline const CostMapCalculationConfig &CostMapCalculationConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }

  inline const std::vector<CostMapCalculationConfig::AbstractParamDescriptionConstPtr> &CostMapCalculationConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<CostMapCalculationConfig::AbstractGroupDescriptionConstPtr> &CostMapCalculationConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const CostMapCalculationConfigStatics *CostMapCalculationConfig::__get_statics__()
  {
    const static CostMapCalculationConfigStatics *statics;

    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = CostMapCalculationConfigStatics::get_instance();

    return statics;
  }


}

#undef DYNAMIC_RECONFIGURE_FINAL

#endif // __COSTMAPCALCULATIONRECONFIGURATOR_H__
