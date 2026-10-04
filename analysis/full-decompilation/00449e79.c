
int * __thiscall FUN_00449e79(int *param_1,int *param_2,int param_3,int param_4,int *param_5)

{
  int local_10;
  
  if (((param_4 == *param_1) || (param_3 != 0)) || (*param_5 < *(int *)(param_4 + 0x10))) {
    local_10 = FUN_0044a20e(param_5);
    *(int *)(param_4 + 8) = local_10;
    if (param_4 == *param_1) {
      *(int *)(*param_1 + 4) = local_10;
      *(int *)(*param_1 + 0xc) = local_10;
    }
    else if (param_4 == *(int *)(*param_1 + 8)) {
      *(int *)(*param_1 + 8) = local_10;
    }
  }
  else {
    local_10 = FUN_0044a20e(param_5);
    *(int *)(param_4 + 0xc) = local_10;
    if (param_4 == *(int *)(*param_1 + 0xc)) {
      *(int *)(*param_1 + 0xc) = local_10;
    }
  }
  *(int *)(local_10 + 4) = param_4;
  *(undefined4 *)(local_10 + 8) = 0;
  *(undefined4 *)(local_10 + 0xc) = 0;
  FUN_00430367(local_10,*param_1 + 4);
  param_1[1] = param_1[1] + 1;
  *param_2 = local_10;
  return param_2;
}

