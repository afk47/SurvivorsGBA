#ifndef BN_REGULAR_BG_ITEMS_WHITEBG_H
#define BN_REGULAR_BG_ITEMS_WHITEBG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(whitebg_bn_gfx)

//======================================================================
//
//	whitebg_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 2 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 64 + 2048 = 2144
//
//	Time-stamp: 2024-05-21, 04:28:57
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_WHITEBG_BN_GFX_H
#define GRIT_WHITEBG_BN_GFX_H

#define whitebg_bn_gfxTilesLen 64
extern const bn::tile whitebg_bn_gfxTiles[2];

#define whitebg_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell whitebg_bn_gfxMap[1024];

#define whitebg_bn_gfxPalLen 32
extern const bn::color whitebg_bn_gfxPal[16];

#endif // GRIT_WHITEBG_BN_GFX_H

//}}BLOCK(whitebg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item whitebg(
            regular_bg_tiles_item(span<const tile>(whitebg_bn_gfxTiles, 2), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(whitebg_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(whitebg_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

