
undefined4 * FUN_005d033c(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005c35b0();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005c35b0();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *extraout_ECX = &PTR_FUN_006734e0;
  extraout_ECX[1] = uVar1;
  uVar1 = *(undefined4 *)(unaff_EBP + 0x10);
  uVar2 = **(undefined4 **)(unaff_EBP + 0x14);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  extraout_ECX[0x2f] = uVar2;
  uVar2 = *(undefined4 *)(unaff_EBP + 0xc);
  extraout_ECX[0x30] = **(undefined4 **)(unaff_EBP + 0x18);
  extraout_ECX[0x31] = **(undefined4 **)(unaff_EBP + 0x1c);
  FUN_005d0422(uVar2,uVar1);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0x32] = 0;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

