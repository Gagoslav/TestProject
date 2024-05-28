using UnrealBuildTool;

public class TPSShooter : ModuleRules
{
    public TPSShooter(ReadOnlyTargetRules TargetRules) : base(TargetRules)
    {
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject" });

        PrivateIncludePaths.AddRange(new string[] { "AddedModule" });
    }
}