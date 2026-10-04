
int FUN_00419493(void)

{
  char cVar1;
  int iVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 0x28))();
  if (cVar1 == '\0') {
    iVar2 = FUN_00413003(*(undefined4 *)(unaff_EBP + 8));
    if (iVar2 == 0) {
      FUN_0041308b();
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_004130d2(*(undefined4 *)(unaff_EBP + 8),1);
      iVar2 = FUN_0041950d(unaff_EBP + -0x18,0);
      FUN_00413154();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004130c0();
    }
  }
  else {
    iVar2 = -0x2f;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2;
}

