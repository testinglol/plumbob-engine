
int * __thiscall
FUN_005102c9(int *param_1,int param_2,int param_3,int param_4,int param_5,int *param_6,int param_7)

{
  int iVar1;
  
  *param_1 = param_2;
  *(undefined1 *)(param_1 + 9) = 0;
  param_1[1] = param_3;
  param_1[8] = param_7;
  param_1[2] = param_4;
  param_1[3] = param_5;
  if (param_5 != 0) {
    param_1[4] = *param_6;
    param_1[5] = param_6[1];
    param_1[6] = param_6[2];
    param_1[7] = param_6[3];
  }
  if ((*param_1 == 2) && (param_1[1] != 0)) {
    iVar1 = FUN_005e3596();
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 9) = 1;
      FUN_005e357a();
    }
  }
  return param_1;
}

