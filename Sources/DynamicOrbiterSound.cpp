#include <OrbiterSoundSDK50.h>
#include <map>
#include "DLL\DynamicOS_Interface.h"

#ifdef _DEBUG
#define DLL_PATH "Modules\\DynamicOrbiterSoundD.dll"
#else
#define DLL_PATH "Modules\\DynamicOrbiterSound.dll"
#endif

typedef DynamicOS_DLL* (*CreateInstance)();
typedef void (*DestroyInstance)(DynamicOS_DLL*);

struct Data
{
	HINSTANCE orbDLL = nullptr;
	DynamicOS_DLL* orbSound = nullptr;
} defaultData;

std::map<int, Data> dataMap;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_DETACH:
	{
		for (const auto& data : dataMap)
		{
			DestroyInstance destroyInstance = reinterpret_cast<DestroyInstance>(GetProcAddress(data.second.orbDLL, "DestroyInstance"));

			if (destroyInstance) destroyInstance(data.second.orbSound);

			FreeLibrary(data.second.orbDLL);
		}

		dataMap.clear();
		break;
	}

	default:
		break;
	}

	return TRUE;
}

int ConnectToOrbiterSoundDLL(OBJHANDLE Obj)
{
	DynamicOS_DLL* orbSound;
	HINSTANCE orbDLL = LoadLibraryA(DLL_PATH);

	if (orbDLL)
	{
		CreateInstance createInstance = reinterpret_cast<CreateInstance>(GetProcAddress(orbDLL, "CreateInstance"));

		if (createInstance)
		{
			orbSound = createInstance();

			int osID = orbSound->DynamicConnectToOrbiterSoundDLL(Obj);

			if (osID != -1)
			{
				defaultData.orbDLL = dataMap[osID].orbDLL = orbDLL;
				defaultData.orbSound = dataMap[osID].orbSound = orbSound;
			}

			return osID;
		}
	}

	return -1;
}

BOOL SetMyDefaultWaveDirectory(char* MySoundDirectory)
{
	return defaultData.orbSound ? defaultData.orbSound->DynamicSetMyDefaultWaveDirectory(MySoundDirectory) : FALSE;
}

float GetUserOrbiterSoundVersion()
{
	return defaultData.orbSound ? defaultData.orbSound->DynamicGetUserOrbiterSoundVersion() : 0;
}

BOOL IsOrbiterSound3D()
{
	return defaultData.orbSound ? defaultData.orbSound->DynamicIsOrbiterSound3D() : FALSE;
}

BOOL RequestLoad3DWaveMono(int iMyID, int iWavNumber, char* cSoundName, EXTENDEDPLAY extended, VECTOR3* v3Position)
{
	if (dataMap.find(iMyID) == dataMap.end()) return FALSE;

	return dataMap.at(iMyID).orbSound->DynamicRequestLoad3DWaveMono(iMyID, iWavNumber, cSoundName, extended, v3Position);
}

BOOL RequestLoad3DWaveStereo(int iMyID, int iWavNumber, char* cSoundName, EXTENDEDPLAY extended, VECTOR3* v3LeftPos, VECTOR3* v3RightPos)
{
	if (dataMap.find(iMyID) == dataMap.end()) return FALSE;

	return dataMap.at(iMyID).orbSound->DynamicRequestLoad3DWaveStereo(iMyID, iWavNumber, cSoundName, extended, v3LeftPos, v3RightPos);
}

BOOL Set3dWaveParameters(int iMyID, int WavNumber, VECTOR3* vLeftPos, VECTOR3* vRightPos, float* flMinDistance, float* flMaxDistance, OS3DCONE* soundConeParm)
{
	if (dataMap.find(iMyID) == dataMap.end()) return FALSE;

	return dataMap.at(iMyID).orbSound->DynamicSet3dWaveParameters(iMyID, WavNumber, vLeftPos, vRightPos, flMinDistance, flMaxDistance, soundConeParm);
}

BOOL RequestLoadVesselWave(int MyID, int WavNumber, char* SoundName, EXTENDEDPLAY extended)
{
	if (dataMap.find(MyID) == dataMap.end()) return FALSE;

	return dataMap.at(MyID).orbSound->DynamicRequestLoadVesselWave(MyID, WavNumber, SoundName, extended);
}

BOOL PlayVesselWave(int MyID, int WavNumber, int Loop, int Volume, int Frequency)
{
	if (dataMap.find(MyID) == dataMap.end()) return FALSE;

	return dataMap.at(MyID).orbSound->DynamicPlayVesselWave(MyID, WavNumber, Loop, Volume, Frequency);
}

BOOL StopVesselWave(int MyID, int WavNumber)
{
	if (dataMap.find(MyID) == dataMap.end()) return FALSE;

	return dataMap.at(MyID).orbSound->DynamicStopVesselWave(MyID, WavNumber);
}

BOOL IsPlaying(int MyID, int WavNumber)
{
	if (dataMap.find(MyID) == dataMap.end()) return FALSE;

	return dataMap.at(MyID).orbSound->DynamicIsPlaying(MyID, WavNumber);
}

BOOL PlayVesselRadioExclusiveWave(int MyID, int WavNumber, int Volume)
{
	if (dataMap.find(MyID) == dataMap.end()) return FALSE;

	return dataMap.at(MyID).orbSound->DynamicPlayVesselRadioExclusiveWave(MyID, WavNumber, Volume);
}

BOOL ReplaceStockSound(int iMyId, char* cMyCustomWavName, int iWhichSoundToReplace)
{
	if (dataMap.find(iMyId) == dataMap.end()) return FALSE;

	return dataMap.at(iMyId).orbSound->DynamicReplaceStockSound(iMyId, cMyCustomWavName, iWhichSoundToReplace);
}

BOOL SoundOptionOnOff(int MyID, int Option, BOOL Status)
{
	if (dataMap.find(MyID) == dataMap.end()) return FALSE;

	return dataMap.at(MyID).orbSound->DynamicSoundOptionOnOff(MyID, Option, Status);
}

BOOL IsRadioPlaying()
{
	return defaultData.orbSound ? defaultData.orbSound->DynamicIsRadioPlaying() : FALSE;
}

BOOL SetRadioFrequency(char* Frequency)
{
	return defaultData.orbSound ? defaultData.orbSound->DynamicSetRadioFrequency(Frequency) : FALSE;
}