#pragma once
#include "DynamicOS_Interface.h"

class DynamicOS : public DynamicOS_DLL
{
public:
	int DynamicConnectToOrbiterSoundDLL(OBJHANDLE Obj) override;

	BOOL DynamicSetMyDefaultWaveDirectory(char* MySoundDirectory) override;

	float DynamicGetUserOrbiterSoundVersion() override;

	BOOL DynamicIsOrbiterSound3D() override;

	BOOL DynamicRequestLoad3DWaveMono(int iMyID, int iWavNumber, char* cSoundName, EXTENDEDPLAY extended, VECTOR3* v3Position) override;

	BOOL DynamicRequestLoad3DWaveStereo(int iMyID, int iWavNumber, char* cSoundName, EXTENDEDPLAY extended, VECTOR3* v3LeftPos, VECTOR3* v3RightPos) override;

	BOOL DynamicSet3dWaveParameters(int iMyID, int WavNumber, VECTOR3* vLeftPos, VECTOR3* vRightPos, float* flMinDistance, float* flMaxDistance, OS3DCONE* soundConeParm) override;

	BOOL DynamicRequestLoadVesselWave(int MyID, int WavNumber, char* SoundName, EXTENDEDPLAY extended) override;

	BOOL DynamicPlayVesselWave(int MyID, int WavNumber, int Loop, int Volume , int Frequency) override;

	BOOL DynamicStopVesselWave(int MyID, int WavNumber) override;

	BOOL DynamicIsPlaying(int MyID, int WavNumber) override;

	BOOL DynamicPlayVesselRadioExclusiveWave(int MyID, int WavNumber, int Volume) override;

	BOOL DynamicReplaceStockSound(int iMyId, char* cMyCustomWavName, int iWhichSoundToReplace) override;

	BOOL DynamicSoundOptionOnOff(int MyID, int Option, BOOL Status) override;

	BOOL DynamicIsRadioPlaying() override;

	BOOL DynamicSetRadioFrequency(char* Frequency) override;
};

DLLCLBK DynamicOS_DLL* CreateInstance() { return new DynamicOS; }

DLLCLBK void DestroyInstance(DynamicOS_DLL* instance) { delete instance; }