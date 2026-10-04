
void __thiscall FUN_004d4116(int param_1,undefined2 *param_2)

{
  undefined2 *puVar1;
  
  puVar1 = *(undefined2 **)(param_1 + 4);
  if (puVar1 == *(undefined2 **)(param_1 + 8)) {
    FUN_004d4315(puVar1,param_2);
  }
  else {
    if (puVar1 != (undefined2 *)0x0) {
      *puVar1 = *param_2;
    }
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 2;
  }
  return;
}

