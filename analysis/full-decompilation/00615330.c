
undefined4 FUN_00615330(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = 0;
  if (0 < DAT_006ff840) {
    puVar3 = &DAT_006ff444;
    do {
      iVar1 = FUN_00615380(param_1,puVar3);
      if (iVar1 != 0) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 4;
    } while (iVar2 < DAT_006ff840);
  }
  return 0;
}

