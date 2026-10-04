
undefined4 FUN_004ce4a9(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(extraout_ECX + 0x58) == 0) {
    pvVar1 = operator_new(0x14);
    *(void **)(unaff_EBP + -0x10) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_004cd130(extraout_ECX);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(extraout_ECX + 0x58) = uVar2;
    FUN_004cd2d8(*(undefined4 *)(DAT_006e486c + 0x28));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(extraout_ECX + 0x58);
}

