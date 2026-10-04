
void FUN_004cb98c(void)

{
  char cVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00668b68;
  iVar2 = extraout_ECX[8];
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if (iVar2 != 0) {
    cVar1 = FUN_005da398(iVar2);
    if (cVar1 != '\0') {
      iVar2 = (**(code **)(*(int *)extraout_ECX[8] + 0x18))();
      if (iVar2 == 0) {
        FUN_005da4c7(extraout_ECX[8]);
      }
    }
  }
  FUN_005a5e48(0);
  FUN_005a5e48(0);
  FUN_005a5e48(0);
  FUN_005a5e48(0);
  if (extraout_ECX[10] != 0) {
    FUN_0045804b(0);
  }
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005a5e09();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00635f6d(extraout_ECX + 0xc,4,2,FUN_005a5e09);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005a5e09();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

