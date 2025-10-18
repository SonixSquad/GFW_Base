#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"


namespace GFWTags
{
	namespace GFWAbilities
	{
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Primary);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Secondary);
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(Tertiary);
		
		UE_DECLARE_GAMEPLAY_TAG_EXTERN(ActivateOnGiven);
	}

	namespace Events
	{
		namespace Enemy
		{
			UE_DECLARE_GAMEPLAY_TAG_EXTERN(HitReact);
		}
	}
}