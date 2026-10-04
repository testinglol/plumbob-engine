
void FUN_0046b2e6(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  int iVar3;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00667680;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  sVar1 = FUN_004066d0();
  iVar3 = (int)sVar1;
  while (iVar3 = iVar3 + -1, -1 < iVar3) {
    puVar2 = (undefined4 *)FUN_004066e7(iVar3);
    FUN_00406675(puVar2);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004065f0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

