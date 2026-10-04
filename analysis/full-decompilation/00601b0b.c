
undefined4 FUN_00601b0b(void)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  undefined1 *puStack_24;
  undefined4 uStack_20;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_LAB_00669c88;
  iVar1 = *(int *)(extraout_ECX + 8);
  *(int **)(unaff_EBP + -0x18) = (int *)(extraout_ECX + 8);
  uStack_20 = 0x601b32;
  (**(code **)(iVar1 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uStack_20 = 0x601b40;
  uVar2 = FUN_0060783f();
  puStack_24 = (undefined1 *)&uStack_20;
  uStack_20 = *(undefined4 *)(extraout_ECX + 4);
  *(undefined4 **)(unaff_EBP + -0x10) = &uStack_20;
  *(undefined1 ***)(unaff_EBP + -0x10) = &puStack_24;
  FUN_00602902(&puStack_24);
  FUN_00602a49(unaff_EBP + -0x14);
  iVar1 = *(int *)(extraout_ECX + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uStack_20 = 0x601b70;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

