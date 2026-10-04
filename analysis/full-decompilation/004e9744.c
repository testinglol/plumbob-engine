
undefined4 FUN_004e9744(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar2 = FUN_004e8d71(param_1);
  if (iVar2 != 0) {
    iVar1 = *(int *)(*DAT_006e486c + 0x14);
    for (puVar4 = *(undefined4 **)(iVar1 + 0x84); puVar4 != *(undefined4 **)(iVar1 + 0x88);
        puVar4 = puVar4 + 1) {
      iVar3 = FUN_0045741b();
      if (iVar3 == iVar2) {
        return *puVar4;
      }
    }
  }
  return 0;
}

