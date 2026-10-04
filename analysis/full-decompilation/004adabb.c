
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004adabb(void)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  char cVar4;
  short sVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  undefined2 uVar19;
  undefined2 extraout_var;
  undefined2 *puVar14;
  undefined2 extraout_var_00;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  undefined1 extraout_var_01;
  uint extraout_ECX_03;
  uint uVar20;
  uint extraout_ECX_04;
  undefined1 extraout_var_02;
  uint extraout_ECX_05;
  uint extraout_ECX_06;
  ushort *puVar21;
  undefined1 extraout_var_03;
  uint extraout_ECX_07;
  uint extraout_ECX_08;
  undefined1 extraout_var_04;
  uint extraout_ECX_09;
  uint extraout_ECX_10;
  short *psVar22;
  int *piVar23;
  char cVar24;
  uint uVar25;
  int unaff_EBP;
  undefined4 *puVar26;
  bool bVar27;
  float10 fVar28;
  undefined8 uVar29;
  int iVar30;
  int iVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  int *piStack_230;
  undefined4 local_22c;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x1c) = extraout_ECX;
  local_22c = 6.874346e-39;
  iVar6 = FUN_00401f6f();
  *(uint *)(unaff_EBP + -0xdc) = (uint)(iVar6 == 0);
  pcVar3 = *(char **)(unaff_EBP + 8);
  cVar4 = *pcVar3;
  cVar24 = pcVar3[1];
  cVar1 = pcVar3[2];
  *(char *)(unaff_EBP + -0x10) = cVar4;
  *(char *)(unaff_EBP + -0xf) = cVar24;
  *(char *)(unaff_EBP + -0xe) = cVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar9 = (undefined4 *)(unaff_EBP + -0x11c);
  for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x88) = 0;
  if (0 < *(int *)(unaff_EBP + 0xc)) {
    do {
      if ((*(byte *)(unaff_EBP + -0xf4) & 0x10) != 0) {
        puVar9 = (undefined4 *)(unaff_EBP + -0x11c);
        for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar9 = 0;
          puVar9 = puVar9 + 1;
        }
      }
      *(char *)(unaff_EBP + -0x14) = cVar4;
      *(char *)(unaff_EBP + -0x13) = cVar24;
      *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(unaff_EBP + -0xe);
      iVar6 = DAT_006e54d8;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      local_22c = (float)(-*(int *)(iVar6 + 0x84) & 3);
      piStack_230 = (int *)0x4adb64;
      FUN_00434ffd();
      iVar6 = extraout_ECX_00;
      if ((*(char *)(*(int *)(unaff_EBP + -0x1c) + 0x50) == '\0') || (DAT_006e4a84 != 0)) {
LAB_004adba1:
        *(undefined4 **)(unaff_EBP + 8) = &local_22c;
        local_22c._0_2_ =
             CONCAT11(*(undefined1 *)(unaff_EBP + -0xf),*(undefined1 *)(unaff_EBP + -0x10));
        local_22c._3_1_ = (undefined1)((uint)iVar6 >> 0x18);
        local_22c._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0xe),(undefined2)local_22c);
        piStack_230 = (int *)(unaff_EBP + -0x4c);
        FUN_004796d9();
        iVar8 = *(char *)(unaff_EBP + -0x14) * 4;
        iVar6 = *(int *)(*(int *)(DAT_006e54dc + 0x20 + *(char *)(unaff_EBP + -0x12) * 4) + 0xc);
        bVar27 = *(char *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x40 +
                                                     *(char *)(unaff_EBP + -0x12) * 4) + 0xc) +
                                   iVar8) + *(char *)(unaff_EBP + -0x13) * 0xe) == '\0';
        uVar7 = (uint)*(ushort *)(*(int *)(iVar6 + iVar8) + *(char *)(unaff_EBP + -0x13) * 2);
        *(uint *)(unaff_EBP + 8) = uVar7;
        if (!bVar27) {
          *(undefined4 **)(unaff_EBP + -0x18) = &local_22c;
          local_22c._0_2_ =
               CONCAT11(*(undefined1 *)(unaff_EBP + -0xf),*(undefined1 *)(unaff_EBP + -0x10));
          local_22c._3_1_ = (undefined1)((uint)iVar6 >> 0x18);
          local_22c._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0xe),(undefined2)local_22c);
          piStack_230 = (int *)(unaff_EBP + -0x228);
          puVar9 = (undefined4 *)FUN_00467768();
          puVar26 = (undefined4 *)(unaff_EBP + -0x11c);
          for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar26 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar26 = puVar26 + 1;
          }
          uVar7 = *(uint *)(unaff_EBP + 8);
          iVar6 = 0;
        }
        *(undefined4 **)(unaff_EBP + 8) = &local_22c;
        local_22c._0_2_ =
             CONCAT11(*(undefined1 *)(unaff_EBP + -0xf),*(undefined1 *)(unaff_EBP + -0x10));
        local_22c._3_1_ = (undefined1)((uint)iVar6 >> 0x18);
        local_22c._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0xe),(undefined2)local_22c);
        piStack_230 = (int *)0x4adc62;
        uVar10 = FUN_00492b33();
        iVar6 = DAT_006e54dc;
        *(undefined4 *)(unaff_EBP + -0x90) = uVar10;
        iVar6 = *(int *)(iVar6 + 0x28 + *(char *)(unaff_EBP + -0x12) * 4);
        *(undefined4 *)(unaff_EBP + -0x58) = 0;
        *(undefined2 *)(unaff_EBP + 8) =
             *(undefined2 *)
              (*(int *)(*(int *)(iVar6 + 0xc) + *(char *)(unaff_EBP + -0x14) * 4) +
              *(char *)(unaff_EBP + -0x13) * 2);
        local_22c = (float)(unaff_EBP + -300);
        piStack_230 = (int *)0x4adc9f;
        piStack_230 = (int *)FUN_00434d3d();
        local_22c = *(float *)(unaff_EBP + 0x24);
        fVar28 = (float10)FUN_0046755a();
        local_22c = (float)fVar28;
        piStack_230 = (int *)0x4adcbd;
        FUN_004b4722();
        local_22c = -NAN;
        piStack_230 = *(int **)(unaff_EBP + 0x1c);
        uVar10 = *(undefined4 *)(unaff_EBP + 0x24);
        uVar11 = FUN_00434d3d(unaff_EBP + -0x124);
        FUN_004b97eb(uVar11,uVar10);
        piStack_230 = extraout_ECX_01;
        if (*(short *)(unaff_EBP + -0x90) != 0) {
          local_22c = 0.0;
          piVar23 = (int *)(int)*(short *)(unaff_EBP + -0x90);
          iVar6 = *(int *)(*(int *)(*(int *)(unaff_EBP + -0x1c) + 0x1c) + 0x14);
          if ((0 < (int)piVar23) &&
             (piStack_230 = (int *)((*(int *)(iVar6 + 0x1c) - *(int *)(iVar6 + 0x18) >> 2) + 1),
             piVar23 < piStack_230)) {
            local_22c = *(float *)(*(int *)(iVar6 + 0x18) + -4 + (int)piVar23 * 4);
          }
          *(float *)(unaff_EBP + -0x58) = local_22c;
          if (local_22c == 0.0) {
            *(int ***)(unaff_EBP + -0x18) = &piStack_230;
            FUN_00461b74(unaff_EBP + -0x10);
            FUN_004aeef5();
            piStack_230 = extraout_ECX_02;
          }
        }
        *(undefined4 **)(unaff_EBP + -0x18) = &local_22c;
        local_22c._0_2_ =
             CONCAT11(*(undefined1 *)(unaff_EBP + -0xf),*(undefined1 *)(unaff_EBP + -0x10));
        local_22c._3_1_ = (undefined1)((uint)piStack_230 >> 0x18);
        local_22c._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0xe),(undefined2)local_22c);
        piStack_230 = (int *)(unaff_EBP + -0x28);
        FUN_004aef32();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        if (((*(int *)(unaff_EBP + 0x24) < 2) || (uVar7 == 0)) || (DAT_006c723b == '\0')) {
          if (((DAT_006c7238 != 0) && (*(int *)(unaff_EBP + -0xdc) != 0)) &&
             ((*(int *)(unaff_EBP + 0x24) != 1 &&
              (*(int *)(unaff_EBP + 0x24) == *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x18))))) {
            if ((*(byte *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x30 +
                                                     *(char *)(unaff_EBP + -0x12) * 4) + 0xc) +
                                   *(char *)(unaff_EBP + -0x14) * 4) +
                          (int)*(char *)(unaff_EBP + -0x13)) & 1) != 0) {
              local_22c = (float)((int)*(char *)(unaff_EBP + -0x14) +
                                  (int)*(char *)(unaff_EBP + -0x13) & 1);
              piStack_230 = *(int **)(unaff_EBP + 0x1c);
              uVar11 = 0;
              iVar12 = DAT_006f0088 * 0x100 + -0xff;
              iVar17 = *(int *)(unaff_EBP + 0x18) -
                       ((uint)*(byte *)(unaff_EBP + -0x4b) << ((char)DAT_006f0088 + 1U & 0x1f));
              iVar18 = *(int *)(unaff_EBP + 0x14) - *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x5c);
              uVar10 = 0;
              iVar6 = unaff_EBP + -0x10;
              iVar8 = unaff_EBP + -0x19c;
              FUN_004c656a(iVar8,iVar6,iVar12,0,iVar18,iVar17,0);
              FUN_004c87ac(iVar8,iVar6,iVar12,uVar10,iVar18,iVar17,uVar11);
            }
          }
        }
        else {
          local_22c = 0.0;
          piStack_230 = (int *)s_UW__DrawFloor_006c73ac;
          local_22c = (float)FUN_005d51f5();
          piStack_230 = (int *)0x4add9b;
          FUN_004b406a();
          if (bVar27) {
LAB_004ae6fa:
            local_22c = (float)(unaff_EBP + -0xe0);
            piStack_230 = (int *)(unaff_EBP + -0xcc);
            cVar4 = FUN_004a156c(uVar7,DAT_006f0088);
            if (cVar4 != '\0') {
              local_22c = 0.0;
              piStack_230 = (int *)0x0;
              FUN_004c828c(unaff_EBP + -0x1fc,unaff_EBP + -0x10,*(undefined4 *)(unaff_EBP + -0xe0),0
                           ,*(int *)(unaff_EBP + 0x14) -
                            *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x5c),
                           *(int *)(unaff_EBP + 0x18) -
                           ((uint)*(byte *)(unaff_EBP + -0x4b) << ((char)DAT_006f0088 + 1U & 0x1f)),
                           0,*(undefined4 *)(unaff_EBP + 0x1c),unaff_EBP + -0x28,1,0);
            }
          }
          else if (((byte)*(undefined4 *)(unaff_EBP + -0x11c) & 0x10) == 0x10) {
            uVar25 = (uint)*(ushort *)(unaff_EBP + -0x108);
            *(uint *)(unaff_EBP + -0x44) = (uint)*(ushort *)(unaff_EBP + -0x114);
            if (*(ushort *)(unaff_EBP + -0x114) == 0) {
              uVar13 = 0;
              if (uVar25 == 0) {
                *(uint *)(unaff_EBP + -0x44) = uVar7;
                uVar13 = uVar7;
                uVar25 = uVar7;
              }
              if ((uVar13 == 0) && (uVar25 == 0)) goto LAB_004ae6fa;
            }
            iVar6 = *(int *)(unaff_EBP + -0x1c);
            *(undefined4 *)(unaff_EBP + -0xac) = _DAT_006f0bc0;
            *(undefined4 *)(unaff_EBP + -0xa8) = _DAT_006f0bc4;
            local_22c = (float)(unaff_EBP + -0xa0);
            piStack_230 = (int *)(unaff_EBP + -0x24);
            FUN_004672d0(unaff_EBP + -0x14,unaff_EBP + -0x2c,unaff_EBP + -0x54);
            local_22c = 6.875514e-39;
            fVar28 = (float10)FUN_004b46a4();
            iVar8 = DAT_006f008c;
            *(float *)(unaff_EBP + -0x5c) = (float)fVar28;
            if (*(int *)(unaff_EBP + -0x24) == 0) {
              iVar12 = 0;
            }
            else {
              iVar12 = ((*(int *)(unaff_EBP + -0x24) - iVar8) - 1U & 3) + 1;
            }
            *(int *)(unaff_EBP + -0x24) = iVar12;
            if (*(int *)(unaff_EBP + -0xa0) == 0) {
              iVar8 = 0;
            }
            else {
              iVar8 = ((*(int *)(unaff_EBP + -0xa0) - iVar8) - 1U & 3) + 1;
            }
            *(int *)(unaff_EBP + -0xa0) = iVar8;
            if (uVar25 != 0) {
              *(char *)(unaff_EBP + -0x40) = (char)*(undefined4 *)(unaff_EBP + -0x28);
              *(char *)(unaff_EBP + -0x3f) = (char)((uint)*(undefined4 *)(unaff_EBP + -0x28) >> 8);
              *(char *)(unaff_EBP + -0x3e) = (char)*(undefined2 *)(unaff_EBP + -0x26);
              *(char *)(unaff_EBP + -0x3d) = (char)((ushort)*(undefined2 *)(unaff_EBP + -0x26) >> 8)
              ;
              uVar7 = *(uint *)(unaff_EBP + -0x2c);
              *(undefined1 *)(unaff_EBP + -4) = 4;
              if (uVar7 != *(uint *)(unaff_EBP + -0x54)) {
                *(undefined1 *)(unaff_EBP + -0x7a) = 0;
                *(undefined1 *)(unaff_EBP + -0x62) = 0;
                local_22c = (float)(unaff_EBP + -0x10);
                piStack_230 = (int *)(unaff_EBP + -100);
                *(undefined1 *)(unaff_EBP + -4) = 6;
                uVar13 = FUN_004aee43(unaff_EBP + -0x7c);
                uVar7 = uVar13;
                if (0 < (int)uVar13) {
                  *(undefined4 **)(unaff_EBP + -0x18) = &local_22c;
                  local_22c._0_2_ =
                       CONCAT11(*(undefined1 *)(unaff_EBP + -0x7b),
                                *(undefined1 *)(unaff_EBP + -0x7c));
                  local_22c._0_3_ =
                       CONCAT12(*(undefined1 *)(unaff_EBP + -0x7a),(undefined2)local_22c);
                  local_22c = (float)CONCAT13(extraout_var_01,(undefined3)local_22c);
                  piStack_230 = (int *)0x4aded4;
                  uVar7 = FUN_00489b59();
                  uVar7 = uVar7 & 0xffff;
                  if (*(int *)(unaff_EBP + -0x24) == 4) {
                    puVar21 = *(ushort **)(unaff_EBP + -0x54);
LAB_004adef0:
                    uVar20 = 0;
                    if ((puVar21 != (ushort *)0x0) && (uVar20 = (uint)*puVar21, uVar20 != uVar7)) {
                      local_22c = 0.0;
                      piStack_230 = (int *)0x4adf04;
                      uVar7 = FUN_004aeeb8();
                      uVar20 = extraout_ECX_04;
                    }
                  }
                  else if ((*(int *)(unaff_EBP + -0x24) == 2) ||
                          (uVar20 = extraout_ECX_03, *(int *)(unaff_EBP + -0x24) == 0)) {
                    puVar21 = *(ushort **)(unaff_EBP + -0x2c);
                    goto LAB_004adef0;
                  }
                  if (uVar13 == 2) {
                    *(undefined4 **)(unaff_EBP + -0x18) = &local_22c;
                    local_22c._0_2_ =
                         CONCAT11(*(undefined1 *)(unaff_EBP + -99),*(undefined1 *)(unaff_EBP + -100)
                                 );
                    local_22c._3_1_ = (undefined1)(uVar20 >> 0x18);
                    local_22c._0_3_ =
                         CONCAT12(*(undefined1 *)(unaff_EBP + -0x62),(undefined2)local_22c);
                    piStack_230 = (int *)0x4adf2b;
                    uVar7 = FUN_00489b59();
                    uVar7 = uVar7 & 0xffff;
                    if (*(int *)(unaff_EBP + -0x24) == 4) {
                      puVar21 = *(ushort **)(unaff_EBP + -0x54);
                    }
                    else {
                      if ((*(int *)(unaff_EBP + -0x24) != 2) && (*(int *)(unaff_EBP + -0x24) != 0))
                      goto LAB_004adf5c;
                      puVar21 = *(ushort **)(unaff_EBP + -0x2c);
                    }
                    if ((puVar21 != (ushort *)0x0) && (*puVar21 != uVar7)) {
                      local_22c = 1.4013e-45;
                      piStack_230 = (int *)0x4adf5c;
                      uVar7 = FUN_004aeeb8();
                    }
                  }
                }
LAB_004adf5c:
                iVar6 = *(int *)(unaff_EBP + -0x1c);
                *(undefined1 *)(unaff_EBP + -4) = 4;
              }
              uVar19 = (undefined2)(uVar7 >> 0x10);
              if (*(int *)(unaff_EBP + -0x24) == 2) {
                sVar5 = *(short *)(unaff_EBP + 8);
              }
              else {
                sVar5 = *(short *)(unaff_EBP + 8);
              }
              if (sVar5 == -5) {
                local_22c = 6.876012e-39;
                fVar28 = (float10)FUN_004689a1();
                local_22c = (float)fVar28;
                piStack_230 = (int *)0x4adf92;
                FUN_004b4722();
                uVar19 = extraout_var;
              }
              uVar7 = DAT_006f0088;
              iVar8 = CONCAT22(uVar19,(ushort)*(byte *)(unaff_EBP + -0x4b)) <<
                      ((char)DAT_006f0088 + 1U & 0x1f);
              iVar8 = CONCAT22((short)((uint)iVar8 >> 0x10),*(short *)(iVar6 + 100) - (short)iVar8)
                      + *(int *)(unaff_EBP + 0x18);
              sVar5 = DAT_006f0bc0;
              *(int *)(unaff_EBP + -0x18) = iVar8;
              puVar14 = (undefined2 *)(unaff_EBP + -0x18);
              if ((short)iVar8 <= sVar5) {
                puVar14 = &DAT_006f0bc0;
              }
              _DAT_006f0bc0 = CONCAT22(DAT_006f0bc2,*puVar14);
              local_22c = (float)(unaff_EBP + -200);
              piStack_230 = (int *)(unaff_EBP + -0xb0);
              cVar4 = FUN_004a156c(uVar25,uVar7);
              if (cVar4 != '\0') {
                local_22c = 0.0;
                piStack_230 = (int *)0x0;
                FUN_004c828c(unaff_EBP + -0x1ec,unaff_EBP + -0x10,*(undefined4 *)(unaff_EBP + -200),
                             0,*(int *)(unaff_EBP + 0x14) - *(int *)(iVar6 + 0x5c),
                             *(int *)(unaff_EBP + 0x18) -
                             ((uint)*(byte *)(unaff_EBP + -0x4b) << ((char)DAT_006f0088 + 1U & 0x1f)
                             ),0,*(undefined4 *)(unaff_EBP + 0x1c),unaff_EBP + -0x40,1,0);
              }
              _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0xac);
              local_22c = *(float *)(unaff_EBP + -0x5c);
              _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0xa8);
              piStack_230 = (int *)0x4ae054;
              FUN_004b4722();
              *(undefined1 *)(unaff_EBP + -4) = 3;
            }
            if (*(int *)(unaff_EBP + -0x44) != 0) {
              *(char *)(unaff_EBP + -0x48) = (char)*(undefined4 *)(unaff_EBP + -0x28);
              *(char *)(unaff_EBP + -0x47) = (char)((uint)*(undefined4 *)(unaff_EBP + -0x28) >> 8);
              *(char *)(unaff_EBP + -0x46) = (char)*(undefined2 *)(unaff_EBP + -0x26);
              *(char *)(unaff_EBP + -0x45) = (char)((ushort)*(undefined2 *)(unaff_EBP + -0x26) >> 8)
              ;
              uVar7 = *(uint *)(unaff_EBP + -0x2c);
              *(undefined1 *)(unaff_EBP + -4) = 7;
              if (uVar7 != *(uint *)(unaff_EBP + -0x54)) {
                *(undefined1 *)(unaff_EBP + -0x82) = 0;
                *(undefined1 *)(unaff_EBP + -0x72) = 0;
                local_22c = (float)(unaff_EBP + -0x10);
                piStack_230 = (int *)(unaff_EBP + -0x74);
                *(undefined1 *)(unaff_EBP + -4) = 9;
                uVar25 = FUN_004aee43(unaff_EBP + -0x84);
                uVar7 = uVar25;
                if (0 < (int)uVar25) {
                  *(undefined4 **)(unaff_EBP + -0x18) = &local_22c;
                  local_22c._0_2_ =
                       CONCAT11(*(undefined1 *)(unaff_EBP + -0x83),
                                *(undefined1 *)(unaff_EBP + -0x84));
                  local_22c._0_3_ =
                       CONCAT12(*(undefined1 *)(unaff_EBP + -0x82),(undefined2)local_22c);
                  local_22c = (float)CONCAT13(extraout_var_02,(undefined3)local_22c);
                  piStack_230 = (int *)0x4ae0e2;
                  uVar7 = FUN_00489b59();
                  uVar7 = uVar7 & 0xffff;
                  if (*(int *)(unaff_EBP + -0x24) == 4) {
LAB_004ae0fb:
                    puVar21 = *(ushort **)(unaff_EBP + -0x2c);
LAB_004ae0fe:
                    uVar13 = 0;
                    if ((puVar21 != (ushort *)0x0) && (uVar13 = (uint)*puVar21, uVar13 != uVar7)) {
                      local_22c = 0.0;
                      piStack_230 = (int *)0x4ae112;
                      uVar7 = FUN_004aeeb8();
                      uVar13 = extraout_ECX_06;
                    }
                  }
                  else {
                    if (*(int *)(unaff_EBP + -0x24) == 2) {
                      puVar21 = *(ushort **)(unaff_EBP + -0x54);
                      goto LAB_004ae0fe;
                    }
                    uVar13 = extraout_ECX_05;
                    if (*(int *)(unaff_EBP + -0x24) == 0) goto LAB_004ae0fb;
                  }
                  if (uVar25 == 2) {
                    *(undefined4 **)(unaff_EBP + -0x18) = &local_22c;
                    local_22c._0_2_ =
                         CONCAT11(*(undefined1 *)(unaff_EBP + -0x73),
                                  *(undefined1 *)(unaff_EBP + -0x74));
                    local_22c._3_1_ = (undefined1)(uVar13 >> 0x18);
                    local_22c._0_3_ =
                         CONCAT12(*(undefined1 *)(unaff_EBP + -0x72),(undefined2)local_22c);
                    piStack_230 = (int *)0x4ae139;
                    uVar7 = FUN_00489b59();
                    uVar7 = uVar7 & 0xffff;
                    if (*(int *)(unaff_EBP + -0x24) == 4) {
LAB_004ae151:
                      puVar21 = *(ushort **)(unaff_EBP + -0x2c);
                    }
                    else {
                      if (*(int *)(unaff_EBP + -0x24) != 2) {
                        if (*(int *)(unaff_EBP + -0x24) != 0) goto LAB_004ae168;
                        goto LAB_004ae151;
                      }
                      puVar21 = *(ushort **)(unaff_EBP + -0x54);
                    }
                    if ((puVar21 != (ushort *)0x0) && (*puVar21 != uVar7)) {
                      local_22c = 1.4013e-45;
                      piStack_230 = (int *)0x4ae168;
                      uVar7 = FUN_004aeeb8();
                    }
                  }
                }
LAB_004ae168:
                iVar6 = *(int *)(unaff_EBP + -0x1c);
                *(undefined1 *)(unaff_EBP + -4) = 7;
              }
              uVar19 = (undefined2)(uVar7 >> 0x10);
              if (*(int *)(unaff_EBP + -0x24) == 4) {
                sVar5 = *(short *)(unaff_EBP + 8);
              }
              else {
                sVar5 = *(short *)(unaff_EBP + 8);
              }
              if (sVar5 == -5) {
                local_22c = 6.876746e-39;
                fVar28 = (float10)FUN_004689a1();
                local_22c = (float)fVar28;
                piStack_230 = (int *)0x4ae19e;
                FUN_004b4722();
                uVar19 = extraout_var_00;
              }
              uVar7 = DAT_006f0088;
              iVar8 = CONCAT22(uVar19,*(short *)(iVar6 + 100) -
                                      ((ushort)*(byte *)(unaff_EBP + -0x4b) <<
                                      ((char)DAT_006f0088 + 1U & 0x1f))) +
                      *(int *)(unaff_EBP + 0x18);
              sVar5 = DAT_006f0bc4;
              *(int *)(unaff_EBP + 8) = iVar8;
              puVar14 = (undefined2 *)(unaff_EBP + 8);
              if (sVar5 <= (short)iVar8) {
                puVar14 = &DAT_006f0bc4;
              }
              _DAT_006f0bc4 = CONCAT22(DAT_006f0bc6,*puVar14);
              local_22c = (float)(unaff_EBP + -0xd0);
              piStack_230 = (int *)(unaff_EBP + -0xd8);
              cVar4 = FUN_004a156c(*(undefined4 *)(unaff_EBP + -0x44),uVar7);
              if (cVar4 != '\0') {
                local_22c = 0.0;
                piStack_230 = (int *)0x0;
                FUN_004c828c(unaff_EBP + -0x15c,unaff_EBP + -0x10,*(undefined4 *)(unaff_EBP + -0xd0)
                             ,0,*(int *)(unaff_EBP + 0x14) - *(int *)(iVar6 + 0x5c),
                             *(int *)(unaff_EBP + 0x18) -
                             ((uint)*(byte *)(unaff_EBP + -0x4b) << ((char)DAT_006f0088 + 1U & 0x1f)
                             ),0,*(undefined4 *)(unaff_EBP + 0x1c),unaff_EBP + -0x48,1,0);
              }
              _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0xac);
              *(undefined1 *)(unaff_EBP + -4) = 3;
              _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0xa8);
            }
            local_22c = *(float *)(unaff_EBP + -0x5c);
            piStack_230 = (int *)0x4ae264;
            FUN_004b4722();
          }
          else {
            if (((byte)*(undefined4 *)(unaff_EBP + -0x11c) & 0x20) != 0x20) goto LAB_004ae6fa;
            uVar25 = (uint)*(ushort *)(unaff_EBP + -0x114);
            *(uint *)(unaff_EBP + -0x44) = (uint)*(ushort *)(unaff_EBP + -0x108);
            if (uVar25 == 0) {
              if (*(ushort *)(unaff_EBP + -0x108) == 0) {
                *(uint *)(unaff_EBP + -0x44) = uVar7;
                uVar25 = uVar7;
              }
              if ((uVar25 == 0) && (*(int *)(unaff_EBP + -0x44) == 0)) goto LAB_004ae6fa;
            }
            iVar6 = *(int *)(unaff_EBP + 0x14);
            *(undefined4 *)(unaff_EBP + -0x98) = _DAT_006f0bc0;
            *(undefined4 *)(unaff_EBP + -0x94) = _DAT_006f0bc4;
            *(int *)(unaff_EBP + -0x5c) = iVar6;
            local_22c = (float)(unaff_EBP + -0xa4);
            piStack_230 = (int *)(unaff_EBP + -0x20);
            FUN_004672d0(unaff_EBP + -0x14,unaff_EBP + -0x30,unaff_EBP + -0x50);
            iVar8 = DAT_006f008c;
            if (*(int *)(unaff_EBP + -0x20) == 0) {
              iVar12 = 0;
            }
            else {
              iVar12 = ((*(int *)(unaff_EBP + -0x20) - DAT_006f008c) - 1U & 3) + 1;
            }
            *(int *)(unaff_EBP + -0x20) = iVar12;
            if (*(int *)(unaff_EBP + -0xa4) == 0) {
              iVar8 = 0;
            }
            else {
              iVar8 = ((*(int *)(unaff_EBP + -0xa4) - iVar8) - 1U & 3) + 1;
            }
            *(int *)(unaff_EBP + -0xa4) = iVar8;
            local_22c = 6.877312e-39;
            fVar28 = (float10)FUN_004b46a4();
            *(float *)(unaff_EBP + -0x18) = (float)fVar28;
            if (uVar25 != 0) {
              *(char *)(unaff_EBP + -0x34) = (char)*(undefined4 *)(unaff_EBP + -0x28);
              *(char *)(unaff_EBP + -0x33) = (char)((uint)*(undefined4 *)(unaff_EBP + -0x28) >> 8);
              *(char *)(unaff_EBP + -0x32) = (char)*(undefined2 *)(unaff_EBP + -0x26);
              *(char *)(unaff_EBP + -0x31) = (char)((ushort)*(undefined2 *)(unaff_EBP + -0x26) >> 8)
              ;
              *(undefined1 *)(unaff_EBP + -4) = 10;
              if (*(int *)(unaff_EBP + -0x30) != *(int *)(unaff_EBP + -0x50)) {
                *(undefined1 *)(unaff_EBP + -0x6e) = 0;
                *(undefined1 *)(unaff_EBP + -0x7e) = 0;
                local_22c = (float)(unaff_EBP + -0x10);
                piStack_230 = (int *)(unaff_EBP + -0x80);
                *(undefined1 *)(unaff_EBP + -4) = 0xc;
                iVar8 = FUN_004aee43(unaff_EBP + -0x70);
                if (0 < iVar8) {
                  *(undefined4 **)(unaff_EBP + -0x78) = &local_22c;
                  local_22c._0_2_ =
                       CONCAT11(*(undefined1 *)(unaff_EBP + -0x6f),
                                *(undefined1 *)(unaff_EBP + -0x70));
                  local_22c._0_3_ =
                       CONCAT12(*(undefined1 *)(unaff_EBP + -0x6e),(undefined2)local_22c);
                  local_22c = (float)CONCAT13(extraout_var_03,(undefined3)local_22c);
                  piStack_230 = (int *)0x4ae3a1;
                  uVar7 = FUN_00489b59();
                  if (*(int *)(unaff_EBP + -0x20) == 1) {
LAB_004ae3bb:
                    puVar21 = *(ushort **)(unaff_EBP + -0x30);
LAB_004ae3be:
                    uVar13 = 0;
                    if ((puVar21 != (ushort *)0x0) &&
                       (uVar13 = (uint)*puVar21, uVar13 != (uVar7 & 0xffff))) {
                      local_22c = 0.0;
                      piStack_230 = (int *)0x4ae3d3;
                      FUN_004aeeb8();
                      uVar13 = extraout_ECX_08;
                    }
                  }
                  else {
                    if (*(int *)(unaff_EBP + -0x20) == 3) {
                      puVar21 = *(ushort **)(unaff_EBP + -0x50);
                      goto LAB_004ae3be;
                    }
                    uVar13 = extraout_ECX_07;
                    if (*(int *)(unaff_EBP + -0x20) == 0) goto LAB_004ae3bb;
                  }
                  if (iVar8 == 2) {
                    *(undefined4 **)(unaff_EBP + -0x78) = &local_22c;
                    local_22c._0_2_ =
                         CONCAT11(*(undefined1 *)(unaff_EBP + -0x7f),
                                  *(undefined1 *)(unaff_EBP + -0x80));
                    local_22c._3_1_ = (undefined1)(uVar13 >> 0x18);
                    local_22c._0_3_ =
                         CONCAT12(*(undefined1 *)(unaff_EBP + -0x7e),(undefined2)local_22c);
                    piStack_230 = (int *)0x4ae3fa;
                    sVar5 = FUN_00489b59();
                    if (*(int *)(unaff_EBP + -0x20) == 1) {
LAB_004ae416:
                      psVar22 = *(short **)(unaff_EBP + -0x30);
                    }
                    else {
                      if (*(int *)(unaff_EBP + -0x20) != 3) {
                        if (*(int *)(unaff_EBP + -0x20) != 0) goto LAB_004ae42d;
                        goto LAB_004ae416;
                      }
                      psVar22 = *(short **)(unaff_EBP + -0x50);
                    }
                    if ((psVar22 != (short *)0x0) && (*psVar22 != sVar5)) {
                      local_22c = 1.4013e-45;
                      piStack_230 = (int *)0x4ae42d;
                      FUN_004aeeb8();
                    }
                  }
                }
LAB_004ae42d:
                *(undefined1 *)(unaff_EBP + -4) = 10;
              }
              if (*(int *)(unaff_EBP + -0x20) == 1) {
                sVar5 = *(short *)(unaff_EBP + 8);
              }
              else {
                sVar5 = *(short *)(unaff_EBP + 8);
              }
              if (sVar5 == -5) {
                local_22c = 6.877738e-39;
                fVar28 = (float10)FUN_004689a1();
                local_22c = (float)fVar28;
                piStack_230 = (int *)0x4ae462;
                FUN_004b4722();
              }
              puVar14 = (undefined2 *)(unaff_EBP + -0x5c);
              if (DAT_006f0bc6 <= (short)iVar6) {
                puVar14 = &DAT_006f0bc6;
              }
              _DAT_006f0bc4 = CONCAT22(*puVar14,DAT_006f0bc4);
              local_22c = (float)(unaff_EBP + -0xbc);
              piStack_230 = (int *)(unaff_EBP + -0xb8);
              cVar4 = FUN_004a156c(uVar25,DAT_006f0088);
              if (cVar4 != '\0') {
                local_22c = 0.0;
                piStack_230 = (int *)0x0;
                FUN_004c828c(unaff_EBP + -0x1bc,unaff_EBP + -0x10,*(undefined4 *)(unaff_EBP + -0xbc)
                             ,0,iVar6 - *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x5c),
                             *(int *)(unaff_EBP + 0x18) -
                             ((uint)*(byte *)(unaff_EBP + -0x4b) << ((char)DAT_006f0088 + 1U & 0x1f)
                             ),0,*(undefined4 *)(unaff_EBP + 0x1c),unaff_EBP + -0x34,1,0);
              }
              _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0x98);
              *(undefined1 *)(unaff_EBP + -4) = 3;
              _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0x94);
            }
            if (*(int *)(unaff_EBP + -0x44) != 0) {
              *(char *)(unaff_EBP + -0x38) = (char)*(undefined4 *)(unaff_EBP + -0x28);
              *(char *)(unaff_EBP + -0x37) = (char)((uint)*(undefined4 *)(unaff_EBP + -0x28) >> 8);
              *(char *)(unaff_EBP + -0x36) = (char)*(undefined2 *)(unaff_EBP + -0x26);
              *(char *)(unaff_EBP + -0x35) = (char)((ushort)*(undefined2 *)(unaff_EBP + -0x26) >> 8)
              ;
              *(undefined1 *)(unaff_EBP + -4) = 0xd;
              if (*(int *)(unaff_EBP + -0x30) != *(int *)(unaff_EBP + -0x50)) {
                *(undefined1 *)(unaff_EBP + -0x66) = 0;
                *(undefined1 *)(unaff_EBP + -0x6a) = 0;
                local_22c = (float)(unaff_EBP + -0x10);
                piStack_230 = (int *)(unaff_EBP + -0x6c);
                *(undefined1 *)(unaff_EBP + -4) = 0xf;
                iVar6 = FUN_004aee43(unaff_EBP + -0x68);
                if (0 < iVar6) {
                  *(undefined4 **)(unaff_EBP + -0x78) = &local_22c;
                  local_22c._0_2_ =
                       CONCAT11(*(undefined1 *)(unaff_EBP + -0x67),
                                *(undefined1 *)(unaff_EBP + -0x68));
                  local_22c._0_3_ =
                       CONCAT12(*(undefined1 *)(unaff_EBP + -0x66),(undefined2)local_22c);
                  local_22c = (float)CONCAT13(extraout_var_04,(undefined3)local_22c);
                  piStack_230 = (int *)0x4ae57c;
                  uVar7 = FUN_00489b59();
                  if (*(int *)(unaff_EBP + -0x20) == 1) {
                    puVar21 = *(ushort **)(unaff_EBP + -0x50);
LAB_004ae598:
                    uVar25 = 0;
                    if ((puVar21 != (ushort *)0x0) &&
                       (uVar25 = (uint)*puVar21, uVar25 != (uVar7 & 0xffff))) {
                      local_22c = 0.0;
                      piStack_230 = (int *)0x4ae5ad;
                      FUN_004aeeb8();
                      uVar25 = extraout_ECX_10;
                    }
                  }
                  else if ((*(int *)(unaff_EBP + -0x20) == 3) ||
                          (uVar25 = extraout_ECX_09, *(int *)(unaff_EBP + -0x20) == 0)) {
                    puVar21 = *(ushort **)(unaff_EBP + -0x30);
                    goto LAB_004ae598;
                  }
                  if (iVar6 == 2) {
                    *(undefined4 **)(unaff_EBP + -0x78) = &local_22c;
                    local_22c._0_2_ =
                         CONCAT11(*(undefined1 *)(unaff_EBP + -0x6b),
                                  *(undefined1 *)(unaff_EBP + -0x6c));
                    local_22c._3_1_ = (undefined1)(uVar25 >> 0x18);
                    local_22c._0_3_ =
                         CONCAT12(*(undefined1 *)(unaff_EBP + -0x6a),(undefined2)local_22c);
                    piStack_230 = (int *)0x4ae5d4;
                    sVar5 = FUN_00489b59();
                    if (*(int *)(unaff_EBP + -0x20) == 1) {
                      psVar22 = *(short **)(unaff_EBP + -0x50);
                    }
                    else {
                      if ((*(int *)(unaff_EBP + -0x20) != 3) && (*(int *)(unaff_EBP + -0x20) != 0))
                      goto LAB_004ae604;
                      psVar22 = *(short **)(unaff_EBP + -0x30);
                    }
                    if ((psVar22 != (short *)0x0) && (*psVar22 != sVar5)) {
                      local_22c = 1.4013e-45;
                      piStack_230 = (int *)0x4ae604;
                      FUN_004aeeb8();
                    }
                  }
                }
LAB_004ae604:
                iVar6 = *(int *)(unaff_EBP + 0x14);
                *(undefined1 *)(unaff_EBP + -4) = 0xd;
              }
              uVar10 = *(undefined4 *)(unaff_EBP + 0x1c);
              local_22c = 6.878367e-39;
              FUN_004b46a4();
              if (*(int *)(unaff_EBP + -0x20) == 3) {
                sVar5 = *(short *)(unaff_EBP + 8);
              }
              else {
                sVar5 = *(short *)(unaff_EBP + 8);
              }
              if (sVar5 == -5) {
                local_22c = 6.878419e-39;
                fVar28 = (float10)FUN_004689a1();
                local_22c = (float)fVar28;
                piStack_230 = (int *)0x4ae647;
                FUN_004b4722();
              }
              puVar14 = (undefined2 *)(unaff_EBP + -0x5c);
              if ((short)iVar6 <= DAT_006f0bc2) {
                puVar14 = &DAT_006f0bc2;
              }
              _DAT_006f0bc0 = CONCAT22(*puVar14,DAT_006f0bc0);
              local_22c = (float)(unaff_EBP + -0xd4);
              piStack_230 = (int *)(unaff_EBP + -0xc4);
              cVar4 = FUN_004a156c(*(undefined4 *)(unaff_EBP + -0x44),DAT_006f0088);
              if (cVar4 != '\0') {
                local_22c = 0.0;
                piStack_230 = (int *)0x0;
                FUN_004c828c(unaff_EBP + -0x17c,unaff_EBP + -0x10,*(undefined4 *)(unaff_EBP + -0xd4)
                             ,0,iVar6 - *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x5c),
                             *(int *)(unaff_EBP + 0x18) -
                             ((uint)*(byte *)(unaff_EBP + -0x4b) << ((char)DAT_006f0088 + 1U & 0x1f)
                             ),0,uVar10,unaff_EBP + -0x38,1,0);
              }
              _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0x98);
              *(undefined1 *)(unaff_EBP + -4) = 3;
              _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0x94);
            }
            local_22c = *(float *)(unaff_EBP + -0x18);
            piStack_230 = (int *)0x4ae6f3;
            FUN_004b4722();
          }
        }
        if (DAT_006f0668 == 0) {
LAB_004ae84a:
          if (*(int *)(unaff_EBP + 0x24) == 1) {
            local_22c = 6.879186e-39;
            iVar6 = FUN_004790b4();
            bVar2 = *(byte *)(*(int *)(*(int *)(iVar6 + 0x10) + *(char *)(unaff_EBP + -0x14) * 4) +
                             (int)*(char *)(unaff_EBP + -0x13));
            *(byte *)(unaff_EBP + -0x8c) = bVar2;
            *(undefined1 *)(unaff_EBP + -4) = 0x10;
            if ((bVar2 < 0x10) || (bVar2 == 0x10)) {
              local_22c = *(float *)(DAT_006e54d8 + 0x84);
              piStack_230 = (int *)0x4ae89e;
              FUN_00461628();
              if (*(byte *)(unaff_EBP + -0x8c) < 0x10) {
                uVar7 = (uint)*(byte *)(unaff_EBP + -0x8c);
                if (uVar7 < 0x10) {
                  iVar6 = (DAT_006f0088 + 0x3f) * 0x10 + uVar7;
                }
                else {
                  iVar6 = uVar7 + 0x41c + DAT_006f0088 * 4;
                }
              }
              else {
                iVar6 = DAT_006f0088 * 0x100 + -0xf4;
              }
              iVar18 = *(int *)(unaff_EBP + 0x1c);
              iVar8 = unaff_EBP + -0x28;
              iVar15 = *(int *)(iVar18 + 0x10) - *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x5c);
              iVar16 = *(int *)(iVar18 + 0x14) - *(int *)(*(int *)(unaff_EBP + -0x1c) + 100);
              local_22c = 0.0;
              piStack_230 = (int *)0x0;
              uVar33 = 0;
              uVar32 = 1;
              uVar11 = 0;
              uVar10 = 0;
              iVar12 = unaff_EBP + -0x10;
              iVar17 = unaff_EBP + -0x13c;
              iVar30 = iVar15;
              iVar31 = iVar16;
              FUN_004c656a(iVar17,iVar12,iVar6,0,iVar15,iVar16,0,iVar18,iVar8,1,0);
              FUN_004c828c(iVar17,iVar12,iVar6,uVar10,iVar30,iVar31,uVar11,iVar18,iVar8,uVar32,
                           uVar33);
              local_22c = (float)DAT_006f008c;
              piStack_230 = (int *)(unaff_EBP + -0x10);
              FUN_004790b4();
              uVar7 = FUN_00461f92();
              if (uVar7 != 0) {
                if ((uVar7 & 1) != 0) {
                  local_22c = 0.0;
                  piStack_230 = (int *)0x0;
                  uVar34 = 0xffffffff;
                  iVar6 = unaff_EBP + -0x28;
                  uVar33 = 1;
                  uVar10 = *(undefined4 *)(unaff_EBP + 0x1c);
                  iVar17 = DAT_006f0088 * 4 + 0x42c;
                  uVar32 = 0;
                  uVar11 = 0;
                  iVar8 = unaff_EBP + -0x10;
                  iVar12 = unaff_EBP + -0x14c;
                  iVar18 = iVar15;
                  iVar30 = iVar16;
                  FUN_004c656a(iVar12,iVar8,iVar17,0,iVar15,iVar16,0,uVar10,iVar6,1,0xffffffff);
                  FUN_004c828c(iVar12,iVar8,iVar17,uVar11,iVar18,iVar30,uVar32,uVar10,iVar6,uVar33,
                               uVar34);
                }
                if ((uVar7 & 2) != 0) {
                  local_22c = 0.0;
                  piStack_230 = (int *)0x0;
                  uVar34 = 0xffffffff;
                  iVar6 = unaff_EBP + -0x28;
                  uVar33 = 1;
                  uVar10 = *(undefined4 *)(unaff_EBP + 0x1c);
                  iVar17 = DAT_006f0088 * 4 + 0x42d;
                  uVar32 = 0;
                  uVar11 = 0;
                  iVar8 = unaff_EBP + -0x10;
                  iVar12 = unaff_EBP + -0x16c;
                  iVar18 = iVar15;
                  iVar30 = iVar16;
                  FUN_004c656a(iVar12,iVar8,iVar17,0,iVar15,iVar16,0,uVar10,iVar6,1,0xffffffff);
                  FUN_004c828c(iVar12,iVar8,iVar17,uVar11,iVar18,iVar30,uVar32,uVar10,iVar6,uVar33,
                               uVar34);
                }
                if ((uVar7 & 4) != 0) {
                  local_22c = 0.0;
                  piStack_230 = (int *)0x0;
                  uVar34 = 0xffffffff;
                  iVar6 = unaff_EBP + -0x28;
                  uVar33 = 1;
                  uVar10 = *(undefined4 *)(unaff_EBP + 0x1c);
                  iVar17 = DAT_006f0088 * 4 + 0x42e;
                  uVar32 = 0;
                  uVar11 = 0;
                  iVar8 = unaff_EBP + -0x10;
                  iVar12 = unaff_EBP + -0x18c;
                  iVar18 = iVar15;
                  iVar30 = iVar16;
                  FUN_004c656a(iVar12,iVar8,iVar17,0,iVar15,iVar16,0,uVar10,iVar6,1,0xffffffff);
                  FUN_004c828c(iVar12,iVar8,iVar17,uVar11,iVar18,iVar30,uVar32,uVar10,iVar6,uVar33,
                               uVar34);
                }
                if ((uVar7 & 8) != 0) {
                  local_22c = 0.0;
                  piStack_230 = (int *)0x0;
                  uVar34 = 0xffffffff;
                  iVar6 = unaff_EBP + -0x28;
                  uVar33 = 1;
                  uVar10 = *(undefined4 *)(unaff_EBP + 0x1c);
                  iVar17 = DAT_006f0088 * 4 + 0x42f;
                  uVar32 = 0;
                  uVar11 = 0;
                  iVar8 = unaff_EBP + -0x10;
                  iVar12 = unaff_EBP + -0x1ac;
                  FUN_004c656a(iVar12,iVar8,iVar17,0,iVar15,iVar16,0,uVar10,iVar6,1,0xffffffff);
                  FUN_004c828c(iVar12,iVar8,iVar17,uVar11,iVar15,iVar16,uVar32,uVar10,iVar6,uVar33,
                               uVar34);
                }
              }
            }
            *(undefined1 *)(unaff_EBP + -4) = 3;
          }
        }
        else if (*(int *)(unaff_EBP + 0x24) == 1) {
          local_22c = (float)(DAT_006f0088 & 0xff);
          piStack_230 = (int *)(unaff_EBP + -0x4c);
          FUN_004c4481(*(undefined4 *)(unaff_EBP + 0x1c),(int)*(char *)(unaff_EBP + -0x10),
                       (int)*(char *)(unaff_EBP + -0xf),*(undefined4 *)(unaff_EBP + 0x14),
                       *(undefined4 *)(unaff_EBP + 0x18));
          goto LAB_004ae84a;
        }
        iVar6 = *(int *)(unaff_EBP + -0x58);
        if ((DAT_006f0138 != '\0') && (iVar6 != 0)) {
          local_22c = 6.879931e-39;
          cVar4 = FUN_004b465e();
          if (cVar4 != '\0') {
            local_22c = 6.879954e-39;
            cVar4 = FUN_004b4665();
            if (cVar4 != '\0') {
              local_22c = (float)(unaff_EBP + -0xc0);
              piStack_230 = (int *)(unaff_EBP + -0xb4);
              FUN_00434ec8();
              uVar7 = *(uint *)(unaff_EBP + -0xb4);
              if (uVar7 != 0xffffffff) {
                *(char *)(unaff_EBP + -0x9c) = (char)uVar7;
                iVar6 = DAT_006e54d8;
                *(undefined1 *)(unaff_EBP + -4) = 0x11;
                if (0 < *(int *)(iVar6 + 0x84)) {
                  *(undefined1 *)(unaff_EBP + -0x9c) =
                       (&DAT_006efc6c)[(uVar7 & 0xff) + *(int *)(iVar6 + 0x84) * 0x100];
                }
                piVar23 = *(int **)(unaff_EBP + -0x1c);
                *(int *)(unaff_EBP + -0x44) =
                     *(int *)(*(int *)(unaff_EBP + 0x1c) + 0x10) - piVar23[0x17];
                *(int *)(unaff_EBP + 8) =
                     *(int *)(*(int *)(unaff_EBP + 0x1c) + 0x14) - piVar23[0x19];
                local_22c = 6.88012e-39;
                local_22c = (float)(**(code **)(*piVar23 + 0x14))();
                piStack_230 = (int *)0x4aeb06;
                iVar12 = FUN_004a15d2();
                local_22c = 0.0;
                *(int ***)(unaff_EBP + -0x78) = &piStack_230;
                FUN_00438c54(unaff_EBP + -0x9c);
                FUN_004a3ddb(unaff_EBP + -0xf0);
                local_22c = 6.880197e-39;
                uVar10 = FUN_00492d2c();
                *(undefined4 *)(unaff_EBP + -0x18) = uVar10;
                local_22c = 6.880212e-39;
                iVar6 = FUN_004cebb0();
                piVar23 = (int *)(*(int *)(iVar6 + (7 - *(int *)(unaff_EBP + -0x18)) * 4) +
                                  DAT_006f0084 * -4 + *(int *)(unaff_EBP + 8) * 4);
                *(int *)(unaff_EBP + -0x5c) = (int)*(char *)(unaff_EBP + -0xe);
                local_22c = 6.880269e-39;
                uVar10 = FUN_00492d2c();
                *(undefined4 *)(unaff_EBP + -0x18) = uVar10;
                local_22c = 6.880284e-39;
                iVar6 = FUN_004cebb0();
                local_22c = 0.0;
                *(undefined4 *)(unaff_EBP + -0x18) =
                     *(undefined4 *)(iVar6 + (0x24 - *(int *)(unaff_EBP + -0x18)) * 4);
                piStack_230 = (int *)0x4aeb85;
                piStack_230 = (int *)FUN_00492d2c();
                iVar17 = FUN_004c9f9a(unaff_EBP + -0x10);
                iVar6 = *(int *)(unaff_EBP + -0x5c);
                iVar8 = *(int *)(unaff_EBP + -0x18);
                local_22c = 6.880366e-39;
                FUN_004b46a4();
                local_22c = 6.88039e-39;
                iVar18 = __ftol();
                local_22c = (float)((iVar17 + (iVar6 + -1) * iVar8) - *piVar23);
                piStack_230 = piVar23;
                FUN_004b12d3(*(undefined4 *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + 8),
                             unaff_EBP + -0xf0,(*(int *)(unaff_EBP + -0xc0) - iVar18) + 0xff,
                             *(undefined4 *)(iVar12 + 0x38),*(undefined4 *)(iVar12 + 0x3c));
                iVar6 = *(int *)(unaff_EBP + -0x58);
                *(undefined1 *)(unaff_EBP + -4) = 3;
              }
            }
          }
        }
        if ((*(short *)(unaff_EBP + -0x90) != 0) && (DAT_006c723e != '\0')) {
          while (iVar6 != 0) {
            if (*(int *)(iVar6 + 0x15c) == 0) {
              if (((((int)*(char *)(unaff_EBP + -0x10) < *(int *)(DAT_006e54d8 + 0x70) + 1) ||
                   (*(int *)(DAT_006e54d8 + 0x74) + -1 < (int)*(char *)(unaff_EBP + -0x10))) ||
                  ((int)*(char *)(unaff_EBP + -0xf) < *(int *)(DAT_006e54d8 + 0x78) + 1)) ||
                 (*(int *)(DAT_006e54d8 + 0x7c) + -1 < (int)*(char *)(unaff_EBP + -0xf))) {
                bVar27 = true;
              }
              else {
                bVar27 = false;
              }
              if (!bVar27) {
                piStack_230 = *(int **)(unaff_EBP + 0x1c);
                *(undefined4 *)(unaff_EBP + -0xe8) = *(undefined4 *)(iVar6 + 0xf4);
                local_22c = -NAN;
                *(undefined4 *)(unaff_EBP + -0xe4) = *(undefined4 *)(iVar6 + 0xf8);
                FUN_004b97eb(unaff_EBP + -0xe8,*(undefined4 *)(unaff_EBP + 0x24));
                local_22c = 1.4013e-45;
                piStack_230 = (int *)0x4aec97;
                FUN_0043908c();
                *(undefined1 *)(unaff_EBP + -0x39) = 0;
                *(undefined1 *)(unaff_EBP + 0xb) = 0;
                if (*(char *)(*(int *)(unaff_EBP + -0x1c) + 0x51) == '\0') {
                  local_22c = 6.880751e-39;
                  cVar4 = FUN_004cebce();
                  if (cVar4 == '\0') {
                    iVar6 = *(int *)(unaff_EBP + -0x1c);
                    cVar4 = *(char *)(iVar6 + 0x48);
                    if (cVar4 == '\0') {
                      if (*(char *)(iVar6 + 0x49) != '\0') {
                        cVar24 = *(char *)(unaff_EBP + -0xf);
                        local_22c = 6.880814e-39;
                        uVar29 = __allshl();
                        if ((*(uint *)(iVar6 + 0x208 + cVar24 * 8) & (uint)uVar29) != 0 ||
                            (*(uint *)(iVar6 + 0x20c + cVar24 * 8) &
                            (uint)((ulonglong)uVar29 >> 0x20)) != 0) goto LAB_004aed03;
                      }
                    }
                    else {
LAB_004aed03:
                      iVar8 = *(int *)(unaff_EBP + -0x58);
                      if ((*(ushort *)(iVar8 + 0x5a) & 0x400) != 0) {
                        *(undefined1 *)(unaff_EBP + -0x60) = *(undefined1 *)(unaff_EBP + -0x10);
                        *(undefined1 *)(unaff_EBP + -0x5f) = *(undefined1 *)(unaff_EBP + -0xf);
                        *(undefined1 *)(unaff_EBP + -0x5e) = *(undefined1 *)(unaff_EBP + -0xe);
                        *(undefined1 *)(unaff_EBP + -4) = 0x12;
                        if (cVar4 == '\0') {
                          local_22c = 6.880922e-39;
                          iVar12 = FUN_00435968();
                          if (*(int **)(&DAT_006f4620 +
                                       (*(int *)(DAT_006e54d8 + 0x84) * 0x40 + iVar12) * 4) !=
                              (int *)0x0) {
                            local_22c = (float)(unaff_EBP + -0x60);
                            piStack_230 = *(int **)(&DAT_006f4620 +
                                                   (*(int *)(DAT_006e54d8 + 0x84) * 0x40 + iVar12) *
                                                   4);
                            FUN_0053c0e0();
                          }
                        }
                        if (*(int *)(iVar6 + 0x18) == *(int *)(iVar8 + 0x110)) {
                          if (*(char *)(iVar6 + 0x48) == '\0') {
                            cVar4 = *(char *)(unaff_EBP + -0x5f);
                            local_22c = 6.881027e-39;
                            uVar29 = __allshl();
                            if ((*(uint *)(iVar6 + 0x208 + cVar4 * 8) & (uint)uVar29) == 0 &&
                                (*(uint *)(iVar6 + 0x20c + cVar4 * 8) &
                                (uint)((ulonglong)uVar29 >> 0x20)) == 0) goto LAB_004aedb2;
                          }
                          sVar5 = *(short *)(iVar8 + 0x8e);
                          *(undefined1 *)(unaff_EBP + 0xb) = 1;
                          *(bool *)(unaff_EBP + -0x39) = sVar5 != 0;
                          *(undefined2 *)(iVar8 + 0x8e) = 1;
                        }
LAB_004aedb2:
                        *(undefined1 *)(unaff_EBP + -4) = 3;
                      }
                    }
                  }
                }
                piVar23 = *(int **)(unaff_EBP + -0x58);
                local_22c = *(float *)(unaff_EBP + 0x1c);
                piStack_230 = (int *)(unaff_EBP + -0x1cc);
                (**(code **)(*piVar23 + 0x30))();
                if (*(char *)(unaff_EBP + 0xb) != '\0') {
                  *(ushort *)((int)piVar23 + 0x8e) = (ushort)*(byte *)(unaff_EBP + -0x39);
                }
                local_22c = 0.0;
                piStack_230 = (int *)0x4aede6;
                FUN_004b46ec();
              }
            }
            local_22c = 6.881185e-39;
            iVar6 = FUN_00432705();
            *(int *)(unaff_EBP + -0x58) = iVar6;
          }
        }
      }
      else {
        iVar6 = *(int *)(*(int *)(DAT_006e54dc + 0x34) + 0xc);
        uVar7 = ((byte)~*(byte *)(*(int *)(iVar6 + *(char *)(unaff_EBP + -0x14) * 4) +
                                 (int)*(char *)(unaff_EBP + -0x13)) & 0x20) >> 5;
        *(uint *)(unaff_EBP + 8) = uVar7;
        if (uVar7 != 0) goto LAB_004adba1;
      }
      *(int *)(unaff_EBP + -0x88) = *(int *)(unaff_EBP + -0x88) + 1;
      cVar4 = *(char *)(unaff_EBP + -0x10) + **(char **)(unaff_EBP + 0x10);
      cVar24 = *(char *)(unaff_EBP + -0xf) + (*(char **)(unaff_EBP + 0x10))[1];
      *(undefined1 *)(unaff_EBP + -4) = 1;
      *(char *)(unaff_EBP + -0x10) = cVar4;
      *(char *)(unaff_EBP + -0xf) = cVar24;
      *(int *)(unaff_EBP + 0x14) =
           *(int *)(unaff_EBP + 0x14) + *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x58);
    } while (*(int *)(unaff_EBP + -0x88) < *(int *)(unaff_EBP + 0xc));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

