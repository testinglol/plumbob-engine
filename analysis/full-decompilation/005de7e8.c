
void __thiscall FUN_005de7e8(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *local_8;
  
  puVar1 = (undefined4 *)*param_1;
  puVar2 = (undefined4 *)*puVar1;
  local_8 = param_1;
  while (puVar3 = puVar2, puVar3 != puVar1) {
    puVar2 = (undefined4 *)*puVar3;
    if (puVar3[2] == *param_2) {
      FUN_00580b0a(&local_8,puVar3);
    }
  }
  return;
}

