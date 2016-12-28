#pragma once

#include <3ds.h>

///@name Initialization and basic operations
///@{

/// Ensures the Chinese font is mapped.
Result fontMappedCN(void);

/// Retrieves the font information structure of the Chinese font.
static inline FINF_s* fontGetInfoCN(void)
{
	extern CFNT_s* g_cnFont;
	return &g_cnFont->finf;
}

/// Retrieves the texture sheet information of the Chinese font.
static inline TGLP_s* fontGetGlyphInfoCN(void)
{
	return fontGetInfoCN()->tglp;
}

/**
 * @brief Retrieves the pointer to texture data for the specified texture sheet.
 * @param sheetIndex Index of the texture sheet.
 */
static inline void* fontGetGlyphSheetTexCN(int sheetIndex)
{
	TGLP_s* tglp = fontGetGlyphInfoCN();
	return &tglp->sheetData[sheetIndex*tglp->sheetSize];
}

/**
 * @brief Retrieves the glyph index of the specified Unicode codepoint.
 * @param codePoint Unicode codepoint.
 */
int fontGlyphIndexFromCodePointCN(u32 codePoint);

/**
 * @brief Retrieves character width information of the specified glyph.
 * @param glyphIndex Index of the glyph.
 */
charWidthInfo_s* fontGetCharWidthInfoCN(int glyphIndex);

/**
 * @brief Calculates position information for the specified glyph.
 * @param out Output structure in which to write the information.
 * @param glyphIndex Index of the glyph.
 * @param flags Calculation flags (see GLYPH_POS_* flags).
 * @param scaleX Scale factor to apply horizontally.
 * @param scaleY Scale factor to apply vertically.
 */
void fontCalcGlyphPosCN(fontGlyphPos_s* out, int glyphIndex, u32 flags, float scaleX, float scaleY);
