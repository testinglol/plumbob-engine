
undefined4 __thiscall FUN_005ced0e(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x78);
  do {
    if (piVar2 == *(int **)(param_1 + 0x7c)) {
LAB_005ced60:
      *(undefined4 *)(param_1 + 0x5c) = 0x9b0b001f;
      return 0x9b0b001f;
    }
    if (*piVar2 == param_2) {
      if (piVar2 != *(int **)(param_1 + 0x7c)) {
        if (*piVar2 != 0) {
          uVar1 = (**(code **)(**(int **)(param_1 + 0xd8) + 0x38))
                            (*(int **)(param_1 + 0xd8),*(undefined4 *)(*piVar2 + 0xc));
          *(undefined4 *)(param_1 + 0x5c) = uVar1;
          (**(code **)(*(int *)*piVar2 + 4))();
        }
        FUN_005db2f2(piVar2);
        *(undefined4 *)(param_1 + 0x5c) = 0;
        return 0;
      }
      goto LAB_005ced60;
    }
    piVar2 = piVar2 + 1;
  } while( true );
}

