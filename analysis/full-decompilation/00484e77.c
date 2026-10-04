
void __thiscall
FUN_00484e77(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  char cVar1;
  
  cVar1 = FUN_00484ba0(&param_2);
  if (cVar1 == '\0') {
    FUN_00490c0d(param_2,param_3,param_4,param_5);
    if ((char)param_1[0xb] == '\0') {
      FUN_0048521a(1);
      (**(code **)(*param_1 + 0x28))(param_2,param_3,param_4,param_5);
    }
  }
  return;
}

