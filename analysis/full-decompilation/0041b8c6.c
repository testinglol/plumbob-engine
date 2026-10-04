
undefined4 FUN_0041b8c6(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_00575b11(unaff_EBP + -0x20,unaff_EBP + -0x18);
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    FUN_0041d852(100,unaff_EBP + -0x12,unaff_EBP + -0x11,unaff_EBP + 0xb);
    *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0041d840(unaff_EBP + -0x74);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0041d985(unaff_EBP + -0x2c,unaff_EBP + -0x4c);
    *(int *)(unaff_EBP + -0x5c) = unaff_EBP + -0x48;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_0041dffb();
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005481b6();
    *(undefined4 *)(unaff_EBP + -4) = 3;
    FUN_0041dffb();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005481b6();
    if (*(char *)(unaff_EBP + -0x24) != '\0') {
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x2c);
      *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x28);
    }
    if (*(int *)(unaff_EBP + -0x20) == 0) goto LAB_0041ba14;
  }
  iVar1 = *(int *)(unaff_EBP + -0x20);
  uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
  uVar2 = *(undefined4 *)(unaff_EBP + 0x10);
  *(short *)(unaff_EBP + 0xc) = (short)uVar3;
  *(char *)(unaff_EBP + 0xe) = (char)uVar2;
  FUN_0041d8f0(unaff_EBP + -0x34,unaff_EBP + 0xc);
  iVar4 = *(int *)(unaff_EBP + -0x34);
  if (iVar4 == 0) {
    uVar3 = FUN_0041ba28(uVar3,uVar2,*(undefined4 *)(unaff_EBP + 0x14));
    *(undefined2 *)(unaff_EBP + -0xd4) = *(undefined2 *)(unaff_EBP + 0xc);
    *(undefined1 *)(unaff_EBP + -0xd2) = *(undefined1 *)(unaff_EBP + 0xe);
    FUN_0041ba73(uVar3);
    FUN_0041decf(*(int *)(iVar1 + 0x18) + 1);
    FUN_0041ddf9(unaff_EBP + -0x58,unaff_EBP + -0xd4);
    if (*(char *)(unaff_EBP + -0x50) == '\0') goto LAB_0041ba14;
    iVar4 = *(int *)(unaff_EBP + -0x58);
  }
  *(int *)(unaff_EBP + -0x10) = iVar4 + 7;
LAB_0041ba14:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x10);
}

