
int FUN_00601cec(void)

{
  int iVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  iVar2 = *(int *)(extraout_ECX + 8);
  *(int **)(unaff_EBP + -0x10) = (int *)(extraout_ECX + 8);
  (**(code **)(iVar2 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = FUN_0060783f();
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*(int *)(extraout_ECX + 4) + 4) + 8;
  }
  iVar1 = *(int *)(extraout_ECX + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2;
}

