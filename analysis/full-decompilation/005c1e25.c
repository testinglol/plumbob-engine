
int FUN_005c1e25(void)

{
  char *_Str;
  char *_Str_00;
  size_t sVar1;
  int iVar2;
  HANDLE pvVar3;
  undefined4 uVar4;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  _Str = *(char **)(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -0x1c) = extraout_ECX;
  if (_Str == (char *)0x0) {
    FUN_005b8680();
    *(undefined4 *)(unaff_EBP + -4) = 2;
    FUN_005d4bbf(*(undefined4 *)(unaff_EBP + 0x10));
    FUN_004015e4(0x5f);
    FUN_0063b26a(*(undefined4 *)(unaff_EBP + 0x18),unaff_EBP + -0x34,10);
    sVar1 = _strlen((char *)(unaff_EBP + -0x34));
    FUN_00412d8a(unaff_EBP + -0x34,unaff_EBP + -0x34 + sVar1);
    FUN_004015e4(0x5f);
    FUN_004015e4(0x2a);
    FUN_005c17b6(unaff_EBP + -0x28);
    pvVar3 = FindFirstFileA(*(LPCSTR *)(unaff_EBP + -0x28),(LPWIN32_FIND_DATAA)(unaff_EBP + -0x18c))
    ;
    if (pvVar3 == (HANDLE)0xffffffff) {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      iVar2 = 5;
      goto LAB_005c21a2;
    }
    FindClose(pvVar3);
    FUN_005b870f(*(undefined4 *)(unaff_EBP + 0x10));
    *(undefined1 *)(unaff_EBP + -4) = 3;
    sVar1 = _strlen((char *)(unaff_EBP + -0x160));
    FUN_00412d8a(unaff_EBP + -0x160,unaff_EBP + -0x160 + sVar1);
    iVar2 = FUN_005c21b3(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x40));
    if (iVar2 == 0) {
      FUN_005c340e(*(undefined4 *)(unaff_EBP + 0xc));
      FUN_005b870f(unaff_EBP + -0x160);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_005c22fb(unaff_EBP + -0x4c);
      FUN_005c33ff(*(undefined4 *)(unaff_EBP + -0x4c));
      FUN_00473577(*(undefined4 *)(unaff_EBP + 0x18));
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      goto LAB_005c1ea1;
    }
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  else {
    _Str_00 = *(char **)(unaff_EBP + 0x10);
    FUN_005b870f(_Str_00);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    sVar1 = _strlen(_Str);
    FUN_00412d8a(_Str,_Str + sVar1);
    FUN_005c17b6(unaff_EBP + -0x18);
    uVar4 = *(undefined4 *)(unaff_EBP + 8);
    iVar2 = FUN_005c21b3(uVar4,*(undefined4 *)(unaff_EBP + -0x18));
    if (iVar2 == 0) {
      FUN_005c340e(*(undefined4 *)(unaff_EBP + 0xc));
      FUN_005c33ff(_Str);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
LAB_005c1ea1:
      FUN_005b8770();
      iVar2 = 0;
      goto LAB_005c21a2;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    FUN_005b870f(_Str_00);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (*(int *)(unaff_EBP + 0x18) != -0x80000000) {
      FUN_004015e4(0x5f);
      FUN_0063b26a(*(undefined4 *)(unaff_EBP + 0x18),unaff_EBP + -0x34,10);
      sVar1 = _strlen((char *)(unaff_EBP + -0x34));
      FUN_00412d8a(unaff_EBP + -0x34,unaff_EBP + -0x34 + sVar1);
      FUN_004015e4(0x5f);
    }
    sVar1 = _strlen(_Str);
    FUN_00412d8a(_Str,_Str + sVar1);
    FUN_005c17b6(unaff_EBP + -0x18);
    iVar2 = FUN_005c21b3(uVar4,*(undefined4 *)(unaff_EBP + -0x18));
    if (iVar2 == 0) {
      FUN_005c340e(*(undefined4 *)(unaff_EBP + 0xc));
      FUN_005c33ff(_Str);
      uVar4 = *(undefined4 *)(unaff_EBP + 0x18);
LAB_005c1f55:
      FUN_00473577(uVar4);
      iVar2 = 0;
    }
    else {
      FUN_005d4bbf(&DAT_006c5bc4);
      sVar1 = _strlen(_Str_00);
      FUN_00412d8a(_Str_00,_Str_00 + sVar1);
      sVar1 = _strlen(&DAT_006c0c2c);
      FUN_00412d8a(&DAT_006c0c2c,&DAT_006c0c2c + sVar1);
      FUN_004015e4(0x5f);
      FUN_004015e4(0x2a);
      FUN_004015e4(0x5f);
      sVar1 = _strlen(_Str);
      FUN_00412d8a(_Str,_Str + sVar1);
      FUN_005c17b6(unaff_EBP + -0x18);
      pvVar3 = FindFirstFileA(*(LPCSTR *)(unaff_EBP + -0x18),
                              (LPWIN32_FIND_DATAA)(unaff_EBP + -0x2cc));
      if (pvVar3 == (HANDLE)0xffffffff) {
        iVar2 = 5;
      }
      else {
        FindClose(pvVar3);
        iVar2 = FUN_005c21b3(uVar4,*(undefined4 *)(unaff_EBP + -0x18));
        if (iVar2 == 0) {
          FUN_005c340e(*(undefined4 *)(unaff_EBP + 0xc));
          FUN_005c33ff(_Str);
          uVar4 = FUN_005c22c1(unaff_EBP + -0x2a0);
          goto LAB_005c1f55;
        }
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  FUN_005b8770();
LAB_005c21a2:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar2;
}

