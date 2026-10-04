
void FUN_005a385a(void)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 uVar3;
  
  FUN_00634c24();
  uVar1 = FUN_00412ab1(unaff_EBP + -0x28,extraout_ECX + 0x10,extraout_ECX + 0x1c);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b86bd(uVar1);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00401729();
  uVar3 = 0;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x1c);
  FUN_005b8e25(uVar1,0);
  iVar2 = FUN_005b936f(uVar1,uVar3);
  *(int *)(unaff_EBP + -0x10) = iVar2;
  if (iVar2 != 0) {
    DAT_006f766c = 1;
    FUN_0059e499(extraout_ECX + 0x10,extraout_ECX + 0x1c,*(undefined4 *)(extraout_ECX + 0x28));
    uVar1 = *(undefined4 *)(unaff_EBP + -0x10);
    DAT_006f766c = 0;
    FUN_005b8e25(uVar1);
    FUN_005b95c0(uVar1);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined1 *)(extraout_ECX + 0x2c) = 1;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

