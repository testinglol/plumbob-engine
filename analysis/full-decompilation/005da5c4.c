
undefined4 __thiscall FUN_005da5c4(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)**(int **)(param_1 + 0x44);
  piVar1 = param_2;
  if (piVar2 != *(int **)(param_1 + 0x44)) {
    do {
      for (; piVar1 != (int *)0x0; piVar1 = (int *)(**(code **)(*piVar1 + 0x18))()) {
        if (piVar1 == (int *)piVar2[2]) {
          return 1;
        }
      }
      piVar2 = (int *)*piVar2;
      piVar1 = param_2;
    } while (piVar2 != (int *)*(int *)(param_1 + 0x44));
  }
  return 0;
}

