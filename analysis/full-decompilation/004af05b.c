
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004af05b(void)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  int *piVar4;
  undefined1 uVar5;
  char cVar6;
  char cVar7;
  short sVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  char *pcVar11;
  undefined4 *puVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  undefined2 uVar17;
  undefined2 extraout_var;
  undefined2 *puVar16;
  undefined2 extraout_var_00;
  int extraout_ECX;
  int iVar18;
  uint uVar19;
  undefined1 extraout_var_01;
  undefined1 extraout_var_02;
  undefined1 extraout_var_03;
  undefined1 extraout_var_04;
  undefined1 extraout_var_05;
  undefined1 extraout_var_06;
  int extraout_ECX_00;
  undefined1 extraout_var_07;
  undefined1 extraout_var_08;
  undefined1 uVar24;
  undefined1 extraout_var_09;
  uint extraout_ECX_01;
  uint uVar20;
  uint extraout_ECX_02;
  undefined1 extraout_var_10;
  uint extraout_ECX_03;
  uint extraout_ECX_04;
  ushort *puVar21;
  int iVar22;
  undefined1 extraout_var_11;
  uint extraout_ECX_05;
  uint extraout_ECX_06;
  undefined1 extraout_var_12;
  uint extraout_ECX_07;
  uint extraout_ECX_08;
  short *psVar23;
  int iVar25;
  int unaff_EBP;
  undefined4 *puVar26;
  bool bVar27;
  float10 fVar28;
  int iVar29;
  undefined4 uVar30;
  undefined4 local_214;
  
  FUN_00634c24();
  cVar7 = *(char *)(extraout_ECX + 0x17b);
  *(int *)(unaff_EBP + -0x24) = extraout_ECX;
  if (cVar7 != '\0') {
    pcVar11 = *(char **)(unaff_EBP + 8);
    cVar7 = *pcVar11;
    cVar6 = pcVar11[1];
    cVar1 = pcVar11[2];
    *(char *)(unaff_EBP + -0x10) = cVar7;
    *(char *)(unaff_EBP + -0xf) = cVar6;
    *(char *)(unaff_EBP + -0xe) = cVar1;
    uVar9 = *(undefined4 *)(DAT_006e54dc + 0x10);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0xb4) = uVar9;
    *(undefined4 *)(unaff_EBP + -0xd0) = uVar9;
    puVar12 = (undefined4 *)(unaff_EBP + -0x144);
    for (iVar18 = 0xb; iVar18 != 0; iVar18 = iVar18 + -1) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(undefined4 *)(unaff_EBP + -0xb0) = 0;
    if (0 < *(int *)(unaff_EBP + 0xc)) {
      do {
        if ((*(byte *)(unaff_EBP + -0x11c) & 0x10) != 0) {
          puVar12 = (undefined4 *)(unaff_EBP + -0x144);
          for (iVar18 = 0xb; iVar18 != 0; iVar18 = iVar18 + -1) {
            *puVar12 = 0;
            puVar12 = puVar12 + 1;
          }
        }
        *(char *)(unaff_EBP + -0x14) = cVar7;
        *(char *)(unaff_EBP + -0x13) = cVar6;
        *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(unaff_EBP + -0xe);
        iVar18 = DAT_006e54d8;
        *(undefined1 *)(unaff_EBP + -4) = 2;
        local_214 = (float)(-*(int *)(iVar18 + 0x84) & 3);
        FUN_00434ffd();
        cVar7 = *(char *)(unaff_EBP + -0x14);
        iVar25 = (int)cVar7;
        *(int *)(unaff_EBP + -0x58) = (int)*(char *)(unaff_EBP + -0x13);
        iVar18 = DAT_006e54dc;
        if (((*(char *)(*(int *)(unaff_EBP + -0x24) + 0x50) == '\0') || (DAT_006e4a84 != 0)) ||
           (uVar19 = ((byte)~*(byte *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x34) + 0xc) +
                                               iVar25 * 4) + *(int *)(unaff_EBP + -0x58)) & 0x20) >>
                     5, *(uint *)(unaff_EBP + 8) = uVar19, uVar19 != 0)) {
          iVar13 = *(int *)(unaff_EBP + -0x58) * 2;
          uVar3 = *(ushort *)
                   (*(int *)(*(int *)(*(int *)(iVar18 + 0x20 + *(char *)(unaff_EBP + -0x12) * 4) +
                                     0xc) + iVar25 * 4) + iVar13);
          *(undefined2 *)(unaff_EBP + -0x48) =
               *(undefined2 *)
                (*(int *)(*(int *)(*(int *)(iVar18 + 0x28 + *(char *)(unaff_EBP + -0x12) * 4) + 0xc)
                         + iVar25 * 4) + iVar13);
          local_214 = (float)(unaff_EBP + -0x14c);
          *(uint *)(unaff_EBP + -0x60) = (uint)uVar3;
          uVar9 = FUN_00434d3d();
          local_214 = 1.4013e-45;
          fVar28 = (float10)FUN_0046755a(uVar9);
          local_214 = (float)fVar28;
          FUN_004b4722();
          *(undefined4 *)(unaff_EBP + 8) = 0;
          *(int *)(unaff_EBP + -0x18) = iVar25 + -1;
          puVar12 = (undefined4 *)(unaff_EBP + 8);
          if (-1 < iVar25 + -1) {
            puVar12 = (undefined4 *)(unaff_EBP + -0x18);
          }
          *(undefined4 *)(unaff_EBP + 8) = *puVar12;
          *(int *)(unaff_EBP + -0x18) = iVar25 + 1;
          puVar12 = (undefined4 *)(unaff_EBP + -0xd0);
          if (iVar25 + 1 <= *(int *)(unaff_EBP + -0xb4)) {
            puVar12 = (undefined4 *)(unaff_EBP + -0x18);
          }
          uVar9 = *puVar12;
          *(undefined4 *)(unaff_EBP + -0x18) = 0;
          *(undefined4 *)(unaff_EBP + -0xcc) = uVar9;
          iVar18 = *(int *)(unaff_EBP + -0x58) + -1;
          *(int *)(unaff_EBP + -0x5c) = iVar18;
          puVar12 = (undefined4 *)(unaff_EBP + -0x18);
          if (-1 < iVar18) {
            puVar12 = (undefined4 *)(unaff_EBP + -0x5c);
          }
          uVar9 = *puVar12;
          iVar18 = *(int *)(unaff_EBP + -0x58) + 1;
          *(int *)(unaff_EBP + -0x18) = iVar18;
          *(undefined4 *)(unaff_EBP + -0x5c) = uVar9;
          puVar12 = (undefined4 *)(unaff_EBP + -0xd0);
          if (iVar18 <= *(int *)(unaff_EBP + -0xb4)) {
            puVar12 = (undefined4 *)(unaff_EBP + -0x18);
          }
          *(undefined4 *)(unaff_EBP + -0x18) = *puVar12;
          *(undefined4 **)(unaff_EBP + -0x4c) = &local_214;
          local_214._0_2_ =
               CONCAT11(*(undefined1 *)(unaff_EBP + -0xf),*(undefined1 *)(unaff_EBP + -0x10));
          local_214._3_1_ = (char)((uint)uVar9 >> 0x18);
          local_214._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0xe),(undefined2)local_214);
          FUN_004796d9(unaff_EBP + -0x3c);
          uVar24 = extraout_var_01;
          if (DAT_006c723a != '\0') {
            if (*(int *)(unaff_EBP + -0x60) != 0) {
              iVar18 = *(int *)(*(int *)(DAT_006e54dc + 0x24) + 0xc);
              iVar25 = *(char *)(unaff_EBP + -0x58) * 2;
              if (((*(short *)(*(int *)(iVar18 + *(char *)(unaff_EBP + 8) * 4) + iVar25) != 0) &&
                  (*(short *)(*(int *)(iVar18 + *(char *)(unaff_EBP + -0xcc) * 4) + iVar25) != 0))
                 && ((iVar18 = *(int *)(iVar18 + cVar7 * 4),
                     *(short *)(iVar18 + *(char *)(unaff_EBP + -0x5c) * 2) != 0 &&
                     (*(short *)(iVar18 + *(char *)(unaff_EBP + -0x18) * 2) != 0)))) {
                *(undefined1 *)(unaff_EBP + -0x76) = 1;
                *(undefined1 *)(unaff_EBP + -0x78) = *(undefined1 *)(unaff_EBP + 8);
                *(undefined1 *)(unaff_EBP + -0x77) = *(undefined1 *)(unaff_EBP + -0x58);
                local_214 = (float)(unaff_EBP + -0x78);
                *(undefined1 *)(unaff_EBP + -4) = 3;
                cVar6 = FUN_004790bc();
                *(undefined1 *)(unaff_EBP + -4) = 2;
                cVar6 = '\x01' - (cVar6 != '\0');
                *(char *)(unaff_EBP + 0xb) = cVar6;
                if (cVar6 == '\0') {
                  *(undefined1 *)(unaff_EBP + -0x62) = 1;
                  *(undefined1 *)(unaff_EBP + -100) = *(undefined1 *)(unaff_EBP + -0xcc);
                  *(undefined1 *)(unaff_EBP + -99) = *(undefined1 *)(unaff_EBP + -0x58);
                  local_214 = (float)(unaff_EBP + -100);
                  *(undefined1 *)(unaff_EBP + -4) = 4;
                  cVar6 = FUN_004790bc();
                  *(undefined1 *)(unaff_EBP + -4) = 2;
                  cVar6 = '\x01' - (cVar6 != '\0');
                  *(char *)(unaff_EBP + 0xb) = cVar6;
                  if (cVar6 == '\0') {
                    *(char *)(unaff_EBP + -0x70) = cVar7;
                    *(undefined1 *)(unaff_EBP + -0x6f) = *(undefined1 *)(unaff_EBP + -0x5c);
                    *(undefined1 *)(unaff_EBP + -0x6e) = 1;
                    local_214 = (float)(unaff_EBP + -0x70);
                    *(undefined1 *)(unaff_EBP + -4) = 5;
                    cVar6 = FUN_004790bc();
                    *(undefined1 *)(unaff_EBP + -4) = 2;
                    cVar6 = '\x01' - (cVar6 != '\0');
                    *(char *)(unaff_EBP + 0xb) = cVar6;
                    if (cVar6 == '\0') {
                      *(char *)(unaff_EBP + -0x6c) = cVar7;
                      *(undefined1 *)(unaff_EBP + -0x6b) = *(undefined1 *)(unaff_EBP + -0x18);
                      *(undefined1 *)(unaff_EBP + -0x6a) = 1;
                      local_214 = (float)(unaff_EBP + -0x6c);
                      *(undefined1 *)(unaff_EBP + -4) = 6;
                      cVar7 = FUN_004790bc();
                      *(undefined1 *)(unaff_EBP + -4) = 2;
                      cVar7 = '\x01' - (cVar7 != '\0');
                      *(char *)(unaff_EBP + 0xb) = cVar7;
                      uVar24 = extraout_var_02;
                      if (cVar7 == '\0') goto LAB_004af64b;
                    }
                  }
                }
              }
            }
            local_214 = -NAN;
            uVar9 = *(undefined4 *)(unaff_EBP + 0x1c);
            uVar30 = 1;
            uVar10 = FUN_00434d3d(unaff_EBP + -0x15c);
            FUN_004b97eb(uVar10,uVar30,uVar9);
            local_214 = (float)(DAT_006f0088 & 0xff);
            FUN_004c44da(*(undefined4 *)(unaff_EBP + 0x1c),(int)*(char *)(unaff_EBP + -0x10),
                         (int)*(char *)(unaff_EBP + -0xf),*(undefined4 *)(unaff_EBP + 0x14),
                         *(undefined4 *)(unaff_EBP + 0x18),unaff_EBP + -0x3c);
            *(undefined4 **)(unaff_EBP + 8) = &local_214;
            local_214._0_2_ =
                 CONCAT11(*(undefined1 *)(unaff_EBP + -0xf),*(undefined1 *)(unaff_EBP + -0x10));
            local_214._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0xe),(undefined2)local_214);
            local_214 = (float)CONCAT13(extraout_var_03,(undefined3)local_214);
            cVar7 = FUN_0047c29a();
            uVar5 = DAT_006e481c;
            uVar24 = extraout_var_04;
            if (cVar7 == '\0') {
              *(undefined1 *)(unaff_EBP + -0x72) = 0;
              *(undefined1 *)(unaff_EBP + -0x74) = uVar5;
              *(undefined1 *)(unaff_EBP + -0x73) = DAT_006e481d;
              local_214 = (float)(unaff_EBP + -0x74);
              pcVar11 = (char *)FUN_0046185f(unaff_EBP + -0x118);
              local_214 = (float)DAT_006e54d8;
              uVar24 = DAT_006e481c;
              if ((((int)*pcVar11 < *(int *)(DAT_006e54d8 + 0x70)) ||
                  (*(int *)(DAT_006e54d8 + 0x74) < (int)*pcVar11)) ||
                 (((int)pcVar11[1] < *(int *)(DAT_006e54d8 + 0x78) ||
                  (*(int *)(DAT_006e54d8 + 0x7c) < (int)pcVar11[1])))) {
LAB_004af484:
                uVar24 = DAT_006e4822;
                *(undefined1 *)(unaff_EBP + -0x86) = 0;
                *(undefined1 *)(unaff_EBP + -0x88) = uVar24;
                *(undefined1 *)(unaff_EBP + -0x87) = DAT_006e4823;
                local_214 = (float)(unaff_EBP + -0x88);
                pcVar11 = (char *)FUN_0046185f(unaff_EBP + -0x110);
                local_214 = (float)DAT_006e54d8;
                uVar24 = DAT_006e4822;
                if ((((*(int *)(DAT_006e54d8 + 0x70) <= (int)*pcVar11) &&
                     ((int)*pcVar11 <= *(int *)(DAT_006e54d8 + 0x74))) &&
                    (*(int *)(DAT_006e54d8 + 0x78) <= (int)pcVar11[1])) &&
                   ((int)pcVar11[1] <= *(int *)(DAT_006e54d8 + 0x7c))) {
                  *(undefined1 *)(unaff_EBP + -0x82) = 0;
                  *(undefined1 *)(unaff_EBP + -0x84) = uVar24;
                  *(undefined1 *)(unaff_EBP + -0x83) = DAT_006e4823;
                  *(undefined4 **)(unaff_EBP + 8) = &local_214;
                  *(undefined1 *)(unaff_EBP + -4) = 0xc;
                  FUN_0046185f(&local_214,unaff_EBP + -0x84);
                  cVar7 = FUN_0047c29a();
                  uVar24 = extraout_var_06;
                  if (cVar7 != '\0') goto LAB_004af5a8;
                }
                uVar24 = DAT_006e4828;
                *(undefined1 *)(unaff_EBP + -0x7a) = 0;
                *(undefined1 *)(unaff_EBP + -0x7c) = uVar24;
                *(undefined1 *)(unaff_EBP + -0x7b) = DAT_006e4829;
                local_214 = (float)(unaff_EBP + -0x7c);
                pcVar11 = (char *)FUN_0046185f(unaff_EBP + -0x114);
                uVar24 = DAT_006e4828;
                local_214 = (float)(int)*pcVar11;
                if (((*(int *)(DAT_006e54d8 + 0x70) <= (int)local_214) &&
                    ((int)local_214 <= *(int *)(DAT_006e54d8 + 0x74))) &&
                   ((*(int *)(DAT_006e54d8 + 0x78) <= (int)pcVar11[1] &&
                    ((int)pcVar11[1] <= *(int *)(DAT_006e54d8 + 0x7c))))) {
                  *(undefined1 *)(unaff_EBP + -0x66) = 0;
                  *(undefined1 *)(unaff_EBP + -0x68) = uVar24;
                  *(undefined1 *)(unaff_EBP + -0x67) = DAT_006e4829;
                  *(undefined4 **)(unaff_EBP + 8) = &local_214;
                  *(undefined1 *)(unaff_EBP + -4) = 0xf;
                  FUN_0046185f(&local_214,unaff_EBP + -0x68);
                  cVar7 = FUN_0047c29a();
                  uVar24 = (undefined1)((uint)extraout_ECX_00 >> 0x18);
                  local_214 = (float)extraout_ECX_00;
                  if (cVar7 != '\0') goto LAB_004af5a8;
                }
                uVar24 = (undefined1)((uint)local_214 >> 0x18);
                bVar27 = false;
              }
              else {
                *(undefined1 *)(unaff_EBP + -0x7e) = 0;
                *(undefined1 *)(unaff_EBP + -0x80) = uVar24;
                *(undefined1 *)(unaff_EBP + -0x7f) = DAT_006e481d;
                *(undefined4 **)(unaff_EBP + 8) = &local_214;
                *(undefined1 *)(unaff_EBP + -4) = 9;
                FUN_0046185f(&local_214,unaff_EBP + -0x80);
                cVar7 = FUN_0047c29a();
                uVar24 = extraout_var_05;
                if (cVar7 == '\0') goto LAB_004af484;
LAB_004af5a8:
                bVar27 = true;
              }
              *(undefined1 *)(unaff_EBP + -4) = 2;
              if (bVar27) {
                local_214 = (float)(unaff_EBP + -0xe4);
                cVar7 = FUN_004a156c(1,DAT_006f0088,unaff_EBP + -0x10c);
                uVar24 = extraout_var_07;
                if (cVar7 != '\0') {
                  *(undefined1 *)(unaff_EBP + -0x91) = 0x7f;
                  *(undefined1 *)(unaff_EBP + -0x92) = 0x7f;
                  *(undefined1 *)(unaff_EBP + -0x93) = 0x7f;
                  *(undefined1 *)(unaff_EBP + -0x94) = 0x7f;
                  local_214 = 0.0;
                  cVar7 = (char)DAT_006f0088;
                  *(undefined1 *)(unaff_EBP + -4) = 0x10;
                  FUN_004c828c(unaff_EBP + -0x1a4,unaff_EBP + -0x10,
                               *(undefined4 *)(unaff_EBP + -0xe4),0,
                               *(int *)(unaff_EBP + 0x14) -
                               *(int *)(*(int *)(unaff_EBP + -0x24) + 0x5c),
                               *(int *)(unaff_EBP + 0x18) -
                               ((uint)*(byte *)(unaff_EBP + -0x3b) << (cVar7 + 1U & 0x1f)),0,
                               *(undefined4 *)(unaff_EBP + 0x1c),unaff_EBP + -0x94,0,0,1);
                  *(undefined1 *)(unaff_EBP + -4) = 2;
                  uVar24 = extraout_var_08;
                }
              }
            }
          }
LAB_004af64b:
          if ((*(int *)(unaff_EBP + -0x60) != 0) && (DAT_006c723b != '\0')) {
            *(undefined4 **)(unaff_EBP + 8) = &local_214;
            local_214._0_2_ =
                 CONCAT11(*(undefined1 *)(unaff_EBP + -0xf),*(undefined1 *)(unaff_EBP + -0x10));
            local_214._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0xe),(undefined2)local_214);
            local_214 = (float)CONCAT13(uVar24,(undefined3)local_214);
            FUN_004aef32(unaff_EBP + -0x44);
            *(undefined1 *)(unaff_EBP + -4) = 0x11;
            local_214 = 6.884282e-39;
            fVar28 = (float10)FUN_004b46a4();
            *(float *)(unaff_EBP + -0x5c) = (float)fVar28;
            if (*(char *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x40 +
                                                    *(char *)(unaff_EBP + -0x12) * 4) + 0xc) +
                                  *(char *)(unaff_EBP + -0x14) * 4) +
                         *(char *)(unaff_EBP + -0x13) * 0xe) == '\0') {
LAB_004b019c:
              local_214 = (float)(unaff_EBP + -0xf4);
              cVar7 = FUN_004a156c(*(undefined4 *)(unaff_EBP + -0x60),DAT_006f0088,
                                   unaff_EBP + -0x104);
              if (cVar7 != '\0') {
                local_214 = 0.0;
                FUN_004c828c(unaff_EBP + -0x184,unaff_EBP + -0x10,*(undefined4 *)(unaff_EBP + -0xf4)
                             ,0,*(int *)(unaff_EBP + 0x14) -
                                *(int *)(*(int *)(unaff_EBP + -0x24) + 0x5c),
                             *(int *)(unaff_EBP + 0x18) -
                             ((uint)*(byte *)(unaff_EBP + -0x3b) << ((char)DAT_006f0088 + 1U & 0x1f)
                             ),0,*(undefined4 *)(unaff_EBP + 0x1c),unaff_EBP + -0x44,0,0,0);
              }
            }
            else {
              *(undefined4 **)(unaff_EBP + 8) = &local_214;
              local_214._0_2_ =
                   CONCAT11(*(undefined1 *)(unaff_EBP + -0xf),*(undefined1 *)(unaff_EBP + -0x10));
              local_214._3_1_ = (char)*(char *)(unaff_EBP + -0x14) >> 7;
              local_214._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + -0xe),(undefined2)local_214);
              puVar12 = (undefined4 *)FUN_00467768(unaff_EBP + -0x210);
              puVar26 = (undefined4 *)(unaff_EBP + -0x144);
              for (iVar18 = 0xb; iVar18 != 0; iVar18 = iVar18 + -1) {
                *puVar26 = *puVar12;
                puVar12 = puVar12 + 1;
                puVar26 = puVar26 + 1;
              }
              if (((byte)*(undefined4 *)(unaff_EBP + -0x144) & 0x10) == 0x10) {
                uVar19 = (uint)*(ushort *)(unaff_EBP + -0x130);
                *(uint *)(unaff_EBP + 8) = (uint)*(ushort *)(unaff_EBP + -0x13c);
                if (*(ushort *)(unaff_EBP + -0x13c) == 0) {
                  uVar15 = 0;
                  if (uVar19 == 0) {
                    uVar15 = *(uint *)(unaff_EBP + -0x60);
                    *(uint *)(unaff_EBP + 8) = uVar15;
                    uVar19 = uVar15;
                  }
                  if ((uVar15 == 0) && (uVar19 == 0)) goto LAB_004b019c;
                }
                iVar18 = *(int *)(unaff_EBP + -0x24);
                *(undefined4 *)(unaff_EBP + -0xdc) = _DAT_006f0bc0;
                *(undefined4 *)(unaff_EBP + -0xd8) = _DAT_006f0bc4;
                local_214 = (float)(unaff_EBP + -0xc0);
                FUN_004672d0(unaff_EBP + -0x14,unaff_EBP + -0x28,unaff_EBP + -0x54,unaff_EBP + -0x1c
                            );
                iVar25 = DAT_006f008c;
                if (*(int *)(unaff_EBP + -0x1c) == 0) {
                  iVar13 = 0;
                }
                else {
                  iVar13 = ((*(int *)(unaff_EBP + -0x1c) - DAT_006f008c) - 1U & 3) + 1;
                }
                *(int *)(unaff_EBP + -0x1c) = iVar13;
                if (*(int *)(unaff_EBP + -0xc0) == 0) {
                  iVar25 = 0;
                }
                else {
                  iVar25 = ((*(int *)(unaff_EBP + -0xc0) - iVar25) - 1U & 3) + 1;
                }
                *(int *)(unaff_EBP + -0xc0) = iVar25;
                if (uVar19 != 0) {
                  *(char *)(unaff_EBP + -0x40) = (char)*(undefined4 *)(unaff_EBP + -0x44);
                  *(char *)(unaff_EBP + -0x3f) =
                       (char)((uint)*(undefined4 *)(unaff_EBP + -0x44) >> 8);
                  *(char *)(unaff_EBP + -0x3e) = (char)*(undefined2 *)(unaff_EBP + -0x42);
                  *(char *)(unaff_EBP + -0x3d) =
                       (char)((ushort)*(undefined2 *)(unaff_EBP + -0x42) >> 8);
                  uVar15 = *(uint *)(unaff_EBP + -0x28);
                  *(undefined1 *)(unaff_EBP + -4) = 0x12;
                  if (uVar15 != *(uint *)(unaff_EBP + -0x54)) {
                    *(undefined1 *)(unaff_EBP + -0xa6) = 0;
                    *(undefined1 *)(unaff_EBP + -0xa2) = 0;
                    local_214 = (float)(unaff_EBP + -0x10);
                    *(undefined1 *)(unaff_EBP + -4) = 0x14;
                    uVar14 = FUN_004aee43(unaff_EBP + -0xa8,unaff_EBP + -0xa4);
                    uVar15 = uVar14;
                    if (0 < (int)uVar14) {
                      *(undefined4 **)(unaff_EBP + -0x4c) = &local_214;
                      local_214._0_2_ =
                           CONCAT11(*(undefined1 *)(unaff_EBP + -0xa7),
                                    *(undefined1 *)(unaff_EBP + -0xa8));
                      local_214._0_3_ =
                           CONCAT12(*(undefined1 *)(unaff_EBP + -0xa6),(undefined2)local_214);
                      local_214 = (float)CONCAT13(extraout_var_09,(undefined3)local_214);
                      uVar15 = FUN_00489b59();
                      uVar15 = uVar15 & 0xffff;
                      if (*(int *)(unaff_EBP + -0x1c) == 4) {
                        puVar21 = *(ushort **)(unaff_EBP + -0x54);
LAB_004af852:
                        uVar20 = 0;
                        if ((puVar21 != (ushort *)0x0) &&
                           (uVar20 = (uint)*puVar21, uVar20 != uVar15)) {
                          local_214 = 0.0;
                          uVar15 = FUN_004aeeb8();
                          uVar20 = extraout_ECX_02;
                        }
                      }
                      else if ((*(int *)(unaff_EBP + -0x1c) == 2) ||
                              (uVar20 = extraout_ECX_01, *(int *)(unaff_EBP + -0x1c) == 0)) {
                        puVar21 = *(ushort **)(unaff_EBP + -0x28);
                        goto LAB_004af852;
                      }
                      if (uVar14 == 2) {
                        *(undefined4 **)(unaff_EBP + -0x4c) = &local_214;
                        local_214._0_2_ =
                             CONCAT11(*(undefined1 *)(unaff_EBP + -0xa3),
                                      *(undefined1 *)(unaff_EBP + -0xa4));
                        local_214._3_1_ = (char)(uVar20 >> 0x18);
                        local_214._0_3_ =
                             CONCAT12(*(undefined1 *)(unaff_EBP + -0xa2),(undefined2)local_214);
                        uVar15 = FUN_00489b59();
                        uVar15 = uVar15 & 0xffff;
                        if (*(int *)(unaff_EBP + -0x1c) == 4) {
                          puVar21 = *(ushort **)(unaff_EBP + -0x54);
                        }
                        else {
                          if ((*(int *)(unaff_EBP + -0x1c) != 2) &&
                             (*(int *)(unaff_EBP + -0x1c) != 0)) goto LAB_004af8c7;
                          puVar21 = *(ushort **)(unaff_EBP + -0x28);
                        }
                        if ((puVar21 != (ushort *)0x0) && (*puVar21 != uVar15)) {
                          local_214 = 1.4013e-45;
                          uVar15 = FUN_004aeeb8();
                        }
                      }
                    }
LAB_004af8c7:
                    iVar18 = *(int *)(unaff_EBP + -0x24);
                    *(undefined1 *)(unaff_EBP + -4) = 0x12;
                  }
                  uVar17 = (undefined2)(uVar15 >> 0x10);
                  if (*(int *)(unaff_EBP + -0x1c) == 2) {
                    sVar8 = *(short *)(unaff_EBP + -0x48);
                  }
                  else {
                    sVar8 = *(short *)(unaff_EBP + -0x48);
                  }
                  if (sVar8 == -5) {
                    local_214 = 6.88513e-39;
                    fVar28 = (float10)FUN_004689a1();
                    local_214 = (float)fVar28;
                    FUN_004b4722();
                    uVar17 = extraout_var;
                  }
                  uVar15 = DAT_006f0088;
                  iVar25 = CONCAT22(uVar17,(ushort)*(byte *)(unaff_EBP + -0x3b)) <<
                           ((char)DAT_006f0088 + 1U & 0x1f);
                  iVar25 = CONCAT22((short)((uint)iVar25 >> 0x10),
                                    *(short *)(iVar18 + 100) - (short)iVar25) +
                           *(int *)(unaff_EBP + 0x18);
                  sVar8 = DAT_006f0bc0;
                  *(int *)(unaff_EBP + -0x18) = iVar25;
                  puVar16 = (undefined2 *)(unaff_EBP + -0x18);
                  if ((short)iVar25 <= sVar8) {
                    puVar16 = &DAT_006f0bc0;
                  }
                  _DAT_006f0bc0 = CONCAT22(DAT_006f0bc2,*puVar16);
                  local_214 = (float)(unaff_EBP + -0x108);
                  cVar7 = FUN_004a156c(uVar19,uVar15,unaff_EBP + -0xf0);
                  if (cVar7 != '\0') {
                    local_214 = 0.0;
                    FUN_004c828c(unaff_EBP + -0x1d4,unaff_EBP + -0x10,
                                 *(undefined4 *)(unaff_EBP + -0x108),0,
                                 *(int *)(unaff_EBP + 0x14) - *(int *)(iVar18 + 0x5c),
                                 *(int *)(unaff_EBP + 0x18) -
                                 ((uint)*(byte *)(unaff_EBP + -0x3b) <<
                                 ((char)DAT_006f0088 + 1U & 0x1f)),0,
                                 *(undefined4 *)(unaff_EBP + 0x1c),unaff_EBP + -0x40,0,0,0);
                  }
                  _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0xdc);
                  *(undefined1 *)(unaff_EBP + -4) = 0x11;
                  _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0xd8);
                }
                if (*(int *)(unaff_EBP + 8) != 0) {
                  *(char *)(unaff_EBP + -0x30) = (char)*(undefined4 *)(unaff_EBP + -0x44);
                  *(char *)(unaff_EBP + -0x2f) =
                       (char)((uint)*(undefined4 *)(unaff_EBP + -0x44) >> 8);
                  *(char *)(unaff_EBP + -0x2e) = (char)*(undefined2 *)(unaff_EBP + -0x42);
                  *(char *)(unaff_EBP + -0x2d) =
                       (char)((ushort)*(undefined2 *)(unaff_EBP + -0x42) >> 8);
                  uVar19 = *(uint *)(unaff_EBP + -0x28);
                  *(undefined1 *)(unaff_EBP + -4) = 0x15;
                  if (uVar19 != *(uint *)(unaff_EBP + -0x54)) {
                    *(undefined1 *)(unaff_EBP + -0x9a) = 0;
                    *(undefined1 *)(unaff_EBP + -0xaa) = 0;
                    local_214 = (float)(unaff_EBP + -0x10);
                    *(undefined1 *)(unaff_EBP + -4) = 0x17;
                    uVar19 = FUN_004aee43(unaff_EBP + -0x9c,unaff_EBP + -0xac);
                    if (0 < (int)uVar19) {
                      *(undefined4 **)(unaff_EBP + -0x4c) = &local_214;
                      local_214._0_2_ =
                           CONCAT11(*(undefined1 *)(unaff_EBP + -0x9b),
                                    *(undefined1 *)(unaff_EBP + -0x9c));
                      local_214._0_3_ =
                           CONCAT12(*(undefined1 *)(unaff_EBP + -0x9a),(undefined2)local_214);
                      local_214 = (float)CONCAT13(extraout_var_10,(undefined3)local_214);
                      uVar15 = FUN_00489b59();
                      uVar15 = uVar15 & 0xffff;
                      if (*(int *)(unaff_EBP + -0x1c) == 4) {
                        puVar21 = *(ushort **)(unaff_EBP + -0x28);
LAB_004afa68:
                        uVar14 = 0;
                        if ((puVar21 != (ushort *)0x0) &&
                           (uVar14 = (uint)*puVar21, uVar14 != uVar15)) {
                          local_214 = 0.0;
                          uVar15 = FUN_004aeeb8();
                          uVar14 = extraout_ECX_04;
                        }
                      }
                      else {
                        if (*(int *)(unaff_EBP + -0x1c) == 2) {
                          puVar21 = *(ushort **)(unaff_EBP + -0x54);
                          goto LAB_004afa68;
                        }
                        uVar14 = extraout_ECX_03;
                        if (*(int *)(unaff_EBP + -0x1c) == 0) {
                          puVar21 = *(ushort **)(unaff_EBP + -0x28);
                          goto LAB_004afa68;
                        }
                      }
                      bVar27 = uVar19 == 2;
                      uVar19 = uVar15;
                      if (bVar27) {
                        *(undefined4 **)(unaff_EBP + -0x4c) = &local_214;
                        local_214._0_2_ =
                             CONCAT11(*(undefined1 *)(unaff_EBP + -0xab),
                                      *(undefined1 *)(unaff_EBP + -0xac));
                        local_214._3_1_ = (char)(uVar14 >> 0x18);
                        local_214._0_3_ =
                             CONCAT12(*(undefined1 *)(unaff_EBP + -0xaa),(undefined2)local_214);
                        uVar19 = FUN_00489b59();
                        uVar19 = uVar19 & 0xffff;
                        if (*(int *)(unaff_EBP + -0x1c) == 4) {
LAB_004afac4:
                          puVar21 = *(ushort **)(unaff_EBP + -0x28);
                        }
                        else {
                          if (*(int *)(unaff_EBP + -0x1c) != 2) {
                            if (*(int *)(unaff_EBP + -0x1c) != 0) goto LAB_004afadf;
                            goto LAB_004afac4;
                          }
                          puVar21 = *(ushort **)(unaff_EBP + -0x54);
                        }
                        if ((puVar21 != (ushort *)0x0) && (*puVar21 != uVar19)) {
                          local_214 = 1.4013e-45;
                          uVar19 = FUN_004aeeb8();
                        }
                      }
                    }
LAB_004afadf:
                    iVar18 = *(int *)(unaff_EBP + -0x24);
                    *(undefined1 *)(unaff_EBP + -4) = 0x15;
                  }
                  uVar17 = (undefined2)(uVar19 >> 0x10);
                  if (*(int *)(unaff_EBP + -0x1c) == 4) {
                    sVar8 = *(short *)(unaff_EBP + -0x48);
                  }
                  else {
                    sVar8 = *(short *)(unaff_EBP + -0x48);
                  }
                  if (sVar8 == -5) {
                    local_214 = 6.885887e-39;
                    fVar28 = (float10)FUN_004689a1();
                    local_214 = (float)fVar28;
                    FUN_004b4722();
                    uVar17 = extraout_var_00;
                  }
                  uVar19 = DAT_006f0088;
                  iVar25 = CONCAT22(uVar17,*(short *)(iVar18 + 100) -
                                           ((ushort)*(byte *)(unaff_EBP + -0x3b) <<
                                           ((char)DAT_006f0088 + 1U & 0x1f))) +
                           *(int *)(unaff_EBP + 0x18);
                  sVar8 = DAT_006f0bc4;
                  *(int *)(unaff_EBP + -0x18) = iVar25;
                  puVar16 = (undefined2 *)(unaff_EBP + -0x18);
                  if (sVar8 <= (short)iVar25) {
                    puVar16 = &DAT_006f0bc4;
                  }
                  _DAT_006f0bc4 = CONCAT22(DAT_006f0bc6,*puVar16);
                  local_214 = (float)(unaff_EBP + -0xf8);
                  cVar7 = FUN_004a156c(*(undefined4 *)(unaff_EBP + 8),uVar19,unaff_EBP + -0xe0);
                  if (cVar7 != '\0') {
                    local_214 = 0.0;
                    FUN_004c828c(unaff_EBP + -0x1c4,unaff_EBP + -0x10,
                                 *(undefined4 *)(unaff_EBP + -0xf8),0,
                                 *(int *)(unaff_EBP + 0x14) - *(int *)(iVar18 + 0x5c),
                                 *(int *)(unaff_EBP + 0x18) -
                                 ((uint)*(byte *)(unaff_EBP + -0x3b) <<
                                 ((char)DAT_006f0088 + 1U & 0x1f)),0,
                                 *(undefined4 *)(unaff_EBP + 0x1c),unaff_EBP + -0x30,0,0,0);
                  }
                  _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0xdc);
                  _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0xd8);
                  goto LAB_004afbc6;
                }
              }
              else {
                if (((byte)*(undefined4 *)(unaff_EBP + -0x144) & 0x20) != 0x20) goto LAB_004b019c;
                uVar19 = (uint)*(ushort *)(unaff_EBP + -0x13c);
                *(uint *)(unaff_EBP + 8) = (uint)*(ushort *)(unaff_EBP + -0x130);
                if (uVar19 == 0) {
                  if (*(ushort *)(unaff_EBP + -0x130) == 0) {
                    uVar19 = *(uint *)(unaff_EBP + -0x60);
                    *(uint *)(unaff_EBP + 8) = uVar19;
                  }
                  if ((uVar19 == 0) && (*(int *)(unaff_EBP + 8) == 0)) goto LAB_004b019c;
                }
                *(undefined4 *)(unaff_EBP + -200) = _DAT_006f0bc0;
                *(undefined4 *)(unaff_EBP + -0xc4) = _DAT_006f0bc4;
                *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 0x14);
                local_214 = (float)(unaff_EBP + -0xd4);
                FUN_004672d0(unaff_EBP + -0x14,unaff_EBP + -0x2c,unaff_EBP + -0x50,unaff_EBP + -0x20
                            );
                iVar18 = DAT_006f008c;
                if (*(int *)(unaff_EBP + -0x20) == 0) {
                  iVar25 = 0;
                }
                else {
                  iVar25 = ((*(int *)(unaff_EBP + -0x20) - DAT_006f008c) - 1U & 3) + 1;
                }
                *(int *)(unaff_EBP + -0x20) = iVar25;
                if (*(int *)(unaff_EBP + -0xd4) == 0) {
                  iVar18 = 0;
                }
                else {
                  iVar18 = ((*(int *)(unaff_EBP + -0xd4) - iVar18) - 1U & 3) + 1;
                }
                *(int *)(unaff_EBP + -0xd4) = iVar18;
                if (uVar19 != 0) {
                  *(char *)(unaff_EBP + -0x34) = (char)*(undefined4 *)(unaff_EBP + -0x44);
                  *(char *)(unaff_EBP + -0x33) =
                       (char)((uint)*(undefined4 *)(unaff_EBP + -0x44) >> 8);
                  *(char *)(unaff_EBP + -0x32) = (char)*(undefined2 *)(unaff_EBP + -0x42);
                  *(char *)(unaff_EBP + -0x31) =
                       (char)((ushort)*(undefined2 *)(unaff_EBP + -0x42) >> 8);
                  *(undefined1 *)(unaff_EBP + -4) = 0x18;
                  if (*(int *)(unaff_EBP + -0x2c) != *(int *)(unaff_EBP + -0x50)) {
                    *(undefined1 *)(unaff_EBP + -0x8e) = 0;
                    *(undefined1 *)(unaff_EBP + -0x96) = 0;
                    local_214 = (float)(unaff_EBP + -0x10);
                    *(undefined1 *)(unaff_EBP + -4) = 0x1a;
                    iVar18 = FUN_004aee43(unaff_EBP + -0x90,unaff_EBP + -0x98);
                    if (0 < iVar18) {
                      *(undefined4 **)(unaff_EBP + -0x4c) = &local_214;
                      local_214._0_2_ =
                           CONCAT11(*(undefined1 *)(unaff_EBP + -0x8f),
                                    *(undefined1 *)(unaff_EBP + -0x90));
                      local_214._0_3_ =
                           CONCAT12(*(undefined1 *)(unaff_EBP + -0x8e),(undefined2)local_214);
                      local_214 = (float)CONCAT13(extraout_var_11,(undefined3)local_214);
                      uVar15 = FUN_00489b59();
                      if (*(int *)(unaff_EBP + -0x20) == 1) {
LAB_004afe53:
                        puVar21 = *(ushort **)(unaff_EBP + -0x2c);
LAB_004afe56:
                        uVar14 = 0;
                        if ((puVar21 != (ushort *)0x0) &&
                           (uVar14 = (uint)*puVar21, uVar14 != (uVar15 & 0xffff))) {
                          local_214 = 0.0;
                          FUN_004aeeb8();
                          uVar14 = extraout_ECX_06;
                        }
                      }
                      else {
                        if (*(int *)(unaff_EBP + -0x20) == 3) {
                          puVar21 = *(ushort **)(unaff_EBP + -0x50);
                          goto LAB_004afe56;
                        }
                        uVar14 = extraout_ECX_05;
                        if (*(int *)(unaff_EBP + -0x20) == 0) goto LAB_004afe53;
                      }
                      if (iVar18 == 2) {
                        *(undefined4 **)(unaff_EBP + -0x4c) = &local_214;
                        local_214._0_2_ =
                             CONCAT11(*(undefined1 *)(unaff_EBP + -0x97),
                                      *(undefined1 *)(unaff_EBP + -0x98));
                        local_214._3_1_ = (char)(uVar14 >> 0x18);
                        local_214._0_3_ =
                             CONCAT12(*(undefined1 *)(unaff_EBP + -0x96),(undefined2)local_214);
                        sVar8 = FUN_00489b59();
                        if (*(int *)(unaff_EBP + -0x20) == 1) {
LAB_004afeb4:
                          psVar23 = *(short **)(unaff_EBP + -0x2c);
                        }
                        else {
                          if (*(int *)(unaff_EBP + -0x20) != 3) {
                            if (*(int *)(unaff_EBP + -0x20) != 0) goto LAB_004afecb;
                            goto LAB_004afeb4;
                          }
                          psVar23 = *(short **)(unaff_EBP + -0x50);
                        }
                        if ((psVar23 != (short *)0x0) && (*psVar23 != sVar8)) {
                          local_214 = 1.4013e-45;
                          FUN_004aeeb8();
                        }
                      }
                    }
LAB_004afecb:
                    *(undefined1 *)(unaff_EBP + -4) = 0x18;
                  }
                  if (*(int *)(unaff_EBP + -0x20) == 1) {
                    sVar8 = *(short *)(unaff_EBP + -0x48);
                  }
                  else {
                    sVar8 = *(short *)(unaff_EBP + -0x48);
                  }
                  if (sVar8 == -5) {
                    local_214 = 6.887292e-39;
                    fVar28 = (float10)FUN_004689a1();
                    local_214 = (float)fVar28;
                    FUN_004b4722();
                  }
                  puVar16 = (undefined2 *)(unaff_EBP + -0x18);
                  if (DAT_006f0bc6 <= *(short *)(unaff_EBP + 0x14)) {
                    puVar16 = &DAT_006f0bc6;
                  }
                  _DAT_006f0bc4 = CONCAT22(*puVar16,DAT_006f0bc4);
                  local_214 = (float)(unaff_EBP + -0xfc);
                  cVar7 = FUN_004a156c(uVar19,DAT_006f0088,unaff_EBP + -0x100);
                  if (cVar7 != '\0') {
                    local_214 = 0.0;
                    FUN_004c828c(unaff_EBP + -0x174,unaff_EBP + -0x10,
                                 *(undefined4 *)(unaff_EBP + -0xfc),0,
                                 *(int *)(unaff_EBP + 0x14) -
                                 *(int *)(*(int *)(unaff_EBP + -0x24) + 0x5c),
                                 *(int *)(unaff_EBP + 0x18) -
                                 ((uint)*(byte *)(unaff_EBP + -0x3b) <<
                                 ((char)DAT_006f0088 + 1U & 0x1f)),0,
                                 *(undefined4 *)(unaff_EBP + 0x1c),unaff_EBP + -0x34,0,0,0);
                  }
                  _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -200);
                  *(undefined1 *)(unaff_EBP + -4) = 0x11;
                  _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0xc4);
                }
                if (*(int *)(unaff_EBP + 8) == 0) goto LAB_004afbcf;
                *(char *)(unaff_EBP + -0x38) = (char)*(undefined4 *)(unaff_EBP + -0x44);
                *(char *)(unaff_EBP + -0x37) = (char)((uint)*(undefined4 *)(unaff_EBP + -0x44) >> 8)
                ;
                *(char *)(unaff_EBP + -0x36) = (char)*(undefined2 *)(unaff_EBP + -0x42);
                *(char *)(unaff_EBP + -0x35) =
                     (char)((ushort)*(undefined2 *)(unaff_EBP + -0x42) >> 8);
                *(undefined1 *)(unaff_EBP + -4) = 0x1b;
                if (*(int *)(unaff_EBP + -0x2c) != *(int *)(unaff_EBP + -0x50)) {
                  *(undefined1 *)(unaff_EBP + -0x9e) = 0;
                  *(undefined1 *)(unaff_EBP + -0x8a) = 0;
                  local_214 = (float)(unaff_EBP + -0x10);
                  *(undefined1 *)(unaff_EBP + -4) = 0x1d;
                  iVar18 = FUN_004aee43(unaff_EBP + -0xa0,unaff_EBP + -0x8c);
                  if (0 < iVar18) {
                    *(undefined4 **)(unaff_EBP + -0x4c) = &local_214;
                    local_214._0_2_ =
                         CONCAT11(*(undefined1 *)(unaff_EBP + -0x9f),
                                  *(undefined1 *)(unaff_EBP + -0xa0));
                    local_214._0_3_ =
                         CONCAT12(*(undefined1 *)(unaff_EBP + -0x9e),(undefined2)local_214);
                    local_214 = (float)CONCAT13(extraout_var_12,(undefined3)local_214);
                    uVar19 = FUN_00489b59();
                    if (*(int *)(unaff_EBP + -0x20) == 1) {
                      puVar21 = *(ushort **)(unaff_EBP + -0x50);
LAB_004b0055:
                      uVar15 = 0;
                      if ((puVar21 != (ushort *)0x0) &&
                         (uVar15 = (uint)*puVar21, uVar15 != (uVar19 & 0xffff))) {
                        local_214 = 0.0;
                        FUN_004aeeb8();
                        uVar15 = extraout_ECX_08;
                      }
                    }
                    else if ((*(int *)(unaff_EBP + -0x20) == 3) ||
                            (uVar15 = extraout_ECX_07, *(int *)(unaff_EBP + -0x20) == 0)) {
                      puVar21 = *(ushort **)(unaff_EBP + -0x2c);
                      goto LAB_004b0055;
                    }
                    if (iVar18 == 2) {
                      *(undefined4 **)(unaff_EBP + -0x4c) = &local_214;
                      local_214._0_2_ =
                           CONCAT11(*(undefined1 *)(unaff_EBP + -0x8b),
                                    *(undefined1 *)(unaff_EBP + -0x8c));
                      local_214._3_1_ = (char)(uVar15 >> 0x18);
                      local_214._0_3_ =
                           CONCAT12(*(undefined1 *)(unaff_EBP + -0x8a),(undefined2)local_214);
                      sVar8 = FUN_00489b59();
                      if (*(int *)(unaff_EBP + -0x20) == 1) {
                        psVar23 = *(short **)(unaff_EBP + -0x50);
                      }
                      else {
                        if ((*(int *)(unaff_EBP + -0x20) != 3) && (*(int *)(unaff_EBP + -0x20) != 0)
                           ) goto LAB_004b00ca;
                        psVar23 = *(short **)(unaff_EBP + -0x2c);
                      }
                      if ((psVar23 != (short *)0x0) && (*psVar23 != sVar8)) {
                        local_214 = 1.4013e-45;
                        FUN_004aeeb8();
                      }
                    }
                  }
LAB_004b00ca:
                  *(undefined1 *)(unaff_EBP + -4) = 0x1b;
                }
                if (*(int *)(unaff_EBP + -0x20) == 3) {
                  sVar8 = *(short *)(unaff_EBP + -0x48);
                }
                else {
                  sVar8 = *(short *)(unaff_EBP + -0x48);
                }
                if (sVar8 == -5) {
                  local_214 = 6.888003e-39;
                  fVar28 = (float10)FUN_004689a1();
                  local_214 = (float)fVar28;
                  FUN_004b4722();
                }
                iVar18 = *(int *)(unaff_EBP + 0x14);
                puVar16 = (undefined2 *)(unaff_EBP + -0x18);
                if ((short)iVar18 <= DAT_006f0bc2) {
                  puVar16 = &DAT_006f0bc2;
                }
                _DAT_006f0bc0 = CONCAT22(*puVar16,DAT_006f0bc0);
                local_214 = (float)(unaff_EBP + -0xe8);
                cVar7 = FUN_004a156c(*(undefined4 *)(unaff_EBP + 8),DAT_006f0088,unaff_EBP + -0xec);
                if (cVar7 != '\0') {
                  local_214 = 0.0;
                  FUN_004c828c(unaff_EBP + -0x1e4,unaff_EBP + -0x10,
                               *(undefined4 *)(unaff_EBP + -0xe8),0,
                               iVar18 - *(int *)(*(int *)(unaff_EBP + -0x24) + 0x5c),
                               *(int *)(unaff_EBP + 0x18) -
                               ((uint)*(byte *)(unaff_EBP + -0x3b) <<
                               ((char)DAT_006f0088 + 1U & 0x1f)),0,*(undefined4 *)(unaff_EBP + 0x1c)
                               ,unaff_EBP + -0x38,0,0,0);
                }
                _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -200);
                _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0xc4);
LAB_004afbc6:
                *(undefined1 *)(unaff_EBP + -4) = 0x11;
              }
LAB_004afbcf:
              local_214 = *(float *)(unaff_EBP + -0x5c);
              FUN_004b4722();
            }
            *(undefined1 *)(unaff_EBP + -4) = 2;
          }
          if ('\0' < *(char *)(unaff_EBP + -0x14)) {
            iVar18 = *(int *)(DAT_006e54dc + 0x10) + -1;
            if (((*(char *)(unaff_EBP + -0x14) < iVar18) && ('\0' < *(char *)(unaff_EBP + -0x13)))
               && (*(char *)(unaff_EBP + -0x13) < iVar18)) {
              local_214 = (float)(unaff_EBP + -0x14);
              cVar7 = FUN_004790bc();
              if ((cVar7 == '\0') || (*(int *)(*(int *)(unaff_EBP + -0x24) + 0x4bc) != 0))
              goto LAB_004b021a;
              local_214 = -NAN;
              uVar9 = *(undefined4 *)(unaff_EBP + 0x1c);
              uVar30 = 1;
              uVar10 = FUN_00434d3d(unaff_EBP + -0x164);
              FUN_004b97eb(uVar10,uVar30,uVar9);
              local_214 = 6.886366e-39;
              iVar18 = FUN_004790b8();
              *(undefined1 *)(unaff_EBP + -0xb8) =
                   *(undefined1 *)
                    (*(int *)(*(int *)(iVar18 + 0x10) + *(char *)(unaff_EBP + -0x14) * 4) +
                    (int)*(char *)(unaff_EBP + -0x13));
              iVar18 = DAT_006e54d8;
              *(undefined1 *)(unaff_EBP + -4) = 0x1e;
              local_214 = *(float *)(iVar18 + 0x84);
              FUN_00461628();
              piVar4 = *(int **)(unaff_EBP + -0x24);
              bVar2 = *(byte *)(unaff_EBP + -0xb8);
              local_214 = 6.886473e-39;
              iVar13 = (**(code **)(*piVar4 + 0x14))();
              uVar9 = *(undefined4 *)(unaff_EBP + 0x1c);
              iVar25 = *(int *)(unaff_EBP + 0x14) - piVar4[0x17];
              iVar22 = (*(int *)(unaff_EBP + 0x18) -
                       ((uint)*(byte *)(unaff_EBP + -0x3b) << ((char)DAT_006f0088 + 1U & 0x1f))) -
                       (((DAT_006f0088 != 3) - 1 & 3) + 1);
              iVar18 = unaff_EBP + -0x194;
LAB_004b030d:
              iVar25 = iVar25 + -1;
              iVar13 = 3 - iVar13;
              iVar29 = bVar2 + 0x800;
              local_214 = 0.0;
              uVar10 = 0;
              FUN_004c656a(iVar18,iVar29,iVar13,iVar25,iVar22,0,uVar9);
              FUN_004c79d3(iVar18,iVar29,iVar13,iVar25,iVar22,uVar10,uVar9);
            }
            else {
LAB_004b021a:
              if (((('\0' < *(char *)(unaff_EBP + -0x14)) &&
                   ((iVar18 = *(int *)(DAT_006e54dc + 0x10) + -1,
                    *(char *)(unaff_EBP + -0x14) < iVar18 && ('\0' < *(char *)(unaff_EBP + -0x13))))
                   ) && (*(char *)(unaff_EBP + -0x13) < iVar18)) &&
                 (iVar18 = *(int *)(unaff_EBP + -0x24), *(int *)(iVar18 + 0x4bc) != 0)) {
                local_214 = -NAN;
                uVar9 = *(undefined4 *)(unaff_EBP + 0x1c);
                uVar30 = 1;
                uVar10 = FUN_00434d3d(unaff_EBP + -0x154);
                FUN_004b97eb(uVar10,uVar30,uVar9);
                cVar7 = *(char *)(*(int *)(*(int *)(*(int *)(iVar18 + 0x4bc) + 0x10) +
                                          *(char *)(unaff_EBP + -0x14) * 4) +
                                 (int)*(char *)(unaff_EBP + -0x13));
                *(char *)(unaff_EBP + -0xbc) = cVar7;
                *(undefined1 *)(unaff_EBP + -4) = 0x1f;
                if (cVar7 != -1) {
                  local_214 = *(float *)(DAT_006e54d8 + 0x84);
                  FUN_00461628();
                  piVar4 = *(int **)(unaff_EBP + -0x24);
                  bVar2 = *(byte *)(unaff_EBP + -0xbc);
                  local_214 = 6.888668e-39;
                  iVar13 = (**(code **)(*piVar4 + 0x14))();
                  uVar9 = *(undefined4 *)(unaff_EBP + 0x1c);
                  iVar25 = *(int *)(unaff_EBP + 0x14) - piVar4[0x17];
                  iVar22 = (*(int *)(unaff_EBP + 0x18) -
                           ((uint)*(byte *)(unaff_EBP + -0x3b) << ((char)DAT_006f0088 + 1U & 0x1f)))
                           - (((DAT_006f0088 != 3) - 1 & 3) + 1);
                  iVar18 = unaff_EBP + -0x1b4;
                  goto LAB_004b030d;
                }
              }
            }
          }
        }
        *(int *)(unaff_EBP + -0xb0) = *(int *)(unaff_EBP + -0xb0) + 1;
        cVar7 = *(char *)(unaff_EBP + -0x10) + **(char **)(unaff_EBP + 0x10);
        cVar6 = *(char *)(unaff_EBP + -0xf) + (*(char **)(unaff_EBP + 0x10))[1];
        *(undefined1 *)(unaff_EBP + -4) = 1;
        *(char *)(unaff_EBP + -0x10) = cVar7;
        *(char *)(unaff_EBP + -0xf) = cVar6;
        *(int *)(unaff_EBP + 0x14) =
             *(int *)(unaff_EBP + 0x14) + *(int *)(*(int *)(unaff_EBP + -0x24) + 0x58);
      } while (*(int *)(unaff_EBP + -0xb0) < *(int *)(unaff_EBP + 0xc));
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

