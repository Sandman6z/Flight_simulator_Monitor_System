# Simulator-Monitor-System
For SFATC

IoT文件夹下的为不同下位机采集端的程序；

PCB文件夹为两种不同的采集PCB，其中
	ESP12F_DHTxx：	可为温湿度DHT22和液压机单温度DS18B20做主板
	ESP12F_infrared：接人体热释感应模块，无人区(如模拟机正下方)有人检测用，模块使用前需调试距离和报警时间等

值班室屏幕为旧构想，若在值班室安装屏幕实时监控，可考虑HDMI驱动部分，或成熟的树莓派体系。