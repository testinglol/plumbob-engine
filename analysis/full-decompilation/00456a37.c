
int FUN_00456a37(void)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  int *extraout_ECX;
  int iVar5;
  int unaff_EBP;
  undefined4 *puVar6;
  
  FUN_00634c24();
  iVar5 = (int)*(short *)(unaff_EBP + 0xc);
  puVar6 = (undefined4 *)0x0;
  if ((*(int *)(unaff_EBP + 8) != 0) && (0 < iVar5)) {
    piVar1 = (int *)extraout_ECX[1];
    piVar4 = (int *)*extraout_ECX;
    *(int **)(unaff_EBP + 0xc) = piVar1;
    for (; piVar4 != piVar1; piVar4 = piVar4 + 3) {
      if (piVar4[1] == 0) {
        *(int **)(unaff_EBP + 0xc) = piVar4;
      }
      else if (piVar4[2] == iVar5) {
        if (piVar4 != piVar1) goto LAB_00456b05;
        break;
      }
    }
    pvVar2 = operator_new(0x6c);
    *(void **)(unaff_EBP + -0x10) = pvVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar2 != (void *)0x0) {
      puVar6 = (undefined4 *)FUN_00401000();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    iVar3 = FUN_00401039(*(undefined4 *)(unaff_EBP + 8),iVar5);
    if (iVar3 == 0) {
      piVar4 = *(int **)(unaff_EBP + 0xc);
      if (piVar4 == (int *)extraout_ECX[1]) {
        *(undefined4 *)(unaff_EBP + -0x1c) = 0;
        *(undefined4 *)(unaff_EBP + -0x18) = 0;
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        FUN_00456c9b(unaff_EBP + -0x1c);
        piVar4 = (int *)(*extraout_ECX + -0xc + ((extraout_ECX[1] - *extraout_ECX) / 0xc) * 0xc);
      }
      piVar4[1] = (int)puVar6;
      piVar4[2] = iVar5;
LAB_00456b05:
      *piVar4 = *piVar4 + 1;
      iVar5 = piVar4[1];
      goto LAB_00456abc;
    }
    if (puVar6 != (undefined4 *)0x0) {
      (**(code **)*puVar6)(1);
    }
  }
  iVar5 = 0;
LAB_00456abc:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar5;
}

