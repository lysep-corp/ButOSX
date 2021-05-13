typedef unsigned long long VPANEL;
typedef unsigned long long HFONT;

#define LIFE_ALIVE 0

class IClientMode {
};

struct CGlowObjectManager;

enum TeamID {
    TEAM_INVALID            = -1,
    TEAM_UNASSIGNED         = 0,
    TEAM_SPECTATOR          = 1,
    TEAM_TERRORIST          = 2,
    TEAM_COUNTER_TERRORIST  = 3
};

enum class FontFeature {
    FONT_FEATURE_ANTIALIASED_FONTS  = 1,
    FONT_FEATURE_DROPSHADOW_FONTS   = 2,
    FONT_FEATURE_OUTLINE_FONTS      = 6
};

enum FontFlags_t {
    FONTFLAG_NONE,
    FONTFLAG_ITALIC             = 0x001,
    FONTFLAG_UNDERLINE          = 0x002,
    FONTFLAG_STRIKEOUT          = 0x004,
    FONTFLAG_SYMBOL             = 0x008,
    FONTFLAG_ANTIALIAS          = 0x010,
    FONTFLAG_GAUSSIANBLUR       = 0x020,
    FONTFLAG_ROTARY             = 0x040,
    FONTFLAG_DROPSHADOW         = 0x080,
    FONTFLAG_ADDITIVE           = 0x100,
    FONTFLAG_OUTLINE            = 0x200,
    FONTFLAG_CUSTOM             = 0x400,     // custom generated font -
                                            // never fall back to asian compatibility mode
    FONTFLAG_BITMAP = 0x800
};
    
enum FontDrawType_t {
    // Use the "additive" value from the scheme file
    FONT_DRAW_DEFAULT       = 0,
    
    // Overrides
    FONT_DRAW_NONADDITIVE,
    FONT_DRAW_ADDITIVE,
    
    FONT_DRAW_TYPE_COUNT    = 2,
};

enum ClientFrameStage_t {
    FRAME_UNDEFINED     =-1,            // (haven't run any frames yet)
    FRAME_START,

    // A network packet is being recieved
    FRAME_NET_UPDATE_START,
    // Data has been received and we're going to start calling PostDataUpdate
    FRAME_NET_UPDATE_POSTDATAUPDATE_START,
    // Data has been received and we've called PostDataUpdate on all data recipients
    FRAME_NET_UPDATE_POSTDATAUPDATE_END,
    // We've received all packets, we can now do interpolation, prediction, etc..
    FRAME_NET_UPDATE_END,

    // We're about to start rendering the scene
    FRAME_RENDER_START,
    // We've finished rendering the scene.
    FRAME_RENDER_END
};
    
enum ObserverMode_t {
    OBS_MODE_NONE = 0,
    OBS_MODE_DEATHCAM = 1,
    OBS_MODE_FREEZECAM = 2,
    OBS_MODE_FIXED = 3,
    OBS_MODE_IN_EYE = 4,
    OBS_MODE_CHASE = 5,
    OBS_MODE_ROAMING = 6
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
    
enum en_class_id
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
    SporeTrail
};
    
enum Bone: int {
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
    
enum Hitbox: int {
    HITBOX_HEAD = 0,
    HITBOX_NECK,
    HITBOX_PELVIS,
    HITBOX_SPINE,
    HITBOX_LEGS,
    HITBOX_ARMS,
};
    
enum HitGroups: int {
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
    
#define MASK_SHOT    (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTER|CONTENTS_WINDOW|CONTENTS_DEBRIS|CONTENTS_HITBOX)
    
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
    
#define MASK_SHOT    (CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTER|CONTENTS_WINDOW|CONTENTS_DEBRIS|CONTENTS_HITBOX)
    
    // NOTE: These are stored in a short in the engine now.  Don't use more than 16 bits
#define SURF_LIGHT        0x0001        // value will hold the light strength
#define SURF_SKY2D        0x0002        // don't draw, indicates we should skylight + draw 2d sky but not draw the 3D skybox
#define SURF_SKY        0x0004        // don't draw, but add to skybox
#define SURF_WARP        0x0008        // turbulent water warp
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
