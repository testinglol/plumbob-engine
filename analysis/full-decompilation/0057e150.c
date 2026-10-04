
void __thiscall FUN_0057e150(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[0x32];
  if (((piVar1 == param_1) || (piVar1 == (int *)0x0)) || (param_2 == 0x35)) {
    (**(code **)(*param_1 + 0x94))(param_2,param_3,param_4);
  }
  else {
    (**(code **)(*piVar1 + 0x84))(param_2,param_3,param_4);
  }
  return;
}

