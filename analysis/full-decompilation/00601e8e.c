
bool FUN_00601e8e(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  iVar3 = *(int *)(extraout_ECX + 8);
  *(int **)(unaff_EBP + -0x10) = (int *)(extraout_ECX + 8);
  (**(code **)(iVar3 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar3 = FUN_0060783f();
  if (iVar3 != 0) {
    puVar1 = *(undefined4 **)(unaff_EBP + 8);
    iVar2 = **(int **)(extraout_ECX + 4);
    *puVar1 = *(undefined4 *)(iVar2 + 8);
    puVar1[1] = *(undefined4 *)(iVar2 + 0xc);
    puVar1[2] = *(undefined4 *)(iVar2 + 0x10);
    puVar1[3] = *(undefined4 *)(iVar2 + 0x14);
    FUN_00602869();
  }
  iVar2 = *(int *)(extraout_ECX + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar2 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar3 != 0;
}

