
void FUN_00599cef(void)

{
  undefined4 uVar1;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0xb;
  FUN_00599e03();
  FUN_0041fb0c(*(undefined4 *)(extraout_ECX + 0x34),*(undefined4 *)(extraout_ECX + 0x38));
  FUN_0053426c(*(undefined4 *)(extraout_ECX + 0x40),*(undefined4 *)(extraout_ECX + 0x44));
  FUN_004a1827(*(undefined4 *)(extraout_ECX + 0x4c),*(undefined4 *)(extraout_ECX + 0x50));
  FUN_004a1827(*(undefined4 *)(extraout_ECX + 0x58),*(undefined4 *)(extraout_ECX + 0x5c));
  FUN_0053426c(*(undefined4 *)(extraout_ECX + 100),*(undefined4 *)(extraout_ECX + 0x68));
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_0059b01d();
  uVar1 = *(undefined4 *)(extraout_ECX + 100);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0059b360();
  uVar1 = *(undefined4 *)(extraout_ECX + 0x58);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0059b3b3();
  uVar1 = *(undefined4 *)(extraout_ECX + 0x4c);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0059b3b3();
  uVar1 = *(undefined4 *)(extraout_ECX + 0x40);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0059b360();
  uVar1 = *(undefined4 *)(extraout_ECX + 0x34);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0059b2ae();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0059b2cd();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0059aec2();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

