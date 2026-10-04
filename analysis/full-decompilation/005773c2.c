
void FUN_005773c2(void)

{
  int iVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = DAT_006f63e8;
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  *(int **)(unaff_EBP + -0x10) = &DAT_006f63e8;
  (**(code **)(iVar1 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = *extraout_ECX + 1;
  if (*extraout_ECX == 1) {
    *(undefined1 *)(extraout_ECX + 10) = 0;
    if ((int *)extraout_ECX[3] != (int *)0x0) {
      (**(code **)(*(int *)extraout_ECX[3] + 0x18))();
    }
  }
  iVar1 = DAT_006f63e8;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

