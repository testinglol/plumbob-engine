
void FUN_00438fc0(undefined4 *param_1,byte param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00422698();
  }
  if ((param_2 & 2) != 0) {
    FUN_00422698();
  }
  *param_1 = 0x7fffffff;
  param_1[1] = 0x7fffffff;
  param_1[2] = 0x80000000;
  param_1[3] = 0x80000000;
  return;
}

