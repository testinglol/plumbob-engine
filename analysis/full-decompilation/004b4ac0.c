
void FUN_004b4ac0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *extraout_ECX;
  uint uVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_006687b0;
  iVar2 = extraout_ECX[10];
  piVar1 = extraout_ECX + 9;
  uVar4 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  if (iVar2 - *piVar1 >> 2 != 0) {
    do {
      if (*(int *)(*piVar1 + uVar4 * 4) != 0) {
        (**(code **)(**(int **)(*piVar1 + uVar4 * 4) + 4))();
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(extraout_ECX[10] - *piVar1 >> 2));
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0048c4c9();
  uVar3 = extraout_ECX[0xf];
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
  FUN_004d6053();
  uVar3 = extraout_ECX[0xc];
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
  FUN_004d6053();
  iVar2 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(unaff_EBP + -0x14) = iVar2;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

