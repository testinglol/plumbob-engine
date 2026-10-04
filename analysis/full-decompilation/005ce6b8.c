
undefined4 FUN_005ce6b8(void)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar2 = FUN_005c3650(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00462f2f(iVar2);
  uVar1 = *(undefined4 *)(iVar2 + 0x40);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x16c) = uVar1;
  FUN_005c4890();
  iVar2 = FUN_005c3650(*(undefined4 *)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00462f2f(iVar2);
  uVar1 = *(undefined4 *)(iVar2 + 0x40);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x1b0) = uVar1;
  FUN_005c4890();
  iVar2 = FUN_005c3650(*(undefined4 *)(unaff_EBP + 0x10));
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_00462f2f(iVar2);
  uVar1 = *(undefined4 *)(iVar2 + 0x40);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x128) = uVar1;
  FUN_005c4890();
  *(undefined4 *)(extraout_ECX + 0x5c) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}

