
undefined4 __thiscall FUN_005ceca4(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_2 != (int *)0x0) {
    if ((uint)(*(int *)(param_1 + 0x7c) - *(int *)(param_1 + 0x78) >> 2) < 0x10) {
      for (piVar1 = *(int **)(param_1 + 0x78); piVar1 != *(int **)(param_1 + 0x7c);
          piVar1 = piVar1 + 1) {
        if ((int *)*piVar1 == param_2) {
          if (piVar1 != *(int **)(param_1 + 0x7c)) goto LAB_005ced06;
          break;
        }
      }
      (**(code **)(*param_2 + 8))();
      FUN_00468a79(&param_2);
      uVar2 = (**(code **)(**(int **)(param_1 + 0xd8) + 0x34))(*(int **)(param_1 + 0xd8),param_2[3])
      ;
      *(undefined4 *)(param_1 + 0x5c) = uVar2;
    }
    else {
      *(undefined4 *)(param_1 + 0x5c) = 0x9b0b0020;
    }
  }
LAB_005ced06:
  return *(undefined4 *)(param_1 + 0x5c);
}

