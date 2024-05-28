// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class TPS_MultiplayerTarget : TargetRules
{
	public TPS_MultiplayerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "TPS_Multiplayer" } );
        ExtraModuleNames.AddRange(new string[] { "TPSShooter" });
    }
}
