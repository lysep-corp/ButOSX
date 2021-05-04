//
//  Others.h
//  ButOSX
//
//  Created by Can on 1.11.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#ifndef Others_h
#define Others_h
#pragma once

typedef unsigned long long VPANEL;
typedef unsigned long long HFONT;

struct Item_t
{
    Item_t(const char* display_name, const char* entity_name, const char* model, const char* killicon = nullptr)
    {
        this->display_name  = display_name;
        this->entity_name   = entity_name;
        this->model         = model;
        this->killicon      = killicon;
    }
    
    const char* display_name= nullptr;
    const char* entity_name = nullptr;
    const char* model       = nullptr;
    const char* killicon    = nullptr;
};

enum TeamID: int
{
    TEAM_UNASSIGNED,
    TEAM_SPECTATOR,
    TEAM_TERRORIST,
    TEAM_COUNTER_TERRORIST,
};


enum FontFlags: int
{
    FONTFLAG_NONE           = 0,
    FONTFLAG_ITALIC         = 0x1,
    FONTFLAG_UNDERLINE      = 0x2,
    FONTFLAG_STRIKEOUT      = 0x4,
    FONTFLAG_SYMBOL         = 0x8,
    FONTFLAG_ANTIALIAS      = 0x10,
    FONTFLAG_GAUSSIANBLUR   = 0x20,
    FONTFLAG_ROTARY         = 0x40,
    FONTFLAG_DROPSHADOW     = 0x80,
    FONTFLAG_ADDITIVE       = 0x100,
    FONTFLAG_OUTLINE        = 0x200,
    FONTFLAG_CUSTOM         = 0x400,
    FONTFLAG_BITMAP         = 0x800
};

enum ClientFrameStage_t: int
{
    FRAME_UNDEFINED = -1,
    FRAME_START,
    FRAME_NET_UPDATE_START,
    FRAME_NET_UPDATE_POSTDATAUPDATE_START,
    FRAME_NET_UPDATE_POSTDATAUPDATE_END,
    FRAME_NET_UPDATE_END,
    FRAME_RENDER_START,
    FRAME_RENDER_END
};

enum ObserverMode_t: int
{
    OBS_MODE_NONE       = 0,
    OBS_MODE_DEATHCAM   = 1,
    OBS_MODE_FREEZECAM  = 2,
    OBS_MODE_FIXED      = 3,
    OBS_MODE_IN_EYE     = 4,
    OBS_MODE_CHASE      = 5,
    OBS_MODE_ROAMING    = 6
};

enum en_item_definition_index : short
{
    weapon_deagle = 1,
    weapon_elite,
    weapon_fiveseven,
    weapon_glock,
    weapon_ak47 = 7,
    weapon_aug,
    weapon_awp,
    weapon_famas,
    weapon_g3sg1,
    weapon_galilar = 13,
    weapon_m249,
    weapon_m4a1 = 16,
    weapon_mac10,
    weapon_p90 = 19,
    weapon_zone_repulsor,
    weapon_mp5sd = 23,
    weapon_ump45,
    weapon_xm1014,
    weapon_bizon,
    weapon_mag7,
    weapon_negev,
    weapon_sawedoff,
    weapon_tec9,
    weapon_taser,
    weapon_hkp2000,
    weapon_mp7,
    weapon_mp9,
    weapon_nova,
    weapon_p250,
    weapon_shield,
    weapon_scar20,
    weapon_sg556,
    weapon_ssg08,
    weapon_knifegg,
    weapon_knife,
    weapon_flashbang,
    weapon_hegrenade,
    weapon_smokegrenade,
    weapon_molotov,
    weapon_decoy,
    weapon_incgrenade,
    weapon_c4,
    item_kevlar,
    item_assaultsuit,
    item_heavyassaultsuit,
    item_nvg = 54,
    item_defuser,
    item_cutters,
    weapon_healthshot,
    weapon_knife_t = 59,
    weapon_m4a1_silencer,
    weapon_usp_silencer,
    weapon_cz75a = 63,
    weapon_revolver,
    weapon_tagrenade = 68,
    weapon_fists,
    weapon_breachcharge,
    weapon_tablet = 72,
    weapon_melee = 74,
    weapon_axe,
    weapon_hammer,
    weapon_spanner = 78,
    weapon_knife_ghost = 80,
    weapon_firebomb,
    weapon_diversion,
    weapon_frag_grenade,
    weapon_snowball,
    weapon_bumpmine,
    weapon_bayonet = 500,
    weapon_knife_css = 503,
    weapon_knife_flip = 505,
    weapon_knife_gut,
    weapon_knife_karambit,
    weapon_knife_m9_bayonet,
    weapon_knife_tactical,
    weapon_knife_falchion = 512,
    weapon_knife_survival_bowie = 514,
    weapon_knife_butterfly,
    weapon_knife_push,
    weapon_knife_cord,
    weapon_knife_canis,
    weapon_knife_ursus,
    weapon_knife_gypsy_jackknife,
    weapon_knife_outdoor,
    weapon_knife_stiletto,
    weapon_knife_widowmaker,
    weapon_knife_skeleton = 525,
    customplayer_ctm_st6_variantj = 4619,
    customplayer_ctm_st6_variantl = 4680,
    customplayer_ctm_swat_variante = 4711,
    customplayer_ctm_swat_variantf,
    customplayer_ctm_swat_variantg,
    customplayer_ctm_swat_varianth,
    customplayer_ctm_swat_varianti,
    customplayer_ctm_swat_variantj,
    customplayer_tm_balkan_variantk = 4718,
    studded_brokenfang_gloves = 4725,
    customplayer_tm_professional_varf,
    customplayer_tm_professional_varg,
    customplayer_tm_professional_varh,
    customplayer_tm_professional_varj = 4730,
    customplayer_tm_professional_vari = 4732,
    customplayer_tm_professional_varf1,
    customplayer_tm_professional_varf2,
    customplayer_tm_professional_varf3,
    customplayer_tm_professional_varf4,
    studded_bloodhound_gloves = 5027,
    t_gloves,
    ct_gloves,
    sporty_gloves,
    slick_gloves,
    leather_handwraps,
    motorcycle_gloves,
    specialist_gloves,
    studded_hydra_gloves,
    customplayer_t_map_based,
    customplayer_ct_map_based,
    customplayer_tm_anarchist,
    customplayer_tm_anarchist_varianta,
    customplayer_tm_anarchist_variantb,
    customplayer_tm_anarchist_variantc,
    customplayer_tm_anarchist_variantd,
    customplayer_tm_pirate,
    customplayer_tm_pirate_varianta,
    customplayer_tm_pirate_variantb,
    customplayer_tm_pirate_variantc,
    customplayer_tm_pirate_variantd,
    customplayer_tm_professional,
    customplayer_tm_professional_var1,
    customplayer_tm_professional_var2,
    customplayer_tm_professional_var3,
    customplayer_tm_professional_var4,
    customplayer_tm_separatist,
    customplayer_tm_separatist_varianta,
    customplayer_tm_separatist_variantb,
    customplayer_tm_separatist_variantc,
    customplayer_tm_separatist_variantd,
    customplayer_ctm_gign,
    customplayer_ctm_gign_varianta,
    customplayer_ctm_gign_variantb,
    customplayer_ctm_gign_variantc,
    customplayer_ctm_gign_variantd,
    customplayer_ctm_gsg9,
    customplayer_ctm_gsg9_varianta,
    customplayer_ctm_gsg9_variantb,
    customplayer_ctm_gsg9_variantc,
    customplayer_ctm_gsg9_variantd,
    customplayer_ctm_idf,
    customplayer_ctm_idf_variantb,
    customplayer_ctm_idf_variantc,
    customplayer_ctm_idf_variantd,
    customplayer_ctm_idf_variante,
    customplayer_ctm_idf_variantf,
    customplayer_ctm_swat,
    customplayer_ctm_swat_varianta,
    customplayer_ctm_swat_variantb,
    customplayer_ctm_swat_variantc,
    customplayer_ctm_swat_variantd,
    customplayer_ctm_sas_varianta,
    customplayer_ctm_sas_variantb,
    customplayer_ctm_sas_variantc,
    customplayer_ctm_sas_variantd,
    customplayer_ctm_st6,
    customplayer_ctm_st6_varianta,
    customplayer_ctm_st6_variantb,
    customplayer_ctm_st6_variantc,
    customplayer_ctm_st6_variantd,
    customplayer_tm_balkan_variante,
    customplayer_tm_balkan_varianta,
    customplayer_tm_balkan_variantb,
    customplayer_tm_balkan_variantc,
    customplayer_tm_balkan_variantd,
    customplayer_tm_jumpsuit_varianta,
    customplayer_tm_jumpsuit_variantb,
    customplayer_tm_jumpsuit_variantc,
    customplayer_tm_phoenix_heavy,
    customplayer_ctm_heavy,
    customplayer_tm_leet_varianta = 5100,
    customplayer_tm_leet_variantb,
    customplayer_tm_leet_variantc,
    customplayer_tm_leet_variantd,
    customplayer_tm_leet_variante,
    customplayer_tm_leet_variantg,
    customplayer_tm_leet_varianth,
    customplayer_tm_leet_varianti,
    customplayer_tm_leet_variantf,
    customplayer_tm_phoenix = 5200,
    customplayer_tm_phoenix_varianta,
    customplayer_tm_phoenix_variantb,
    customplayer_tm_phoenix_variantc,
    customplayer_tm_phoenix_variantd,
    customplayer_tm_phoenix_varianth,
    customplayer_tm_phoenix_variantf,
    customplayer_tm_phoenix_variantg,
    customplayer_tm_phoenix_varianti,
    customplayer_ctm_fbi = 5300,
    customplayer_ctm_fbi_varianta,
    customplayer_ctm_fbi_variantc,
    customplayer_ctm_fbi_variantd,
    customplayer_ctm_fbi_variante,
    customplayer_ctm_fbi_variantf,
    customplayer_ctm_fbi_variantg,
    customplayer_ctm_fbi_varianth,
    customplayer_ctm_fbi_variantb,
    customplayer_ctm_st6_variantk = 5400,
    customplayer_ctm_st6_variante,
    customplayer_ctm_st6_variantg,
    customplayer_ctm_st6_variantm,
    customplayer_ctm_st6_varianti,
    customplayer_tm_balkan_variantf = 5500,
    customplayer_tm_balkan_varianti,
    customplayer_tm_balkan_variantg,
    customplayer_tm_balkan_variantj,
    customplayer_tm_balkan_varianth,
    customplayer_tm_balkan_variantl,
    customplayer_ctm_sas = 5600,
    customplayer_ctm_sas_variantf
};



enum en_class_id: int
{
    CAI_BaseNPC,
    CAK47,
    CBaseAnimating,
    CBaseAnimatingOverlay,
    CBaseAttributableItem,
    CBaseButton,
    CBaseCombatCharacter,
    CBaseCombatWeapon,
    CBaseCSGrenade,
    CBaseCSGrenadeProjectile,
    CBaseDoor,
    CBaseEntity,
    CBaseFlex,
    CBaseGrenade,
    CBaseParticleEntity,
    CBasePlayer,
    CBasePropDoor,
    CBaseTeamObjectiveResource,
    CBaseTempEntity,
    CBaseToggle,
    CBaseTrigger,
    CBaseViewModel,
    CBaseVPhysicsTrigger,
    CBaseWeaponWorldModel,
    CBeam,
    CBeamSpotlight,
    CBoneFollower,
    CBRC4Target,
    CBreachCharge,
    CBreachChargeProjectile,
    CBreakableProp,
    CBreakableSurface,
    CBumpMine,
    CBumpMineProjectile,
    CC4,
    CCascadeLight,
    CChicken,
    CColorCorrection,
    CColorCorrectionVolume,
    CCSGameRulesProxy,
    CCSPlayer,
    CCSPlayerResource,
    CCSRagdoll,
    CCSTeam,
    CDangerZone,
    CDangerZoneController,
    CDEagle,
    CDecoyGrenade,
    CDecoyProjectile,
    CDrone,
    CDronegun,
    CDynamicLight,
    CDynamicProp,
    CEconEntity,
    CEconWearable,
    CEmbers,
    CEntityDissolve,
    CEntityFlame,
    CEntityFreezing,
    CEntityParticleTrail,
    CEnvAmbientLight,
    CEnvDetailController,
    CEnvDOFController,
    CEnvGasCanister,
    CEnvParticleScript,
    CEnvProjectedTexture,
    CEnvQuadraticBeam,
    CEnvScreenEffect,
    CEnvScreenOverlay,
    CEnvTonemapController,
    CEnvWind,
    CFEPlayerDecal,
    CFireCrackerBlast,
    CFireSmoke,
    CFireTrail,
    CFish,
    CFists,
    CFlashbang,
    CFogController,
    CFootstepControl,
    CFunc_Dust,
    CFunc_LOD,
    CFuncAreaPortalWindow,
    CFuncBrush,
    CFuncConveyor,
    CFuncLadder,
    CFuncMonitor,
    CFuncMoveLinear,
    CFuncOccluder,
    CFuncReflectiveGlass,
    CFuncRotating,
    CFuncSmokeVolume,
    CFuncTrackTrain,
    CGameRulesProxy,
    CGrassBurn,
    CHandleTest,
    CHEGrenade,
    CHostage,
    CHostageCarriableProp,
    CIncendiaryGrenade,
    CInferno,
    CInfoLadderDismount,
    CInfoMapRegion,
    CInfoOverlayAccessor,
    CItem_Healthshot,
    CItemCash,
    CItemDogtags,
    CKnife,
    CKnifeGG,
    CLightGlow,
    CMapVetoPickController,
    CMaterialModifyControl,
    CMelee,
    CMolotovGrenade,
    CMolotovProjectile,
    CMovieDisplay,
    CParadropChopper,
    CParticleFire,
    CParticlePerformanceMonitor,
    CParticleSystem,
    CPhysBox,
    CPhysBoxMultiplayer,
    CPhysicsProp,
    CPhysicsPropMultiplayer,
    CPhysMagnet,
    CPhysPropAmmoBox,
    CPhysPropLootCrate,
    CPhysPropRadarJammer,
    CPhysPropWeaponUpgrade,
    CPlantedC4,
    CPlasma,
    CPlayerPing,
    CPlayerResource,
    CPointCamera,
    CPointCommentaryNode,
    CPointWorldText,
    CPoseController,
    CPostProcessController,
    CPrecipitation,
    CPrecipitationBlocker,
    CPredictedViewModel,
    CProp_Hallucination,
    CPropCounter,
    CPropDoorRotating,
    CPropJeep,
    CPropVehicleDriveable,
    CRagdollManager,
    CRagdollProp,
    CRagdollPropAttached,
    CRopeKeyframe,
    CSCAR17,
    CSceneEntity,
    CSensorGrenade,
    CSensorGrenadeProjectile,
    CShadowControl,
    CSlideshowDisplay,
    CSmokeGrenade,
    CSmokeGrenadeProjectile,
    CSmokeStack,
    CSnowball,
    CSnowballPile,
    CSnowballProjectile,
    CSpatialEntity,
    CSpotlightEnd,
    CSprite,
    CSpriteOriented,
    CSpriteTrail,
    CStatueProp,
    CSteamJet,
    CSun,
    CSunlightShadowControl,
    CSurvivalSpawnChopper,
    CTablet,
    CTeam,
    CTeamplayRoundBasedRulesProxy,
    CTEArmorRicochet,
    CTEBaseBeam,
    CTEBeamEntPoint,
    CTEBeamEnts,
    CTEBeamFollow,
    CTEBeamLaser,
    CTEBeamPoints,
    CTEBeamRing,
    CTEBeamRingPoint,
    CTEBeamSpline,
    CTEBloodSprite,
    CTEBloodStream,
    CTEBreakModel,
    CTEBSPDecal,
    CTEBubbles,
    CTEBubbleTrail,
    CTEClientProjectile,
    CTEDecal,
    CTEDust,
    CTEDynamicLight,
    CTEEffectDispatch,
    CTEEnergySplash,
    CTEExplosion,
    CTEFireBullets,
    CTEFizz,
    CTEFootprintDecal,
    CTEFoundryHelpers,
    CTEGaussExplosion,
    CTEGlowSprite,
    CTEImpact,
    CTEKillPlayerAttachments,
    CTELargeFunnel,
    CTEMetalSparks,
    CTEMuzzleFlash,
    CTEParticleSystem,
    CTEPhysicsProp,
    CTEPlantBomb,
    CTEPlayerAnimEvent,
    CTEPlayerDecal,
    CTEProjectedDecal,
    CTERadioIcon,
    CTEShatterSurface,
    CTEShowLine,
    CTesla,
    CTESmoke,
    CTESparks,
    CTESprite,
    CTESpriteSpray,
    CTest_ProxyToggle_Networkable,
    CTestTraceline,
    CTEWorldDecal,
    CTriggerPlayerMovement,
    CTriggerSoundOperator,
    CVGuiScreen,
    CVoteController,
    CWaterBullet,
    CWaterLODControl,
    CWeaponAug,
    CWeaponAWP,
    CWeaponBaseItem,
    CWeaponBizon,
    CWeaponCSBase,
    CWeaponCSBaseGun,
    CWeaponCycler,
    CWeaponElite,
    CWeaponFamas,
    CWeaponFiveSeven,
    CWeaponG3SG1,
    CWeaponGalil,
    CWeaponGalilAR,
    CWeaponGlock,
    CWeaponHKP2000,
    CWeaponM249,
    CWeaponM3,
    CWeaponM4A1,
    CWeaponMAC10,
    CWeaponMag7,
    CWeaponMP5Navy,
    CWeaponMP7,
    CWeaponMP9,
    CWeaponNegev,
    CWeaponNOVA,
    CWeaponP228,
    CWeaponP250,
    CWeaponP90,
    CWeaponSawedoff,
    CWeaponSCAR20,
    CWeaponScout,
    CWeaponSG550,
    CWeaponSG552,
    CWeaponSG556,
    CWeaponShield,
    CWeaponSSG08,
    CWeaponTaser,
    CWeaponTec9,
    CWeaponTMP,
    CWeaponUMP45,
    CWeaponUSP,
    CWeaponXM1014,
    CWeaponZoneRepulsor,
    CWorld,
    CWorldVguiText,
    DustTrail,
    MovieExplosion,
    ParticleSmokeGrenade,
    RocketTrail,
    SmokeTrail,
    SporeExplosion,
    SporeTrail,
};

enum Bone: int
{
    INVALID = -1,
    BONE_PELVIS = 0,
    LEAN_ROOT,
    CAM_DRIVER,
    BONE_HIP,
    BONE_LOWER_SPINAL_COLUMN,
    BONE_MIDDLE_SPINAL_COLUMN,
    BONE_UPPER_SPINAL_COLUMN,
    BONE_NECK,
    BONE_HEAD,
};

enum Hitbox: int
{
    HITBOX_HEAD,
    HITBOX_NECK,
    HITBOX_PELVIS,
    HITBOX_BODY,
    HITBOX_THORAX,
    HITBOX_CHEST,
    HITBOX_UPPER_CHEST,
    HITBOX_RIGHT_THIGH,
    HITBOX_LEFT_THIGH,
    HITBOX_RIGHT_CALF,
    HITBOX_LEFT_CALF,
    HITBOX_RIGHT_FOOT,
    HITBOX_LEFT_FOOT,
    HITBOX_RIGHT_HAND,
    HITBOX_LEFT_HAND,
    HITBOX_RIGHT_UPPER_ARM,
    HITBOX_RIGHT_FOREARM,
    HITBOX_LEFT_UPPER_ARM,
    HITBOX_LEFT_FOREARM,
    HITBOX_MAX
};

enum HitGroups: int
{
    HITGROUP_GENERIC = 0,
    HITGROUP_HEAD,
    HITGROUP_CHEST,
    HITGROUP_STOMACH,
    HITGROUP_LEFTARM,
    HITGROUP_RIGHTARM,
    HITGROUP_LEFTLEG,
    HITGROUP_RIGHTLEG,
    HITGROUP_GEAR
};

#define FL_ONGROUND                     (1<<0)      // At rest / on the ground
#define FL_DUCKING                      (1<<1)      // Player flag -- Player is fully crouched
#define FL_WATERJUMP                    (1<<2)      // player jumping out of water
#define FL_ONTRAIN                      (1<<3)      // Player is _controlling_ a train, so movement commands should be ignored on client during prediction.
#define FL_INRAIN                       (1<<4)      // Indicates the entity is standing in rain
#define FL_FROZEN                       (1<<5)      // Player is frozen for 3rd person camera
#define FL_ATCONTROLS                   (1<<6)      // Player can't move, but keeps key inputs for controlling another entity
#define FL_CLIENT                       (1<<7)      // Is a player
#define FL_FAKECLIENT                   (1<<8)      // Fake client, simulated server side; don't send network messages to them
// NON-PLAYER SPECIFIC (i.e., not used by GameMovement or the client .dll ) -- Can still be applied to players, though
#define FL_INWATER                      (1<<9)      // In water

#define CONTENTS_EMPTY                  0           // No contents

#define CONTENTS_SOLID                  0x1         // an eye is never valid in a solid
#define CONTENTS_WINDOW                 0x2         // translucent, but not watery (glass)
#define CONTENTS_AUX                    0x4
#define CONTENTS_GRATE                  0x8         // alpha-tested "grate" textures.  Bullets/sight pass through, but solids don't
#define CONTENTS_SLIME                  0x10
#define CONTENTS_WATER                  0x20
#define CONTENTS_BLOCKLOS               0x40        // block AI line of sight
#define CONTENTS_OPAQUE                 0x80        // things that cannot be seen through (may be non-solid though)
#define LAST_VISIBLE_CONTENTS    CONTENTS_OPAQUE

#define ALL_VISIBLE_CONTENTS (LAST_VISIBLE_CONTENTS | (LAST_VISIBLE_CONTENTS-1))

#define CONTENTS_TESTFOGVOLUME          0x100
#define CONTENTS_UNUSED                 0x200

// unused
// NOTE: If it's visible, grab from the top + update LAST_VISIBLE_CONTENTS
// if not visible, then grab from the bottom.
// CONTENTS_OPAQUE + SURF_NODRAW count as CONTENTS_OPAQUE (shadow-casting toolsblocklight textures)
#define CONTENTS_BLOCKLIGHT             0x400

#define CONTENTS_TEAM1                  0x800    // per team contents used to differentiate collisions
#define CONTENTS_TEAM2                  0x1000    // between players and objects on different teams

// ignore CONTENTS_OPAQUE on surfaces that have SURF_NODRAW
#define CONTENTS_IGNORE_NODRAW_OPAQUE   0x2000

// hits entities which are MOVETYPE_PUSH (doors, plats, etc.)
#define CONTENTS_MOVEABLE               0x4000

// remaining contents are non-visible, and don't eat brushes
#define CONTENTS_AREAPORTAL             0x8000

#define CONTENTS_PLAYERCLIP             0x10000
#define CONTENTS_MONSTERCLIP            0x20000

// currents can be added to any other contents, and may be mixed
#define CONTENTS_CURRENT_0              0x40000
#define CONTENTS_CURRENT_90             0x80000
#define CONTENTS_CURRENT_180            0x100000
#define CONTENTS_CURRENT_270            0x200000
#define CONTENTS_CURRENT_UP             0x400000
#define CONTENTS_CURRENT_DOWN           0x800000

#define CONTENTS_ORIGIN                 0x1000000    // removed before bsping an entity

#define CONTENTS_MONSTER                0x2000000    // should never be on a brush, only in game
#define CONTENTS_DEBRIS                 0x4000000
#define CONTENTS_DETAIL                 0x8000000    // brushes to be added after vis leafs
#define CONTENTS_TRANSLUCENT            0x10000000    // auto set if any surface has trans
#define CONTENTS_LADDER                 0x20000000
#define CONTENTS_HITBOX                 0x40000000    // use accurate hitboxes on trace

// These are given to FindMaterial to reference the texture groups that show up on the
#define TEXTURE_GROUP_LIGHTMAP                          xorstr("Lightmaps")
#define TEXTURE_GROUP_WORLD                             xorstr("World textures")
#define TEXTURE_GROUP_MODEL                             xorstr("Model textures")
#define TEXTURE_GROUP_VGUI                              xorstr("VGUI textures")
#define TEXTURE_GROUP_PARTICLE                          xorstr("Particle textures")
#define TEXTURE_GROUP_DECAL                             xorstr("Decal textures")
#define TEXTURE_GROUP_SKYBOX                            xorstr("SkyBox textures")
#define TEXTURE_GROUP_CLIENT_EFFECTS                    xorstr("ClientEffect textures")
#define TEXTURE_GROUP_OTHER                             xorstr("Other textures")
#define TEXTURE_GROUP_PRECACHED                         xorstr("Precached")
#define TEXTURE_GROUP_CUBE_MAP                          xorstr("CubeMap textures")
#define TEXTURE_GROUP_RENDER_TARGET                     xorstr("RenderTargets")
#define TEXTURE_GROUP_UNACCOUNTED                       xorstr("Unaccounted textures")
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER              xorstr("Static Vertex")
#define TEXTURE_GROUP_STATIC_INDEX_BUFFER               xorstr("Static Indices")
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_DISP         xorstr("Displacement Verts")
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_COLOR        xorstr("Lighting Verts")
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_WORLD        xorstr("World Verts")
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_MODELS       xorstr("Model Verts")
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_OTHER        xorstr("Other Verts")
#define TEXTURE_GROUP_DYNAMIC_INDEX_BUFFER              xorstr("Dynamic Indices")
#define TEXTURE_GROUP_DYNAMIC_VERTEX_BUFFER             xorstr("Dynamic Verts")
#define TEXTURE_GROUP_DEPTH_BUFFER                      xorstr("DepthBuffer")
#define TEXTURE_GROUP_VIEW_MODEL                        xorstr("ViewModel")
#define TEXTURE_GROUP_PIXEL_SHADERS                     xorstr("Pixel Shaders")
#define TEXTURE_GROUP_VERTEX_SHADERS                    xorstr("Vertex Shaders")
#define TEXTURE_GROUP_RENDER_TARGET_SURFACE             xorstr("RenderTarget Surfaces")
#define TEXTURE_GROUP_MORPH_TARGETS                     xorstr("Morph Targets")

#define MAXSTUDIOBONES 128
#define BONE_USED_BY_HITBOX 0x100

// NOTE: These are stored in a short in the engine now.  Don't use more than 16 bits
#define SURF_LIGHT          0x0001  // value will hold the light strength
#define SURF_SKY2D          0x0002  // don't draw, indicates we should skylight + draw 2d sky but not draw the 3D skybox
#define SURF_SKY            0x0004  // don't draw, but add to skybox
#define SURF_WARP           0x0008  // turbulent water warp
#define SURF_TRANS          0x0010
#define SURF_NOPORTAL       0x0020    // the surface can not have a portal placed on it
#define SURF_TRIGGER        0x0040    // FIXME: This is an xbox hack to work around elimination of trigger surfaces, which breaks occluders
#define SURF_NODRAW         0x0080    // don't bother referencing the texture

#define SURF_HINT           0x0100    // make a primary bsp splitter

#define SURF_SKIP           0x0200    // completely ignore, allowing non-closed brushes
#define SURF_NOLIGHT        0x0400    // Don't calculate light
#define SURF_BUMPLIGHT      0x0800    // calculate three lightmaps for the surface for bumpmapping
#define SURF_NOSHADOWS      0x1000    // Don't receive shadows
#define SURF_NODECALS       0x2000    // Don't receive decals
#define SURF_NOPAINT        SURF_NODECALS    // the surface can not have paint placed on it
#define SURF_NOCHOP         0x4000    // Don't subdivide patches on this surface
#define SURF_HITBOX         0x8000    // surface is part of a hitbox

#define MASK_ALL                    (0xFFFFFFFF)
// everything that is normally solid
#define MASK_SOLID                    (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_MONSTER|CONTENTS_GRATE)
// everything that blocks player movement
#define MASK_PLAYERSOLID            (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_PLAYERCLIP|CONTENTS_WINDOW|CONTENTS_MONSTER|CONTENTS_GRATE)
// blocks npc movement
#define MASK_NPCSOLID                (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTERCLIP|CONTENTS_WINDOW|CONTENTS_MONSTER|CONTENTS_GRATE)
// blocks fluid movement
#define MASK_NPCFLUID                (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTERCLIP|CONTENTS_WINDOW|CONTENTS_MONSTER)
// water physics in these contents
#define MASK_WATER                    (CONTENTS_WATER|CONTENTS_MOVEABLE|CONTENTS_SLIME)
// everything that blocks lighting
#define MASK_OPAQUE                    (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_OPAQUE)
// everything that blocks lighting, but with monsters added.
#define MASK_OPAQUE_AND_NPCS        (MASK_OPAQUE|CONTENTS_MONSTER)
// everything that blocks line of sight for AI
#define MASK_BLOCKLOS                (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_BLOCKLOS)
// everything that blocks line of sight for AI plus NPCs
#define MASK_BLOCKLOS_AND_NPCS        (MASK_BLOCKLOS|CONTENTS_MONSTER)
// everything that blocks line of sight for players
#define MASK_VISIBLE                    (MASK_OPAQUE|CONTENTS_IGNORE_NODRAW_OPAQUE)
// everything that blocks line of sight for players, but with monsters added.
#define MASK_VISIBLE_AND_NPCS        (MASK_OPAQUE_AND_NPCS|CONTENTS_IGNORE_NODRAW_OPAQUE)
// bullets see these as solid
#define MASK_SHOT                    (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTER|CONTENTS_WINDOW|CONTENTS_DEBRIS|CONTENTS_HITBOX)
// bullets see these as solid, except monsters (world+brush only)
#define MASK_SHOT_BRUSHONLY            (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_DEBRIS)
// non-raycasted weapons see this as solid (includes grates)
#define MASK_SHOT_HULL                (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTER|CONTENTS_WINDOW|CONTENTS_DEBRIS|CONTENTS_GRATE)
// hits solids (not grates) and passes through everything else
#define MASK_SHOT_PORTAL            (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_MONSTER)
// everything normally solid, except monsters (world+brush only)
#define MASK_SOLID_BRUSHONLY        (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_GRATE)
// everything normally solid for player movement, except monsters (world+brush only)
#define MASK_PLAYERSOLID_BRUSHONLY    (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_PLAYERCLIP|CONTENTS_GRATE)
// everything normally solid for npc movement, except monsters (world+brush only)
#define MASK_NPCSOLID_BRUSHONLY        (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_MONSTERCLIP|CONTENTS_GRATE)
// just the world, used for route rebuilding
#define MASK_NPCWORLDSTATIC            (CONTENTS_SOLID|CONTENTS_WINDOW|CONTENTS_MONSTERCLIP|CONTENTS_GRATE)
// just the world, used for route rebuilding
#define MASK_NPCWORLDSTATIC_FLUID    (CONTENTS_SOLID|CONTENTS_WINDOW|CONTENTS_MONSTERCLIP)
// These are things that can split areaportals
#define MASK_SPLITAREAPORTAL        (CONTENTS_WATER|CONTENTS_SLIME)

// UNDONE: This is untested, any moving water
#define MASK_CURRENT                (CONTENTS_CURRENT_0|CONTENTS_CURRENT_90|CONTENTS_CURRENT_180|CONTENTS_CURRENT_270|CONTENTS_CURRENT_UP|CONTENTS_CURRENT_DOWN)

// everything that blocks corpse movement
// UNDONE: Not used yet / may be deleted
#define MASK_DEADSOLID                (CONTENTS_SOLID|CONTENTS_PLAYERCLIP|CONTENTS_WINDOW|CONTENTS_GRATE)

#define SEQUENCE_DEFAULT_DRAW                       0
#define SEQUENCE_DEFAULT_IDLE1                      1
#define SEQUENCE_DEFAULT_IDLE2                      2
#define SEQUENCE_DEFAULT_LIGHT_MISS1                3
#define SEQUENCE_DEFAULT_LIGHT_MISS2                4
#define SEQUENCE_DEFAULT_HEAVY_MISS1                9
#define SEQUENCE_DEFAULT_HEAVY_HIT1                10
#define SEQUENCE_DEFAULT_HEAVY_BACKSTAB            11
#define SEQUENCE_DEFAULT_LOOKAT01                  12

#define SEQUENCE_BUTTERFLY_DRAW                     0
#define SEQUENCE_BUTTERFLY_DRAW2                    1
#define SEQUENCE_BUTTERFLY_LOOKAT01                13
#define SEQUENCE_BUTTERFLY_LOOKAT03                15

#define SEQUENCE_FALCHION_IDLE1                     1
#define SEQUENCE_FALCHION_HEAVY_MISS1               8
#define SEQUENCE_FALCHION_HEAVY_MISS1_NOFLIP        9
#define SEQUENCE_FALCHION_LOOKAT01                 12
#define SEQUENCE_FALCHION_LOOKAT02                 13

#define SEQUENCE_DAGGERS_IDLE1                      1
#define SEQUENCE_DAGGERS_LIGHT_MISS1                2
#define SEQUENCE_DAGGERS_LIGHT_MISS5                6
#define SEQUENCE_DAGGERS_HEAVY_MISS2               11
#define SEQUENCE_DAGGERS_HEAVY_MISS1               12

#define SEQUENCE_BOWIE_IDLE1                        1

#define MAX_SPLITSCREEN_CLIENT_BITS                 2
// this should == MAX_JOYSTICKS in InputEnums.h
#define MAX_SPLITSCREEN_CLIENTS                     ( 1 << MAX_SPLITSCREEN_CLIENT_BITS ) // 4

#define JOYSTICK_BUTTON_INTERNAL( _joystick, _button ) ( JOYSTICK_FIRST_BUTTON + ((_joystick) * JOYSTICK_MAX_BUTTON_COUNT) + (_button) )
#define JOYSTICK_POV_BUTTON_INTERNAL( _joystick, _button ) ( JOYSTICK_FIRST_POV_BUTTON + ((_joystick) * JOYSTICK_POV_BUTTON_COUNT) + (_button) )
#define JOYSTICK_AXIS_BUTTON_INTERNAL( _joystick, _button ) ( JOYSTICK_FIRST_AXIS_BUTTON + ((_joystick) * JOYSTICK_AXIS_BUTTON_COUNT) + (_button) )

#define JOYSTICK_BUTTON( _joystick, _button ) ( (ButtonCode_t)JOYSTICK_BUTTON_INTERNAL( _joystick, _button ) )
#define JOYSTICK_POV_BUTTON( _joystick, _button ) ( (ButtonCode_t)JOYSTICK_POV_BUTTON_INTERNAL( _joystick, _button ) )
#define JOYSTICK_AXIS_BUTTON( _joystick, _button ) ( (ButtonCode_t)JOYSTICK_AXIS_BUTTON_INTERNAL( _joystick, _button ) )

enum
{
    MAX_JOYSTICKS = MAX_SPLITSCREEN_CLIENTS,
    MOUSE_BUTTON_COUNT = 5,
};

enum JoystickAxis_t
{
    JOY_AXIS_X = 0,
    JOY_AXIS_Y,
    JOY_AXIS_Z,
    JOY_AXIS_R,
    JOY_AXIS_U,
    JOY_AXIS_V,
    MAX_JOYSTICK_AXES,
};

enum
{
    JOYSTICK_MAX_BUTTON_COUNT = 32,
    JOYSTICK_POV_BUTTON_COUNT = 4,
    JOYSTICK_AXIS_BUTTON_COUNT = MAX_JOYSTICK_AXES * 2,
};

enum ButtonCode_t
{
    BUTTON_CODE_INVALID = -1,
    BUTTON_CODE_NONE = 0,
    
    KEY_FIRST = 0,
    
    KEY_NONE = KEY_FIRST,
    KEY_0,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_A,
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_E,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,
    KEY_K,
    KEY_L,
    KEY_M,
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,
    KEY_U,
    KEY_V,
    KEY_W,
    KEY_X,
    KEY_Y,
    KEY_Z,
    KEY_PAD_0,
    KEY_PAD_1,
    KEY_PAD_2,
    KEY_PAD_3,
    KEY_PAD_4,
    KEY_PAD_5,
    KEY_PAD_6,
    KEY_PAD_7,
    KEY_PAD_8,
    KEY_PAD_9,
    KEY_PAD_DIVIDE,
    KEY_PAD_MULTIPLY,
    KEY_PAD_MINUS,
    KEY_PAD_PLUS,
    KEY_PAD_ENTER,
    KEY_PAD_DECIMAL,
    KEY_LBRACKET,
    KEY_RBRACKET,
    KEY_SEMICOLON,
    KEY_APOSTROPHE,
    KEY_BACKQUOTE,
    KEY_COMMA,
    KEY_PERIOD,
    KEY_SLASH,
    KEY_BACKSLASH,
    KEY_MINUS,
    KEY_EQUAL,
    KEY_ENTER,
    KEY_SPACE,
    KEY_BACKSPACE,
    KEY_TAB,
    KEY_CAPSLOCK,
    KEY_NUMLOCK,
    KEY_ESCAPE,
    KEY_SCROLLLOCK,
    KEY_INSERT,
    KEY_DELETE,
    KEY_HOME,
    KEY_END,
    KEY_PAGEUP,
    KEY_PAGEDOWN,
    KEY_BREAK,
    KEY_LSHIFT,
    KEY_RSHIFT,
    KEY_LALT,
    KEY_RALT,
    KEY_LCONTROL,
    KEY_RCONTROL,
    KEY_LWIN,
    KEY_RWIN,
    KEY_APP,
    KEY_UP,
    KEY_LEFT,
    KEY_DOWN,
    KEY_RIGHT,
    KEY_F1,
    KEY_F2,
    KEY_F3,
    KEY_F4,
    KEY_F5,
    KEY_F6,
    KEY_F7,
    KEY_F8,
    KEY_F9,
    KEY_F10,
    KEY_F11,
    KEY_F12,
    KEY_CAPSLOCKTOGGLE,
    KEY_NUMLOCKTOGGLE,
    KEY_SCROLLLOCKTOGGLE,
    
    KEY_LAST = KEY_SCROLLLOCKTOGGLE,
    KEY_COUNT = KEY_LAST - KEY_FIRST + 1,
    
    // Mouse
    MOUSE_FIRST = KEY_LAST + 1,
    
    MOUSE_LEFT = MOUSE_FIRST,
    MOUSE_RIGHT,
    MOUSE_MIDDLE,
    MOUSE_4,
    MOUSE_5,
    MOUSE_WHEEL_UP,        // A fake button which is 'pressed' and 'released' when the wheel is moved up
    MOUSE_WHEEL_DOWN,    // A fake button which is 'pressed' and 'released' when the wheel is moved down
    
    MOUSE_LAST = MOUSE_WHEEL_DOWN,
    MOUSE_COUNT = MOUSE_LAST - MOUSE_FIRST + 1,
    
    // Joystick
    JOYSTICK_FIRST = MOUSE_LAST + 1,
    
    JOYSTICK_FIRST_BUTTON = JOYSTICK_FIRST,
    JOYSTICK_LAST_BUTTON = JOYSTICK_BUTTON_INTERNAL( MAX_JOYSTICKS - 1, JOYSTICK_MAX_BUTTON_COUNT - 1 ),
    JOYSTICK_FIRST_POV_BUTTON,
    JOYSTICK_LAST_POV_BUTTON = JOYSTICK_POV_BUTTON_INTERNAL( MAX_JOYSTICKS - 1, JOYSTICK_POV_BUTTON_COUNT - 1 ),
    JOYSTICK_FIRST_AXIS_BUTTON,
    JOYSTICK_LAST_AXIS_BUTTON = JOYSTICK_AXIS_BUTTON_INTERNAL( MAX_JOYSTICKS - 1, JOYSTICK_AXIS_BUTTON_COUNT - 1 ),
    
    JOYSTICK_LAST = JOYSTICK_LAST_AXIS_BUTTON,
    
    BUTTON_CODE_LAST,
    BUTTON_CODE_COUNT = BUTTON_CODE_LAST - KEY_FIRST + 1,
    
    // Helpers for XBox 360
    KEY_XBUTTON_UP = JOYSTICK_FIRST_POV_BUTTON,    // POV buttons
    KEY_XBUTTON_RIGHT,
    KEY_XBUTTON_DOWN,
    KEY_XBUTTON_LEFT,
    
    KEY_XBUTTON_A = JOYSTICK_FIRST_BUTTON,        // Buttons
    KEY_XBUTTON_B,
    KEY_XBUTTON_X,
    KEY_XBUTTON_Y,
    KEY_XBUTTON_LEFT_SHOULDER,
    KEY_XBUTTON_RIGHT_SHOULDER,
    KEY_XBUTTON_BACK,
    KEY_XBUTTON_START,
    KEY_XBUTTON_STICK1,
    KEY_XBUTTON_STICK2,
    KEY_XBUTTON_INACTIVE_START,
    
    KEY_XSTICK1_RIGHT = JOYSTICK_FIRST_AXIS_BUTTON,     // XAXIS POSITIVE
    KEY_XSTICK1_LEFT,                                   // XAXIS NEGATIVE
    KEY_XSTICK1_DOWN,                                   // YAXIS POSITIVE
    KEY_XSTICK1_UP,                                     // YAXIS NEGATIVE
    KEY_XBUTTON_LTRIGGER,                               // ZAXIS POSITIVE
    KEY_XBUTTON_RTRIGGER,                               // ZAXIS NEGATIVE
    KEY_XSTICK2_RIGHT,                                  // UAXIS POSITIVE
    KEY_XSTICK2_LEFT,                                   // UAXIS NEGATIVE
    KEY_XSTICK2_DOWN,                                   // VAXIS POSITIVE
    KEY_XSTICK2_UP,                                     // VAXIS NEGATIVE
};

enum MouseCodeState_t
{
    BUTTON_RELEASED = 0,
    BUTTON_PRESSED,
    BUTTON_DOUBLECLICKED,
};


#define IN_ATTACK       (1 << 0)
#define IN_JUMP         (1 << 1)
#define IN_DUCK         (1 << 2)
#define IN_FORWARD      (1 << 3)
#define IN_BACK         (1 << 4)
#define IN_USE          (1 << 5)
#define IN_CANCEL       (1 << 6)
#define IN_LEFT         (1 << 7)
#define IN_RIGHT        (1 << 8)
#define IN_MOVELEFT     (1 << 9)
#define IN_MOVERIGHT    (1 << 10)
#define IN_ATTACK2      (1 << 11)
#define IN_RUN          (1 << 12)
#define IN_RELOAD       (1 << 13)
#define IN_ALT1         (1 << 14)
#define IN_ALT2         (1 << 15)
#define IN_SCORE        (1 << 16)
#define IN_SPEED        (1 << 17)
#define IN_WALK         (1 << 18)
#define IN_ZOOM         (1 << 19)
#define IN_WEAPON1      (1 << 20)
#define IN_WEAPON2      (1 << 21)
#define IN_BULLRUSH     (1 << 22)
#define IN_GRENADE1     (1 << 23)
#define IN_GRENADE2     (1 << 24)
#define IN_ATTACK3      (1 << 25)



#endif /* Others_h */
