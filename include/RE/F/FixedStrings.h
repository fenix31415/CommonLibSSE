#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class FixedStrings
	{
	public:
		static FixedStrings* GetSingleton()
		{
			using func_t = decltype(&FixedStrings::GetSingleton);
			REL::Relocation<func_t> func{ REL::Offset(0x10EA60) };
			return func();
		}

		// members
		BSFixedString npcRoot;                               // 0x000 - "NPCRoot[Root]"
		BSFixedString npc;                                   // 0x008 - "NPC"
		BSFixedString npcHead;                               // 0x010 - "NPCHead[Head]"
		BSFixedString npcPelvis_Pelv;                        // 0x018 - "NPCPelvis[Pelv]"
		BSFixedString npcSpine;                              // 0x020 - "NPCSpine[Spn0]"
		BSFixedString npcSpine1;                             // 0x028 - "NPCSpine1[Spn1]"
		BSFixedString npcSpine2;                             // 0x030 - "NPCSpine2[Spn2]"
		BSFixedString npcLFoot;                              // 0x038 - "NPCLFoot[Lft]"
		BSFixedString npcRFoot;                              // 0x040 - "NPCRFoot[Rft]"
		BSFixedString npcLCalf;                              // 0x048 - "NPCLCalf[LClf]"
		BSFixedString npcRCalf;                              // 0x050 - "NPCRCalf[RClf]"
		BSFixedString specialIdle_Cast;                      // 0x058 - "SpecialIdle_Cast"
		BSFixedString specialIdle_AreaEffect;                // 0x060 - "SpecialIdle_AreaEffect"
		BSFixedString attachSound;                           // 0x068 - "AttachSound"
		BSFixedString soundMarker;                           // 0x070 - "SoundMarker"
		BSFixedString skinnedDecalNode;                      // 0x078 - "SkinnedDecalNode"
		BSFixedString decalNode;                             // 0x080 - "DecalNode"
		BSFixedString modelSwapNode;                         // 0x088 - "ModelSwapNode"
		BSFixedString open;                                  // 0x090 - "Open"
		BSFixedString close;                                 // 0x098 - "Close"
		BSFixedString dvpg;                                  // 0x0A0 - "DVPG"
		BSFixedString prn;                                   // 0x0A8 - "Prn"
		BSFixedString weapon;                                // 0x0B0 - "Weapon"
		BSFixedString weaponSword;                           // 0x0B8 - "WeaponSword"
		BSFixedString weaponDagger;                          // 0x0C0 - "WeaponDagger"
		BSFixedString weaponAxe;                             // 0x0C8 - "WeaponAxe"
		BSFixedString weaponMace;                            // 0x0D0 - "WeaponMace"
		BSFixedString shield;                                // 0x0D8 - "Shield"
		BSFixedString weaponBack;                            // 0x0E0 - "WeaponBack"
		BSFixedString weaponBow;                             // 0x0E8 - "WeaponBow"
		BSFixedString quiver;                                // 0x0F0 - "Quiver"
		BSFixedString editorMarker;                          // 0x0F8 - "EditorMarker"
		BSFixedString editorMarker0;                         // 0x100 - "EditorMarker:0"
		BSFixedString editorMarker1;                         // 0x108 - "EditorMarker:1"
		BSFixedString editorMarker2;                         // 0x110 - "EditorMarker:2"
		BSFixedString arrowQuiver;                           // 0x118 - "ArrowQuiver"
		BSFixedString markerSource;                          // 0x120 - "MarkerSource"
		BSFixedString markerTarget;                          // 0x128 - "MarkerTarget"
		BSFixedString attachLight;                           // 0x130 - "AttachLight"
		BSFixedString skin;                                  // 0x138 - "skin"
		BSFixedString faceGenEars;                           // 0x140 - "FaceGenEars"
		BSFixedString unequip;                               // 0x148 - "Unequip"
		BSFixedString laserSight;                            // 0x150 - "LaserSight"
		BSFixedString aimSight;                              // 0x158 - "AimSight"
		BSFixedString decal;                                 // 0x160 - "Decal"
		BSFixedString permanentDecal;                        // 0x168 - "PermanentDecal"
		BSFixedString grabLeft;                              // 0x170 - "grabLeft"
		BSFixedString grabRight;                             // 0x178 - "grabRight"
		BSFixedString arrow0;                                // 0x180 - "Arrow:0"
		BSFixedString arrowBone;                             // 0x188 - "ArrowBone"
		BSFixedString bsFaceGenNiNodeSkinned;                // 0x190 - "BSFaceGenNiNodeSkinned"
		BSFixedString entryPoint;                            // 0x198 - "EntryPoint"
		BSFixedString npcLUpperArm;                          // 0x1A0 - "NPCLUpperArm[LUar]"
		BSFixedString npcLForearm;                           // 0x1A8 - "NPCLForearm[LLar]"
		BSFixedString npcRUpperArm;                          // 0x1B0 - "NPCRUpperArm[RUar]"
		BSFixedString npcLookNode;                           // 0x1B8 - "NPCLookNode[Look]"
		BSFixedString npcTail1;                              // 0x1C0 - "NPCTail1"
		BSFixedString npcTailHub;                            // 0x1C8 - "NPCTailHub"
		BSFixedString npcPelvis;                             // 0x1D0 - "NPCPelvis"
		BSFixedString talking;                               // 0x1D8 - "Talking"
		BSFixedString camera1st;                             // 0x1E0 - "Camera1st[Cam1]"
		BSFixedString camera3rd;                             // 0x1E8 - "Camera3rd[Cam3]"
		BSFixedString headMeshForExport_FaceGenAndMorphs_0;  // 0x1F0 - "HeadMeshForExport_FaceGenAndMorphs:0"
		BSFixedString pinnedLimb;                            // 0x1F8 - "PinnedLimb"
		BSFixedString backpack;                              // 0x200 - "Backpack"
		BSFixedString projectileNode;                        // 0x208 - "ProjectileNode"
		BSFixedString blastRadiusNode;                       // 0x210 - "BlastRadiusNode"
		BSFixedString torchFire;                             // 0x218 - "TorchFire"
		BSFixedString lightOn;                               // 0x220 - "##LightOn"
		BSFixedString npcCOM;                                // 0x228 - "NPCCOM[COM]"
		BSFixedString skinAttachment;                        // 0x230 - "SkinAttachment"
		BSFixedString npcNeck;                               // 0x238 - "NPCNeck[Neck]"
		BSFixedString nifRound;                              // 0x240 - "##NifRound"
		BSFixedString scb;                                   // 0x248 - "Scb"
		BSFixedString upperBody;                             // 0x250 - "UpperBody"
		BSFixedString lightOff;                              // 0x258 - "##LightOff"
		BSFixedString npcHeadMagicNode;                      // 0x260 - "NPCHeadMagicNode[Hmag]"
		BSFixedString npcLMagicNode;                         // 0x268 - "NPCLMagicNode[LMag]"
		BSFixedString npcRMagicNode;                         // 0x270 - "NPCRMagicNode[RMag]"
		BSFixedString magicLeft;                             // 0x278 - "MagicLeft"
		BSFixedString magicRight;                            // 0x280 - "MagicRight"
		BSFixedString magicOther;                            // 0x288 - "MagicOther"
		BSFixedString cameraControl;                         // 0x290 - "CameraControl"
		BSFixedString npcRoot1;                              // 0x298 - "NPCRoot[Root]"
		BSFixedString saddleBone;                            // 0x2A0 - "SaddleBone"
		BSFixedString perchFireNode;                         // 0x2A8 - "PerchFireNode"
		BSFixedString graphDeleting;                         // 0x2B0 - "GraphDeleting"
		BSFixedString isBlocking;                            // 0x2B8 - "IsBlocking"
		BSFixedString isShouting;                            // 0x2C0 - "IsShouting"
		BSFixedString isPlayer;                              // 0x2C8 - "IsPlayer"
		BSFixedString isnpc;                                 // 0x2D0 - "IsNPC"
		BSFixedString iIsPlayer;                             // 0x2D8 - "iIsPlayer"
		BSFixedString fScale;                                // 0x2E0 - "fScale"
		BSFixedString femaleOffset;                          // 0x2E8 - "FemaleOffset"
		BSFixedString isFirstPerson;                         // 0x2F0 - "IsFirstPerson"
		BSFixedString i1stPerson;                            // 0x2F8 - "i1stPerson"
		BSFixedString fIsFirstPerson;                        // 0x300 - "fIsFirstPerson"
		BSFixedString bHumanoidFootIKEnable;                 // 0x308 - "bHumanoidFootIKEnable"
		BSFixedString iSyncIdleLocomotion;                   // 0x310 - "iSyncIdleLocomotion"
		BSFixedString iSyncTurnState;                        // 0x318 - "iSyncTurnState"
		BSFixedString isAttackReady;                         // 0x320 - "IsAttackReady"
		BSFixedString bVoiceReady;                           // 0x328 - "bVoiceReady"
		BSFixedString bMLh_Ready;                            // 0x330 - "bMLh_Ready"
		BSFixedString bMRh_Ready;                            // 0x338 - "bMRh_Ready"
		BSFixedString bEquipOK;                              // 0x340 - "bEquipOk"
		BSFixedString hitFrame;                              // 0x348 - "HitFrame"
		BSFixedString isSprinting;                           // 0x350 - "IsSprinting"
		BSFixedString iSyncSprintState;                      // 0x358 - "iSyncSprintState"
		BSFixedString weapAdj;                               // 0x360 - "weapAdj"
		BSFixedString weaponSpeedMult;                       // 0x368 - "weaponSpeedMult"
		BSFixedString leftWeaponSpeedMult;                   // 0x370 - "leftWeaponSpeedMult"
		BSFixedString bowZoom;                               // 0x378 - "BowZoom"
		BSFixedString bBowZoomed;                            // 0x380 - "bBowZoomed"
		BSFixedString iLeftHandType;                         // 0x388 - "iLeftHandType"
		BSFixedString iRightHandType;                        // 0x390 - "iRightHandType"
		BSFixedString iLeftHandEquipped;                     // 0x398 - "iLeftHandEquipped"
		BSFixedString iRightHandEquipped;                    // 0x3A0 - "iRightHandEquipped"
		BSFixedString bLeftHand;                             // 0x3A8 - "bLeftHand"
		BSFixedString bRightHand;                            // 0x3B0 - "bRightHand"
		BSFixedString fIdleTimer;                            // 0x3B8 - "fIdleTimer"
		BSFixedString injured;                               // 0x3C0 - "Injured"
		BSFixedString land;                                  // 0x3C8 - "Land"
		BSFixedString bCrashLand;                            // 0x3D0 - "bCrashLand"
		BSFixedString landTypeIndex;                         // 0x3D8 - "LandTypeIndex"
		BSFixedString actorResponse;                         // 0x3E0 - "ActorResponse"
		BSFixedString playerCharacterResponse;               // 0x3E8 - "PlayerCharacterResponse"
		BSFixedString tailPitchCurrent;                      // 0x3F0 - "TailPitchCurrent"
		BSFixedString tailPitchMax;                          // 0x3F8 - "TailPitchMax"
		BSFixedString tailYawCurrent;                        // 0x400 - "TailYawCurrent"
		BSFixedString tailYawMax;                            // 0x408 - "TailYawMax"
		BSFixedString lookAtHeadingMaxAngle;                 // 0x410 - "LookAtHeadingMaxAngle"
		BSFixedString english;                               // 0x418 - "English"
		BSFixedString russian;                               // 0x420 - "Russian"
		BSFixedString polish;                                // 0x428 - "Polish"
		BSFixedString mLh_SpellFire_Event;                   // 0x430 - "MLh_SpellFire_Event"
		BSFixedString mRh_SpellFire_Event;                   // 0x438 - "MRh_SpellFire_Event"
		BSFixedString voice_SpellFire_Event;                 // 0x440 - "Voice_SpellFire_Event"
		BSFixedString arrowRelease;                          // 0x448 - "arrowRelease"
		BSFixedString endAnim;                               // 0x450 - "EndAnim"
		BSFixedString stopEffect;                            // 0x458 - "StopEffect"
		BSFixedString tweenEntryDirection;                   // 0x460 - "TweenEntryDirection"
		BSFixedString tweenPosition;                         // 0x468 - "TweenPosition"
		BSFixedString tweenRotation;                         // 0x470 - "TweenRotation"
		BSFixedString hasTweenSpeed;                         // 0x478 - "HasTweenSpeed"
		BSFixedString tweenSpeed;                            // 0x480 - "TweenSpeed"
		BSFixedString bTweenUpdate;                          // 0x488 - "bTweenUpdate"
		BSFixedString targetLocation;                        // 0x490 - "TargetLocation"
		BSFixedString movementDirection;                     // 0x498 - "MovementDirection"
		BSFixedString fCastStrength;                         // 0x4A0 - "fCastStrength"
		BSFixedString staggerMagnitude;                      // 0x4A8 - "staggerMagnitude"
		BSFixedString staggerDirection;                      // 0x4B0 - "staggerDirection"
		BSFixedString isBusy;                                // 0x4B8 - "IsBusy"
		BSFixedString imod;                                  // 0x4C0 - "Imod"
		BSFixedString rimod;                                 // 0x4C8 - "Rimod"
		BSFixedString distToGoal;                            // 0x4D0 - "DistToGoal"
		BSFixedString preHitFrame;                           // 0x4D8 - "preHitFrame"
		BSFixedString weaponSwing;                           // 0x4E0 - "weaponSwing"
		BSFixedString weaponLeftSwing;                       // 0x4E8 - "weaponLeftSwing"
		BSFixedString attackWinStart;                        // 0x4F0 - "AttackWinStart"
		BSFixedString attackWinEnd;                          // 0x4F8 - "AttackWinEnd"
		BSFixedString velocityZ;                             // 0x500 - "VelocityZ"
		BSFixedString speed;                                 // 0x508 - "Speed"
		BSFixedString turnDelta;                             // 0x510 - "TurnDelta"
		BSFixedString direction;                             // 0x518 - "Direction"
		BSFixedString speedSampled;                          // 0x520 - "SpeedSampled"
		BSFixedString horseSpeedSampled;                     // 0x528 - "HorseSpeedSampled"
		BSFixedString lookAtOutOfRange;                      // 0x530 - "LookAtOutOfRange"
		BSFixedString aimHeadingMax;                         // 0x538 - "AimHeadingMax"
		BSFixedString aimPitchMax;                           // 0x540 - "AimPitchMax"
		BSFixedString aimHeadingCurrent;                     // 0x548 - "AimHeadingCurrent"
		BSFixedString aimPitchCurrent;                       // 0x550 - "AimPitchCurrent"
		BSFixedString iSyncForwardState;                     // 0x558 - "iSyncForwardState"
		BSFixedString iSyncStrafeState;                      // 0x560 - "iSyncStrafeState"
		BSFixedString bAnimationDriven;                      // 0x568 - "bAnimationDriven"
		BSFixedString bAllowRotation;                        // 0x570 - "bAllowRotation"
		BSFixedString bIsSynced;                             // 0x578 - "bIsSynced"
		BSFixedString bSpeedSynced;                          // 0x580 - "bSpeedSynced"
		BSFixedString bDisableInterp;                        // 0x588 - "bDisableInterp"
		BSFixedString iGetUpType;                            // 0x590 - "iGetUpType"
		BSFixedString objectActivated;                       // 0x598 - "ObjectActivated"
		BSFixedString fFlameProjectileLength;                // 0x5A0 - "fFlameProjectileLength"
		BSFixedString pairedKillTarget;                      // 0x5A8 - "PairedKillTarget"
		BSFixedString bAimActive;                            // 0x5B0 - "bAimActive"
		BSFixedString turnDynamic;                           // 0x5B8 - "TurnDynamic"
		BSFixedString bForceIdleStop;                        // 0x5C0 - "bForceIdleStop"
		BSFixedString constraintOffset;                      // 0x5C8 - "ConstraintOffset"
		BSFixedString left;                                  // 0x5D0 - "Left"
		BSFixedString pickup;                                // 0x5D8 - "PickUp"
		BSFixedString pathTweenerStart;                      // 0x5E0 - "PathTweenerStart"
		BSFixedString pathTweenerEnd;                        // 0x5E8 - "PathTweenerEnd"
	};
	static_assert(sizeof(FixedStrings) == 0x5F0);
}
