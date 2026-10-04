
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004b5918(void)

{
  int *piVar1;
  undefined4 *puVar2;
  float fVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  void *pvVar8;
  undefined4 uVar9;
  int *extraout_ECX;
  int iVar10;
  int unaff_EBP;
  uint uVar11;
  int *piVar12;
  int *piVar13;
  undefined4 uVar14;
  
  FUN_00634c24();
  iVar5 = FUN_0049bf60();
  iVar5 = iVar5 + 1;
  *(int *)(unaff_EBP + -0x2c) = iVar5;
  FUN_004b5ef1(iVar5);
  *(undefined4 *)(unaff_EBP + -0x10) = 3;
  do {
    FUN_004b5f7b(iVar5);
    FUN_004b5f7b(iVar5);
    piVar13 = (int *)(unaff_EBP + -0x10);
    *piVar13 = *piVar13 + -1;
  } while (*piVar13 != 0);
  iVar10 = 0;
  FUN_0046f824();
  *(undefined ***)(unaff_EBP + -0x25c) = &PTR_FUN_006664e8;
  FUN_0041532c();
  FUN_004ee9ce();
  uVar14 = 0;
  uVar9 = *(undefined4 *)(unaff_EBP + -600);
  FUN_005b8e25(uVar9,0);
  iVar6 = FUN_005b936f(uVar9,uVar14);
  extraout_ECX[0x18] = iVar6;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  if (0 < iVar5) {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    do {
      puVar7 = operator_new(0x18);
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        *puVar7 = 0;
        puVar7[4] = 0;
        puVar7[3] = 0;
        puVar7[2] = 0;
      }
      *(undefined4 **)(unaff_EBP + -0x1c) = puVar7;
      if (puVar7 == (undefined4 *)0x0) goto LAB_004b5e25;
      cVar4 = FUN_0049bfe2(*(undefined4 *)(unaff_EBP + -0x14),extraout_ECX[0x18] != 0);
      if (cVar4 != '\0') goto LAB_004b5e25;
      if (extraout_ECX[0x18] == 0) {
        *(undefined4 *)(unaff_EBP + -0x3c) = 0x3fc00000;
        fVar3 = (float)_DAT_006687d0;
        *(undefined4 *)(unaff_EBP + -0x34) = 0x40a00000;
        *(float *)(unaff_EBP + -0x38) = -((float)*(int *)(unaff_EBP + -0x10) + fVar3);
        FUN_0049c03c(unaff_EBP + -0x3c);
      }
      FUN_004b5f54(unaff_EBP + -0x1c);
      FUN_0049bf89(*(undefined4 *)(unaff_EBP + -0x14));
      *(undefined4 *)(unaff_EBP + -0x18) = 1;
      *(int **)(unaff_EBP + -0x20) = extraout_ECX + 0xc;
      do {
        pvVar8 = operator_new(0x20);
        *(void **)(unaff_EBP + -0x28) = pvVar8;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar8 == (void *)0x0) {
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_004bb693();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(int *)(unaff_EBP + -0x24) = iVar5;
        if (iVar5 == 0) goto LAB_004b5e25;
        if (extraout_ECX[0x18] == 0) {
          cVar4 = FUN_004bb7ad();
          if (cVar4 != '\0') goto LAB_004b5e25;
        }
        pvVar8 = operator_new(0x20);
        *(void **)(unaff_EBP + -0x28) = pvVar8;
        *(undefined4 *)(unaff_EBP + -4) = 1;
        if (pvVar8 == (void *)0x0) {
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_004bb693();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(int *)(unaff_EBP + -0x30) = iVar5;
        if (iVar5 == 0) goto LAB_004b5e25;
        if (extraout_ECX[0x18] == 0) {
          cVar4 = FUN_004bb7ad();
          if (cVar4 != '\0') goto LAB_004b5e25;
        }
        FUN_004b5fde(unaff_EBP + -0x24);
        FUN_004b5fde(unaff_EBP + -0x30);
        *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 0xc;
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
      } while (*(int *)(unaff_EBP + -0x18) + -1 < 3);
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 3;
    } while (*(int *)(unaff_EBP + -0x14) < *(int *)(unaff_EBP + -0x2c));
  }
  iVar5 = 0;
  *(int **)(unaff_EBP + -0x10) = extraout_ECX + 0x15;
  do {
    puVar7 = operator_new(0x10);
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      *puVar7 = 0;
      puVar7[1] = 0;
      puVar7[2] = 0;
    }
    puVar2 = *(undefined4 **)(unaff_EBP + -0x10);
    *puVar2 = puVar7;
    if (puVar7 == (undefined4 *)0x0) goto LAB_004b5e25;
    iVar5 = iVar5 + 1;
    cVar4 = FUN_004a3808((double)_DAT_006f011c,_DAT_006687c8,iVar5,
                         CONCAT31((int3)((uint)puVar2 >> 8),extraout_ECX[0x18] != 0));
    if (cVar4 != '\0') goto LAB_004b5e25;
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 4;
  } while (iVar5 < 3);
  if (extraout_ECX[0x18] == 0) {
LAB_004b5c92:
    FUN_0046f824();
    *(undefined ***)(unaff_EBP + -0x14c) = &PTR_FUN_006664e8;
    FUN_0041532c();
    FUN_004ee9ce();
    uVar14 = 1;
    uVar9 = *(undefined4 *)(unaff_EBP + -0x148);
    FUN_005b8e25(uVar9,1);
    iVar5 = FUN_005b936f(uVar9,uVar14);
    extraout_ECX[0x18] = iVar5;
    if (iVar5 != 0) {
      FUN_005b8e25(iVar5);
      FUN_005b95c0(iVar5);
      uVar9 = *(undefined4 *)(unaff_EBP + -0x148);
      FUN_005b8e25(uVar9);
      FUN_005b9796(uVar9);
    }
    uVar9 = *(undefined4 *)(unaff_EBP + -0x148);
    FUN_005b8e25(uVar9);
    cVar4 = FUN_005b960e(uVar9);
    if (cVar4 != '\0') {
      uVar14 = 1;
      uVar9 = *(undefined4 *)(unaff_EBP + -0x148);
      FUN_005b8e25(uVar9,1);
      iVar5 = FUN_005b936f(uVar9,uVar14);
      extraout_ECX[0x18] = iVar5;
    }
    if (extraout_ECX[0x18] != 0) {
      uVar11 = 0;
      if (extraout_ECX[1] - *extraout_ECX >> 2 != 0) {
        do {
          FUN_0049c1d3(extraout_ECX[0x18]);
          uVar11 = uVar11 + 1;
        } while (uVar11 < (uint)(extraout_ECX[1] - *extraout_ECX >> 2));
      }
      *(undefined4 *)(unaff_EBP + -0x10) = 3;
      piVar13 = extraout_ECX;
      do {
        piVar12 = piVar13 + 3;
        iVar5 = piVar13[4];
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        if (iVar5 - *piVar12 >> 2 != 0) {
          do {
            FUN_004bb9e9(extraout_ECX[0x18]);
            iVar5 = piVar13[4];
            *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
          } while (*(uint *)(unaff_EBP + -0x14) < (uint)(iVar5 - *piVar12 >> 2));
        }
        piVar1 = (int *)(unaff_EBP + -0x10);
        *piVar1 = *piVar1 + -1;
        piVar13 = piVar12;
      } while (*piVar1 != 0);
      piVar13 = extraout_ECX + 0xc;
      *(undefined4 *)(unaff_EBP + -0x10) = 3;
      do {
        iVar5 = piVar13[1];
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        if (iVar5 - *piVar13 >> 2 != 0) {
          do {
            FUN_004bb9e9(extraout_ECX[0x18]);
            iVar5 = piVar13[1];
            *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
          } while (*(uint *)(unaff_EBP + -0x14) < (uint)(iVar5 - *piVar13 >> 2));
        }
        piVar13 = piVar13 + 3;
        piVar12 = (int *)(unaff_EBP + -0x10);
        *piVar12 = *piVar12 + -1;
      } while (*piVar12 != 0);
      *(undefined4 *)(unaff_EBP + -0x10) = 3;
      do {
        FUN_004a3a9d(extraout_ECX[0x18]);
        piVar13 = (int *)(unaff_EBP + -0x10);
        *piVar13 = *piVar13 + -1;
      } while (*piVar13 != 0);
      iVar5 = extraout_ECX[0x18];
      FUN_005b8e25(iVar5);
      FUN_005b95c0(iVar5);
      extraout_ECX[0x18] = 0;
    }
  }
  else {
    iVar5 = *extraout_ECX;
    uVar11 = 0;
    if (extraout_ECX[1] - iVar5 >> 2 != 0) {
      do {
        *(int *)(*(int *)(iVar5 + uVar11 * 4) + 0x14) = iVar10;
        iVar5 = FUN_0049c1cb();
        iVar10 = iVar10 + iVar5;
        iVar5 = *extraout_ECX;
        uVar11 = uVar11 + 1;
      } while (uVar11 < (uint)(extraout_ECX[1] - iVar5 >> 2));
    }
    *(undefined4 *)(unaff_EBP + -0x10) = 3;
    piVar13 = extraout_ECX;
    do {
      piVar12 = piVar13 + 3;
      iVar5 = piVar13[4];
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      if (iVar5 - *piVar12 >> 2 != 0) {
        do {
          *(int *)(*(int *)(*(int *)(unaff_EBP + -0x14) * 4 + *piVar12) + 0x18) = iVar10;
          iVar5 = FUN_004bb9b6();
          iVar10 = iVar10 + iVar5;
          iVar5 = piVar13[4];
          iVar6 = *piVar12;
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        } while (*(uint *)(unaff_EBP + -0x14) < (uint)(iVar5 - iVar6 >> 2));
      }
      piVar1 = (int *)(unaff_EBP + -0x10);
      *piVar1 = *piVar1 + -1;
      piVar13 = piVar12;
    } while (*piVar1 != 0);
    piVar13 = extraout_ECX + 0xc;
    *(undefined4 *)(unaff_EBP + -0x10) = 3;
    do {
      iVar5 = piVar13[1];
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      if (iVar5 - *piVar13 >> 2 != 0) {
        do {
          *(int *)(*(int *)(*(int *)(unaff_EBP + -0x14) * 4 + *piVar13) + 0x18) = iVar10;
          iVar5 = FUN_004bb9b6();
          iVar10 = iVar10 + iVar5;
          iVar5 = piVar13[1];
          iVar6 = *piVar13;
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        } while (*(uint *)(unaff_EBP + -0x14) < (uint)(iVar5 - iVar6 >> 2));
      }
      piVar13 = piVar13 + 3;
      piVar12 = (int *)(unaff_EBP + -0x10);
      *piVar12 = *piVar12 + -1;
    } while (*piVar12 != 0);
    piVar13 = extraout_ECX + 0x15;
    *(undefined4 *)(unaff_EBP + -0x10) = 3;
    do {
      *(int *)(*piVar13 + 0xc) = iVar10;
      iVar5 = FUN_004a3a8f();
      iVar10 = iVar10 + iVar5;
      piVar13 = piVar13 + 1;
      piVar12 = (int *)(unaff_EBP + -0x10);
      *piVar12 = *piVar12 + -1;
    } while (*piVar12 != 0);
    if (extraout_ECX[0x18] == 0) goto LAB_004b5c92;
  }
  uVar9 = 0;
LAB_004b5e16:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar9;
LAB_004b5e25:
  uVar9 = 1;
  goto LAB_004b5e16;
}

