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

class IClientMode {};
struct CGlowObjectManager;

// Misc functions
typedef bool (*ServerRankRevealAllFn) (float*);
typedef void (*SendClanTagFn) (const char*, const char*);

// Random functions
typedef void  (*RandomSeedFn)(int);
typedef float (*RandomFloatFn)(float, float);
typedef float (*RandomFloatExpFn)(float, float, float);
typedef int   (*RandomIntFn)(int, int);
typedef float (*RandomGaussianFloatFn)(float, float);



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
    FONTFLAG_NONE       = 0,
    FONTFLAG_ITALIC     = 0x1,
    FONTFLAG_UNDERLINE  = 0x2,
    FONTFLAG_STRIKEOUT  = 0x4,
    FONTFLAG_SYMBOL     = 0x8,
    FONTFLAG_ANTIALIAS  = 0x10,
    FONTFLAG_GAUSSIANBLUR   = 0x20,
    FONTFLAG_ROTARY     = 0x40,
    FONTFLAG_DROPSHADOW = 0x80,
    FONTFLAG_ADDITIVE   = 0x100,
    FONTFLAG_OUTLINE    = 0x200,
    FONTFLAG_CUSTOM     = 0x400,
    FONTFLAG_BITMAP     = 0x800,
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

enum ItemDefinitionIndex: int
{
    WEAPON_INVALID      = -1,
    WEAPON_DEAGLE       = 1,
    WEAPON_ELITE        = 2,
    WEAPON_FIVESEVEN    = 3,
    WEAPON_GLOCK        = 4,
    WEAPON_AK47         = 7,
    WEAPON_AUG          = 8,
    WEAPON_AWP          = 9,
    WEAPON_FAMAS        = 10,
    WEAPON_G3SG1        = 11,
    WEAPON_GALILAR      = 13,
    WEAPON_M249         = 14,
    WEAPON_M4A1         = 16,
    WEAPON_MAC10        = 17,
    WEAPON_P90          = 19,
    WEAPON_MP5          = 23,
    WEAPON_UMP45        = 24,
    WEAPON_XM1014       = 25,
    WEAPON_BIZON        = 26,
    WEAPON_MAG7         = 27,
    WEAPON_NEGEV        = 28,
    WEAPON_SAWEDOFF     = 29,
    WEAPON_TEC9 = 30,
    WEAPON_TASER = 31,
    WEAPON_HKP2000 = 32,
    WEAPON_MP7 = 33,
    WEAPON_MP9 = 34,
    WEAPON_NOVA = 35,
    WEAPON_P250 = 36,
    WEAPON_SCAR20 = 38,
    WEAPON_SG556 = 39,
    WEAPON_SSG08 = 40,
    WEAPON_KNIFE = 42,
    WEAPON_FLASHBANG = 43,
    WEAPON_HEGRENADE = 44,
    WEAPON_SMOKEGRENADE = 45,
    WEAPON_MOLOTOV = 46,
    WEAPON_DECOY = 47,
    WEAPON_INCGRENADE = 48,
    WEAPON_C4 = 49,
    WEAPON_KNIFE_T = 59,
    WEAPON_M4A1_SILENCER = 60,
    WEAPON_USP_SILENCER = 61,
    WEAPON_CZ75A = 63,
    WEAPON_REVOLVER = 64,
    WEAPON_KNIFE_BAYONET = 500,
    WEAPON_KNIFE_FLIP = 505,
    WEAPON_KNIFE_GUT = 506,
    WEAPON_KNIFE_KARAMBIT = 507,
    WEAPON_KNIFE_M9_BAYONET = 508,
    WEAPON_KNIFE_TACTICAL = 509,
    WEAPON_KNIFE_FALCHION = 512,
    WEAPON_KNIFE_SURVIVAL_BOWIE = 514,
    WEAPON_KNIFE_BUTTERFLY = 515,
    WEAPON_KNIFE_PUSH = 516,
    GLOVE_STUDDED_BLOODHOUND = 5027,
    GLOVE_T = 5028,
    GLOVE_CT = 5029,
    GLOVE_SPORTY = 5030,
    GLOVE_SLICK = 5031,
    GLOVE_LEATHER_WRAP = 5032,
    GLOVE_MOTORCYCLE = 5033,
    GLOVE_SPECIALIST = 5034,
    GLOVE = GLOVE_T
};



enum EClassIds: int
{
    CAK47 = 1,
    CBaseAnimating = 2,
    CBaseAnimatingOverlay = 3,
    CBaseAttributableItem = 4,
    CBaseButton = 5,
    CBaseCombatCharacter = 6,
    CBaseCombatWeapon = 7,
    CBaseCSGrenade = 8,
    CBaseCSGrenadeProjectile = 9,
    CBaseDoor = 10,
    CBaseEntity = 11,
    CBaseFlex = 12,
    CBaseGrenade = 13,
    CBaseParticleEntity = 14,
    CBasePlayer = 15,
    CBasePropDoor = 16,
    CBaseTeamObjectiveResource = 17,
    CBaseTempEntity = 18,
    CBaseToggle = 19,
    CBaseTrigger = 20,
    CBaseViewModel = 21,
    CBaseVPhysicsTrigger = 22,
    CBaseWeaponWorldModel = 23,
    CBeam = 24,
    CBeamSpotlight = 25,
    CBoneFollower = 26,
    CBreakableProp = 27,
    CBreakableSurface = 28,
    CC4 = 29,
    CCascadeLight = 30,
    CChicken = 31,
    CColorCorrection = 32,
    CColorCorrectionVolume = 33,
    CCSGameRulesProxy = 34,
    CCSPlayer = 35,
    CCSPlayerResource = 36,
    CCSRagdoll = 37,
    CCSTeam = 38,
    CDEagle = 39,
    CDecoyGrenade = 40,
    CDecoyProjectile = 41,
    CDynamicLight = 42,
    CDynamicProp = 43,
    CEconEntity = 44,
    CEconWearable = 45,
    CEmbers = 46,
    CEntityDissolve = 47,
    CEntityFlame = 48,
    CEntityFreezing = 49,
    CEntityParticleTrail = 50,
    CEnvAmbientLight = 51,
    CEnvDetailController = 52,
    CEnvDOFController = 53,
    CEnvParticleScript = 54,
    CEnvProjectedTexture = 55,
    CEnvQuadraticBeam = 56,
    CEnvScreenEffect = 57,
    CEnvScreenOverlay = 58,
    CEnvTonemapController = 59,
    CEnvWind = 60,
    CFEPlayerDecal = 61,
    CFireCrackerBlast = 62,
    CFireSmoke = 63,
    CFireTrail = 64,
    CFish = 65,
    CFlashbang = 66,
    CFogController = 67,
    CFootstepControl = 68,
    CFunc_Dust = 69,
    CFunc_LOD = 70,
    CFuncAreaPortalWindow = 71,
    CFuncBrush = 72,
    CFuncConveyor = 73,
    CFuncLadder = 74,
    CFuncMonitor = 75,
    CFuncMoveLinear = 76,
    CFuncOccluder = 77,
    CFuncReflectiveGlass = 78,
    CFuncRotating = 79,
    CFuncSmokeVolume = 80,
    CFuncTrackTrain = 81,
    CGameRulesProxy = 82,
    CHandleTest = 83,
    CHEGrenade = 84,
    CHostage = 85,
    CHostageCarriableProp = 86,
    CIncendiaryGrenade = 87,
    CInferno = 88,
    CInfoLadderDismount = 89,
    CInfoOverlayAccessor = 90,
    CItem_Healthshot = 91,
    CItemDogtags = 92,
    CKnife = 93,
    CKnifeGG = 94,
    CLightGlow = 95,
    CMaterialModifyControl = 96,
    CMolotovGrenade = 97,
    CMolotovProjectile = 98,
    CMovieDisplay = 99,
    CParticleFire = 100,
    CParticlePerformanceMonitor = 101,
    CParticleSystem = 102,
    CPhysBox = 103,
    CPhysBoxMultiplayer = 104,
    CPhysicsProp = 105,
    CPhysicsPropMultiplayer = 106,
    CPhysMagnet = 107,
    CPlantedC4 = 108,
    CPlasma = 109,
    CPlayerResource = 110,
    CPointCamera = 111,
    CPointCommentaryNode = 112,
    CPointWorldText = 113,
    CPoseController = 114,
    CPostProcessController = 115,
    CPrecipitation = 116,
    CPrecipitationBlocker = 117,
    CPredictedViewModel = 118,
    CProp_Hallucination = 119,
    CPropDoorRotating = 120,
    CPropJeep = 121,
    CPropVehicleDriveable = 122,
    CRagdollManager = 123,
    CRagdollProp = 124,
    CRagdollPropAttached = 125,
    CRopeKeyframe = 126,
    CSCAR17 = 127,
    CSceneEntity = 128,
    CSensorGrenade = 129,
    CSensorGrenadeProjectile = 130,
    CShadowControl = 131,
    CSlideshowDisplay = 132,
    CSmokeGrenade = 133,
    CSmokeGrenadeProjectile = 134,
    CSmokeStack = 135,
    CSpatialEntity = 136,
    CSpotlightEnd = 137,
    CSprite = 138,
    CSpriteOriented = 139,
    CSpriteTrail = 140,
    CStatueProp = 141,
    CSteamJet = 142,
    CSun = 143,
    CSunlightShadowControl = 144,
    CTeam = 145,
    CTeamplayRoundBasedRulesProxy = 146,
    CTEArmorRicochet = 147,
    CTEBaseBeam = 148,
    CTEBeamEntPoint = 149,
    CTEBeamEnts = 150,
    CTEBeamFollow = 151,
    CTEBeamLaser = 152,
    CTEBeamPoints = 153,
    CTEBeamRing = 154,
    CTEBeamRingPoint = 155,
    CTEBeamSpline = 156,
    CTEBloodSprite = 157,
    CTEBloodStream = 158,
    CTEBreakModel = 159,
    CTEBSPDecal = 160,
    CTEBubbles = 161,
    CTEBubbleTrail = 162,
    CTEClientProjectile = 163,
    CTEDecal = 164,
    CTEDust = 165,
    CTEDynamicLight = 166,
    CTEEffectDispatch = 167,
    CTEEnergySplash = 168,
    CTEExplosion = 169,
    CTEFireBullets = 170,
    CTEFizz = 171,
    CTEFootprintDecal = 172,
    CTEFoundryHelpers = 173,
    CTEGaussExplosion = 174,
    CTEGlowSprite = 175,
    CTEImpact = 176,
    CTEKillPlayerAttachments = 177,
    CTELargeFunnel = 178,
    CTEMetalSparks = 179,
    CTEMuzzleFlash = 180,
    CTEParticleSystem = 181,
    CTEPhysicsProp = 182,
    CTEPlantBomb = 183,
    CTEPlayerAnimEvent = 184,
    CTEPlayerDecal = 185,
    CTEProjectedDecal = 186,
    CTERadioIcon = 187,
    CTEShatterSurface = 188,
    CTEShowLine = 189,
    CTesla = 190,
    CTESmoke = 191,
    CTESparks = 192,
    CTESprite = 193,
    CTESpriteSpray = 194,
    CTest_ProxyToggle_Networkable = 194,
    CTestTraceline = 196,
    CTEWorldDecal = 197,
    CTriggerPlayerMovement = 198,
    CTriggerSoundOperator = 199,
    CVGuiScreen = 200,
    CVoteController = 201,
    CWaterBullet = 202,
    CWaterLODControl = 203,
    CWeaponAug = 204,
    CWeaponAWP = 205,
    CWeaponBaseItem = 206,
    CWeaponBizon = 207,
    CWeaponCSBase = 208,
    CWeaponCSBaseGun = 209,
    CWeaponCycler = 210,
    CWeaponElite = 211,
    CWeaponFamas = 212,
    CWeaponFiveSeven = 213,
    CWeaponG3SG1 = 214,
    CWeaponGalil = 215,
    CWeaponGalilAR = 216,
    CWeaponGlock = 217,
    CWeaponHKP2000 = 218,
    CWeaponM249 = 219,
    CWeaponM3 = 220,
    CWeaponM4A1 = 221,
    CWeaponMAC10 = 222,
    CWeaponMag7 = 223,
    CWeaponMP5Navy = 224,
    CWeaponMP7 = 225,
    CWeaponMP9 = 226,
    CWeaponNegev = 227,
    CWeaponNOVA = 228,
    CWeaponP228 = 229,
    CWeaponP250 = 230,
    CWeaponP90 = 231,
    CWeaponSawedoff = 232,
    CWeaponSCAR20 = 233,
    CWeaponScout = 234,
    CWeaponSG550 = 235,
    CWeaponSG552 = 236,
    CWeaponSG556 = 237,
    CWeaponSSG08 = 238,
    CWeaponTaser = 239,
    CWeaponTec9 = 240,
    CWeaponTMP = 241,
    CWeaponUMP45 = 242,
    CWeaponUSP = 243,
    CWeaponXM1014 = 244,
    CWorld = 245,
    DustTrail = 246,
    MovieExplosion = 247,
    ParticleSmokeGrenade = 248,
    RocketTrail = 249,
    SmokeTrail = 250,
    SporeExplosion = 251,
    SporeTrail = 252
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

#define FL_ONGROUND                (1<<0)    // At rest / on the ground
#define FL_DUCKING                (1<<1)    // Player flag -- Player is fully crouched
#define FL_WATERJUMP            (1<<2)    // player jumping out of water
#define FL_ONTRAIN                (1<<3)    // Player is _controlling_ a train, so movement commands should be ignored on client during prediction.
#define FL_INRAIN                (1<<4)    // Indicates the entity is standing in rain
#define FL_FROZEN                (1<<5)    // Player is frozen for 3rd person camera
#define FL_ATCONTROLS            (1<<6)    // Player can't move, but keeps key inputs for controlling another entity
#define FL_CLIENT                (1<<7)    // Is a player
#define FL_FAKECLIENT            (1<<8)    // Fake client, simulated server side; don't send network messages to them
// NON-PLAYER SPECIFIC (i.e., not used by GameMovement or the client .dll ) -- Can still be applied to players, though
#define FL_INWATER                (1<<9)    // In water

#define CONTENTS_EMPTY            0        // No contents

#define CONTENTS_SOLID            0x1        // an eye is never valid in a solid
#define CONTENTS_WINDOW            0x2        // translucent, but not watery (glass)
#define CONTENTS_AUX            0x4
#define CONTENTS_GRATE            0x8        // alpha-tested "grate" textures.  Bullets/sight pass through, but solids don't
#define CONTENTS_SLIME            0x10
#define CONTENTS_WATER            0x20
#define CONTENTS_BLOCKLOS        0x40    // block AI line of sight
#define CONTENTS_OPAQUE            0x80    // things that cannot be seen through (may be non-solid though)
#define LAST_VISIBLE_CONTENTS    CONTENTS_OPAQUE

#define ALL_VISIBLE_CONTENTS (LAST_VISIBLE_CONTENTS | (LAST_VISIBLE_CONTENTS-1))

#define CONTENTS_TESTFOGVOLUME    0x100
#define CONTENTS_UNUSED            0x200

// unused
// NOTE: If it's visible, grab from the top + update LAST_VISIBLE_CONTENTS
// if not visible, then grab from the bottom.
// CONTENTS_OPAQUE + SURF_NODRAW count as CONTENTS_OPAQUE (shadow-casting toolsblocklight textures)
#define CONTENTS_BLOCKLIGHT        0x400

#define CONTENTS_TEAM1            0x800    // per team contents used to differentiate collisions
#define CONTENTS_TEAM2            0x1000    // between players and objects on different teams

// ignore CONTENTS_OPAQUE on surfaces that have SURF_NODRAW
#define CONTENTS_IGNORE_NODRAW_OPAQUE    0x2000

// hits entities which are MOVETYPE_PUSH (doors, plats, etc.)
#define CONTENTS_MOVEABLE        0x4000

// remaining contents are non-visible, and don't eat brushes
#define CONTENTS_AREAPORTAL        0x8000

#define CONTENTS_PLAYERCLIP        0x10000
#define CONTENTS_MONSTERCLIP    0x20000

// currents can be added to any other contents, and may be mixed
#define CONTENTS_CURRENT_0        0x40000
#define CONTENTS_CURRENT_90        0x80000
#define CONTENTS_CURRENT_180    0x100000
#define CONTENTS_CURRENT_270    0x200000
#define CONTENTS_CURRENT_UP        0x400000
#define CONTENTS_CURRENT_DOWN    0x800000

#define CONTENTS_ORIGIN            0x1000000    // removed before bsping an entity

#define CONTENTS_MONSTER        0x2000000    // should never be on a brush, only in game
#define CONTENTS_DEBRIS            0x4000000
#define CONTENTS_DETAIL            0x8000000    // brushes to be added after vis leafs
#define CONTENTS_TRANSLUCENT    0x10000000    // auto set if any surface has trans
#define CONTENTS_LADDER            0x20000000
#define CONTENTS_HITBOX            0x40000000    // use accurate hitboxes on trace

// These are given to FindMaterial to reference the texture groups that show up on the
#define TEXTURE_GROUP_LIGHTMAP                        "Lightmaps"
#define TEXTURE_GROUP_WORLD                            "World textures"
#define TEXTURE_GROUP_MODEL                            "Model textures"
#define TEXTURE_GROUP_VGUI                            "VGUI textures"
#define TEXTURE_GROUP_PARTICLE                        "Particle textures"
#define TEXTURE_GROUP_DECAL                            "Decal textures"
#define TEXTURE_GROUP_SKYBOX                        "SkyBox textures"
#define TEXTURE_GROUP_CLIENT_EFFECTS                "ClientEffect textures"
#define TEXTURE_GROUP_OTHER                            "Other textures"
#define TEXTURE_GROUP_PRECACHED                        "Precached"                // TODO: assign texture groups to the precached materials
#define TEXTURE_GROUP_CUBE_MAP                        "CubeMap textures"
#define TEXTURE_GROUP_RENDER_TARGET                    "RenderTargets"
#define TEXTURE_GROUP_UNACCOUNTED                    "Unaccounted textures"    // Textures that weren't assigned a texture group.
//#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER        "Static Vertex"
#define TEXTURE_GROUP_STATIC_INDEX_BUFFER            "Static Indices"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_DISP        "Displacement Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_COLOR    "Lighting Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_WORLD    "World Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_MODELS    "Model Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_OTHER    "Other Verts"
#define TEXTURE_GROUP_DYNAMIC_INDEX_BUFFER            "Dynamic Indices"
#define TEXTURE_GROUP_DYNAMIC_VERTEX_BUFFER            "Dynamic Verts"
#define TEXTURE_GROUP_DEPTH_BUFFER                    "DepthBuffer"
#define TEXTURE_GROUP_VIEW_MODEL                    "ViewModel"
#define TEXTURE_GROUP_PIXEL_SHADERS                    "Pixel Shaders"
#define TEXTURE_GROUP_VERTEX_SHADERS                "Vertex Shaders"
#define TEXTURE_GROUP_RENDER_TARGET_SURFACE            "RenderTarget Surfaces"
#define TEXTURE_GROUP_MORPH_TARGETS                    "Morph Targets"

#define MAXSTUDIOBONES 128
#define BONE_USED_BY_HITBOX 0x100

// NOTE: These are stored in a short in the engine now.  Don't use more than 16 bits
#define SURF_LIGHT        0x0001  // value will hold the light strength
#define SURF_SKY2D        0x0002  // don't draw, indicates we should skylight + draw 2d sky but not draw the 3D skybox
#define SURF_SKY        0x0004  // don't draw, but add to skybox
#define SURF_WARP        0x0008  // turbulent water warp
#define SURF_TRANS        0x0010
#define SURF_NOPORTAL    0x0020    // the surface can not have a portal placed on it
#define SURF_TRIGGER    0x0040    // FIXME: This is an xbox hack to work around elimination of trigger surfaces, which breaks occluders
#define SURF_NODRAW        0x0080    // don't bother referencing the texture

#define SURF_HINT        0x0100    // make a primary bsp splitter

#define SURF_SKIP        0x0200    // completely ignore, allowing non-closed brushes
#define SURF_NOLIGHT    0x0400    // Don't calculate light
#define SURF_BUMPLIGHT    0x0800    // calculate three lightmaps for the surface for bumpmapping
#define SURF_NOSHADOWS    0x1000    // Don't receive shadows
#define SURF_NODECALS    0x2000    // Don't receive decals
#define SURF_NOPAINT    SURF_NODECALS    // the surface can not have paint placed on it
#define SURF_NOCHOP        0x4000    // Don't subdivide patches on this surface
#define SURF_HITBOX        0x8000    // surface is part of a hitbox

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

#define SEQUENCE_DEFAULT_DRAW                        0
#define SEQUENCE_DEFAULT_IDLE1                        1
#define SEQUENCE_DEFAULT_IDLE2                        2
#define SEQUENCE_DEFAULT_LIGHT_MISS1                3
#define SEQUENCE_DEFAULT_LIGHT_MISS2                4
#define SEQUENCE_DEFAULT_HEAVY_MISS1                9
#define SEQUENCE_DEFAULT_HEAVY_HIT1                    10
#define SEQUENCE_DEFAULT_HEAVY_BACKSTAB                11
#define SEQUENCE_DEFAULT_LOOKAT01                    12

#define SEQUENCE_BUTTERFLY_DRAW                        0
#define SEQUENCE_BUTTERFLY_DRAW2                    1
#define SEQUENCE_BUTTERFLY_LOOKAT01                    13
#define SEQUENCE_BUTTERFLY_LOOKAT03                    15

#define SEQUENCE_FALCHION_IDLE1                        1
#define SEQUENCE_FALCHION_HEAVY_MISS1                8
#define SEQUENCE_FALCHION_HEAVY_MISS1_NOFLIP        9
#define SEQUENCE_FALCHION_LOOKAT01                    12
#define SEQUENCE_FALCHION_LOOKAT02                    13

#define SEQUENCE_DAGGERS_IDLE1                        1
#define SEQUENCE_DAGGERS_LIGHT_MISS1                 2
#define SEQUENCE_DAGGERS_LIGHT_MISS5                 6
#define SEQUENCE_DAGGERS_HEAVY_MISS2                 11
#define SEQUENCE_DAGGERS_HEAVY_MISS1                 12

#define SEQUENCE_BOWIE_IDLE1                         1

#define MAX_SPLITSCREEN_CLIENT_BITS 2
// this should == MAX_JOYSTICKS in InputEnums.h
#define MAX_SPLITSCREEN_CLIENTS    ( 1 << MAX_SPLITSCREEN_CLIENT_BITS ) // 4

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
