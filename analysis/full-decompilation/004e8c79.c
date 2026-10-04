
void FUN_004e8c79(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  int iVar3;
  
  FUN_00634c24();
  FUN_004e8cf4();
  iVar3 = 0;
  while( true ) {
    iVar1 = FUN_0043ad1f(iVar3);
    if (iVar1 == 0) break;
    if (*(short *)(*(int *)(iVar1 + 0x60) + 0x12) == 2) {
      uVar2 = FUN_0045741b();
      uVar2 = FUN_004e8a46(uVar2);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_004eb2b2(uVar2);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00635f6d(unaff_EBP + -0x44,8,7,&LAB_004e8a75);
    }
    iVar3 = iVar3 + 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

