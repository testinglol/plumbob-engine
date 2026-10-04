
bool FUN_006037f7(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  bool bVar4;
  
  FUN_00634c24();
  uVar3 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x50))();
  piVar1 = (int *)(extraout_ECX + 0xac);
  *(undefined4 *)(unaff_EBP + -0x20) = uVar3;
  iVar2 = *piVar1;
  *(int **)(unaff_EBP + -0x24) = piVar1;
  *(undefined ***)(unaff_EBP + -0x28) = &PTR_LAB_00669c88;
  (**(code **)(iVar2 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
  iVar2 = *(int *)(extraout_ECX + 0x78);
  FUN_00601485(unaff_EBP + -0x18,unaff_EBP + -0x10);
  bVar4 = *(int *)(unaff_EBP + -0x18) == iVar2;
  if (bVar4) {
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 8);
    FUN_004c662a(unaff_EBP + -0x14,unaff_EBP + -0x1c);
  }
  iVar2 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar2 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return bVar4;
}

