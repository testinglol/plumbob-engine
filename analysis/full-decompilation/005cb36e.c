
undefined4 FUN_005cb36e(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  void *_Dst;
  
  iVar1 = param_3 + 0x48;
  cVar3 = FUN_005cb8aa(iVar1,0);
  if (cVar3 == '\0') {
    cVar3 = FUN_005cb92b(iVar1,0);
    if (cVar3 == '\0') {
      cVar3 = FUN_005cb9ac(iVar1,0);
      if ((cVar3 == '\0') && (cVar3 = FUN_005cb9e1(iVar1,0), cVar3 == '\0')) {
        cVar3 = FUN_005cba13(iVar1,0);
        if (cVar3 != '\0') {
          uVar4 = FUN_005cba42(param_1,param_2,param_3);
          return uVar4;
        }
        cVar3 = FUN_005cba91(iVar1,0);
        if (cVar3 != '\0') {
          uVar4 = FUN_005cbac0(param_1,param_2,param_3);
          return uVar4;
        }
        cVar3 = FUN_005cbb0f(iVar1,0);
        if (cVar3 != '\0') {
          uVar4 = FUN_005cbb44(param_1,param_2,param_3,0);
          return uVar4;
        }
        iVar1 = *(int *)(param_3 + 0x54);
        param_2 = 0;
        iVar2 = *(int *)(param_3 + 0xc);
        _Dst = *(void **)(param_3 + 0x24);
        if (*(int *)(param_3 + 8) != 0) {
          do {
            _memset(_Dst,0x88,(iVar1 * iVar2 - 1U | 7) + 1 >> 3);
            _Dst = (void *)((int)_Dst + *(int *)(param_3 + 0x10));
            param_2 = param_2 + 1;
          } while (param_2 < *(uint *)(param_3 + 8));
        }
      }
      uVar4 = 1;
    }
    else {
      uVar4 = FUN_005cb95d(param_1,param_2,param_3);
    }
  }
  else {
    uVar4 = FUN_005cb8dc(param_1,param_2,param_3);
  }
  return uVar4;
}

