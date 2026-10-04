
undefined4 FUN_00457ea7(void)

{
  int iVar1;
  char *_Str;
  int *piVar2;
  size_t sVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (extraout_ECX[0x2e] == 0) {
    *(undefined2 *)(unaff_EBP + -0x10) = *(undefined2 *)(extraout_ECX[0x18] + 0x52);
    piVar2 = operator_new(0x18);
    *(int **)(unaff_EBP + -0x14) = piVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      FUN_005b8680();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8680();
    }
    iVar1 = extraout_ECX[0x18];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0040622a(*extraout_ECX,*(undefined4 *)(unaff_EBP + -0x10),
                 CONCAT31((int3)((uint)iVar1 >> 8),*(short *)(iVar1 + 0x12) == 2));
    if (piVar2[1] == *piVar2) {
      FUN_005b870f(&DAT_006c12fc);
      *(undefined4 *)(unaff_EBP + -4) = 2;
      _Str = (char *)extraout_ECX[6];
      sVar3 = _strlen(_Str);
      FUN_00412d8a(_Str,_Str + sVar3);
      FUN_005d499c(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
    extraout_ECX[0x2e] = piVar2;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX[0x2e];
}

