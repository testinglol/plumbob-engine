
void __thiscall FUN_005dadff(int param_1,int param_2,int param_3,int param_4)

{
  DWORD DVar1;
  int *piVar2;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = param_2;
  local_10 = param_3;
  DVar1 = timeGetTime();
  local_c = DVar1 + local_10;
  piVar2 = *(int **)(param_1 + 0x1cc);
  local_8 = param_4;
  do {
    if (piVar2 == *(int **)(param_1 + 0x1d0)) {
LAB_005dae4d:
      FUN_005db385(&local_14);
      return;
    }
    if (*piVar2 == local_14) {
      if (piVar2 != *(int **)(param_1 + 0x1d0)) {
        *piVar2 = local_14;
        piVar2[1] = local_10;
        piVar2[2] = local_c;
        piVar2[3] = param_4;
        return;
      }
      goto LAB_005dae4d;
    }
    piVar2 = piVar2 + 4;
  } while( true );
}

