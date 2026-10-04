
undefined1 * FUN_005babc6(void)

{
  undefined1 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x14) = extraout_ECX;
  *extraout_ECX = *(undefined1 *)(unaff_EBP + -0xd);
  extraout_ECX[1] = *(undefined1 *)(unaff_EBP + -0xd);
  extraout_ECX[2] = *(undefined1 *)(unaff_EBP + -0xd);
  *(undefined4 *)(extraout_ECX + 4) = 0;
  *(undefined4 *)(extraout_ECX + 8) = 0;
  *(undefined4 *)(extraout_ECX + 0xc) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(extraout_ECX + 0x10) = 0;
  FUN_005badd7(100);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

