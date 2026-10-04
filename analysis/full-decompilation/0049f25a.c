
undefined4 * FUN_0049f25a(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  int iVar3;
  bool bVar4;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  iVar3 = 0;
  *extraout_ECX = &PTR_FUN_00668660;
  bVar4 = DAT_006efbd8 == '\0';
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (bVar4) {
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x18) = 0xff;
    *(undefined4 *)(unaff_EBP + -0x14) = 0x400;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = 0xff;
    *(undefined4 *)(unaff_EBP + -0x20) = 0x200;
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
    *(undefined4 *)(unaff_EBP + -0x30) = 0xff;
    *(undefined4 *)(unaff_EBP + -0x2c) = 0x100;
    do {
      uVar2 = FUN_0049f360();
      uVar1 = FUN_00636bef(uVar2);
      (&DAT_006eefd8)[iVar3] = uVar1;
      uVar2 = FUN_0049f360();
      uVar1 = FUN_00636bef(uVar2);
      (&DAT_006ef3d8)[iVar3] = uVar1;
      uVar2 = FUN_0049f360();
      uVar1 = FUN_00636bef(uVar2);
      (&DAT_006ef7d8)[iVar3] = uVar1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x400);
    DAT_006efbd8 = '\x01';
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[2] = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(extraout_ECX + 3) = *(undefined1 *)(unaff_EBP + 0xc);
  extraout_ECX[1] = 0;
  return extraout_ECX;
}

