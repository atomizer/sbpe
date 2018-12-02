struct ObjectUpdate;
struct MessageHandlers__MessageHandlerBase;
struct AsyncTask;
struct Point;
struct Rectangle;
struct ActiveHitbox;
struct ObjKeyMessage;
struct AnimBoxes;
struct AnimPoint;
struct AnimBoxDescription;
struct AnimPointDescription;
struct VidAnimData;
struct CharacterDescription;
struct ForeignSubWorld;
struct ClientObject;
struct Handler;
struct World;
struct Player;
struct StatBoost;
struct EmitObj;
struct SubWorldImpl;
struct ForeignObject;
struct WorldState_World;
struct CharacterProperties;
struct ItemProperties;
struct ClientWorld;
struct ClientSubWorld;
struct DecorationDescription;
struct CreateSubWorld;
struct DestroySubWorld;
struct CreatePlayer;
struct AccountProperties;
struct RectMessage;
struct CreateLoot;
struct Properties;
struct GeneralUpdate_Create;
struct Action;
struct Shape;
struct AnimationProperties;
struct InteractDescription;
struct PlayerData;
struct DrawMods;
struct Properties_Move;
struct Linear;
struct PointMessage;
struct Properties_Move_Vel;
struct Properties_Move_Waypoint;
struct Elliptical;
struct Properties_Move_Follow;
struct Properties_Move_Lerp;
struct Sinusoidal;
struct Reaction;
struct ItemPurchase;
struct Keys;
struct AnchoredImage;
struct AccountProgress;
struct ObjectUpdate_ModifyProps;
struct PlaySound;
struct ItemObjDescription;
struct CreatedPlatform;
struct WorldState_World_Obj;
struct GeneralUpdate_Damage;
struct GeneralUpdate_Destroy;
struct GeneralUpdate_ScreenShake;
struct GeneralUpdate_ScreenFlash;
struct GeneralUpdate_RunDecorationAnim;
struct GeneralUpdate_CutScene;
struct GeneralUpdate_WorldTitle;
struct Visual;
struct TileSpace;
struct Texture;
struct Animation;
struct Stage;
struct UIElementContainer;
struct TextTexture;
struct MarkupLabel;
struct MarkupLabel__TextureSegment;
struct DialogButton;
struct DropdownSelection;
struct FrameElement;
struct Frame;
struct LabeledInputField;
struct MarkupLabel__TextSegment;
struct VisualElement;
struct LocalStorage;
struct GameClient;
struct WorldClient;
struct ChatLogEntry;
struct TextureLoader__TextureRequest;
struct LoadingScreen;
struct ChatLog;
struct ChatWindow;
struct ChatInput;
struct PerfDisplay;
struct GameDest;
struct Hello;
struct ErrorMessage;
struct TrackEvent;
struct UserLinksMessage;
struct Joined;
struct LoadPVid;
struct ChangeServer;
struct UserLinks;
struct Join;
struct ChatWindow__ChatLine;
struct GameMenuButton;
struct InputKeys;
struct Graph__Data;
struct Graph;
struct SoundMixer__ChannelStatus;
struct ImageMap;
struct UIIDInfo;
struct ImageDefinition;
struct FrameDescription_Element;
struct ImageFileDescription;
struct ImageMapDescription_Mapping;
struct SheetDefinition;
struct Tile;
struct ImageVidDescription;
struct TileVidDescription;
struct TileDescription;
struct AccountWindow;
struct ChangeNameWindow;
struct GeneralResponse;
struct ServerRequestTask;
struct ChangeName;
struct ChangePasswordWindow;
struct ChangePasswordResponse;
struct ChangePassword;
struct ExportAccountWindow;
struct PortAccountResponse;
struct PortAccount;
struct ForgotPasswordWindow;
struct ResetPassword;
struct ImportAccountWindow;
struct LoginWindow;
struct LoginResponse;
struct LoginResponse_Suspension;
struct RegisterWindow;
struct RegisterResponse;
struct Register;
struct DecorationVisualElement;
struct UIBGDecorationDescription_Uniform;
struct UIBGDecorationDescription_Scatter;
struct DecoratedBackground;
struct UIBGDecorationDescription;
struct UIBGDecorationDescription_Scatter_Bounds;
struct FactionRegisterWindow;
struct FactionRegisterDialog;
struct FactionRosterLine;
struct FactionRoster_Member;
struct FactionRosterWindow;
struct WorldOverlay;
struct PlayerWindowExitSprite;
struct FactionRosterDialog;
struct FactionRosterResponse;
struct FactionRoster;
struct KeyRemapPage;
struct Controls;
struct Tabs;
struct KeyRemapLine;
struct GameplayOptions;
struct GraphicsOptions;
struct SoundsOptions;
struct SliderLine;
struct SlotSprite;
struct Uniform;
struct DynamicGraphic;
struct WorldView__Fill;
struct WorldView__Drawable;
struct Tiles;
struct WorldView;
struct HUD;
struct HUDStatus;
struct HUDEquip;
struct InstructionLabel;
struct KeypressLabel;
struct IconStat;
struct NameWindow;
struct StatsWindow;
struct InventoryWindow;
struct StashWindow;
struct FilledRect;
struct StringChooser;
struct Cluster;
struct ProgressWindow;
struct StatLine;
struct ScoreStatLine;
struct CharacterScore_Bonus;
struct CharacterScore;
struct ScoreStatsWindow;
struct XPLevelBars;
struct StatBar;
struct StringChoices;
struct PurchaseButton;
struct UCPurchaseWindow;
struct WorldTitle;
struct KeyVal;
struct TilesDescription;
struct TileMap;
struct Uniform__Layer;
struct DecorationDescription_Uniform_Layer;
struct Grid;
struct DecorationDescription_Scatter;
struct DecorationDescription_Edge;
struct DecorationDescription_Fill;
struct DecorationDescription_Edge_Element;
struct DecorationDescription_Scatter_Bounds;
struct Emote;
struct ShowCharScore;
struct ShowZoneCompleteScore;
struct SFX;
struct Mix_Chunk;
struct CharacterDescription_StartingItem;
struct ObjLocMessage;
struct StringUtil {
  char gap0[1];
};
struct ObjectUpdate {
  void *classptr;
  uint32_t objid;
  int32_t offset;
  struct ObjectUpdate_ModifyProps *modifyprops;
  int32_t t;
  int32_t movetoxmp;
  struct PlaySound *playsound;
  int32_t movetoymp;
  int32_t movetodt;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ObjectUpdate_ModifyProps {
  void *classptr;
  int32_t property;
  int32_t intval;
  struct STDString *messageval;
  struct STDString *stringval;
  bool boolval;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct PlaySound {
  void *classptr;
  struct STDString *soundname;
  int32_t wx;
  int32_t wy;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
enum MessageType {
  MT_INVALID = 0x0,
  MT_HELLO = 0x1,
  MT_FATAL_ERROR = 0x2,
  MT_CONNECT = 0x3,
  MT_LOGIN_RESPONSE = 0x4,
  MT_REGISTER_RESPONSE = 0x5,
  MT_CHANGEPW_RESPONSE = 0x6,
  MT_GENERAL_RESPONSE = 0x7,
  MT_JOINED = 0x8,
  MT_NEW_CLIENT_ID = 0x9,
  MT_CREATE_WORLD = 0xA,
  MT_WORLD_CREATED = 0xB,
  MT_SERVER_DELTA = 0xC,
  MT_SERVER_DELTA_ACK = 0xD,
  MT_PLAYER_INPUT = 0xE,
  MT_TIME_PASSES = 0xF,
  MT_DESCRIBE_ITEM = 0x10,
  MT_DESCRIBE_CHAR = 0x11,
  MT_MODIFY_INV = 0x12,
  MT_PLAYER_TEXT = 0x13,
  MT_CHAT = 0x14,
  MT_LOAD_PVID = 0x15,
  MT_PVID_LOADED = 0x16,
  MT_TRACK_EVENT = 0x17,
  MT_SERVER_SPEC = 0x18,
  MT_SERVER_STATUS = 0x19,
  MT_CHANGE_SERVER = 0x1A,
  MT_USER_MESSAGE = 0x1B,
  MT_PLAYER_EMOTE = 0x1C,
  MT_EMOTE = 0x1D,
  MT_UPDATE_ACCOUNT = 0x1E,
  MT_PORT_RESPONSE = 0x1F,
  MT_INIT_PURCHASE = 0x20,
  MT_FINALIZE_PURCHASE = 0x21,
  MT_ERROR = 0x22,
  MT_SHOW_CHAR_SCORE = 0x23,
  MT_SHOW_ZONE_SCORE = 0x24,
  MT_SERVER_DELTA_MTC = 0x25,
  MT_SERVER_DELTA_GENC = 0x26,
  MT_SOCIAL_CONNECT = 0x27,
  MT_SOCIAL_FULL_STATE = 0x28,
  MT_SOCIAL_DELTA = 0x29,
  MT_SOCIAL_JOIN = 0x2A,
  MT_USER_LINKS = 0x2B,
  MT_FACTION_ACTION = 0x2C,
  MT_GET_FACTION_ROSTER = 0x2D,
  MT_FACTION_ROSTER = 0x2E,
};
enum TerrainType {
  TERRAIN_NONE = 0x0,
  TERRAIN_PLATFORM = 0x1,
  TERRAIN_LEDGE = 0x2,
  TERRAIN_CLIMBWALL = 0x3,
  TERRAIN_LADDER = 0x4,
};
enum BlendMode {
  BLENDMODE_INVALID = 0xFFFFFFFF,
  BLENDMODE_NONE = 0x0,
  BLENDMODE_BLEND = 0x1,
  BLENDMODE_ADD = 0x2,
  BLENDMODE_MOD = 0x4,
};
enum CharacterType {
  CHARACTER_INVALID = 0x0,
  CHARACTER_WILDFIRE = 0x1,
  CHARACTER_DUSKWING = 0x2,
  CHARACTER_IRONCLAD = 0x3,
  CHARACTER_TOASTER = 0x4,
  CHARACTER_FABRICATOR = 0x5,
  CHARACTER_ANCIENT = 0x6,
  NUM_CHARACTER = 0x7,
};
enum DestroyReason {
  DESTROYREASON_INVALID = 0xFFFFFFFF,
  DESTROYREASON_NONE = 0x0,
  DESTROYREASON_INTERNAL = 0x1,
  DESTROYREASON_HITPOINTS = 0x2,
  DESTROYREASON_SHIELD = 0x3,
  DESTROYREASON_DAMAGES = 0x4,
  DESTROYREASON_BLOCKED = 0x5,
  DESTROYREASON_LIFETIME = 0x6,
  DESTROYREASON_CANCEL = 0x7,
};
enum Stat {
  STAT_INVALID = 0x0,
  STAT_HP = 0x1,
  STAT_MAXHP = 0x2,
  STAT_AMMO = 0x3,
  STAT_MAXAMMO = 0x4,
  STAT_MAINSLOT = 0x5,
  STAT_SECSLOT = 0x6,
  STAT_MAXAIRJUMPS = 0x8,
  STAT_DAMAGE = 0x9,
  STAT_ARMOR = 0xA,
  STAT_WALKSPEED = 0xB,
  STAT_JUMPSPEED = 0xC,
  STAT_RANGE = 0xD,
  STAT_PRECISION = 0xE,
  STAT_DEED = 0xF,
  STAT_EC = 0x10,
  STAT_IMPSLOT = 0x11,
  STAT_DAMAGEBONUS = 0x12,
  STAT_CRITCHANCEP = 0x13,
  STAT_CRITMULT = 0x14,
  STAT_MAXAIRDASH = 0x15,
  STAT_KNOCKBACKRESIST = 0x16,
  STAT_CRITCHANCE = 0x17,
  STAT_ITEMCRITCHANCE = 0x18,
  STAT_ITEMCRITMULT = 0x19,
  STAT_UC = 0x1A,
  STAT_AMMOMULT = 0x1B,
  STAT_PENETRATING = 0x20,
  STAT_BOUNCE = 0x21,
  STAT_EXPLOSIVE = 0x22,
  STAT_INCENDIARY = 0x23,
  STAT_NUMSUBS = 0x24,
  STAT_SPEED = 0x25,
  STAT_LIFETIME = 0x26,
  STAT_SEEKING = 0x27,
  STAT_ADMIN_INVUL = 0x28,
  STAT_RADIUS = 0x29,
  STAT_ACCEL = 0x2A,
  STAT_ARMORPIERCE = 0x2B,
  STAT_KEY = 0x2C,
  STAT_SIMULTANEOUS = 0x2D,
  STAT_NUMSECSUBS = 0x2E,
  STAT_BARBED = 0x2F,
  STAT_TRISECTED = 0x30,
  STAT_GRAVITYACCEL = 0x31,
  STAT_LEECH = 0x32,
  STAT_EXTRAHIT = 0x33,
  STAT_REFLECT = 0x34,
  STAT_MOVETIME = 0x35,
  STAT_ITEMARMOR = 0x36,
  STAT_ANIMSPEED = 0x37,
  STAT_SHIELDED = 0x38,
  STAT_COOLDOWN = 0x39,
  STAT_ANCHORIMAGE = 0x3A,
  STAT_CHARSTAT = 0x3B,
  STAT_IMAGEMAP = 0x3C,
  STAT_ACHIEVEMENT = 0x3D,
  STAT_FACTION = 0x3E,
  STAT_USERNAME = 0x3F,
  STAT_TOTALSCORE = 0x40,
  NUM_STAT = 0x41,
};
enum ZoneType {
  ZONE_INVALID = 0xFFFFFFFF,
  ZONE_TUTORIAL = 0x0,
  ZONE_FOREST = 0x1,
  ZONE_CAVE = 0x2,
  ZONE_DUMB = 0x3,
  ZONE_HULK = 0x4,
  ZONE_JUNGLE = 0x5,
  ZONE_LAB = 0x6,
  ZONE_CITY = 0x7,
  ZONE_FOREST_HARD = 0x8,
  ZONE_CAVE_HARD = 0x9,
  ZONE_DUMB_HARD = 0xA,
  ZONE_HULK_HARD = 0xB,
  ZONE_JUNGLE_HARD = 0xC,
  ZONE_LAB_HARD = 0xD,
  ZONE_CITY_HARD = 0xE,
  ZONE_UNKNOWN = 0xF,
  ZONE_MYSTERIOUS = 0x10,
  ZONE_SC = 0x11,
  ZONE_ICE = 0x12,
  ZONE_ICE_HARD = 0x13,
  NUM_ZONE = 0x14,
};
enum BoxType {
  BOX_VUL = 0x0,
  BOX_HIT = 0x1,
  BOX_SHIELD = 0x2,
  NUM_BOX = 0x3,
};
enum PointType {
  POINT_INVALID = 0xFFFFFFFF,
  POINT_EMIT = 0x0,
  POINT_POS = 0x1,
  POINT_AURA = 0x2,
  POINT_ANCHOR_BACK = 0x3,
  POINT_ANCHOR_HEAD = 0x4,
  POINT_ANCHOR_HIP = 0x5,
  NUM_POINT = 0x6,
};
enum ItemBuild {
  ITEMBUILD_INVALID = 0xFFFFFFFF,
  ITEMBUILD_STANDARD = 0x0,
  ITEMBUILD_EXOTIC = 0x1,
};
enum Slot {
  SLOT_INVALID = 0x0,
  SLOT_MAIN = 0x100,
  SLOT_SEC = 0x200,
  SLOT_SPECIAL = 0x300,
  SLOT_BODY = 0x400,
  SLOT_MOB = 0x500,
  SLOT_IMP = 0x600,
  SLOT_INV = 0xF00,
  SLOT_STASH = 0x1000,
  SLOT_REJOIN = 0xFD00,
  SLOT_KEYS = 0xFE00,
  SLOT_HOME = 0xFF00,
};
enum ItemClass {
  ITEMCLASS_INVALID = 0xFFFFFFFF,
  ITEMCLASS_ITEM = 0x0,
  ITEMCLASS_SIMPLEWEAPON = 0x1,
  ITEMCLASS_FLAIL = 0x2,
  ITEMCLASS_GUN = 0x3,
  ITEMCLASS_BOOMERANG = 0x4,
  ITEMCLASS_GRENADE = 0x5,
  ITEMCLASS_HAMMER = 0x6,
  ITEMCLASS_ROCKET = 0x7,
  ITEMCLASS_FLASK = 0x8,
  ITEMCLASS_GROUPHEAL = 0x9,
  ITEMCLASS_DASH = 0xA,
  ITEMCLASS_PINATA = 0xB,
  ITEMCLASS_PLATFORMCREATOR = 0xC,
  ITEMCLASS_HOVERGUN = 0xD,
  ITEMCLASS_DRONEMAKER = 0xE,
  ITEMCLASS_TELEPORTTHROW = 0xF,
  ITEMCLASS_BOMBJUMP = 0x10,
  ITEMCLASS_KICK = 0x11,
  ITEMCLASS_STAR = 0x12,
  ITEMCLASS_SHIELD = 0x13,
  ITEMCLASS_PETCREATOR = 0x14,
  ITEMCLASS_BOOSTER = 0x15,
};
enum GQ {
  GQ_MINIMUM = 0x0,
  GQ_LOW = 0x1,
  GQ_MEDIUM = 0x2,
  GQ_HIGH = 0x3,
  GQ_BEST = 0x4,
};
enum GDV {
  GDV_INVALID = 0xFFFFFFFF,
  GDV_NORMAL = 0x0,
  GDV_HARD = 0x1,
  NUM_GDV = 0x2,
};
enum ChatType {
  CHAT_PLAYER = 0x0,
  CHAT_TELL = 0x1,
  CHAT_ENEMY = 0x2,
  CHAT_ANNOUNCE = 0x3,
  CHAT_IANNOUNCE = 0x4,
  CHAT_ZONEANNOUNCE = 0x5,
  CHAT_ERROR = 0x6,
  CHAT_ADMIN = 0x7,
  CHAT_FRIEND = 0x8,
  CHAT_FACTION = 0x9,
};
enum EmoteType {
  EMOTE_INVALID = 0xFFFFFFFF,
  EMOTE_HEART = 0x0,
  EMOTE_HELP = 0x1,
  EMOTE_HP = 0x2,
  EMOTE_TREASURE = 0x3,
  EMOTE_RIP = 0x4,
  EMOTE_HAPPY = 0x5,
  EMOTE_SAD = 0x6,
  EMOTE_FOLLOW = 0x7,
  EMOTE_GOODJOB = 0x8,
  EMOTE_THANKS = 0x9,
  NUM_EMOTE = 0xA,
};
enum CurrencyType {
  CURRENCY_INVALID = 0xFFFFFFFF,
  CURRENCY_EC = 0x0,
  CURRENCY_UC = 0x1,
};
enum PurchaseId {
  PURCHASE_INVALID = 0x0,
  PURCHASE_5USD = 0x1,
  PURCHASE_10USD = 0x2,
  PURCHASE_20USD = 0x3,
  PURCHASE_50USD = 0x4,
  NUM_PURCHASE = 0x5,
};
enum FactionRank {
  FACTIONRANK_OWNER = 0x64,
  FACTIONRANK_OFFICER = 0x32,
  FACTIONRANK_MEMBER = 0x0,
};
enum Pose {
  POSE_INVALID = 0x0,
  POSE_AIR = 0x1,
  POSE_FLY_HORIZ = 0x2,
  POSE_FLY_VERT = 0x3,
  POSE_STAND = 0x4,
  POSE_WALK = 0x5,
  POSE_RUN = 0x6,
  POSE_CROUCH = 0x7,
  POSE_HOLD = 0x8,
  POSE_CLIMB_HORIZ = 0x9,
  POSE_CLIMB_VERT = 0xA,
  NUM_POSE = 0xB,
};
enum PoseV {
  POSEV_NORMAL = 0x0,
  POSEV_UP = 0x1,
  POSEV_DOWN = 0x2,
};
enum Anim {
  ANIM_INVALID = 0x0,
  ANIM_HIT = 0x1,
  ANIM_SHOOT = 0x2,
  ANIM_SHOOT2 = 0x3,
  ANIM_SHOOT3 = 0x4,
  ANIM_SHOOT4 = 0x5,
  ANIM_SHOOT5 = 0x6,
  ANIM_FIRE = 0x7,
  ANIM_FIRE2 = 0x8,
  ANIM_FIRE3 = 0x9,
  ANIM_FIRE4 = 0xA,
  ANIM_FIRE5 = 0xB,
  ANIM_LAUNCH = 0xC,
  ANIM_LAUNCH2 = 0xD,
  ANIM_LAUNCH3 = 0xE,
  ANIM_LAUNCH4 = 0xF,
  ANIM_LAUNCH5 = 0x10,
  ANIM_SLASH = 0x11,
  ANIM_SLASH2 = 0x12,
  ANIM_SLASH3 = 0x13,
  ANIM_SLASH4 = 0x14,
  ANIM_SLASH5 = 0x15,
  ANIM_SWING = 0x16,
  ANIM_SWING2 = 0x17,
  ANIM_SWING3 = 0x18,
  ANIM_SWING4 = 0x19,
  ANIM_SWING5 = 0x1A,
  ANIM_THROW = 0x1B,
  ANIM_THROW2 = 0x1C,
  ANIM_THROW3 = 0x1D,
  ANIM_THROW4 = 0x1E,
  ANIM_THROW5 = 0x1F,
  ANIM_LOB = 0x20,
  ANIM_LOB2 = 0x21,
  ANIM_LOB3 = 0x22,
  ANIM_LOB4 = 0x23,
  ANIM_LOB5 = 0x24,
  ANIM_TOSS = 0x25,
  ANIM_TOSS2 = 0x26,
  ANIM_TOSS3 = 0x27,
  ANIM_TOSS4 = 0x28,
  ANIM_TOSS5 = 0x29,
  ANIM_DROP = 0x2A,
  ANIM_DROP2 = 0x2B,
  ANIM_DROP3 = 0x2C,
  ANIM_DROP4 = 0x2D,
  ANIM_DROP5 = 0x2E,
  ANIM_STEP = 0x2F,
  ANIM_STEP2 = 0x30,
  ANIM_STEP3 = 0x31,
  ANIM_STEP4 = 0x32,
  ANIM_STEP5 = 0x33,
  ANIM_TURN = 0x34,
  ANIM_TURNL = 0x35,
  ANIM_TURNR = 0x36,
  ANIM_INTERACT = 0x37,
  ANIM_INTERACT2 = 0x38,
  ANIM_INTERACT3 = 0x39,
  ANIM_INTERACT4 = 0x3A,
  ANIM_INTERACT5 = 0x3B,
  ANIM_DESTROY = 0x3C,
  ANIM_DESTROY_INTERNAL = 0x3D,
  ANIM_DESTROY_HITPOINTS = 0x3E,
  ANIM_DESTROY_SHIELD = 0x3F,
  ANIM_DESTROY_DAMAGES = 0x40,
  ANIM_DESTROY_BLOCKED = 0x41,
  ANIM_DESTROY_LIFETIME = 0x42,
  ANIM_DAMAGE = 0x43,
  ANIM_READY = 0x44,
  ANIM_SPECIAL = 0x45,
  ANIM_CREATE = 0x46,
  ANIM_SUMMON = 0x47,
  ANIM_SUMMON2 = 0x48,
  ANIM_SUMMON3 = 0x49,
  ANIM_SUMMON4 = 0x4A,
  ANIM_SUMMON5 = 0x4B,
  ANIM_SPECIALUP = 0x4C,
  ANIM_SPECIALDOWN = 0x4D,
  ANIM_USED = 0x4E,
  ANIM_SPECIALSTART = 0x4F,
  ANIM_SPECIALEND = 0x50,
  ANIM_SPECIALHIT = 0x51,
  ANIM_SLOT = 0x52,
  NUM_ANIM = 0x53,
};
enum ShapeType {
  SHAPE_RECT = 0x0,
  SHAPE_LR_TRI = 0x1,
  SHAPE_LL_TRI = 0x2,
  SHAPE_UL_TRI = 0x3,
  SHAPE_UR_TRI = 0x4,
  NUM_SHAPE = 0x5,
};
enum BlockType {
  BLOCK_NONE = 0x0,
  BLOCK_MOVE_ALL = 0x1,
  BLOCK_MOVE_PLATFORM = 0x2,
  BLOCK_REMOVE_ALL = 0x3,
  BLOCK_REMOVE_PLATFORM = 0x4,
};
enum OwnerType {
  OWNERTYPE_NONE = 0x0,
  OWNERTYPE_PLAYER = 0x1,
  OWNERTYPE_ENEMY = 0x2,
};
enum InteractType {
  INTERACTTYPE_INTERACT = 0x0,
  INTERACTTYPE_ITEM = 0x1,
  INTERACTTYPE_CHARACTER = 0x2,
  INTERACTTYPE_GATE = 0x3,
  INTERACTTYPE_OPEN_DOOR = 0x4,
  INTERACTTYPE_OPEN_CHEST = 0x5,
  INTERACTTYPE_TELEPORT = 0x6,
  INTERACTTYPE_PURCHASE = 0x7,
  INTERACTTYPE_RETRIEVE = 0x8,
  INTERACTTYPE_DEPOSIT = 0x9,
  INTERACTTYPE_STASH = 0xA,
  INTERACTTYPE_CHARSLOT = 0xB,
  INTERACTTYPE_ENTER = 0xC,
};
enum ForeignClass {
  FOREIGNCLASS_BASE = 0x0,
  FOREIGNCLASS_BODYDISPENSER = 0x1,
  FOREIGNCLASS_STASH = 0x2,
  FOREIGNCLASS_STASHEDITEM = 0x3,
  FOREIGNCLASS_CHARSLOT = 0x4,
  FOREIGNCLASS_SLOTTEDCHAR = 0x5,
};
enum ScoreBonus {
  SCOREBONUS_STATS = 0x1,
  SCOREBONUS_GEAR = 0x2,
  SCOREBONUS_ALL_MISSION = 0x3,
  SCOREBONUS_ALL_ELITE_MISSION = 0x4,
  SCOREBONUS_NO_HEALTH = 0x20,
  SCOREBONUS_NO_AMMO = 0x21,
  SCOREBONUS_NO_CHESTOPEN = 0x22,
  SCOREBONUS_NO_STATBOOST = 0x23,
  SCOREBONUS_NO_MAIN = 0x24,
  SCOREBONUS_NO_SECONDARY = 0x25,
  SCOREBONUS_NO_SPECIAL = 0x26,
  SCOREBONUS_NO_HOME = 0x27,
  SCOREBONUS_NO_BODY = 0x28,
  SCOREBONUS_NO_MOBILITY = 0x29,
};
enum CharacterState {
  CS_ALIVE = 0x0,
  CS_DEAD = 0x1,
  CS_DELETED = 0x2,
};
enum ModifyInvCommand {
  MODINV_INVALID = 0x0,
  MODINV_DROP = 0x1,
  MODINV_MOVE = 0x2,
};
struct GeneralUpdate {
  void *classptr;
  int32_t offset;
  int32_t t;
  struct GeneralUpdate_Create *create;
  struct GeneralUpdate_Damage *damage;
  struct GeneralUpdate_Destroy *destroy;
  struct PlaySound *playsound;
  struct GeneralUpdate_ScreenShake *screenshake;
  struct GeneralUpdate_ScreenFlash *screenflash;
  struct GeneralUpdate_RunDecorationAnim *rundecorationanim;
  struct GeneralUpdate_CutScene *cutscene;
  struct GeneralUpdate_WorldTitle *worldtitle;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct GeneralUpdate_Create {
  void *classptr;
  struct Properties *props;
  uint32_t objid;
  uint32_t creatorid;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct GeneralUpdate_Damage {
  void *classptr;
  uint32_t ownerid;
  uint32_t objid;
  int32_t val;
  bool iscrit;
  bool armormitigated;
  int32_t x;
  int32_t y;
  struct STDString *damagefxvid;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct GeneralUpdate_Destroy {
  void *classptr;
  uint32_t ownerid;
  uint32_t objid;
  uint32_t reason;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct GeneralUpdate_ScreenShake {
  void *classptr;
  int32_t magnitude;
  int32_t duration;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct GeneralUpdate_ScreenFlash {
  void *classptr;
  int32_t start;
  int32_t hold;
  int32_t end;
  uint32_t color;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct GeneralUpdate_RunDecorationAnim {
  void *classptr;
  struct STDString *name;
  uint32_t anim;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct GeneralUpdate_CutScene {
  void *classptr;
  struct STDString *vid;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct GeneralUpdate_WorldTitle {
  void *classptr;
  struct STDString *title;
  int32_t x;
  int32_t y;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct Properties {
  void *classptr;
  int32_t xmp;
  int32_t ymp;
  int32_t wmp;
  int32_t hmp;
  int32_t z;
  uint32_t shapetype;
  int32_t facing;
  int32_t lifetime;
  uint32_t blocktype;
  uint32_t ownertype;
  int32_t damage;
  int32_t hitboxdamage;
  int32_t hitpoints;
  int32_t maxhitpoints;
  int32_t removetype;
  uint32_t terraintype;
  struct InteractDescription *interactdescription;
  int32_t interact;
  int32_t trigger;
  struct STDString *displayname;
  struct PlayerData *playerdata;
  bool draw;
  bool decorate;
  bool isinternal;
  bool invulnerable;
  int32_t armor;
  int32_t armorpierce;
  bool knockback;
  bool boundsworld;
  bool isshield;
  bool noleech;
  int32_t recommend;
  uint32_t activateworldid;
  uint32_t foreignclass;
  int32_t killachievement;
  struct STDString *vid;
  struct DrawMods *drawmods;
  bool spawn;
  bool rotate;
  uint32_t pose;
  int32_t posetime;
  uint32_t prevpose;
  struct AnimationProperties *animprops;
  struct STDString *movetrail;
  struct STDString *destroyvid;
  struct STDString *soundprefix;
  struct Properties_Move *move;
  struct Reaction *interactreaction;
  struct Reaction *triggerreaction;
  int32_t _cached_size;
  uint32_t _has_bits[2];
};
struct InteractDescription {
  void *classptr;
  uint32_t type;
  uint32_t chartype;
  struct STDString *gatename;
  uint32_t requireddeed;
  int32_t requiredlevel;
  int32_t requiredplayertype;
  int32_t mk;
  int32_t numused;
  bool noblink;
  int32_t totaluses;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct PlayerData {
  void *classptr;
  struct STDString *accountid;
  struct STDString *factionname;
  int32_t level;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct DrawMods {
  void *classptr;
  struct RepeatedPtrField imagemap; // std::basic_string<char,std::char_traits<char>,std::allocator<char> > 
  struct RepeatedPtrField anchoredimage; // AnchoredImage
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct AnimationProperties {
  void *classptr;
  int32_t animid;
  int32_t pos;
  int32_t time;
  bool loop;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct Properties_Move {
  void *classptr;
  struct ObjKeyMessage *relativeto;
  struct Linear *to;
  struct Properties_Move_Vel *vel;
  struct Properties_Move_Waypoint *waypoint;
  struct Elliptical *elliptical;
  struct Properties_Move_Follow *follow;
  struct Properties_Move_Lerp *lerp;
  struct Sinusoidal *sin;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct Reaction {
  void *classptr;
  struct STDString *sound;
  struct ObjKeyMessage *teleport;
  struct ItemPurchase *itempurchase;
  uint32_t keyuse;
  int32_t openstash;
  int32_t switchcharslot;
  int32_t stashitempos;
  bool openucwindow;
  bool openfactionregistrar;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ObjKeyMessage {
  void *classptr;
  uint32_t worldid;
  uint32_t objid;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct Linear {
  void *classptr;
  int32_t xmp;
  int32_t ymp;
  int32_t pos;
  int32_t dt;
  struct PointMessage *start;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct Properties_Move_Vel {
  void *classptr;
  int32_t xvel;
  int32_t yvel;
  int32_t xaccel;
  int32_t yaccel;
  int32_t minxvel;
  int32_t minyvel;
  int32_t maxxvel;
  int32_t maxyvel;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct Properties_Move_Waypoint {
  void *classptr;
  struct RepeatedPtrField points; // Linear
  bool loop;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct Elliptical {
  void *classptr;
  int32_t xmp;
  int32_t ymp;
  int32_t radiusamp;
  int32_t radiusbmp;
  int32_t angle;
  int32_t period;
  int32_t pos;
  int32_t dt;
  int32_t ravel;
  int32_t rbvel;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct Properties_Move_Follow {
  void *classptr;
  int32_t maxdist;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct Properties_Move_Lerp {
  void *classptr;
  struct ObjKeyMessage *target;
  int32_t percentage;
  bool center;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct Sinusoidal {
  void *classptr;
  int32_t xmp;
  int32_t ymp;
  int32_t vel;
  int32_t period;
  int32_t offset;
  int32_t amp;
  int32_t angle;
  int32_t pos;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ItemPurchase {
  void *classptr;
  int32_t price;
  uint32_t currency;
  struct ItemProperties *itemprops;
  uint32_t stashid;
  uint32_t charslotid;
  bool issecret;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct PointMessage {
  void *classptr;
  int32_t xmp;
  int32_t ymp;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ItemProperties {
  void *classptr;
  int32_t type;
  int32_t slotpos;
  struct RepeatedPtrField statboosts; // StatBoost
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct WorldUpdate {
  void *classptr;
  uint32_t worldid;
  int32_t dt;
  struct RepeatedPtrField generalupdates; // GeneralUpdate
  struct RepeatedPtrField objectupdates; // ObjectUpdate
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct Delta {
  void *classptr;
  struct CreateSubWorld *createsubworld;
  struct DestroySubWorld *destroysubworld;
  struct WorldUpdate *worldupdate;
  struct CreatePlayer *createplayer;
  struct CreateLoot *createloot;
  struct StatBoost *statboost;
  bool staterequested;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct CreateSubWorld {
  void *classptr;
  uint32_t worldid;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct DestroySubWorld {
  void *classptr;
  uint32_t worldid;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct CreatePlayer {
  void *classptr;
  struct STDString *accountid;
  struct AccountProperties *accountprops;
  struct CharacterProperties *charprops;
  struct STDString *username;
  int32_t playertype;
  bool teleport;
  bool admininvul;
  struct RectMessage *pos;
  struct RepeatedPtrField slottedcharprops; // CharacterProperties
  struct STDString *factionname;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct CreateLoot {
  void *classptr;
  struct Properties *props;
  struct RepeatedPtrField itemprops; // ItemProperties
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct StatBoost {
  void *classptr;
  uint32_t stat;
  int32_t val;
  int32_t level;
  bool increment;
  struct STDString *subtypestr;
  int32_t subtype;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct AccountProperties {
  void *classptr;
  struct RepeatedPtrField totalstats; // CharStatMessage
  struct AccountProgress *progress;
  int32_t ec;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct CharacterProperties {
  void *classptr;
  uint32_t charid;
  uint32_t type;
  int32_t charslotid;
  int32_t hitpoints;
  int32_t maxhitpoints;
  int32_t ammo;
  int32_t maxammo;
  int32_t damagebonus;
  int32_t armor;
  int32_t walkspeed;
  int32_t jumpspeed;
  int32_t critchance;
  int32_t critmult;
  int32_t mainslots;
  int32_t secslots;
  int32_t impslots;
  struct STDString *imagemap;
  struct RepeatedPtrField items; // ItemProperties
  int32_t invslots;
  uint32_t state;
  struct RepeatedPtrField stats; // CharStatMessage
  struct CharacterScore *score;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct RectMessage {
  void *classptr;
  int32_t xmp;
  int32_t ymp;
  int32_t wmp;
  int32_t hmp;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct AccountProgress {
  void *classptr;
  struct RepeatedPtrField keys; // Keys
  uint32_t deeds;
  uint32_t numstash;
  struct RepeatedPtrField stash; // ItemProperties
  uint32_t numcharslots;
  int32_t uc;
  struct RepeatedPtrField beststats; // CharStatMessage
  int32_t totalscore;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct CharacterScore {
  void *classptr;
  struct RepeatedField_int beststat;
  int32_t basescore;
  int32_t finalscore;
  struct RepeatedPtrField bonuses; // CharacterScore_Bonus
  int32_t prevtotalscore;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
enum GameServiceType {
  GAMESERVICE_INVALID = 0xFFFFFFFF,
  GAMESERVICE_NAKED = 0x0,
  GAMESERVICE_STEAM = 0x1,
};
struct MessageHandlers__MessageHandlerBase {
  void *classptr;
};
struct AsyncTask {
  void *classptr;
};
struct MessageHandlers {
  struct STDUMap handlers; // MessageType,MessageHandlers::MessageHandlerBase*,std::hash<int>,std::equal_to<MessageType>,std::allocator<std::pair<const MessageType,MessageHandlers::MessageHandlerBase*> > 
};
struct MessageHandlers__DataHandler {
  struct MessageHandlers__MessageHandlerBase asMessageHandlers__MessageHandlerBase;
  struct STDFunction func; // void(MessageType,char const*,int)
};
struct AsyncRun {
  char gap0[1];
};
struct ServerLoc {
  struct STDString hostname;
  unsigned short rawSocketPort;
  unsigned short webSocketPort;
};
struct ServerLocMessage {
  void *classptr;
  struct STDString *hostname;
  int32_t rawsocketport;
  int32_t websocketport;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
enum PlatformType {
  PLATFORM_UNKNOWN = 0x0,
  PLATFORM_WEB = 0x1,
  PLATFORM_PC_CLIENT = 0x2,
  PLATFORM_MAC_CLIENT = 0x3,
  PLATFORM_LINUX_CLIENT = 0x4,
};
struct FileUtil {
  char gap0[1];
};
struct Point {
  int x;
  int y;
};
struct Rectangle {
  int x;
  int y;
  int w;
  int h;
};
struct Geometry {
  char gap0[1];
};
struct MathUtil {
  char gap0[1];
};
struct NetworkUtil {
  char gap0[1];
};
struct PRNG {
  uint32_t w;
  uint32_t x;
  uint32_t y;
  uint32_t z;
};
struct TimeUtil {
  char gap0[1];
};
struct BI_CTX {
  void *active_list; // _bigint
  void *free_list; // _bigint
  void *bi_radix; // _bigint
  void *bi_mod[3]; // _bigint
  void *bi_mu[3]; // _bigint
  void *bi_normalised_mod[3]; // _bigint
  void **g; // _bigint
  int window;
  int active_count;
  int free_count;
  uint8_t mod_offset;
};
struct RSAEncrypt {
  void *m; // _bigint
  void *e; // _bigint
  int numOctets;
  struct BI_CTX *biCtx;
};
struct Series {
  size_t maxValues;
  struct STDDeque values; // int,std::allocator<int> 
  int sum;
};
struct Timer {
  int startTime;
  int totalTime;
};
struct ScopeTimer {
  struct STDString name;
  int startTime;
};
enum ScoreRank {
  SCORE_RANK_INVALID = 0x0,
  SCORE_RANK_C = 0x1,
  SCORE_RANK_B = 0x2,
  SCORE_RANK_A = 0x3,
  SCORE_RANK_S = 0x4,
  NUM_SCORE_RANK = 0x5,
};
enum Achievement {
  ACHIEVEMENT_INVALID = 0x0,
  ACHIEVEMENT_BRINK_COMPLETE = 0x1,
  ACHIEVEMENT_FOREST_COMPLETE = 0x2,
  ACHIEVEMENT_CAVE_COMPLETE = 0x3,
  ACHIEVEMENT_CITY_COMPLETE = 0x4,
  ACHIEVEMENT_DUMB_COMPLETE = 0x5,
  ACHIEVEMENT_JUNGLE_COMPLETE = 0x6,
  ACHIEVEMENT_HULK_COMPLETE = 0x7,
  ACHIEVEMENT_LAB_COMPLETE = 0x8,
  ACHIEVEMENT_SC_COMPLETE = 0x9,
  ACHIEVEMENT_EFOREST_COMPLETE = 0xA,
  ACHIEVEMENT_ECAVE_COMPLETE = 0xB,
  ACHIEVEMENT_ECITY_COMPLETE = 0xC,
  ACHIEVEMENT_EDUMB_COMPLETE = 0xD,
  ACHIEVEMENT_EJUNGLE_COMPLETE = 0xE,
  ACHIEVEMENT_EHULK_COMPLETE = 0xF,
  ACHIEVEMENT_ELAB_COMPLETE = 0x10,
  ACHIEVEMENT_1000_KILLS = 0x11,
  ACHIEVEMENT_20000_KILLS = 0x12,
  ACHIEVEMENT_1000000_DAMAGE_DEALT = 0x13,
  ACHIEVEMENT_WILDFIRE_ALL_MISSIONS = 0x14,
  ACHIEVEMENT_DUSKWING_ALL_MISSIONS = 0x15,
  ACHIEVEMENT_IRONCLAD_ALL_MISSIONS = 0x16,
  ACHIEVEMENT_FABRICATOR_ALL_MISSIONS = 0x17,
  ACHIEVEMENT_REGISTERED = 0x18,
  ACHIEVEMENT_10_CALLOUTS = 0x19,
  ACHIEVEMENT_100_CALLOUTS = 0x1A,
  ACHIEVEMENT_MK_2_ACHIEVED = 0x1B,
  ACHIEVEMENT_MK_3_ACHIEVED = 0x1C,
  ACHIEVEMENT_MK_4_ACHIEVED = 0x1D,
  ACHIEVEMENT_MK_5_ACHIEVED = 0x1E,
  ACHIEVEMENT_MK_6_ACHIEVED = 0x1F,
  ACHIEVEMENT_20_MIDBOSSES = 0x20,
  ACHIEVEMENT_100_MIDBOSSES = 0x21,
  ACHIEVEMENT_KILLED_BY_FOREST_SPIKES = 0x22,
  ACHIEVEMENT_KILLED_BY_WORM_MOUTH = 0x23,
  ACHIEVEMENT_KILLED_BY_GOLDTOOTH = 0x24,
  ACHIEVEMENT_KILLED_BY_FALL_IN_JUNGLE = 0x25,
  ACHIEVEMENT_KILLED_BY_SWEEPER = 0x26,
  ACHIEVEMENT_KILLED_BY_SCAVENGER_TAIL = 0x27,
  ACHIEVEMENT_KILLED_BY_STONEHEAD = 0x28,
  ACHIEVEMENT_PROTOTYPE_FOUND = 0x29,
  ACHIEVEMENT_CLOSE_CALL = 0x2A,
  ACHIEVEMENT_DIED = 0x2B,
  ACHIEVEMENT_ALL_CUSTOM = 0x2C,
  ACHIEVEMENT_ALL_EXPERIMENTAL = 0x2D,
  ACHIEVEMENT_ALL_PROTOTYPE = 0x2E,
  ACHIEVEMENT_PURCHASE_AT_SECRET_SHOP = 0x2F,
  ACHIEVEMENT_BLOCKED_1000_BULLETS = 0x30,
  ACHIEVEMENT_BLOCKED_100000_BULLETS = 0x31,
  ACHIEVEMENT_100_BOOSTS_COLLECTED = 0x32,
  ACHIEVEMENT_10000_BOOSTS_COLLECTED = 0x33,
  ACHIEVEMENT_100_ALLY_LOST = 0x34,
  ACHIEVEMENT_10000_ALLY_LOST = 0x35,
  ACHIEVEMENT_100_ALLY_MKUP = 0x36,
  ACHIEVEMENT_10000_ALLY_MKUP = 0x37,
  ACHIEVEMENT_20_ALLY_NEW_MISSION_COMPLETE = 0x38,
  ACHIEVEMENT_1000_ALLY_NEW_MISSION_COMPLETE = 0x39,
  ACHIEVEMENT_SPARK_OPEN_BOSS_CHEST = 0x3A,
  ACHIEVEMENT_REACH_DUMB_WAVE_50 = 0x3B,
  ACHIEVEMENT_REACH_EDUMB_WAVE_50 = 0x3C,
  ACHIEVEMENT_FIND_FOREST_SECRET = 0x3D,
  ACHIEVEMENT_FIND_CAVE_SECRET = 0x3E,
  ACHIEVEMENT_FIND_CITY_SECRET = 0x3F,
  ACHIEVEMENT_FIND_DUMB_SECRET = 0x40,
  ACHIEVEMENT_FIND_JUNGLE_SECRET = 0x41,
  ACHIEVEMENT_FIND_HULK_SECRET = 0x42,
  ACHIEVEMENT_FIND_LAB_SECRET = 0x43,
  ACHIEVEMENT_FIND_BES = 0x44,
  ACHIEVEMENT_FIND_HORUS = 0x45,
  ACHIEVEMENT_FIND_PTAH = 0x46,
  ACHIEVEMENT_FIND_SET = 0x47,
  ACHIEVEMENT_FIND_THOTH = 0x48,
  ACHIEVEMENT_FIND_SHU = 0x49,
  ACHIEVEMENT_A_RANK_WILDFIRE = 0x4A,
  ACHIEVEMENT_S_RANK_WILDFIRE = 0x4B,
  ACHIEVEMENT_A_RANK_DUSKWING = 0x4C,
  ACHIEVEMENT_S_RANK_DUSKWING = 0x4D,
  ACHIEVEMENT_A_RANK_IRONCLAD = 0x4E,
  ACHIEVEMENT_S_RANK_IRONCLAD = 0x4F,
  ACHIEVEMENT_A_RANK_FABRICATOR = 0x50,
  ACHIEVEMENT_S_RANK_FABRICATOR = 0x51,
  ACHIEVEMENT_VANITY_ITEM = 0x52,
  ACHIEVEMENT_ICE_COMPLETE = 0x53,
  ACHIEVEMENT_EICE_COMPLETE = 0x54,
  NUM_ACHIEVEMENT = 0x55,
};
struct ObjKey {
  uint32_t worldId;
  uint32_t objId;
};
struct ActiveHitbox {
  struct ObjKey objKey;
  struct Rectangle rectmp; // int
  int damage;
};
struct ActiveHitboxes {
  struct STDVector hitboxes; // ActiveHitbox,std::allocator<ActiveHitbox> 
};
struct AnimBoxes {
  int time;
  int length;
  struct STDVector rects; // std::vector<Rectangle<int>,std::allocator<Rectangle<int> > >,std::allocator<std::vector<Rectangle<int>,std::allocator<Rectangle<int> > > > 
};
struct AnimPoint {
  int time;
  int x;
  int y;
  int angle;
};
struct AnimBoxDescription {
  void *classptr;
  uint32_t type;
  int32_t id;
  int32_t time;
  int32_t length;
  int32_t x;
  int32_t y;
  int32_t w;
  int32_t h;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct AnimPointDescription {
  void *classptr;
  uint32_t type;
  int32_t time;
  int32_t x;
  int32_t y;
  int32_t angle;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct AnimationDescription {
  void *classptr;
  int32_t fullpose;
  uint32_t prevpose;
  struct STDString *aaid;
  uint32_t anim;
  int32_t length;
  struct RepeatedPtrField framedesc; // FrameDescription
  struct RepeatedPtrField box; // AnimBoxDescription
  struct RepeatedPtrField point; // AnimPointDescription
  bool looping;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct AnimationData {
  uint32_t ganim;
  int fullPose;
  int length;
  struct STDVector boxes[3]; // AnimBoxes,std::allocator<AnimBoxes> 
  struct STDVector point[6]; // AnimPoint,std::allocator<AnimPoint> 
};
struct VidAnimData {
  struct STDString vid;
  struct STDVector animDataVec; // AnimationData*,std::allocator<AnimationData*> 
  struct STDUMap animMap; // unsigned int,std::unordered_map<int,std::vector<int,std::allocator<int> >,std::hash<int>,std::equal_to<int>,std::allocator<std::pair<int const,std::vector<int,std::allocator<int> > > > >,std::hash<unsigned int>,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const,std::unordered_map<int,std::vector<int,std::allocator<int> >,std::hash<int>,std::equal_to<int>,std::allocator<std::pair<int const,std::vector<int,std::allocator<int> > > > > > > 
  struct STDUMap *transMap; // int,std::unordered_map<Pose,int,std::hash<int>,std::equal_to<Pose>,std::allocator<std::pair<const Pose,int> > >,std::hash<int>,std::equal_to<int>,std::allocator<std::pair<int const,std::unordered_map<Pose,int,std::hash<int>,std::equal_to<Pose>,std::allocator<std::pair<const Pose,int> > > > > 
  bool hasShieldBoxes;
};
struct AnimDataLibrary {
  struct STDUMap vidMap; // std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::vector<std::pair<int,VidAnimData*>,std::allocator<std::pair<int,VidAnimData*> > >,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<const std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::vector<std::pair<int,VidAnimData*>,std::allocator<std::pair<int,VidAnimData*> > > > > 
};
struct CharacterDescription {
  void *classptr;
  uint32_t type;
  int32_t w;
  struct STDString *vid;
  struct STDString *auravid;
  struct STDString *portraitvid;
  struct RepeatedField_int maxhitpoints;
  struct RepeatedField_int maxammo;
  struct RepeatedField_int damagebonus;
  int32_t h;
  int32_t walkaccel;
  struct RepeatedField_int armor;
  struct RepeatedField_int walkspeed;
  struct RepeatedField_int jumpspeed;
  struct RepeatedField_int critchance;
  struct RepeatedField_int critmult;
  int32_t airaccel;
  int32_t climbspeed;
  struct RepeatedField_int mainslots;
  struct RepeatedField_int secslots;
  struct RepeatedField_int impslots;
  bool hasspecialslot;
  bool hasbodyslot;
  bool hasmobslot;
  bool canhome;
  bool lockfacingincrouch;
  bool usecharstats;
  struct RepeatedField_int invslots;
  struct STDString *jumpsound;
  struct STDString *hitsound;
  struct STDString *deathsound;
  struct RepeatedPtrField startingitems; // CharacterDescription_StartingItem
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct CharacterLibrary {
  struct STDUMap typeMap; // CharacterType,CharacterDescription*,std::hash<int>,std::equal_to<CharacterType>,std::allocator<std::pair<const CharacterType,CharacterDescription*> > 
};
struct SubWorld {
  void *classptr;
  uint32_t worldId;
  int t;
};
struct Handler {
  int nextId;
  struct STDVector cbs; // Handler<ForeignObject*>::Callback,std::allocator<Handler<ForeignObject*>::Callback> 
};
struct SortedVecMap {
  struct STDVector vec; // std::pair<unsigned int,ForeignObject*>,std::allocator<std::pair<unsigned int,ForeignObject*> > 
  struct STDUMap map; // unsigned int,ForeignObject*,std::hash<unsigned int>,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const,ForeignObject*> > 
};
struct SubWorldImpl {
  struct SubWorld asSubWorld;
  struct Handler onAddObj; // ForeignObject*
  struct Handler onModifyObj; // ForeignObject*
  struct Handler onRemoveObj; // ForeignObject*,DestroyReason
  struct SortedVecMap objs; // unsigned int,ForeignObject*
  bool inUpdate;
  struct STDDeque toAdd; // ForeignObject*,std::allocator<ForeignObject*> 
  struct STDDeque toRemove; // SubWorldImpl<ForeignObject>::RemoveObj,std::allocator<SubWorldImpl<ForeignObject>::RemoveObj> 
};
struct FreeList {
  int32_t max;
  struct STDVector list; // std::deque<ObjectUpdate*,std::allocator<ObjectUpdate*> >*,std::allocator<std::deque<ObjectUpdate*,std::allocator<ObjectUpdate*> >*> 
};
struct ForeignSubWorld {
  struct SubWorldImpl asSubWorldImpl;
  struct World *world;
  struct STDDeque generalUpdates; // GeneralUpdate*,std::allocator<GeneralUpdate*> 
  struct STDUMap objectUpdates; // unsigned int,std::deque<ObjectUpdate*,std::allocator<ObjectUpdate*> >*,std::hash<unsigned int>,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const,std::deque<ObjectUpdate*,std::allocator<ObjectUpdate*> >*> > 
  int maxT;
  struct FreeList objectUpdatesFreeList; // std::deque<ObjectUpdate*,std::allocator<ObjectUpdate*> > 
};
struct WorldObject {
  void *classptr;
  bool isLive;
  bool dirty;
  uint32_t objId;
  struct Properties props;
  int32_t lastXmp;
  int32_t lastYmp;
  struct Shape *shape;
  struct VidAnimData *vad;
  int lastDamageT;
};
struct ForeignObject {
  struct WorldObject asWorldObject;
  struct ForeignSubWorld *subWorld;
  struct STDDeque *updates; // ObjectUpdate*,std::allocator<ObjectUpdate*> 
};
struct WorldProperties {
  void *classptr;
  uint32_t zoneid;
  uint32_t gameid;
  struct STDString *zone;
  int32_t floor;
  int32_t gdv;
  struct STDString *music;
  uint32_t seed;
  int32_t gravity;
  struct DecorationDescription *decoration;
  bool safe;
  bool tutorial;
  bool nocreateplayer;
  bool nohome;
  int32_t fadein;
  struct STDString *title;
  int32_t invultime;
  bool allowteleport;
  bool allowstash;
  bool allowcharslots;
  bool allowrejoin;
  int32_t movemult;
  int32_t forceplayertype;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct MapInfo {
  uint32_t worldId;
  struct STDUMap quadinfo; // unsigned int,MapInfo::QuadInfo,std::hash<unsigned int>,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const,MapInfo::QuadInfo> > 
  struct STDUMap objInfo; // WorldObject*,MapInfo::ObjInfo,std::hash<WorldObject*>,std::equal_to<WorldObject*>,std::allocator<std::pair<WorldObject* const,MapInfo::ObjInfo> > 
  struct STDVector sQuads; // unsigned int,std::allocator<unsigned int> 
  struct STDVector sOldQuads; // unsigned int,std::allocator<unsigned int> 
  struct STDVector sNewQuads; // unsigned int,std::allocator<unsigned int> 
};
struct World {
  void *classptr;
  struct Handler onDelta; // unsigned int,Delta
  struct Handler onPlayerEvent; // PlayerEvent,ObjKey,ObjKey
  struct Handler onDamage; // WorldObject*,int,bool,bool,unsigned int,int,int,char const*
  struct Handler onTrail; // WorldObject*,char const*
  struct Handler onPlaySound; // char const*,SoundType,int,int,ObjKey
  struct Handler onScreenShake; // int,int
  struct Handler onScreenFlash; // int,int,int,unsigned int
  struct Handler onRunDecorationAnim; // char const*,Anim
  struct Handler onCutScene; // char const*
  struct Handler onWorldTitle; // char const*,int,int
  uint32_t id;
  uint32_t nextObjId;
  struct WorldProperties props;
  struct MapInfo mapInfo;
  struct Delta worldUpdate;
};
struct Shape {
  void *classptr;
  struct WorldObject *obj;
};
enum PlayerEvent {
  PLAYER_EVENT_INVALID = 0x0,
  PLAYER_EVENT_INTERACT = 0x1,
  PLAYER_EVENT_INTERACT_SHIFT = 0x2,
  PLAYER_EVENT_TRIGGER = 0x3,
  PLAYER_EVENT_TRIGGER_END = 0x4,
  PLAYER_EVENT_GLOBAL = 0x5,
  PLAYER_EVENT_RETURN = 0x6,
  NUM_PLAYER_EVENT = 0x7,
};
enum SoundType {
  SOUND_TYPE_INVALID = 0xFFFFFFFF,
  SOUND_TYPE_UI = 0x0,
  SOUND_TYPE_PLAYER_MAIN = 0x1,
  SOUND_TYPE_PLAYER_OTHER = 0x2,
  SOUND_TYPE_ENEMY = 0x3,
  SOUND_TYPE_OTHER = 0x4,
  NUM_SOUND_TYPE = 0x5,
};
struct DecorationDescription {
  void *classptr;
  struct STDString *name;
  struct RepeatedPtrField inherit; // std::basic_string<char,std::char_traits<char>,std::allocator<char> > 
  struct RepeatedPtrField externaltiles; // TilesDescription
  struct RepeatedPtrField transitiontiles; // TilesDescription
  struct RepeatedPtrField internaltiles; // TilesDescription
  struct RepeatedPtrField uniform; // DecorationDescription_Uniform
  struct RepeatedPtrField scatter; // DecorationDescription_Scatter
  struct RepeatedPtrField edge; // DecorationDescription_Edge
  struct RepeatedPtrField fill; // DecorationDescription_Fill
  uint32_t backgroundcolor;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct NativeObject {
  struct WorldObject asWorldObject;
  int offsetDT;
  int32_t xVel;
  int32_t yVel;
  bool isPrivate;
  bool hasGravity;
  bool xBlocked;
  bool yBlocked;
  bool crouching;
  bool running;
  int32_t attXVel;
  int32_t moveXVel;
  int32_t moveYVel;
  int32_t walkAccel;
  bool instantWalkDecel;
  int32_t airAccel;
  int32_t gravityAccel;
  struct STDUMap damaged; // ObjKey,int,std::hash<ObjKey>,std::equal_to<ObjKey>,std::allocator<std::pair<const ObjKey,int> > 
  int redamageTime;
  struct STDString createSound;
  bool createSoundGlobal;
  struct ObjKey attached;
};
struct ClientObject {
  struct NativeObject asNativeObject;
  struct ClientSubWorld *subWorld;
  struct Action *action;
};
struct NativeSubWorld {
  struct SubWorldImpl asSubWorldImpl;
};
struct ClientSubWorld {
  struct NativeSubWorld asNativeSubWorld;
  struct ClientWorld *world;
};
struct Action {
  void *classptr;
  struct ClientObject *user;
  int animId;
  int speed;
  bool loop;
  struct STDString sound;
  enum SoundType soundType;
  bool soundPlayed;
};
struct ClientWorld {
  struct World asWorld;
  struct Handler onObjectAdded; // WorldObject*
  struct Handler onObjectRemoved; // WorldObject*,DestroyReason
  struct Handler onPlayerCharacterKilled; // Player*
  struct Handler onPlayerStatBoost; // Player*,const StatBoost&,bool
  struct Handler onPlayerMKUp; // Player*,int
  struct Handler onOpenStash; // int
  struct Handler onSwitchCharSlot; // WorldObject*,int
  struct Handler onRejoin;
  struct Handler onHome;
  struct Handler onFailedUCPurchase;
  struct Handler onFactionRegistrar;
  struct Handler onZoneComplete; // ZoneType,int
  struct Handler onPurchaseItem; // char const*,char const*,int,CurrencyType
  struct Handler onAchievement; // Achievement
  struct Handler onPlayerInputError; // PlayerInputError
  struct ActiveHitboxes activeHitboxes;
  struct ObjKey spawnObj;
  struct ForeignSubWorld *serverSubWorld;
  struct SortedVecMap clientSubWorlds; // unsigned int,ForeignSubWorld*
  struct ClientSubWorld *mySubWorld;
  uint32_t total;
  struct Player *player;
  struct STDVector allies; // WorldObject*,std::allocator<WorldObject*> 
  int timeReserve;
  int targetBuffer;
  int inputBuffer;
};
enum PlayerInputError {
  PIE_INVALID = 0x0,
  PIE_SECONDARY_SPAM = 0x1,
  PIE_INPUT_BUFFER_EXHAUSTED = 0x2,
  PIE_CAN_NOT_REJOIN = 0x3,
};
struct Player {
  struct ClientObject asClientObject;
  uint32_t numStash;
  uint32_t numCharSlots;
  uint32_t deeds;
  struct ObjKey interactObj;
  struct STDVector activeTriggers; // ObjKey,std::allocator<ObjKey> 
  struct STDUMap slottedCharProps; // int,CharacterProperties*,std::hash<int>,std::equal_to<int>,std::allocator<std::pair<int const,CharacterProperties*> > 
};
struct EmitObj {
  struct ClientObject *obj;
  int angleOffset;
};
struct WorldState_World {
  void *classptr;
  struct RepeatedPtrField obj; // WorldState_World_Obj
  uint32_t ownerid;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
enum ScatterType {
  SCATTERTYPE_INVALID = 0xFFFFFFFF,
  SCATTERTYPE_FLOAT = 0x0,
  SCATTERTYPE_BOTTOM = 0x1,
  SCATTERTYPE_LEFT = 0x2,
  SCATTERTYPE_TOP = 0x3,
  SCATTERTYPE_RIGHT = 0x4,
  SCATTERTYPE_INSIDE = 0x5,
  SCATTERTYPE_OUTSIDE = 0x6,
};
enum EdgeType {
  EDGETYPE_INVALID = 0xFFFFFFFF,
  EDGETYPE_GROUND = 0x0,
  EDGETYPE_LEFTWALL = 0x1,
  EDGETYPE_CEILING = 0x2,
  EDGETYPE_RIGHTWALL = 0x3,
  EDGETYPE_OBJBOTTOM = 0x4,
  EDGETYPE_OBJLEFT = 0x5,
  EDGETYPE_OBJTOP = 0x6,
  EDGETYPE_OBJRIGHT = 0x7,
};
struct SortedVecMap;
struct WorldState {
  void *classptr;
  struct WorldState_World *serverworld;
  struct RepeatedPtrField clientworld; // WorldState_World
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct TimePasses {
  void *classptr;
  int32_t dt;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct PlayerInput {
  void *classptr;
  int32_t total;
  int32_t hit;
  int32_t unhit;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ModifyInv {
  void *classptr;
  uint32_t command;
  int32_t slotpos;
  int32_t targetslotpos;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct Flappy {
  struct Player asPlayer;
  int ec;
  int untilFall;
};
struct Wings {
  struct Player asPlayer;
  int ec;
  uint32_t total;
  int sinceShoot;
  bool adminInvul;
};
struct OverlaidAnimation {
  struct ClientObject asClientObject;
  struct ObjKey followKey;
};
struct StatVal {
  int base;
  int bonus;
};
struct CharStats {
  struct STDUMap stats; // int,unsigned int,std::hash<int>,std::equal_to<int>,std::allocator<std::pair<int const,unsigned int> > 
};
struct PlayerCharacter {
  struct Player asPlayer;
  bool adminInvul;
  bool teleport;
  int createT;
  int ec;
  int uc;
  int keys[20];
  uint32_t charId;
  struct CharacterDescription *charDesc;
  struct DrawMods drawMods;
  uint32_t total;
  struct StatVal maxHitpoints;
  struct StatVal maxAmmo;
  int ammo;
  int ammoMult;
  struct StatVal damageBonus;
  struct StatVal armor;
  struct StatVal walkSpeed;
  struct StatVal jumpSpeed;
  struct StatVal critChance;
  struct StatVal critMult;
  int numMainSlots;
  int numSecSlots;
  int numImpSlots;
  int numInvSlots;
  struct STDString imageMap;
  int knockbackResist;
  int maxAirJumps;
  int numAirJumps;
  int maxAirDashes;
  int numAirDashes;
  int maxAirMobility;
  int numAirMobility;
  struct STDUMap items; // int,Item*,std::hash<int>,std::equal_to<int>,std::allocator<std::pair<int const,Item*> > 
  struct CharStats charStats;
  struct CharStats totalCharStats;
  enum Achievement killAchievement;
  bool tryClimb;
  struct STDUMap outs; // unsigned int,std::unordered_set<unsigned int,std::hash<unsigned int>,std::equal_to<unsigned int>,std::allocator<unsigned int> >,std::hash<unsigned int>,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const,std::unordered_set<unsigned int,std::hash<unsigned int>,std::equal_to<unsigned int>,std::allocator<unsigned int> > > > 
  int secondarySpamTimer;
};
struct StatInfo {
  char *name;
  char *unit;
  double div;
};
struct MapInfo__QuadInfo {
  struct STDVector objtypeMap[7]; // WorldObject*,std::allocator<WorldObject*> 
};
struct MapInfo__ObjInfo {
  int xmp;
  int ymp;
  int wmp;
  int hmp;
  uint32_t typeDesc;
};
struct QuadUtil {
  char gap0[1];
};
enum ObjType {
  OBJTYPE_BLOCKING = 0x0,
  OBJTYPE_CLIMB = 0x1,
  OBJTYPE_DRAWABLE = 0x2,
  OBJTYPE_DAMAGES_PLAYER = 0x3,
  OBJTYPE_PLAYER_DAMAGEABLE = 0x4,
  OBJTYPE_ENEMY_DAMAGEABLE = 0x5,
  OBJTYPE_ACTIVATE = 0x6,
  NUM_OBJTYPE = 0x7,
};
struct Tri {
  struct Shape asShape;
};
struct DamageGenerator {
  unsigned int min100;
  unsigned int diff100;
  int32_t critChance;
  int32_t critMult;
  int32_t armorPierce;
  struct PRNG prng;
};
struct EmitObjs {
  struct STDVector objs; // std::vector<EmitObj,std::allocator<EmitObj> >,std::allocator<std::vector<EmitObj,std::allocator<EmitObj> > > 
};
enum SharedProperty {
  PROPERTY_INVALID = 0x0,
  PROPERTY_XMP = 0x1,
  PROPERTY_X = 0x2,
  PROPERTY_CX = 0x3,
  PROPERTY_YMP = 0x4,
  PROPERTY_Y = 0x5,
  PROPERTY_CY = 0x6,
  PROPERTY_WMP = 0x7,
  PROPERTY_W = 0x8,
  PROPERTY_HMP = 0x9,
  PROPERTY_H = 0xA,
  PROPERTY_Z = 0xB,
  PROPERTY_SHAPETYPE = 0xC,
  PROPERTY_FACING = 0xD,
  PROPERTY_LIFETIME = 0xE,
  PROPERTY_BLOCKTYPE = 0xF,
  PROPERTY_OWNERTYPE = 0x10,
  PROPERTY_DAMAGE = 0x11,
  PROPERTY_HITBOXDAMAGE = 0x12,
  PROPERTY_HITPOINTS = 0x13,
  PROPERTY_MAXHITPOINTS = 0x14,
  PROPERTY_REMOVETYPE = 0x15,
  PROPERTY_DISPLAY_NAME = 0x16,
  PROPERTY_PLAYERDATA = 0x17,
  PROPERTY_TERRAINTYPE = 0x18,
  PROPERTY_INTERACT = 0x19,
  PROPERTY_IDESCRIPTION = 0x1A,
  PROPERTY_TRIGGER = 0x1B,
  PROPERTY_DRAW = 0x1C,
  PROPERTY_DECORATE = 0x1D,
  PROPERTY_ISINTERNAL = 0x1E,
  PROPERTY_INVULNERABLE = 0x1F,
  PROPERTY_KNOCKBACK = 0x20,
  PROPERTY_BOUNDSWORLD = 0x21,
  PROPERTY_ARMOR = 0x22,
  PROPERTY_ARMORPIERCE = 0x23,
  PROPERTY_RECOMMEND = 0x24,
  PROPERTY_NOLEECH = 0x25,
  PROPERTY_FOREIGNCLASS = 0x26,
  PROPERTY_SPAWN = 0x27,
  PROPERTY_KILLACHIEVEMENT = 0x28,
  PROPERTY_MOVE = 0x29,
  PROPERTY_MOVE_TO = 0x2A,
  PROPERTY_VID = 0x2B,
  PROPERTY_DRAWMODS = 0x2C,
  PROPERTY_ROTATE = 0x2D,
  PROPERTY_POSE = 0x2E,
  PROPERTY_POSETIME = 0x2F,
  PROPERTY_PREVPOSE = 0x30,
  PROPERTY_ANIMPROPS = 0x31,
  PROPERTY_MOVETRAIL = 0x32,
  PROPERTY_SOUNDPREFIX = 0x33,
  PROPERTY_IREACTION = 0x34,
  PROPERTY_TREACTION = 0x35,
  NUM_SHARED_PROPERTY = 0x36,
};
struct HomeAction {
  struct Action asAction;
  int homeCountdown;
  struct ObjKey homeAnimKey;
};
struct HitAction {
  struct Action asAction;
  int32_t moveXVel;
  enum TerrainType terrainType;
};
struct AttackAction {
  struct Action asAction;
  struct Handler onEmit; // ClientObject*
  bool canTransToAir;
  bool canTransToGround;
  bool jumpCancels;
  bool canChangeFacing;
  enum TerrainType terrainType;
  int fullPose;
  struct EmitObjs emitObjs;
  struct DamageGenerator damage;
  struct STDString damageFXVid;
  struct STDString emitSound;
  struct STDVector damaged; // std::unordered_map<ObjKey,int,std::hash<ObjKey>,std::equal_to<ObjKey>,std::allocator<std::pair<const ObjKey,int> > >,std::allocator<std::unordered_map<ObjKey,int,std::hash<ObjKey>,std::equal_to<ObjKey>,std::allocator<std::pair<const ObjKey,int> > > > 
};
struct Admin {
  struct Player asPlayer;
  uint32_t total;
};
struct ItemDescription {
  void *classptr;
  struct STDString *name;
  uint32_t type;
  uint32_t build;
  int32_t tier;
  uint32_t price;
  uint32_t currency;
  uint32_t itemclass;
  int32_t itemsubclass;
  uint32_t slot;
  struct RepeatedField_int usableby;
  struct STDString *lootvid;
  struct STDString *lootdestroyvid;
  struct STDString *lootsound;
  int32_t lootlifetime;
  uint32_t anim;
  struct STDString *aaid;
  struct STDString *imagemap;
  struct STDString *sound;
  struct STDString *altsound;
  struct STDString *emitsound;
  int32_t cooldown;
  int32_t numsubs;
  int32_t jitter;
  bool autoapply;
  bool candrop;
  bool lootisglobalplayerevent;
  bool unhitcancel;
  int32_t maxheat;
  int32_t speed;
  int32_t secondarysubs;
  int32_t simultaneous;
  struct AnchoredImage *anchoredimage;
  struct RepeatedPtrField statboosts; // StatBoost
  struct RepeatedPtrField obj; // ItemObjDescription
  int32_t bounces;
  int32_t _cached_size;
  uint32_t _has_bits[2];
};
struct AnchoredImage {
  void *classptr;
  struct STDString *vid;
  uint32_t pointtype;
  int32_t draworder;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct Item {
  void *classptr;
  struct PlayerCharacter *user;
  struct ItemDescription *desc;
  struct ItemProperties itemProps;
  struct PRNG prng;
  int slotPos;
  int damageBoost;
  int rangeBoost;
  int precisionBoost;
  int numSubsBoost;
  int speedBoost;
  int lifetimeBoost;
  int radiusBoost;
  int accelBoost;
  int armorPierceBoost;
  int simulBoost;
  int bounceBoost;
  int secSubsBoost;
  int32_t critChanceBoost;
  int32_t critMultBoost;
  int leechBoost;
  int extraHitBoost;
  int moveTimeBoost;
  int itemArmor;
  int animSpeedBoost;
  int cooldownBoost;
  bool penetrating;
  bool explosive;
  bool incendiary;
  bool seeking;
  bool barbed;
  bool trisected;
  bool reflect;
  bool shielded;
};
struct Ancient {
  struct PlayerCharacter asPlayerCharacter;
};
struct Duskwing {
  struct PlayerCharacter asPlayerCharacter;
};
struct Fabricator {
  struct PlayerCharacter asPlayerCharacter;
};
struct Ironclad {
  struct PlayerCharacter asPlayerCharacter;
};
struct Shield {
  struct Item asItem;
};
struct Keys {
  void *classptr;
  uint32_t zone;
  int32_t count;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct OnDestruct {
  struct STDFunction func; // void()
};
struct CharStatMessage {
  void *classptr;
  int32_t stat;
  uint32_t val;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
enum Rank {
  RANK_INVALID = 0xFFFFFFFF,
  RANK_STOCK = 0x0,
  RANK_MODIFIED = 0x1,
  RANK_CUSTOM = 0x2,
  RANK_EXPERIMENTAL = 0x3,
  RANK_PROTOTYPE = 0x4,
  NUM_RANK = 0x5,
};
struct ItemLibrary {
  struct STDUMap typeMap; // unsigned int,ItemDescription*,std::hash<unsigned int>,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const,ItemDescription*> > 
  struct STDUMap nameMap; // std::basic_string<char,std::char_traits<char>,std::allocator<char> >,ItemDescription*,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<const std::basic_string<char,std::char_traits<char>,std::allocator<char> >,ItemDescription*> > 
};
struct TotalChatStatAchievement {
  int charStat;
  int val;
  enum Achievement achievement;
};
struct Toaster {
  struct PlayerCharacter asPlayerCharacter;
  int starTimeLeft;
  struct DamageGenerator damageGenerator;
};
struct Wildfire {
  struct PlayerCharacter asPlayerCharacter;
};
struct MoveUtil {
  char gap0[1];
};
struct Chest {
  struct ClientObject asClientObject;
  struct RepeatedPtrField items; // ItemProperties
  struct STDVector angles; // int,std::allocator<int> 
  int pos;
  int untilThrow;
};
struct Loot {
  struct ClientObject asClientObject;
  struct ItemProperties itemProps;
  struct ItemDescription *itemDesc;
  int untilAutoApply;
};
struct DamagingClientObject {
  struct ClientObject asClientObject;
  struct DamageGenerator damage;
};
struct BodyDispenser {
  struct ForeignObject asForeignObject;
  struct STDString origVid;
  bool enabled;
};
enum CharSlot__State {
  STATE_UNKNOWN = 0x0,
  STATE_DISABLED = 0x1,
  STATE_EMPTY = 0x2,
  STATE_FULL = 0x3,
};
struct CharSlot {
  struct ForeignObject asForeignObject;
  int charSlotId;
  enum CharSlot__State state;
  uint32_t charId;
};
enum PropertyType {
  PROPERTY_TYPE_INVALID = 0x0,
  PROPERTY_TYPE_INT = 0x1,
  PROPERTY_TYPE_BOOL = 0x2,
  PROPERTY_TYPE_MESSAGE = 0x3,
  PROPERTY_TYPE_STRING = 0x4,
};
struct PropertyDesc {
  int property;
  char *name;
  enum PropertyType type;
  bool makesDirty;
  bool allowsUnset;
  void *factory; // google::protobuf::MessageLite
};
struct ObjectUpdate_Create;
struct SlottedChar {
  struct ForeignObject asForeignObject;
  uint32_t charId;
};
enum Stash__State {
  STATE_UNKNOWN_0 = 0x0,
  STATE_DISABLED_0 = 0x1,
  STATE_OPEN = 0x2,
};
struct Stash {
  struct ForeignObject asForeignObject;
  int stashId;
  enum Stash__State state;
};
struct StashedItem {
  struct ForeignObject asForeignObject;
  bool full;
};
struct Blocker {
  struct DamagingClientObject asDamagingClientObject;
  uint32_t creator;
  bool willDamage;
  bool hasDamage;
  int sinceCreate;
};
struct BulletBase {
  struct DamagingClientObject asDamagingClientObject;
  int32_t speed;
  int jitter;
  int radius;
  struct ObjKey relativeTo;
  int xSize;
  int xLifetime;
  struct STDString xVid;
  struct DamageGenerator xDamage;
  bool onlyXDamage;
  bool trisectedX;
  int numGuides;
  struct STDString guideVid;
  int32_t guideW;
  int32_t guideH;
  bool ignoreSetMovement;
};
struct BounceBullet {
  struct BulletBase asBulletBase;
  int bounces;
  int origLifetime;
};
struct Bullet {
  struct BulletBase asBulletBase;
  int behavior;
  int index;
};
struct Guide {
  struct ClientObject asClientObject;
  struct ObjKey source;
  struct ObjKey dest;
};
struct ClientAnimObject {
  struct ClientObject asClientObject;
};
struct DamageOverTimeSeed {
  struct ClientObject asClientObject;
  int cooldown;
  struct DamageGenerator damageGenerator;
};
struct DamageOverTime {
  struct DamagingClientObject asDamagingClientObject;
  struct ObjKey targetKey;
};
struct MultiExplosion {
  struct ClientObject asClientObject;
  int lifetime;
  struct DamageGenerator damage;
  struct STDString vid;
  int num;
  int interval;
  int angle;
  int32_t speed;
  int32_t jitter;
  int angleJitter;
  bool useMoveFacing;
  int i;
  int sinceX;
  int offsetAngle;
};
struct Explosion {
  struct DamagingClientObject asDamagingClientObject;
  int32_t speed;
  int32_t jitter;
  int angleJitter;
  bool useMoveFacing;
};
struct Incendiary {
  struct DamagingClientObject asDamagingClientObject;
};
struct ItemObjDescription {
  void *classptr;
  struct STDString *name;
  struct STDString *vid;
  int32_t w;
  int32_t h;
  int32_t mindamage;
  int32_t maxdamage;
  int32_t lifetime;
  int32_t speed;
  int32_t speedjitter;
  int32_t accel;
  int32_t dist;
  int32_t movetime;
  int32_t radius;
  int32_t hitpoints;
  uint32_t chartype;
  int32_t jitter;
  struct STDString *damagefxvid;
  struct STDString *createsound;
  int32_t angle;
  int32_t cooldown;
  struct STDString *soundprefix;
  int32_t behavior;
  bool rotate;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct BombJump {
  struct Item asItem;
};
struct BombJumpAction {
  struct AttackAction asAttackAction;
  int totalT;
  int32_t moveXVel;
};
struct Boomerang {
  struct Item asItem;
  struct STDUMap out; // ObjKey,int,std::hash<ObjKey>,std::equal_to<ObjKey>,std::allocator<std::pair<const ObjKey,int> > 
};
struct BounceBoomerang {
  struct DamagingClientObject asDamagingClientObject;
  struct ItemDescription *desc;
  int speedBoost;
  int lifetimeBoost;
  int bounces;
  int origLifetime;
};
struct StickyBoomerang {
  struct DamagingClientObject asDamagingClientObject;
  struct DamageGenerator damage;
  struct ItemDescription *desc;
  int speedBoost;
  int rangeBoost;
  bool stuck;
  struct ObjKey targetKey;
  int timeUntilHit;
  struct Point hitOffsetMP; // int
};
struct ThrownBoomerang {
  struct DamagingClientObject asDamagingClientObject;
  struct ItemDescription *desc;
  int speedBoost;
  int rangeBoost;
};
struct Booster {
  struct Item asItem;
};
struct BoosterAction {
  struct Action asAction;
  int timeLeft;
  int32_t accel;
  int32_t maxSpeed;
};
struct LiveBulletPinata {
  struct ClientObject asClientObject;
  struct ItemDescription *desc;
  int damageBoost;
};
struct BulletPinata {
  struct Item asItem;
  int untilUse;
  struct ObjKey out;
};
struct Dash {
  struct Item asItem;
};
struct DashDownAction {
  struct AttackAction asAttackAction;
  struct PlayerCharacter *character;
  struct ItemDescription *desc;
  struct DamageGenerator subDamage;
  int32_t moveXVel;
  int32_t moveYVel;
  int lifetime;
  struct PRNG prng;
  int untilSub;
  bool dashing;
};
struct DashAction {
  struct AttackAction asAttackAction;
  struct ItemDescription *desc;
  struct DamageGenerator subDamage;
  int32_t moveXVel;
  int lifetime;
  uint32_t hit;
  struct PRNG prng;
  int untilSub;
  uint32_t mirror;
  bool dashing;
};
struct DroneMaker {
  struct Item asItem;
};
struct MortarDrone {
  struct ClientObject asClientObject;
  int cooldown;
  bool penetrating;
  struct ItemObjDescription *bulletDesc;
  struct DamageGenerator damage;
  int untilShoot;
};
struct MortarBall {
  struct DamagingClientObject asDamagingClientObject;
  int32_t speed;
};
struct AggressorDrone {
  struct ClientObject asClientObject;
  struct DamageGenerator damage;
  int32_t speed;
  bool penetrating;
  int numOptions;
  struct ItemObjDescription *bulletDesc;
  int cooldown;
  int sinceShoot;
  int rangeMP;
  struct STDUMap numAttacks; // unsigned int,int,std::hash<unsigned int>,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const,int> > 
};
struct DeactivatedDrone {
  struct ClientObject asClientObject;
};
struct Flail {
  struct Item asItem;
};
struct FlailAction {
  struct AttackAction asAttackAction;
  int leech;
  struct ItemObjDescription *hitObjDesc;
  struct STDDeque hitObjs; // ObjKey,std::allocator<ObjKey> 
  struct DamageGenerator hitObjDamage;
  int lastHitObjT;
  int leeched;
};
struct FlailAttackAction {
  struct FlailAction asFlailAction;
  int extraHit;
  int hit;
};
struct FlailSpinAction {
  struct FlailAction asFlailAction;
  int moveTime;
  int hitTime;
  int soundTime;
  int diveFacing;
};
struct FlaskFire {
  struct DamagingClientObject asDamagingClientObject;
  struct ItemDescription *desc;
  struct DamageGenerator fireDamage;
  int32_t speed;
  int moveDir;
  bool started;
  int untilFire;
  int damageBoost;
  int numFiresLeft;
};
struct Flask {
  struct Item asItem;
  int untilUse;
};
struct LiveGrenadeBase {
  struct DamagingClientObject asDamagingClientObject;
  struct ItemObjDescription *itemObjDesc;
  struct ItemObjDescription *xObjDesc;
  bool incendiary;
  bool barbed;
  bool trisected;
};
struct LiveGrenade {
  struct LiveGrenadeBase asLiveGrenadeBase;
};
struct LiveCluster {
  struct LiveGrenadeBase asLiveGrenadeBase;
  struct ItemObjDescription *gObjDesc;
  int numSubs;
};
struct Grenade {
  struct Item asItem;
};
struct GroupHeal {
  struct Item asItem;
  int untilUse;
};
struct Gun {
  struct Item asItem;
  int heat;
  int untilCooldown;
  struct STDVector bullets; // ObjKey,std::allocator<ObjKey> 
};
struct GunAction {
  struct AttackAction asAttackAction;
  bool unhitCancel;
};
struct Hammer {
  struct Item asItem;
  struct STDDeque currs; // ObjKey,std::allocator<ObjKey> 
};
struct HammerAction {
  struct AttackAction asAttackAction;
  int extraHit;
  int hit;
};
struct Totem {
  struct DamagingClientObject asDamagingClientObject;
  int32_t speed;
  int32_t accel;
  int behavior;
  struct DamageGenerator damageGenerator;
  struct ObjKey stuckObj;
  int sinceClear;
};
struct WaveSeed {
  struct ClientObject asClientObject;
  int seedLifetime;
  struct STDString waveVid;
  int32_t waveWmp;
  int32_t waveHmp;
  int32_t vel;
  int waveLifetime;
  struct STDString waveSound;
  int numSubs;
  bool foundGround;
  struct DamageGenerator damageGenerator;
  int32_t nextWaveXmp;
};
struct WavePart {
  struct DamagingClientObject asDamagingClientObject;
  struct STDString vid;
  int lifetime;
  int untilNext;
  int numLeft;
};
struct HammerBomb {
  struct DamagingClientObject asDamagingClientObject;
  struct ItemObjDescription *itemObjDesc;
  struct ItemObjDescription *xObjDesc;
};
struct HoverGun {
  struct Item asItem;
  struct ClientSubWorld *clientSubWorld;
  unsigned int gunObjIds[2];
  uint32_t out;
  int sinceUse;
};
struct Hoverer {
  struct ClientObject asClientObject;
  struct HoverGun *gun;
  int untilShoot;
};
struct Seed {
  struct ClientObject asClientObject;
  struct ItemDescription *desc;
  int totalSubs;
  int lifetimeBoost;
  int radiusBoost;
  int cooldown;
  struct DamageGenerator damageGenerator;
  bool seeking;
  struct PRNG prng;
};
struct SeedX {
  struct DamagingClientObject asDamagingClientObject;
  bool seeking;
  int sinceSeek;
  bool firstSeek;
};
struct Kick {
  struct Item asItem;
};
struct KickAction {
  struct AttackAction asAttackAction;
  int hitId;
  bool hover;
  bool hit;
  int bounceTimer;
  int32_t moveXVel;
  int32_t moveYVel;
};
enum PetFollower__State {
  STATE_FOLLOW = 0x0,
  STATE_GRABLOOT = 0x1,
  STATE_RETURNLOOT = 0x2,
};
struct PetFollower {
  struct ClientObject asClientObject;
  int32_t speed;
  int32_t dist;
  uint32_t creator;
  uint32_t loot;
  enum PetFollower__State state;
  int sinceLookForLoot;
};
struct PetCreator {
  struct Item asItem;
  struct ClientSubWorld *clientSubWorld;
  struct STDVector outs; // unsigned int,std::allocator<unsigned int> 
};
struct CreatedPlatform {
  struct ClientObject asClientObject;
  struct Handler doTeleport;
  struct ItemObjDescription *xDesc;
  struct DamageGenerator xDamage;
  bool incediary;
  int shrapnel;
  char *timerVid;
  bool firstUpdate;
  uint32_t timerId;
};
struct PlatformCreator {
  struct Item asItem;
  int availableUses;
};
struct ProtoCreatedPlatform {
  struct ClientObject asClientObject;
  struct Handler doTeleport;
  struct CreatedPlatform *createdPlatform;
};
struct Rocket {
  struct Item asItem;
  int untilUse;
  struct PRNG prng;
};
struct LaunchedRocket {
  struct DamagingClientObject asDamagingClientObject;
  struct ItemDescription *desc;
  int accel;
  int totalSecSubs;
  struct DamageGenerator xDamage;
  bool seeking;
  bool trisected;
  int sinceSeek;
  int32_t lastCXmp;
  int32_t lastCYmp;
};
struct ShieldBashAction {
  struct AttackAction asAttackAction;
  int32_t xAccel;
  int32_t maxSpeed;
  int moveTime;
  uint32_t hit;
  int time;
  struct PRNG prng;
  int32_t moveXVel;
};
struct SimpleWeapon {
  struct Item asItem;
};
struct Star {
  struct Item asItem;
};
struct TeleportThrow {
  struct Item asItem;
  int throwT;
  uint32_t out;
};
struct TeleportObj {
  struct ClientObject asClientObject;
  struct ItemDescription *desc;
  uint32_t creatorId;
};
struct CrossTimes {
  int x;
  int y;
};
struct Spark {
  struct Player asPlayer;
  uint32_t total;
  int homeCountdown;
};
struct WingsBullet {
  struct ClientObject asClientObject;
};
struct WorldState_World_Obj {
  void *classptr;
  struct Properties *props;
  uint32_t objid;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ArrayUtil {
  char gap0[1];
};
struct SharedPropertyList {
  char gap0[1];
};
struct PurchaseDesc {
  int price;
  int uc;
  char *description;
  char *category;
};
struct URTri {
  struct Tri asTri;
};
struct ULTri {
  struct Tri asTri;
};
struct LLTri {
  struct Tri asTri;
};
struct LRTri {
  struct Tri asTri;
};
struct Rect {
  struct Shape asShape;
};
enum VisualType {
  IMAGE = 0x0,
  TILE_SET = 0x1,
  VISUAL_SET = 0x3,
  ANIMATED_IMAGE = 0x4,
};
struct Visual {
  void *classptr;
  enum VisualType type;
  struct STDString vid;
};
struct TileSpace {
  struct STDUMap tileSets; // unsigned char,TileSet*,std::hash<unsigned char>,std::equal_to<unsigned char>,std::allocator<std::pair<unsigned char const,TileSet*> > 
  struct STDUMap tileMap; // unsigned int,std::vector<Tile*,std::allocator<Tile*> >,std::hash<unsigned int>,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const,std::vector<Tile*,std::allocator<Tile*> > > > 
  struct STDVector tiles; // Tile*,std::allocator<Tile*> 
};
struct Tile {
  unsigned int sheet;
  unsigned short id;
  bool mirrorX;
  bool mirrorY;
  int rotation;
  int tw;
  int th;
  struct STDVector type; // unsigned int,std::allocator<unsigned int> 
  struct Point center; // int
  struct Rectangle src; // int
  int32_t flip;
};
struct PVidDescription {
  void *classptr;
  struct STDString *name;
  struct STDString *descid;
  struct RepeatedPtrField imageids; // std::basic_string<char,std::char_traits<char>,std::allocator<char> > 
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct Texture {
  struct PVidDescription pvidDesc;
  struct ImageFileDescription *desc;
  struct STDVector sheets; // unsigned int,std::allocator<unsigned int> 
  struct STDVector uiids; // UIIDInfo,std::allocator<UIIDInfo> 
};
struct ImageFileDescription {
  void *classptr;
  struct RepeatedPtrField sheetdef; // SheetDefinition
  struct RepeatedPtrField imageviddesc; // ImageVidDescription
  struct RepeatedPtrField tileviddesc; // TileVidDescription
  struct RepeatedPtrField tiledesc; // TileDescription
  struct RepeatedPtrField animatedimagedesc; // AnimatedImageDescription
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct UIIDInfo {
  int sheetId;
  struct ImageDefinition *imageDef;
};
struct ImageDefinition {
  void *classptr;
  int32_t x;
  int32_t y;
  int32_t w;
  int32_t h;
  int32_t rpx;
  int32_t rpy;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
enum GamepadType {
  GAMEPAD_NONE = 0x0,
  GAMEPAD_XBOX = 0x1,
  GAMEPAD_PS = 0x2,
};
struct TextureManager {
  struct STDVector textures; // Texture*,std::allocator<Texture*> 
  struct STDUMap visuals; // std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Visual*,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<const std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Visual*> > 
  struct STDUMap tileSpaces; // std::basic_string<char,std::char_traits<char>,std::allocator<char> >,TileSpace*,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<const std::basic_string<char,std::char_traits<char>,std::allocator<char> >,TileSpace*> > 
  struct STDUMap pvidVidMap; // std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::unordered_set<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<const std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::unordered_set<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > > > 
};
struct Image {
  struct Visual asVisual;
  unsigned int sheet;
  struct Point rp; // int
  struct Rectangle src; // int
};
struct AnimatedImage {
  struct Visual asVisual;
  struct Texture *texture;
  struct VidAnimData *vad;
  struct STDVector anims; // Animation*,std::allocator<Animation*> 
};
struct Animation {
  int length;
  bool looping;
  struct STDVector frames; // Frame*,std::allocator<Frame*> 
};
struct Frame {
  struct Texture *texture;
  int time;
  struct STDVector elements; // FrameElement*,std::allocator<FrameElement*> 
  struct STDUMap imageMapping; // std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::vector<FrameElement*,std::allocator<FrameElement*> >,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<const std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::vector<FrameElement*,std::allocator<FrameElement*> > > > 
};
struct FrameElement {
  unsigned int sheet;
  struct Rectangle src; // int
  struct Point size; // int
  struct Point offset; // int
  int angleDegt;
  int opacity;
  enum BlendMode blendMode;
  bool flipH;
  bool flipV;
  int rpX;
  int frpX;
  int rpY;
  int frpY;
};
struct TileSet {
  struct Visual asVisual;
  struct TileSpace *tileSpace;
  unsigned char tileSetId;
};
struct VisualSet {
  struct Visual asVisual;
  struct STDVector visuals; // std::pair<int,Visual*>,std::allocator<std::pair<int,Visual*> > 
};
struct UIElement {
  void *classptr;
  struct Stage *stage;
  struct UIElementContainer *parent;
  bool show;
  bool isModal;
  bool isSelected;
  bool containsMouse;
  int x;
  int y;
  int w;
  int h;
};
struct Background {
  struct UIElement asUIElement;
  struct Image *top;
  struct Image *mid;
  struct Image *bot;
  int topH;
  int midH;
  int botH;
};
struct UIElementContainer {
  struct UIElement asUIElement;
  struct STDVector children; // UIElement*,std::allocator<UIElement*> 
};
struct Stage {
  struct UIElementContainer asUIElementContainer;
  uint32_t backgroundColor;
  struct STDUMap gamepads; // int,std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::hash<int>,std::equal_to<int>,std::allocator<std::pair<int const,std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > 
  int lastTimeMS;
  struct UIElement *textInputTarget;
  bool done;
};
struct BackgroundVH {
  struct UIElement asUIElement;
  struct STDVector vids; // std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > 
  struct STDVector images; // Image*,std::allocator<Image*> 
  struct STDVector whs; // Point<int>,std::allocator<Point<int> > 
  int mids;
};
struct Checkbox {
  struct UIElement asUIElement;
  struct Handler onChange; // bool
  struct Image *check;
  bool checked;
  bool error;
  bool down;
};
struct TextTexture {
  struct STDString fontName;
  int size;
  uint32_t color;
  uint32_t colorMod;
  int outlineSize;
  uint32_t outlineColor;
  int lineSpacing;
  unsigned int texture;
  struct STDString text;
  int w;
  int h;
};
struct SoundMixer__ChannelStatus {
  int channel;
  int lastPlayMS;
  double distSq;
  struct STDString soundName;
  struct ObjKey obj;
};
struct SoundMixer {
  struct STDVector channels; // std::vector<SoundMixer::ChannelStatus,std::allocator<SoundMixer::ChannelStatus> >,std::allocator<std::vector<SoundMixer::ChannelStatus,std::allocator<SoundMixer::ChannelStatus> > > 
};
struct Label {
  struct UIElement asUIElement;
  struct STDString text;
  struct STDString fontName;
  int fontSize;
  uint32_t color;
  int outlineSize;
  uint32_t outlineColor;
  unsigned char opacity;
  int maxWidth;
  uint32_t backgroundColor;
  struct STDVector textTextures; // TextTexture*,std::allocator<TextTexture*> 
  int vSpacing;
};
struct ClickableLabel {
  struct Label asLabel;
  struct Handler onClick;
  uint32_t color;
  uint32_t overColor;
  bool mouseDown;
  bool disabled;
};
struct MarkupLabel {
  struct UIElement asUIElement;
  struct STDString text;
  int fontSize;
  uint32_t color;
  uint32_t linkColor;
  uint32_t linkOverColor;
  int maxWidth;
  struct STDVector textureSegments; // MarkupLabel::TextureSegment,std::allocator<MarkupLabel::TextureSegment> 
  struct MarkupLabel__TextureSegment *linkTarget;
  bool down;
};
struct MarkupLabel__TextureSegment {
  struct TextTexture *textTexture;
  int x;
  int y;
  struct STDString link;
};
struct Dialog {
  struct UIElementContainer asUIElementContainer;
  struct Handler onButton1;
  struct Handler onButton2;
  struct Label *title;
  struct STDVector text; // MarkupLabel*,std::allocator<MarkupLabel*> 
  struct DialogButton *button1;
  struct DialogButton *button2;
};
struct DialogButton {
  struct UIElementContainer asUIElementContainer;
  struct Handler onClick;
  struct Label *text;
  struct STDString trackingName;
  bool mouseOver;
  bool mouseDown;
  bool disabled;
};
struct DropdownSelection {
  struct UIElementContainer asUIElementContainer;
  struct Handler onPick; // std::basic_string<char,std::char_traits<char>,std::allocator<char> > 
  int eh;
  struct STDVector options; // std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > 
};
struct Dropdown {
  struct UIElementContainer asUIElementContainer;
  struct Handler onPick; // std::basic_string<char,std::char_traits<char>,std::allocator<char> > 
  struct Label *current;
  struct STDVector options; // std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > 
};
struct FrameDescription {
  void *classptr;
  struct RepeatedPtrField element; // FrameDescription_Element
  int32_t time;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ImageMaps {
  struct STDVector maps; // ImageMap,std::allocator<ImageMap> 
};
struct ImageMap {
  struct STDString name;
  struct STDUMap map; // int,int,std::hash<int>,std::equal_to<int>,std::allocator<std::pair<int const,int> > 
};
struct ImageButton {
  struct UIElementContainer asUIElementContainer;
  struct Handler onClick;
  uint32_t fontColor;
  struct STDString trackingName;
  struct Visual *visual;
  struct Label *label;
  bool mouseDown;
  bool disabled;
};
struct LabeledCheckbox {
  struct UIElementContainer asUIElementContainer;
  struct MarkupLabel *label;
  struct Checkbox *checkbox;
};
struct LabeledInput {
  struct UIElementContainer asUIElementContainer;
  struct Label *nameLabel;
  struct LabeledInputField *input;
  struct Label *errorLabel;
};
struct TextInputBuffer {
  struct STDString utf32;
  int cursor;
  int maxSize;
  struct STDString charRestrict;
};
struct TextInputField {
  struct UIElement asUIElement;
  struct Handler onTab;
  struct Handler onEnter; // std::basic_string<char,std::char_traits<char>,std::allocator<char> > 
  struct TextInputBuffer buffer;
  bool isPassword;
  bool disabled;
  int textOffsetWidth;
  int beforeCursorWidth;
  struct TextTexture *textTexture;
  int dt;
};
struct LabeledInputField {
  struct TextInputField asTextInputField;
};
struct MarkupLabel__TextSegment {
  struct STDString text;
  struct STDString link;
};
struct Slider {
  struct UIElementContainer asUIElementContainer;
  struct Handler onChange; // int
  struct VisualElement *bg;
  struct VisualElement *slider;
  bool isHeld;
};
struct VisualElement {
  struct UIElement asUIElement;
  struct STDString vid;
  bool flipH;
  bool flipV;
  int rotation;
  enum BlendMode blendMode;
  struct Visual *visual;
  struct Rectangle drawRect; // int
  int t;
  enum Anim anim;
  enum Pose pose;
  struct STDVector imageMaps; // std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > 
  int animPos;
  bool hideAfterAnim;
};
struct Settings {
  struct LocalStorage *ls;
};
struct LocalStorage {
  struct STDUMap fields; // std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<const std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > 
};
struct TextButton {
  struct UIElementContainer asUIElementContainer;
  struct Handler onMouseOver;
  struct Handler onClick;
  struct VisualElement *cursor;
  struct Label *text;
  struct STDString trackingName;
  bool mouseDown;
};
enum ClientInput {
  CINPUT_INVALID = 0xFFFFFFFF,
  CINPUT_WORLD_LEFT = 0x0,
  CINPUT_WORLD_RIGHT = 0x1,
  CINPUT_WORLD_UP = 0x2,
  CINPUT_WORLD_DOWN = 0x3,
  CINPUT_WORLD_JUMP = 0x4,
  CINPUT_WORLD_MAIN = 0x5,
  CINPUT_WORLD_SEC = 0x6,
  CINPUT_WORLD_INTERACT = 0x7,
  CINPUT_WORLD_HOME = 0x8,
  CINPUT_WORLD_SHIFT = 0x9,
  CINPUT_WORLD_DASHLEFT = 0xA,
  CINPUT_WORLD_DASHRIGHT = 0xB,
  CINPUT_WORLD_DASHUP = 0xC,
  CINPUT_WORLD_DASHDOWN = 0xD,
  CINPUT_WORLD_MAX = 0x20,
  CINPUT_MENU = 0x20,
  CINPUT_EXIT = 0x21,
  CINPUT_TOGGLE_PERF_STATS = 0x22,
  CINPUT_TOGGLE_INVENTORY = 0x23,
  CINPUT_TEXT_INPUT = 0x24,
  CINPUT_TOGGLE_FULLSCREEN = 0x25,
  CINPUT_DRAW_BOXES = 0x26,
  CINPUT_DRAW_HIT_BOXES = 0x27,
  CINPUT_DRAW_UNIFORM = 0x28,
  CINPUT_DRAW_SCATTER = 0x29,
  CINPUT_DRAW_EDGE = 0x2A,
  CINPUT_DRAW_TILES = 0x2B,
  CINPUT_DRAW_HUD = 0x2C,
  CINPUT_DECREASE_QUALITY = 0x2D,
  CINPUT_INCREASE_QUALITY = 0x2E,
  CINPUT_TOGGLE_MUSIC = 0x2F,
  CINPUT_TOGGLE_SOUND = 0x30,
  CINPUT_CHAT_SCROLL_UP = 0x31,
  CINPUT_CHAT_SCROLL_DOWN = 0x32,
  CINPUT_TOGGLE_PROGRESS = 0x34,
  CINPUT_DRAW_OPTION = 0x35,
  CINPUT_EMOTE_FIRST = 0x40,
  CINPUT_EMOTE_HEART = 0x40,
  CINPUT_EMOTE_HELP = 0x41,
  CINPUT_EMOTE_HP = 0x42,
  CINPUT_EMOTE_TREASURE = 0x43,
  CINPUT_EMOTE_RIP = 0x44,
  CINPUT_EMOTE_HAPPY = 0x45,
  CINPUT_EMOTE_SAD = 0x46,
  CINPUT_EMOTE_FOLLOW = 0x47,
  CINPUT_EMOTE_GOODJOB = 0x48,
  CINPUT_EMOTE_THANKS = 0x49,
  CINPUT_EMOTE_MAX = 0x4A,
  CINPUT_MAX = 0x4A,
};
enum ServerConnection__Error {
  INVALID_ERROR = 0x0,
  UNABLE_TO_ESTABLISH_CONNECTION = 0x1,
  LOST_CONNECTION_TO_SERVER = 0x2,
};
struct RC4_CTX {
  uint8_t x;
  uint8_t y;
  unsigned char m[256];
};
enum ServerConnection__State {
  UNOPENED = 0x0,
  OPENWAIT = 0x1,
  CONNECTING = 0x2,
  CONNECTED = 0x3,
  ERRORED = 0x4,
};
struct ServerConnection {
  struct Handler onError; // ServerConnection::Error
  struct RSAEncrypt *rsaEncrypt;
  enum ServerConnection__State state;
  struct STDString hostname;
  unsigned short port;
  int retriesLeft;
  int waitTime;
  int socket;
  struct STDString outputBuffer;
  uint8_t inputType;
  uint32_t inputLen;
  struct MessageHandlers messageHandlers;
  struct RC4_CTX *inRC4;
  struct RC4_CTX *outRC4;
  char *socketBuffer;
  size_t socketBufferAllocation;
  size_t socketBufferSize;
};
enum ServerConnection__ConnectionResult {
  FAILURE = 0xFFFFFFFF,
  WAITING = 0x0,
  SUCCESS = 0x1,
};
struct ClientStats {
  void *classptr;
  struct GameClient *gameClient;
  struct Series dt;
  struct Series numDraws;
  struct Series bufSize;
  struct Series reserve;
  struct Series targetBuffer;
  int lastTotalDraws;
  int sinceTrackEvent;
};
struct GameClient {
  struct UIElementContainer asUIElementContainer;
  struct Handler onDone;
  struct ClientStats *clientStats;
  struct ServerConnection *serverConnection;
  bool isAdmin;
  struct WorldClient *worldClient;
  struct LoadingScreen *loadingScreen;
  struct ChatLog *chatLog;
  struct ChatWindow *chatWindow;
  struct ChatInput *chatInput;
  struct PerfDisplay *perfDisplay;
  struct GameDest *gameDest;
  struct STDString gameKey;
  int accountInUseRetries;
  int sinceKeypress;
  int lastEmoteT;
};
struct WorldClient {
  struct UIElementContainer asUIElementContainer;
  struct Handler onChatError; // std::basic_string<char,std::char_traits<char>,std::allocator<char> > 
  struct ServerConnection *serverConnection;
  bool isAdmin;
  int lastUpdate;
  struct ClientWorld *clientWorld;
  struct WorldView *worldView;
  struct HUD *hud;
  struct WorldOverlay *overlay;
  struct WorldTitle *worldTitle;
  struct STDString scratch;
  struct Delta scratchDelta;
};
struct LoadingScreen {
  struct UIElementContainer asUIElementContainer;
  struct Label *loading;
  struct Label *tip;
};
struct ChatLog {
  struct STDVector entries; // ChatLogEntry*,std::allocator<ChatLogEntry*> 
};
struct ChatWindow {
  struct UIElementContainer asUIElementContainer;
  struct Image *bg;
  int bgH;
  struct ChatLog *chatLog;
  int offset;
  int currStart;
  int currEnd;
  struct STDVector chatLines; // ChatWindow::ChatLine*,std::allocator<ChatWindow::ChatLine*> 
};
struct ChatInput {
  struct TextInputField asTextInputField;
};
struct PerfDisplay {
  struct UIElementContainer asUIElementContainer;
  struct ClientStats *clientStats;
  struct Graph *drawGraph;
  struct Graph *netGraph;
  struct Label *dtText;
  struct Label *numDrawsText;
  struct Label *bufSizeText;
  struct Label *reserveText;
  struct Label *targetBufferText;
};
struct GameDest {
  void *classptr;
  struct STDString *zone;
  struct STDString *zonedesc;
  int32_t floor;
  uint32_t destgameid;
  struct ObjKeyMessage *destobjkey;
  struct STDString *spawnobjname;
  bool teleporttoparty;
  uint32_t time;
  struct ObjLocMessage *source;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct WorldView {
  struct UIElement asUIElement;
  struct ClientWorld *world;
  int addCBId;
  int removeCBId;
  int damageCBId;
  int trailCBId;
  int boostCBId;
  int mkUpCBId;
  int playSoundCBId;
  int shakeCBId;
  int flashCBId;
  int runAnimCBId;
  int userLinksCBId;
  bool recalculateWorldBounds;
  bool rebuildTiles;
  struct Rectangle worldBounds; // int
  struct Rectangle playerBounds; // int
  struct TileMap *tileMap;
  struct Tiles *tiles60;
  struct Tiles *tiles70;
  struct STDVector uniforms; // Uniform*,std::allocator<Uniform*> 
  bool offsetsInitialized;
  struct Point offset; // int
  struct Point currOffset; // int
  struct Point goalOffset; // int
  struct Point targetPos; // int
  int nextViewId;
  struct Grid *graphicGrid; // Graphic
  struct STDVector dynamicGraphics; // DynamicGraphic*,std::allocator<DynamicGraphic*> 
  struct STDUMap namedGraphics; // std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::vector<Graphic*,std::allocator<Graphic*> >,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<const std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::vector<Graphic*,std::allocator<Graphic*> > > > 
  struct STDVector fills; // WorldView::Fill,std::allocator<WorldView::Fill> 
  int lastSubWorldT;
  int shakeMagnitude;
  int shakePos;
  int shakeDuration;
  int flashStart;
  int flashHold;
  int flashEnd;
  int flashPos;
  uint32_t flashColor;
  struct STDUMap emotes; // ObjKey,std::deque<EmoteIcon*,std::allocator<EmoteIcon*> >,std::hash<ObjKey>,std::equal_to<ObjKey>,std::allocator<std::pair<const ObjKey,std::deque<EmoteIcon*,std::allocator<EmoteIcon*> > > > 
  struct STDUSet graphics; // Graphic*,std::hash<Graphic*>,std::equal_to<Graphic*>,std::allocator<Graphic*> 
  struct STDVector das; // WorldView::Drawable,std::allocator<WorldView::Drawable> 
  struct PRNG nsPRNG;
  struct STDUMap nameTextureCache; // unsigned int,TextTexture*,std::hash<unsigned int>,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const,TextTexture*> > 
};
struct HUD {
  struct UIElementContainer asUIElementContainer;
  struct ClientWorld *world;
  struct WorldView *worldView;
  struct HUDStatus *hudStatus;
  struct HUDEquip *hudEquip;
  struct InstructionLabel *rejoinLabel;
  struct InstructionLabel *homeLabel;
  struct InstructionLabel *tutorialLabel;
  struct TextTexture *countdownText;
  struct UIElement *mainInteractElement;
  struct UIElement *secInteractElement;
  struct ObjKey interactObjKey;
  size_t interactObjPropsKey;
  struct ObjKey recommendedObjKey;
  int untilRecCheck;
  struct VisualElement *rarrow;
  int sparkTime;
};
struct WorldOverlay {
  struct UIElementContainer asUIElementContainer;
  struct Handler onDone;
};
struct WorldTitle {
  struct UIElementContainer asUIElementContainer;
  int perX;
  int perY;
  int t;
  struct TextTexture *title;
};
struct Chat {
  void *classptr;
  struct STDString *username;
  struct STDString *accountid;
  struct STDString *target;
  struct STDString *message;
  struct STDString *filteredmessage;
  uint32_t chattype;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ChatLogEntry {
  struct Chat chat;
  bool isSelf;
  int receiveTime;
};
struct ChatWindow__ChatLine {
  struct UIElementContainer asUIElementContainer;
};
struct Graph {
  struct UIElement asUIElement;
  struct STDVector data; // Graph::Data,std::allocator<Graph::Data> 
};
struct ObjLocMessage {
  void *classptr;
  struct ServerLocMessage *server;
  struct ObjKeyMessage *objkey;
  uint32_t gameid;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
enum TileType {
  NONE = 0x0,
  WALL = 0x1,
  INTERIOR = 0x2,
};
struct TileMap {
  struct WorldView *view;
  struct Rectangle bounds; // int
  unsigned char externalSetId;
  int externalZ;
  unsigned char transitionSetId;
  unsigned char internalSetId;
  int internalZ;
  int tw;
  int th;
  bool has60;
  bool has70;
  unsigned char *setIds60;
  unsigned char *setIds70;
  enum TileType *tileTypes;
  struct TileSpace *tileSpace;
};
struct Tiles {
  int z;
  struct WorldView *view;
  int id;
  struct Rectangle bounds; // int
  struct TileSpace *tileSpace;
  int tw;
  int th;
  int tdw;
  int tdh;
  unsigned short *tileData;
};
struct Uniform {
  struct WorldView *view;
  int id;
  short z;
  enum GQ minGQ;
  enum GQ maxGQ;
  int xps;
  int yps;
  unsigned char parallax;
  int zeroOffset;
  struct STDVector layers; // Uniform::Layer,std::allocator<Uniform::Layer> 
};
struct Grid {
  int exp;
  struct STDUMap elemSquares; // Graphic*,std::vector<unsigned int,std::allocator<unsigned int> >,std::hash<Graphic*>,std::equal_to<Graphic*>,std::allocator<std::pair<Graphic* const,std::vector<unsigned int,std::allocator<unsigned int> > > > 
  struct STDUMap squareMap; // unsigned int,std::unordered_set<Graphic*,std::hash<Graphic*>,std::equal_to<Graphic*>,std::allocator<Graphic*> >,std::hash<unsigned int>,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const,std::unordered_set<Graphic*,std::hash<Graphic*>,std::equal_to<Graphic*>,std::allocator<Graphic*> > > > 
};
struct Graphic {
  void *classptr;
  struct WorldView *view;
  int id;
  short z;
  enum GQ minGQ;
  enum GQ maxGQ;
  struct Rectangle rect; // int
};
struct DynamicGraphic {
  struct Graphic asGraphic;
};
struct WorldView__Fill {
  short z;
  enum GQ minGQ;
  enum GQ maxGQ;
  uint32_t color;
  enum BlendMode blendMode;
};
enum WorldView__Drawable__Type {
  WORLDOBJECT = 0x0,
  TILES = 0x1,
  UNIFORM = 0x2,
  GRAPHIC = 0x3,
  FILL = 0x4,
};
struct WorldView__Drawable {
  enum WorldView__Drawable__Type type;
  short z;
  // WorldView__Drawable__$CB221A102CF7B03D7A73DE7569919313 _anon_0;
};
struct HUDStatus {
  struct UIElementContainer asUIElementContainer;
  struct ClientWorld *world;
  uint32_t charId;
  struct Image *hpbar;
  struct Image *hpbarbg;
  struct IconStat *hpStat;
  struct IconStat *ammoStat;
  struct IconStat *ecStat;
  struct IconStat *ucStat;
};
struct HUDEquip {
  struct UIElementContainer asUIElementContainer;
  struct ClientWorld *world;
  struct Image *hudequipbgedge;
  struct Image *hudequipbgspacer;
  struct STDVector slotTypes; // Slot,std::allocator<Slot> 
  struct STDVector slots; // SlotSprite*,std::allocator<SlotSprite*> 
  bool requireDraw;
};
struct InstructionLabel {
  struct UIElementContainer asUIElementContainer;
  struct VisualElement *bg;
  struct KeypressLabel *label;
};
struct Graph__Data {
  struct Series *series;
  int divisor;
  uint32_t color;
};
struct Uniform__Layer {
  int tileWidth;
  int tileHeight;
  enum BlendMode blendMode;
  bool allowFlipH;
  bool allowFlipV;
  int depthStart;
  int depthEnd;
  int yStart;
  int yEnd;
  struct Visual *visual;
};
struct IconStat {
  struct UIElementContainer asUIElementContainer;
  uint32_t highlightColor;
  struct VisualElement *icon;
  struct Label *text;
  int t;
  int lastIncrease;
  int val;
  int max;
};
struct SlotSprite {
  struct UIElementContainer asUIElementContainer;
  struct ClientWorld *world;
  int slotPos;
  struct Label *label;
  struct Image *select;
  struct VisualElement *icon;
  struct KeypressLabel *hotkeyLabel;
};
struct KeypressLabel {
  struct UIElementContainer asUIElementContainer;
  int fontSize;
  struct Label *keypress;
  struct Label *action;
};
struct GameService {
  void *classptr;
  struct Handler onFinalizePurchase; // PurchaseId,std::basic_string<char,std::char_traits<char>,std::allocator<char> > 
};
struct Login {
  void *classptr;
  struct STDString *guid;
  struct STDString *password;
  struct STDString *secret;
  struct STDString *accountid;
  struct STDString *steamauthticket;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct TextureLoader__TextureRequest {
  struct Texture *texture;
};
struct Hello {
  void *classptr;
  struct STDString *gameversion;
  uint32_t hid;
  int32_t dataversiontimestamp;
  struct STDString *dataversionid;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ErrorMessage {
  void *classptr;
  struct STDString *description;
  uint32_t code;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct TrackEvent {
  void *classptr;
  struct STDString *category;
  struct STDString *action;
  struct STDString *label;
  double value;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct UserLinksMessage {
  void *classptr;
  struct RepeatedPtrField ignoreid; // std::basic_string<char,std::char_traits<char>,std::allocator<char> > 
  struct RepeatedPtrField friendid; // std::basic_string<char,std::char_traits<char>,std::allocator<char> > 
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct Joined {
  void *classptr;
  struct STDString *guid;
  struct STDString *accountid;
  struct STDString *username;
  bool isadmin;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct LoadPVid {
  void *classptr;
  struct STDString *pvid;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ChangeServer {
  void *classptr;
  struct ServerLocMessage *server;
  struct GameDest *gamedest;
  struct STDString *gamekey;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct UserLinks {
  struct Handler onChange;
  struct STDUMap linksMap; // std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<const std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int> > 
};
struct Join {
  void *classptr;
  struct STDString *guid;
  struct STDString *secret;
  struct STDString *accountid;
  struct GameDest *gamedest;
  struct STDString *gamekey;
  uint32_t gameservice;
  bool newsession;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct GameMenuButton {
  struct UIElementContainer asUIElementContainer;
  struct Handler onMouseOver;
  struct Handler onClick;
  struct Label *text;
  struct STDString trackingName;
  bool mouseDown;
};
struct MessageHandlers__MessageHandler {
  struct MessageHandlers__MessageHandlerBase asMessageHandlers__MessageHandlerBase;
  struct STDFunction func; // void(MessageType,const ChangeServer&)
  struct ChangeServer message;
};
enum ResponseCode {
  RC_INVALID = 0xFFFFFFFF,
  RC_SUCCESS = 0x0,
  RC_FATAL_ERROR = 0x1,
  RC_CONNECTION_ERROR = 0x2,
  RC_INVALID_EMAIL = 0x3,
  RC_INVALID_USERNAME = 0x4,
  RC_INVALID_PASSWORD = 0x5,
  RC_INVALID_CREDENTIALS = 0x6,
  RC_EMAIL_IN_USE = 0x7,
  RC_USERNAME_IN_USE = 0x8,
  RC_SUSPENDED = 0x9,
  RC_INTERNAL_ERROR = 0xA,
  RC_NEW_PLAYER_NOT_ALLOWED = 0xB,
  RC_SERVER_FULL = 0xC,
  RC_ACCOUNT_IN_USE = 0xD,
  RC_INCORRECT_GAME_KEY = 0xE,
  RC_UNKNOWN_USERNAME = 0xF,
  RC_IS_ALREADY = 0x10,
  RC_IS_NOT = 0x11,
  RC_IS_SELF = 0x12,
  RC_COMMAND_NOT_FOUND = 0x13,
  RC_INCORRECT_PARAMETERS = 0x14,
  RC_ALREADY_IMPORTED = 0x15,
  RC_STEAM_USER_TICKET_AUTH_FAILED = 0x16,
  RC_PAYMENT_FAILED = 0x17,
  RC_PAYMENT_CONNECTION_ERROR = 0x18,
  RC_TOO_MANY_LOGIN_FAILURES = 0x19,
  RC_NAME_IN_USE = 0x1A,
  RC_IN_FACTION = 0x1B,
  RC_INVALID_NAME = 0x1C,
  RC_FACTION_NOT_FOUND = 0x1D,
  RC_NOT_IN_FACTION = 0x1E,
  RC_NOT_ALLOWED = 0x1F,
  RC_FACTION_MAX_MEMBERS = 0x20,
  RC_ALREADY_FACTION_RANK = 0x21,
  RC_USER_CONNECTED = 0x22,
};
enum FactionActionType {
  FACTIONACTION_CREATE = 0x1,
};
struct ClientInputKeys {
  int32_t primary;
  int32_t secondary;
  int32_t tertiary;
};
struct InputMapping {
  struct ClientInputKeys cik[74];
  struct STDUMap keyMap; // int,ClientInput,std::hash<int>,std::equal_to<int>,std::allocator<std::pair<int const,ClientInput> > 
};
struct TextureLoader {
  struct Handler onDone;
  bool titleLoaded;
  bool baseLoaded;
  struct STDString current;
  struct STDVector outstandingRequests; // TextureLoader::TextureRequest*,std::allocator<TextureLoader::TextureRequest*> 
  struct STDString dataVersionId;
  int dataVersionTimestamp;
  struct STDUMap pvidIdMap; // std::basic_string<char,std::char_traits<char>,std::allocator<char> >,PVidDescription,std::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<const std::basic_string<char,std::char_traits<char>,std::allocator<char> >,PVidDescription> > 
};
struct Connect {
  void *classptr;
  uint32_t hid;
  uint32_t platfromtype;
  uint32_t sessionid;
  uint32_t enckey;
  struct STDString *currentpvid;
  struct Login *login;
  struct Register *reg;
  struct ChangeName *changename;
  struct ChangePassword *changepassword;
  struct Join *join;
  struct ResetPassword *resetpassword;
  struct PortAccount *importaccount;
  struct PortAccount *exportaccount;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct Register {
  void *classptr;
  struct STDString *guid;
  struct STDString *secret;
  struct STDString *accountid;
  struct STDString *newguid;
  struct STDString *newusername;
  struct STDString *newpassword;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ChangeName {
  void *classptr;
  struct STDString *guid;
  struct STDString *secret;
  struct STDString *accountid;
  struct STDString *newusername;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ChangePassword {
  void *classptr;
  struct STDString *guid;
  struct STDString *password;
  struct STDString *newpassword;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ResetPassword {
  void *classptr;
  struct STDString *guid;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct PortAccount {
  void *classptr;
  struct STDString *guid;
  struct STDString *secret;
  struct STDString *accountid;
  struct STDString *newguid;
  struct STDString *newpassword;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct PlayerText {
  void *classptr;
  struct STDString *text;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct PlayerEmote {
  void *classptr;
  uint32_t emote;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct FinalizePurchase {
  void *classptr;
  struct STDString *purchasekey;
  uint32_t purchaseid;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct CreateWorld {
  void *classptr;
  struct WorldProperties *worldprops;
  struct WorldState *worldstate;
  struct ObjKeyMessage *spawnobj;
  uint32_t worldid;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct GameMenu {
  struct UIElementContainer asUIElementContainer;
  struct Handler onRegistered;
  struct GameClient *gameClient;
  struct STDVector buttons; // GameMenuButton*,std::allocator<GameMenuButton*> 
  struct GameMenuButton *selected;
};
struct SteamGameService {
  struct GameService asGameService;
  uint32_t sessionId;
  bool newSession;
  struct STDString guid;
  struct STDString secret;
  struct STDString accountId;
  struct STDString username;
  bool isProd;
};
struct InputKeys {
  void *classptr;
  int32_t cinput;
  int32_t primary;
  int32_t secondary;
  int32_t tertiary;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct InputMappingPB {
  void *classptr;
  struct RepeatedPtrField inputkeys; // InputKeys
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ClusterInfo {
  void *classptr;
  struct RepeatedPtrField clusters; // Cluster
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct MainMenu {
  struct UIElementContainer asUIElementContainer;
  struct Handler onPlay; // std::basic_string<char,std::char_traits<char>,std::allocator<char> >,short unsigned int
  bool outstandingRequest;
  struct ClusterInfo clusterInfo;
  struct DecoratedBackground *bg;
  struct FilledRect *blackBar;
  struct VisualElement *logo;
  struct Label *loading;
  struct TextButton *playButton;
  struct TextButton *optionsButton;
  struct TextButton *exitButton;
  struct ImageButton *crunchyButton;
  struct STDVector accountButtons; // TextButton*,std::allocator<TextButton*> 
  struct TextButton *selected;
  struct StringChooser *accountName;
  struct StringChooser *serverName;
  struct Label *controllerStatus;
  struct Label *version;
};
struct UIBGDecorationFile {
  void *classptr;
  struct UIBGDecorationDescription *decoration;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct DecoratedBackground {
  struct UIElementContainer asUIElementContainer;
  struct UIBGDecorationFile decorationFile;
};
struct FilledRect {
  struct UIElement asUIElement;
  uint32_t color;
};
struct StringChooser {
  struct UIElementContainer asUIElementContainer;
  struct Handler onChoose; // std::basic_string<char,std::char_traits<char>,std::allocator<char> > 
  struct STDString title;
  struct STDString value;
  struct STDVector options; // std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > 
  int minW;
  bool opened;
  int valueX;
  int lineH;
};
struct UIBGDecorationDescription {
  void *classptr;
  struct RepeatedPtrField uniform; // UIBGDecorationDescription_Uniform
  struct RepeatedPtrField scatter; // UIBGDecorationDescription_Scatter
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ImageMapDescription {
  void *classptr;
  struct STDString *name;
  struct RepeatedPtrField mapping; // ImageMapDescription_Mapping
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct AnimatedImageDescription {
  void *classptr;
  struct STDString *vid;
  struct RepeatedPtrField imagemapdesc; // ImageMapDescription
  struct RepeatedPtrField animdesc; // AnimationDescription
  int32_t versionid;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct FrameDescription_Element {
  void *classptr;
  int32_t uiid;
  int32_t offsetx;
  int32_t offsety;
  int32_t angledegt;
  int32_t scalex;
  int32_t scaley;
  int32_t opacity;
  uint32_t blendmode;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ImageMapDescription_Mapping {
  void *classptr;
  int32_t uiid;
  int32_t targetuiid;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct NumberTexture {
  int value;
  unsigned int numberDict;
  struct TextTexture *textTexture;
  int w;
  int h;
};
struct SheetDefinition {
  void *classptr;
  struct RepeatedPtrField imagedef; // ImageDefinition
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct DataVersion {
  void *classptr;
  struct STDString *id;
  struct RepeatedPtrField pvid; // PVidDescription
  int32_t timestamp;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ImageVidDescription {
  void *classptr;
  struct STDString *vid;
  int32_t versionid;
  int32_t uiid;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct TileVidDescription {
  void *classptr;
  struct STDString *vid;
  int32_t tilesetid;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct TileDescription {
  void *classptr;
  int32_t uiid;
  int32_t tw;
  struct STDString *type;
  int32_t th;
  bool mirrorx;
  bool mirrory;
  bool rotate;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct AccountWindow {
  struct UIElementContainer asUIElementContainer;
  struct Handler onDone;
  struct Label *error;
  struct DialogButton *cancelButton;
  struct DialogButton *okButton;
  struct STDVector tabOrder; // TextInputField*,std::allocator<TextInputField*> 
};
struct ChangeNameWindow {
  struct AccountWindow asAccountWindow;
  struct LabeledInput *usernameInput;
};
struct GeneralResponse {
  void *classptr;
  uint32_t code;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ServerRequestTask {
  struct AsyncTask asAsyncTask;
  struct Connect *connect;
  enum MessageType responseType;
  struct STDFunction responseFunc; // void(const GeneralResponse&)
  bool done;
  struct ServerConnection *serverConnection;
};
struct ChangePasswordWindow {
  struct AccountWindow asAccountWindow;
  struct LabeledInput *passwordInput;
  struct LabeledInput *newPasswordInput;
  struct LabeledInput *verifyInput;
};
struct ChangePasswordResponse {
  void *classptr;
  struct STDString *secret;
  uint32_t code;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ExportAccountWindow {
  struct AccountWindow asAccountWindow;
  struct Label *infoLabel;
  struct LabeledInput *emailInput;
  struct LabeledInput *passwordInput;
  struct LabeledInput *verifyInput;
};
struct PortAccountResponse {
  void *classptr;
  struct STDString *accountid;
  struct STDString *secret;
  struct STDString *username;
  uint32_t code;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ForgotPasswordWindow {
  struct AccountWindow asAccountWindow;
  struct LabeledInput *emailInput;
};
struct ImportAccountWindow {
  struct AccountWindow asAccountWindow;
  struct Label *warningLabel;
  struct LabeledInput *emailInput;
  struct LabeledInput *passwordInput;
};
struct LoginWindow {
  struct AccountWindow asAccountWindow;
  struct LabeledInput *emailInput;
  struct LabeledInput *passwordInput;
  struct ClickableLabel *forgotPasswordLink;
};
struct LoginResponse {
  void *classptr;
  struct STDString *guid;
  struct STDString *secret;
  struct STDString *accountid;
  struct STDString *username;
  struct LoginResponse_Suspension *suspension;
  uint32_t code;
  bool isprod;
  bool created;
  struct ClusterInfo *clusterinfo;
  struct STDString *error;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct LoginResponse_Suspension {
  void *classptr;
  struct STDString *reason;
  int32_t hoursleft;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct RegisterWindow {
  struct AccountWindow asAccountWindow;
  struct LabeledInput *emailInput;
  struct LabeledInput *usernameInput;
  struct LabeledInput *passwordInput;
  struct LabeledInput *verifyInput;
  struct LabeledCheckbox *tosCheckbox;
};
struct RegisterResponse {
  void *classptr;
  struct STDString *accountid;
  struct STDString *secret;
  uint32_t code;
  bool created;
  struct STDString *username;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct CharInteractElement {
  char gap0[1];
};
struct ToolTip {
  struct UIElementContainer asUIElementContainer;
  struct Background *background;
  int hPos;
};
enum ToolTip__TextType {
  HEADER_TEXT = 0x0,
  NORMAL_TEXT = 0x1,
  NUM_TEXT = 0x2,
};
struct CharData {
  char *name;
  char *article;
  char *description;
};
struct CutScene {
  struct UIElementContainer asUIElementContainer;
  struct VisualElement *visual;
};
struct DecorationVisualElement {
  struct VisualElement asVisualElement;
  int offsetX;
  int offsetY;
  int startX;
  int startY;
  int z;
  int xps;
  int yps;
};
struct UIBGDecorationDescription_Uniform {
  void *classptr;
  int32_t z;
  int32_t tilewidth;
  struct STDString *vid;
  int32_t tileheight;
  uint32_t blendmode;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct UIBGDecorationDescription_Scatter {
  void *classptr;
  int32_t z;
  int32_t zjitter;
  struct UIBGDecorationDescription_Scatter_Bounds *bounds;
  int32_t xps;
  int32_t xpsjitter;
  int32_t yps;
  int32_t ypsjitter;
  int32_t frequency;
  int32_t spacingwidth;
  struct STDString *vid;
  int32_t spacingheight;
  uint32_t blendmode;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct UIBGDecorationDescription_Scatter_Bounds {
  void *classptr;
  float left;
  float top;
  float right;
  float bottom;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct DepositInteractElement {
  char gap0[1];
};
struct FactionRegisterWindow {
  struct UIElementContainer asUIElementContainer;
  struct Handler onRegisterFaction; // std::basic_string<char,std::char_traits<char>,std::allocator<char> > 
  int ec;
  struct STDString currFactionName;
  struct Image *halftone;
  struct FactionRegisterDialog *dialog;
};
struct FactionRegisterDialog {
  struct UIElementContainer asUIElementContainer;
  struct Handler onRegister;
  struct Handler onCancel;
  struct LabeledInput *nameInput;
  struct Label *errorLabel;
  struct Label *priceLabel;
  struct DialogButton *button1;
  struct DialogButton *button2;
};
struct FactionVendorWindow {
  struct UIElementContainer asUIElementContainer;
};
struct FactionRosterLine {
  struct UIElementContainer asUIElementContainer;
};
struct FactionRoster_Member {
  void *classptr;
  struct STDString *username;
  struct STDString *accountid;
  uint32_t rank;
  bool online;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct FactionRosterWindow {
  struct WorldOverlay asWorldOverlay;
  struct ServerConnection *serverConnection;
  struct PlayerWindowExitSprite *playerWindowExitSprite;
  struct FactionRosterDialog *factionRosterDialog;
};
struct FactionRosterResponse {
  void *classptr;
  struct FactionRoster *roster;
  uint32_t code;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct PlayerWindowExitSprite {
  struct UIElementContainer asUIElementContainer;
  struct Image *pwinexit;
};
struct FactionRosterDialog {
  struct UIElementContainer asUIElementContainer;
  struct FactionRosterResponse factionRosterResponse;
  int page;
  int numPages;
  struct STDVector lines; // FactionRosterLine*,std::allocator<FactionRosterLine*> 
  struct VisualElement *prevPage;
  struct VisualElement *nextPage;
};
struct FactionRoster {
  void *classptr;
  struct STDString *name;
  struct RepeatedPtrField member; // FactionRoster_Member
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
enum WorldOverlay__Type {
  INVALID = 0xFFFFFFFF,
  INVENTORY = 0x0,
  PROGRESS = 0x1,
  SCORE = 0x2,
  ZONE_SCORE = 0x3,
  FACTION_ROSTER = 0x4,
};
struct CheckboxLine {
  struct UIElementContainer asUIElementContainer;
  struct Label *name;
  struct Checkbox *checkbox;
};
struct KeyRemapPage {
  struct UIElementContainer asUIElementContainer;
  struct STDVector keys; // KeyRemapLine*,std::allocator<KeyRemapLine*> 
  int selectedIndex;
  int selectedPlace;
};
struct KeyRemapLine {
  struct UIElementContainer asUIElementContainer;
  struct Handler onSelect; // int
  struct Handler onModify;
  enum ClientInput cinput;
  struct Label *name;
  struct Label *primary;
  struct Label *secondary;
  struct Label *tertiary;
  int selectedPlace;
  bool modifying;
};
struct OptionsDialog {
  struct UIElementContainer asUIElementContainer;
  struct Handler onDone;
  struct Label *title;
  struct DialogButton *button1;
  struct DialogButton *button2;
  struct STDVector lines; // UIElement*,std::allocator<UIElement*> 
  struct UIElement *selected;
};
struct Controls {
  struct OptionsDialog asOptionsDialog;
  struct Label *instructions;
  struct Label *primaryLabel;
  struct Label *secondaryLabel;
  struct Label *tertiaryLabel;
  struct Tabs *tabs;
  struct STDVector pages; // KeyRemapPage*,std::allocator<KeyRemapPage*> 
  int pageId;
};
struct Tabs {
  struct UIElementContainer asUIElementContainer;
  struct Handler onTab; // int
  struct Image *tab;
  struct Image *stab;
  struct STDVector labels; // ClickableLabel*,std::allocator<ClickableLabel*> 
  int selected;
};
struct DropdownLine {
  struct UIElementContainer asUIElementContainer;
  struct Label *name;
  struct Dropdown *dropdown;
};
struct GameplayOptions {
  struct OptionsDialog asOptionsDialog;
  struct CheckboxLine *doubleTap;
};
struct GraphicsOptions {
  struct OptionsDialog asOptionsDialog;
  struct DropdownLine *resolution;
  struct CheckboxLine *fullScreen;
  struct SliderLine *gq;
  struct CheckboxLine *vsync;
  struct CheckboxLine *equipHUD;
  struct CheckboxLine *allyHitDamage;
  struct CheckboxLine *filterChat;
  struct CheckboxLine *showRArrow;
};
struct SliderLine {
  struct UIElementContainer asUIElementContainer;
  struct Label *name;
  struct Slider *slider;
};
struct SoundsOptions {
  struct OptionsDialog asOptionsDialog;
  struct SliderLine *music;
  struct SliderLine *sfx;
};
struct GateInteractElement {
  char gap0[1];
};
struct GateData {
  char *action;
  char *description;
  bool isElite;
};
struct ItemInteractElement {
  char gap0[1];
};
struct ItemToolTip {
  struct ToolTip asToolTip;
  struct ItemDescription *desc;
  bool equipable;
  enum Slot slot;
};
struct PurchaseInteractElement {
  char gap0[1];
};
struct InventoryOverlay {
  struct WorldOverlay asWorldOverlay;
  struct Handler onModifyInv; // ModifyInv
  uint32_t total;
  struct ClientWorld *world;
  struct HUD *hud;
  struct NameWindow *nameWindow;
  struct StatsWindow *statsWindow;
  struct InventoryWindow *inventoryWindow;
  struct StashWindow *stashWindow;
  struct PlayerWindowExitSprite *playerWindowExitSprite;
  struct ToolTip *toolTip;
  struct ToolTip *comparisonToolTip;
};
struct NameWindow {
  struct ToolTip asToolTip;
  struct ClientWorld *world;
  struct Label *name;
  struct Label *factionName;
};
struct StatsWindow {
  struct ToolTip asToolTip;
  struct ClientWorld *world;
  struct Label *keys[12];
  struct Label *values[12];
};
struct InventoryWindow {
  struct UIElementContainer asUIElementContainer;
  struct ClientWorld *world;
  struct STDVector slots; // SlotSprite*,std::allocator<SlotSprite*> 
};
struct StashWindow {
  struct UIElementContainer asUIElementContainer;
  struct ClientWorld *world;
  int stashId;
  enum Slot stashSlot;
  struct STDVector slots; // SlotSprite*,std::allocator<SlotSprite*> 
};
struct Cluster {
  void *classptr;
  struct STDString *name;
  struct ServerLocMessage *location;
  double latitude;
  double longitude;
  bool recommended;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ProgressOverlay {
  struct WorldOverlay asWorldOverlay;
  struct ClientWorld *world;
  struct ProgressWindow *progressWindow;
  struct PlayerWindowExitSprite *playerWindowExitSprite;
};
struct ProgressWindow {
  struct UIElementContainer asUIElementContainer;
  struct ClientWorld *world;
  struct StatLine *statLine[8];
};
enum PWStat {
  PWSTAT_MAXHP = 0x0,
  PWSTAT_AMMO = 0x1,
  PWSTAT_DAMAGE = 0x2,
  PWSTAT_ARMOR = 0x3,
  PWSTAT_SPEED = 0x4,
  PWSTAT_JUMP = 0x5,
  PWSTAT_CRITC = 0x6,
  PWSTAT_CRITX = 0x7,
  NUM_PWSTAT = 0x8,
};
struct StatLine {
  struct UIElementContainer asUIElementContainer;
  enum PWStat pwStat;
  struct Label *valLabel;
  struct StatBar *statBars[5];
  int inc;
};
struct StatBar {
  struct UIElement asUIElement;
  int val;
  int max;
  struct Image *bg;
  struct Image *frame;
  struct Image *gap;
  struct Image *pipl;
  struct Image *pipm;
  struct Image *pipr;
};
struct FinalScoreSprite {
  struct UIElementContainer asUIElementContainer;
  struct ScoreStatLine *scoreLine;
};
struct ScoreStatLine {
  struct UIElementContainer asUIElementContainer;
  int value;
  struct STDString valuePrefix;
  bool best;
  struct Label *nameLabel;
  struct Label *valueLabel;
  bool started;
  int time;
};
struct CharacterScore_Bonus {
  void *classptr;
  uint32_t bonus;
  int32_t value;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct StatLineList {
  struct STDVector statLines; // ScoreStatLine*,std::allocator<ScoreStatLine*> 
};
struct ScoreBonusWindow {
  struct UIElementContainer asUIElementContainer;
  struct StatLineList statLineList;
};
struct ScoreCharWindow {
  struct UIElementContainer asUIElementContainer;
};
struct ScoreOverlay {
  struct WorldOverlay asWorldOverlay;
  int time;
  struct ScoreCharWindow *scoreCharWindow;
  struct ScoreStatsWindow *scoreStatsWindow;
  struct ScoreBonusWindow *scoreBonusWindow;
  struct FinalScoreSprite *finalScoreSprite;
  struct PlayerWindowExitSprite *playerWindowExitSprite;
  enum ScoreRank scoreRank;
  struct XPLevelBars *xpLevelBars;
  bool scoreRankAdded;
};
struct ScoreStatsWindow {
  struct UIElementContainer asUIElementContainer;
  struct StatLineList statLineList;
};
struct XPLevelBars {
  struct UIElementContainer asUIElementContainer;
  bool started;
  int prevTotalScore;
  int totalScore;
  int maxLevel;
  struct Image *bg;
  struct Image *gap;
  struct Image *frame;
  struct Image *piplXP;
  struct Image *pipmXP;
  struct Image *piprXP;
  struct Image *piplLevel;
  struct Image *pipmLevel;
  struct Image *piprLevel;
  int time;
  int maxTime;
  int currTotalScore;
  struct Label *nameLabel;
  struct Label *levelLabel;
  struct Label *xpLabel;
};
struct XPLevelScore {
  void *classptr;
  int32_t totalscore;
  uint32_t deeds;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ZoneScoreOverlay {
  struct WorldOverlay asWorldOverlay;
  struct Image *halftone;
  struct VisualElement *outro;
  struct PlayerWindowExitSprite *playerWindowExitSprite;
  struct STDVector keyValLabels; // std::pair<Label*,Label*>,std::allocator<std::pair<Label*,Label*> > 
  struct XPLevelBars *xpLevelBars;
  bool done;
};
struct EquipSlotSprite {
  struct SlotSprite asSlotSprite;
};
struct HomeSlotSprite {
  struct SlotSprite asSlotSprite;
};
struct KeysSlotSprite {
  struct SlotSprite asSlotSprite;
};
struct RejoinSlotSprite {
  struct SlotSprite asSlotSprite;
};
struct StringChoices {
  struct UIElementContainer asUIElementContainer;
  struct Handler onDone; // int
  int lineH;
  struct STDVector options; // std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > 
};
struct ToolTip__TextDesc {
  int fontSize;
};
struct KeysToolTip {
  struct ToolTip asToolTip;
};
struct PurchaseButton {
  struct ImageButton asImageButton;
  struct Handler onMouseOver;
  struct Label *ucLabel;
  struct Label *priceLabel;
};
struct UCPurchaseWindow {
  struct UIElementContainer asUIElementContainer;
  struct Handler onPurchaseButton; // PurchaseId
  struct Image *halftone;
  struct STDVector buttons; // PurchaseButton*,std::allocator<PurchaseButton*> 
  struct PurchaseButton *selected;
};
struct CloseButton {
  struct ImageButton asImageButton;
  struct Label *label;
};
struct UCVendorWindow {
  struct UIElementContainer asUIElementContainer;
};
struct KeyVal {
  void *classptr;
  struct STDString *key;
  struct STDString *val;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct KeyValList {
  void *classptr;
  struct RepeatedPtrField keyval; // KeyVal
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct AnimationGraphic {
  struct DynamicGraphic asDynamicGraphic;
  int startTime;
  int time;
  int rpX;
  int rpY;
  struct Animation *animation;
  bool flipH;
  bool flipV;
  int rotation;
  struct Rectangle drawRect; // int
  struct STDVector imageMaps; // std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > 
};
struct EdgeElementGraphic {
  struct Graphic asGraphic;
  int wrpX;
  int wrpY;
  int rotation;
  bool flipH;
  bool flipV;
  struct Visual *visual;
  enum BlendMode blendMode;
};
struct EmoteIcon {
  int32_t xmp;
  int32_t ymp;
  struct AnimatedImage *animImage;
  struct Rectangle rect; // int
  struct Animation *cAnim;
  struct Animation *aAnim;
  struct Animation *dAnim;
  int startT;
  int createDoneT;
  int destroyStartT;
  int32_t xVel;
  int32_t yVel;
  int32_t yAccel;
};
struct TestGraphic {
  struct Graphic asGraphic;
};
enum HitNumberGraphic__NumType {
  NT_SELF_HURT = 0x0,
  NT_ALLY_HURT = 0x1,
  NT_SELF_ATTACK = 0x2,
  NT_ALLY_ATTACK = 0x3,
  NT_SELF_CRIT = 0x4,
  NT_ALLY_CRIT = 0x5,
  NT_SELF_ARMOR = 0x6,
  NT_ALLY_ARMOR = 0x7,
  NUM_NT = 0x8,
};
struct HitNumberGraphic {
  struct DynamicGraphic asDynamicGraphic;
  bool isCrit;
  bool isSelf;
  enum HitNumberGraphic__NumType nt;
  int startTime;
  int x;
  int y;
  double xVel;
  struct NumberTexture *numTexture;
};
struct HitNumberGraphic__TextProps {
  uint32_t color;
  int size;
  int dz;
};
struct PlayerBoostGraphic {
  struct DynamicGraphic asDynamicGraphic;
  int startTime;
  int lifetime;
  int x;
  int y;
  struct TextTexture *textTexture;
};
struct PlayerTextGraphic {
  struct DynamicGraphic asDynamicGraphic;
  int x;
  int y;
  int startTime;
  int lifetime;
  struct TextTexture *textTexture;
};
struct ScatterGraphic {
  struct Graphic asGraphic;
  int iX;
  int iY;
  int rpX;
  int rpY;
  bool flipH;
  unsigned char parallax;
  struct Visual *visual;
  enum BlendMode blendMode;
  enum Anim anim;
  int animPos;
};
struct ScatterMovingGraphic {
  struct DynamicGraphic asDynamicGraphic;
  int iX;
  int iY;
  int rpX;
  int rpY;
  int xps;
  int yps;
  bool flipH;
  struct Rectangle bounds; // int
  unsigned char parallax;
  struct Visual *visual;
  enum BlendMode blendMode;
};
struct TilesDescription {
  void *classptr;
  struct STDString *vid;
  uint32_t gdv;
  int32_t z;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct DecorationDescription_Uniform_Layer {
  void *classptr;
  int32_t depthend;
  int32_t tilewidth;
  struct STDString *vid;
  int32_t tileheight;
  uint32_t blendmode;
  bool allowfliph;
  bool allowflipv;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct DecorationDescription_Uniform {
  void *classptr;
  int32_t z;
  uint32_t mingq;
  uint32_t maxgq;
  uint32_t gdv;
  struct RepeatedPtrField layer; // DecorationDescription_Uniform_Layer
  int32_t xps;
  int32_t yps;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct DecorationDescription_Scatter {
  void *classptr;
  struct STDString *name;
  struct RepeatedField_int type;
  struct RepeatedField_int mingq;
  uint32_t maxgq;
  uint32_t gdv;
  struct DecorationDescription_Scatter_Bounds *bounds;
  int32_t xps;
  int32_t xpsjitter;
  int32_t yps;
  int32_t ypsjitter;
  int32_t z;
  int32_t zjitter;
  int32_t frequency;
  int32_t spacingwidth;
  struct STDString *vid;
  int32_t spacingheight;
  uint32_t blendmode;
  bool allowfliph;
  int32_t widthoverride;
  int32_t heightoverride;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct DecorationDescription_Scatter_Bounds {
  void *classptr;
  float left;
  float top;
  float right;
  float bottom;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct DecorationDescription_Edge {
  void *classptr;
  struct STDString *name;
  struct RepeatedField_int type;
  struct RepeatedField_int mingq;
  uint32_t maxgq;
  uint32_t gdv;
  int32_t frequency;
  int32_t widthoverride;
  int32_t heightoverride;
  int32_t spacingwidth;
  int32_t spacingheight;
  bool allowfliph;
  struct STDString *vidrestrict;
  struct RepeatedPtrField element; // DecorationDescription_Edge_Element
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct DecorationDescription_Fill {
  void *classptr;
  int32_t z;
  uint32_t mingq;
  uint32_t maxgq;
  uint32_t gdv;
  uint32_t color;
  uint32_t blendmode;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct DecorationDescription_Edge_Element {
  void *classptr;
  struct STDString *vid;
  int32_t z;
  uint32_t blendmode;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct Emote {
  void *classptr;
  struct ObjKeyMessage *obj;
  uint32_t emote;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ShowCharScore {
  void *classptr;
  struct CharacterProperties *charprops;
  struct STDString *username;
  struct XPLevelScore *xplevelscore;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ShowZoneCompleteScore {
  void *classptr;
  uint32_t zonetype;
  int32_t prevnum;
  int32_t maxnum;
  int32_t score;
  struct XPLevelScore *xplevelscore;
  int32_t prevtotalscore;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ServerDeltaAck {
  void *classptr;
  struct WorldState *worldstate;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct InitPurchase {
  void *classptr;
  uint32_t purchaseid;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct FactionAction {
  void *classptr;
  struct STDString *factionname;
  uint32_t type;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct ControllerState {
  int axis[6];
};
struct TextureData {
  int w;
  int h;
};
struct NumberDictData {
  int digitPos[10];
  int digitWidth[10];
  int height;
  int spacing;
};
struct SFX {
  struct STDString soundPath;
  struct Mix_Chunk *chunk;
};
struct Mix_Chunk {
  int allocated;
  uint8_t *abuf;
  uint32_t alen;
  uint8_t volume;
};
enum MIX_InitFlags {
  MIX_INIT_FLAC = 0x1,
  MIX_INIT_MOD = 0x2,
  MIX_INIT_MODPLUG = 0x4,
  MIX_INIT_MP3 = 0x8,
  MIX_INIT_OGG = 0x10,
  MIX_INIT_FLUIDSYNTH = 0x20,
};
enum IMG_InitFlags {
  IMG_INIT_JPG = 0x1,
  IMG_INIT_PNG = 0x2,
  IMG_INIT_TIF = 0x4,
  IMG_INIT_WEBP = 0x8,
};
struct ShaderProgramData {
  unsigned int program;
  unsigned int vshader;
  unsigned int fshader;
  int attributes[8];
  int uniforms[8];
};
enum DrawMode {
  MODE_INVALID = 0x0,
  MODE_COLOR_POINTS = 0x1,
  MODE_COLOR_LINES = 0x2,
  MODE_COLOR_TRIANGLES = 0x3,
  MODE_TEXTURE_TRIANGLES = 0x4,
};
enum FlushReason {
  FLUSH_PRESENT = 0x0,
  FLUSH_MAX_VERTEX = 0x1,
  FLUSH_DRAW_MODE = 0x2,
  FLUSH_BLEND_MODE = 0x3,
  FLUSH_DRAW_COLOR = 0x4,
  FLUSH_TEXTURE_UNITS = 0x5,
  NUM_FLUSH = 0x6,
};
struct EmptyMessage {
  void *classptr;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct CharacterDescription_StartingItem {
  void *classptr;
  struct STDString *name;
  int32_t _cached_size;
  uint32_t _has_bits[1];
};
struct LZ4_stream_t {
  long long table[2052];
};
struct LZ4_streamDecode_t {
  unsigned long long table[4];
};
struct LZ4_stream_t_internal {
  unsigned int hashTable[4096];
  unsigned int currentOffset;
  unsigned int initCheck;
  unsigned char *dictionary;
  unsigned char *bufferStart;
  unsigned int dictSize;
};
struct LZ4_streamDecode_t_internal {
  unsigned char *externalDict;
  size_t extDictSize;
  unsigned char *prefixEnd;
  size_t prefixSize;
};
struct RC4_CTX_0 {
  uint8_t x;
  uint8_t y;
  uint8_t m[256];
};
typedef void (*demangle_callbackref)(const char *, size_t, void *);
struct DWstruct {
  int low;
  int high;
};
typedef void (*func_ptr)(void);
struct LONG_DOUBLE_12 {
  // _TBYTE value;
  char padding[2];
};
