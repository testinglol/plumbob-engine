
void FUN_0041f4e7(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int extraout_ECX;
  uint uVar4;
  int unaff_EBP;
  int iVar5;
  
  FUN_00634c24();
  iVar5 = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  iVar2 = *(int *)(extraout_ECX + 8);
  piVar1 = (int *)(extraout_ECX + 4);
  uVar4 = 0;
  iVar3 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((iVar2 - iVar3) / 0xc != 0) {
    do {
      if (*(int *)(iVar5 + *piVar1) != *(int *)(unaff_EBP + 8)) {
        FUN_0041f7ca(*piVar1 + iVar5);
      }
      uVar4 = uVar4 + 1;
      iVar5 = iVar5 + 0xc;
    } while (uVar4 < (uint)((*(int *)(extraout_ECX + 8) - *piVar1) / 0xc));
  }
  FUN_0041f957(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004d6053();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

