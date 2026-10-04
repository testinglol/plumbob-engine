
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d2a7e(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int *extraout_ECX;
  uint uVar8;
  int *piVar9;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  iVar4 = FUN_00401f6f();
  if (iVar4 == 2) {
    piVar1 = extraout_ECX + 0x45f;
    iVar4 = extraout_ECX[0x460] - *piVar1 >> 2;
    while (iVar4 = iVar4 + -1, -1 < iVar4) {
      piVar9 = *(int **)(*piVar1 + iVar4 * 4);
      *(int **)(unaff_EBP + -0x10) = piVar9;
      iVar5 = (**(code **)(*piVar9 + 0x18))();
      if (iVar5 == 0) {
        FUN_005ddfdc(1);
        (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(unaff_EBP + -0x10));
      }
    }
    if ((DAT_006f0ed4 & 1) == 0) {
      DAT_006f0ed4 = DAT_006f0ed4 | 1;
      DAT_006f0ec8 = 0;
      DAT_006f0ecc = 0;
      _DAT_006f0ed0 = 0;
      FUN_00635543(&LAB_004d2e4c);
    }
    FUN_004d419c(DAT_006f0ec8,DAT_006f0ecc);
    uVar6 = FUN_004e99a9(&DAT_006f0ec8);
    FUN_004ea458(uVar6);
    uVar8 = 0;
    if (extraout_ECX[0x460] - *piVar1 >> 2 != 0) {
      do {
        *(undefined1 *)(*(int *)(*piVar1 + uVar8 * 4) + 0x104) = 0;
        uVar8 = uVar8 + 1;
      } while (uVar8 < (uint)(extraout_ECX[0x460] - *piVar1 >> 2));
    }
    if ((DAT_006f0ed4 & 2) == 0) {
      DAT_006f0ed4 = DAT_006f0ed4 | 2;
      DAT_006f0eb8 = 0;
      DAT_006f0ebc = 0;
      _DAT_006f0ec0 = 0;
      FUN_00635543(&LAB_004d2e42);
    }
    FUN_0042ed71(DAT_006f0eb8,DAT_006f0ebc);
    iVar4 = DAT_006f0ec8;
    iVar5 = DAT_006f0ecc - DAT_006f0ec8;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    if (iVar5 / 0x1c != 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      piVar9 = extraout_ECX;
      do {
        iVar4 = *(int *)(unaff_EBP + -0x18) + iVar4;
        uVar6 = FUN_004e89f3();
        iVar5 = extraout_ECX[0x460];
        uVar8 = 0;
        iVar2 = *piVar1;
        *(undefined4 *)(unaff_EBP + -0x20) = uVar6;
        if (iVar5 - iVar2 >> 2 != 0) {
          iVar5 = *piVar1;
          do {
            iVar2 = *(int *)(iVar5 + uVar8 * 4);
            *(int *)(unaff_EBP + -0x10) = iVar2;
            if (*(int *)(unaff_EBP + -0x20) == *(int *)(iVar2 + 0x108)) {
              *(undefined1 *)(iVar2 + 0x104) = 1;
              uVar6 = FUN_004096c2();
              FUN_004cb0b0(uVar6);
              *(undefined1 *)(*(int *)(unaff_EBP + -0x10) + 0x120) = *(undefined1 *)(iVar4 + 8);
              cVar3 = FUN_004e89fa();
              if (cVar3 != '\0') {
                puVar7 = (undefined4 *)FUN_004e8a14(1);
                FUN_005d4956(*puVar7);
                *(undefined4 *)(unaff_EBP + -4) = 0;
                FUN_005dd9c8(unaff_EBP + -0x2c);
                *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                FUN_005b8770();
              }
              goto LAB_004d2d19;
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < (uint)(extraout_ECX[0x460] - *piVar1 >> 2));
          piVar9 = *(int **)(unaff_EBP + -0x14);
        }
        uVar6 = FUN_004d2e9c(iVar4);
        *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
        if ((char)piVar9[0x465] == '\0') {
LAB_004d2d05:
          *(undefined1 *)(*(int *)(unaff_EBP + -0x10) + 0x105) = 0;
        }
        else {
          iVar5 = FUN_004e89f3();
          iVar4 = *(int *)(unaff_EBP + -0x14);
          if (*(int *)(iVar4 + 0x1198) != iVar5) goto LAB_004d2d05;
          iVar5 = *(int *)(iVar4 + 0x11a4);
          *(char *)(piVar9 + 0x465) = '\0';
          FUN_004cb2f2(*(int *)(iVar4 + 0x11a0) + -0x10,iVar5 + -0x10);
          *(undefined1 *)(*(int *)(unaff_EBP + -0x10) + 0x105) = 1;
        }
        *(undefined1 *)(*(int *)(unaff_EBP + -0x10) + 0x104) = 1;
LAB_004d2d19:
        FUN_004d40e1(unaff_EBP + -0x10);
        iVar4 = DAT_006f0ec8;
        iVar5 = DAT_006f0ecc - DAT_006f0ec8;
        *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 0x1c;
        piVar9 = *(int **)(unaff_EBP + -0x14);
      } while (*(uint *)(unaff_EBP + -0x1c) < (uint)(iVar5 / 0x1c));
    }
    do {
      uVar8 = 0;
      while( true ) {
        if ((uint)(extraout_ECX[0x460] - *piVar1 >> 2) <= uVar8) {
          iVar4 = 0x20;
          FUN_0042ed71(*piVar1,extraout_ECX[0x460]);
          uVar8 = 0;
          if (DAT_006f0ebc - DAT_006f0eb8 >> 2 != 0) goto LAB_004d2d9c;
          goto LAB_004d2e0d;
        }
        iVar4 = *(int *)(*piVar1 + uVar8 * 4);
        *(int *)(unaff_EBP + -0x10) = iVar4;
        if (*(char *)(iVar4 + 0x104) == '\0') break;
        uVar8 = uVar8 + 1;
      }
      FUN_004d29e6(iVar4);
    } while( true );
  }
  iVar4 = extraout_ECX[0x460] - extraout_ECX[0x45f] >> 2;
  while (iVar4 = iVar4 + -1, -1 < iVar4) {
    piVar1 = *(int **)(extraout_ECX[0x45f] + iVar4 * 4);
    *(int **)(unaff_EBP + -0x10) = piVar1;
    iVar5 = (**(code **)(*piVar1 + 0x18))();
    if (iVar5 != 0) {
      FUN_005ddfdc(0);
      (**(code **)(*extraout_ECX + 0x24))(*(undefined4 *)(unaff_EBP + -0x10));
    }
  }
  goto LAB_004d2e33;
LAB_004d2d9c:
  do {
    iVar5 = *(int *)(DAT_006f0eb8 + uVar8 * 4);
    *(int *)(unaff_EBP + -0x10) = iVar5;
    if (*(char *)(iVar5 + 0x105) == '\0') {
      FUN_004cb2f2(iVar4,0x20);
    }
    else {
      if (*(char *)(iVar5 + 0xf0) == '\0') {
        if (iVar4 == *(int *)(iVar5 + 0x7c)) {
          iVar5 = *(int *)(iVar5 + 0x80);
          goto LAB_004d2ddb;
        }
      }
      else if (iVar4 == *(int *)(iVar5 + 0xfc)) {
        iVar5 = *(int *)(iVar5 + 0x100);
LAB_004d2ddb:
        if (iVar5 == 0x20) goto LAB_004d2dea;
      }
      FUN_004cb341(iVar4,0x20,500);
    }
LAB_004d2dea:
    FUN_004d40e1(unaff_EBP + -0x10);
    iVar4 = iVar4 + 0x32;
    uVar8 = uVar8 + 1;
  } while (uVar8 < (uint)(DAT_006f0ebc - DAT_006f0eb8 >> 2));
LAB_004d2e0d:
  uVar8 = 0;
  if (extraout_ECX[0x460] - *piVar1 >> 2 != 0) {
    do {
      *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(*piVar1 + uVar8 * 4);
      FUN_004cb3c2();
      uVar8 = uVar8 + 1;
    } while (uVar8 < (uint)(extraout_ECX[0x460] - *piVar1 >> 2));
  }
LAB_004d2e33:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

