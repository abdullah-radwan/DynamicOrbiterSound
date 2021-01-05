#include "DynamicOS_DLL.h"

int DynamicOS::DynamicConnectToOrbiterSoundDLL(OBJHANDLE Obj)
{
	return ConnectToOrbiterSoundDLL(Obj);
}

BOOL DynamicOS::DynamicSetMyDefaultWaveDirectory(char* MySoundDirectory)
{
	return SetMyDefaultWaveDirectory(MySoundDirectory);
}

float DynamicOS::DynamicGetUserOrbiterSoundVersion()
{
	return GetUserOrbiterSoundVersion();
}

BOOL DynamicOS::DynamicIsOrbiterSound3D()
{
	return IsOrbiterSound3D();
}

BOOL DynamicOS::DynamicRequestLoad3DWaveMono(int iMyID, int iWavNumber, char* cSoundName, EXTENDEDPLAY extended, VECTOR3* v3Position)
{
	return RequestLoad3DWaveMono(iMyID, iWavNumber, cSoundName, extended, v3Position);
}

BOOL DynamicOS::DynamicRequestLoad3DWaveStereo(int iMyID, int iWavNumber, char* cSoundName, EXTENDEDPLAY extended, VECTOR3* v3LeftPos, VECTOR3* v3RightPos)
{
	return RequestLoad3DWaveStereo(iMyID, iWavNumber, cSoundName, extended, v3LeftPos, v3RightPos);
}

BOOL DynamicOS::DynamicSet3dWaveParameters(int iMyID, int WavNumber, VECTOR3* vLeftPos, VECTOR3* vRightPos, float* flMinDistance, float* flMaxDistance, OS3DCONE* soundConeParm)
{
	return Set3dWaveParameters(iMyID, WavNumber, vLeftPos, vRightPos, flMinDistance, flMaxDistance, soundConeParm);
}

BOOL DynamicOS::DynamicRequestLoadVesselWave(int MyID, int WavNumber, char* SoundName, EXTENDEDPLAY extended)
{
	return RequestLoadVesselWave(MyID, WavNumber, SoundName, extended);
}

BOOL DynamicOS::DynamicPlayVesselWave(int MyID, int WavNumber, int Loop, int Volume, int Frequency)
{
	return PlayVesselWave(MyID, WavNumber, Loop, Volume, Frequency);
}

BOOL DynamicOS::DynamicStopVesselWave(int MyID, int WavNumber)
{
	return StopVesselWave(MyID, WavNumber);
}

BOOL DynamicOS::DynamicIsPlaying(int MyID, int WavNumber)
{
	return IsPlaying(MyID, WavNumber);
}

BOOL DynamicOS::DynamicPlayVesselRadioExclusiveWave(int MyID, int WavNumber, int Volume)
{
	return PlayVesselRadioExclusiveWave(MyID, WavNumber, Volume);
}

BOOL DynamicOS::DynamicReplaceStockSound(int iMyId, char* cMyCustomWavName, int iWhichSoundToReplace)
{
	return ReplaceStockSound(iMyId, cMyCustomWavName, iWhichSoundToReplace);
}

BOOL DynamicOS::DynamicSoundOptionOnOff(int MyID, int Option, BOOL Status)
{
	return SoundOptionOnOff(MyID, Option, Status);
}

BOOL DynamicOS::DynamicIsRadioPlaying()
{
	return IsRadioPlaying();
}

BOOL DynamicOS::DynamicSetRadioFrequency(char* Frequency)
{
	return SetRadioFrequency(Frequency);
}
