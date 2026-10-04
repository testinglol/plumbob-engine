
undefined4 FUN_005c1d8b(void)

{
  char *_Str;
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  _Str = *(char **)(unaff_EBP + 0x14);
  if (_Str != (char *)0x0) {
    FUN_005b870f(*(undefined4 *)(unaff_EBP + 0x10));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    sVar1 = _strlen(_Str);
    FUN_00412d8a(_Str,_Str + sVar1);
    FUN_005c17b6(unaff_EBP + -0x18);
    iVar2 = FUN_005c21b3(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18));
    if (iVar2 == 0) {
      FUN_005c340e(*(undefined4 *)(unaff_EBP + 0xc));
      FUN_005c33ff(_Str);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      uVar3 = 0;
      goto LAB_005c1e15;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  uVar3 = 5;
LAB_005c1e15:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}

