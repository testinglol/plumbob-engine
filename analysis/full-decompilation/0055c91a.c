
bool FUN_0055c91a(void)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  int extraout_ECX;
  bool bVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar4 = *(int *)(unaff_EBP + 8);
  bVar5 = true;
  bVar3 = true;
  iVar1 = *(int *)(extraout_ECX + 0xd4);
  if (iVar1 == 1) {
    FUN_00429c21();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar2 = FUN_004e1c79(*(undefined4 *)(extraout_ECX + 0x1ac),unaff_EBP + -0x28);
    if (cVar2 != '\0') {
      if (*(int *)(unaff_EBP + -0x1c) < *(int *)(iVar4 + 0x1b0)) {
        bVar5 = false;
      }
      else if ((*(int *)(iVar4 + 0x1a4) == 0) || (*(int *)(iVar4 + 0x1b8) != -1)) {
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
        goto LAB_0055c9ff;
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    bVar3 = bVar5;
  }
  else {
    if ((iVar1 == 2) || (iVar1 == 3)) {
      if (((*(int *)(iVar4 + 0x1b8) != -1) || (*(int *)(iVar4 + 0x1ac) != 0)) &&
         (*(int *)(iVar4 + 0x1a8) == 0)) goto LAB_0055c978;
    }
    else {
      if (iVar1 == 4) {
        iVar4 = FUN_0042ba25(*(undefined4 *)(iVar4 + 0x1d8));
        bVar3 = iVar4 == 2;
        goto LAB_0055c978;
      }
      if (*(int *)(iVar4 + 0x1b8) != -1) goto LAB_0055c978;
    }
LAB_0055c9ff:
    bVar3 = false;
  }
LAB_0055c978:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return bVar3;
}

