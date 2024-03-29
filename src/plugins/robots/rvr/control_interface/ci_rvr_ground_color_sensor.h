/**
 * @file <argos3/plugins/robots/rvr/control_interface/rvr_ground_color_sensor.h>
 *
 * @brief This is an interface that represents the RVR ground color sensor.
 *
 * Its single color sensor, placed under the chassis, allows color detection.
 *
 * @author Raffaele Todesco - <raffaele.todesco@ulb.be>
 */

#ifndef CCI_RVR_GROUND_COLOR_SENSOR_H
#define CCI_RVR_GROUND_COLOR_SENSOR_H

namespace argos
{
    class CCI_RVRGroundColorSensor;
}

#include <argos3/core/control_interface/ci_sensor.h>
#include <argos3/core/utility/datatypes/color.h>

namespace argos
{
    class CCI_RVRGroundColorSensor : public CCI_Sensor
    {
    public:
        /**
         * Destructor
         */
        ~CCI_RVRGroundColorSensor() override = default;

        struct SReading
        {
            CColor Color;
            SReading() : Color(255, 255, 255) {}
            SReading(const SReading &s_reading) : Color(s_reading.Color) {}
            SReading(const CColor &c_color) : Color(c_color) {}

            void Reset() { Color.Set(255, 255, 255); }
        };

        /**
         * Returns the detected color
         */
        inline const SReading &GetReading() const
        {
            return m_sReading;
        }

#ifdef ARGOS_WITH_LUA
        /**
         *
         * @param pt_lua_state
         */
        virtual void CreateLuaState(lua_State *pt_lua_state);

        /**
         *
         * @param pt_lua_state
         */
        virtual void ReadingsToLuaState(lua_State *pt_lua_state);
#endif

    protected:
        /**
         * Color detected by the sensor
         */
        SReading m_sReading;
    };
} // namespace argos

#endif