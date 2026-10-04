
uint __thiscall FUN_00493b0f(int param_1,undefined2 param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  undefined2 *puVar3;
  int local_8;
  
  uVar2 = 0;
  if (param_3 == 0x10) {
    if (param_4 == 0) {
      param_4 = 4;
    }
  }
  else if ((param_3 == 0x20) && (param_4 == 0)) {
    param_4 = 1;
  }
  puVar3 = (undefined2 *)(param_1 + 0x14);
  local_8 = param_1;
  do {
    uVar1 = FUN_0046341b(uVar2,&local_8);
    if (((param_3 & uVar1) != 0) && (local_8 == param_4)) {
      *puVar3 = param_2;
    }
    uVar2 = uVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (uVar2 < 8);
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x10;
  return param_3;
}

