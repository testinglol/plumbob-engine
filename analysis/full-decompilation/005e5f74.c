
undefined4 * FUN_005e5f74(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005e69c2(iVar1 + 4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005e69c2(iVar1 + 0x10);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b86bd(iVar1 + 0x1c);
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 10) = *(undefined1 *)(iVar1 + 0x28);
  *extraout_ECX = &PTR_FUN_00674344;
  *unaff_FS_OFFSET = uVar2;
  return extraout_ECX;
}

