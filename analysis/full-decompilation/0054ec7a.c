
void __thiscall FUN_0054ec7a(int param_1,int *param_2)

{
  int *piVar1;
  
  if (((*(byte *)(DAT_006e486c + 0x66) & 0x20) == 0) ||
     (piVar1 = (int *)(param_1 + 500), *(int *)(param_1 + 0x244) == 0)) {
    piVar1 = (int *)(param_1 + 0x1e0);
  }
  if (*piVar1 == 0x7fffffff) {
    FUN_004cb21d(*param_2 - (*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c)) / 2,
                 param_2[1] - (*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80)) / 2);
  }
  else {
    *(int *)(param_1 + 0x210) = *param_2;
    *(int *)(param_1 + 0x214) = param_2[1];
    FUN_004cb21d(*param_2 - *piVar1,(param_2[1] - piVar1[1]) - piVar1[2]);
  }
  return;
}

