
void __thiscall FUN_00464c84(int *param_1,int *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (*(char *)((int)param_1 + 0x12) == '\0') {
    if (*(char *)((int)param_1 + 0x13) != '\0') {
      param_1[8] = 0;
    }
    iVar1 = param_1[3];
    if (iVar1 != 2) {
      if (iVar1 == 0) {
        FUN_005d4bbf(param_1[2] + *param_1);
      }
      else if (iVar1 == 1) {
        FUN_006358b0(param_1[2] + *param_1,*param_2);
      }
    }
    param_1[2] = param_1[2] + (param_2[1] - *param_2) + 1;
    if ((param_1[2] & 1U) != 0) {
      param_1[2] = param_1[2] + 1;
    }
  }
  else {
    param_1[6] = param_1[6] + 1;
    if (param_1[3] != 2) {
      if (param_1[3] == 1) {
        FUN_004704a5(param_1[6],*param_2,0xffffffff);
      }
      else {
        puVar2 = (undefined1 *)FUN_004705f2(param_1[6],0xffffffff);
        if (puVar2 == (undefined1 *)0x0) {
          puVar2 = &DAT_006de560;
        }
        FUN_005d4bbf(puVar2);
      }
    }
  }
  return;
}

