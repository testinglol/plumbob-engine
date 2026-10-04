
undefined4 FUN_0040622a(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  char *_Str;
  size_t sVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_00406466(0,DAT_00666580);
  FUN_00406466(0,DAT_00666580);
  iVar1 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x38))
                    (0x43415453,*(undefined4 *)(unaff_EBP + 0xc),0);
  *(int *)(unaff_EBP + -0x10) = iVar1;
  if (iVar1 == 0) {
    FUN_004706f0();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0047034e(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),0x43545353,0,
                 0xffffffff);
    iVar1 = FUN_00470d9f(0,0);
    *(int *)(unaff_EBP + 0xc) = iVar1;
    if (iVar1 == 0) {
      iVar1 = FUN_00471509(1,0xffffffff);
      if (iVar1 == 0) {
        if ((undefined1 *)*extraout_ECX != (undefined1 *)extraout_ECX[1]) {
          *(undefined1 *)*extraout_ECX = 0;
          extraout_ECX[1] = *extraout_ECX;
        }
      }
      else {
        FUN_005d4bbf(iVar1);
      }
      iVar1 = FUN_00471509(2,0xffffffff);
      if (iVar1 == 0) {
        puVar3 = (undefined1 *)extraout_ECX[3];
        if (puVar3 != (undefined1 *)extraout_ECX[4]) {
          *puVar3 = 0;
          extraout_ECX[4] = extraout_ECX[3];
        }
      }
      else {
        FUN_005d4bbf(iVar1);
      }
    }
    if ((*(char *)(unaff_EBP + 0x10) != '\0') && (extraout_ECX[1] == *extraout_ECX)) {
      uVar2 = FUN_00470d9f(1,0);
      *(undefined4 *)(unaff_EBP + 0xc) = uVar2;
      puVar3 = (undefined1 *)FUN_00471557(1,0);
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_006de560;
      }
      FUN_005d4bbf(puVar3);
      FUN_00471557(2,0);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004712d0();
    uVar2 = *(undefined4 *)(unaff_EBP + 0xc);
  }
  else {
    _Str = (char *)FUN_00420048(iVar1);
    FUN_005d4bbf(_Str);
    sVar4 = _strlen(_Str);
    iVar1 = FUN_00420096(*(undefined4 *)(unaff_EBP + -0x10));
    if (_Str + sVar4 + 1 < _Str + iVar1) {
      FUN_005d4bbf(_Str + sVar4 + 1);
    }
    FUN_0042004f(*(undefined4 *)(unaff_EBP + -0x10));
    uVar2 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

