
void __fastcall FUN_0049c5b9(int param_1)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = FUN_00635845();
  if (iVar2 != 0) {
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fDitherOffsets_0__006c65f0,
                 *(undefined4 *)(param_1 + 0x20));
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fDitherOffsets_1__006c65dc,
                 *(undefined4 *)(param_1 + 0x24));
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fDitherOffsets_2__006c65c8,
                 *(undefined4 *)(param_1 + 0x28));
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fDitherOffsets_3__006c65b4,
                 *(undefined4 *)(param_1 + 0x2c));
    FUN_006357d8(iVar2,&DAT_006c08dc);
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fJitterEnvelope_006c65a4,
                 *(undefined4 *)(param_1 + 0x30));
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fJitterRandSeed_006c6594,
                 *(undefined4 *)(param_1 + 0x34));
    FUN_006357d8(iVar2,&DAT_006c08dc);
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fNumShades_006c6588,*(undefined4 *)(param_1 + 0x4c));
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fMinColorIndex_006c6578,*(undefined4 *)(param_1 + 0x38)
                );
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fMaxColorIndex_006c6568,*(undefined4 *)(param_1 + 0x3c)
                );
    FUN_006357d8(iVar2,&DAT_006c08dc);
    FUN_006357d8(iVar2,s__s____f__006c6544,s_fLightSourceLongitude_006c6550,
                 (double)*(float *)(param_1 + 0x40));
    FUN_006357d8(iVar2,s__s____f__006c6544,s_fLightSourceLatitude_006c652c,
                 (double)*(float *)(param_1 + 0x44));
    FUN_006357d8(iVar2,&DAT_006c08dc);
    uVar1 = *(uint *)(param_1 + 0x50);
    FUN_006357d8(iVar2,s__s___RGB_MAKE__d___d___d___006c6510,s_fLightGreen_006c6504,
                 uVar1 >> 0x10 & 0xff,uVar1 >> 8 & 0xff,uVar1 & 0xff);
    uVar1 = *(uint *)(param_1 + 0x54);
    FUN_006357d8(iVar2,s__s___RGB_MAKE__d___d___d___006c6510,s_fDarkGreen_006c64f8,
                 uVar1 >> 0x10 & 0xff,uVar1 >> 8 & 0xff,uVar1 & 0xff);
    uVar1 = *(uint *)(param_1 + 0x58);
    FUN_006357d8(iVar2,s__s___RGB_MAKE__d___d___d___006c6510,s_fLightBrown_006c64ec,
                 uVar1 >> 0x10 & 0xff,uVar1 >> 8 & 0xff,uVar1 & 0xff);
    uVar1 = *(uint *)(param_1 + 0x5c);
    FUN_006357d8(iVar2,s__s___RGB_MAKE__d___d___d___006c6510,s_fDarkBrown_006c64e0,
                 uVar1 >> 0x10 & 0xff,uVar1 >> 8 & 0xff,uVar1 & 0xff);
    uVar1 = *(uint *)(param_1 + 0xbc);
    FUN_006357d8(iVar2,s__s___RGB_MAKE__d___d___d___006c6510,s_fHiliteLightGreen_006c64cc,
                 uVar1 >> 0x10 & 0xff,uVar1 >> 8 & 0xff,uVar1 & 0xff);
    uVar1 = *(uint *)(param_1 + 0xc0);
    FUN_006357d8(iVar2,s__s___RGB_MAKE__d___d___d___006c6510,s_fHiliteDarkGreen_006c64b8,
                 uVar1 >> 0x10 & 0xff,uVar1 >> 8 & 0xff,uVar1 & 0xff);
    uVar1 = *(uint *)(param_1 + 0xc4);
    FUN_006357d8(iVar2,s__s___RGB_MAKE__d___d___d___006c6510,s_fHiliteLightRed_006c64a8,
                 uVar1 >> 0x10 & 0xff,uVar1 >> 8 & 0xff,uVar1 & 0xff);
    uVar1 = *(uint *)(param_1 + 200);
    FUN_006357d8(iVar2,s__s___RGB_MAKE__d___d___d___006c6510,s_fHiliteDarkRed_006c6498,
                 uVar1 >> 0x10 & 0xff,uVar1 >> 8 & 0xff,uVar1 & 0xff);
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fNumColors_006c648c,*(undefined4 *)(param_1 + 0x7c));
    FUN_006357d8(iVar2,&DAT_006c08dc);
    pcVar3 = &DAT_006c0aac;
    if (*(char *)(param_1 + 0x80) == '\0') {
      pcVar3 = s_false_006c0ab4;
    }
    FUN_006357d8(iVar2,s__s____s__006c646c,s_fEnableBladeGrass_006c6478,pcVar3);
    pcVar3 = &DAT_006c0aac;
    if (*(char *)(param_1 + 0x81) == '\0') {
      pcVar3 = s_false_006c0ab4;
    }
    FUN_006357d8(iVar2,s__s____s__006c646c,s_fEnableSpriteGrass_006c6458,pcVar3);
    pcVar3 = &DAT_006c0aac;
    if (*(char *)(param_1 + 0x82) == '\0') {
      pcVar3 = s_false_006c0ab4;
    }
    FUN_006357d8(iVar2,s__s____s__006c646c,s_fDrawSmallGrass_006c6448,pcVar3);
    FUN_006357d8(iVar2,&DAT_006c08dc);
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fColorRandSeed_006c6438,*(undefined4 *)(param_1 + 0x84)
                );
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fGrassRandSeed_006c6428,*(undefined4 *)(param_1 + 0x88)
                );
    FUN_006357d8(iVar2,&DAT_006c08dc);
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fShadeDispMin_006c6418,*(undefined4 *)(param_1 + 0x90))
    ;
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fShadeDispMax_006c6408,*(undefined4 *)(param_1 + 0x94))
    ;
    pcVar3 = &DAT_006c0aac;
    if (*(char *)(param_1 + 0x98) == '\0') {
      pcVar3 = s_false_006c0ab4;
    }
    FUN_006357d8(iVar2,s__s____s__006c646c,s_fShadeDispInvertible_006c63f0,pcVar3);
    FUN_006357d8(iVar2,&DAT_006c08dc);
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fGrassLowDensityValue_006c63d8,
                 *(undefined4 *)(param_1 + 0x9c));
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fGrassHighDensityValue_006c63c0,
                 *(undefined4 *)(param_1 + 0xa0));
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fQ0MaxGrassBladesPerTile_006c63a4,
                 *(undefined4 *)(param_1 + 0xa4));
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fQ0MinGrassBladesPerTile_006c6388,
                 *(undefined4 *)(param_1 + 0xa8));
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fQ1MaxGrassBladesPerTile_006c636c,
                 *(undefined4 *)(param_1 + 0xac));
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fQ1MinGrassBladesPerTile_006c6350,
                 *(undefined4 *)(param_1 + 0xb0));
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fQ2MaxGrassBladesPerTile_006c6334,
                 *(undefined4 *)(param_1 + 0xb4));
    FUN_006357d8(iVar2,s__s____d__006c6604,s_fQ2MinGrassBladesPerTile_006c6318,
                 *(undefined4 *)(param_1 + 0xb8));
    FUN_0063558d(iVar2);
  }
  return;
}

