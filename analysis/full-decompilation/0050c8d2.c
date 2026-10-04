
void __thiscall FUN_0050c8d2(int param_1,int *param_2,char param_3,undefined2 param_4)

{
  int iVar1;
  uint uVar2;
  undefined2 *puVar3;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0xcc))();
  uVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0xd0))();
  uVar2 = uVar2 >> 1;
  puVar3 = (undefined2 *)(iVar1 + (param_2[1] * uVar2 + *param_2) * 2);
  if (param_3 == '\0') {
    *puVar3 = param_4;
    puVar3 = puVar3 + uVar2;
    *puVar3 = param_4;
    puVar3[1] = param_4;
    puVar3 = puVar3 + uVar2;
    *puVar3 = param_4;
    puVar3[1] = param_4;
    puVar3[2] = param_4;
    puVar3 = puVar3 + uVar2;
    *puVar3 = param_4;
    puVar3[1] = param_4;
    puVar3[uVar2] = param_4;
  }
  else {
    puVar3[2] = param_4;
    puVar3[uVar2 + 1] = param_4;
    puVar3[uVar2 + 2] = param_4;
    puVar3 = puVar3 + uVar2 * 2;
    *puVar3 = param_4;
    puVar3[1] = param_4;
    puVar3[2] = param_4;
    puVar3[uVar2 + 1] = param_4;
    puVar3[uVar2 + 2] = param_4;
    puVar3[uVar2 * 2 + 2] = param_4;
  }
  return;
}

