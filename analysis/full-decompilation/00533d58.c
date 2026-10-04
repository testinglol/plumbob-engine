
int FUN_00533d58(void)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005d48d9();
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d499c(iVar1);
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  *(undefined4 *)(extraout_ECX + 0x10) = *(undefined4 *)(iVar1 + 0x10);
  *(undefined4 *)(extraout_ECX + 0x14) = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 *)(extraout_ECX + 0x18) = *(undefined4 *)(iVar1 + 0x18);
  *(undefined4 *)(extraout_ECX + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
  *(undefined4 *)(extraout_ECX + 0x20) = *(undefined4 *)(iVar1 + 0x20);
  *unaff_FS_OFFSET = uVar2;
  return extraout_ECX;
}

