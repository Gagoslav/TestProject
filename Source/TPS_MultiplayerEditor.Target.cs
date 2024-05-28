// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class TPS_MultiplayerEditorTarget : TargetRules
{
	public TPS_MultiplayerEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "TPS_Multiplayer" } );
        ExtraModuleNames.AddRange(new string[] { "TPSShooter" });
    }
}
