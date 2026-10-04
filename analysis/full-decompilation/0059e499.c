
undefined4 FUN_0059e499(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  uVar2 = FUN_00412ab1(unaff_EBP + -0x30,*(undefined4 *)(unaff_EBP + 8),
                       *(undefined4 *)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b86bd(uVar2);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00401729();
  iVar3 = *(int *)(unaff_EBP + -0x20);
  iVar1 = *(int *)(unaff_EBP + -0x24);
  FUN_005c32ce();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005c22bb();
  iVar3 = FUN_00646330((iVar3 - iVar1) + -4 + iVar1,&DAT_006d1d5c);
  if (iVar3 == 0) {
    FUN_0047354f(0);
    uVar2 = FUN_00401f77();
    FUN_00476033(1);
    uVar4 = FUN_005c21b3(unaff_EBP + -0x50,*(undefined4 *)(unaff_EBP + -0x24));
    *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
    FUN_00476033(uVar2);
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      uVar7 = 0;
      uVar6 = 0;
      uVar5 = 0;
      uVar2 = *(undefined4 *)(unaff_EBP + 0x10);
      uVar4 = FUN_00401f73(uVar2,0,0,0);
      iVar3 = FUN_0059e5d1(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),uVar4,
                           uVar2,uVar5,uVar6,uVar7);
LAB_0059e59a:
      if (iVar3 == 0) goto LAB_0059e5a5;
    }
  }
  else {
    FUN_0047354f(1);
    iVar3 = FUN_005c21b3(unaff_EBP + -0x50,*(undefined4 *)(unaff_EBP + -0x24));
    if (iVar3 == 0) {
      uVar5 = 0;
      uVar2 = *(undefined4 *)(unaff_EBP + 0x10);
      uVar4 = FUN_00401f73(uVar2,0);
      iVar3 = FUN_0059ef12(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),uVar4,
                           uVar2,uVar5);
      goto LAB_0059e59a;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x14) = 1;
LAB_0059e5a5:
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005c3314();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  uVar2 = *(undefined4 *)(unaff_EBP + -0x14);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}

