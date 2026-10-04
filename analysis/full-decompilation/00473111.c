
void FUN_00473111(undefined1 *param_1)

{
  undefined1 uVar1;
  
  uVar1 = *param_1;
  *param_1 = param_1[1];
  param_1[1] = uVar1;
  uVar1 = param_1[2];
  param_1[2] = param_1[3];
  param_1[3] = uVar1;
  uVar1 = param_1[4];
  param_1[4] = param_1[5];
  param_1[5] = uVar1;
  uVar1 = param_1[6];
  param_1[6] = param_1[7];
  param_1[7] = uVar1;
  return;
}

