#ifndef ATG_ENGINE_SIM_RIGHT_GAUGE_CLUSTER_H
#define ATG_ENGINE_SIM_RIGHT_GAUGE_CLUSTER_H

#include "ui_element.h"

#include "engine.h"
#include "simulator.h"
#include "gauge.h"
#include "firing_order_display.h"
#include "labeled_gauge.h"
#include "throttle_display.h"
#include "afr_cluster.h"
#include "fuel_cluster.h"

/**
 * @class RightGaugeCluster
 * @brief 表示右侧仪表盘的UI元素。
 * 
 * RightGaugeCluster类是UiElement的子类，提供了渲染和更新与引擎模拟相关的各种仪表和显示器的功能。它包括转速表、速度表、进气歧管真空表、进气流量表、容积效率表、燃油集群、油门显示器、AFR集群和燃烧室状态显示器。
 * 
 * RightGaugeCluster类还提供了设置引擎、设置单位和获取带单位的进气歧管压力的方法。它具有用于模拟目的的Simulator成员变量。
 * 
 * 受保护的成员包括渲染转速表和速度表的方法，以及用于获取RPM、红线、速度和进气歧管压力的私有成员。
 */
class RightGaugeCluster : public UiElement {
    public:
        RightGaugeCluster();
        virtual ~RightGaugeCluster();

        virtual void initialize(EngineSimApplication *app);
        virtual void destroy();

        virtual void update(float dt);
        virtual void render();

        void setEngine(Engine *engine);
        void setUnits();
        double getManifoldPressureWithUnits(double ambientPressure);

        Simulator *m_simulator;

    private:
        double getRpm() const;
        double getRedline() const;
        double getSpeed() const;
        double getManifoldPressure() const;

    protected:
        Engine *m_engine;

        void renderTachSpeedCluster(const Bounds &bounds);
        void renderFuelAirCluster(const Bounds &bounds);

        LabeledGauge *m_tachometer;
        LabeledGauge *m_speedometer;
        LabeledGauge *m_manifoldVacuumGauge;
        LabeledGauge *m_intakeCfmGauge;
        LabeledGauge *m_volumetricEffGauge;
        FuelCluster *m_fuelCluster;
        ThrottleDisplay *m_throttleDisplay;
        AfrCluster *m_afrCluster;
        FiringOrderDisplay *m_combusionChamberStatus;
        std::string m_speedUnits;
        std::string m_pressureUnits;
        bool m_isAbsolute;
};

#endif /* ATG_ENGINE_SIM_GAUGE_CLUSTER_H */
