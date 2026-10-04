
undefined4 FUN_006025b0(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  iVar1 = *(int *)(extraout_ECX + 4);
  *(int **)(unaff_EBP + -0x10) = (int *)(extraout_ECX + 4);
  (**(code **)(iVar1 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(char *)(unaff_EBP + 0xc) == '\0') {
    (**(code **)(*(int *)(extraout_ECX + 0x28) + 8))(*(undefined4 *)(unaff_EBP + 8));
  }
  else {
    (**(code **)(*(int *)(extraout_ECX + 0x28) + 4))();
  }
  iVar1 = *(int *)(extraout_ECX + 4);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

