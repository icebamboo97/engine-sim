#include "../include/engine_sim_application.h"

#include <iostream>

/**
 * @brief 主窗口程序入口函数。
 *
 * @param hInstance 当前实例的句柄。
 * @param hPrevInstance 先前实例的句柄（已弃用）。
 * @param lpCmdLine 命令行参数。
 * @param nCmdShow 窗口显示方式。
 * @return 程序退出代码。
 */
int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nCmdShow)
{
    (void)nCmdShow;
    (void)lpCmdLine;
    (void)hPrevInstance;

    EngineSimApplication application;
    application.initialize((void *)&hInstance, ysContextObject::DeviceAPI::DirectX11);
    application.run();
    application.destroy();

    return 0;
}
