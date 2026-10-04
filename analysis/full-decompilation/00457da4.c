
undefined4 FUN_00457da4(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (extraout_ECX[0x24] == 0) {
    pvVar1 = operator_new(0xc);
    *(void **)(unaff_EBP + -0x10) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_0045616c();
    }
    iVar3 = extraout_ECX[0x2d];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x24] = uVar2;
    iVar3 = FUN_004563fd(*extraout_ECX,iVar3 >> 0x10);
    if (iVar3 == -0x62) {
      FUN_00456209(extraout_ECX[0x18]);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX[0x24];
}

