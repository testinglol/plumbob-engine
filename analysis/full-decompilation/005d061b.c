
void FUN_005d061b(void)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  iVar2 = *(int *)(unaff_EBP + 8);
  FUN_00462f2f(iVar2);
  *(undefined4 *)(extraout_ECX + 0x48) = *(undefined4 *)(iVar2 + 0x40);
  iVar2 = FUN_0049b967(unaff_EBP + -0x50);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00462f2f(iVar2);
  uVar1 = *(undefined4 *)(iVar2 + 0x40);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x8c) = uVar1;
  FUN_005c4890();
  FUN_005ce90a(extraout_ECX + 0x4c,extraout_ECX);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

