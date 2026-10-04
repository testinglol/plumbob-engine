
undefined4 FUN_0059ef12(void)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x28) = extraout_ECX;
  FUN_005b903c(0x1000,0);
  cVar1 = FUN_005b9095(unaff_EBP + -0x18);
  if (cVar1 == '\0') {
    uVar6 = **(undefined4 **)(unaff_EBP + 0xc);
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    if (0 < *(int *)(unaff_EBP + -0x18)) {
      do {
        pvVar2 = operator_new(0xd4);
        *(void **)(unaff_EBP + -0x14) = pvVar2;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar2 == (void *)0x0) {
          iVar3 = 0;
        }
        else {
          iVar3 = FUN_00598f28();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005954bc();
        cVar1 = FUN_00598aff(*(undefined4 *)(unaff_EBP + 0x10));
        if (cVar1 == '\0') {
          FUN_004f6cef(**(undefined4 **)(unaff_EBP + 0xc));
          uVar6 = 0xffffffff;
          goto LAB_0059f416;
        }
        uVar6 = FUN_005a1f21(iVar3 + 4);
        *(undefined4 *)(unaff_EBP + -4) = 1;
        FUN_005a242b(unaff_EBP + -0x34,uVar6);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_0059ee43();
        if (*(int *)(unaff_EBP + -0x34) == 0) {
          FUN_0042004f();
          uVar6 = FUN_005a1f88(iVar3,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc)
                               ,*(undefined4 *)(unaff_EBP + 0x14));
          *(undefined4 *)(unaff_EBP + -4) = 2;
          FUN_005a1cbf(unaff_EBP + -0x40,uVar6);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_0059ee43();
        }
        else if (*(char *)(*(int *)(unaff_EBP + -0x34) + 0x30) == '\0') {
          FUN_005a208f(iVar3);
        }
        else {
          FUN_00598d92();
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x18));
    }
    cVar1 = FUN_005b9095(unaff_EBP + -0x18);
    if (cVar1 != '\0') {
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      if (*(char *)(unaff_EBP + 0x18) != '\0') {
        puVar4 = operator_new(0x10);
        *(undefined4 **)(unaff_EBP + -0x14) = puVar4;
        *(undefined4 *)(unaff_EBP + -4) = 3;
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          *puVar4 = 0;
          FUN_0055e4e2(unaff_EBP + -0x29);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(undefined4 **)(unaff_EBP + -0x1c) = puVar4;
        pvVar2 = operator_new(0x2c);
        *(void **)(unaff_EBP + -0x14) = pvVar2;
        *(undefined4 *)(unaff_EBP + -4) = 4;
        if (pvVar2 == (void *)0x0) {
          uVar6 = 0;
        }
        else {
          uVar6 = FUN_00594f5f();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x20) = uVar6;
      }
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      if (0 < *(int *)(unaff_EBP + -0x18)) {
        do {
          pvVar2 = operator_new(0x38);
          *(void **)(unaff_EBP + -0x14) = pvVar2;
          *(undefined4 *)(unaff_EBP + -4) = 5;
          if (pvVar2 == (void *)0x0) {
            iVar3 = 0;
          }
          else {
            iVar3 = FUN_0059ed87();
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005954bc();
          uVar6 = *(undefined4 *)(unaff_EBP + 0x14);
          cVar1 = *(char *)(unaff_EBP + 0x18);
          *(undefined4 *)(iVar3 + 0x10) = uVar6;
          if (cVar1 == '\0') {
            cVar1 = FUN_0059510c(*(undefined4 *)(unaff_EBP + 0x10));
          }
          else {
            cVar1 = FUN_00595299(*(undefined4 *)(unaff_EBP + 0x10),
                                 *(undefined4 *)(unaff_EBP + -0x1c),
                                 *(undefined4 *)(unaff_EBP + -0x20));
          }
          if (cVar1 == '\0') goto LAB_0059f427;
          uVar5 = FUN_005a20c2(iVar3 + 4);
          *(undefined4 *)(unaff_EBP + -4) = 6;
          FUN_005a2464(unaff_EBP + -0x34,uVar5);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_0059ee88();
          if (*(int *)(unaff_EBP + -0x34) == 0) {
            FUN_0042004f();
            FUN_005b86bd(*(undefined4 *)(unaff_EBP + 0xc));
            *(undefined4 *)(unaff_EBP + -4) = 7;
            FUN_005b88c2();
            uVar6 = FUN_005a2129(iVar3,*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x40,uVar6);
            *(undefined1 *)(unaff_EBP + -4) = 8;
            FUN_005a1e39(unaff_EBP + -0x54,uVar6);
            *(undefined1 *)(unaff_EBP + -4) = 7;
            FUN_0059ee88();
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            FUN_005b8770();
          }
          else if (*(char *)(*(int *)(unaff_EBP + -0x34) + 0x30) == '\0') {
            FUN_005a2230(iVar3);
          }
          else {
            FUN_005954c1();
          }
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
        } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x18));
      }
      cVar1 = FUN_005b9095(unaff_EBP + -0x18);
      if (cVar1 != '\0') {
        *(undefined4 *)(unaff_EBP + -0x24) = 0;
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        if (*(char *)(unaff_EBP + 0x18) != '\0') {
          pvVar2 = operator_new(0x34);
          *(void **)(unaff_EBP + -0x14) = pvVar2;
          *(undefined4 *)(unaff_EBP + -4) = 9;
          if (pvVar2 == (void *)0x0) {
            uVar6 = 0;
          }
          else {
            uVar6 = FUN_0059780a();
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          *(undefined4 *)(unaff_EBP + -0x24) = uVar6;
          puVar4 = operator_new(0x10);
          if (puVar4 == (undefined4 *)0x0) {
            puVar4 = (undefined4 *)0x0;
          }
          else {
            *puVar4 = 0;
            puVar4[1] = 0;
            puVar4[2] = 0;
            puVar4[3] = 0;
          }
          *(undefined4 **)(unaff_EBP + -0x14) = puVar4;
        }
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
        if (0 < *(int *)(unaff_EBP + -0x18)) {
          do {
            pvVar2 = operator_new(0x80);
            *(void **)(unaff_EBP + -0x30) = pvVar2;
            *(undefined4 *)(unaff_EBP + -4) = 10;
            if (pvVar2 == (void *)0x0) {
              iVar3 = 0;
            }
            else {
              iVar3 = FUN_0059edbf();
            }
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            FUN_005954bc();
            cVar1 = *(char *)(unaff_EBP + 0x18);
            *(undefined4 *)(iVar3 + 0x58) = *(undefined4 *)(unaff_EBP + 0x14);
            if (cVar1 == '\0') {
              cVar1 = FUN_00596f69(*(undefined4 *)(unaff_EBP + 0x10));
            }
            else {
              cVar1 = FUN_00597112(*(undefined4 *)(unaff_EBP + 0x10),
                                   *(undefined4 *)(unaff_EBP + -0x24),
                                   *(undefined4 *)(unaff_EBP + -0x1c),
                                   *(undefined4 *)(unaff_EBP + -0x14));
            }
            if (cVar1 == '\0') goto LAB_0059f427;
            uVar6 = FUN_005a2263(iVar3 + 4);
            *(undefined4 *)(unaff_EBP + -4) = 0xb;
            FUN_005a242b(unaff_EBP + -0x48,uVar6);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            FUN_0059eecd();
            if (*(int *)(unaff_EBP + -0x48) == 0) {
              FUN_0042004f();
              if (*(char *)(unaff_EBP + 0x18) == '\0') {
                uVar6 = FUN_005a22ca(iVar3,*(undefined4 *)(unaff_EBP + 8),
                                     *(undefined4 *)(unaff_EBP + 0xc),
                                     *(undefined4 *)(unaff_EBP + 0x14));
                *(undefined4 *)(unaff_EBP + -4) = 0xd;
                FUN_005a1d7c(unaff_EBP + -200,uVar6);
                *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                FUN_0059eecd();
              }
              else {
                uVar6 = FUN_005a234f(iVar3 + 4,*(undefined4 *)(unaff_EBP + 8),
                                     *(undefined4 *)(unaff_EBP + 0xc),
                                     *(undefined4 *)(unaff_EBP + 0x14));
                *(undefined4 *)(unaff_EBP + -4) = 0xc;
                FUN_005a1d7c(unaff_EBP + -0x54,uVar6);
                *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                FUN_0059eecd();
LAB_0059f360:
                FUN_005977a1();
              }
            }
            else {
              if (*(char *)(*(int *)(unaff_EBP + -0x48) + 0x30) != '\0') goto LAB_0059f360;
              FUN_005a23d1(iVar3);
            }
            *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
          } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x18));
        }
        if (*(int *)(unaff_EBP + -0x20) != 0) {
          FUN_00594d07();
          FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x20));
        }
        if (*(int *)(unaff_EBP + -0x1c) != 0) {
          FUN_00594235();
          FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x1c));
        }
        if (*(int *)(unaff_EBP + -0x24) != 0) {
          FUN_00596b92();
          FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x24));
        }
        if (*(int *)(unaff_EBP + -0x14) != 0) {
          FUN_00594673();
          FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x14));
        }
        uVar6 = 0;
        goto LAB_0059f416;
      }
    }
LAB_0059f427:
    uVar6 = **(undefined4 **)(unaff_EBP + 0xc);
  }
  FUN_004f6cef(uVar6);
  uVar6 = 0xffffffff;
LAB_0059f416:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar6;
}

