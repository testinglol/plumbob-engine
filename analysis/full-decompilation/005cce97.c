
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005cce97(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  char cVar7;
  uint uVar8;
  float *pfVar9;
  int iVar10;
  float *pfVar11;
  int *piVar12;
  int iVar13;
  float local_1d0;
  float fStack_1cc;
  float fStack_1c8;
  float fStack_1c4;
  float fStack_1c0;
  float fStack_1bc;
  float fStack_1b8;
  float fStack_1b4;
  float local_1b0;
  float fStack_1ac;
  float fStack_1a8;
  float fStack_1a4;
  float local_1a0 [4];
  float local_190 [4];
  float fStack_180;
  float fStack_17c;
  float fStack_178;
  float fStack_174;
  float fStack_170;
  float fStack_16c;
  float fStack_168;
  float fStack_164;
  float fStack_160;
  float fStack_15c;
  float fStack_158;
  float fStack_154;
  float fStack_150;
  float fStack_14c;
  float fStack_148;
  float local_144;
  float local_140;
  float local_13c;
  float local_138;
  float local_134;
  float local_130;
  float local_12c;
  float local_128;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  float fStack_114;
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  float afStack_e4 [4];
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float local_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  tagRECT local_6c;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float local_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  uint local_2c;
  float local_28;
  uint local_24;
  uint local_20;
  float local_1c;
  uint local_18;
  char local_11;
  int *local_10;
  float *local_c;
  float local_8;
  
  if (DAT_006d6184 == 0) {
    return;
  }
  if (((char)param_1[3] != '\0') || ((uint)(param_1[1] - *param_1 >> 4) < 2)) {
    *(undefined1 *)(param_1 + 3) = 1;
    return;
  }
  local_2c = 1;
  local_10 = param_1;
LAB_005cced7:
  piVar12 = local_10;
  if (1 < (uint)(local_10[1] - *local_10 >> 4)) {
    local_24 = 0;
    while( true ) {
      iVar13 = *piVar12;
      uVar8 = piVar12[1] - iVar13 >> 4;
      if (uVar8 - 1 <= local_24) break;
      local_11 = '\0';
      pfVar11 = (float *)(local_24 * 0x10 + iVar13);
      if (((int)*pfVar11 < (int)pfVar11[2]) && ((int)pfVar11[1] < (int)pfVar11[3])) {
        local_20 = local_24 + 1;
        if (local_20 < uVar8) {
          do {
            local_c = (float *)(local_20 * 0x10 + iVar13);
            fVar4 = local_c[2];
            if ((((int)fVar4 <= (int)*local_c) || ((int)local_c[3] <= (int)local_c[1])) ||
               (((int)*pfVar11 <= (int)*local_c &&
                ((((int)fVar4 <= (int)pfVar11[2] && ((int)pfVar11[1] <= (int)local_c[1])) &&
                 ((int)local_c[3] <= (int)pfVar11[3])))))) {
              FUN_005db3b0(local_c);
              local_20 = local_20 - 1;
              goto LAB_005cdb13;
            }
            if ((((int)*local_c <= (int)*pfVar11) && ((int)pfVar11[2] <= (int)fVar4)) &&
               (((int)local_c[1] <= (int)pfVar11[1] && ((int)pfVar11[3] <= (int)local_c[3])))) {
              *pfVar11 = *local_c;
              pfVar11[1] = local_c[1];
              pfVar11[2] = local_c[2];
              pfVar11[3] = local_c[3];
              pfVar11 = local_c;
              goto code_r0x005cdc69;
            }
            cVar7 = FUN_005240ec();
            if (cVar7 == '\0') goto LAB_005cdb13;
            fVar4 = *pfVar11;
            local_18 = 0;
            local_8 = *local_c;
            local_1c = local_c[1];
            if ((((int)fVar4 <= (int)local_8) && ((int)local_8 <= (int)pfVar11[2])) &&
               (((int)pfVar11[1] <= (int)local_1c && ((int)local_1c <= (int)pfVar11[3])))) {
              local_18 = 8;
            }
            local_28 = local_c[2];
            if (((((int)fVar4 <= (int)local_28) && ((int)local_28 <= (int)pfVar11[2])) &&
                ((int)pfVar11[1] <= (int)local_1c)) && ((int)local_1c <= (int)pfVar11[3])) {
              local_18 = local_18 | 4;
            }
            fVar5 = local_c[3];
            if ((((int)fVar4 <= (int)local_8) && ((int)local_8 <= (int)pfVar11[2])) &&
               (((int)pfVar11[1] <= (int)fVar5 && ((int)fVar5 <= (int)pfVar11[3])))) {
              local_18 = local_18 | 2;
            }
            if ((((int)fVar4 <= (int)local_28) && ((int)local_28 <= (int)pfVar11[2])) &&
               (((int)pfVar11[1] <= (int)fVar5 && ((int)fVar5 <= (int)pfVar11[3])))) {
              local_18 = local_18 | 1;
            }
            if (local_18 == 0) {
              local_18 = 0;
              if ((((((int)fVar4 <= (int)local_8) && ((int)local_8 <= (int)pfVar11[2])) &&
                   ((int)local_1c <= (int)pfVar11[1])) &&
                  (((int)fVar4 <= (int)local_8 && ((int)local_8 <= (int)pfVar11[2])))) &&
                 ((int)pfVar11[3] <= (int)fVar5)) {
                local_18 = 8;
              }
              if ((((int)fVar4 <= (int)local_28) && ((int)local_28 <= (int)pfVar11[2])) &&
                 (((int)local_1c <= (int)pfVar11[1] &&
                  ((((int)fVar4 <= (int)local_28 && ((int)local_28 <= (int)pfVar11[2])) &&
                   ((int)pfVar11[3] <= (int)fVar5)))))) {
                local_18 = local_18 | 4;
              }
              if ((int)local_8 <= (int)fVar4) {
                if ((((int)pfVar11[1] <= (int)local_1c) && ((int)local_1c <= (int)pfVar11[3])) &&
                   (((int)pfVar11[2] <= (int)local_28 &&
                    (((int)pfVar11[1] <= (int)local_1c && ((int)local_1c <= (int)pfVar11[3])))))) {
                  local_18 = local_18 | 2;
                }
                if ((((((int)local_8 <= (int)fVar4) && ((int)pfVar11[1] <= (int)fVar5)) &&
                     ((int)fVar5 <= (int)pfVar11[3])) &&
                    (((int)pfVar11[2] <= (int)local_28 && ((int)pfVar11[1] <= (int)fVar5)))) &&
                   ((int)fVar5 <= (int)pfVar11[3])) {
                  local_18 = local_18 | 1;
                }
              }
              local_5c = *local_c;
              local_58 = local_c[1];
              local_54 = local_c[2];
              local_50 = local_c[3];
              local_7c = *local_c;
              local_78 = local_c[1];
              local_74 = local_c[2];
              local_70 = local_c[3];
              if (local_18 != 1) {
                if (local_18 == 2) {
                  if (local_1c == pfVar11[3]) goto LAB_005cda0e;
                  local_c[1] = pfVar11[3];
                  goto LAB_005cd9f4;
                }
                if (local_18 == 3) {
                  local_c[2] = fVar4;
                  local_5c = pfVar11[2];
LAB_005cd6a5:
                  local_b4 = *pfVar11;
                  local_b0 = pfVar11[1];
                  local_8 = (float)(((int)local_50 - (int)local_58) *
                                   ((int)local_54 - (int)local_5c)) + DAT_006fe838;
                  local_ac = pfVar11[2];
                  local_a8 = pfVar11[3];
                  FUN_00422698();
                  local_134 = local_b4;
                  local_130 = local_b0;
                  local_12c = local_ac;
                  local_128 = local_a8;
                  FUN_00422698();
                  iVar13 = 0;
                  local_190[0] = (float)(((int)local_128 - (int)local_130) *
                                        ((int)local_12c - (int)local_134)) + DAT_006fe838;
                  local_190[1] = (float)(((int)local_ac - (int)local_b4) *
                                        ((int)local_a8 - (int)local_b0)) + local_8 + DAT_006fe838;
                  local_1c = (float)(((int)local_c[2] - (int)*local_c) *
                                    ((int)local_c[3] - (int)local_c[1]));
                  iVar10 = 0;
                  pfVar9 = local_190;
                  local_190[2] = DAT_006fe838 + DAT_006fe838 +
                                 (float)(((int)pfVar11[2] - (int)*pfVar11) *
                                        ((int)pfVar11[3] - (int)pfVar11[1])) + (float)(int)local_1c
                                 + local_8;
                  fVar4 = _DAT_00673498;
                  do {
                    if (*pfVar9 < fVar4) {
                      fVar4 = *pfVar9;
                      iVar13 = iVar10;
                    }
                    iVar10 = iVar10 + 1;
                    pfVar9 = pfVar9 + 1;
                  } while (iVar10 < 3);
                  if (iVar13 != 0) {
                    if (iVar13 != 1) {
                      if (iVar13 != 2) goto LAB_005cdafc;
                      pfVar9 = &local_5c;
                      goto LAB_005cd9c1;
                    }
                    *pfVar11 = local_b4;
                    pfVar11[1] = local_b0;
                    pfVar11[2] = local_ac;
                    pfVar11[3] = local_a8;
                    pfVar11 = &local_5c;
                    goto LAB_005cdc54;
                  }
                  local_1b0 = local_b4;
                  fStack_1ac = local_b0;
                  fStack_1a8 = local_ac;
                  fStack_1a4 = local_a8;
                  FUN_00422698();
                  pfVar9 = &local_1b0;
                  goto LAB_005cdae7;
                }
                if (local_18 == 4) {
                  if (local_28 == fVar4) goto LAB_005cda0e;
                  local_c[2] = fVar4;
LAB_005cd7f7:
                  local_c[1] = pfVar11[1];
                  local_c[3] = pfVar11[3];
                  local_50 = pfVar11[1];
                  local_78 = pfVar11[3];
                  goto LAB_005cd80f;
                }
                if (local_18 != 8) {
                  if (local_18 != 0xc) goto LAB_005cdafc;
                  local_c[3] = pfVar11[1];
                  local_58 = pfVar11[3];
                  goto LAB_005cd6a5;
                }
                if (local_8 != pfVar11[2]) {
                  *local_c = pfVar11[2];
                  goto LAB_005cd7f7;
                }
LAB_005cda0e:
                local_144 = *local_c;
                local_140 = local_c[1];
                local_13c = local_c[2];
                local_138 = local_c[3];
                FUN_00422698();
                local_8 = (float)(((int)local_c[2] - (int)*local_c) *
                                 ((int)local_c[3] - (int)local_c[1]));
                if (DAT_006fe838 + DAT_006fe838 +
                    (float)(((int)pfVar11[2] - (int)*pfVar11) * ((int)pfVar11[3] - (int)pfVar11[1]))
                    + (float)(int)local_8 <=
                    (float)(((int)local_138 - (int)local_140) * ((int)local_13c - (int)local_144)) +
                    DAT_006fe838) goto LAB_005cdafc;
                FUN_00422698();
LAB_005cdaed:
                FUN_005db3b0(local_c);
                local_11 = '\x01';
                goto LAB_005cdafc;
              }
              if (fVar5 == pfVar11[1]) goto LAB_005cda0e;
              local_c[3] = pfVar11[1];
LAB_005cd9f4:
              *local_c = *pfVar11;
              local_c[2] = pfVar11[2];
              local_54 = *pfVar11;
              local_7c = pfVar11[2];
LAB_005cd80f:
              local_6c.left = (LONG)*local_c;
              local_6c.top = (LONG)local_c[1];
              local_6c.right = (LONG)local_c[2];
              local_6c.bottom = (LONG)local_c[3];
              FUN_00422698();
              local_c4 = (float)local_6c.left;
              local_c0 = (float)local_6c.top;
              local_bc = (float)local_6c.right;
              local_b8 = (float)local_6c.bottom;
              FUN_00422698();
              local_8 = (float)(((int)local_70 - (int)local_78) * ((int)local_74 - (int)local_7c));
              local_a4 = (float)(((int)local_50 - (int)local_58) * ((int)local_54 - (int)local_5c))
                         + DAT_006fe838;
              local_124 = local_c4;
              local_a0 = (float)(int)local_8 + DAT_006fe838;
              local_120 = local_c0;
              local_11c = local_bc;
              local_118 = local_b8;
              FUN_00422698();
              local_1a0[0] = (float)(((int)local_118 - (int)local_120) *
                                    ((int)local_11c - (int)local_124)) + DAT_006fe838;
              local_1a0[1] = (float)(((int)local_bc - (int)local_c4) *
                                    ((int)local_b8 - (int)local_c0)) + local_a0 + DAT_006fe838;
              local_1a0[2] = (float)((local_6c.bottom - local_6c.top) *
                                    (local_6c.right - local_6c.left)) + local_a0 + local_a4 +
                             DAT_006fe838;
              iVar13 = 0;
              local_8 = (float)(((int)local_c[2] - (int)*local_c) *
                               ((int)local_c[3] - (int)local_c[1]));
              iVar10 = 0;
              pfVar9 = local_1a0;
              local_1a0[3] = DAT_006fe838 + DAT_006fe838 +
                             (float)(((int)pfVar11[2] - (int)*pfVar11) *
                                    ((int)pfVar11[3] - (int)pfVar11[1])) + (float)(int)local_8 +
                             local_a0 + local_a4;
              fVar4 = _DAT_00673498;
              do {
                if (*pfVar9 < fVar4) {
                  fVar4 = *pfVar9;
                  iVar13 = iVar10;
                }
                iVar10 = iVar10 + 1;
                pfVar9 = pfVar9 + 1;
              } while (iVar10 < 4);
              if (iVar13 == 0) {
                local_1d0 = local_c4;
                fStack_1cc = local_c0;
                fStack_1c8 = local_bc;
                fStack_1c4 = local_b8;
                FUN_00422698();
                pfVar9 = &local_1d0;
LAB_005cdae7:
                *pfVar11 = *pfVar9;
                pfVar11[1] = pfVar9[1];
                pfVar11[2] = pfVar9[2];
                pfVar11[3] = pfVar9[3];
                goto LAB_005cdaed;
              }
              if (iVar13 != 1) {
                if (iVar13 == 2) {
                  *pfVar11 = (float)local_6c.left;
                  pfVar11[1] = (float)local_6c.top;
                  pfVar11[2] = (float)local_6c.right;
                  pfVar11[3] = (float)local_6c.bottom;
                  *local_c = local_5c;
                  local_c[1] = local_58;
                  local_c[2] = local_54;
                  local_c[3] = local_50;
                  FUN_004b3fea(&local_7c);
                  goto LAB_005cdc71;
                }
                if (iVar13 == 3) {
                  FUN_004b3fea(&local_5c);
                  pfVar9 = &local_7c;
LAB_005cd9c1:
                  FUN_004b3fea(pfVar9);
                }
                goto LAB_005cdafc;
              }
              *pfVar11 = local_c4;
              pfVar11[1] = local_c0;
              pfVar11[2] = local_bc;
              pfVar11[3] = local_b8;
              pfVar11 = &local_7c;
              goto LAB_005cdc54;
            }
            local_8c = *local_c;
            fStack_88 = local_c[1];
            fStack_84 = local_c[2];
            fStack_80 = local_c[3];
            local_9c = *local_c;
            fStack_98 = local_c[1];
            fStack_94 = local_c[2];
            fStack_90 = local_c[3];
            local_4c = *local_c;
            fStack_48 = local_c[1];
            fStack_44 = local_c[2];
            fStack_40 = local_c[3];
            local_3c = *local_c;
            fStack_38 = local_c[1];
            fStack_34 = local_c[2];
            fStack_30 = local_c[3];
            switch(local_18) {
            case 1:
              fStack_90 = pfVar11[1];
              fStack_34 = fVar4;
              fStack_38 = fStack_90;
              fStack_84 = fVar4;
              fStack_40 = fStack_90;
              goto code_r0x005cd0c3;
            case 2:
              fStack_90 = pfVar11[1];
              local_8c = pfVar11[2];
              fStack_38 = fStack_90;
              local_3c = local_8c;
              fStack_40 = fStack_90;
              goto code_r0x005cd261;
            case 3:
              if (fVar5 == pfVar11[1]) break;
              local_c[3] = pfVar11[1];
code_r0x005cd27a:
              fStack_154 = *local_c;
              fStack_150 = local_c[1];
              fStack_14c = local_c[2];
              fStack_148 = local_c[3];
              FUN_00422698();
              local_8 = (float)(((int)local_c[2] - (int)*local_c) *
                               ((int)local_c[3] - (int)local_c[1]));
              if (DAT_006fe838 + DAT_006fe838 +
                  (float)(((int)pfVar11[2] - (int)*pfVar11) * ((int)pfVar11[3] - (int)pfVar11[1])) +
                  (float)(int)local_8 <=
                  (float)(((int)fStack_148 - (int)fStack_150) * ((int)fStack_14c - (int)fStack_154))
                  + DAT_006fe838) goto code_r0x005cd577;
              fStack_1c0 = *local_c;
              fStack_1bc = local_c[1];
              fStack_1b8 = local_c[2];
              fStack_1b4 = local_c[3];
              FUN_00422698();
              *pfVar11 = fStack_1c0;
              pfVar11[1] = fStack_1bc;
              pfVar11[2] = fStack_1b8;
              pfVar11[3] = fStack_1b4;
              FUN_005db3b0(local_c);
              if (((int)pfVar11[2] <= (int)*pfVar11) || ((int)pfVar11[3] <= (int)pfVar11[1]))
              goto code_r0x005cdc69;
              goto LAB_005cdc71;
            case 4:
              fStack_98 = pfVar11[3];
              fStack_34 = fVar4;
              fStack_30 = fStack_98;
              fStack_84 = fVar4;
              fStack_48 = fStack_98;
code_r0x005cd0c3:
              local_4c = fVar4;
              fStack_84 = local_4c;
              fStack_34 = local_4c;
code_r0x005cd0c6:
              if (((int)local_3c < (int)fStack_34) && ((int)fStack_38 < (int)fStack_30)) {
                fStack_f4 = *pfVar11;
                fStack_f0 = pfVar11[1];
                fStack_ec = pfVar11[2];
                fStack_e8 = pfVar11[3];
                FUN_00422698();
                local_8 = (float)(((int)fStack_e8 - (int)fStack_f0) *
                                 ((int)fStack_ec - (int)fStack_f4));
                fStack_164 = fStack_f4;
                fStack_160 = fStack_f0;
                fStack_15c = fStack_ec;
                afStack_e4[0] =
                     DAT_006fe838 + DAT_006fe838 +
                     (float)(((int)fStack_30 - (int)fStack_38) * ((int)fStack_34 - (int)local_3c)) +
                     (float)(int)local_8;
                fStack_158 = fStack_e8;
                FUN_00422698();
                local_8 = (float)(((int)fStack_158 - (int)fStack_160) *
                                 ((int)fStack_15c - (int)fStack_164));
                fStack_114 = *pfVar11;
                fStack_110 = pfVar11[1];
                afStack_e4[1] = (float)(int)local_8 + DAT_006fe838;
                fStack_10c = pfVar11[2];
                fStack_108 = pfVar11[3];
                FUN_00422698();
                fVar4 = (float)(((int)fStack_94 - (int)local_9c) * ((int)fStack_90 - (int)fStack_98)
                               );
                afStack_e4[2] =
                     DAT_006fe838 + DAT_006fe838 +
                     (float)(((int)fStack_108 - (int)fStack_110) *
                            ((int)fStack_10c - (int)fStack_114)) + fVar4;
                local_8 = (float)(((int)fStack_30 - (int)fStack_38) *
                                 ((int)fStack_34 - (int)local_3c));
                afStack_e4[3] =
                     DAT_006fe838 * _DAT_00666ccc +
                     (float)(((int)pfVar11[2] - (int)*pfVar11) * ((int)pfVar11[3] - (int)pfVar11[1])
                            ) + (float)(int)local_8 + fVar4;
              }
              else {
                afStack_e4[0] = _DAT_00673498;
                afStack_e4[1] = _DAT_00673498;
                afStack_e4[2] = _DAT_00673498;
                afStack_e4[3] = _DAT_00673498;
              }
              if (((int)local_4c < (int)fStack_44) && ((int)fStack_48 < (int)fStack_40)) {
                fStack_104 = *pfVar11;
                fStack_100 = pfVar11[1];
                fStack_fc = pfVar11[2];
                fStack_f8 = pfVar11[3];
                FUN_00422698();
                local_8 = (float)(((int)fStack_f8 - (int)fStack_100) *
                                 ((int)fStack_fc - (int)fStack_104));
                local_190[3] = fStack_104;
                fStack_180 = fStack_100;
                fStack_17c = fStack_fc;
                fStack_d4 = DAT_006fe838 + DAT_006fe838 +
                            (float)(((int)fStack_40 - (int)fStack_48) *
                                   ((int)fStack_44 - (int)local_4c)) + (float)(int)local_8;
                fStack_178 = fStack_f8;
                FUN_00422698();
                local_8 = (float)(((int)fStack_178 - (int)fStack_180) *
                                 ((int)fStack_17c - (int)local_190[3]));
                fStack_174 = *pfVar11;
                fStack_170 = pfVar11[1];
                fStack_d0 = (float)(int)local_8 + DAT_006fe838;
                fStack_16c = pfVar11[2];
                fStack_168 = pfVar11[3];
                FUN_00422698();
                fVar4 = (float)(((int)fStack_80 - (int)fStack_88) * ((int)fStack_84 - (int)local_8c)
                               );
                fStack_cc = DAT_006fe838 + DAT_006fe838 +
                            (float)(((int)fStack_168 - (int)fStack_170) *
                                   ((int)fStack_16c - (int)fStack_174)) + fVar4;
                local_8 = (float)(((int)pfVar11[2] - (int)*pfVar11) *
                                 ((int)pfVar11[3] - (int)pfVar11[1]));
                fStack_c8 = DAT_006fe838 * _DAT_00666ccc +
                            (float)(((int)fStack_40 - (int)fStack_48) *
                                   ((int)fStack_44 - (int)local_4c)) + (float)(int)local_8 + fVar4;
              }
              else {
                fStack_d4 = _DAT_00673498;
                fStack_d0 = _DAT_00673498;
                fStack_cc = _DAT_00673498;
                fStack_c8 = _DAT_00673498;
              }
              iVar13 = 0;
              iVar10 = 0;
              pfVar9 = afStack_e4;
              fVar4 = _DAT_00673498;
              do {
                if (*pfVar9 < fVar4) {
                  fVar4 = *pfVar9;
                  iVar13 = iVar10;
                }
                iVar10 = iVar10 + 1;
                pfVar9 = pfVar9 + 1;
              } while (iVar10 < 8);
              if ((float)_UNK_00673490 <= fVar4) break;
              switch(iVar13) {
              case 0:
                FUN_00422698();
                pfVar11 = &local_3c;
                break;
              case 1:
                FUN_00422698();
                goto code_r0x005cdbdf;
              case 2:
                FUN_00422698();
                pfVar11 = &local_9c;
                goto code_r0x005cdbf8;
              case 3:
                *local_c = local_9c;
                local_c[1] = fStack_98;
                local_c[2] = fStack_94;
                local_c[3] = fStack_90;
                if (((int)local_c[2] <= (int)*local_c) || ((int)local_c[3] <= (int)local_c[1])) {
                  FUN_005db3b0(local_c);
                }
                pfVar9 = &local_3c;
                goto code_r0x005cd56e;
              case 4:
                FUN_00422698();
                pfVar11 = &local_4c;
                break;
              case 5:
                FUN_00422698();
code_r0x005cdbdf:
                FUN_00422698();
                pfVar11 = local_c;
code_r0x005cdc69:
                FUN_005db3b0(pfVar11);
                goto LAB_005cdc71;
              case 6:
                FUN_00422698();
                pfVar11 = &local_8c;
code_r0x005cdbf8:
                *local_c = *pfVar11;
                local_c[1] = pfVar11[1];
                local_c[2] = pfVar11[2];
                local_c[3] = pfVar11[3];
                pfVar11 = local_c;
                if (((int)local_c[2] <= (int)*local_c) || ((int)local_c[3] <= (int)local_c[1]))
                goto code_r0x005cdc69;
                goto LAB_005cdc71;
              case 7:
                *local_c = local_8c;
                local_c[1] = fStack_88;
                local_c[2] = fStack_84;
                local_c[3] = fStack_80;
                if (((int)local_c[2] <= (int)*local_c) || ((int)local_c[3] <= (int)local_c[1])) {
                  FUN_005db3b0(local_c);
                }
                pfVar9 = &local_4c;
code_r0x005cd56e:
                FUN_004b3fea(pfVar9);
code_r0x005cd577:
                local_20 = local_20 - 1;
              default:
                goto LAB_005cdafc;
              }
LAB_005cdc54:
              *local_c = *pfVar11;
              local_c[1] = pfVar11[1];
              local_c[2] = pfVar11[2];
              local_c[3] = pfVar11[3];
              goto LAB_005cdc71;
            case 5:
              if (local_28 != fVar4) {
                local_c[2] = fVar4;
                goto code_r0x005cd27a;
              }
              break;
            case 6:
            case 7:
            case 9:
            case 0xb:
            case 0xd:
            case 0xe:
            case 0xf:
              FUN_005db3b0(local_c);
              local_24 = local_24 - 1;
              break;
            case 8:
              fStack_98 = pfVar11[3];
              local_8c = pfVar11[2];
              local_3c = local_8c;
              fStack_30 = fStack_98;
              fStack_48 = fStack_98;
code_r0x005cd261:
              fStack_44 = local_8c;
              local_3c = local_8c;
              goto code_r0x005cd0c6;
            case 10:
              if (local_8 != pfVar11[2]) {
                *local_c = pfVar11[2];
                goto code_r0x005cd27a;
              }
              break;
            case 0xc:
              if (local_1c != pfVar11[3]) {
                local_c[1] = pfVar11[3];
                goto code_r0x005cd27a;
              }
            }
LAB_005cdafc:
            if (local_11 != '\0') {
LAB_005cdc71:
              local_2c = local_2c + 1;
              piVar12 = local_10;
              if (100 < local_2c) goto LAB_005cdc81;
              goto LAB_005cced7;
            }
LAB_005cdb13:
            local_20 = local_20 + 1;
            iVar13 = *local_10;
            piVar12 = local_10;
          } while (local_20 < (uint)(local_10[1] - iVar13 >> 4));
        }
      }
      else {
        FUN_005db3b0(pfVar11);
        local_24 = local_24 - 1;
      }
      local_24 = local_24 + 1;
    }
  }
LAB_005cdc81:
  if (0x10 < (int)(piVar12[1] - *piVar12 & 0xfffffff0U)) {
    local_8 = 0.0;
    SetRect(&local_6c,0x7fffffff,0x7fffffff,-0x80000000,-0x80000000);
    local_2c = piVar12[1] - *piVar12 >> 4;
    if (0 < (int)local_2c) {
      iVar13 = 0;
      do {
        FUN_00422698();
        iVar6 = *piVar12;
        iVar10 = iVar13 + 0xc;
        iVar2 = iVar13 + 8;
        iVar3 = iVar13 + 4;
        piVar1 = (int *)(iVar13 + iVar6);
        iVar13 = iVar13 + 0x10;
        local_1c = (float)((*(int *)(iVar10 + iVar6) - *(int *)(iVar3 + iVar6)) *
                          (*(int *)(iVar2 + iVar6) - *piVar1));
        local_2c = local_2c + -1;
        local_8 = (float)(int)local_1c + local_8;
      } while (local_2c != 0);
    }
    local_2c = (local_6c.bottom - local_6c.top) * (local_6c.right - local_6c.left);
    if (_DAT_0067343c < ABS(DAT_006fe838)) {
      if ((float)_DAT_00673488 <= (float)(int)local_2c / local_8) goto LAB_005cdd64;
    }
    else if (_DAT_0067343c < ABS((float)(int)local_2c - local_8)) goto LAB_005cdd64;
    FUN_004b4015(*piVar12,piVar12[1]);
    FUN_004b3fea(&local_6c);
    piVar12[4] = 0;
  }
LAB_005cdd64:
  *(undefined1 *)(piVar12 + 3) = 1;
  return;
}

