
undefined4 FUN_0056254b(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  undefined4 uVar6;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 0x10);
  piVar2 = *(int **)(unaff_EBP + 0xc);
  *piVar2 = 0;
  *piVar1 = 0;
  if (*(int *)(extraout_ECX + 0xd4) == 1) {
    FUN_00429c21();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar5 = FUN_004e1c79(*(undefined4 *)(extraout_ECX + 0x160),unaff_EBP + -0x28);
    if (cVar5 != '\0') {
      iVar3 = *(int *)(unaff_EBP + -0x1c);
      iVar4 = *(int *)(unaff_EBP + 8);
      *piVar2 = iVar3;
      iVar4 = *(int *)(iVar4 + 0x1c);
      if (iVar4 <= iVar3) {
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *piVar1 = iVar3 - iVar4;
        FUN_005b8770();
        uVar6 = 1;
        goto LAB_005625c4;
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  uVar6 = 0;
LAB_005625c4:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

