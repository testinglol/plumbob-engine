
void FUN_005be8cc(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_00672b9c;
  cVar1 = *(char *)(extraout_ECX + 6);
  *(undefined4 *)(unaff_EBP + -4) = 3;
  if (cVar1 != '\0') {
    FUN_005bebb1();
  }
  iVar2 = extraout_ECX[0x1b];
  iVar3 = extraout_ECX[0x1d] - iVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  if (iVar3 != 0) {
    FUN_0040189d(iVar2,iVar3);
  }
  iVar2 = extraout_ECX[0x15];
  iVar3 = extraout_ECX[0x17] - iVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (iVar3 != 0) {
    FUN_0040189d(iVar2,iVar3);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0xd] = &PTR_LAB_0066933c;
  FUN_00401729();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[1] = &PTR_LAB_0066933c;
  FUN_00401729();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

