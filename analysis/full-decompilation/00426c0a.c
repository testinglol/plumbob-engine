
undefined4 FUN_00426c0a(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined **ppuVar6;
  uint uVar7;
  uint uVar8;
  int extraout_ECX;
  int *piVar9;
  int unaff_EBP;
  undefined **ppuStack_5c8;
  undefined **ppuStack_5c4;
  undefined **ppuStack_5c0;
  DWORD DStack_5bc;
  
  FUN_00634c24();
  DStack_5bc = 0x426c25;
  DStack_5bc = timeGetTime();
  ppuStack_5c0 = (undefined **)0x426c30;
  FUN_005bc6cb();
  DStack_5bc = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(DAT_006e486c + 0x28);
  ppuStack_5c0 = (undefined **)0x426c45;
  puVar3 = (undefined4 *)FUN_0043acf5();
  *(undefined4 **)(unaff_EBP + -0x18) = puVar3;
  if (puVar3 != (undefined4 *)0x0) {
    DStack_5bc = 0x104;
    *(undefined4 *)(unaff_EBP + -0x10) = *puVar3;
    ppuStack_5c4 = (undefined **)(unaff_EBP + -0x128);
    ppuStack_5c0 = (undefined **)0x0;
    *(undefined4 *)(unaff_EBP + 8) = 0xffffffd5;
    ppuStack_5c8 = (undefined **)0x426c75;
    FUN_0046f824();
    *(undefined ***)(unaff_EBP + -0x134) = &PTR_FUN_006664e8;
    if (*(int *)(extraout_ECX + 0x160) < 32000) {
      do {
        if (*(int *)(unaff_EBP + 8) != -0x2b) break;
        ppuStack_5c0 = (undefined **)(unaff_EBP + -0x340);
        DStack_5bc = 0x100;
        ppuStack_5c4 = (undefined **)0x426cb2;
        FUN_0046fb9b();
        DStack_5bc = *(undefined4 *)(extraout_ECX + 0x160);
        *(undefined ***)(unaff_EBP + -0x34c) = &PTR_LAB_0066655c;
        ppuStack_5c0 = (undefined **)s_User_05d_006c2650;
        ppuStack_5c4 = *(undefined ***)(unaff_EBP + -0x348);
        ppuStack_5c8 = (undefined **)0x426cd2;
        FUN_00635858();
        ppuStack_5c4 = (undefined **)(unaff_EBP + -0x234);
        DStack_5bc = 0x100;
        ppuStack_5c0 = (undefined **)0x0;
        ppuStack_5c8 = (undefined **)0x426cea;
        FUN_0046f824();
        DStack_5bc = unaff_EBP + -0x34c;
        *(undefined ***)(unaff_EBP + -0x240) = &PTR_FUN_00666524;
        ppuStack_5c0 = (undefined **)0x426d06;
        FUN_0046f8e4();
        DStack_5bc = 0xffffffff;
        ppuStack_5c0 = (undefined **)&DAT_006c2648;
        ppuStack_5c4 = (undefined **)0x426d18;
        FUN_0046f847();
        DStack_5bc = unaff_EBP + -0x134;
        ppuStack_5c4 = (undefined **)0x426d25;
        FUN_00412122();
        DStack_5bc = 0xffffffff;
        ppuStack_5c0 = (undefined **)s_Characters__006c1d48;
        ppuStack_5c4 = (undefined **)0x426d39;
        FUN_0046f847();
        ppuStack_5c0 = (undefined **)(unaff_EBP + -0x240);
        DStack_5bc = 0xffffffff;
        ppuStack_5c4 = (undefined **)0x426d4d;
        FUN_0046f917();
        DStack_5bc = 0x100;
        ppuStack_5c4 = (undefined **)(unaff_EBP + -0x44c);
        ppuStack_5c0 = (undefined **)0x0;
        ppuStack_5c8 = (undefined **)0x426d62;
        FUN_0046f824();
        DStack_5bc = unaff_EBP + -0x34c;
        *(undefined ***)(unaff_EBP + -0x458) = &PTR_FUN_00666524;
        ppuStack_5c0 = (undefined **)0x426d7e;
        FUN_0046f8e4();
        DStack_5bc = 0x20;
        ppuStack_5c0 = (undefined **)0x426d8b;
        FUN_0046fa24();
        DStack_5bc = 0x426d96;
        FUN_0047234b();
        DStack_5bc = unaff_EBP + -0x458;
        ppuStack_5c0 = (undefined **)0x426da8;
        FUN_0047239b();
        DStack_5bc = unaff_EBP + -0x134;
        ppuStack_5c0 = *(undefined ***)(unaff_EBP + -0x10);
        ppuStack_5c4 = (undefined **)0x426dbd;
        uVar4 = FUN_004723b0();
        *(int *)(extraout_ECX + 0x160) = *(int *)(extraout_ECX + 0x160) + 1;
        iVar5 = *(int *)(extraout_ECX + 0x160);
        *(undefined4 *)(unaff_EBP + 8) = uVar4;
      } while (iVar5 < 32000);
      if (31999 < *(int *)(extraout_ECX + 0x160)) goto LAB_00426ddd;
    }
    else {
LAB_00426ddd:
      *(undefined4 *)(extraout_ECX + 0x160) = 0;
    }
    if (*(int *)(unaff_EBP + 8) == 0) {
      DStack_5bc = unaff_EBP + -0x134;
      ppuStack_5c0 = (undefined **)0x426dfd;
      FUN_0043c422();
      DStack_5bc = 0;
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      ppuStack_5c0 = (undefined **)0x426e0b;
      iVar5 = FUN_0043ad1f();
      if (iVar5 != 0) {
        do {
          if (*(short *)(*(int *)(iVar5 + 0x60) + 0x12) == 0x200) {
            piVar9 = *(int **)(extraout_ECX + 0x148);
            *(undefined4 *)(unaff_EBP + 8) = 0;
            piVar1 = *(int **)(extraout_ECX + 0x14c);
            if (piVar9 != piVar1) {
              do {
                iVar2 = *piVar9;
                if (((iVar2 != 0) && (*(int *)(iVar2 + 8) == iVar5)) &&
                   (*(int *)(unaff_EBP + 8) == 0)) {
                  *(int *)(unaff_EBP + 8) = iVar2;
                }
                piVar9 = piVar9 + 1;
              } while (piVar9 != piVar1);
              if (*(int *)(unaff_EBP + 8) != 0) goto LAB_00426e61;
            }
            if (*(int *)(unaff_EBP + -0x10) == 0) {
              DStack_5bc = 0xffffffff;
              ppuStack_5c4 = (undefined **)0x426e5e;
              ppuStack_5c0 = (undefined **)iVar5;
              uVar4 = FUN_004257ef();
              *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
            }
          }
LAB_00426e61:
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
          DStack_5bc = *(undefined4 *)(unaff_EBP + -0x14);
          ppuStack_5c0 = (undefined **)0x426e6e;
          iVar5 = FUN_0043ad1f();
        } while (iVar5 != 0);
        if (*(int *)(unaff_EBP + -0x10) != 0) {
          puVar3 = *(undefined4 **)(*(int *)(unaff_EBP + -0x10) + 8);
          if (puVar3 != (undefined4 *)0x0) {
            DStack_5bc = 0x426e98;
            (**(code **)(*(int *)*puVar3 + 0x10))();
            DStack_5bc = 0x426e9f;
            (**(code **)(*(int *)*puVar3 + 0x14))();
            *(undefined2 *)(puVar3[0x18] + 0x12) = 2;
            DStack_5bc = 0x426eaf;
            FUN_004574bb();
            DStack_5bc = 0x426eb4;
            FUN_004e8b76();
            if (*(short *)(*(int *)(*(int *)(unaff_EBP + -0x18) + 0x60) + 0x12) == 0x200) {
              DStack_5bc = 0x426ecd;
              DStack_5bc = FUN_0045741b();
              ppuStack_5c0 = (undefined **)0x426ed3;
              ppuVar6 = (undefined **)FUN_004e988f();
              ppuStack_5c0 = (undefined **)0x1;
              ppuStack_5c8 = (undefined **)0x426edd;
              ppuStack_5c4 = ppuVar6;
              FUN_004ea53c();
              ppuStack_5c8 = *(undefined ***)(unaff_EBP + 0xc);
              FUN_004eaa9b(ppuVar6);
              FUN_004eabf6(ppuVar6,*(undefined4 *)(unaff_EBP + 0x10));
              *(undefined ****)(unaff_EBP + 8) = &ppuStack_5c8;
              FUN_0040f4b7(unaff_EBP + 0x18);
              ppuStack_5c8 = &PTR_FUN_00666634;
              FUN_004eac8c(ppuVar6);
              uVar4 = FUN_004eacb7(ppuVar6);
              *(undefined4 *)(unaff_EBP + 8) = uVar4;
              uVar4 = FUN_004ead68(ppuVar6);
              *(undefined4 *)(unaff_EBP + 0x10) = 0;
              *(undefined4 *)(unaff_EBP + -0x10) = 0;
              *(undefined4 *)(unaff_EBP + 0xc) = uVar4;
              iVar5 = *(int *)(unaff_EBP + 8);
              if (0 < iVar5) {
                if (iVar5 < 1000) {
                  DStack_5bc = 1000;
                }
                else {
                  DStack_5bc = iVar5 * 2;
                }
                ppuStack_5c0 = (undefined **)0x426f4c;
                uVar7 = FUN_005bc722();
                *(uint *)(unaff_EBP + 0x10) = uVar7 % *(uint *)(unaff_EBP + 8);
              }
              iVar5 = *(int *)(unaff_EBP + 0xc);
              if (0 < iVar5) {
                if (iVar5 < 1000) {
                  DStack_5bc = 1000;
                }
                else {
                  DStack_5bc = iVar5 * 2;
                }
                ppuStack_5c0 = (undefined **)0x426f70;
                uVar7 = FUN_005bc722();
                *(uint *)(unaff_EBP + -0x10) = uVar7 % *(uint *)(unaff_EBP + 0xc);
              }
              DStack_5bc = *(undefined4 *)(unaff_EBP + 0x10);
              ppuStack_5c4 = (undefined **)0x426f81;
              ppuStack_5c0 = ppuVar6;
              FUN_004eacf0();
              ppuStack_5c4 = *(undefined ***)(unaff_EBP + -0x10);
              ppuStack_5c8 = ppuVar6;
              FUN_004eada1();
              FUN_004eadc1(ppuVar6);
              DStack_5bc = 1000;
              ppuStack_5c0 = (undefined **)0x426f9e;
              uVar7 = FUN_005bc722();
              DStack_5bc = 0xffffffff;
              ppuStack_5c0 = (undefined **)0x426faa;
              uVar8 = FUN_0046fbe5();
              DStack_5bc = 0xffffffff;
              iVar5 = uVar7 % uVar8 + 1;
              ppuStack_5c4 = (undefined **)0x426fc0;
              ppuStack_5c0 = (undefined **)iVar5;
              DStack_5bc = FUN_004705f2();
              ppuStack_5c0 = (undefined **)0x426fc9;
              FUN_005b870f();
              *(undefined4 *)(unaff_EBP + -4) = 0;
              DStack_5bc = unaff_EBP + -0x24;
              ppuStack_5c4 = (undefined **)0x426fd7;
              ppuStack_5c0 = ppuVar6;
              FUN_004e9a99();
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
              DStack_5bc = 0x426fe5;
              FUN_005b8770();
              DStack_5bc = 0xffffffff;
              ppuStack_5c4 = (undefined **)0x426ff0;
              ppuStack_5c0 = (undefined **)iVar5;
              FUN_0047053c();
              DStack_5bc = 0;
              ppuStack_5c0 = (undefined **)0x1;
              ppuStack_5c4 = (undefined **)0x1;
              ppuStack_5c8 = ppuVar6;
              FUN_004ea674();
            }
            DStack_5bc = 0x427006;
            uVar4 = FUN_0045741b();
            goto LAB_00427006;
          }
          goto LAB_00426e8a;
        }
      }
      uVar4 = 0xffffffff;
      goto LAB_00427006;
    }
  }
LAB_00426e8a:
  uVar4 = 0;
LAB_00427006:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

