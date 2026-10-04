
void FUN_0057312a(void)

{
  int *piVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x18) = &PTR_LAB_00669c88;
  piVar1 = *(int **)(extraout_ECX + 0x10);
  *(int **)(unaff_EBP + -0x10) = piVar1;
  iVar2 = *piVar1;
  *(int **)(unaff_EBP + -0x14) = piVar1;
  (**(code **)(iVar2 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(extraout_ECX + 8) = 0;
  if (DAT_006f63bc == '\0') {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    iVar2 = *piVar1;
  }
  else {
    piVar1 = (int *)(extraout_ECX + 0x114);
    iVar2 = *piVar1;
    if (iVar2 != 0) {
      FUN_005745d3();
      *piVar1 = 0;
      FUN_005745d3();
      *piVar1 = iVar2 + -1;
    }
    if (**(char **)(extraout_ECX + 0x14) != '\0') {
      piVar1 = (int *)(*(char **)(extraout_ECX + 0x14) + 4);
      *piVar1 = *piVar1 + 1;
    }
    FUN_0057d230();
    *(int *)(extraout_ECX + 4) = *(int *)(extraout_ECX + 4) + 1;
    if (5000 < *(uint *)(extraout_ECX + 4)) {
      FUN_0057311d();
      FUN_0057310e();
      *(undefined4 *)(extraout_ECX + 4) = 0;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    iVar2 = **(int **)(unaff_EBP + -0x10);
  }
  (**(code **)(iVar2 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

