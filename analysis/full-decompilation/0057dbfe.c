
void FUN_0057dbfe(void)

{
  int *piVar1;
  int iVar2;
  int *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar2 = *(int *)(unaff_EBP + -0x14);
  *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
  if (100 < iVar2) {
    (**(code **)(DAT_006f6a78 + 200))();
  }
  piVar1 = *(int **)(unaff_ESI + 0x198);
  if ((piVar1 != unaff_EBX) && (piVar1 <= *(int **)(unaff_EBP + -0x1c))) {
    if ((int)piVar1 < (int)unaff_EBX) {
      (**(code **)(DAT_006f6a78 + 200))();
    }
    *(int **)(unaff_EBP + -4) = unaff_EBX;
    FUN_0057e3dc();
    FUN_0057dbfe();
    return;
  }
  if ((*(int **)(unaff_ESI + 0x194) != unaff_EBX) &&
     (*(int **)(unaff_ESI + 0x194) <= *(int **)(unaff_EBP + -0x1c))) {
    if (*(int **)(unaff_ESI + 0x1d0) != unaff_EBX) {
      (**(code **)(**(int **)(unaff_ESI + 0x1d0) + 0x98))();
    }
    *(int **)(unaff_ESI + 0x194) = unaff_EBX;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

