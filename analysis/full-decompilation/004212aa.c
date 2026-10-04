
void FUN_004212aa(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar2 = FUN_00635845(*(undefined4 *)(unaff_EBP + 8),&DAT_006c0a78);
  if (iVar2 != 0) {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x78) = &PTR_FUN_0066643c;
    iVar1 = DAT_006e486c;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00470383(*(undefined4 *)(iVar1 + 0xc),0x86,0);
    FUN_0042119e(iVar2,unaff_EBP + -0x78);
    FUN_0063558d(iVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

