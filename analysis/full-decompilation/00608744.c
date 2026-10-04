
undefined4 FUN_00608744(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = DAT_006d95ec + -1;
  if (-1 < iVar1) {
    puVar2 = &DAT_006ff2bc + iVar1;
    do {
      if (*(int *)*puVar2 <= param_1) {
        return (&DAT_006ff2bc)[iVar1];
      }
      iVar1 = iVar1 + -1;
      puVar2 = puVar2 + -1;
    } while (-1 < iVar1);
  }
  return DAT_006ff2bc;
}

