
undefined4 * FUN_00603243(void)

{
  undefined4 uVar1;
  void *_Dst;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_00676b88;
  FUN_005d58d8(0xffd23940);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(extraout_ECX + 0x13) = 1;
  *(undefined1 *)((int)extraout_ECX + 0x4d) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x4e) = 1;
  extraout_ECX[0x14] = 0;
  extraout_ECX[0x16] = 0;
  extraout_ECX[0x17] = 0;
  extraout_ECX[0x18] = 0x10;
  extraout_ECX[0x19] = 0x5622;
  extraout_ECX[0x1a] = 2;
  extraout_ECX[0x1c] = 0;
  extraout_ECX[0x1d] = 0;
  FUN_005d5fbc(unaff_EBP + -0xe,unaff_EBP + -0xd);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  extraout_ECX[0x24] = 0;
  extraout_ECX[0x26] = 0;
  extraout_ECX[0x22] = 1;
  extraout_ECX[0x25] = 0;
  extraout_ECX[0x27] = 0;
  uVar1 = FUN_005fd96f();
  extraout_ECX[0x28] = uVar1;
  extraout_ECX[0x2a] = 0xffffffff;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d909f();
  extraout_ECX[0x34] = 0;
  extraout_ECX[0x35] = 0;
  extraout_ECX[0x36] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *extraout_ECX = &PTR_FUN_00676acc;
  extraout_ECX[1] = &PTR_LAB_00676ab4;
  extraout_ECX[2] = &PTR_LAB_00676aa8;
  extraout_ECX[3] = &PTR_FUN_00676a90;
  extraout_ECX[5] = &PTR_LAB_00676a88;
  _Dst = operator_new(0x60);
  extraout_ECX[0x15] = _Dst;
  _memset(_Dst,0,0x60);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined4 *)extraout_ECX[0x15] = 0x60;
  DAT_006fecc4 = extraout_ECX;
  return extraout_ECX;
}

