
undefined4 __fastcall FUN_006062d5(int param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  
  FUN_00606366();
  FUN_005b8e25();
  iVar3 = FUN_005b936f(*(undefined4 *)(param_1 + 0xc),0);
  if (iVar3 != 0) {
    uVar1 = *(uint *)(iVar3 + 0x10);
    pvVar4 = operator_new(uVar1);
    *(void **)(param_1 + 4) = pvVar4;
    if (pvVar4 != (void *)0x0) {
      FUN_005b903c(0x1000,0);
      uVar5 = FUN_005b8e6a(*(undefined4 *)(param_1 + 4),uVar1);
      if ((uVar5 == uVar1) &&
         (cVar2 = FUN_00606916(*(undefined4 *)(param_1 + 4),param_1 + 8,param_1 + 0x18),
         cVar2 != '\0')) {
        FUN_005b95c0(iVar3);
        return 1;
      }
    }
    FUN_005b95c0(iVar3);
    FUN_00606366();
  }
  return 0;
}

