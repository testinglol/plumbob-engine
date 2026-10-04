
undefined4 * FUN_005b880e(void)

{
  uint uVar1;
  uint uVar2;
  size_t _Count;
  char *_Dest;
  undefined4 *puVar3;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  uVar2 = extraout_ECX[1] - *extraout_ECX;
  if (uVar2 < uVar1) {
    FUN_005b8680();
    puVar3 = *(undefined4 **)(unaff_EBP + 8);
  }
  else {
    _Count = *(size_t *)(unaff_EBP + 0x10);
    if (uVar2 < uVar1 + _Count) {
      _Count = uVar2 - uVar1;
    }
    _Dest = operator_new(_Count + 1);
    _strncpy(_Dest,(char *)(*extraout_ECX + *(int *)(unaff_EBP + 0xc)),_Count);
    _Dest[_Count] = '\0';
    FUN_005b870f(_Dest);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_006321f0(_Dest);
    puVar3 = *(undefined4 **)(unaff_EBP + 8);
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_00401a3c(*(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x18));
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    FUN_00401729();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return puVar3;
}

