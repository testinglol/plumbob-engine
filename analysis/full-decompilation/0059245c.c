
void FUN_0059245c(void)

{
  undefined4 uVar1;
  size_t sVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar1 = FUN_004705f2(4,0xffffffff);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  uVar1 = FUN_004705f2(5,0xffffffff);
  *(undefined4 *)(unaff_EBP + 8) = uVar1;
  uVar1 = FUN_004705f2(6,0xffffffff);
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar1;
  uVar1 = FUN_004705f2(7,0xffffffff);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar1;
  *(char **)(unaff_EBP + -0x18) = s_HeadFake_006d1a3c;
  if (*(int *)(unaff_EBP + 8) != 0) {
    sVar2 = _strlen(*(char **)(unaff_EBP + 8));
    if (sVar2 == 0) {
      *(undefined4 *)(unaff_EBP + 8) = 0;
    }
  }
  if (*(int *)(unaff_EBP + -0x10) != 0) {
    sVar2 = _strlen(*(char **)(unaff_EBP + -0x10));
    if (sVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
    }
  }
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    sVar2 = _strlen(*(char **)(unaff_EBP + -0x14));
    if (sVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
    }
  }
  uVar1 = FUN_005b870f(*(undefined4 *)(unaff_EBP + -0x14));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar1 = FUN_005a14b9(uVar1,*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(extraout_ECX + 0x144) = uVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  uVar1 = FUN_005b870f(*(undefined4 *)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  uVar1 = FUN_005a14b9(uVar1,*(undefined4 *)(unaff_EBP + -0x10));
  *(undefined4 *)(extraout_ECX + 0x140) = uVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  uVar1 = FUN_005b870f(s_PELVIS_006c459c);
  *(undefined4 *)(unaff_EBP + -4) = 2;
  uVar1 = FUN_005a14b9(uVar1,0);
  *(undefined4 *)(extraout_ECX + 0x148) = uVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  uVar1 = FUN_005b870f(*(undefined4 *)(unaff_EBP + -0x14));
  *(undefined4 *)(unaff_EBP + -4) = 3;
  uVar1 = FUN_005a14b9(uVar1,*(undefined4 *)(unaff_EBP + -0x18));
  *(undefined4 *)(extraout_ECX + 0x14c) = uVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

