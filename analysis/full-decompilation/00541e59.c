
void FUN_00541e59(void)

{
  char cVar1;
  int unaff_EBP;
  int iVar2;
  
  FUN_00634c24();
  iVar2 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  while( true ) {
    iVar2 = iVar2 + -4;
    cVar1 = (**(code **)(unaff_EBP + 0x10))(unaff_EBP + 0xc,iVar2);
    if (cVar1 == '\0') break;
    FUN_005412f4(iVar2);
  }
  FUN_005412f4(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    FUN_0053d900();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

