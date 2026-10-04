
undefined4 __thiscall FUN_005d44cf(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = (**(code **)(*param_2 + 8))();
  if (iVar1 == 1) {
    FUN_005d474e();
    for (puVar2 = *(undefined4 **)(param_1 + 4); puVar2 != *(undefined4 **)(param_1 + 8);
        puVar2 = puVar2 + 1) {
      if ((int *)*puVar2 == param_2) {
        if (puVar2 == *(undefined4 **)(param_1 + 8)) {
          return 0;
        }
        FUN_005db2f2(puVar2);
        (**(code **)(*param_2 + 8))();
        return 0;
      }
    }
  }
  return 0;
}

