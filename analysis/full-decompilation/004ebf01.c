
void __thiscall FUN_004ebf01(int *param_1,int *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  local_c = param_1[1];
  iVar2 = *param_1;
  if (param_1[8] == 0) {
    local_8 = 0;
    if (0 < param_3) {
      do {
        if (((int *)*param_2 != (int *)0x0) &&
           (cVar1 = (**(code **)(*(int *)*param_2 + 0x8c))(1), cVar1 != '\0')) {
          FUN_004cb21d(iVar2,local_c);
          iVar2 = iVar2 + param_1[2];
          if ((param_1[2] == 0) || (param_1[4] < param_1[6] + iVar2)) {
            local_8 = local_8 + 1;
            iVar2 = *param_1;
            local_c = param_1[1] + param_1[3] * local_8;
          }
        }
        param_2 = param_2 + 1;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
  }
  else {
    local_8 = 0;
    if (0 < param_3) {
      do {
        if (((int *)*param_2 != (int *)0x0) &&
           (cVar1 = (**(code **)(*(int *)*param_2 + 0x8c))(1), cVar1 != '\0')) {
          FUN_004cb21d(iVar2,local_c);
          local_c = local_c + param_1[3];
          if ((param_1[3] == 0) || (param_1[5] < param_1[7] + local_c)) {
            local_c = param_1[1];
            local_8 = local_8 + 1;
            iVar2 = *param_1 + param_1[2] * local_8;
          }
        }
        param_2 = param_2 + 1;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
  }
  return;
}

