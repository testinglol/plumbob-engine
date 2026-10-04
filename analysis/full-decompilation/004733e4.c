
void __thiscall FUN_004733e4(uint *param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1[2] == 0) {
    *param_1 = param_1[1];
  }
  else {
    *param_1 = *param_1 + (param_2 - param_1[2]);
  }
  param_1[2] = param_2;
  if ((param_1[3] != 0) && (uVar1 = param_1[1] * param_1[3], uVar1 < *param_1)) {
    *param_1 = uVar1;
  }
  return;
}

