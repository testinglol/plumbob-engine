
bool FUN_00603a56(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x18) = &PTR_LAB_00669c88;
  iVar1 = *(int *)(extraout_ECX + 0xac);
  *(int **)(unaff_EBP + -0x14) = (int *)(extraout_ECX + 0xac);
  (**(code **)(iVar1 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = *(int *)(extraout_ECX + 0x78);
  FUN_00601485(unaff_EBP + -0x10,unaff_EBP + 8);
  iVar2 = *(int *)(unaff_EBP + -0x10);
  iVar3 = *(int *)(extraout_ECX + 0xac);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar3 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2 != iVar1;
}

