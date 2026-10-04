
undefined4 * FUN_005c858c(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005cb594(*(undefined4 *)(unaff_EBP + 8));
  puVar1 = (undefined4 *)extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[2] = 0;
  *extraout_ECX = &PTR_FUN_00673464;
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = (**(code **)*puVar1)(puVar1,&DAT_00677308,extraout_ECX + 2);
    if (iVar2 < 0) {
      extraout_ECX[2] = 0;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

