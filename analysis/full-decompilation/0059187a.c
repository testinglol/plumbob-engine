
void FUN_0059187a(void)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined2 extraout_var;
  undefined4 uVar6;
  void *pvVar7;
  int *extraout_ECX;
  int iVar8;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar2 = *(int *)(unaff_EBP + 8);
  if (*(int *)(unaff_EBP + 0xc) < 0x2f) {
    FUN_00464b48(extraout_ECX + 0x20,1);
    FUN_00464b48(extraout_ECX + 0x21,1);
    FUN_00464b48(extraout_ECX + 0x22,1);
    if (*(int *)(iVar2 + 0xc) == 1) {
      *(uint *)(unaff_EBP + 8) = CONCAT22(extraout_var,(short)extraout_ECX[0x60]);
    }
    FUN_00464973(unaff_EBP + 8,1);
    if (*(int *)(iVar2 + 0xc) == 0) {
      sVar1 = *(short *)(unaff_EBP + 8);
      extraout_ECX[0x60] = (int)sVar1;
      if (sVar1 == -1) {
        extraout_ECX[0x62] = 0;
      }
      else {
        extraout_ECX[0x62] = 1;
      }
    }
    piVar3 = (int *)extraout_ECX[0x61];
    if (piVar3 == (int *)0x0) {
      *(undefined4 *)(unaff_EBP + 8) = 0;
    }
    else {
      *(int *)(unaff_EBP + 8) = piVar3[1] - *piVar3 >> 3;
    }
    FUN_00464973(unaff_EBP + 8,1);
    iVar8 = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    if (0 < *(short *)(unaff_EBP + 8)) {
      while( true ) {
        *(undefined4 *)(unaff_EBP + -0x20) = 0;
        *(undefined4 *)(unaff_EBP + -0x1c) = 0;
        if (*(int *)(iVar2 + 0xc) == 1) {
          iVar4 = *(int *)extraout_ECX[0x61];
          *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(iVar4 + iVar8 * 8);
          *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar4 + 4 + iVar8 * 8);
        }
        FUN_00464a5e(unaff_EBP + -0x1c,1);
        FUN_00464a5e(unaff_EBP + -0x20,1);
        if (*(int *)(iVar2 + 0xc) == 0) {
          FUN_0045f7c5(unaff_EBP + -0x20);
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
        if ((int)*(short *)(unaff_EBP + 8) <= *(int *)(unaff_EBP + -0x10)) break;
        iVar8 = *(int *)(unaff_EBP + -0x10);
      }
    }
  }
  if (0xc < *(int *)(unaff_EBP + 0xc)) {
    FUN_00464a4e(extraout_ECX + 0x29,1);
    FUN_00464a4e(extraout_ECX + 0x28,1);
  }
  if (*(int *)(unaff_EBP + 0xc) < 0x33) {
    if (*(int *)(iVar2 + 0xc) == 0) {
      *(undefined1 *)(extraout_ECX + 0x36) = 1;
      *(undefined1 *)((int)extraout_ECX + 0xd9) = 1;
    }
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(extraout_ECX[2] + 4);
    FUN_005b86bd(extraout_ECX[0x96] + 4);
    iVar8 = extraout_ECX[0x96];
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005b86bd(iVar8 + 0x10);
    puVar5 = (undefined4 *)extraout_ECX[0x97];
    iVar8 = *(int *)(iVar2 + 0xc);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    uVar6 = *puVar5;
    *(undefined4 *)(unaff_EBP + -0x30) = puVar5[1];
    puVar5 = (undefined4 *)extraout_ECX[0x9a];
    *(undefined4 *)(unaff_EBP + -0x34) = uVar6;
    uVar6 = *puVar5;
    *(undefined4 *)(unaff_EBP + -0x28) = puVar5[1];
    iVar4 = extraout_ECX[0x96];
    *(undefined4 *)(unaff_EBP + -0x2c) = uVar6;
    *(int *)(unaff_EBP + -0x24) = iVar4;
    if (iVar8 == 0) {
      (**(code **)(*extraout_ECX + 0x10))();
      iVar8 = *extraout_ECX;
      *(undefined1 *)((int)extraout_ECX + 0xd9) = 1;
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      (**(code **)(iVar8 + 0x18))();
    }
    else {
      *(int *)(unaff_EBP + -0x10) = extraout_ECX[0x9e] - extraout_ECX[0x9d] >> 2;
    }
    *(undefined4 *)(unaff_EBP + -0x14) = 5;
    *(int *)(unaff_EBP + 8) = unaff_EBP + -0x34;
    do {
      iVar8 = **(int **)(unaff_EBP + 8);
      FUN_00464c84(iVar8 + 4);
      FUN_00464c84(iVar8 + 0x10);
      if ((*(int *)(iVar2 + 0xc) == 0) && (*(char *)(unaff_EBP + 0x10) == '\0')) {
        FUN_00583714(DAT_006f6b64,*(undefined4 *)(unaff_EBP + -0x18));
      }
      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 4;
      piVar3 = (int *)(unaff_EBP + -0x14);
      *piVar3 = *piVar3 + -1;
    } while (*piVar3 != 0);
    iVar8 = FUN_0043017f(*(undefined4 *)(unaff_EBP + -0x4c),*(undefined4 *)(unaff_EBP + -0x48),
                         *(undefined4 *)(extraout_ECX[0x96] + 4),
                         *(undefined4 *)(extraout_ECX[0x96] + 8));
    if ((iVar8 != 0) ||
       (iVar8 = FUN_0043017f(*(undefined4 *)(unaff_EBP + -0x40),*(undefined4 *)(unaff_EBP + -0x3c),
                             *(undefined4 *)(extraout_ECX[0x96] + 0x10),
                             *(undefined4 *)(extraout_ECX[0x96] + 0x14)), iVar8 != 0)) {
      uVar6 = FUN_0045741b();
      FUN_004eb227(uVar6);
    }
    FUN_00464a5e(unaff_EBP + -0x10,1);
    *(undefined4 *)(unaff_EBP + 8) = 0;
    if (0 < *(int *)(unaff_EBP + -0x10)) {
      do {
        if (*(int *)(iVar2 + 0xc) == 0) {
          pvVar7 = operator_new(0x1c);
          *(void **)(unaff_EBP + -0x1c) = pvVar7;
          *(undefined1 *)(unaff_EBP + -4) = 2;
          if (pvVar7 == (void *)0x0) {
            uVar6 = 0;
          }
          else {
            uVar6 = FUN_0058364c();
          }
          *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_005873ba(unaff_EBP + -0x14);
        }
        FUN_00464c84(*(int *)(extraout_ECX[0x9d] + *(int *)(unaff_EBP + 8) * 4) + 4);
        FUN_00464c84(*(int *)(extraout_ECX[0x9d] + *(int *)(unaff_EBP + 8) * 4) + 0x10);
        if ((*(int *)(iVar2 + 0xc) == 0) && (*(char *)(unaff_EBP + 0x10) == '\0')) {
          FUN_00583714(DAT_006f6b64,*(undefined4 *)(unaff_EBP + -0x18));
        }
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
      } while (*(int *)(unaff_EBP + 8) < *(int *)(unaff_EBP + -0x10));
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  if (0x3a < *(int *)(unaff_EBP + 0xc)) {
    FUN_005b8680();
    iVar8 = *(int *)(iVar2 + 0xc);
    *(undefined4 *)(unaff_EBP + -4) = 3;
    if (iVar8 == 0) {
      FUN_00464c84(unaff_EBP + -0x2c);
      (**(code **)(*extraout_ECX + 0x8c))(extraout_ECX + 3,unaff_EBP + -0x2c);
      FUN_00464c84(unaff_EBP + -0x2c);
      (**(code **)(*extraout_ECX + 0x8c))(extraout_ECX + 0x4f,unaff_EBP + -0x2c);
      FUN_00464c84(unaff_EBP + -0x2c);
      (**(code **)(*extraout_ECX + 0x8c))(extraout_ECX + 5,unaff_EBP + -0x2c);
    }
    else {
      iVar8 = extraout_ECX[100];
      if ((((iVar8 == 0) || (iVar8 == 3)) || (iVar8 == 1)) || (iVar8 == 2)) {
        (**(code **)(*extraout_ECX + 0x88))(extraout_ECX[3],unaff_EBP + -0x2c);
      }
      else {
        FUN_005d4bbf(&DAT_006de560);
      }
      FUN_00464c84(unaff_EBP + -0x2c);
      (**(code **)(*extraout_ECX + 0x88))(extraout_ECX[0x4f],unaff_EBP + -0x2c);
      FUN_00464c84(unaff_EBP + -0x2c);
      (**(code **)(*extraout_ECX + 0x88))(extraout_ECX[5],unaff_EBP + -0x2c);
      FUN_00464c84(unaff_EBP + -0x2c);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  if (0x3c < *(int *)(unaff_EBP + 0xc)) {
    FUN_00464a4e(extraout_ECX + 100,1);
    if (*(int *)(iVar2 + 0xc) == 0) {
      iVar8 = extraout_ECX[100];
      if (((iVar8 != 0) && (iVar8 != 3)) && ((iVar8 != 1 && (iVar8 != 2)))) {
        extraout_ECX[100] = 3;
      }
    }
    FUN_00464b48(extraout_ECX + 0x84,1);
    FUN_00464b48(extraout_ECX + 0x85,1);
    FUN_00464b48(extraout_ECX + 0x86,1);
    FUN_00464b48(extraout_ECX + 0x87,1);
    FUN_00464b48(extraout_ECX + 0x88,1);
    FUN_00464b48(extraout_ECX + 0x89,1);
    FUN_00464b48(extraout_ECX + 0x23,1);
    FUN_00464b48(extraout_ECX + 0x24,1);
    FUN_00464b48(extraout_ECX + 0x25,1);
    if (*(int *)(iVar2 + 0xc) == 0) {
      FUN_004341a6(0);
      FUN_0058fafa();
      FUN_005992ca(extraout_ECX[0x2d],1,1);
      (**(code **)(*extraout_ECX + 0x60))();
      FUN_005994da(1);
      FUN_005a1444(1);
      FUN_0059076c();
      FUN_005904d6();
      FUN_005a0f1a(extraout_ECX[0x2d]);
      FUN_00590b2b();
      (**(code **)(*extraout_ECX + 0x54))(0);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

