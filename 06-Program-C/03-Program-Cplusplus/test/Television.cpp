/*************************************************************************
	> File Name: Television.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月26日 星期二 12时29分31秒
 ************************************************************************/
/*
 * 请编写电视机类，电视机有开机和关机状态，有音量，有频道，提供音量操作的方法，频道操作的方法。由于电视机只能逐一调整频道，不能指定频道，增加遥控类，遥控类除了拥有电视机已有的功能，再增加根据输入调台功能。
 *
 * 提示：遥控器可作为电视机类的友元类。
 *
 */
#include<iostream>
using namespace std;

class Remote;

class Television {
	friend class Remote;
public:
	enum { On, Off }; // 电视状态
	enum { minVol, maxVol = 100 }; // 音量从 0 到 100
	enum { minChannel = 1, maxChannel = 255 };  // 频道从 1 到 255
	Television() {
		mState = Off;
		mVolume = minVol;
		mChannel = minChannel;
	}

	// 打开电视机
	void OnOff(){
		this->mState = (this->mState = On ? Off : On);
	}

	// 调高音量
	void VolumeUp(){
		if (this->mVolume >= maxVol)
			return;
		this->mVolume++;
	}

	// 调低音量
	void VolumeDown(){
		if (this->mVolume <= minVol)
			return;
		this->mVolume--;
	}

	// 更换电视频道
	void ChannelUp(){
		if (this->mChannel >= maxChannel)
			return;
		this->mChannel++;
	}

	void ChannelDown(){
		if (this->mChannel <= minChannel)
			return;
		this->mChannel--;
	}

	// 展示当前电视机状态信息
	void ShowTeleState(){
		cout << "开机状态：" << (mState == On ? "已开机" : "已关机") << endl;
		if (mState == On){
			cout << "当前音量：" << mVolume << endl;
			cout << "当前频道：" << mChannel << endl;
		}
		cout << "------------------" << endl;
	}

private:
	int mState;	// 电视状态，开机还是关机
	int mVolume;  // 电视音量
	int mChannel;  // 电视频道
};

// 电视机调台只能一个一个调，遥控可以指定频道
// 电视遥控器
class Remote{
public:
	Remote(Television *television){
		pTelevision = television;
	}
public:
	void OnOff(){
		pTelevision->OnOff();
	}

	// 调高音量
	void VolumeUp(){
		pTelevision->VolumeUp();
	}

	// 调低音量
	void VolumeDown(){
		pTelevision->VolumeDown();
	}

	// 跟换电视频道
	void ChannelUp(){
		pTelevision->ChannelUp();
	}

	void ChannelDown(){
		pTelevision->ChannelDown();
	}

	// 设置频道 遥控新增功能
	void SetChannel(int channel){
		if (channel < Television::minChannel || channel > Television::maxChannel)
			return;
		pTelevision->mChannel = channel;
	}

	// 显示电视机当前信息
	void ShowTeleState(){
		pTelevision->ShowTeleState();
	}

private:
	Television *pTelevision;
};

// 直接操作电视
void test01()
{
	Television television;
	television.ShowTeleState();
	television.OnOff();		// 开机
	television.VolumeUp();	// 增加音量 +1
	television.VolumeUp();	// 增加音量 +1
	television.VolumeUp();	// 增加音量 +1
	television.VolumeUp();	// 增加音量 +1
	television.ChannelUp(); // 频道 +1
	television.ChannelUp(); // 频道 +1
	television.ShowTeleState();
}

// 通过遥控器操作电视
void test02()
{
	// 创建电视
	Television television;
	// 创建遥控
	Remote remote(&television);
	remote.ShowTeleState();
	remote.OnOff();
	remote.ChannelUp();
	remote.ChannelUp();
	remote.ChannelUp();
	remote.VolumeUp();
	remote.VolumeUp();
	remote.VolumeUp();
	remote.VolumeUp();
	remote.ShowTeleState();
	remote.SetChannel(100);
	remote.ShowTeleState();
}

int main()
{
	//test01();
	test02();

	return 0;
}
