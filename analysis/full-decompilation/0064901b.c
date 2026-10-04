
undefined4 FUN_0064901b(int param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  if (param_1 != 0) {
    iVar1 = FUN_0063ab25(param_1);
    pvVar2 = _malloc(iVar1 * 2 + 2);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_00648e84(pvVar2,param_1);
      return uVar3;
    }
  }
  return 0;
}

