
undefined4 FUN_00603b2a(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 uVar2;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x18) = &PTR_LAB_00669c88;
  iVar1 = *(int *)(extraout_ECX + 0xac);
  *(int **)(unaff_EBP + -0x14) = (int *)(extraout_ECX + 0xac);
  (**(code **)(iVar1 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00601485(unaff_EBP + -0x10,unaff_EBP + 8);
  if (*(int *)(unaff_EBP + -0x10) == *(int *)(extraout_ECX + 0x78)) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x14);
  }
  iVar1 = *(int *)(extraout_ECX + 0xac);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

