
void FUN_005421c6(void)

{
  int iVar1;
  char cVar2;
  int unaff_EBP;
  int iVar3;
  
  FUN_00634c24();
  iVar3 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = *(int *)(unaff_EBP + 8);
  if (*(int *)(unaff_EBP + 0x10) < iVar3) {
    do {
      iVar3 = (iVar3 + -1) / 2;
      cVar2 = (**(code **)(unaff_EBP + 0x18))(iVar1 + iVar3 * 4,unaff_EBP + 0x14);
      if (cVar2 == '\0') break;
      FUN_005412f4(iVar1 + iVar3 * 4);
    } while (*(int *)(unaff_EBP + 0x10) < iVar3);
  }
  FUN_005412f4(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0x14) != 0) {
    FUN_0053d900();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

