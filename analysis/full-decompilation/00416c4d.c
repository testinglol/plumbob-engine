
void FUN_00416c4d(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(unaff_EBP + 8) != -1) {
    for (piVar2 = (int *)*extraout_ECX; piVar2 != (int *)extraout_ECX[1]; piVar2 = piVar2 + 0x14) {
      if (*piVar2 == *(int *)(unaff_EBP + 8)) {
        if (piVar2 != (int *)extraout_ECX[1]) {
          FUN_00418454(piVar2);
        }
        break;
      }
    }
    puVar1 = *(undefined4 **)(unaff_EBP + 0xc);
    iVar3 = (**(code **)*puVar1)();
    if (iVar3 != 0) {
      FUN_00416cc1(*(undefined4 *)(unaff_EBP + 8),puVar1);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_0041842c(unaff_EBP + -0x5c);
    }
    *(undefined1 *)(extraout_ECX + 3) = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

