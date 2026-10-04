
undefined4 * __thiscall FUN_005bfad6(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  uVar2 = param_2;
  FUN_005bfbc9(param_2,(int)&param_2 + 3);
  puVar3 = (undefined4 *)*param_1;
  if (uVar2 != 0) {
    puVar4 = puVar3;
    for (uVar1 = uVar2 >> 1; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    puVar3 = (undefined4 *)((int)puVar3 + uVar2 * 2);
    for (uVar2 = (uint)((uVar2 & 1) != 0); uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined2 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 2);
    }
  }
  param_1[1] = puVar3;
  return param_1;
}

