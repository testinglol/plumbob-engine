
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058da16(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *extraout_ECX;
  uint uVar5;
  char cVar6;
  int unaff_EBP;
  undefined4 uVar7;
  
  FUN_00634c24();
  cVar6 = '\x01';
  if ((*(char *)(unaff_EBP + 8) == '\0') ||
     (cVar6 = *(char *)((int)extraout_ECX + 0x109), cVar6 != '\0')) {
    iVar2 = (**(code **)(*extraout_ECX + 0x34))();
    iVar4 = extraout_ECX[4];
    extraout_ECX[0x2d] = iVar2;
    if ((iVar4 != 0) && (ABS(*(float *)(iVar4 + 0x2c)) <= _DAT_0067343c)) {
      FUN_005a0903(iVar4);
      extraout_ECX[4] = 0;
    }
    FUN_004341a6(0);
    if (extraout_ECX[0x95] != (int)*(short *)(extraout_ECX[0x4e] + 0x5c8)) {
      cVar6 = '\x01';
    }
    FUN_0058fafa();
    FUN_005992ca(extraout_ECX[0x2d],cVar6,1);
    (**(code **)(*extraout_ECX + 0x60))();
    FUN_005994da(1);
    FUN_005a1444(1);
    FUN_0059076c();
    FUN_005904d6();
    FUN_00590b2b();
    iVar4 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + 8) = 0;
    if ((*(int *)(iVar4 + 0x134) - *(int *)(iVar4 + 0x130)) / 0x24 + -1 < 2) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar4 + 0x130) + 0x48;
    }
    if (iVar2 != 0) {
      *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(iVar2 + 0x20);
    }
    if ((*(int *)(iVar4 + 0x134) - *(int *)(iVar4 + 0x130)) / 0x24 + -1 < 2) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar4 + 0x130) + 0x48;
    }
    if (iVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
    }
    else {
      uVar5 = (uint)*(short *)(iVar2 + 0x10);
      iVar4 = *(int *)(iVar4 + 0xdc);
      uVar7 = 0;
      if ((0 < (int)uVar5) && (uVar5 < (*(int *)(iVar4 + 0x1c) - *(int *)(iVar4 + 0x18) >> 2) + 1U))
      {
        uVar7 = *(undefined4 *)(*(int *)(iVar4 + 0x18) + -4 + uVar5 * 4);
      }
      *(undefined4 *)(unaff_EBP + -0x10) = uVar7;
    }
    if (*(int **)(unaff_EBP + -0x10) != (int *)0x0) {
      piVar3 = (int *)(**(code **)(**(int **)(unaff_EBP + -0x10) + 0x2c))();
      if (*(int *)(unaff_EBP + 8) != 0) {
        FUN_005c35b0();
        iVar4 = *extraout_ECX;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        iVar4 = (**(code **)(iVar4 + 0xac))();
        if (iVar4 != 0) {
          FUN_005b870f(*(undefined4 *)(unaff_EBP + 8));
          *(undefined1 *)(unaff_EBP + -4) = 1;
          iVar4 = FUN_005990f7(unaff_EBP + -0x1c);
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_005b8770();
          if (iVar4 != 0) {
            *(undefined4 *)(unaff_EBP + -0x20) = 0;
            *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(iVar4 + 0x4c);
            *(undefined4 *)(unaff_EBP + -0x20) = 0;
            uVar7 = *(undefined4 *)(iVar4 + 0x50);
            *(undefined4 *)(unaff_EBP + -0x20) = 0;
            *(undefined4 *)(unaff_EBP + -0x2c) = uVar7;
            *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(iVar4 + 0x54);
            uVar7 = (**(code **)(*extraout_ECX + 0xb0))();
            FUN_00462c01(uVar7);
          }
        }
        (**(code **)(*piVar3 + 0xac))();
        (**(code **)(*piVar3 + 100))(1);
        (**(code **)(*piVar3 + 0xb8))(unaff_EBP + -0x60);
        FUN_0045d283(3);
        iVar4 = __ftol();
        piVar1 = *(int **)(unaff_EBP + -0x10);
        *(undefined4 *)(unaff_EBP + -0x18) = 0;
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        piVar3[0x40] = iVar4;
        (**(code **)(*piVar1 + 0x78))(unaff_EBP + -0x18);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005c4890();
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

