#include "GameplayTags/GFWTags.h"



namespace GFWTags
{
	namespace GFWAbilities
	{
		//native tags implementation
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Primary, "GFWTags.GFWAbilities.Primary", "Tag for the Primary Ability")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Secondary, "GFWTags.GFWAbilities.Secondary", "Tag for the Secondary Ability")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Tertiary, "GFWTags.GFWAbilities.Tertiary", "Tag for the Tertiary Ability")
		
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ActivateOnGiven, "GFWTags.GFWAbilities.ActivateOnGiven", "Tag for the Ability to activate on given")
		//
		//
	}

	namespace Events
	{
		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "GFWTags.Events.Enemy.HitReact", "Tag for Enemy HitReaction Event")
		}
		
	}



	
}