
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ad0c7(void)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar9;
  int iVar10;
  bool bVar11;
  
  FUN_00634c24();
  bVar11 = DAT_006e4870 == '\0';
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff90;
  uVar7 = (uint)bVar11;
  *(int **)(unaff_EBP + -0x30) = extraout_ECX;
  *(uint *)(unaff_EBP + -0x1c) = uVar7;
  if (*(int *)(unaff_EBP + 0xc) == 0) {
    if ((((extraout_ECX[0x23] - extraout_ECX[0x22] & 0xfffffff0U) == 0) ||
        (extraout_ECX[uVar7 + 0x1c] == 0)) || (*(int *)(extraout_ECX[uVar7 + 0x1c] + 0x5c) == 0))
    goto LAB_004ad68a;
    FUN_005cce4d(extraout_ECX + 10);
  }
  FUN_004ad69b();
  *(undefined1 *)(unaff_EBP + -0x11) = 0;
  if ((char)extraout_ECX[0x1e] == '\0') {
    *(undefined1 *)(unaff_EBP + -0x11) = 1;
    FUN_004b038a(extraout_ECX[uVar7 + 0x1c],*(undefined4 *)(unaff_EBP + 8));
    if ((char)extraout_ECX[0x1e] != '\0') {
      extraout_ECX[0x1f] = uVar7;
    }
  }
  if ((DAT_006c723d != '\0') && (DAT_006f0095 == '\0')) {
    if ((char)extraout_ECX[0x14] == '\0') {
      if ((DAT_006f007c & 1) == 0) {
        DAT_006f007c = DAT_006f007c | 1;
        DAT_006f0070 = 0;
        DAT_006f0074 = 0;
        _DAT_006f0078 = 0;
        FUN_00635543(&LAB_004ad6c2);
      }
      FUN_004b4015(DAT_006f0070,DAT_006f0074);
      iVar10 = extraout_ECX[0x141];
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      if (0 < (int)(iVar10 - extraout_ECX[0x140] & 0xfffffff0U)) {
        *(undefined4 *)(unaff_EBP + -0x2c) = 0;
        do {
          iVar8 = DAT_006f0084;
          puVar9 = (undefined4 *)(*(int *)(unaff_EBP + -0x2c) + extraout_ECX[0x140]);
          *(undefined4 *)(unaff_EBP + -0x40) = *puVar9;
          iVar10 = DAT_006f0080;
          *(undefined4 *)(unaff_EBP + -0x3c) = puVar9[1];
          *(undefined4 *)(unaff_EBP + -0x38) = puVar9[2];
          *(undefined4 *)(unaff_EBP + -0x34) = puVar9[3];
          OffsetRect((LPRECT)(unaff_EBP + -0x40),iVar10,iVar8);
          FUN_004a7901();
          if ((*(int *)(unaff_EBP + -0x40) < *(int *)(unaff_EBP + -0x38)) &&
             (*(int *)(unaff_EBP + -0x3c) < *(int *)(unaff_EBP + -0x34))) {
            iVar10 = extraout_ECX[0x23];
            *(undefined4 *)(unaff_EBP + -0x28) = 0;
            iVar8 = extraout_ECX[0x22];
            if (0 < (int)(iVar10 - iVar8 & 0xfffffff0U)) {
              *(undefined4 *)(unaff_EBP + -0x20) = 0;
              do {
                puVar9 = (undefined4 *)(*(int *)(unaff_EBP + -0x20) + iVar8);
                *(undefined4 *)(unaff_EBP + -0x60) = *puVar9;
                *(undefined4 *)(unaff_EBP + -0x5c) = puVar9[1];
                *(undefined4 *)(unaff_EBP + -0x58) = puVar9[2];
                *(undefined4 *)(unaff_EBP + -0x54) = puVar9[3];
                if (-1 < (int)((*(int *)(unaff_EBP + -0x34) - *(int *)(unaff_EBP + -0x5c)) - 1U |
                               (*(int *)(unaff_EBP + -0x38) - *(int *)(unaff_EBP + -0x60)) - 1U |
                               (*(int *)(unaff_EBP + -0x54) - *(int *)(unaff_EBP + -0x3c)) - 1U |
                              (*(int *)(unaff_EBP + -0x58) - *(int *)(unaff_EBP + -0x40)) - 1U)) {
                  *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(unaff_EBP + -0x40);
                  *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(unaff_EBP + -0x3c);
                  *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x38);
                  *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + -0x34);
                  FUN_004a7901();
                  if ((*(int *)(unaff_EBP + -0x50) < *(int *)(unaff_EBP + -0x48)) &&
                     (*(int *)(unaff_EBP + -0x4c) < *(int *)(unaff_EBP + -0x44))) {
                    FUN_004b3fea(unaff_EBP + -0x50);
                  }
                }
                iVar10 = extraout_ECX[0x23];
                *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 1;
                *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 0x10;
                iVar8 = extraout_ECX[0x22];
              } while (*(int *)(unaff_EBP + -0x28) < iVar10 - iVar8 >> 4);
            }
          }
          iVar10 = extraout_ECX[0x141];
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
          iVar8 = extraout_ECX[0x140];
          *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 0x10;
        } while (*(int *)(unaff_EBP + -0x18) < iVar10 - iVar8 >> 4);
        uVar7 = *(uint *)(unaff_EBP + -0x1c);
      }
      iVar8 = DAT_006f0074;
      iVar10 = DAT_006f0070;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      if (iVar8 - iVar10 >> 4 != 0) {
        *(undefined4 *)(unaff_EBP + -0x2c) = 0;
        do {
          puVar9 = (undefined4 *)(*(int *)(unaff_EBP + -0x2c) + iVar10);
          *(undefined4 *)(unaff_EBP + -0x70) = *puVar9;
          *(undefined4 *)(unaff_EBP + -0x6c) = puVar9[1];
          *(undefined4 *)(unaff_EBP + -0x68) = puVar9[2];
          *(undefined4 *)(unaff_EBP + -100) = puVar9[3];
          cVar6 = FUN_004b465e();
          if (cVar6 != '\0') {
            FUN_004aac36(unaff_EBP + -0x70,*(undefined4 *)(unaff_EBP + -0x1c));
          }
          cVar6 = FUN_004b4665();
          if (cVar6 != '\0') {
            FUN_004aaca7(unaff_EBP + -0x70,*(undefined4 *)(unaff_EBP + -0x1c));
          }
          iVar8 = DAT_006f0074;
          iVar10 = DAT_006f0070;
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
          *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 0x10;
        } while (*(uint *)(unaff_EBP + -0x18) < (uint)(iVar8 - iVar10 >> 4));
        uVar7 = *(uint *)(unaff_EBP + -0x1c);
      }
    }
    else {
      cVar6 = FUN_004b465e();
      if (cVar6 != '\0') {
        FUN_004aac36(extraout_ECX + 10,uVar7);
      }
      cVar6 = FUN_004b4665();
      if (cVar6 != '\0') {
        FUN_004aaca7(extraout_ECX + 10,uVar7);
      }
    }
  }
  if (DAT_006c7241 != '\0') {
    iVar10 = extraout_ECX[0x22];
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(int *)(unaff_EBP + -0x18) = iVar10;
    while ((*(int *)(unaff_EBP + -0x18) != extraout_ECX[0x23] || (*(int *)(unaff_EBP + 0xc) != 0)))
    {
      if (*(int *)(unaff_EBP + 0xc) == 0) {
        puVar9 = *(undefined4 **)(unaff_EBP + -0x18);
        *(undefined2 *)(unaff_EBP + -0x24) = *(undefined2 *)(puVar9 + 1);
        *(undefined2 *)(unaff_EBP + -0x20) = *(undefined2 *)(puVar9 + 3);
        *(undefined2 *)(unaff_EBP + -0x22) = *(undefined2 *)puVar9;
        *(undefined2 *)(unaff_EBP + -0x1e) = *(undefined2 *)(puVar9 + 2);
        _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0x24);
        _DAT_006f0bc4 = *(int *)(unaff_EBP + -0x20);
      }
      else {
        psVar2 = *(short **)(unaff_EBP + 0xc);
        puVar9 = (undefined4 *)(unaff_EBP + -0x60);
        _DAT_006f0bc0 = *(undefined4 *)psVar2;
        _DAT_006f0bc4 = *(int *)(psVar2 + 2);
        *(int *)(unaff_EBP + -0x5c) = (int)*psVar2;
        *(int *)(unaff_EBP + -0x54) = (int)psVar2[2];
        sVar1 = psVar2[3];
        *(int *)(unaff_EBP + -0x60) = (int)psVar2[1];
        *(int *)(unaff_EBP + -0x58) = (int)sVar1;
      }
      bVar11 = DAT_006f0095 != '\0';
      *(undefined4 *)(unaff_EBP + -0x50) = *puVar9;
      *(undefined4 *)(unaff_EBP + -0x4c) = puVar9[1];
      *(undefined4 *)(unaff_EBP + -0x48) = puVar9[2];
      *(undefined4 *)(unaff_EBP + -0x44) = puVar9[3];
      if ((bVar11) && (DAT_006c723d != '\0')) {
        cVar6 = FUN_004b465e();
        if (cVar6 != '\0') {
          FUN_004aac36(unaff_EBP + -0x50,*(undefined4 *)(unaff_EBP + -0x1c));
        }
        cVar6 = FUN_004b4665();
        if (cVar6 != '\0') {
          FUN_004aaca7(unaff_EBP + -0x50,*(undefined4 *)(unaff_EBP + -0x1c));
        }
      }
      *(int *)(unaff_EBP + -0x28) = extraout_ECX[6];
      FUN_004ad6cc(&DAT_006f0bc0,1,1,1,*(undefined4 *)(unaff_EBP + 8));
      for (iVar10 = 1; *(int *)(unaff_EBP + -0x2c) = iVar10, iVar10 <= *(int *)(unaff_EBP + -0x28);
          iVar10 = iVar10 + 1) {
        if (DAT_006c723c != '\0') {
          if (*(int *)(unaff_EBP + 0xc) == 0) {
            iVar8 = *(int *)(unaff_EBP + -0x18);
          }
          else {
            iVar8 = unaff_EBP + -0x50;
          }
          FUN_00540610(iVar8,iVar10,*(undefined4 *)(unaff_EBP + 8));
        }
        if (*(int *)(unaff_EBP + 0xc) == 0) {
          puVar9 = *(undefined4 **)(unaff_EBP + -0x18);
          *(undefined2 *)(unaff_EBP + -0x38) = *(undefined2 *)(puVar9 + 1);
          *(undefined2 *)(unaff_EBP + -0x34) = *(undefined2 *)(puVar9 + 3);
          *(undefined2 *)(unaff_EBP + -0x36) = *(undefined2 *)puVar9;
          *(undefined2 *)(unaff_EBP + -0x32) = *(undefined2 *)(puVar9 + 2);
          _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0x38);
          iVar8 = *(int *)(unaff_EBP + -0x34);
          _DAT_006f0bc4 = iVar8;
        }
        else {
          psVar2 = *(short **)(unaff_EBP + 0xc);
          puVar9 = (undefined4 *)(unaff_EBP + -0x70);
          _DAT_006f0bc0 = *(undefined4 *)psVar2;
          _DAT_006f0bc4 = *(int *)(psVar2 + 2);
          *(int *)(unaff_EBP + -0x6c) = (int)*psVar2;
          *(int *)(unaff_EBP + -100) = (int)psVar2[2];
          iVar8 = (int)psVar2[3];
          *(int *)(unaff_EBP + -0x70) = (int)psVar2[1];
          *(int *)(unaff_EBP + -0x68) = iVar8;
        }
        *(undefined4 *)(unaff_EBP + -0x50) = *puVar9;
        *(undefined4 *)(unaff_EBP + -0x4c) = puVar9[1];
        *(undefined4 *)(unaff_EBP + -0x48) = puVar9[2];
        *(undefined4 *)(unaff_EBP + -0x44) = puVar9[3];
        iVar10 = *(int *)(unaff_EBP + -0x2c);
        FUN_004ad6cc(&DAT_006f0bc0,iVar10,
                     CONCAT31((int3)((uint)iVar8 >> 8),iVar10 < *(int *)(unaff_EBP + -0x28)),0,
                     *(undefined4 *)(unaff_EBP + 8));
      }
      if (*(int *)(unaff_EBP + 0xc) != 0) break;
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 0x10;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    uVar7 = *(uint *)(unaff_EBP + -0x1c);
  }
  if (*(char *)(unaff_EBP + -0x11) != '\0') {
    FUN_004b048c(*(undefined4 *)(unaff_EBP + 8));
  }
  if (*(char *)((int)extraout_ECX + 0x51) != '\0') {
    iVar10 = extraout_ECX[0x1a];
    iVar8 = extraout_ECX[uVar7 + 0x1c];
    iVar3 = extraout_ECX[0x21];
    *(undefined1 *)(unaff_EBP + 0xf) = 0;
    uVar4 = *(undefined4 *)(iVar10 + 0x10);
    uVar5 = *(undefined4 *)(iVar10 + 0x14);
    *(int *)(unaff_EBP + -0x30) = iVar3;
    *(undefined4 *)(unaff_EBP + -0x34) = uVar5;
    if (iVar8 != iVar3) {
      cVar6 = FUN_004b0db9(iVar8);
      if (cVar6 == '\0') goto LAB_004ad68a;
      *(undefined1 *)(unaff_EBP + 0xf) = 1;
      FUN_005cf06d(uVar4,*(undefined4 *)(unaff_EBP + -0x34));
      FUN_004a7d36();
    }
    cVar6 = FUN_004b465e();
    if (cVar6 != '\0') {
      cVar6 = FUN_004b4665();
      if (cVar6 != '\0') {
        iVar10 = FUN_005ce621(1);
        if (-1 < iVar10) {
          iVar8 = 0;
          iVar10 = (**(code **)(*extraout_ECX + 0x38))();
          if (0 < iVar10) {
            do {
              iVar10 = FUN_00479149(iVar8);
              if (iVar10 != 0) {
                FUN_0056eb75(extraout_ECX[0x1a],iVar8 + 1,0,0);
              }
              iVar8 = iVar8 + 1;
              iVar10 = (**(code **)(*extraout_ECX + 0x38))();
            } while (iVar8 < iVar10);
          }
          FUN_005ce67e();
        }
      }
    }
    if (*(char *)(unaff_EBP + 0xf) != '\0') {
      FUN_004b0db9(*(undefined4 *)(unaff_EBP + -0x30));
      FUN_005cf06d(uVar4,*(undefined4 *)(unaff_EBP + -0x34));
      FUN_004a7d36();
    }
  }
LAB_004ad68a:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

