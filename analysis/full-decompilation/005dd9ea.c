
void __thiscall FUN_005dd9ea(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  *(undefined4 *)(param_1 + 0x5c) = param_2;
  piVar1 = (int *)**(int **)(param_1 + 0x38);
  if (piVar1 != *(int **)(param_1 + 0x38)) {
    do {
      (**(code **)(*(int *)piVar1[2] + 0x188))(param_2);
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 0x38));
  }
  return;
}

