
undefined4 FUN_00602702(void)

{
  int iVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x18) = &PTR_LAB_00669c88;
  iVar1 = *(int *)(extraout_ECX + 4);
  *(int **)(unaff_EBP + -0x14) = (int *)(extraout_ECX + 4);
  (**(code **)(iVar1 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005e76d4(unaff_EBP + -0x10,unaff_EBP + 0xc);
  if (*(int *)(unaff_EBP + -0x10) != *(int *)(extraout_ECX + 0x90)) {
    iVar1 = *(int *)(*(int *)(unaff_EBP + -0x10) + 0x14);
    FUN_005de7e8(unaff_EBP + 8);
    iVar2 = FUN_0060783f();
    if (iVar2 == 0) {
      if (iVar1 != 0) {
        FUN_006029b3();
        FUN_006321f0(iVar1);
      }
      FUN_00602bf9(unaff_EBP + 0xc);
    }
  }
  iVar1 = *(int *)(extraout_ECX + 4);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

