
int FUN_00594f5f(void)

{
  undefined4 uVar1;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(extraout_ECX + 0xc) = 0;
  FUN_005b8680();
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *(undefined4 *)(extraout_ECX + 0x1c) = 0;
  *(undefined4 *)(extraout_ECX + 0x20) = 0;
  *(undefined4 *)(extraout_ECX + 0x24) = 0;
  *(undefined4 *)(extraout_ECX + 0x28) = 0;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

