
undefined4 FUN_0059e5d1(void)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 extraout_ECX;
  undefined4 uVar6;
  int unaff_EBP;
  int *piVar7;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  piVar7 = *(int **)(unaff_EBP + 0x10);
  uVar6 = 0;
  *(undefined4 *)(unaff_EBP + -0x30) = extraout_ECX;
  if (*(int *)(*(int *)(*piVar7 + 4) + 8 + (int)piVar7) == 0) {
    if (*(char *)(unaff_EBP + 0x18) != '\0') {
      *(undefined1 *)(unaff_EBP + 0x20) = 0;
    }
    FUN_00594033(unaff_EBP + -0x234,0x100,10);
    FUN_00594033(unaff_EBP + -0x334,0x100,10);
    if (*(int *)(*(int *)(*piVar7 + 4) + 8 + (int)piVar7) == 0) {
      FUN_006326ae(unaff_EBP + -0x18);
      if (*(int *)(*(int *)(*piVar7 + 4) + 8 + (int)piVar7) == 0) {
        *(undefined4 *)(unaff_EBP + -0x54) = 0;
        *(undefined4 *)(unaff_EBP + -0x50) = 0;
        *(undefined4 *)(unaff_EBP + -0x4c) = 0;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(undefined4 *)(unaff_EBP + -0x48) = 0;
        *(undefined4 *)(unaff_EBP + -0x44) = 0;
        *(undefined4 *)(unaff_EBP + -0x40) = 0;
        *(undefined4 *)(unaff_EBP + -0x3c) = 0;
        *(undefined4 *)(unaff_EBP + -0x38) = 0;
        *(undefined4 *)(unaff_EBP + -0x34) = 0;
        iVar8 = 0;
        *(undefined1 *)(unaff_EBP + -4) = 2;
        if (0 < *(int *)(unaff_EBP + -0x18)) {
          do {
            pvVar2 = operator_new(0xd4);
            *(void **)(unaff_EBP + -0x14) = pvVar2;
            *(undefined1 *)(unaff_EBP + -4) = 3;
            if (pvVar2 == (void *)0x0) {
              uVar3 = 0;
            }
            else {
              uVar3 = FUN_00598f28();
            }
            *(undefined1 *)(unaff_EBP + -4) = 2;
            *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
            FUN_005954bc();
            FUN_00598821(piVar7,*(undefined4 *)(unaff_EBP + -0x10));
            if (*(int *)(*(int *)(*piVar7 + 4) + 8 + (int)piVar7) != 0) {
              FUN_004f6cef(**(undefined4 **)(unaff_EBP + 0xc));
              FUN_00598d92();
              goto LAB_0059ed5f;
            }
            uVar3 = FUN_005a1f21(*(int *)(unaff_EBP + -0x10) + 4);
            *(undefined1 *)(unaff_EBP + -4) = 4;
            FUN_005a242b(unaff_EBP + -0x5c,uVar3);
            *(undefined1 *)(unaff_EBP + -4) = 2;
            FUN_0059ee43();
            if (*(int *)(unaff_EBP + -0x5c) == 0) {
              FUN_0042004f();
              uVar3 = FUN_005a1f88(*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + 8)
                                   ,*(undefined4 *)(unaff_EBP + 0xc),
                                   *(undefined4 *)(unaff_EBP + 0x14));
              *(undefined1 *)(unaff_EBP + -4) = 5;
              FUN_005a1cbf(unaff_EBP + -0x74,uVar3);
              *(undefined1 *)(unaff_EBP + -4) = 2;
              FUN_0059ee43();
            }
            else if ((*(char *)(*(int *)(unaff_EBP + -0x5c) + 0x30) == '\0') &&
                    (*(char *)(unaff_EBP + 0x20) == '\0')) {
              FUN_005a208f(*(undefined4 *)(unaff_EBP + -0x10));
            }
            else {
              FUN_00598d92();
              *(undefined4 *)(unaff_EBP + -0x10) = 0;
            }
            if (*(int *)(unaff_EBP + -0x10) != 0) {
              FUN_005a1eac(unaff_EBP + -0x10);
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < *(int *)(unaff_EBP + -0x18));
        }
        FUN_006326ae(unaff_EBP + -0x18);
        if (*(int *)(*(int *)(*piVar7 + 4) + 8 + (int)piVar7) == 0) {
          *(undefined4 *)(unaff_EBP + -0x24) = 0;
          *(undefined4 *)(unaff_EBP + -0x28) = 0;
          if (*(char *)(unaff_EBP + 0x20) != '\0') {
            puVar4 = operator_new(0x10);
            *(undefined4 **)(unaff_EBP + -0x14) = puVar4;
            *(undefined1 *)(unaff_EBP + -4) = 6;
            if (puVar4 == (undefined4 *)0x0) {
              puVar4 = (undefined4 *)0x0;
            }
            else {
              *puVar4 = 0;
              FUN_0055e4e2(unaff_EBP + -0x1d);
            }
            *(undefined1 *)(unaff_EBP + -4) = 2;
            *(undefined4 **)(unaff_EBP + -0x24) = puVar4;
            pvVar2 = operator_new(0x2c);
            *(void **)(unaff_EBP + -0x14) = pvVar2;
            *(undefined1 *)(unaff_EBP + -4) = 7;
            if (pvVar2 == (void *)0x0) {
              uVar3 = 0;
            }
            else {
              uVar3 = FUN_00594f5f();
            }
            *(undefined1 *)(unaff_EBP + -4) = 2;
            *(undefined4 *)(unaff_EBP + -0x28) = uVar3;
          }
          *(undefined4 *)(unaff_EBP + -0x1c) = 0;
          if (0 < *(int *)(unaff_EBP + -0x18)) {
            do {
              pvVar2 = operator_new(0x38);
              *(void **)(unaff_EBP + -0x14) = pvVar2;
              *(undefined1 *)(unaff_EBP + -4) = 8;
              if (pvVar2 == (void *)0x0) {
                uVar3 = 0;
              }
              else {
                uVar3 = FUN_0059ed87();
              }
              *(undefined1 *)(unaff_EBP + -4) = 2;
              *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
              FUN_005954bc();
              cVar1 = *(char *)(unaff_EBP + 0x20);
              *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10) =
                   *(undefined4 *)(unaff_EBP + 0x14);
              if (cVar1 == '\0') {
                piVar7 = *(int **)(unaff_EBP + 0x10);
                FUN_00594d8a(piVar7,*(undefined4 *)(unaff_EBP + -0x10));
              }
              else {
                piVar7 = *(int **)(unaff_EBP + 0x10);
                FUN_00594fa2(piVar7,*(undefined4 *)(unaff_EBP + -0x24),
                             *(undefined4 *)(unaff_EBP + -0x28));
              }
              if (*(int *)(*(int *)(*piVar7 + 4) + 8 + (int)piVar7) != 0) {
                FUN_004f6cef(**(undefined4 **)(unaff_EBP + 0xc));
                FUN_005954c1();
                goto LAB_0059ed5f;
              }
              iVar8 = *(int *)(unaff_EBP + -0x10) + 4;
              uVar3 = FUN_005a20c2(iVar8);
              *(undefined1 *)(unaff_EBP + -4) = 9;
              FUN_005a2464(unaff_EBP + -0x5c,uVar3);
              *(undefined1 *)(unaff_EBP + -4) = 2;
              FUN_0059ee88();
              if (*(int *)(unaff_EBP + -0x5c) == 0) {
                FUN_0042004f();
                FUN_005b86bd(*(undefined4 *)(unaff_EBP + 0xc));
                *(undefined1 *)(unaff_EBP + -4) = 10;
                FUN_005b88c2();
                if (*(char *)(unaff_EBP + 0x20) == '\0') {
                  uVar3 = FUN_005a2129(*(undefined4 *)(unaff_EBP + -0x10),
                                       *(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x68,
                                       *(undefined4 *)(unaff_EBP + 0x14));
                  *(undefined1 *)(unaff_EBP + -4) = 0xc;
                  FUN_005a1e39(unaff_EBP + -0x80,uVar3);
                  *(undefined1 *)(unaff_EBP + -4) = 10;
                  FUN_0059ee88();
                }
                else {
                  uVar3 = FUN_005a21ae(iVar8,*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x68,
                                       *(undefined4 *)(unaff_EBP + 0x14));
                  *(undefined1 *)(unaff_EBP + -4) = 0xb;
                  FUN_005a1e39(unaff_EBP + -0x74,uVar3);
                  *(undefined1 *)(unaff_EBP + -4) = 10;
                  FUN_0059ee88();
                  FUN_005954c1();
                  *(undefined4 *)(unaff_EBP + -0x10) = 0;
                }
                *(undefined1 *)(unaff_EBP + -4) = 2;
                FUN_005b8770();
              }
              else if ((*(char *)(*(int *)(unaff_EBP + -0x5c) + 0x30) == '\0') &&
                      (*(char *)(unaff_EBP + 0x20) == '\0')) {
                FUN_005a2230(*(undefined4 *)(unaff_EBP + -0x10));
              }
              else {
                FUN_005954c1();
                *(undefined4 *)(unaff_EBP + -0x10) = 0;
              }
              if (*(int *)(unaff_EBP + -0x10) != 0) {
                FUN_005a1ed3(unaff_EBP + -0x10);
              }
              *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
            } while (*(int *)(unaff_EBP + -0x1c) < *(int *)(unaff_EBP + -0x18));
            piVar7 = *(int **)(unaff_EBP + 0x10);
          }
          FUN_006326ae(unaff_EBP + -0x18);
          if (*(int *)(*(int *)(*piVar7 + 4) + 8 + (int)piVar7) != 0) goto LAB_0059e79e;
          pvVar2 = operator_new(0x34);
          *(void **)(unaff_EBP + -0x14) = pvVar2;
          *(undefined1 *)(unaff_EBP + -4) = 0xd;
          if (pvVar2 == (void *)0x0) {
            *(undefined4 *)(unaff_EBP + -0x2c) = 0;
          }
          else {
            uVar3 = FUN_0059780a();
            *(undefined4 *)(unaff_EBP + -0x2c) = uVar3;
          }
          *(undefined1 *)(unaff_EBP + -4) = 2;
          puVar4 = operator_new(0x10);
          *(undefined4 **)(unaff_EBP + -0x14) = puVar4;
          *(undefined1 *)(unaff_EBP + -4) = 0xe;
          if (puVar4 == (undefined4 *)0x0) {
            *(undefined4 *)(unaff_EBP + -0x14) = 0;
          }
          else {
            *puVar4 = 0;
            FUN_0055e4e2(unaff_EBP + -0x1d);
            *(undefined4 **)(unaff_EBP + -0x14) = puVar4;
          }
          *(undefined1 *)(unaff_EBP + -4) = 2;
          *(undefined4 *)(unaff_EBP + -0x1c) = 0;
          if (0 < *(int *)(unaff_EBP + -0x18)) {
            do {
              pvVar2 = operator_new(0x80);
              *(void **)(unaff_EBP + -0x58) = pvVar2;
              *(undefined1 *)(unaff_EBP + -4) = 0xf;
              if (pvVar2 == (void *)0x0) {
                uVar3 = 0;
              }
              else {
                uVar3 = FUN_0059edbf();
              }
              *(undefined1 *)(unaff_EBP + -4) = 2;
              *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
              FUN_005954bc();
              cVar1 = *(char *)(unaff_EBP + 0x20);
              *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x58) =
                   *(undefined4 *)(unaff_EBP + 0x14);
              if (cVar1 == '\0') {
                piVar7 = *(int **)(unaff_EBP + 0x10);
                FUN_00596c0d(piVar7,*(undefined4 *)(unaff_EBP + -0x10));
              }
              else {
                piVar7 = *(int **)(unaff_EBP + 0x10);
                FUN_00596dcf(piVar7,*(undefined4 *)(unaff_EBP + -0x2c),
                             *(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x14));
              }
              if (*(int *)(*(int *)(*piVar7 + 4) + 8 + (int)piVar7) != 0) {
                FUN_004f6cef(**(undefined4 **)(unaff_EBP + 0xc));
                FUN_005977a1();
LAB_0059ed5f:
                *(undefined1 *)(unaff_EBP + -4) = 1;
                FUN_0048c4c9();
                *(undefined1 *)(unaff_EBP + -4) = 0;
                FUN_0048c4c9();
                *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                FUN_0048c4c9();
                goto LAB_0059ed82;
              }
              iVar8 = *(int *)(unaff_EBP + -0x10) + 4;
              uVar3 = FUN_005a2263(iVar8);
              *(undefined1 *)(unaff_EBP + -4) = 0x10;
              FUN_005a242b(unaff_EBP + -100,uVar3);
              *(undefined1 *)(unaff_EBP + -4) = 2;
              FUN_0059eecd();
              if (*(int *)(unaff_EBP + -100) == 0) {
                FUN_0042004f();
                if (*(char *)(unaff_EBP + 0x20) == '\0') {
                  uVar3 = FUN_005a22ca(*(undefined4 *)(unaff_EBP + -0x10),
                                       *(undefined4 *)(unaff_EBP + 8),
                                       *(undefined4 *)(unaff_EBP + 0xc),
                                       *(undefined4 *)(unaff_EBP + 0x14));
                  *(undefined1 *)(unaff_EBP + -4) = 0x12;
                  FUN_005a1d7c(unaff_EBP + -0x80,uVar3);
                  *(undefined1 *)(unaff_EBP + -4) = 2;
                  FUN_0059eecd();
                  goto LAB_0059ebc2;
                }
                uVar3 = FUN_005a234f(iVar8,*(undefined4 *)(unaff_EBP + 8),
                                     *(undefined4 *)(unaff_EBP + 0xc),
                                     *(undefined4 *)(unaff_EBP + 0x14));
                *(undefined1 *)(unaff_EBP + -4) = 0x11;
                FUN_005a1d7c(unaff_EBP + -0x74,uVar3);
                *(undefined1 *)(unaff_EBP + -4) = 2;
                FUN_0059eecd();
                FUN_005977a1();
                *(undefined4 *)(unaff_EBP + -0x10) = 0;
              }
              else {
                if ((*(char *)(*(int *)(unaff_EBP + -100) + 0x30) == '\0') &&
                   (*(char *)(unaff_EBP + 0x20) == '\0')) {
                  FUN_005a23d1(*(undefined4 *)(unaff_EBP + -0x10));
                }
                else {
                  FUN_005977a1();
                  *(undefined4 *)(unaff_EBP + -0x10) = 0;
                }
LAB_0059ebc2:
                if (*(int *)(unaff_EBP + -0x10) != 0) {
                  FUN_005a1efa(unaff_EBP + -0x10);
                }
              }
              *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
            } while (*(int *)(unaff_EBP + -0x1c) < *(int *)(unaff_EBP + -0x18));
          }
          if (*(int *)(unaff_EBP + -0x24) != 0) {
            FUN_00594235();
            FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x24));
          }
          if (*(int *)(unaff_EBP + -0x28) != 0) {
            FUN_00594d07();
            FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x28));
          }
          if (*(int *)(unaff_EBP + -0x2c) != 0) {
            FUN_00596b92();
            FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x2c));
          }
          if (*(int *)(unaff_EBP + -0x14) != 0) {
            FUN_00594673();
            FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x14));
          }
          if (*(char *)(unaff_EBP + 0x18) != '\0') {
            uVar3 = FUN_005b870f(&DAT_006d1d64);
            *(undefined1 *)(unaff_EBP + -4) = 0x13;
            uVar5 = FUN_00412ab1(unaff_EBP + -0x80,*(undefined4 *)(unaff_EBP + 0x1c),
                                 *(undefined4 *)(unaff_EBP + 0xc));
            *(undefined1 *)(unaff_EBP + -4) = 0x14;
            uVar3 = FUN_00412ab1(unaff_EBP + -0x98,uVar5,uVar3);
            *(undefined1 *)(unaff_EBP + -4) = 0x15;
            FUN_005b86bd(uVar3);
            *(undefined1 *)(unaff_EBP + -4) = 0x19;
            FUN_00401729();
            *(undefined1 *)(unaff_EBP + -4) = 0x18;
            FUN_00401729();
            *(undefined1 *)(unaff_EBP + -4) = 0x17;
            FUN_005b8770();
            uVar3 = *(undefined4 *)(unaff_EBP + -0x8c);
            uVar5 = uVar3;
            FUN_005b8e25(uVar3);
            cVar1 = FUN_005b960e(uVar5);
            if (cVar1 != '\0') {
              uVar5 = 1;
              FUN_005b8e25(uVar3,1);
              uVar3 = FUN_005b936f(uVar3,uVar5);
              FUN_0059f437(*(undefined4 *)(unaff_EBP + 0xc),uVar3,*(undefined4 *)(unaff_EBP + 0x14),
                           *(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0x1c),
                           unaff_EBP + -0x54,unaff_EBP + -0x48,unaff_EBP + -0x3c);
              FUN_005b8e25(uVar3);
              FUN_005b95c0(uVar3);
            }
            *(undefined1 *)(unaff_EBP + -4) = 2;
            FUN_005b8770();
          }
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_0048c4c9();
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_0048c4c9();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        }
        else {
LAB_0059e79e:
          FUN_004f6cef(**(undefined4 **)(unaff_EBP + 0xc));
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_0048c4c9();
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_0048c4c9();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          uVar6 = 0xffffffff;
        }
        FUN_0048c4c9();
        goto LAB_0059ed3b;
      }
    }
    FUN_004f6cef(**(undefined4 **)(unaff_EBP + 0xc));
  }
LAB_0059ed82:
  uVar6 = 0xffffffff;
LAB_0059ed3b:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar6;
}

