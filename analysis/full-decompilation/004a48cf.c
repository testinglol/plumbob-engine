
undefined4 FUN_004a48cf(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(DAT_006e486c + 0x34) == 0) {
    uVar1 = 0;
  }
  else {
    if (extraout_ECX[1] == 0) {
      pvVar2 = operator_new(0x20);
      *(void **)(unaff_EBP + -0x10) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar2 == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004a5385(*(undefined4 *)(DAT_006e54d8 + 0x10));
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[1] = iVar3;
    }
    iVar3 = extraout_ECX[1];
    if ((iVar3 != 0) && (*(int *)(iVar3 + 8) == *(int *)(DAT_006e54d8 + 0x10))) {
      extraout_ECX[2] = *(int *)(iVar3 + 0xc);
    }
    *(undefined1 *)(unaff_EBP + -0x10) = 0;
    *(undefined1 *)(unaff_EBP + -0xf) = 0;
    *(undefined1 *)(unaff_EBP + -0xe) = 0;
    *(undefined1 *)(unaff_EBP + -0xd) = 0;
    FUN_004a53f5(*(undefined4 *)(unaff_EBP + -0x10));
    (**(code **)(*extraout_ECX + 0xc))();
    uVar1 = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar1;
}

