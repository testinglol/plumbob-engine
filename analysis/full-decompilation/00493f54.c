
undefined4 * FUN_00493f54(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *_Dst;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_00492f28();
  _Dst = extraout_ECX + 9;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0x1000;
  do {
    _memset(_Dst,0,0xe);
    _Dst = (undefined4 *)((int)_Dst + 0xe);
    piVar1 = (int *)(unaff_EBP + -0x10);
    *piVar1 = *piVar1 + -1;
  } while (*piVar1 != 0);
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)((int)extraout_ECX + 0xe02e) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xe032) = 0;
  extraout_ECX[0x3811] = uVar2;
  *(undefined1 *)((int)extraout_ECX + 0xe04a) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xe04d) = 0;
  *extraout_ECX = &PTR_FUN_006681f4;
  extraout_ECX[0x3817] = 0;
  extraout_ECX[0x3816] = 0;
  *(undefined1 *)(extraout_ECX + 0x3809) = 0;
  extraout_ECX[0x380a] = 0;
  *(undefined1 *)(extraout_ECX + 0x3818) = 0;
  extraout_ECX[0x3814] = 0;
  extraout_ECX[0x3815] = 0;
  return extraout_ECX;
}

