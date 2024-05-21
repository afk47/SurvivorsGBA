#ifndef BN_SPRITE_ITEMS_GOBLIN_H
#define BN_SPRITE_ITEMS_GOBLIN_H

#include "bn_sprite_item.h"

//{{BLOCK(goblin_bn_gfx)

//======================================================================
//
//	goblin_bn_gfx, 16x160@4, 
//	+ palette 16 entries, not compressed
//	+ 40 tiles not compressed
//	Total size: 32 + 1280 = 1312
//
//	Time-stamp: 2024-05-21, 04:28:57
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GOBLIN_BN_GFX_H
#define GRIT_GOBLIN_BN_GFX_H

#define goblin_bn_gfxTilesLen 1280
extern const bn::tile goblin_bn_gfxTiles[40];

#define goblin_bn_gfxPalLen 32
extern const bn::color goblin_bn_gfxPal[16];

#endif // GRIT_GOBLIN_BN_GFX_H

//}}BLOCK(goblin_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item goblin(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(goblin_bn_gfxTiles, 40), bpp_mode::BPP_4, compression_type::NONE, 10), 
            sprite_palette_item(span<const color>(goblin_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

