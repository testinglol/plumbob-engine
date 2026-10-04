
void __thiscall FUN_005dc0ec(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != (int *)0x0) {
    iVar2 = (((param_2[2] - param_1[0x21]) - *param_2) + param_1[0x1f]) / 2 + *param_2;
    iVar1 = (((param_1[0x20] - param_1[0x22]) + param_2[3]) - param_2[1]) / 2 + param_2[1];
    (**(code **)(*param_1 + 0x60))
              (iVar2,iVar1,(param_1[0x21] - param_1[0x1f]) + iVar2,
               (param_1[0x22] - param_1[0x20]) + iVar1);
  }
  return;
}

