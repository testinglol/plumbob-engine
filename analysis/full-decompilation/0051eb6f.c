
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0051eb6f(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  code *pcVar10;
  int extraout_ECX;
  int unaff_EBP;
  int iVar11;
  code *local_64;
  
  FUN_00634c24();
  iVar11 = *(int *)(extraout_ECX + 0x468);
  *(int *)(unaff_EBP + -0x18) = extraout_ECX;
  if (iVar11 == 0) {
    local_64 = (code *)0x51eb98;
    puVar5 = operator_new(0x5c);
    *(undefined4 **)(unaff_EBP + -0x14) = puVar5;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (puVar5 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      puVar6 = puVar5 + 1;
      local_64 = FUN_005c1719;
      *puVar5 = 0x16;
      FUN_00635e55(puVar6,4,0x16);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(extraout_ECX + 0x46c) = 0x16;
    *(undefined4 **)(extraout_ECX + 0x468) = puVar6;
    iVar11 = 0;
    do {
      FUN_005c1719();
      *(undefined4 *)(unaff_EBP + -4) = 1;
      local_64 = (code *)0x51ebfe;
      FUN_005a5e1c();
      cVar4 = FUN_005a5e72();
      if (cVar4 != '\0') {
        iVar7 = FUN_004096c2();
        *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(iVar7 + 0x14);
        *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(iVar7 + 0x18);
        iVar8 = *(int *)(iVar7 + 0x1c);
        *(int *)(unaff_EBP + -0x24) = iVar8;
        iVar7 = *(int *)(iVar7 + 0x20);
        *(int *)(unaff_EBP + -0x24) = iVar8 / 4;
        *(int *)(unaff_EBP + -0x20) = iVar7 / 0x16;
        iVar8 = (*(int *)(unaff_EBP + -0x24) - *(int *)(unaff_EBP + -0x2c)) * 2;
        *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + iVar8;
        *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + iVar8;
        iVar8 = (*(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x28)) * iVar11;
        *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + iVar8;
        *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + iVar8;
        local_64 = (code *)(unaff_EBP + -0x2c);
        uVar9 = FUN_004096c2();
        FUN_004ba969(_DAT_0066743c,uVar9);
        local_64 = (code *)0x51ec90;
        FUN_005a5e48();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005a5e09();
      iVar11 = iVar11 + 1;
    } while (iVar11 < *(int *)(extraout_ECX + 0x46c));
  }
  local_64 = (code *)(extraout_ECX + 0x470);
  if (*(int *)(extraout_ECX + 0x470) == 0) {
    FUN_005a5631(0x132c);
  }
  iVar11 = *(int *)(extraout_ECX + 0xf4);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  piVar1 = (int *)(extraout_ECX + 0xf0);
  iVar8 = extraout_ECX;
  if (iVar11 - *(int *)(extraout_ECX + 0xf0) >> 2 != 0) {
    do {
      local_64 = (code *)0x51ecef;
      pcVar10 = (code *)FUN_004e9918();
      if (pcVar10 == (code *)0xffffffff) break;
      local_64 = (code *)0x51ed01;
      FUN_004e9744();
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      local_64 = pcVar10;
      cVar4 = FUN_004ea8c8();
      if (cVar4 == '\0') {
        local_64 = (code *)0x51ee52;
        cVar4 = FUN_004ea8e8();
        if (cVar4 == '\0') {
          local_64 = (code *)0x51ef44;
          iVar11 = FUN_004e9744();
          if (DAT_006f6b5c == iVar11) {
            *(code ***)(unaff_EBP + -0x1c) = &local_64;
            uVar9 = *(undefined4 *)(iVar8 + 0x318);
          }
          else {
            *(code ***)(unaff_EBP + -0x1c) = &local_64;
            uVar9 = 0;
          }
          local_64 = (code *)0x0;
          FUN_005938bb(*(undefined4 *)(unaff_EBP + -0x10));
          FUN_005e4fb5(uVar9);
        }
        else {
          iVar11 = *(int *)(iVar8 + 0x470);
          *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(iVar11 + 0x14);
          *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(iVar11 + 0x18);
          *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(iVar11 + 0x1c);
          *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(iVar11 + 0x20);
          iVar8 = *(int *)(*piVar1 + *(int *)(unaff_EBP + -0x10) * 4);
          iVar7 = *(int *)(iVar8 + 0xd8);
          *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(iVar7 + 0x14);
          *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(iVar7 + 0x18);
          iVar2 = *(int *)(iVar7 + 0x1c);
          iVar3 = *(int *)(iVar8 + 0xf0);
          *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(iVar7 + 0x20);
          iVar7 = *(int *)(unaff_EBP + -0x3c);
          local_64 = (code *)(((iVar2 / iVar3 - *(int *)(unaff_EBP + -0x34)) -
                              *(int *)(unaff_EBP + -0x4c)) + iVar7 + -1);
          *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) / *(int *)(iVar8 + 0xec);
          if (iVar11 != 0) {
            *(code ***)(unaff_EBP + -0x1c) = &local_64;
            iVar8 = *(int *)(unaff_EBP + -0x10);
            FUN_005938bb(iVar8);
            FUN_005e4fb5(iVar11);
            iVar11 = *(int *)(*piVar1 + iVar8 * 4);
            *(undefined4 *)(iVar11 + 0x138) = *(undefined4 *)(unaff_EBP + -0x38);
            *(undefined4 *)(iVar11 + 0x13c) = *(undefined4 *)(unaff_EBP + -0x34);
            uVar9 = *(undefined4 *)(unaff_EBP + -0x30);
            *(int *)(iVar11 + 0x134) = iVar7;
            *(undefined4 *)(iVar11 + 0x140) = uVar9;
          }
          iVar8 = *(int *)(unaff_EBP + -0x18);
        }
      }
      else {
        iVar11 = FUN_004096c2();
        *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(iVar11 + 0x14);
        *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(iVar11 + 0x18);
        uVar9 = *(undefined4 *)(iVar11 + 0x20);
        *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(iVar11 + 0x1c);
        *(undefined4 *)(unaff_EBP + -0x20) = uVar9;
        local_64 = (code *)0x51ed41;
        iVar11 = FUN_004eaa44();
        if (iVar11 == 1) {
LAB_0051ed50:
          uVar9 = FUN_004096c2();
          *(undefined4 *)(unaff_EBP + -0x14) = uVar9;
        }
        else {
          local_64 = (code *)0x51ed60;
          iVar11 = FUN_004ea83d();
          if (iVar11 != 0) {
            iVar11 = FUN_004096c2();
            if ((-1 < iVar11) && (iVar11 = FUN_004096c2(), iVar11 < *(int *)(iVar8 + 0x46c))) {
              FUN_004096c2();
              goto LAB_0051ed50;
            }
            iVar11 = FUN_004096c2();
            if (iVar11 == -1) goto LAB_0051ef1b;
          }
        }
        iVar11 = *(int *)(*piVar1 + *(int *)(unaff_EBP + -0x10) * 4);
        iVar7 = *(int *)(iVar11 + 0xd8);
        *(undefined4 *)(unaff_EBP + -0x5c) = *(undefined4 *)(iVar7 + 0x14);
        *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(iVar7 + 0x18);
        iVar2 = *(int *)(iVar7 + 0x1c);
        iVar11 = *(int *)(iVar11 + 0xf0);
        *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(iVar7 + 0x20);
        local_64 = (code *)(((iVar2 / iVar11 - *(int *)(unaff_EBP + -0x24)) -
                            *(int *)(unaff_EBP + -0x5c)) + *(int *)(unaff_EBP + -0x2c) + -4);
        if (*(int *)(unaff_EBP + -0x14) != 0) {
          iVar11 = *(int *)(unaff_EBP + -0x10);
          *(code ***)(unaff_EBP + -0x1c) = &local_64;
          uVar9 = *(undefined4 *)(unaff_EBP + -0x14);
          FUN_005938bb(iVar11);
          FUN_005e4fb5(uVar9);
          iVar11 = *(int *)(*piVar1 + iVar11 * 4);
          *(undefined4 *)(iVar11 + 0x134) = *(undefined4 *)(unaff_EBP + -0x2c);
          *(undefined4 *)(iVar11 + 0x138) = *(undefined4 *)(unaff_EBP + -0x28);
          *(undefined4 *)(iVar11 + 0x13c) = *(undefined4 *)(unaff_EBP + -0x24);
          *(undefined4 *)(iVar11 + 0x140) = *(undefined4 *)(unaff_EBP + -0x20);
        }
      }
LAB_0051ef1b:
      iVar11 = *(int *)(extraout_ECX + 0xf4);
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(uint *)(unaff_EBP + -0x10) < (uint)(iVar11 - *piVar1 >> 2));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

