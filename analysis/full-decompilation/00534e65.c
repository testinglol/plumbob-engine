
void FUN_00534e65(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_2c [36];
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x534e6f;
  FUN_00634c24();
  uStack_4 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uStack_8 = 0x534e7e;
  FUN_00533dae();
  uStack_4 = *(undefined4 *)(unaff_EBP + 0x3c);
  *(undefined1 **)(unaff_EBP + 0x10) = auStack_2c;
  FUN_00533d58(unaff_EBP + 0x14);
  FUN_00534fbf(*(undefined4 *)(unaff_EBP + 8),0,
               (*(int *)(unaff_EBP + 0xc) - *(int *)(unaff_EBP + 8)) / 0x28);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uStack_4 = 0x534eb8;
  FUN_005b8770();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

