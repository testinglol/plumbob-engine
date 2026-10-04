
void __thiscall FUN_0059adbe(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  if (puVar1 == *(undefined4 **)(param_1 + 8)) {
    FUN_0059b5d6(puVar1,param_2);
  }
  else {
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_2;
      puVar1[1] = param_2[1];
    }
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 8;
  }
  return;
}

