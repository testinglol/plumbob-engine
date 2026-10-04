
undefined4 FUN_005d04ff(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  FUN_005c35b0();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar1 = FUN_00462f96(unaff_EBP + -0x1a8,extraout_ECX + 0xa8);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar2 = FUN_005c38c0(unaff_EBP + -0x120,1,extraout_ECX + 0xb4);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar2 = FUN_005c38c0(unaff_EBP + -0xdc,0,extraout_ECX + 0xb8);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  uVar2 = FUN_0049b9e6(unaff_EBP + -0x98,uVar2,*(undefined4 *)(unaff_EBP + -0x10));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  iVar3 = FUN_0049b9e6(unaff_EBP + -0x164,uVar2,uVar1);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_00462f2f(iVar3);
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar3 + 0x40);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005c4890();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005c4890();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005c4890();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005c4890();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005c4890();
  uVar1 = FUN_005d061b(unaff_EBP + -0x54);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar1;
}

