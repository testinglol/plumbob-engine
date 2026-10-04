
void FUN_004cac05(void)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int *piVar4;
  int extraout_ECX;
  int iVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005a5e48(0);
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined1 *)(extraout_ECX + 0xf0) = 0;
  *(undefined1 *)(extraout_ECX + 0xf1) = 0;
  *(undefined4 *)(extraout_ECX + 0x100) = 0;
  *(undefined4 *)(extraout_ECX + 0xfc) = 0;
  *(undefined4 *)(extraout_ECX + 0xf8) = 0;
  *(undefined4 *)(extraout_ECX + 0xf4) = 0;
  *(undefined1 *)(extraout_ECX + 0x104) = 0;
  *(undefined1 *)(extraout_ECX + 0x105) = 0;
  *(undefined4 *)(extraout_ECX + 0x108) = 0;
  *(undefined4 *)(extraout_ECX + 0x10c) = 0;
  *(undefined4 *)(extraout_ECX + 0x110) = 6;
  *(undefined4 *)(extraout_ECX + 0x114) = 1;
  *(undefined4 *)(extraout_ECX + 0x118) = 0;
  *(undefined4 *)(extraout_ECX + 0x11c) = 0;
  *(undefined1 *)(extraout_ECX + 0x120) = 1;
  if (puVar1 == (undefined4 *)0x0) {
    FUN_004cb0b0(0);
    *(undefined4 *)(extraout_ECX + 0x108) = 0;
    uVar3 = FUN_005d4956(&DAT_006de560);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005dd9c8(uVar3);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  else {
    uVar3 = FUN_004096c2();
    FUN_004cb0b0(uVar3);
    uVar3 = FUN_004e89f3();
    *(undefined4 *)(extraout_ECX + 0x108) = uVar3;
    uVar2 = FUN_004e8a07();
    *(undefined1 *)(extraout_ECX + 0xf1) = uVar2;
    *(undefined4 *)(extraout_ECX + 0x10c) = *puVar1;
    piVar4 = (int *)FUN_004e8a14(0);
    iVar5 = piVar4[1] - *piVar4;
    FUN_004e8a14(0);
    uVar3 = FUN_004096c2(iVar5);
    uVar3 = FUN_005d4916(uVar3,iVar5);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_005dd9c8(uVar3);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

