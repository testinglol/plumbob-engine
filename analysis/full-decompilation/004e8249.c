
void FUN_004e8249(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005b870f(&DAT_006c4518);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0042ed71(**(undefined4 **)(unaff_EBP + 0xc),(*(undefined4 **)(unaff_EBP + 0xc))[1]);
  piVar2 = (int *)(**(code **)(**(int **)(unaff_EBP + 8) + 0x8c))();
  iVar3 = (**(code **)(*piVar2 + 0xac))();
  iVar3 = *(int *)(iVar3 + 4);
  *(undefined4 *)(unaff_EBP + 8) = 0;
  iVar4 = *(int *)(iVar3 + 0x8c) - *(int *)(iVar3 + 0x88) >> 2;
  *(int *)(unaff_EBP + -0x18) = iVar4;
  if (0 < iVar4) {
    do {
      iVar4 = *(int *)(*(int *)(iVar3 + 0x88) + *(int *)(unaff_EBP + 8) * 4);
      iVar5 = (*(int *)(iVar4 + 0xc) - *(int *)(iVar4 + 8)) / 0xc;
      if (0 < iVar5) {
        *(undefined4 *)(unaff_EBP + 0xc) = 0;
        *(int *)(unaff_EBP + -0x10) = iVar5;
        do {
          cVar1 = FUN_004317d5(*(undefined4 *)(*(int *)(unaff_EBP + 0xc) + *(int *)(iVar4 + 8)),
                               unaff_EBP + -0x24);
          if (cVar1 != '\0') {
            *(undefined4 *)(unaff_EBP + -0x14) =
                 *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 8 + *(int *)(iVar4 + 8));
            FUN_004e8708(unaff_EBP + -0x14);
          }
          *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 0xc;
          piVar2 = (int *)(unaff_EBP + -0x10);
          *piVar2 = *piVar2 + -1;
        } while (*piVar2 != 0);
      }
      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
    } while (*(int *)(unaff_EBP + 8) < *(int *)(unaff_EBP + -0x18));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

