#pragma once
#include <OrbiterSoundSDK50.h>

class DynamicOS_DLL
{
public:
	virtual int DynamicConnectToOrbiterSoundDLL(OBJHANDLE Obj) = 0;

	virtual BOOL DynamicSetMyDefaultWaveDirectory(char* MySoundDirectory) = 0;

	virtual float DynamicGetUserOrbiterSoundVersion() = 0;

	virtual BOOL DynamicIsOrbiterSound3D() = 0;

	virtual BOOL DynamicRequestLoad3DWaveMono(int iMyID, int iWavNumber, char* cSoundName, EXTENDEDPLAY extended, VECTOR3* v3Position) = 0;

	virtual BOOL DynamicRequestLoad3DWaveStereo(int iMyID, int iWavNumber, char* cSoundName, EXTENDEDPLAY extended, VECTOR3* v3LeftPos, VECTOR3* v3RightPos) = 0;

	virtual BOOL DynamicSet3dWaveParameters(int iMyID, int WavNumber, VECTOR3* vLeftPos, VECTOR3* vRightPos, float* flMinDistance, float* flMaxDistance, OS3DCONE* soundConeParm) = 0;

	virtual BOOL DynamicRequestLoadVesselWave(int MyID, int WavNumber, char* SoundName, EXTENDEDPLAY extended) = 0;

	virtual BOOL DynamicPlayVesselWave(int MyID, int WavNumber, int Loop, int Volume, int Frequency) = 0;

	virtual BOOL DynamicStopVesselWave(int MyID, int WavNumber) = 0;

	virtual BOOL DynamicIsPlaying(int MyID, int WavNumber) = 0;

	virtual BOOL DynamicPlayVesselRadioExclusiveWave(int MyID, int WavNumber, int Volume) = 0;

	virtual BOOL DynamicReplaceStockSound(int iMyId, char* cMyCustomWavName, int iWhichSoundToReplace) = 0;

	virtual BOOL DynamicSoundOptionOnOff(int MyID, int Option, BOOL Status) = 0;

	virtual BOOL DynamicIsRadioPlaying() = 0;

	virtual BOOL DynamicSetRadioFrequency(char* Frequency) = 0;

	virtual ~DynamicOS_DLL() { }
};