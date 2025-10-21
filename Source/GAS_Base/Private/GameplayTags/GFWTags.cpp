#include "GameplayTags/GFWTags.h"



namespace GFWTags
{
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(None, "GFWTags.None", "None")
	
	namespace SetByCaller
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Projectile, "GFWTags.SetByCaller.Projectile", "Tag for Projectile")
	}
	
	namespace GFWAbilities
	{
		//native tags implementation

		
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Primary, "GFWTags.GFWAbilities.Primary", "Tag for the Primary Ability")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Secondary, "GFWTags.GFWAbilities.Secondary", "Tag for the Secondary Ability")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Tertiary, "GFWTags.GFWAbilities.Tertiary", "Tag for the Tertiary Ability")
		
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ActivateOnGiven, "GFWTags.GFWAbilities.ActivateOnGiven", "Tag for the Ability to activate on given")

		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attack, "GFWTags.GFWAbilities.Enemy.Attack", "Enemy Attack Tag")
		}
	}

	namespace Events
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(KillScored, "GFWTags.Events.KillScored", "Tag for the KillScored Event")

		namespace Player
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "GFWTags.Events.Player.HitReact", "Tag for the Player HitReact Event")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Death, "GFWTags.Events.Player.Death", "Tag for the Player Death Event")
		}
		
		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "GFWTags.Events.Enemy.HitReact", "Tag for Enemy HitReaction Event")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(EndAttack, "GFWTags.Events.Enemy.EndAttack", "Tag for the Enemy Ending an Attack")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MeleeTraceHit, "GFWTags.Events.Enemy.MeleeTraceHit", "Tag for the Enemy Melee Trace Hit")
		}
		
	}



	
}