
undefined4 __thiscall FUN_005d3d7a(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x5c);
  while( true ) {
    if (piVar1 == *(int **)(param_1 + 0x60)) {
      return 0x9b0b001f;
    }
    if (*piVar1 == param_2) break;
    piVar1 = piVar1 + 1;
  }
  if (piVar1 == *(int **)(param_1 + 0x60)) {
    return 0x9b0b001f;
  }
  (**(code **)(*(int *)*piVar1 + 8))();
  FUN_005db2f2(piVar1);
  return 0;
}

