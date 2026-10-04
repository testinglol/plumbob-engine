
int FUN_005bab42(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  uVar1 = FUN_005babc6();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 8));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005bad33(uVar1);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  iVar2 = FUN_005bb94c(unaff_EBP + -0x44);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005ba44c();
  *(undefined4 *)(unaff_EBP + -4) = 3;
  FUN_005bb5f0();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005481b6();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar2 + 0xc;
}

