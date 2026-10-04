
void FUN_00511d39(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 uVar5;
  undefined4 uVar6;
  
  FUN_00634c24();
  if (DAT_006f38b0 == 0) {
    uVar2 = FUN_004ecf2e();
    uVar3 = FUN_00511a2d(unaff_EBP + -0x34,uVar2);
    piVar1 = *(int **)(extraout_ECX + 0x110);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    (**(code **)(*piVar1 + 0x9c))(uVar3);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    FUN_00511b02(unaff_EBP + -0x4c,uVar2);
    uVar2 = 1;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    uVar6 = 1;
    uVar5 = 0;
    uVar3 = FUN_004096c2(0,1);
    FUN_005f436c(uVar3,uVar5,uVar6);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    *(undefined4 *)(extraout_ECX + 0x13c) = 0;
  }
  else {
    if (DAT_006f38b0 == 1) {
      uVar2 = FUN_004ecf2e();
      *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
      uVar2 = FUN_00511851(unaff_EBP + -0x1c,uVar2);
      piVar1 = *(int **)(extraout_ECX + 0x110);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      (**(code **)(*piVar1 + 0x9c))(uVar2);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      FUN_0051193f(unaff_EBP + -0x28,*(undefined4 *)(unaff_EBP + -0x10));
      uVar5 = 1;
      uVar3 = 0;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      uVar2 = FUN_004096c2(0,1);
      FUN_005f436c(uVar2,uVar3,uVar5);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      if (*(int *)(unaff_EBP + -0x10) < 0xc) {
        *(undefined4 *)(extraout_ECX + 0x13c) = 1;
      }
      else {
        *(undefined4 *)(extraout_ECX + 0x13c) = 2;
      }
      *(undefined4 *)(extraout_ECX + 0x140) = 0;
      goto LAB_00511f0f;
    }
    if (DAT_006f38b0 != 2) goto LAB_00511f0f;
    uVar2 = FUN_004ecf2e();
    *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
    uVar3 = FUN_00511bd7(unaff_EBP + -0x40,uVar2);
    uVar2 = 4;
    iVar4 = **(int **)(extraout_ECX + 0x110);
    *(undefined4 *)(unaff_EBP + -4) = 4;
    (**(code **)(iVar4 + 0x9c))(uVar3);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    FUN_00511c88(unaff_EBP + -0x58,*(undefined4 *)(unaff_EBP + -0x10));
    uVar6 = 1;
    uVar5 = 0;
    *(undefined4 *)(unaff_EBP + -4) = 5;
    uVar3 = FUN_004096c2(0,1);
    FUN_005f436c(uVar3,uVar5,uVar6);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    if (4 < *(int *)(unaff_EBP + -0x10)) {
      *(undefined4 *)(extraout_ECX + 0x13c) = 3;
      *(undefined4 *)(extraout_ECX + 0x140) = 3;
      goto LAB_00511f0f;
    }
    *(undefined4 *)(extraout_ECX + 0x13c) = 4;
  }
  *(undefined4 *)(extraout_ECX + 0x140) = uVar2;
LAB_00511f0f:
  uVar2 = *(undefined4 *)(*(int *)(extraout_ECX + 0x460) + 0xd8);
  iVar4 = *(int *)(*(int *)(extraout_ECX + 0x460) + 0xd4) + 1;
  uVar3 = FUN_004705f2(5,0xffffffff);
  FUN_00635858(unaff_EBP + -0x458,uVar3,iVar4,uVar2);
  (**(code **)(**(int **)(extraout_ECX + 0x454) + 0x1a0))(unaff_EBP + -0x458);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

