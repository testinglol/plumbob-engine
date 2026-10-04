
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053c3dc(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  short sVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined2 *puVar9;
  int iVar10;
  byte *pbVar11;
  undefined1 *puVar12;
  uint uVar13;
  int iVar14;
  byte bVar15;
  byte bVar16;
  undefined1 *extraout_ECX;
  int iVar17;
  int iVar18;
  char *pcVar19;
  int unaff_EBP;
  int *piVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  int iVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  
  FUN_00634c24();
  piVar20 = *(int **)(DAT_006e486c + 4);
  *(undefined4 *)(unaff_EBP + -0x24) = DAT_006f0ba8;
  iVar6 = *piVar20;
  *(int **)(unaff_EBP + -0x28) = piVar20;
  uVar5 = (**(code **)(iVar6 + 0x24))();
  uVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x30) = uVar5;
  uVar2 = extraout_ECX[1];
  *(undefined1 *)(unaff_EBP + -0x18) = uVar1;
  *(undefined1 *)(unaff_EBP + -0x17) = uVar2;
  *(undefined1 *)(unaff_EBP + -0x16) = extraout_ECX[2];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((char)piVar20[0x14] != '\0') {
    *(undefined1 **)(unaff_EBP + -0x50) = &stack0xffffff84;
    iVar6 = FUN_00488924();
    if (iVar6 == 0) goto LAB_0053cc0b;
  }
  iVar6 = *(int *)(unaff_EBP + 0xc);
  if (extraout_ECX[0x50] == '\0') {
    iVar14 = (**(code **)(**(int **)(unaff_EBP + -0x28) + 0x14))();
    *(undefined1 **)(unaff_EBP + -0x50) = &stack0xffffff84;
    puVar7 = (undefined4 *)FUN_004796d9();
    *(undefined4 *)(unaff_EBP + -0x2c) = *puVar7;
    FUN_004b3e97(unaff_EBP + -0x20);
    FUN_00434ffd();
  }
  else {
    *(undefined1 *)(unaff_EBP + -0x20) = 0;
    *(undefined1 *)(unaff_EBP + -0x1f) = 0;
    *(undefined1 *)(unaff_EBP + -0x1e) = 0;
    *(undefined1 *)(unaff_EBP + -0x1d) = 0;
    iVar14 = *(int *)(extraout_ECX + 0x54);
    *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(extraout_ECX + 0x58);
    *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(extraout_ECX + 0x5c);
    FUN_004b4bbd();
    FUN_004b463f(3);
    puVar7 = (undefined4 *)FUN_00434d3d();
    *(undefined4 *)(iVar6 + 0x50) = *puVar7;
    *(undefined4 *)(iVar6 + 0x54) = puVar7[1];
    iVar18 = *(int *)(extraout_ECX + 0x5c);
    *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(extraout_ECX + 0x58);
    *(int *)(iVar6 + 0x14) = (4 << ((byte)iVar14 & 0x1f)) + iVar18;
  }
  bVar15 = (byte)iVar14;
  *(int *)(unaff_EBP + -0x38) = 8 << (bVar15 & 0x1f);
  *(int *)(unaff_EBP + -0x4c) = 4 << (bVar15 & 0x1f);
  iVar6 = (int)(char)extraout_ECX[2];
  uVar5 = FUN_00434d3d(unaff_EBP + -0x58);
  FUN_004b469d(uVar5,iVar6);
  FUN_004b97eb(uVar5,iVar6);
  iVar6 = FUN_004670a4();
  if (iVar6 == 0) {
    FUN_004b475c();
  }
  else {
    FUN_004689a1();
    FUN_004b4722();
  }
  *(undefined1 *)(unaff_EBP + -0x1c) = 0;
  bVar16 = extraout_ECX[9];
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if ((bVar16 != 0) || (extraout_ECX[10] != '\0')) {
    *(int *)(unaff_EBP + -0x14) = (*(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x38)) + -1;
    iVar6 = (*(int *)(unaff_EBP + -0x34) -
            ((uint)*(byte *)(unaff_EBP + -0x2b) << (bVar15 + 1 & 0x1f))) -
            *(int *)(unaff_EBP + -0x4c);
    if (bVar16 != 0) {
      bVar16 = ~extraout_ECX[0xc] & ~extraout_ECX[0xb] & bVar16;
      *(byte *)(unaff_EBP + -0x1c) = bVar16;
      if (bVar16 != 0) {
        *(byte *)(unaff_EBP + -0xd) = bVar16;
        pbVar11 = (byte *)(unaff_EBP + -0xd);
        *pbVar11 = *pbVar11 & 0x10;
        if ((*pbVar11 == 0) && ((bVar16 & 0x40) == 0)) {
          iVar17 = iVar6 - *(int *)(*(int *)(unaff_EBP + -0x30) + (0x21 - iVar14) * 4);
          uVar30 = 0;
          uVar5 = *(undefined4 *)(unaff_EBP + -0x14);
          iVar8 = (byte)(&DAT_006cd440)[*(byte *)(unaff_EBP + -0x1c)] - 1;
          iVar25 = iVar14 + 0x17ff;
          iVar10 = iVar14 + 0x13ff;
          iVar18 = unaff_EBP + -0x78;
          FUN_004c656a(iVar18,iVar10,iVar25,iVar8,uVar5,iVar17,0);
          FUN_004c8c8c(iVar18,iVar10,iVar25,iVar8,uVar5,iVar17,uVar30);
        }
        else {
          iVar18 = 0;
          *(undefined4 *)(unaff_EBP + -0x3c) = 900;
          if (bVar16 == 0x10) {
            if (iVar14 == 3) {
              iVar18 = -5;
            }
            else if (iVar14 == 2) {
              iVar18 = -2;
            }
          }
          if ((bVar16 & 0x40) != 0) {
            *(uint *)(unaff_EBP + -0x3c) = ((extraout_ECX[2] != '\x02') - 1 & 0xffffffba) + 0x302;
          }
          piVar20 = (int *)(*(int *)(unaff_EBP + -0x30) + (0x21 - iVar14) * 4);
          uVar5 = *(undefined4 *)(unaff_EBP + 0xc);
          *(int **)(unaff_EBP + -0x44) = piVar20;
          iVar25 = *piVar20;
          *(uint *)(unaff_EBP + -0x48) = (uint)*(byte *)(unaff_EBP + -0x1c);
          uVar29 = 0;
          iVar10 = (iVar18 - iVar25) + iVar6;
          uVar30 = *(undefined4 *)(unaff_EBP + -0x14);
          iVar8 = (byte)(&DAT_006cd440)[*(byte *)(unaff_EBP + -0x1c)] - 1;
          iVar25 = iVar14 + 0xfff;
          iVar18 = unaff_EBP + -0x78;
          puVar12 = extraout_ECX;
          FUN_004c656a(iVar18,extraout_ECX,iVar25,iVar8,uVar30,iVar10,0,uVar5);
          FUN_004c89b6(iVar18,puVar12,iVar25,iVar8,uVar30,iVar10,uVar29,uVar5);
          if (*(char *)(unaff_EBP + -0xd) != '\0') {
            if ((*(byte *)(unaff_EBP + -0x1c) & 8) != 0) {
              *(undefined4 *)(unaff_EBP + -0x40) = _DAT_006f0bc0;
              *(undefined4 *)(unaff_EBP + -0x3c) = _DAT_006f0bc4;
              iVar18 = (8 << (bVar15 & 0x1f)) +
                       *(int *)(unaff_EBP + -0x14) + (8 >> (3 - bVar15 & 0x1f));
              sVar3 = DAT_006f0bc2;
              *(int *)(unaff_EBP + -0x50) = iVar18;
              puVar9 = (undefined2 *)(unaff_EBP + -0x50);
              if ((short)iVar18 <= sVar3) {
                puVar9 = &DAT_006f0bc2;
              }
              _DAT_006f0bc0 = CONCAT22(*puVar9,DAT_006f0bc0);
              iVar17 = iVar6 - **(int **)(unaff_EBP + -0x44);
              uVar30 = 0;
              uVar5 = *(undefined4 *)(unaff_EBP + -0x14);
              iVar8 = (byte)(&DAT_006cd440)[*(int *)(unaff_EBP + -0x48)] - 1;
              iVar25 = iVar14 + 0x17ff;
              iVar10 = iVar14 + 0x13ff;
              iVar18 = unaff_EBP + -0x78;
              FUN_004c656a(iVar18,iVar10,iVar25,iVar8,uVar5,iVar17,0);
              FUN_004c8c8c(iVar18,iVar10,iVar25,iVar8,uVar5,iVar17,uVar30);
              _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0x40);
              _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0x3c);
            }
            if ((*(byte *)(unaff_EBP + -0x1c) & 4) != 0) {
              *(undefined4 *)(unaff_EBP + -0x40) = _DAT_006f0bc0;
              *(undefined4 *)(unaff_EBP + -0x3c) = _DAT_006f0bc4;
              iVar18 = ((8 << (bVar15 & 0x1f)) - (8 >> (3 - bVar15 & 0x1f))) +
                       *(int *)(unaff_EBP + -0x14);
              sVar3 = DAT_006f0bc6;
              *(int *)(unaff_EBP + -0x50) = iVar18;
              puVar9 = (undefined2 *)(unaff_EBP + -0x50);
              if (sVar3 <= (short)iVar18) {
                puVar9 = &DAT_006f0bc6;
              }
              _DAT_006f0bc4 = CONCAT22(*puVar9,DAT_006f0bc4);
              iVar17 = iVar6 - **(int **)(unaff_EBP + -0x44);
              uVar30 = 0;
              uVar5 = *(undefined4 *)(unaff_EBP + -0x14);
              iVar8 = (byte)(&DAT_006cd440)[*(int *)(unaff_EBP + -0x48)] - 1;
              iVar25 = iVar14 + 0x17ff;
              iVar10 = iVar14 + 0x13ff;
              iVar18 = unaff_EBP + -0x78;
              FUN_004c656a(iVar18,iVar10,iVar25,iVar8,uVar5,iVar17,0);
              FUN_004c8c8c(iVar18,iVar10,iVar25,iVar8,uVar5,iVar17,uVar30);
              _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0x40);
              _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0x3c);
            }
          }
        }
      }
    }
    if (extraout_ECX[10] != 0) {
      bVar16 = ~extraout_ECX[0xc] & ~extraout_ECX[0xb] & extraout_ECX[10];
      *(byte *)(unaff_EBP + -0x1c) = bVar16;
      if (bVar16 != 0) {
        *(undefined4 *)(unaff_EBP + -0x48) = 0;
        if (((bVar16 & 0x40) != 0) && (extraout_ECX[2] == '\x02')) {
          *(undefined4 *)(unaff_EBP + -0x48) = 0xffffff9c;
        }
        uVar5 = *(undefined4 *)(unaff_EBP + 0xc);
        iVar6 = iVar6 - *(int *)(*(int *)(unaff_EBP + -0x30) + (0x1e - iVar14) * 4);
        uVar29 = 0;
        uVar30 = *(undefined4 *)(unaff_EBP + -0x14);
        iVar10 = (byte)(&DAT_006cd440)[bVar16] - 1;
        iVar25 = iVar14 + 0xfff;
        iVar18 = unaff_EBP + -0x78;
        puVar12 = extraout_ECX;
        FUN_004c656a(iVar18,extraout_ECX,iVar25,iVar10,uVar30,iVar6,0,uVar5);
        FUN_004c89b6(iVar18,puVar12,iVar25,iVar10,uVar30,iVar6,uVar29,uVar5);
      }
    }
  }
  cVar4 = extraout_ECX[0x24];
  *(undefined1 *)(unaff_EBP + -0x18) = *extraout_ECX;
  *(undefined1 *)(unaff_EBP + -0x17) = extraout_ECX[1];
  *(undefined1 *)(unaff_EBP + -0x16) = extraout_ECX[2];
  if (cVar4 == '\0') {
    if (extraout_ECX[0x25] == '\0') goto LAB_0053cc0b;
    pcVar19 = extraout_ECX + 0x3c;
  }
  else {
    pcVar19 = extraout_ECX + 0x28;
  }
  if (pcVar19 == (char *)0x0) goto LAB_0053cc0b;
  iVar6 = *(int *)(pcVar19 + 8);
  iVar18 = *(int *)(extraout_ECX + iVar6 * 4 + 0x10);
  if (extraout_ECX == *(undefined1 **)(iVar18 + 0x20)) {
    pbVar11 = *(byte **)(iVar18 + 0x30);
  }
  else {
    pbVar11 = (byte *)(*(int *)(iVar18 + 0x34) + -6);
  }
  bVar16 = *pbVar11;
  *(uint *)(unaff_EBP + -0x30) = (uint)*(ushort *)(pbVar11 + *(int *)(iVar18 + 0x18) * 2 + 2);
  *(uint *)(unaff_EBP + -0x3c) = (uint)(byte)extraout_ECX[0x25];
  if (((bVar16 & 1) != 0) && ((bVar16 & 6) != 0)) {
    if (iVar6 == 0) {
LAB_0053c8e6:
      bVar16 = bVar16 >> 2;
LAB_0053c8e9:
      *(uint *)(unaff_EBP + -0x3c) = bVar16 & 1;
    }
    else if (0 < iVar6) {
      if (iVar6 < 3) {
        bVar16 = bVar16 >> 1;
        goto LAB_0053c8e9;
      }
      if (iVar6 == 3) goto LAB_0053c8e6;
    }
  }
  iVar6 = *(int *)(pcVar19 + 4) << (bVar15 - 1 & 0x1f);
  cVar4 = pcVar19[0x10];
  *(undefined4 *)(unaff_EBP + -0x58) = _DAT_006f0bc0;
  *(undefined4 *)(unaff_EBP + -0x54) = _DAT_006f0bc4;
  if (cVar4 == '\0') {
    iVar18 = *(int *)(unaff_EBP + -0x20) - iVar6;
    iVar6 = *(int *)(unaff_EBP + -0x20);
  }
  else {
    iVar18 = *(int *)(unaff_EBP + -0x20) + -1;
    iVar6 = iVar6 + -1 + *(int *)(unaff_EBP + -0x20);
  }
  if (DAT_006f0bc2 < iVar18) {
    _DAT_006f0bc0 = CONCAT22((short)iVar18,DAT_006f0bc0);
  }
  if (iVar6 < DAT_006f0bc6) {
    _DAT_006f0bc4 = CONCAT22((short)iVar6,DAT_006f0bc4);
  }
  *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(pcVar19 + 0xc);
  FUN_00492d2c();
  FUN_004ac357(unaff_EBP + -0x68);
  puVar12 = (undefined1 *)FUN_0046185f();
  cVar4 = extraout_ECX[0x50];
  *(undefined1 *)(unaff_EBP + -0x18) = *puVar12;
  *(undefined1 *)(unaff_EBP + -0x17) = puVar12[1];
  *(undefined1 *)(unaff_EBP + -0x16) = puVar12[2];
  if (cVar4 == '\0') {
    FUN_004b3e97(unaff_EBP + -0x44);
    iVar6 = *(int *)(unaff_EBP + -0x48);
  }
  else {
    iVar6 = ((int)*pcVar19 + (int)pcVar19[1]) * *(int *)(unaff_EBP + -0x4c) +
            *(int *)(unaff_EBP + -0x34);
    *(int *)(unaff_EBP + -0x44) =
         ((int)*pcVar19 - (int)pcVar19[1]) * *(int *)(unaff_EBP + -0x38) +
         *(int *)(unaff_EBP + -0x20);
    *(int *)(unaff_EBP + -0x48) = iVar6;
  }
  *(undefined4 *)(unaff_EBP + -0x4c) = 0;
  if (*(int *)(pcVar19 + 0xc) == 2) {
    *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(unaff_EBP + -0x38);
  }
  OffsetRect((LPRECT)(unaff_EBP + -0x68),*(int *)(unaff_EBP + -0x44),
             iVar6 - ((uint)*(byte *)(unaff_EBP + -0x2b) << (bVar15 + 1 & 0x1f)));
  iVar18 = (int)DAT_006f0bc6;
  iVar6 = (int)DAT_006f0bc0;
  *(int *)(unaff_EBP + -0x6c) = (int)DAT_006f0bc4;
  *(int *)(unaff_EBP + -0x70) = iVar18;
  if (-1 < (int)((*(int *)(unaff_EBP + -0x60) - (int)DAT_006f0bc2) - 1U |
                 (*(int *)(unaff_EBP + -0x5c) - iVar6) - 1U |
                 (*(int *)(unaff_EBP + -0x70) - *(int *)(unaff_EBP + -0x68)) - 1U |
                (*(int *)(unaff_EBP + -0x6c) - *(int *)(unaff_EBP + -100)) - 1U)) {
    cVar4 = FUN_004a156c(*(undefined4 *)(unaff_EBP + -0x30),iVar14);
    if (cVar4 == '\0') {
      *(undefined4 *)(unaff_EBP + -0x50) = 0;
      *(int *)(unaff_EBP + -0x38) = iVar14 * 0x100 + 0x5ff;
    }
    iVar6 = *(int *)(extraout_ECX + *(int *)(pcVar19 + 8) * 4 + 0x10);
    if (extraout_ECX == *(undefined1 **)(iVar6 + 0x20)) {
      iVar6 = *(int *)(iVar6 + 0x30);
    }
    else {
      iVar6 = *(int *)(iVar6 + 0x34) + -6;
    }
    uVar13 = (uint)*(byte *)(iVar6 + 1);
    if (uVar13 != 0xff) {
      uVar13 = 1;
    }
    *(uint *)(unaff_EBP + -0x28) =
         ((*(int *)(unaff_EBP + -0x3c) != 0) - 0x200) + (iVar14 * 0x100 + uVar13) * 2;
    iVar6 = *(int *)(pcVar19 + 0xc);
    if (iVar6 == 1) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
    }
    else if (iVar6 == 2) {
      *(undefined4 *)(unaff_EBP + -0x14) = 2;
    }
    else if (iVar6 == 0x10) {
      *(undefined4 *)(unaff_EBP + -0x14) = 3;
    }
    else if (iVar6 == 0x20) {
      *(undefined4 *)(unaff_EBP + -0x14) = 4;
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x14) = 0xffffffff;
    }
    *(undefined1 *)(unaff_EBP + -0x30) = *(undefined1 *)(unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -0x2f) = *(undefined1 *)(unaff_EBP + -0x17);
    *(undefined1 *)(unaff_EBP + -0x2e) = *(undefined1 *)(unaff_EBP + -0x16);
    cVar4 = extraout_ECX[0x50];
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (cVar4 == '\0') {
      FUN_00434ffd();
    }
    iVar6 = (int)(char)extraout_ECX[2];
    uVar5 = FUN_00434d3d(unaff_EBP + -0x40);
    FUN_004b469d(uVar5,iVar6);
    FUN_004b97eb(uVar5,iVar6);
    iVar6 = *(int *)(pcVar19 + 8);
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    piVar20 = (int *)(extraout_ECX + 0x10);
    *(undefined4 *)(unaff_EBP + -0x3c) =
         *(undefined4 *)
          (*(int *)(extraout_ECX + iVar6 * 4 + 0x10) + 0x28 +
          *(int *)(*(int *)(extraout_ECX + iVar6 * 4 + 0x10) + 0x18) * 4);
    do {
      if ((*piVar20 != 0) && (iVar6 = FUN_0053c16a(), iVar6 == *(int *)(pcVar19 + 0xc))) {
        *(undefined4 *)(unaff_EBP + -0x3c) =
             *(undefined4 *)
              (*(int *)(extraout_ECX + *(int *)(unaff_EBP + -0x2c) * 4 + 0x10) + 0x28 +
              *(int *)(*(int *)(extraout_ECX + *(int *)(unaff_EBP + -0x2c) * 4 + 0x10) + 0x18) * 4);
        break;
      }
      *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 1;
      piVar20 = piVar20 + 1;
    } while (*(int *)(unaff_EBP + -0x2c) < 4);
    if (*(int *)(unaff_EBP + -0x3c) == 0) {
      FUN_004b475c();
    }
    else {
      FUN_004689a1();
      FUN_004b4722();
    }
    *(undefined1 **)(unaff_EBP + -0x3c) = &stack0xffffff80;
    FUN_00461b74(unaff_EBP + -0x18);
    FUN_004aef32(unaff_EBP + -0x3c);
    uVar5 = *(undefined4 *)(pcVar19 + 0xc);
    iVar14 = *(int *)(unaff_EBP + -0x14) + -1;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    uVar30 = *(undefined4 *)(unaff_EBP + -0x4c);
    uVar29 = *(undefined4 *)(unaff_EBP + 0xc);
    uVar28 = 0;
    uVar27 = *(undefined4 *)(unaff_EBP + -100);
    uVar26 = *(undefined4 *)(unaff_EBP + -0x68);
    iVar6 = unaff_EBP + -0x78;
    uVar24 = *(undefined4 *)(unaff_EBP + -0x38);
    uVar23 = *(undefined4 *)(unaff_EBP + -0x50);
    uVar22 = *(undefined4 *)(unaff_EBP + -0x28);
    uVar21 = 0;
    FUN_004c656a(iVar6,0,uVar22,uVar23,uVar24,iVar14,uVar26,uVar27,0,uVar29,uVar30,uVar5);
    FUN_004c7b37(iVar6,uVar21,uVar22,uVar23,uVar24,iVar14,uVar26,uVar27,uVar28,uVar29,uVar30,uVar5);
  }
  _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0x58);
  _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0x54);
LAB_0053cc0b:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

