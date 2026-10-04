
int FUN_004c9b32(void)

{
  undefined4 uVar1;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0047343b(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0047343b(0,0);
  *(undefined4 *)(extraout_ECX + 0x20) = 0;
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *(undefined4 *)(extraout_ECX + 0x24) = 1;
  *(undefined4 *)(extraout_ECX + 0x28) = DAT_006c7778;
  *(undefined4 *)(extraout_ECX + 0x2c) = 0x3f800000;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

