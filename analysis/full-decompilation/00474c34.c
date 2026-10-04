
undefined4 FUN_00474c34(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  int unaff_ESI;
  
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_ESI + 4) = uVar1;
  DAT_006c4d5c = *(undefined1 *)(unaff_EBP + 0x13);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT31((int3)((uint)uVar1 >> 8),*(undefined1 *)(unaff_EBP + 0xf));
}

