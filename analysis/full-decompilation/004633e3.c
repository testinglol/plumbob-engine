
uint __thiscall FUN_004633e3(int param_1,undefined2 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined2 *puVar3;
  
  uVar2 = 0;
  puVar3 = (undefined2 *)(param_1 + 8);
  do {
    uVar1 = FUN_0046341b(uVar2,0);
    if ((param_3 & uVar1) != 0) {
      *puVar3 = param_2;
    }
    uVar2 = uVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (uVar2 < 6);
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x10;
  return param_3;
}

