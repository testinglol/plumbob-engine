
uint FUN_005e9006(void)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + 8) == 1) {
    iVar1 = *(int *)(unaff_EBP + 0xc);
    cVar2 = (**(code **)(*extraout_ECX + 0x38))(iVar1);
    if (cVar2 != '\0') {
      if (*(int *)(iVar1 + 8) == 0) {
        FUN_005dac30(0x10,extraout_ECX,0);
      }
      else {
        (*(code *)extraout_ECX[0x3f])(1,iVar1,extraout_ECX[0x40]);
      }
    }
  }
  else if ((code *)extraout_ECX[0x3f] != (code *)0x0) {
    (*(code *)extraout_ECX[0x3f])
              (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),extraout_ECX[0x40]);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar3 = FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3 & 0xffffff00;
}

