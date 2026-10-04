
void FUN_00584a60(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *extraout_ECX;
  uint uVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_00671d6c;
  *(undefined4 *)(unaff_EBP + -4) = 6;
  FUN_00584b40();
  if (DAT_006f6b5c == extraout_ECX[1]) {
    DAT_006f6b5c = 0;
  }
  FUN_00584db6();
  piVar1 = extraout_ECX + 0x30;
  uVar4 = 0;
  if (extraout_ECX[0x31] - *piVar1 >> 2 != 0) {
    do {
      iVar2 = *(int *)(*piVar1 + uVar4 * 4);
      *(int *)(unaff_EBP + -0x10) = iVar2;
      if (iVar2 != 0) {
        FUN_005836d2();
        FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x10));
      }
      *(undefined4 *)(*piVar1 + uVar4 * 4) = 0;
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(extraout_ECX[0x31] - *piVar1 >> 2));
  }
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005b8770();
  uVar3 = extraout_ECX[0x33];
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
  FUN_0048c4c9();
  iVar2 = *piVar1;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(int *)(unaff_EBP + -0x10) = iVar2;
  FUN_0048c4c9();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005c4890();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

