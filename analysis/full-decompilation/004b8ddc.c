
void FUN_004b8ddc(void)

{
  int iVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 uVar2;
  undefined4 uVar3;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  if (iVar1 != 0) {
    *(int *)(unaff_EBP + -0x10) = iVar1;
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar2 = extraout_ECX;
    uVar3 = extraout_ECX;
    FUN_004b8e9f(unaff_EBP + -0x14);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (*(int *)(unaff_EBP + -0x10) != 0) {
      FUN_00415317(uVar2,uVar3);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

