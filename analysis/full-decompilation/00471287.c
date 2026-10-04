
void __thiscall FUN_00471287(int param_1,char param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  
  puVar1 = (undefined4 *)(*(int *)(param_1 + 0x6c) + param_2 * 0xc);
  for (piVar2 = *(int **)(*(int *)(param_1 + 0x6c) + param_2 * 0xc); piVar2 != (int *)puVar1[1];
      piVar2 = piVar2 + 3) {
    if (*piVar2 != 0) {
      FUN_006321f0(*piVar2);
    }
    if (piVar2[1] != 0) {
      FUN_006321f0(piVar2[1]);
    }
  }
  FUN_004717fa(*puVar1,puVar1[1]);
  return;
}

