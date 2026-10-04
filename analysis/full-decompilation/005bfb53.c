
void FUN_005bfb53(void)

{
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffff0;
  FUN_005bd7e5(*(undefined4 *)(extraout_ECX + 4));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

