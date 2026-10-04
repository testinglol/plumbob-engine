
void __thiscall FUN_0056d96d(int *param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  piVar1 = (int *)param_1[0x6a];
  param_1[0x6c] = param_2;
  *(short *)(piVar1 + 0x167) = (short)param_2;
  (**(code **)(*piVar1 + 0x8c))(0);
  FUN_0058a17c(uVar2);
  (**(code **)(*param_1 + 0x168))();
  return;
}

