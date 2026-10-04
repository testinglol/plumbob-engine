
short FUN_00484444(char *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  short sVar3;
  
  puVar2 = &DAT_006e5630;
  sVar3 = 1;
  do {
    iVar1 = _strcmp((char *)*puVar2,param_1);
    if (iVar1 == 0) {
      return sVar3;
    }
    puVar2 = puVar2 + 3;
    sVar3 = sVar3 + 1;
  } while ((int)puVar2 < 0x6e56b5);
  return 0;
}

