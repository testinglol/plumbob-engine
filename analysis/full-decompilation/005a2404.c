
void __thiscall FUN_005a2404(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  if (puVar1 == *(undefined4 **)(param_1 + 8)) {
    FUN_005a3952(puVar1,param_2);
  }
  else {
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_2;
    }
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 4;
  }
  return;
}

