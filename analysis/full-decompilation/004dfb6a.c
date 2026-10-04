
undefined * FUN_004dfb6a(undefined4 param_1)

{
  size_t sVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  
  wsprintfA(&DAT_006f2024,(LPCSTR)&DAT_006c8db0,param_1);
  sVar1 = _strlen(&DAT_006f2024);
  if (sVar1 != 3 && -1 < (int)(sVar1 - 3)) {
    puVar3 = &DAT_006f2021 + sVar1;
    iVar4 = 0;
    uVar2 = (sVar1 - 1) / 3;
    do {
      iVar4 = iVar4 + 4;
      FUN_00635190(puVar3 + 1,puVar3,iVar4);
      *puVar3 = 0x2c;
      puVar3 = puVar3 + -3;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return &DAT_006f2024;
}

