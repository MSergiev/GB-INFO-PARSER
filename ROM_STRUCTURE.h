#ifndef ROM_STRUCT_H
#define ROM_STRUCT_H

#include <map>
#include <string>

static const unsigned char LOGO[] = {
    0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B, 0x03, 0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D, 
    0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E, 0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99, 
    0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC, 0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E
};

static const std::map<std::string, std::pair<unsigned, unsigned> > HEADER = {
    {"ENTRY",   {0x100, 3} },
    {"LOGO",    {0x104, 48} },
    {"TITLE",   {0x134, 16} },
    {"CGB",     {0x143, 1} },
    {"LIC",     {0x144, 2} },
    {"SGB",     {0x146, 1} },
    {"CART",    {0x147, 1} },
    {"ROMSIZE", {0x148, 1} },
    {"RAMSIZE", {0x149, 1} },
    {"DEST",    {0x14A, 1} },
    {"OLIC",    {0x14B, 1} },
    {"VNUM",    {0x14C, 1} },
    {"HCHECK",  {0x14D, 1} },
    {"GCHECK",  {0x13E, 2} },
};

static const std::map<char, std::string> CART = {
    {0x00, "ROM ONLY"},
    {0x01, "MBC1"},
    {0x02, "MBC1 + RAM"},
    {0x03, "MBC1 + RAM + BATTERY"},
    {0x05, "MBC2"},
    {0x06, "MBC2 + BATTERY"},
    {0x08, "ROM + RAM"},
    {0x09, "ROM + RAM + BATTERY"},
    {0x0B, "MMM01"},
    {0x0C, "MMM01 + RAM"},
    {0x0D, "MMM01 + RAM + BATTERY"},
    {0x0F, "MBC3 + TIMER + BATTERY"},
    {0x10, "MBC3 + TIMER + RAM + BATTERY"},
    {0x11, "MBC3"},
    {0x12, "MBC3 + RAM"},
    {0x13, "MBC3 + RAM + BATTERY"},
    {0x15, "MBC4"},
    {0x16, "MBC4 + RAM"},
    {0x17, "MBC4 + RAM + BATTERY"},
    {0x19, "MBC5"},
    {0x1A, "MBC5 + RAM"},
    {0x1B, "MBC5 + RAM + BATTERY"},
    {0x1C, "MBC5 + RUMBLE"},
    {0x1D, "MBC5 + RUMBLE + RAM"},
    {0x1E, "MBC5 + RUMBLE + RAM + BATTERY"},
    {0xFC, "POCKET CAMERA"},
    {0xFD, "BANDAI TAMA5"},
    {0xFE, "HuC3"},
    {0xFF, "HuC1 + RAM + BATTERY"},
};

static const std::map<char, std::string> LIC {
    {0x00, "None" },
    {0x01, "Nintendo R&D1" },
    {0x08, "Capcom" },
    {0x13, "Electronic Arts" },
    {0x18, "Hudson Soft" },
    {0x19, "B-AI" },
    {0x20, "KSS" },
    {0x22, "POW" },
    {0x24, "PCM Complete" },
    {0x25, "San-x" },
    {0x28, "Kemco Japan" },
    {0x29, "Seta" },
    {0x30, "Viacom" },
    {0x31, "Nintendo" },
    {0x32, "Bandai" },
    {0x33, "Ocean/Acclaim" },
    {0x34, "Konami" },
    {0x35, "Hector" },
    {0x37, "Taito" },
    {0x38, "Hudson" },
    {0x39, "Banpresto" },
    {0x41, "Ubi Soft" },
    {0x42, "Atlus" },
    {0x44, "Malibu" },
    {0x46, "Angel" },
    {0x47, "Bullet-Proof" },
    {0x49, "IRem" },
    {0x50, "Absolute" },
    {0x51, "Acclaim" },
    {0x52, "Activision" },
    {0x53, "American Sammy" },
    {0x54, "Konami" },
    {0x55, "Hi Tech Entertainment" },
    {0x56, "LJN" },
    {0x57, "Matchbox" },
    {0x58, "Mattel" },
    {0x59, "Milton Bradley" },
    {0x60, "Titus" },
    {0x61, "Virgin" },
    {0x64, "LucasArts" },
    {0x67, "Ocean" },
    {0x69, "Electronic Arts" },
    {0x70, "Infogrames" },
    {0x71, "Interplay" },
    {0x72, "Broderbund" },
    {0x73, "Sculptured" },
    {0x75, "SCI" },
    {0x78, "THQ" },
    {0x79, "Accolade" },
    {0x80, "Misawa" },
    {0x83, "Lozc" },
    {0x86, "Tokuma Shoten I" },
    {0x87, "Tsukuda Ori" },
    {0x91, "Chunsoft" },
    {0x92, "Video System" },
    {0x93, "Ocean/Acclaim" },
    {0x95, "Varie" },
    {0x96, "Yonezawa's Pal" },
    {0x97, "Kaneko" },
    {0x99, "Pack In Soft" },
    {0xA4, "Konami" },
};

static const std::map<char, std::string> OLIC {
    {0x00,	"None" },
    {0x01,	"Nintendo" },
    {0x08,	"Capcom" },
    {0x09,	"Hot-b" },
    {0x0A,	"Jaleco" },
    {0x0B,	"Coconuts" },
    {0x0C,	"Elite Systems" },
    {0x13,	"Electronic Arts" },
    {0x18,	"Hudsonsoft" },
    {0x19,	"Itc Entertainment" },
    {0x1A,	"Yanoman" },
    {0x1D,	"Clary" },
    {0x1F,	"Virgin" },
    {0x24,	"Pcm complete" },
    {0x25,	"San-x" },
    {0x28,	"Kotobuki Systems" },
    {0x29,	"Seta" },
    {0x30,	"Infogrames" },
    {0x31,	"Nintendo" },
    {0x32,	"Bandai" },
    {0x33,	"GBC" },
    {0x34,	"Konami" },
    {0x35,	"Hector" },
    {0x38,	"Capcom" },
    {0x39,	"Banpresto" },
    {0x3C,	"Entertainment I" },
    {0x3E,	"Gremlin" },
    {0x41,	"Ubisoft" },
    {0x42,	"Atlus" },
    {0x44,	"Malibu" },
    {0x46,	"Angel" },
    {0x47,	"Spectrum Holoby" },
    {0x49,	"IRem" },
    {0x4A,	"Virgin" },
    {0x4D,	"Malibu" },
    {0x4F,	"U.S. Gold" },
    {0x50,	"Absolute" },
    {0x51,	"Acclaim" },
    {0x52,	"Activision" },
    {0x53,	"American Sammy" },
    {0x54,	"Gametek" },
    {0x55,	"Park Place" },
    {0x56,	"LJN" },
    {0x57,	"Matchbox" },
    {0x59,	"Milton Bradley" },
    {0x5A,	"Mindscape" },
    {0x5B,	"Romstar" },
    {0x5C,	"Naxat Soft" },
    {0x5D,	"Tradewest" },
    {0x60,	"Titus" },
    {0x61,	"Virgin" },
    {0x67,	"Ocean" },
    {0x69,	"Electronic Arts" },
    {0x6E,	"Elite Systems" },
    {0x6F,	"Electro Brain" },
    {0x70,	"Infogrames" },
    {0x71,	"Interplay" },
    {0x72,	"Broderbund" },
    {0x73,	"Sculptered Soft" },
    {0x75,	"The Sales Curve" },
    {0x78,	"THQ" },
    {0x79,	"Accolade" },
    {0x7A,	"Triffix Entertainment" },
    {0x7C,	"Microprose" },
    {0x7F,	"Kemco" },
    {0x80,	"Misawa Entertainment" },
    {0x83,	"Lozc" },
    {0x86,	"Tokuma Shoten Intermedia" },
    {0x8B,	"Bullet-Proof Software" },
    {0x8C,	"Vic Tokai" },
    {0x8E,	"Ape" },
    {0x8F,	"I'max" },
    {0x91,	"Chun Soft" },
    {0x92,	"Video System" },
    {0x93,	"Tsuburava" },
    {0x95,	"Varie" },
    {0x96,	"Yonezawa's pal" },
    {0x97,	"Kaneko" },
    {0x99,	"Arc" },
    {0x9A,	"Nihon Bussan" },
    {0x9B,	"Tecmo" },
    {0x9C,	"Imagineer" },
    {0x9D,	"Banpresto" },
    {0x9F,	"Nova" },
    {0xA1,	"Hori Electric" },
    {0xA2,	"Bandai" },
    {0xA4,	"Konami" },
    {0xA6,	"Kawada" },
    {0xA7,	"Takara" },
    {0xA9,	"Technos Japan" },
    {0xAA,	"Broderbund" },
    {0xAC,	"Toei Animation" },
    {0xAD,	"Toho" },
    {0xAF,	"Namco" },
    {0xB0,	"Acclaim" },
    {0xB1,	"Ascii/Nexoft" },
    {0xB2,	"Bandai" },
    {0xB4,	"Enix" },
    {0xB6,	"HAL" },
    {0xB7,	"SNK" },
    {0xB9,	"Pony Canyon" },
    {0xBA,	"Culture Brain O" },
    {0xBB,	"Sunsoft" },
    {0xBD,	"Sony Imagesoft" },
    {0xBF,	"Sammy" },
    {0xC0,	"Taito" },
    {0xC2,	"Kemco" },
    {0xC3,	"SquareSoft" },
    {0xC4,	"Tokuma Shoten Intermedia" },
    {0xC5,	"Data East" },
    {0xC6,	"Tonkin House" },
    {0xC8,	"Koei" },
    {0xC9,	"UFL" },
    {0xCA,	"Ultra" },
    {0xCB,	"Yap" },
    {0xCC,	"Use" },
    {0xCD,	"Meldac" },
    {0xCE,	"Pony Canyon" }, 
    {0xCF,	"Angel" },
    {0xD0,	"Taito" },
    {0xD1,	"Sofel" },
    {0xD2,	"Quest" },
    {0xD3,	"Sigma Enterprises" },
    {0xD4,	"Ask Kodansha" },
    {0xD6,	"Naxat Soft" },
    {0xD7,	"Copya Systems" },
    {0xD9,	"Banpresto" },
    {0xDA,	"Tomy" },
    {0xDB,	"LJN" },
    {0xDD,	"NCS" },
    {0xDE,	"Human" },
    {0xDF,	"Altron" },
    {0xE0,	"Jaleco" },
    {0xE1,	"Towachiki" },
    {0xE2,	"Uutaka" },
    {0xE3,	"Varie" },
    {0xE5,	"Epoch" },
    {0xE7,	"Athena" },
    {0xE8,	"Asmik" },
    {0xE9,	"Natsume" },
    {0xEA,	"King Records" },
    {0xEB,	"Atlus" },
    {0xEC,	"Epic/Sony records" },
    {0xEE,	"IGS" },
    {0xF0,	"A Wave" },
    {0xF3,	"Extreme Entertainment" },
    {0xFF,	"LJN" },
};

static const std::map<char, unsigned> ROMSIZE = {
   {0x00,   32768},
   {0x01,   65536},
   {0x02,   131072},
   {0x03,   262144},
   {0x04,   524288},
   {0x05,   1048576},
   {0x06,   2097152},
   {0x07,   4194304},
   {0x08,   8388608},
   {0x52,   1179648},
   {0x53,   1310720},
   {0x54,   1572864},
};

static const std::map<char, unsigned> RAMSIZE = {
   {0x00,   0},
   {0x01,   2048},
   {0x02,   8192},
   {0x03,   32768},
   {0x04,   131072},
   {0x05,   65536},
};

static const std::map<char, std::string> DEST = {
   {0x00,   "Japan"},
   {0x01,   "World"},
};

static const std::map<char, std::string> CGB = {
   {0x00,   "GB"},
   {0xC0,   "CGB"},
   {0x80,   "GB/CGB"},
};

#endif
