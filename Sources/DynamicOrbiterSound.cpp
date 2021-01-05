#include <OrbiterSoundSDK50.h>
#include "DLL\DynamicOS_Interface.h"

#ifdef _DEBUG
#define DLL_PATH "Modules\\DynamicOrbiterSoundD.dll"
#else
#define DLL_PATH "Modules\\DynamicOrbiterSound.dll"
#endif

DynamicOS_DLL* orbSound = nullptr;
HINSTANCE orbDLL = nullptr;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	{
		if (!orbDLL)
		{
			orbDLL = LoadLibraryA(DLL_PATH);

			if (orbDLL)
			{
				typedef DynamicOS_DLL* (*CreateInstance)();
				CreateInstance createInstance = reinterpret_cast<CreateInstance>(GetProcAddress(orbDLL, "CreateInstance"));

				if (createInstance) orbSound = createInstance();
			}
		}

		break;
	}

	case DLL_PROCESS_DETACH:
	case DLL_THREAD_DETACH:
	{
		if (orbDLL)
		{
			typedef void (*DestroyInstance)(DynamicOS_DLL*);
			DestroyInstance destroyInstance = reinterpret_cast<DestroyInstance>(GetProcAddress(orbDLL, "DestroyInstance"));

			if (destroyInstance) destroyInstance(orbSound);

			FreeLibrary(orbDLL);

			orbDLL = nullptr;
		}
		break;
	}
	}

	return TRUE;
}

int ConnectToOrbiterSoundDLL(OBJHANDLE Obj)
{
	return orbSound ? orbSound->DynamicConnectToOrbiterSoundDLL(Obj) : -1;
}

BOOL SetMyDefaultWaveDirectory(char* MySoundDirectory)
{
	return orbSound ? orbSound->DynamicSetMyDefaultWaveDirectory(MySoundDirectory) : FALSE;
}

float GetUserOrbiterSoundVersion()
{
	return orbSound ? orbSound->DynamicGetUserOrbiterSoundVersion() : 0;
}

BOOL IsOrbiterSound3D()
{
	return orbSound ? orbSound->DynamicIsOrbiterSound3D() : FALSE;
}

BOOL RequestLoad3DWaveMono(int iMyID, int iWavNumber, char* cSoundName, EXTENDEDPLAY extended, VECTOR3* v3Position)
{
	return orbSound ? orbSound->DynamicRequestLoad3DWaveMono(iMyID, iWavNumber, cSoundName, extended, v3Position) : FALSE;
}

BOOL RequestLoad3DWaveStereo(int iMyID, int iWavNumber, char* cSoundName, EXTENDEDPLAY extended, VECTOR3* v3LeftPos, VECTOR3* v3RightPos)
{
	return orbSound ? orbSound->DynamicRequestLoad3DWaveStereo(iMyID, iWavNumber, cSoundName, extended, v3LeftPos, v3RightPos) : FALSE;
}

BOOL Set3dWaveParameters(int iMyID, int WavNumber, VECTOR3* vLeftPos, VECTOR3* vRightPos, float* flMinDistance, float* flMaxDistance, OS3DCONE* soundConeParm)
{
	return orbSound ? orbSound->DynamicSet3dWaveParameters(iMyID, WavNumber, vLeftPos, vRightPos, flMinDistance, flMaxDistance, soundConeParm) : FALSE;
}

BOOL RequestLoadVesselWave(int MyID, int WavNumber, char* SoundName, EXTENDEDPLAY extended)
{
	return orbSound ? orbSound->DynamicRequestLoadVesselWave(MyID, WavNumber, SoundName, extended) : FALSE;
}

BOOL PlayVesselWave(int MyID, int WavNumber, int Loop, int Volume, int Frequency)
{
	return orbSound ? orbSound->DynamicPlayVesselWave(MyID, WavNumber, Loop, Volume, Frequency) : FALSE;
}

BOOL StopVesselWave(int MyID, int WavNumber)
{
	return orbSound ? orbSound->DynamicStopVesselWave(MyID, WavNumber) : FALSE;
}

BOOL IsPlaying(int MyID, int WavNumber)
{
	return orbSound ? orbSound->DynamicIsPlaying(MyID, WavNumber) : FALSE;
}

BOOL PlayVesselRadioExclusiveWave(int MyID, int WavNumber, int Volume)
{
	return orbSound ? orbSound->DynamicPlayVesselRadioExclusiveWave(MyID, WavNumber, Volume) : FALSE;
}

BOOL ReplaceStockSound(int iMyId, char* cMyCustomWavName, int iWhichSoundToReplace)
{
	return orbSound ? orbSound->DynamicReplaceStockSound(iMyId, cMyCustomWavName, iWhichSoundToReplace) : FALSE;
}

BOOL SoundOptionOnOff(int MyID, int Option, BOOL Status)
{
	return orbSound ? orbSound->DynamicSoundOptionOnOff(MyID, Option, Status) : FALSE;
}

BOOL IsRadioPlaying()
{
	return orbSound ? orbSound->DynamicIsRadioPlaying() : FALSE;
}

BOOL SetRadioFrequency(char* Frequency)
{
	return orbSound ? orbSound->DynamicSetRadioFrequency(Frequency) : FALSE;
}

