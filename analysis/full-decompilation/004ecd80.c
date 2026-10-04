
void FUN_004ecd80(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int extraout_ECX;
  int iVar6;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(extraout_ECX + 0xf4) - *(int *)(extraout_ECX + 0xf0) >> 2 != 0) {
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    iVar1 = *(int *)(extraout_ECX + 0x114);
    iVar6 = -(*(int *)(extraout_ECX + 0x110) * iVar1);
    uVar2 = *(undefined4 *)(extraout_ECX + 0x118);
    *(int *)(unaff_EBP + -0x1c) =
         (*(int *)(extraout_ECX + 0xf4) - *(int *)(extraout_ECX + 0xf0) >> 2) * iVar1 + iVar6;
    iVar3 = *(int *)(extraout_ECX + 0xf4);
    iVar4 = *(int *)(extraout_ECX + 0xf0);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(int *)(unaff_EBP + -0x2c) = iVar6;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = uVar2;
    uVar5 = *(undefined4 *)(extraout_ECX + 0xf0);
    *(int *)(unaff_EBP + -0x24) = iVar1;
    *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    *(int *)(unaff_EBP + -0x14) = iVar1;
    FUN_004ebf01(uVar5,iVar3 - iVar4 >> 2);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

