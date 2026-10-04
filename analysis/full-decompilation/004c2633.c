
undefined1 FUN_004c2633(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  char cVar6;
  undefined1 uVar7;
  int iVar8;
  int unaff_EBP;
  int unaff_ESI;
  int *unaff_EDI;
  
  *(int **)(unaff_EBP + -4) = unaff_EDI;
  piVar5 = DAT_006f0a6c;
  if (*(char *)(unaff_EBP + -0x11) != '\0') {
    if ((*(int *)(unaff_ESI + 0x158) != *(int *)(unaff_ESI + 0x154)) && (DAT_006f0a6c != unaff_EDI))
    {
      iVar1 = *(int *)(unaff_ESI + 0x14c);
      *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(iVar1 + 0x14);
      *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(iVar1 + 0x18);
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(iVar1 + 0x1c);
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(iVar1 + 0x20);
      iVar8 = (**(code **)(*piVar5 + 0x58))();
      piVar5 = DAT_006f0a6c;
      iVar1 = *(int *)(unaff_ESI + 0x154);
      iVar8 = *(int *)(unaff_EBP + -0x24) - iVar8;
      iVar2 = *(int *)(unaff_ESI + 0x158);
      *(int *)(unaff_EBP + -0x2c) = iVar8 + -3;
      (**(code **)(*piVar5 + 0x78))
                (*(undefined4 *)(unaff_ESI + 0x14c),*(int *)(unaff_EBP + -0x30) + 3,iVar8 + -1,iVar1
                 ,iVar2 - iVar1,unaff_EBP + -0x30,0);
      unaff_EDI = (int *)0x0;
    }
    cVar6 = (**(code **)(**(int **)(unaff_ESI + 0x14c) + 0x20))(0x40);
    if (cVar6 != '\0') {
      FUN_004b7c9a(*(undefined4 *)(unaff_ESI + 0x14c));
      (**(code **)(**(int **)(unaff_ESI + 0x14c) + 0x24))(0x40);
    }
    uVar3 = *(undefined4 *)(unaff_ESI + 0x14c);
    uVar4 = *(undefined4 *)(unaff_ESI + 0x38);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_004b818c(uVar4,uVar3,unaff_EDI,0x5a,unaff_EDI,unaff_EDI);
    uVar7 = FUN_004c2711();
    return uVar7;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined1 *)(unaff_EBP + -0x11);
}

