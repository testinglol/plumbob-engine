
bool FUN_00602220(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  uint uVar2;
  int *piVar3;
  bool bVar4;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_LAB_00669c88;
  uVar2 = -(uint)(extraout_ECX != 0x48) & extraout_ECX - 0x38U;
  iVar1 = *(int *)(uVar2 + 4);
  piVar3 = (int *)(uVar2 + 4);
  *(int **)(unaff_EBP + -0x18) = piVar3;
  (**(code **)(iVar1 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = *(int *)(extraout_ECX + 8);
  FUN_005e76d4(unaff_EBP + -0x10,unaff_EBP + 8);
  bVar4 = *(int *)(unaff_EBP + -0x10) == iVar1;
  if (bVar4) {
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + 0xc);
    FUN_00602b14(unaff_EBP + -0x24,unaff_EBP + -0x14);
  }
  iVar1 = *piVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return bVar4;
}

