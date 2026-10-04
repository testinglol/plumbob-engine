
undefined1 FUN_00578877(void)

{
  int iVar1;
  undefined1 uVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = DAT_006f63e8;
  *(int **)(unaff_EBP + -0x10) = &DAT_006f63e8;
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  (**(code **)(iVar1 + 4))();
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar2 = (**(code **)(iVar1 + 0x70))(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(DAT_006f63e8 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

