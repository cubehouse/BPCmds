// Copyright 2016 @cube. All Rights Reserved.

#include "BPCmdsPrivatePCH.h"
#include "GameFramework/Actor.h"

class FBPCmds : public IBPCmds, public FSelfRegisteringExec
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	// intercept Exec console commands
	bool Exec(class UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override;
};

IMPLEMENT_MODULE( FBPCmds, BPCmds )

void FBPCmds::StartupModule() {}
void FBPCmds::ShutdownModule() {}


bool FBPCmds::Exec(class UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar)
{
	// Commands need to start with Cmd in Blueprint
	FString CmdName = FString::Printf(TEXT("Cmd%s"), Cmd);

	// if any of the actors consumes this command, we'll return that this command ran
	bool didExecuteFunction = false;

	// attempt to run this on each actor available
	FOutputDeviceNull ar;
	for (TObjectIterator<AActor> Itr; Itr; ++Itr)
	{
		// Only run on objects in the world the console command was run in
		//  eg. if you run in PIE, there are actually two worlds, the editor and the PIE session
		if (Itr->GetWorld() == InWorld)
		{
			didExecuteFunction |= Itr->CallFunctionByNameWithArguments(*CmdName, ar, NULL, true);
		}
	}

	return didExecuteFunction;
}
