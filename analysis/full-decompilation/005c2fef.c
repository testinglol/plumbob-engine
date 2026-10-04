
void FUN_005c2fef(void)

{
  int *piVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBP;
  int iVar5;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  iVar4 = 0;
  iVar5 = piVar1[1] - *piVar1;
  if (0 < iVar5) {
    do {
      if (*(char *)(*piVar1 + iVar4) == '/') {
        *(char *)(*piVar1 + iVar4) = '\\';
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar5);
  }
  if (2 < iVar5) {
    iVar4 = FUN_00636845((int)*(char *)*piVar1);
    if (((iVar4 != 0) && (*(char *)(*piVar1 + 1) == ':')) && (*(char *)(*piVar1 + 2) == '\\'))
    goto LAB_005c30c8;
  }
  if (((iVar5 < 2) || (*(char *)*piVar1 != '.')) || (((char *)*piVar1)[1] != '\\')) {
    if (((2 < iVar5) && (pcVar2 = (char *)*piVar1, *pcVar2 == '\\')) && (pcVar2[1] == '\\')) {
      iVar4 = FUN_00636845((int)pcVar2[2]);
      if (iVar4 != 0) goto LAB_005c30c8;
    }
    if ((iVar5 != 1) || (*(char *)*piVar1 != '.')) {
      uVar3 = FUN_004fee54(unaff_EBP + -0x24,&DAT_006d2c30,piVar1);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_005b86bd(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005d499c(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00401729();
    }
  }
LAB_005c30c8:
  if (*(char *)(piVar1[1] + -1) != '\\') {
    FUN_004015e4(0x5c);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

